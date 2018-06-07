/******************************************************************************
* Copyright (C) 2016, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd ("HDSC").
*
* BY DOWNLOADING, INSTALLING OR USING THIS SOFTWARE, YOU AGREE TO BE BOUND
* BY ALL THE TERMS AND CONDITIONS OF THIS AGREEMENT.
*
* This software contains source code for use with HDSC
* components. This software is licensed by HDSC to be adapted only
* for use in systems utilizing HDSC components. HDSC shall not be
* responsible for misuse or illegal use of this software for devices not
* supported herein. HDSC is providing this software "AS IS" and will
* not be responsible for issues arising from incorrect user implementation
* of the software.
*
* Disclaimer:
* HDSC MAKES NO WARRANTY, EXPRESS OR IMPLIED, ARISING BY LAW OR OTHERWISE,
* REGARDING THE SOFTWARE (INCLUDING ANY ACOOMPANYING WRITTEN MATERIALS),
* ITS PERFORMANCE OR SUITABILITY FOR YOUR INTENDED USE, INCLUDING,
* WITHOUT LIMITATION, THE IMPLIED WARRANTY OF MERCHANTABILITY, THE IMPLIED
* WARRANTY OF FITNESS FOR A PARTICULAR PURPOSE OR USE, AND THE IMPLIED
* WARRANTY OF NONINFRINGEMENT.
* HDSC SHALL HAVE NO LIABILITY (WHETHER IN CONTRACT, WARRANTY, TORT,
* NEGLIGENCE OR OTHERWISE) FOR ANY DAMAGES WHATSOEVER (INCLUDING, WITHOUT
* LIMITATION, DAMAGES FOR LOSS OF BUSINESS PROFITS, BUSINESS INTERRUPTION,
* LOSS OF BUSINESS INFORMATION, OR OTHER PECUNIARY LOSS) ARISING FROM USE OR
* INABILITY TO USE THE SOFTWARE, INCLUDING, WITHOUT LIMITATION, ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL OR CONSEQUENTIAL DAMAGES OR LOSS OF DATA,
* SAVINGS OR PROFITS,
* EVEN IF Disclaimer HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* YOU ASSUME ALL RESPONSIBILITIES FOR SELECTION OF THE SOFTWARE TO ACHIEVE YOUR
* INTENDED RESULTS, AND FOR THE INSTALLATION OF, USE OF, AND RESULTS OBTAINED
* FROM, THE SOFTWARE.
*
* This software may be replicated in part or whole for the licensed use,
* with the restriction that this Disclaimer and Copyright notice must be
* included with each copy of this software, whether used in part or whole,
* at all times.
*/
/*****************************************************************************/
/** \file main.c
 **
 ** A detailed description is available at
 ** @link exint Group Some description @endlink
 **
 **   - 2016-02-16  1.0  xiaoli First version for Device Driver Library of Module.
 **
 *****************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "exint.h"
#include "gpio.h"
// In this sample, INT00_2 and INT03_2 will be used, check whether these two is
// available first.


uint32_t u32ExtInt0Count = 0, u32ExtInt1Count = 0;
uint32_t u32NmiCount = 0;

/**
 ******************************************************************************
 ** \brief ExtInt0 callback function
 ******************************************************************************/
void Main_ExtInt0Callback(void)
{
    u32ExtInt0Count++;
}

/**
 ******************************************************************************
 ** \brief ExtInt1 callback function
 ******************************************************************************/
void Main_ExtInt1Callback(void)
{
    u32ExtInt1Count++;
}

/**
 ******************************************************************************
 ** \brief NMI callback function
 ******************************************************************************/
void Main_NmiCallback(void)
{
    u32NmiCount++;
    Exint_Nmi_IrqFlagClear();
}

/**
 ******************************************************************************
 ** \brief  Main function
 **
 ** \return uint32_t return value, if needed
 ******************************************************************************/
int32_t main(void)
{
	stc_exint_config_t stcExintConfig;
	//stc_exint_nmi_config_t stcNmiConfig;
	//Gpio_SetFunc_NMIX(0u)
	//DDL_ZERO_STRUCT(stcExintConfig);

	Gpio_SetFunc_INT02_2(0u); 	                  // Pin Function: INT00_0
	Gpio_SetFunc_INT03_1(0u); 	                  // Pin Function: INT03_1

												  // Configure interrupt ch.0 and ch.3
	DDL_ZERO_STRUCT(stcExintConfig);

      stcExintConfig.bEnable = 1u;
	stcExintConfig.enLevel = ExIntFallingEdge;
	stcExintConfig.pfnExintCallback = Main_ExtInt0Callback;
	stcExintConfig.bTouchNvic = TRUE;
	Exint_Init(ExintInstanceIndexExint2, &stcExintConfig);
	stcExintConfig.bEnable = 1u;
	stcExintConfig.enLevel = ExIntFallingEdge;
	stcExintConfig.pfnExintCallback = Main_ExtInt1Callback;

	stcExintConfig.bTouchNvic = TRUE;

	Exint_Init(ExintInstanceIndexExint3, &stcExintConfig);

	DDL_ZERO_STRUCT(stcExintConfig);

    while(1)
    {}
}
