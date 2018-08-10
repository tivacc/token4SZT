#include <stdio.h>
#include <stdint.h>
#include "ddl.h"
#include "gpio.h"
#include "sci.h"
#include "des.h"

//#define DEST_DEV_FM1280
#define DEST_DEV_P60D

uint8_t sciRxBuf[128];
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

uint8_t getMFCmdHeader[] = {0x00,0xA4,0x00,0x00,0x02};
uint8_t getMFCmdContent[] = {0x3F,0x00};

uint8_t getMFAuthRandomCmdHeader[] = {0x00,0x84,0x00,0x00,0x08};

uint8_t setMFAuthCmdHeader[] = {0x00,0x82,0x00,0x00,0x08};

uint8_t defaultMFAuthKey[]= {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};


//create the ADF
uint8_t setADF4BikeCmdHeader[] = {0x80,0xE0,0x3F,0x01,0x0E};
uint8_t setADF4BikeCmdContent[] = {0x38,0x03,0xFF,0xF0,0xF0,0x95,0xFF,0xFF,0x6C,0x69,0x6E,0x79,0x75,0x61,0x6E};

uint8_t getADF4BikeCmdHeader[] = {0x00,0xA4,0x04,0x00,0x07};
uint8_t getADF4BikeCmdContent[] = {0x6C,0x69,0x6E,0x79,0x75,0x61,0x6E};

uint8_t setADF4BikeKeyCmdHeader[] = {0x80,0xE0,0x00,0x00,0x07};
uint8_t setADF4BikeKeyCmdContent[] = {0x3F,0x01,0x8F,0x95,0xF0,0xFF,0xFF};

uint8_t addADF4BikeMaintainKeyHeader[] = {0x80,0xD4,0x01,0x00,0x15};
uint8_t addADF4BikeMaintainKeyContent[] = {0x36,0xF0,0x02,0xFF,0x33,0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22,0x11,0x11,0x11,0x11,0x22,0x22,0x22,0x22};

uint8_t addADF4BikePinKeyHeader[] = {0x80,0xD4,0x01,0x00,0x0D};
uint8_t addADF4BikePinKeyContent[] = {0x3A,0xF0,0xEF,0x01,0x33,0x12,0x34,0x5F,0xFF,0xFF,0xFF,0xFF,0xFF};

uint8_t createADF4BikeRecordCmdHeader[] = {0x80,0xE0,0x00,0x19,0x07};
uint8_t createADF4BikeRecordCmdContent[] = {0x2E,0x01,0xFF,0xf0,0xEF,0xFF,0xFF};


//获取安全通道认证随机数命令
uint8_t getRandomDataCmdHeader[] = {0x80,0x50,0x00,0x00,0x08};
uint8_t getRandomDataCmdContent[] = {0xF0,0x12,0x34,0x56,0x78,0x9A,0xBC,0xDE,0x1C};

//卡认证命令
uint8_t setExtAuthCmdHeader[] = {0x84,0x82,0x00,0x00,0x10};


uint8_t getSecurityCmdHeader[] = {0x00,0xA4,0x04,0x00,0x08};
uint8_t getSecurityCmdContent[] = {0xA0,0x00,0x00,0x00,0x03,0x00,0x00,0x00};

