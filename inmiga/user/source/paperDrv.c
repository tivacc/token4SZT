#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include "ddl.h"
#include "typedef.h"
#include "paperDrv.h"
#include "paperTable.h"

//
unsigned char HRES = 0;
unsigned char VRES_byte1,VRES_byte2;


//local function
static void SPI_Delay(unsigned char xrate);
static void SPI_Write(unsigned char value);
static void EPD_W21_WriteCMD(unsigned char command);
static void EPD_W21_WriteDATA(unsigned char command);

extern unsigned char openLockTime[];
extern unsigned char  closeLockTime[];
extern unsigned char  rideTime[];
extern unsigned char  pay[];
extern unsigned char  balance[];


/*------------completment----------------------------------*/
static void SPI_Delay(unsigned char xrate)
{
	unsigned char i;
	while(xrate)
	{
		for(i=0;i<SPI_SPEED;i++);
		xrate--;
	}
}


//
static void SPI_Write(unsigned char value)                                    
{                                                           
  unsigned char i;


  SPI_Delay(1);
  for(i=0; i<8; i++)   
  {
    EPD_W21_CLK_0;
    SPI_Delay(1);
    if(value & 0x80)
      EPD_W21_MOSI_1;
    else
      EPD_W21_MOSI_0;		
    value = (value << 1); 
    SPI_Delay(1);
    asm("NOP");asm("NOP");asm("NOP");
    EPD_W21_CLK_1; 
    SPI_Delay(1);
  }
}

//
static void EPD_W21_WriteCMD(unsigned char command)
{
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_0;		// command write
  SPI_Write(command);
  EPD_W21_CS_1;
}


//
static void EPD_W21_WriteDATA(unsigned char command)
{
  SPI_Delay(1);
  EPD_W21_CS_0;                   
  EPD_W21_DC_1;		// command write
  SPI_Write(command);
  EPD_W21_CS_1;
}


//
void paperIOInit(void)
{
	Gpio_InitIO(PAPER_MOSI_PORT,PAPER_MOSI_PIN,GpioDirOut,FALSE,FALSE);
	Gpio_InitIO(PAPER_CLK_PORT,PAPER_CLK_PIN,GpioDirOut,FALSE,FALSE);
	Gpio_InitIO(PAPER_CS_PORT,PAPER_CS_PIN,GpioDirOut,FALSE,FALSE);
	Gpio_InitIO(PAPER_RST_PORT,PAPER_RST_PIN,GpioDirOut,FALSE,FALSE);
	Gpio_InitIO(PAPER_DC_PORT,PAPER_DC_PIN,GpioDirOut,FALSE,FALSE);
	Gpio_InitIO(PAPER_BUSY_PORT,PAPER_BUSY_PIN,GpioDirIn,FALSE,FALSE);
}


/*************************EPD display init function******************************************************/

void EPD_W21_Init(void)
{
	EPD_W21_RST_0;		// Module reset
	delay1ms(1000);
	EPD_W21_RST_1;
	delay1ms(1000);
}


void EPD_display_init(void)
{
	HRES=0x98;					//152
	VRES_byte1=0x00;			//152
	VRES_byte2=0x98;
	EPD_W21_Init();
	EPD_W21_WriteCMD(0x01);			//POWER SETTING 
	EPD_W21_WriteDATA (0x03);	          
	EPD_W21_WriteDATA (0x00);
	EPD_W21_WriteDATA (0x2b);
	EPD_W21_WriteDATA (0x2b);
	EPD_W21_WriteDATA (0x03);

	EPD_W21_WriteCMD(0x06);         //boost soft start
	EPD_W21_WriteDATA (0x17);		//A
	EPD_W21_WriteDATA (0x17);		//B
	EPD_W21_WriteDATA (0x17);		//C       

	EPD_W21_WriteCMD(0x04);  
	lcd_chkstatus();

	EPD_W21_WriteCMD(0x00);			//panel setting
	EPD_W21_WriteDATA(0xbf);		//LUT from OTP??128x296  0xBF
	EPD_W21_WriteDATA(0x0d);		//VCOM to 0V fast

	EPD_W21_WriteCMD(0x30);			//PLL setting
	EPD_W21_WriteDATA (0x3a);   // 3a 100HZ   29 150Hz 39 200HZ	31 171HZ

	EPD_W21_WriteCMD(0x61);			//resolution setting
	EPD_W21_WriteDATA (HRES);        	 
	EPD_W21_WriteDATA (VRES_byte1);		
	EPD_W21_WriteDATA (VRES_byte2);

	EPD_W21_WriteCMD(0x82);			//vcom_DC setting  	
	EPD_W21_WriteDATA (0x28);	

	EPD_W21_WriteCMD(0X50);			//VCOM AND DATA INTERVAL SETTING			
	EPD_W21_WriteDATA(0x97);		//WBmode:VBDF 17|D7 VBDW 97 VBDB 57		WBRmode:VBDF F7 VBDW 77 VBDB 37  VBDR B7
}

