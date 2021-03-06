#include "ddl.h"
#include "gpio.h"
#include "clk.h"
#include "lpm.h"
#include "lvd.h"
#include "typedef.h"
#include "tokenCon.h"
#include "tokenBsp.h"
#include "paperDrv.h"

/* Private function prototypes -----------------------------------------------*/
static void RCC_Configuration(void);
static void NVIC_Configuration(void);
static void GPIO_Configuration(void);
static void LPM_Configuration(void);
static void recordProcess(void);

uint8_t sztRecordNum = 1;
uint8_t openLockTime[5] = {0};    //xx:xx
uint8_t closeLockTime[5] = {0};   //xx:xx
uint8_t rideTime[4] = {0};        //xxx minute
uint8_t pay[6] = {0};             //xxxx.x yuan
uint8_t balance[6] = {0};         //xxxx.x yuan

extern uint8_t keyUpPress;
extern uint8_t keyDownPress;

void	main(void)
{
	RCC_Configuration();
	GPIO_Configuration();
	
	tokenConfig();
	bspConfig();
  EPD_display_init();
  
  /*
  tokenPowerOn();
  tokenEnableTrx();  
  tokenRead(1);
  tokenDisableTrx();
  tokenPowerOff();

  recordProcess();
  full_display(lcdDisInfo);
  deep_sleep();
  */

  delay1ms(10000);  //avoid low power mode an once  
  
  tokenPowerOn();
  tokenEnableTrx();
  delay1ms(10);
  adfCreate();
  delay1ms(100);
  tokenDisableTrx();
  tokenPowerOff();

	while(1) ;
  { 
    if(keyUpPress)
    {
      keyUpPress = 0;
      if(sztRecordNum<10)
      {
        sztRecordNum += 1;
        
        tokenPowerOn();
        tokenEnableTrx();  
        tokenRead(sztRecordNum);
        tokenDisableTrx();
        tokenPowerOff();
        
        recordProcess();
        
        EPD_display_init();        
        full_display(lcdDisInfo);
        deep_sleep();
      }
    }
    else if(keyDownPress)
    {
      keyDownPress = 0;      
      if(sztRecordNum>1)
      {
        sztRecordNum -= 1;
        tokenPowerOn();
        tokenEnableTrx();  
        tokenRead(sztRecordNum);
        tokenDisableTrx();
        tokenPowerOff();
        
        recordProcess();
        
        EPD_display_init();        
        full_display(lcdDisInfo);
        deep_sleep();
      }
    }
    else
    {
      ;
    }
    
    
    LPM_Configuration();
  }
}


//
static void RCC_Configuration(void)
{  
  stc_clk_config_t stcCfg;
  en_result_t enRet = Ok;

  M0P_CLOCK->FCM_CTL = 0;

  ddl_memclr(&stcCfg,sizeof(stcCfg));
  stcCfg.enAPB0Div = ClkApb0Div1;
  stcCfg.enBaseClkDiv = ClkBaseDiv1;
  enRet = Clk_Init(&stcCfg);
  
  Clk_SwitchTo(ClkHICR);
  Clk_SetHICRFreq(ClkHICR16Mhz);
}


static void GPIO_Configuration(void)
{ 
  tokenIOInit();
  paperIOInit();
}


static void NVIC_Configuration(void)
{ 
  ;
}

static void LPM_Configuration(void)
{ 
  stc_dstb_ret_cause_t stcCauseCfg;
  ddl_memclr(&stcCauseCfg,sizeof(stcCauseCfg));
  stcCauseCfg.bWakeup0En = TRUE;
  stcCauseCfg.bWakeup3En = TRUE;
  Lpm_ConfigDeepStbRetCause(&stcCauseCfg);
  Lpm_SetWkupPinLevel(WkupPin0,WkupLowLevelValid);
  Lpm_SetWkupPinLevel(WkupPin3,WkupLowLevelValid);
  Lpm_ConfigDeepStbRAMRetention(TRUE);
  Lpm_GoToStandByMode(DeepStbStopMode, TRUE);
}


static void recordProcess(void)
{
  closeLockTime[0] = (sciRxBuf[21]&0xF0)>>4;
  closeLockTime[1] = (sciRxBuf[21]&0x0F)>>4;
  closeLockTime[3] = (sciRxBuf[22]&0xF0)>>4;
  closeLockTime[4] = (sciRxBuf[22]&0x0F)>>4;
  
  uint32_t userPay = sciRxBuf[6]<<24|sciRxBuf[7]<<16 | \
                      sciRxBuf[8]<<8|sciRxBuf[9];
  userPay = userPay&(~0x80000000);
  pay[0] = userPay%1000000/100000;
  pay[1] = userPay%100000/10000;
  pay[2] = userPay%10000/1000;
  pay[3] = userPay%1000/100;
  pay[4] = '.';
  pay[5] = userPay%100/10;
}







