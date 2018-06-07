/*****************************************************************************
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
/** \file gpio.h
 **
 ** GPIO driver
 ** @link GPIO Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of
 **                         Module.
 **
 *****************************************************************************/

#ifndef __GPIO_H__
#define __GPIO_H__

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

//@{

/******************************************************************************
 * Global type definitions
 *****************************************************************************/
typedef enum en_Gpio_dir
{
    GpioDirIn,
    GpioDirOut,
}en_Gpio_dir_t;

/******************************************************************************
 * Global definitions
 *****************************************************************************/

en_result_t Gpio_SetAnalog(uint8_t u8Port, uint8_t u8Pin, boolean_t bFlag);


en_result_t Gpio_InitIO(uint8_t u8Port, uint8_t u8Pin, 
                        en_Gpio_dir_t enDir, boolean_t bPullup,
                        boolean_t bOdr);

void Gpio_SetIO(uint8_t u8Port, uint8_t u8Pin,boolean_t bVal);
boolean_t Gpio_GetIO(uint8_t u8Port, uint8_t u8Pin);

en_result_t FGpio_InitIO(uint8_t u8Port, uint8_t u8Pin, en_Gpio_dir_t enDir);
boolean_t FGpio_GetIO(uint8_t u8Port, uint8_t u8Pin);
void FGpio_SetIO(uint8_t u8Port, uint8_t u8Pin, boolean_t bVal);


/*
    pin function configure macro
*/
#define Gpio_SetFunc_PC1IN_0(x)     do{\
                                        M0P_GPIO->FN6_f.P64 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC1INS = 1;\
                                    }while(0);

#define Gpio_SetFunc_PC1IN_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE06 = 0;\
                                        M0P_GPIO->FN6_f.P62 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC1INS = 2;\
                                    }while(0);

#define Gpio_SetFunc_PC1IN_2(x)     do{\
                                        M0P_GPIO->FN7_f.P71 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC1INS = 3;\
                                    }while(0);

#define Gpio_SetFunc_PC0IN_0(x)     do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC0INS = 1;\
                                    }while(0);

#define Gpio_SetFunc_PC0IN_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE07 = 0;\
                                        M0P_GPIO->FN6_f.P63 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC0INS = 2;\
                                    }while(0);

#define Gpio_SetFunc_PC0IN_2(x)     do{\
                                        M0P_GPIO->FN7_f.P72 = 1;\
                                        M0P_GPIO->FN_SEL00_f.PC0INS = 3;\
                                    }while(0);

#define Gpio_SetFunc_SUBOUT_0(x)    do{\
                                        M0P_GPIO->FN4_f.P45 = 1;\
                                        M0P_GPIO->FN_SEL00_f.SUBOUTE = 1;\
                                    }while(0);

#define Gpio_SetFunc_SUBOUT_1(x)    do{\
                                        bM0P_GPIO_ANALOG_ADE01 = 0;\
                                        M0P_GPIO->FN0_f.P01 = 1;\
                                        M0P_GPIO->FN_SEL00_f.SUBOUTE = 2;\
                                    }while(0);

#define Gpio_SetFunc_SUBOUT_2(x)    do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL00_f.SUBOUTE = 3;\
                                    }while(0);

#define Gpio_SetFunc_RTCO_0(x)      do{\
                                        M0P_GPIO->FN6_f.P66 = 1;\
                                        M0P_GPIO->FN_SEL00_f.RTCCOE = 1;\
                                    }while(0);

#define Gpio_SetFunc_RTCO_1(x)      do{\
                                        M0P_GPIO->FN3_f.P34 = 1;\
                                        M0P_GPIO->FN_SEL00_f.RTCCOE = 2;\
                                    }while(0);

#define Gpio_SetFunc_RTCO_2(x)      do{\
                                        M0P_GPIO->FN2_f.P20 = 1;\
                                        M0P_GPIO->FN_SEL00_f.RTCCOE = 3;\
                                    }while(0);

#define Gpio_SetFunc_IRCO_0(x)      do{\
                                        M0P_GPIO->FN6_f.P67 = 1;\
                                        M0P_GPIO->FN_SEL00_f.CROUTE = 1;\
                                    }while(0);

#define Gpio_SetFunc_IRCO_1(x)      do{\
                                        M0P_GPIO->FN5_f.P55 = 1;\
                                        M0P_GPIO->FN_SEL00_f.CROUTE = 2;\
                                    }while(0);

#define Gpio_SetFunc_IRCO_2(x)      do{\
                                        M0P_GPIO->FN1_f.P11 = 1;\
                                        M0P_GPIO->FN_SEL00_f.CROUTE = 3;\
                                    }while(0);

#define Gpio_SetFunc_NMIX(x)        do{\
                                        bM0P_GPIO_ANALOG_ADE03 = 0;\
                                        M0P_GPIO->FN0_f.P03 = 1;\
                                        M0P_GPIO->FN_SEL00_f.NMIS = 1;\
                                    }while(0);