/***************************full display function*************************************/
void full_display(void pic_display(void))
{		
	pic_display(); 				//picture
	lut(); 						    //Power settings
	EPD_W21_WriteCMD(0x12);		//DISPLAY REFRESH 	
	delay1ms(100);	      //!!!The delay here is necessary, 200uS at least!!!     
	lcd_chkstatus();
}

/***************************partial display function*************************************/

void partial_display(u16 x_start,u16 x_end,u16 y_start,u16 y_end ,void partial_old(void),void partial_new(void)) //partial display
{
	EPD_W21_WriteCMD(0x82);			//vcom_DC setting  	
	EPD_W21_WriteDATA (0x08);	
	EPD_W21_WriteCMD(0X50);
	EPD_W21_WriteDATA(0x47);		
	lut1();
	EPD_W21_WriteCMD(0x91);		//This command makes the display enter partial mode
	EPD_W21_WriteCMD(0x90);		//resolution setting
	EPD_W21_WriteDATA (x_start);   //x-start     
	EPD_W21_WriteDATA (x_end-1);	 //x-end	

	EPD_W21_WriteDATA (y_start/256);
	EPD_W21_WriteDATA (y_start%256);   //y-start    

	EPD_W21_WriteDATA (y_end/256);		
	EPD_W21_WriteDATA (y_end%256-1);  //y-end
	EPD_W21_WriteDATA (0x28);	

	EPD_W21_WriteCMD(0x10);	       //writes Old data to SRAM for programming
	partial_old();
	EPD_W21_WriteCMD(0x13);				 //writes New data to SRAM.
	partial_new();

	EPD_W21_WriteCMD(0x12);		 //DISPLAY REFRESH 		             
	delay1ms(10);     //!!!The delay here is necessary, 200uS at least!!!     
	lcd_chkstatus();
	  
}

void partial_display_dynam(u16 x_start,u16 x_end,u16 y_start,u16 y_end ,void partial_old(void),unsigned char dataLen,unsigned char *playData,void partial_new(unsigned char ,unsigned char *))
{
	EPD_W21_WriteCMD(0x82);			//vcom_DC setting  	
	EPD_W21_WriteDATA (0x08);	
	EPD_W21_WriteCMD(0X50);
	EPD_W21_WriteDATA(0x47);		
	lut1();
	EPD_W21_WriteCMD(0x91);		//This command makes the display enter partial mode
	EPD_W21_WriteCMD(0x90);		//resolution setting
	EPD_W21_WriteDATA (x_start);   //x-start     
	EPD_W21_WriteDATA (x_end-1);	 //x-end	

	EPD_W21_WriteDATA (y_start/256);
	EPD_W21_WriteDATA (y_start%256);   //y-start    

	EPD_W21_WriteDATA (y_end/256);		
	EPD_W21_WriteDATA (y_end%256-1);  //y-end
	EPD_W21_WriteDATA (0x28);	

	EPD_W21_WriteCMD(0x10);	       //writes Old data to SRAM for programming
	partial_old();
	EPD_W21_WriteCMD(0x13);				 //writes New data to SRAM.
	partial_new(dataLen,playData);

	EPD_W21_WriteCMD(0x12);		 //DISPLAY REFRESH 		             
	delay1ms(10);     //!!!The delay here is necessary, 200uS at least!!!     
	lcd_chkstatus();
	  
}
/////////////////////////////Enter deep sleep mode////////////////////////
void deep_sleep(void) //Enter deep sleep mode
{
	EPD_W21_WriteCMD(0X50);
	EPD_W21_WriteDATA(0xf7);	
	EPD_W21_WriteCMD(0X02);  	//power off
	EPD_W21_WriteCMD(0X07);  	//deep sleep
	EPD_W21_WriteDATA(0xA5);
}

//LUT download
void lut(void)
{
	unsigned int count;
	EPD_W21_WriteCMD(0x20);
	for(count=0;count<44;count++)	     
	{
		EPD_W21_WriteDATA(lut_vcomDC[count]);}

	EPD_W21_WriteCMD(0x21);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_ww[count]);}   

	EPD_W21_WriteCMD(0x22);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_bw[count]);} 

	EPD_W21_WriteCMD(0x23);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_wb[count]);} 

	EPD_W21_WriteCMD(0x24);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_bb[count]);} 
}

void lut1(void)
{
	unsigned int count;
	EPD_W21_WriteCMD(0x20);
	for(count=0;count<44;count++)	     
	{
		EPD_W21_WriteDATA(lut_vcom1[count]);}

	EPD_W21_WriteCMD(0x21);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_ww1[count]);}   

	EPD_W21_WriteCMD(0x22);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_bw1[count]);} 

	EPD_W21_WriteCMD(0x23);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_wb1[count]);} 

	EPD_W21_WriteCMD(0x24);
	for(count=0;count<42;count++)	     
	{
		EPD_W21_WriteDATA(lut_bb1[count]);}   
}

//Detection busy
void lcd_chkstatus(void)
{
	unsigned char busy;
	do
	{
		EPD_W21_WriteCMD(0x71);
		busy = isEPD_W21_BUSY;
		busy =!(busy & 0x01);        
	}
	while(busy);   
	delay1ms(200);                       
}


