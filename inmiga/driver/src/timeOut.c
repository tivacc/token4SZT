#include "ddl.h"
#include "gpio.h"
#include "clk.h"
#include "ct.h"
#include "typedef.h"

#define  CT_CH           CtChannel0
#define  CT_RT_MODE      RtOneshot
#define  CT_TIMER_SIZE   RtSize16Bit

uint8_t timeOutFlag = 0;

static void RtTrigIrqHandler(void)
{
    
}

static void RtUnderflowIrqHandler(void)
{
  timeOutFlag = 1;
}

void timeOutStart(uint16_t value)
{
  stc_rt_irq_en_t    stcIrqEn;
  stc_rt_irq_cb_t    stcIrqCb;
  stc_ct_rt_config_t stcRtConfig;
     
  /* Clear structures */
  ddl_memclr((uint8_t*)&stcIrqEn, (uint32_t)(sizeof(stcIrqEn)));
  ddl_memclr((uint8_t*)&stcIrqCb, (uint32_t)(sizeof(stcIrqCb)));
  ddl_memclr((uint8_t*)&stcRtConfig, (uint32_t)(sizeof(stcRtConfig)));

  Ct_ConfigIOMode(CT_CH, CtIoMode0);
  
  Gpio_SetFunc_TIOA0_1(0u);
  
  /* Initialize Pointer to interrupt request structure  */
  stcRtConfig.pstcRtIrqEn = &stcIrqEn;
  stcRtConfig.pstcRtIrqCb = &stcIrqCb;
  /* Initialize Composite Timer  */
  stcRtConfig.enPres = RtPresNone; 
  stcRtConfig.enSize = CT_TIMER_SIZE;
  stcRtConfig.enMode = CT_RT_MODE;
  stcRtConfig.enExtTrig = RtExtTiggerDisable;
  stcRtConfig.enOutputPolarity = RtPolarityLow;
  stcRtConfig.pstcRtIrqEn->bRtTrigIrq = 0;
  stcRtConfig.pstcRtIrqEn->bRtUnderflowIrq = 1;
  //stcRtConfig.pstcRtIrqCb->pfnRtTrigIrqCb = RtTrigIrqHandler ;
  stcRtConfig.pstcRtIrqCb->pfnRtUnderflowIrqCb = RtUnderflowIrqHandler;
  stcRtConfig.bTouchNvic = TRUE;
  Ct_Rt_Init(CT_CH, &stcRtConfig);
  
  Ct_Rt_WriteCycleVal(CT_CH, value); 
  Ct_Rt_EnableCount(CT_CH);
  Ct_Rt_EnableSwTrig(CT_CH);
}

void timeOutStop(void)
{
  Ct_Rt_DisableCount(CT_CH);
}