//
#define Gpio_SetFunc_TIOB3_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE09 = 0;\
                                        M0P_GPIO->FN5_f.P51 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB3S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB3_1(x)     do{\
                                        M0P_GPIO->FN1_f.P12 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB3S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB3_2(x)     do{\
                                        M0P_GPIO->FN4_f.P41 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB3S = 3;\
                                    }while(0);


#define Gpio_SetFunc_TIOA3_0_OUT(x) do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA3_1_OUT(x) do{\
                                        M0P_GPIO->FN1_f.P11 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA3_2_OUT(x) do{\
                                        M0P_GPIO->FN4_f.P40 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3E = 3;\
                                    }while(0);


#define Gpio_SetFunc_TIOA3_0_IN(x)  do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA3_1_IN(x)  do{\
                                        M0P_GPIO->FN1_f.P11 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA3_2_IN(x)  do{\
                                        M0P_GPIO->FN4_f.P40 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA3S = 3;\
                                    }while(0);


#define Gpio_SetFunc_TIOB2_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE11 = 0;\
                                        M0P_GPIO->FN5_f.P53 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB2S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB2_1(x)     do{\
                                        M0P_GPIO->FN1_f.P14 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB2S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB2_2(x)     do{\
                                        M0P_GPIO->FN4_f.P47 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB2S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA2_0(x)    do{\
                                        bM0P_GPIO_ANALOG_ADE10 = 0;\
                                        M0P_GPIO->FN5_f.P52 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA2E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA2_1(x)    do{\
                                        M0P_GPIO->FN1_f.P13 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA2E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA2_2(x)    do{\
                                        M0P_GPIO->FN4_f.P46 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA2E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB1_0(x)    do{\
                                        M0P_GPIO->FN1_f.P17 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB1S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB1_1(x)    do{\
                                        M0P_GPIO->FN3_f.P31 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB1S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB1_2(x)    do{\
                                        bM0P_GPIO_ANALOG_ADE01 = 0;\
                                        M0P_GPIO->FN0_f.P01 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB1S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_0_OUT(x) do{\
                                        M0P_GPIO->FN1_f.P16 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_1_OUT(x) do{\
                                        M0P_GPIO->FN3_f.P30 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_2_OUT(x) do{\
                                        bM0P_GPIO_ANALOG_ADE00 = 0;\
                                        M0P_GPIO->FN0_f.P00 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_0_IN(x) do{\
                                        M0P_GPIO->FN1_f.P16 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_1_IN(x) do{\
                                        M0P_GPIO->FN3_f.P30 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA1_2_IN(x) do{\
                                        bM0P_GPIO_ANALOG_ADE00 = 0;\
                                        M0P_GPIO->FN0_f.P00 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA1S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB0_0(x)     do{\
                                        M0P_GPIO->FN1_f.P15 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB0_1(x)     do{\
                                        M0P_GPIO->FN1_f.P10 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB0_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE03 = 0;\
                                        M0P_GPIO->FN0_f.P03 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA0_0(x)     do{\
                                        M0P_GPIO->FN1_f.P14 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA0E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA0_1(x)     do{\
                                        M0P_GPIO->FN2_f.P20 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA0E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA0_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE02 = 0;\
                                        M0P_GPIO->FN0_f.P02 = 1;\
                                        M0P_GPIO->FN_SEL02_f.TIOA0E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB7_0(x)     do{\
                                        M0P_GPIO->FN5_f.P57 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB7S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB7_1(x)     do{\
                                        M0P_GPIO->FN2_f.P24 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB7S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB7_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE04 = 0;\
                                        M0P_GPIO->FN6_f.P60 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB7S = 3;\
                                    }while(0);


#define Gpio_SetFunc_TIOA7_0_OUT(x) do{\
                                        M0P_GPIO->FN5_f.P56 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA7_1_OUT(x) do{\
                                        M0P_GPIO->FN2_f.P23 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA7_2_OUT(x) do{\
                                        bM0P_GPIO_ANALOG_ADE05 = 0;\
                                        M0P_GPIO->FN6_f.P61 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA7_0_IN(x)  do{\
                                        M0P_GPIO->FN5_f.P56 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA7_1_IN(x)  do{\
                                        M0P_GPIO->FN2_f.P23 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA7_2_IN(x)  do{\
                                        bM0P_GPIO_ANALOG_ADE05 = 0;\
                                        M0P_GPIO->FN6_f.P61 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA7S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB6_0(x)     do{\
                                        M0P_GPIO->FN5_f.P55 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB6S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB6_1(x)     do{\
                                        M0P_GPIO->FN2_f.P22 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB6S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB6_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE06 = 0;\
                                        M0P_GPIO->FN6_f.P62 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB6S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA6_0(x)     do{\
                                        M0P_GPIO->FN5_f.P54 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA6E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA6_1(x)     do{\
                                        M0P_GPIO->FN2_f.P21 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA6E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA6_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE07 = 0;\
                                        M0P_GPIO->FN6_f.P63 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA6E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB5_0(x)     do{\
                                        M0P_GPIO->FN0_f.P07 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB5S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB5_1(x)     do{\
                                        M0P_GPIO->FN3_f.P37 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB5S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB5_2(x)     do{\
                                        M0P_GPIO->FN6_f.P64 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB5S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_0_OUT(x) do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_1_OUT(x) do{\
                                        M0P_GPIO->FN2_f.P27 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_2_OUT(x) do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5E = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_0_IN(x)  do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_1_IN(x)  do{\
                                        M0P_GPIO->FN2_f.P27 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA5_2_IN(x)  do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA5S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOB4_0(x)     do{\
                                        M0P_GPIO->FN0_f.P05 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB4S = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOB4_1(x)     do{\
                                        M0P_GPIO->FN2_f.P26 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB4S = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOB4_2(x)     do{\
                                        M0P_GPIO->FN6_f.P66 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOB4S = 3;\
                                    }while(0);

#define Gpio_SetFunc_TIOA4_0(x)     do{\
                                        M0P_GPIO->FN0_f.P04 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA4E = 1;\
                                    }while(0);

#define Gpio_SetFunc_TIOA4_1(x)     do{\
                                        M0P_GPIO->FN2_f.P25 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA4E = 2;\
                                    }while(0);

#define Gpio_SetFunc_TIOA4_2(x)     do{\
                                        M0P_GPIO->FN6_f.P67 = 1;\
                                        M0P_GPIO->FN_SEL03_f.TIOA4E = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT15_0(x)     do{\
                                        M0P_GPIO->FN1_f.P13 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT15S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT15_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE04 = 0;\
                                        M0P_GPIO->FN6_f.P60 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT15S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT15_2(x)     do{\
                                        M0P_GPIO->FN1_f.P17 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT15S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT14_0(x)     do{\
                                        M0P_GPIO->FN1_f.P12 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT14S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT14_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE05 = 0;\
                                        M0P_GPIO->FN6_f.P61 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT14S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT14_2(x)     do{\
                                        M0P_GPIO->FN1_f.P16 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT14S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT13_0(x)     do{\
                                        M0P_GPIO->FN1_f.P11 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT13S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT13_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE09 = 0;\
                                        M0P_GPIO->FN5_f.P51 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT13S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT13_2(x)     do{\
                                        M0P_GPIO->FN1_f.P15 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT13S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT12_0(x)     do{\
                                        M0P_GPIO->FN1_f.P10 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT12S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT12_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT12S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT12_2(x)     do{\
                                        M0P_GPIO->FN1_f.P14 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT12S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT11_0(x)     do{\
                                        M0P_GPIO->FN5_f.P57 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT11S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT11_1(x)     do{\
                                        M0P_GPIO->FN3_f.P35 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT11S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT11_2(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE07 = 0;\
                                        M0P_GPIO->FN6_f.P63 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT11S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT10_0(x)     do{\
                                        M0P_GPIO->FN5_f.P56 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT10S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT10_1(x)     do{\
                                        M0P_GPIO->FN3_f.P36 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT10S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT10_2(x)     do{\
                                        M0P_GPIO->FN6_f.P64 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT10S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT09_0(x)     do{\
                                        M0P_GPIO->FN5_f.P55 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT09S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT09_1(x)     do{\
                                        M0P_GPIO->FN3_f.P37 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT09S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT09_2(x)     do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT09S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT08_0(x)     do{\
                                        M0P_GPIO->FN5_f.P54 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT08S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT08_1(x)     do{\
                                        M0P_GPIO->FN7_f.P70 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT08S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT08_2(x)     do{\
                                        M0P_GPIO->FN2_f.P24 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT08S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT07_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE11 = 0;\
                                        M0P_GPIO->FN5_f.P53 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT07S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT07_1(x)     do{\
                                        M0P_GPIO->FN7_f.P71 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT07S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT07_2(x)     do{\
                                        M0P_GPIO->FN2_f.P23 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT07S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT06_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE10 = 0;\
                                        M0P_GPIO->FN5_f.P52 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT06S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT06_1(x)     do{\
                                        M0P_GPIO->FN7_f.P72 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT06S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT06_2(x)     do{\
                                        M0P_GPIO->FN2_f.P25 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT06S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT05_0(x)     do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT05S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT05_1(x)     do{\
                                        M0P_GPIO->FN7_f.P73 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT05S = 2;\
                                    }while(0);


#define Gpio_SetFunc_INT04_0(x)     do{\
                                        M0P_GPIO->FN0_f.P05 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT04S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT04_1(x)     do{\
                                        M0P_GPIO->FN7_f.P74 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT04S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT03_0(x)     do{\
                                        M0P_GPIO->FN0_f.P04 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT03S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT03_1(x)     do{\
                                        M0P_GPIO->FN2_f.P27 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT03S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT03_2(x)     do{\
                                        M0P_GPIO->FN2_f.P22 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT03S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT02_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE02 = 0;\
                                        M0P_GPIO->FN0_f.P02 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT02S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT02_1(x)     do{\
                                        M0P_GPIO->FN2_f.P26 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT02S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT02_2(x)     do{\
                                        M0P_GPIO->FN2_f.P21 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT02S = 3;\
                                    }while(0);

#define Gpio_SetFunc_INT01_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE01 = 0;\
                                        M0P_GPIO->FN0_f.P01 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT01S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT01_1(x)     do{\
                                        M0P_GPIO->FN6_f.P67 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT01S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT00_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE00 = 0;\
                                        M0P_GPIO->FN0_f.P00 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT00S = 1;\
                                    }while(0);

#define Gpio_SetFunc_INT00_1(x)     do{\
                                        M0P_GPIO->FN4_f.P45 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT00S = 2;\
                                    }while(0);

#define Gpio_SetFunc_INT00_2(x)     do{\
                                        M0P_GPIO->FN2_f.P20 = 1;\
                                        M0P_GPIO->FN_SEL04_f.EINT00S = 3;\
                                    }while(0);

#define Gpio_SetFunc_SCS10_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE01 = 0;\
                                        M0P_GPIO->FN0_f.P01 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCS10B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS10_1(x)     do{\
                                        M0P_GPIO->FN2_f.P27 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCS10B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK1_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE00 = 0;\
                                        M0P_GPIO->FN0_f.P00 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK1B = 1;\
                                    }while(0);
#define Gpio_SetFunc_SCK1_1(x)     do{\
                                        M0P_GPIO->FN2_f.P26 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK1B = 2;\
                                    }while(0);
#define Gpio_SetFunc_SCK1_2(x)     do{\
                                        M0P_GPIO->FN1_f.P13 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK1B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SOT1_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE11 = 0;\
                                        M0P_GPIO->FN5_f.P53 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT1B = 1;\
                                    }while(0);
#define Gpio_SetFunc_SOT1_1(x)     do{\
                                        M0P_GPIO->FN2_f.P25 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT1B = 2;\
                                    }while(0);
#define Gpio_SetFunc_SOT1_2(x)     do{\
                                        M0P_GPIO->FN2_f.P20 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT1B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SIN1_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE10 = 0;\
                                        M0P_GPIO->FN5_f.P52 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN1S = 1;\
                                    }while(0);
#define Gpio_SetFunc_SIN1_1(x)     do{\
                                        M0P_GPIO->FN2_f.P24 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN1S = 2;\
                                    }while(0);
#define Gpio_SetFunc_SIN1_2(x)     do{\
                                        M0P_GPIO->FN2_f.P21 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN1S = 3;\
                                    }while(0);

#define Gpio_SetFunc_CTS1_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL05_f.CTS1S = 1;\
                                    }while(0);

#define Gpio_SetFunc_CTS1_2(x)     do{\
                                        M0P_GPIO->FN2_f.P22 = 1;\
                                        M0P_GPIO->FN_SEL05_f.CTS1S = 3;\
                                    }while(0);

#define Gpio_SetFunc_RTS1_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE09 = 0;\
                                        M0P_GPIO->FN5_f.P51 = 1;\
                                        M0P_GPIO->FN_SEL05_f.RTS1E = 1;\
                                    }while(0);
#define Gpio_SetFunc_RTS1_2(x)     do{\
                                        M0P_GPIO->FN2_f.P23 = 1;\
                                        M0P_GPIO->FN_SEL05_f.RTS1E = 3;\
                                    }while(0);

#define Gpio_SetFunc_SCK0_0(x)     do{\
                                        M0P_GPIO->FN1_f.P13 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK0B = 1;\
                                    }while(0);
#define Gpio_SetFunc_SCK0_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE10 = 0;\
                                        M0P_GPIO->FN5_f.P52 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK0B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK0_2(x)     do{\
                                        M0P_GPIO->FN4_f.P45 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SCK0B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SOT0_0(x)     do{\
                                        M0P_GPIO->FN1_f.P12 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT0B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SOT0_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE09 = 0;\
                                        M0P_GPIO->FN5_f.P51 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT0B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SOT0_2(x)     do{\
                                        M0P_GPIO->FN6_f.P67 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SOT0B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SIN0_0(x)     do{\
                                        M0P_GPIO->FN1_f.P11 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN0S = 1;\
                                    }while(0);

#define Gpio_SetFunc_SIN0_1(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN0S = 2;\
                                    }while(0);

#define Gpio_SetFunc_SIN0_2(x)      do{\
                                        M0P_GPIO->FN6_f.P66 = 1;\
                                        M0P_GPIO->FN_SEL05_f.SIN0S = 3;\
                                    }while(0);

#define Gpio_SetFunc_SCS22_0(x)     do{\
                                        M0P_GPIO->FN1_f.P10 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SCS22E = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS21_0(x)     do{\
                                        M0P_GPIO->FN5_f.P54 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SCS21E = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS20_0(x)     do{\
                                        M0P_GPIO->FN0_f.P07 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SCS20B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCK2_0(x)      do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SCK2B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCK2_1(x)      do{\
                                        M0P_GPIO->FN4_f.P40 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SCK2B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SOT2_0(x)      do{\
                                        M0P_GPIO->FN0_f.P05 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SOT2B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SOT2_1(x)      do{\
                                        M0P_GPIO->FN4_f.P41 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SOT2B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SIN2S_0(x)     do{\
                                        M0P_GPIO->FN0_f.P04 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SIN2S = 1;\
                                    }while(0);

#define Gpio_SetFunc_SIN2S_1(x)    do{\
                                        M0P_GPIO->FN4_f.P40 = 1;\
                                        M0P_GPIO->FN_SEL06_f.SIN2S = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCS50_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE03 = 0;\
                                        M0P_GPIO->FN0_f.P03 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS50B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS50_1(x)     do{\
                                        M0P_GPIO->FN2_f.P27 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS50B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCS50_2(x)     do{\
                                        M0P_GPIO->FN2_f.P21 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS50B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SCK5_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE02 = 0;\
                                        M0P_GPIO->FN0_f.P02 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK5B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCK5_1(x)      do{\
                                        M0P_GPIO->FN3_f.P37 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK5B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK5_2(x)      do{\
                                        M0P_GPIO->FN2_f.P23 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK5B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SOT5_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE01 = 0;\
                                        M0P_GPIO->FN0_f.P01 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT5B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SOT5_1(x)      do{\
                                        M0P_GPIO->FN3_f.P36 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT5B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SOT5_2(x)      do{\
                                        M0P_GPIO->FN2_f.P22 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT5B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SIN5_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE00 = 0;\
                                        M0P_GPIO->FN0_f.P00 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN5S = 1;\
                                    }while(0);

#define Gpio_SetFunc_SIN5_1(x)      do{\
                                        M0P_GPIO->FN7_f.P74 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN5S = 2;\
                                    }while(0);

#define Gpio_SetFunc_SIN5_2(x)      do{\
                                        M0P_GPIO->FN2_f.P20 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN5S = 3;\
                                    }while(0);

#define Gpio_SetFunc_SCS41_1(x)     do{\
                                        M0P_GPIO->FN5_f.P56 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS41E = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCS40_0(x)     do{\
                                        M0P_GPIO->FN7_f.P74 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS40B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS40_1(x)     do{\
                                        M0P_GPIO->FN5_f.P57 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCS40B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK4_0(x)      do{\
                                        M0P_GPIO->FN7_f.P73 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK4B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCK4_1(x)      do{\
                                        M0P_GPIO->FN5_f.P54 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK4B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK4_2(x)      do{\
                                        M0P_GPIO->FN4_f.P46 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SCK4B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SOT4_0(x)      do{\
                                        M0P_GPIO->FN7_f.P72 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT4B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SOT4_1(x)      do{\
                                        M0P_GPIO->FN5_f.P55 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT4B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SOT4_2(x)      do{\
                                        M0P_GPIO->FN4_f.P47 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SOT4B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SIN4_0(x)      do{\
                                        M0P_GPIO->FN7_f.P71 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN4S = 1;\
                                    }while(0);

#define Gpio_SetFunc_SIN4_1(x)      do{\
                                        M0P_GPIO->FN5_f.P56 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN4S = 2;\
                                    }while(0);

#define Gpio_SetFunc_SIN4_2(x)      do{\
                                        M0P_GPIO->FN4_f.P46 = 1;\
                                        M0P_GPIO->FN_SEL07_f.SIN4S = 3;\
                                    }while(0);

#define Gpio_SetFunc_CTS4_0(x)      do{\
                                        M0P_GPIO->FN3_f.P35 = 1;\
                                        M0P_GPIO->FN_SEL07_f.CTS4S = 1;\
                                    }while(0);

#define Gpio_SetFunc_CTS4_1(x)      do{\
                                        M0P_GPIO->FN5_f.P54 = 1;\
                                        M0P_GPIO->FN_SEL07_f.CTS4S = 2;\
                                    }while(0);

#define Gpio_SetFunc_RTS4_0(x)      do{\
                                        M0P_GPIO->FN7_f.P73 = 1;\
                                        M0P_GPIO->FN_SEL07_f.RTS4E = 1;\
                                    }while(0);

#define Gpio_SetFunc_RTS4_1(x)      do{\
                                        M0P_GPIO->FN5_f.P57 = 1;\
                                        M0P_GPIO->FN_SEL07_f.RTS4E = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCS62_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE04 = 0;\
                                        M0P_GPIO->FN6_f.P60 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCS62E = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS61_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE05 = 0;\
                                        M0P_GPIO->FN6_f.P61 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCS61E = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS60_0(x)     do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCS60B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCS60_1(x)     do{\
                                        M0P_GPIO->FN1_f.P17 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCS60B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK6_0(x)      do{\
                                        M0P_GPIO->FN6_f.P64 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCK6B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SCK6_1(x)      do{\
                                        M0P_GPIO->FN1_f.P16 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCK6B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SCK6_2(x)      do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SCK6B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SOT6_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE07 = 0;\
                                        M0P_GPIO->FN6_f.P63 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SOT6B = 1;\
                                    }while(0);

#define Gpio_SetFunc_SOT6_1(x)      do{\
                                        M0P_GPIO->FN1_f.P15 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SOT6B = 2;\
                                    }while(0);

#define Gpio_SetFunc_SOT6_2(x)      do{\
                                        M0P_GPIO->FN0_f.P07 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SOT6B = 3;\
                                    }while(0);

#define Gpio_SetFunc_SIN6_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE06 = 0;\
                                        M0P_GPIO->FN6_f.P62 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SIN6S = 1;\
                                    }while(0);

#define Gpio_SetFunc_SIN6_1(x)      do{\
                                        M0P_GPIO->FN1_f.P14 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SIN6S = 2;\
                                    }while(0);

#define Gpio_SetFunc_SIN6_2(x)      do{\
                                        M0P_GPIO->FN0_f.P06 = 1;\
                                        M0P_GPIO->FN_SEL08_f.SIN6S = 3;\
                                    }while(0);

#define Gpio_SetFunc_CTS6_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE04 = 0;\
                                        M0P_GPIO->FN6_f.P60 = 1;\
                                        M0P_GPIO->FN_SEL08_f.CTS6S = 1;\
                                    }while(0);

#define Gpio_SetFunc_RTS6_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE05 = 0;\
                                        M0P_GPIO->FN6_f.P61 = 1;\
                                        M0P_GPIO->FN_SEL08_f.RTS6E = 1;\
                                    }while(0);

#define Gpio_SetFunc_ICRST_0(x)     do{\
                                        bM0P_GPIO_ANALOG_ADE10 = 0;\
                                        M0P_GPIO->FN5_f.P52 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICRSTE = 1;\
                                    }while(0);

#define Gpio_SetFunc_ICRST_1(x)     do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICRSTE = 2;\
                                    }while(0);

#define Gpio_SetFunc_ICIO_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE09 = 0;\
                                        M0P_GPIO->FN5_f.P51 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICIOB = 1;\
                                    }while(0);

#define Gpio_SetFunc_ICIO_1(x)      do{\
                                        M0P_GPIO->FN6_f.P64 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICIOB = 2;\
                                    }while(0);

#define Gpio_SetFunc_ICCK_0(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE08 = 0;\
                                        M0P_GPIO->FN5_f.P50 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICCKE = 1;\
                                    }while(0);

#define Gpio_SetFunc_ICCK_1(x)      do{\
                                        bM0P_GPIO_ANALOG_ADE07 = 0;\
                                        M0P_GPIO->FN6_f.P63 = 1;\
                                        M0P_GPIO->FN_SEL09_f.ICCKE = 2;\
                                    }while(0);

#define Gpio_SetFunc_BZ_0(x)        do{\
                                        bM0P_GPIO_ANALOG_ADE11 = 0;\
                                        M0P_GPIO->FN5_f.P53 = 1;\
                                        M0P_GPIO->FN_SEL09_f.BZOE = 1;\
                                    }while(0);

#define Gpio_SetFunc_BZ_1(x)        do{\
                                        M0P_GPIO->FN3_f.P35 = 1;\
                                        M0P_GPIO->FN_SEL09_f.BZOE = 2;\
                                    }while(0);

#define Gpio_SetFunc_BZ_2(x)        do{\
                                        M0P_GPIO->FN1_f.P13 = 1;\
                                        M0P_GPIO->FN_SEL09_f.BZOE = 3;\
                                    }while(0);

#define Gpio_SetFunc_CAOUT_0(x)     do{\
                                        M0P_GPIO->FN6_f.P65 = 1;\
                                        M0P_GPIO->FN_SEL09_f.VCOE = 1;\
                                    }while(0);

#define Gpio_SetFunc_CAOUT_1(x)     do{\
                                        M0P_GPIO->FN1_f.P10 = 1;\
                                        M0P_GPIO->FN_SEL09_f.VCOE = 2;\
                                    }while(0);

#define Gpio_SetFunc_CAOUT_2(x)     do{\
                                        M0P_GPIO->FN3_f.P35 = 1;\
                                        M0P_GPIO->FN_SEL09_f.VCOE = 3;\
                                    }while(0);

//wake up, x = enable level
#define Gpio_SetFunc_WKUP0(x)       do{\
                                        M0P_WSUNIT->WAKE_IER_f.REWU0E = 1;\
                                        M0P_WSUNIT->WAKE_LVR_f.WUI0LV = (x);\
                                    }while(0);

#define Gpio_SetFunc_WKUP1(x)       do{\
                                        M0P_WSUNIT->WAKE_IER_f.REWU1E = 1;\
                                        M0P_WSUNIT->WAKE_LVR_f.WUI1LV = (x);\
                                    }while(0);

#define Gpio_SetFunc_WKUP2(x)       do{\
                                        M0P_WSUNIT->WAKE_IER_f.REWU2E = 1;\
                                        M0P_WSUNIT->WAKE_LVR_f.WUI2LV = (x);\
                                    }while(0);

#define Gpio_SetFunc_WKUP3(x)       do{\
                                        M0P_WSUNIT->WAKE_IER_f.REWU3E = 1;\
                                        M0P_WSUNIT->WAKE_LVR_f.WUI3LV = (x);\
                                    }while(0);

#define Gpio_SetFunc_LVDIHZ(x)      do{\
                                        M0P_GPIO->SPS_f.LVDIE = (x);\
                                    }while(0);

//
#define Gpio_SetFunc_SWDEN(x)       do{\
                                        M0P_GPIO->FN_SEL00_f.SWDEN = (x);\
                                    }while(0);

#define Gpio_SetFunc_NMIEN(x)       do{\
                                        M0P_GPIO->FN_SEL00_f.NMIS = (x);\
                                    }while(0);

#define Gpio_SetFunc_VC2TM2(x)      do{\
                                        M0P_GPIO->FN_SEL02_f.TIOB2S = 4;\
                                    }while(0);

#define Gpio_SetFunc_VC2TM0(x)      do{\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 4;\
                                    }while(0);

#define Gpio_SetFunc_SUBOUT(x)      do{\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 6;\
                                    }while(0);

#define Gpio_SetFunc_TRIMMING(x)    do{\
                                        M0P_GPIO->FN_SEL02_f.TIOB0S = 7;\
                                    }while(0);



//Fast GPIO BitMap (FGET, FSET)
#define MOP_FGPIO_FGET0             (0xF8010000)
#define MOP_FGPIO_FGET1             (0xF8010400)
#define MOP_FGPIO_FGET2             (0xF8010800)
#define MOP_FGPIO_FGET3             (0xF8010C00)
#define MOP_FGPIO_FGET4             (0xF8011000)
#define MOP_FGPIO_FGET5             (0xF8011400)
#define MOP_FGPIO_FGET6             (0xF8011800)
#define MOP_FGPIO_FGET7             (0xF8011C00)
#define MOP_FGPIO_FGET8             (0xF8012000)

#define MOP_FGPIO_FSET0             (0xF8014000)
#define MOP_FGPIO_FSET1             (0xF8014400)
#define MOP_FGPIO_FSET2             (0xF8014800)
#define MOP_FGPIO_FSET3             (0xF8014C00)
#define MOP_FGPIO_FSET4             (0xF8015000)
#define MOP_FGPIO_FSET5             (0xF8015400)
#define MOP_FGPIO_FSET6             (0xF8015800)
#define MOP_FGPIO_FSET7             (0xF8015C00)
#define MOP_FGPIO_FSET8             (0xF8016000)


//#define bM0P_FASTIO_FSET(port,pin)  bM0P_FASTIO_FSET##port_P##

#define bM0P_FASTIO_FGET0_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x4))
#define bM0P_FASTIO_FGET0_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x8))
#define bM0P_FASTIO_FGET0_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x10))
#define bM0P_FASTIO_FGET0_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x20))
#define bM0P_FASTIO_FGET0_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x40))
#define bM0P_FASTIO_FGET0_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x80))
#define bM0P_FASTIO_FGET0_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x100))
#define bM0P_FASTIO_FGET0_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET0 + 0x200))

#define bM0P_FASTIO_FGET1_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x4))
#define bM0P_FASTIO_FGET1_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x8))
#define bM0P_FASTIO_FGET1_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x10))
#define bM0P_FASTIO_FGET1_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x20))
#define bM0P_FASTIO_FGET1_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x40))
#define bM0P_FASTIO_FGET1_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x80))
#define bM0P_FASTIO_FGET1_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x100))
#define bM0P_FASTIO_FGET1_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET1 + 0x200))

#define bM0P_FASTIO_FGET2_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x4))
#define bM0P_FASTIO_FGET2_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x8))
#define bM0P_FASTIO_FGET2_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x10))
#define bM0P_FASTIO_FGET2_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x20))
#define bM0P_FASTIO_FGET2_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x40))
#define bM0P_FASTIO_FGET2_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x80))
#define bM0P_FASTIO_FGET2_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x100))
#define bM0P_FASTIO_FGET2_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET2 + 0x200))

#define bM0P_FASTIO_FGET3_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x4))
#define bM0P_FASTIO_FGET3_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x8))
#define bM0P_FASTIO_FGET3_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x40))
#define bM0P_FASTIO_FGET3_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x80))
#define bM0P_FASTIO_FGET3_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x100))
#define bM0P_FASTIO_FGET3_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET3 + 0x200))

#define bM0P_FASTIO_FGET4_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET4 + 0x4))
#define bM0P_FASTIO_FGET4_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET4 + 0x8))
#define bM0P_FASTIO_FGET4_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET4 + 0x80))
#define bM0P_FASTIO_FGET4_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET4 + 0x100))
#define bM0P_FASTIO_FGET4_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET4 + 0x200))

#define bM0P_FASTIO_FGET5_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x4))
#define bM0P_FASTIO_FGET5_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x8))
#define bM0P_FASTIO_FGET5_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x10))
#define bM0P_FASTIO_FGET5_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x20))
#define bM0P_FASTIO_FGET5_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x40))
#define bM0P_FASTIO_FGET5_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x80))
#define bM0P_FASTIO_FGET5_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x100))
#define bM0P_FASTIO_FGET5_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET5 + 0x200))

#define bM0P_FASTIO_FGET6_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x4))
#define bM0P_FASTIO_FGET6_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x8))
#define bM0P_FASTIO_FGET6_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x10))
#define bM0P_FASTIO_FGET6_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x20))
#define bM0P_FASTIO_FGET6_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x40))
#define bM0P_FASTIO_FGET6_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x80))
#define bM0P_FASTIO_FGET6_P6        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x100))
#define bM0P_FASTIO_FGET6_P7        (*(volatile uint8_t *)(MOP_FGPIO_FGET6 + 0x200))

#define bM0P_FASTIO_FGET7_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x4))
#define bM0P_FASTIO_FGET7_P1        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x8))
#define bM0P_FASTIO_FGET7_P2        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x10))
#define bM0P_FASTIO_FGET7_P3        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x20))
#define bM0P_FASTIO_FGET7_P4        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x40))
#define bM0P_FASTIO_FGET7_P5        (*(volatile uint8_t *)(MOP_FGPIO_FGET7 + 0x80))

#define bM0P_FASTIO_FGET8_P0        (*(volatile uint8_t *)(MOP_FGPIO_FGET8 + 0x4))


#define bM0P_FASTIO_FSET0_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x4))
#define bM0P_FASTIO_FSET0_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x8))
#define bM0P_FASTIO_FSET0_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x10))
#define bM0P_FASTIO_FSET0_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x20))
#define bM0P_FASTIO_FSET0_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x40))
#define bM0P_FASTIO_FSET0_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x80))
#define bM0P_FASTIO_FSET0_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x100))
#define bM0P_FASTIO_FSET0_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET0 + 0x200))

#define bM0P_FASTIO_FSET1_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x4))
#define bM0P_FASTIO_FSET1_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x8))
#define bM0P_FASTIO_FSET1_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x10))
#define bM0P_FASTIO_FSET1_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x20))
#define bM0P_FASTIO_FSET1_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x40))
#define bM0P_FASTIO_FSET1_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x80))
#define bM0P_FASTIO_FSET1_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x100))
#define bM0P_FASTIO_FSET1_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET1 + 0x200))

#define bM0P_FASTIO_FSET2_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x4))
#define bM0P_FASTIO_FSET2_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x8))
#define bM0P_FASTIO_FSET2_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x10))
#define bM0P_FASTIO_FSET2_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x20))
#define bM0P_FASTIO_FSET2_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x40))
#define bM0P_FASTIO_FSET2_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x80))
#define bM0P_FASTIO_FSET2_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x100)) 
#define bM0P_FASTIO_FSET2_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET2 + 0x200))

#define bM0P_FASTIO_FSET3_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x4))
#define bM0P_FASTIO_FSET3_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x8))
#define bM0P_FASTIO_FSET3_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x40))
#define bM0P_FASTIO_FSET3_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x80))
#define bM0P_FASTIO_FSET3_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x100))
#define bM0P_FASTIO_FSET3_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET3 + 0x200))

#define bM0P_FASTIO_FSET4_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET4 + 0x4))
#define bM0P_FASTIO_FSET4_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET4 + 0x8))
#define bM0P_FASTIO_FSET4_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET4 + 0x80))
#define bM0P_FASTIO_FSET4_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET4 + 0x100))
#define bM0P_FASTIO_FSET4_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET4 + 0x200))

#define bM0P_FASTIO_FSET5_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x4))
#define bM0P_FASTIO_FSET5_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x8))
#define bM0P_FASTIO_FSET5_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x10))
#define bM0P_FASTIO_FSET5_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x20))
#define bM0P_FASTIO_FSET5_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x40))
#define bM0P_FASTIO_FSET5_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x80))
#define bM0P_FASTIO_FSET5_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x100))
#define bM0P_FASTIO_FSET5_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET5 + 0x200))

#define bM0P_FASTIO_FSET6_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x4))
#define bM0P_FASTIO_FSET6_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x8))
#define bM0P_FASTIO_FSET6_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x10))
#define bM0P_FASTIO_FSET6_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x20))
#define bM0P_FASTIO_FSET6_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x40))
#define bM0P_FASTIO_FSET6_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x80))
#define bM0P_FASTIO_FSET6_P6        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x100))
#define bM0P_FASTIO_FSET6_P7        (*(volatile uint8_t *)(MOP_FGPIO_FSET6 + 0x200))


#define bM0P_FASTIO_FSET7_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x4))
#define bM0P_FASTIO_FSET7_P1        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x8))
#define bM0P_FASTIO_FSET7_P2        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x10))
#define bM0P_FASTIO_FSET7_P3        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x20))
#define bM0P_FASTIO_FSET7_P4        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x40))
#define bM0P_FASTIO_FSET7_P5        (*(volatile uint8_t *)(MOP_FGPIO_FSET7 + 0x80))

#define bM0P_FASTIO_FSET8_P0        (*(volatile uint8_t *)(MOP_FGPIO_FSET8 + 0x4))


/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')
 ******************************************************************************/

/******************************************************************************
  Global function prototypes (definition in C source)
*******************************************************************************/


//@} // GPIO Group

#ifdef __cplusplus
}
#endif

#endif /* __GPIO_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