void lcd_full00(void)
{
	unsigned int i;
	for(i=0;i<2888;i++)	     
	{
		EPD_W21_WriteDATA(0x00);  
	}  
}

void lcd_white(void)
{
	unsigned int i;
	EPD_W21_WriteCMD(0x10);
	for(i=0;i<2888;i++)	     
	{
			EPD_W21_WriteDATA(0x00);  
	}  
	delay1ms(2);

	EPD_W21_WriteCMD(0x13);
	for(i=0;i<2888;i++)	     
	{
			EPD_W21_WriteDATA(0xff);  
	}  
	delay1ms(2);
}

void lcdDisInfo(void)
{
    unsigned int i;
		EPD_W21_WriteCMD(0x10);
		for(i=0;i<2888;i++)	     
		{
				EPD_W21_WriteDATA(0x00);  
		}  
		delay1ms(2);
    
    unsigned int startX,startY,startPos;
    
    startX = 8;
    startY = 32;    
    startX = startX/8;
    for(i=0;i<16;i++)
    {
      //开锁时间:
      startPos = 0;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_open[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_open[2*i+1];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_lock[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_lock[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[openLockTime[0]][i];
      startPos++;      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[openLockTime[1]][i]; 
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[openLockTime[3]][i]; 
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[openLockTime[4]][i];
      startPos++;
    }
    

    startX = 8;
    startY = 48;   
    startX = startX/8;
    for(i=0;i<16;i++)
    {
      //落锁时间:
      startPos = 0;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_close[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_close[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_lock[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_lock[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[closeLockTime[0]][i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[closeLockTime[1]][i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[closeLockTime[3]][i];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[closeLockTime[4]][i];
      startPos++;
    }
    
    startX = 8;
    startY = 64;    
    startX = startX/8;
    for(i=0;i<16;i++)
    {
      //骑行时间:
      startPos = 0;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_ride1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_ride1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_ride2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_ride2[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_time2[2*i+1];
      startPos++;

      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      if(rideTime[0] == 0)
      {
        if(rideTime[1] == 0)
        {
          if(rideTime[2] == 0)
          {
              gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[3]][i];
              startPos++;
          }
          else
          {
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[2]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[3]][i];
            startPos++;
          }
        }
        else
        {
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[1]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[2]][i];
          startPos++;
            
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[3]][i];
          startPos++;
        }
      }
      else
      {
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[0]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[1]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[2]][i];
        startPos++;
          
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[rideTime[3]][i];
        startPos++;
      }
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_minute1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_minute1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_minute2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_minute2[2*i+1];
      startPos++;      
    }
    
    startX = 8;
    startY = 80;
    
    startX = startX/8;
    for(i=0;i<16;i++)
    {
      //扣费:
      startPos = 0;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_pay1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_pay1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_pay2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_pay2[2*i+1];
      startPos++;
        
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      if(pay[0] == 0)
      {
        if(pay[1] == 0)
        {
          if(pay[2] == 0)
          {
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[3]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
            startPos++;
              
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[5]][i];
            startPos++;
             
          }
          else
          {
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[2]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[3]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
            startPos++;
              
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[5]][i];
            startPos++;
          }
        }
        else
        {        
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[1]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[2]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[3]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
          startPos++;
            
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[5]][i];
          startPos++;
        }
      }
      else
      {
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[0]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[1]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[2]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[3]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
        startPos++;
          
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[pay[5]][i];
        startPos++;
      }
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_yuan[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_yuan[2*i+1];
      startPos++;
    }
    
    startX = 8;
    startY = 96;
    
    startX = startX/8;
    for(i=0;i<16;i++)
    {
      //余额:
      startPos = 0;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_balance1[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_balance1[2*i+1];
      startPos++;
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_balance2[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_balance2[2*i+1];
      startPos++;
        
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_colon[i];
      startPos++;
      
      if(balance[0] == 0)
      {
        if(balance[1] == 0)
        {
          if(balance[2] == 0)
          {
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[3]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
            startPos++;
              
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[5]][i];
            startPos++;
             
          }
          else
          {
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[2]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[3]][i];
            startPos++;
            
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
            startPos++;
              
            gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[5]][i];
            startPos++;
          }
        }
        else
        {        
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[1]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[2]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[3]][i];
          startPos++;
          
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
          startPos++;
            
          gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[5]][i];
          startPos++;
        }
      }
      else
      {
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[0]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[1]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[2]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[3]][i];
        startPos++;
        
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_dot[i];
        startPos++;
          
        gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_num[balance[5]][i];
        startPos++;
      }
      
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_yuan[2*i];
      startPos++;
      gText_immigaFull[19*(startY+i)+startX+startPos] = gText_immiga_yuan[2*i+1];
      startPos++;
    }
    
		EPD_W21_WriteCMD(0x13);
		for(i=0;i<2888;i++)	     
		{
				EPD_W21_WriteDATA(gText_immigaFull[i]);  
		}  
		delay1ms(2);	 	 
}








