#include <stdio.h>
#include <stdint.h>
#include "ddl.h"
#include "gpio.h"
#include "exint.h"
#include "tokenCon.h"

//local function 
static void keyUpCallback(void);
static void keyDownCallback(void);

uint8_t keyUpPress = 0;
uint8_t keyDownPress = 0;


static void keyUpCallback(void)
{
  keyUpPress = 1;
}


static void keyDownCallback(void)
{
  keyDownPress = 1;
}

void bspConfig(void) 
{
	stc_exint_config_t stcExintConfig;

	Gpio_SetFunc_INT07_2(0u); 	                  
	Gpio_SetFunc_INT08_2(0u);
	// Configure interrupt ch.0 and ch.3
	DDL_ZERO_STRUCT(stcExintConfig);

	stcExintConfig.bEnable = 1u;
	stcExintConfig.enLevel = ExIntFallingEdge;
	stcExintConfig.pfnExintCallback = keyUpCallback;
	stcExintConfig.bTouchNvic = TRUE;
	Exint_Init(ExintInstanceIndexExint7, &stcExintConfig);
	stcExintConfig.bEnable = 1u;
	stcExintConfig.enLevel = ExIntFallingEdge;
	stcExintConfig.pfnExintCallback = keyDownCallback;

	stcExintConfig.bTouchNvic = TRUE;

	Exint_Init(ExintInstanceIndexExint8, &stcExintConfig);

	DDL_ZERO_STRUCT(stcExintConfig);
}

