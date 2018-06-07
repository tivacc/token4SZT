#include <stdio.h>
#include <stdint.h>
#include "ddl.h"
#include "gpio.h"
#include "sci.h"

//#define DEST_DEV_FM1280
#define DEST_DEV_P60D

uint8_t sciRxBuf[64];
uint8_t sciRxOffset = 0;

static uint8_t sciTxErrFlag = 0;
static uint8_t sciTxFinState = 0;
static uint8_t sciTxPendCnt = 0;

uint8_t getResponseCmd[] = {0x00,0xc0,0x00,0x00,0x00};

uint8_t getSZTCmdHeader[] = {0x00,0xa4,0x04,0x00,0x0E};
uint8_t getSZTCmdContent[] = {0x53,0x5A,0x54,0x2E,0x57,0x41,0x4C,0x4C,0x45,0x54,0x2E,0x45,0x4E,0x56};

uint8_t getEFCardCmdHeader[] = {0x00,0xa4,0x00,0x00,0x02};
uint8_t getEFCardCmdContent[] = {0x10,0x01};

uint8_t getDDFCardCmdHeader[] = {0x00,0xa4,0x00,0x00,0x02};
uint8_t getDDFCardCmdContent[] = {0x00,0x18};

uint8_t getSZTRecord1Cmd[] = {0x00,0xB2,0x01,0xC4,0x17};
uint8_t getSZTBalanceCmd[] = {0x80,0x5c,0x00,0x02,0x04};

extern uint8_t timeOutFlag;
extern void timeOutStart(uint16_t value);
extern void timeOutStop(void);


//
void RxIntCb(void)
{
    while(Sci_GetIrqStatus(SciRxFinInt))
    {
      Sci_ClearIrqStatus(SciRxFinInt);
      sciRxBuf[sciRxOffset++] = Sci_ReceiveData();
    }
    
    while(Sci_GetStatus(SciRxErr))
    {
      Sci_ClearStatus(SciRxErr);
    }
}

void TxIntCb(void)
{
    
    while(Sci_GetIrqStatus(SciTxFinInt))
    {
      Sci_ClearIrqStatus(SciTxFinInt);
    }
    
    while(Sci_GetStatus(SciTxErr))
    {
      sciTxErrFlag = 1;
      Sci_ClearStatus(SciTxErr);      
      sciTxPendCnt = Sci_GetWriteFifoCurCnt();
    }
    
    sciTxFinState = 1;
}


void tokenIOInit(void)
{
#if defined(DEST_DEV_FM1280)
	M0P_GPIO->ANALOG = 0;
  //P52 as RST
  M0P_GPIO->FN5_f.P52 = 1;
  //P50 as ICCLK
  M0P_GPIO->FN5_f.P50 = 1;
  //P51 as ICIO
  M0P_GPIO->FN5_f.P51 = 1;
  //EPFR09 configuration
  M0P_GPIO->FN_SEL09_f.ICCKE = 1;
  M0P_GPIO->FN_SEL09_f.ICIOB = 1;
  M0P_GPIO->FN_SEL09_f.ICRSTE = 1;
#endif
  
#if defined(DEST_DEV_P60D)
  M0P_GPIO->ANALOG = 0;
  //P65as RST
  M0P_GPIO->FN6_f.P65 = 1;
  //P63 as ICCLK
  M0P_GPIO->FN6_f.P63 = 1;
  //P64 as ICIO
  M0P_GPIO->FN6_f.P64 = 1;
  //EPFR09 configuration
  M0P_GPIO->FN_SEL09_f.ICCKE = 2;
  M0P_GPIO->FN_SEL09_f.ICIOB = 2;
  M0P_GPIO->FN_SEL09_f.ICRSTE = 2;
#endif
  
  //power control
  Gpio_InitIO(3,6,GpioDirOut,FALSE,FALSE);
  Gpio_SetIO(3, 6, 0);
}

void tokenPowerOn(void)
{
  Gpio_SetIO(3, 6, 1);
}


void tokenPowerOff(void)
{
  Gpio_SetIO(3, 6, 0);
}

void tokenEnableTrx(void)
{
  Sci_EnableIrq(SciRxIrq);
}


void tokenDisableTrx(void)
{
  Sci_DisableIrq(SciRxIrq);
}

