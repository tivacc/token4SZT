#include <stdio.h>
#include <stdint.h>
#include "ddl.h"
#include "gpio.h"
#include "exint.h"
#include "lvd.h"
#include "paperDrv.h"
#include "tokenCon.h"

//local function 
static void keyUpCallback(void);
static void keyDownCallback(void);
static void LvdIrqCallback(void);

uint8_t keyUpPress = 0;
uint8_t keyDownPress = 0;


static void keyUpCallback(void)
{
  keyUpPress = 1;
  Exint_Nmi_IrqFlagClear();
}


static void keyDownCallback(void)
{
  keyDownPress = 1;
}

static void LvdIrqCallback(void)
{
  ;
}


void bspConfig(void) 
{
   stc_exint_nmi_config_t stcNmiConfig;

  // Congfigure NMI    
  DDL_ZERO_STRUCT(stcNmiConfig);
  stcNmiConfig.pfnNmiCallback = keyUpCallback;
  
  Exint_Nmi_Init(&stcNmiConfig);
  Gpio_SetFunc_NMIX(0u); 	                  // Pin Function: NMIX
  
	stc_exint_config_t stcExintConfig;
  DDL_ZERO_STRUCT(stcExintConfig);
  
  Gpio_SetFunc_INT00_2(0u);
	stcExintConfig.bEnable = 1u;
	stcExintConfig.enLevel = ExIntFallingEdge;
	stcExintConfig.pfnExintCallback = keyDownCallback;
	stcExintConfig.bTouchNvic = TRUE;
	Exint_Init(ExintInstanceIndexExint0, &stcExintConfig);

	DDL_ZERO_STRUCT(stcExintConfig);
  
  /*
  stc_lvd1_config_t   stcCfg;
  uint32_t u32val = 0;

  u32val = M0P_WSUNIT->WAKE_ISR;   //clear interrupt to prevent reset repeatly.
  u32val = u32val;                    //dis warning

  DDL_ZERO_STRUCT(stcCfg);

  stcCfg.b10mvDly = FALSE;
  stcCfg.bFilter = FALSE;
  //stcCfg.enFilterTime = LvdFilter16ms;
  stcCfg.bLvdReset = FALSE;
  stcCfg.enInput = LvdInputPIN;
  stcCfg.enIrqType = Lvd1IrqLow;
  stcCfg.enThreshold = Lvd1TH2_50V;
  stcCfg.pfnIrqCbk = LvdIrqCallback;
  
  Lvd1_Init(&stcCfg);
  Lvd_Enable(LvdType1);
  */
}