uint8_t machineRandom[] = {0xF0,0x12,0x34,0x56,0x78,0x9A,0xBC,0xDE};
uint8_t kmcNumber[] = {0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F};
uint8_t encKeyInitNumber[] = {0x01,0x82,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t macKeyInitNumber[] = {0x01,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
uint8_t dekKeyInitNumber[] = {0x01,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

uint8_t randomSeed[8] = {0};
uint8_t encKey[16] = {0};
uint8_t macKey[16] = {0};
uint8_t dekKey[16] = {0};

extern uint8_t timeOutFlag;
extern void timeOutStart(uint16_t value);
extern void timeOutStop(void);


void RxIntCb(void);
void TxIntCb(void);
uint8_t cardAuth(void);
uint8_t mfAuth(void);


//
void RxIntCb(void)
{
    while(Sci_GetIrqStatus(SciRxFinInt))
    {
      Sci_ClearIrqStatus(SciRxFinInt);
      if(sciRxOffset>=64)
      {
        sciRxOffset = 0;
      }
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
  /*
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
  */
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
  
  //power control
  Gpio_InitIO(5,3,GpioDirOut,FALSE,FALSE);
  Gpio_SetIO(5, 3, 0);
}

void tokenReset(void)
{  
  sciRxOffset = 0;
  Sci_ResetLow();   //rst out low
  delay1ms(100);    
  Sci_ResetHigh();
  
  
  while(0x12>sciRxOffset) ;
    
  Sci_InitStatus();
  Sci_ClearIrqStatus(SciTxFinInt);
  Sci_ClearIrqStatus(SciRxFinInt);
  Sci_ClearIrqStatus(SciEtuCntInt);
  Sci_ClearIrqStatus(SciWakeupInt);
  Sci_ClearWriteFifo();   
  Sci_ClearReadFifo();
}

void tokenPowerOn(void)
{
  Gpio_SetIO(5, 3, 1);
}


void tokenPowerOff(void)
{
  Gpio_SetIO(5, 3, 0);
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
    
    //Enable Sci
    Sci_Enable();
    
    tokenPowerOn();
    Sci_EnableIrq(SciRxIrq);
    
    /*
    Sci_ResetLow();   //rst out low
    delay1ms(100);    
    Sci_ResetHigh();
     
    delay1ms(1000);
    */
    tokenReset();
    Sci_DisableIrq(SciRxIrq);
    tokenPowerOff();
    /*
    Sci_InitStatus();
    Sci_ClearIrqStatus(SciTxFinInt);
    Sci_ClearIrqStatus(SciRxFinInt);
    Sci_ClearIrqStatus(SciEtuCntInt);
    Sci_ClearIrqStatus(SciWakeupInt);
    Sci_ClearWriteFifo();   
    Sci_ClearReadFifo();
    */

    
}

void tokenControl(uint8_t conlen,uint8_t* conContent)
{
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



uint8_t cardAuth(void)
{
  tokenReset();
  
  uint8_t fileDescLen = 0;
  sciRxOffset = 0;
  tokenControl(sizeof(getSecurityCmdHeader),getSecurityCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag) { return 0;}}
  timeOutStop();
  sciRxOffset = 0;
  tokenControl(sizeof(getSecurityCmdContent),getSecurityCmdContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();
  if(sciRxBuf[0] == 0x61)
  {
    fileDescLen = sciRxBuf[1];
    getResponseCmd[4] = sciRxBuf[1];
    
    sciRxOffset = 0;
    tokenControl(sizeof(getResponseCmd),getResponseCmd);
  }
  else
  {
  	return 0;
  }
  timeOutStart(1000);
  while(0x2A>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();
  sciRxOffset = 0;
  uint8_t unknownCmd[] = {0x80,0xCA,0x00,0x66};
  tokenControl(sizeof(unknownCmd),unknownCmd);
  timeOutStart(1000);
  while(0x3C>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();

  sciRxOffset = 0;  
  tokenControl(sizeof(getRandomDataCmdHeader),getRandomDataCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();
  sciRxOffset= 0;
  tokenControl(sizeof(getRandomDataCmdContent),getRandomDataCmdContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();
  if(sciRxBuf[0] == 0x61)
  {
    fileDescLen = sciRxBuf[1];
    getResponseCmd[4] = sciRxBuf[1];
    
    sciRxOffset = 0;
    tokenControl(sizeof(getResponseCmd),getResponseCmd);
  }
  else
  {
  	return 0;
  }
  timeOutStart(1000);
  while((fileDescLen+3)>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();

  for(uint8_t i=0;i<8;i++)
  {
  	randomSeed[i] = sciRxBuf[i+13];
  }
    
  encKeyInitNumber[2] = randomSeed[0];
  encKeyInitNumber[3] = randomSeed[1];

  macKeyInitNumber[2] = randomSeed[0];
  macKeyInitNumber[3] = randomSeed[1];

  dekKeyInitNumber[2] = randomSeed[0];
  dekKeyInitNumber[3] = randomSeed[1];

	uint8_t temp[8];
	//calculate the enc key,use 3des_cbc
	TDES(encKeyInitNumber,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		encKey[i] = Mout[i];
		temp[i] = Mout[i]^encKeyInitNumber[15-i];
	}
	TDES(temp,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		encKey[i+8] = Mout[i];
	}

	//calculate the mac key,use 3des_cbc
	TDES(macKeyInitNumber,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		macKey[i] = Mout[i];
		temp[i] = Mout[i]^macKeyInitNumber[15-i];
	}
	TDES(temp,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		macKey[i+8] = Mout[i];
	}

	//calculate the dek key,use 3des_cbc
	TDES(dekKeyInitNumber,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		dekKey[i] = Mout[i];
		temp[i] = Mout[i]^dekKeyInitNumber[15-i];
	}
	TDES(temp,kmcNumber,0x00);
	for(uint8_t i=0;i<8;i++)
	{
		dekKey[i+8] = Mout[i];
	}

  //calculate the dek key,use 3des_cbc
  uint8_t hostCryptogrAm[8];
  uint8_t hostCryptogrampatch[8] = {0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
  TDES(randomSeed,encKey,0x00);
  for(uint8_t i=0;i<8;i++)
  {
	hostCryptogrAm[i] = Mout[i]^machineRandom[i];
  }
  TDES(hostCryptogrAm,encKey,0x00);
  for(uint8_t i=0;i<8;i++)
  {
	hostCryptogrAm[i] = Mout[i]^hostCryptogrampatch[i];
  }

  TDES(hostCryptogrAm,encKey,0x00);
  for(uint8_t i=0;i<8;i++)
  {
	hostCryptogrAm[i] = Mout[i];
  }  

  uint8_t temp1[8] = {0x84,0x82,0x00,0x00,0x10};
  temp1[5] = hostCryptogrAm[0];
  temp1[6] = hostCryptogrAm[1];
  temp1[7] = hostCryptogrAm[2];

  SDES(temp1,macKey,0);

  uint8_t macData[8] = {0};
  for(uint8_t i=0;i<8;i++)
  {
  	macData[i] = Mout[i];
  }

  uint8_t temp2[8] = {0};
  for(uint8_t i= 0;i<5;i++)
  {
  	temp2[i] = hostCryptogrAm[3+i];
  }
  temp2[5] = 0x80;
  temp2[6] = 0x00;
  temp2[7] = 0x00;

  for(uint8_t i=0;i<8;i++)
  {
  	macData[i] = macData[i]^temp2[i];
  }

  TDES(macData,macKey,0);

  for(uint8_t i=0;i<8;i++)
  {
  	macData[i] = Mout[i];
  }

  sciRxOffset = 0;
  tokenControl(sizeof(setExtAuthCmdHeader),setExtAuthCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();
  
  uint8_t temp3[16] = {0};
  for(uint8_t i=0;i<16;i++)
  {
  	temp3[i] = hostCryptogrAm[i];
  	temp3[i+8] = macData[i];
  }

  sciRxOffset = 0;
  tokenControl(sizeof(temp3),temp3);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	return 1;
  }
  else
  {
  	return 0;
  }
}

uint8_t mfAuth(void)
{  
  sciRxOffset = 0;
  tokenControl(sizeof(getMFCmdHeader),getMFCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();
  
  sciRxOffset =  0;
  tokenControl(sizeof(getMFCmdContent),getMFCmdContent);

  while(1) ;
  
  tokenControl(sizeof(getMFAuthRandomCmdHeader),getMFAuthRandomCmdHeader);
  timeOutStart(1000);
  while(11>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();
  for(uint8_t i=0;i<8;i++)
  {
    randomSeed[i] = sciRxBuf[i+1];
  }
    
  TDES(randomSeed,defaultMFAuthKey,0x00);
  
  uint8_t encryResult[8];
  for(uint8_t i=0;i<8;i++)
  {
    encryResult[i] = Mout[i];
  }
  
  sciRxOffset = 0;  
  tokenControl(sizeof(setMFAuthCmdHeader),setMFAuthCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();
  
  sciRxOffset = 0;
  tokenControl(sizeof(encryResult),encryResult);
	timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
	timeOutStop();
  
  while(1) ;
	
  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	return 1;
  }
  else
  {
  	return 0;
  }
}

uint8_t  adfCreate(void)
{
	uint8_t fileDescLen = 0;
	
	tokenReset();

	#if 0
	if(0 == cardAuth()) 
	{
		return 0;
	}
	
	if(0 == mfAuth())
	{
		return 0;
	}
	
	#endif

	sciRxOffset = 0;
  tokenControl(sizeof(getMFCmdHeader),getMFCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();
  
  sciRxOffset =  0;
  tokenControl(sizeof(getMFCmdContent),getMFCmdContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();

  if(0x61 == sciRxBuf[0])
  {
  	fileDescLen = sciRxBuf[1];
  	getResponseCmd[4] = sciRxBuf[1];
    
    sciRxOffset = 0;
    tokenControl(sizeof(getResponseCmd),getResponseCmd);
  }
  else
  {
  	return 0;
  }

	timeOutStart(1000);
  while((fileDescLen+3)>sciRxOffset) {if(timeOutFlag){return 0;}}
  timeOutStop();

	//80E00380 08 0002E20017180100
	uint8_t testCmdHeader[] = {0x80,0xE0,0x03,0x80,0x08};
	uint8_t testCmdContent[] = {0x00,0x02,0xE2,0x00,0x17,0x18,0x01,0x00};

  //建立ADF 目录
  sciRxOffset = 0;
  tokenControl(sizeof(/*testCmdHeader*/setADF4BikeCmdHeader),setADF4BikeCmdHeader);
  
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  sciRxOffset = 0;
  tokenControl(sizeof(/*testCmdContent*/setADF4BikeCmdContent),setADF4BikeCmdContent);
  
  while(1) ;
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	;
  }
  else
  {
  	return 0;
  }

	//建立key文件
  sciRxOffset = 0;
  tokenControl(sizeof(setADF4BikeKeyCmdHeader),setADF4BikeKeyCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  sciRxOffset = 0;
  tokenControl(sizeof(setADF4BikeKeyCmdContent),setADF4BikeKeyCmdContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	;
  }
  else
  {
  	return 0;
  }


	//增加维护密钥
	sciRxOffset = 0;
  tokenControl(sizeof(addADF4BikeMaintainKeyHeader),addADF4BikeMaintainKeyHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  sciRxOffset = 0;
  tokenControl(sizeof(addADF4BikeMaintainKeyContent),addADF4BikeMaintainKeyContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	;
  }
  else
  {
  	return 0;
  }

	
	//增加pin口令
  sciRxOffset = 0;
  tokenControl(sizeof(addADF4BikePinKeyHeader),addADF4BikePinKeyHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  sciRxOffset = 0;
  tokenControl(sizeof(addADF4BikePinKeyContent),addADF4BikePinKeyContent);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	;
  }
  else
  {
  	return 0;
  }

	//建立循环记录文件
  sciRxOffset = 0;
  tokenControl(sizeof(createADF4BikeRecordCmdHeader),createADF4BikeRecordCmdHeader);
  timeOutStart(1000);
  while(1>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  sciRxOffset = 0;
  tokenControl(sizeof(createADF4BikeRecordCmdContent),createADF4BikeRecordCmdHeader);
  timeOutStart(1000);
  while(2>sciRxOffset) {if(timeOutFlag){return 0;}};
  timeOutStop();

  if((0x90 == sciRxBuf[0]) && (0x00== sciRxBuf[1]))
  {
  	;
  }
  else
  {
  	return 0;
  }

  return 1;
}


void tokenRead(uint8_t recordNum)
{
  //if user power control,it must be reset ,when read the balance from the ic
  tokenReset();
  
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