void tokenConfig(void)
{
    stc_sci_config_t stcSciConfig;
    stc_sci_irq_cb_t stcSciIrqCb;
    
    //Init the variable
    DDL_ZERO_STRUCT(stcSciConfig);
    DDL_ZERO_STRUCT(stcSciIrqCb);
       
    // Initialize interrupt callback fucntion
    stcSciIrqCb.pfnRxIrqCb = RxIntCb;               //Rx Callback handler
    stcSciIrqCb.pfnTxIrqCb = TxIntCb;               //Rx Callback handler

    //Config the SCI as needed
    stcSciConfig.enTMode = SciT0Mode;               //T0 Mode
    stcSciConfig.u16BaudRate = 0x174;               //372
    stcSciConfig.bParity = TRUE;                    //Parity check on
    stcSciConfig.enParity = SciParityEven;          //Even
    stcSciConfig.bTouchNvic = TRUE;                 //Use interrupt
    stcSciConfig.enBitDirection = SciDataLsbFirst;  //LSB first
    stcSciConfig.pstcIrqEn->bRxIrq = TRUE;          //Use Interrupt  
    stcSciConfig.u8ResendTimes = 0;                 //Don't need resend
    stcSciConfig.pstcIrqCb = &stcSciIrqCb;          //Callback function
    
    //Sci init
    Sci_Init(&stcSciConfig);
    
    //Set Sci clock
    Sci_SetClock(SciClockDiv4);

    //Enable Sci clock
    Sci_EnableClock();  
    Sci_EnableReset();   
    
    //Clean the Sci status
    Sci_InitStatus();    
    Sci_ClearWriteFifo();    
    Sci_ClearReadFifo();    
    
    tokenPowerOn();
    
    //Enable Sci
    Sci_Enable();
    //Sci_EnableIrq(SciRxIrq);
    
    Sci_ResetLow();   //rst out low
    delay1ms(100);    
    Sci_ResetHigh();
     
    delay1ms(1000);
    
    tokenPowerOff();
    Sci_InitStatus();
    Sci_ClearIrqStatus(SciTxFinInt);
    Sci_ClearIrqStatus(SciRxFinInt);
    Sci_ClearIrqStatus(SciEtuCntInt);
    Sci_ClearIrqStatus(SciWakeupInt);
    Sci_ClearWriteFifo();   
    Sci_ClearReadFifo();
}

void tokenControl(uint8_t conlen,uint8_t* conContent)
{
	/*for(uint8_t i=0;i<conlen;i++)
	{   
	repeat:
	    sciTxFinState = 0;
	    Sci_SendData(conContent[i]);
	    if((Sci_GetFifoStatus(SciFifoTxFul)))
	    {
	      Sci_ClearFifoStatus(SciFifoTxFul);
	      while(!sciTxFinState) ;
	      Sci_ClearWriteFifo();
	      i = i + 1 - sciTxPendCnt;
	      if(i<conlen)          
	        goto repeat;
	    }
	    
	    while(!sciTxFinState) ;
	}*/
  uint8_t i = 0;
  while(1)
  {
    if(i>=conlen)
    {
      while(!sciTxFinState) ;
      sciTxFinState = 0;
      if(sciTxErrFlag)
      {
        sciTxErrFlag = 0;
        Sci_ClearWriteFifo();
        i = i + 1 - sciTxPendCnt;
        sciTxPendCnt = 0;
      }
      else
      {
        break;
      }
    }
    
    if((Sci_GetFifoStatus(SciFifoTxFul)))
    {
      Sci_ClearFifoStatus(SciFifoTxFul);
      while(!sciTxFinState) ;
      sciTxFinState = 0;
      if(sciTxErrFlag)
      {
        sciTxErrFlag = 0;
        Sci_ClearWriteFifo();
        i = i + 1 - sciTxPendCnt; 
        sciTxPendCnt = 0;
      }
      else
      {
        i = i+1;
      }
    }
    else
    {
      Sci_SendData(conContent[i]);
      i = i+1;
    }
  }
}

void tokenRead(uint8_t recordNum)
{
  sciRxOffset = 0;
  tokenControl(sizeof(getSZTCmdHeader),getSZTCmdHeader);
  timeOutFlag = 0;
  timeOutStart(1000);
  while(1>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if(sciRxBuf[0] == 0xA4)
  {
    sciRxOffset = 0;
    tokenControl(sizeof(getSZTCmdContent),getSZTCmdContent);
  }else
  {
    return ;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(2>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if((sciRxBuf[0] == 0x90)&&(sciRxBuf[1]==0x00))
  {
    sciRxOffset = 0;
    tokenControl(sizeof(getEFCardCmdHeader),getEFCardCmdHeader);
  }
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(1>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if(sciRxBuf[0] == 0xA4)
  {
    sciRxOffset = 0;
    tokenControl(sizeof(getEFCardCmdContent),getEFCardCmdContent);
  }  
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(2>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if(sciRxBuf[0] == 0x61)
  {
    getResponseCmd[4] = sciRxBuf[1];
    
    sciRxOffset = 0;
    tokenControl(sizeof(getResponseCmd),getResponseCmd);
  }
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(55>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if((sciRxBuf[53] == 0x90)&&(sciRxBuf[54]==0x00))
  {
    sciRxOffset = 0;
    tokenControl(sizeof(getDDFCardCmdHeader),getDDFCardCmdHeader);
  }
  while(1>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if(sciRxBuf[0] == 0xA4)
  {
    sciRxOffset = 0;
    tokenControl(sizeof(getDDFCardCmdContent),getDDFCardCmdContent);
  }
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(2>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if(sciRxBuf[0] == 0x61)
  {
    getResponseCmd[4] = sciRxBuf[1];
    
    sciRxOffset = 0;
    tokenControl(sizeof(getResponseCmd),getResponseCmd);
  }
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(11>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
  if((sciRxBuf[9] == 0x90)&&(sciRxBuf[10]==0x00))
  {
    sciRxOffset = 0;
    getSZTRecord1Cmd[2] = recordNum;
    tokenControl(sizeof(getSZTRecord1Cmd),getSZTRecord1Cmd);
  }
  else
  {
    return;
  }
  timeOutFlag = 0;
  timeOutStart(1000);
  while(0x17>sciRxOffset){if(timeOutFlag){return;}};
  timeOutStop();
}





