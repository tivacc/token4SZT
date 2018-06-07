/*******************************************************************************
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
/******************************************************************************/
/** \file ddl.h
 **
 ** DDL common define.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __DDL_H__
#define __DDL_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "base_types.h"
#include "hc32l15.h"


/* C binding of definitions if building with C++ compiler                     */
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/* Macro for initializing local structures to zero                            */
/******************************************************************************/
#define DDL_ZERO_STRUCT(x) ddl_memclr((void *)&(x), (uint32_t)(sizeof(x)))

#define DEC2BCD(x)           ((((x)/10)<<4) + ((x)%10))
#define BCD2DEC(x)           ((((x)>>4)*10) + ((x)&0x0F))


/**
 ******************************************************************************
 ** Global Device Series List
 ******************************************************************************/
#define DDL_DEVICE_SERIES_HC32L15       (0u)

/**
 ******************************************************************************
 ** Global Device Package List
 ******************************************************************************/
// package definitions of HC device.
#define DDL_DEVICE_PACKAGE_HC_C         (0x00u)
#define DDL_DEVICE_PACKAGE_HC_F         (0x10u)
#define DDL_DEVICE_PACKAGE_HC_J         (0x20u)
#define DDL_DEVICE_PACKAGE_HC_K         (0x30u)

/******************************************************************************/
/* User Device Setting Include file                                           */
/******************************************************************************/
#include "ddl_device.h"  // MUST be included here!

/**
 ******************************************************************************
 ** \brief IRQ name definition for all type MCUs
 ******************************************************************************/
    #define CSV_IRQHandler(void)               IRQ000_Handler(void) ///< CSV
    #define SWDT_IRQHandler(void)              IRQ001_Handler(void) ///< SWDT
    #define LVD_IRQHandler(void)               IRQ002_Handler(void) ///< LVD
//                                             IRQ003_Handler(void) ///< Reserved
    #define EXTI07_IRQHandler(void)            IRQ004_Handler(void) ///< External interrupt ch.0-7
    #define EXTI815_IRQHandler(void)           IRQ005_Handler(void) ///< External interrupt ch.8-15
    #define DTIM_IRQHandler(void)              IRQ006_Handler(void) ///< Dual timer
    #define MSC0RX_IRQHandler(void)            IRQ007_Handler(void) ///< MSC ch.0, RX
    #define MSC0TX_IRQHandler(void)            IRQ008_Handler(void) ///< MSC ch.0, TX
    #define MSC1RX_IRQHandler(void)            IRQ009_Handler(void) ///< MSC ch.1, RX
    #define MSC1TX_IRQHandler(void)            IRQ010_Handler(void) ///< MSC ch.1, TX
    #define MSC2RX_IRQHandler(void)            IRQ011_Handler(void) ///< MSC ch.2, RX
    #define MSC2TX_IRQHandler(void)            IRQ012_Handler(void) ///< MSC ch.2, TX
//                                             IRQ013_Handler(void) ///< Reserved
//                                             IRQ014_Handler(void) ///< Reserved
    #define MSC4RX_IRQHandler(void)            IRQ015_Handler(void) ///< MSC ch.4, RX
    #define MSC4TX_IRQHandler(void)            IRQ016_Handler(void) ///< MSC ch.4, TX
    #define MSC5RX_IRQHandler(void)            IRQ017_Handler(void) ///< MSC ch.5, RX
    #define MSC5TX_IRQHandler(void)            IRQ018_Handler(void) ///< MSC ch.5, TX
    #define MSC6RX_IRQHandler(void)            IRQ019_Handler(void) ///< MSC ch.6, RX
    #define MSC6TX_IRQHandler(void)            IRQ020_Handler(void) ///< MSC ch.6, TX
//                                             IRQ021_Handler(void) ///< Reserved
//                                             IRQ022_Handler(void) ///< Reserved
//                                             IRQ023_Handler(void) ///< Reserved
    #define OSC_WU_RTC_IRQHandler(void)        IRQ024_Handler(void) ///< OSC / MSC Wake Up / RTC
    #define ADC_IRQHandler(void)               IRQ025_Handler(void) ///< ADC
    #define VC_IRQHandler(void)                IRQ026_Handler(void) ///< VC
    #define SCI_IRQHandler(void)               IRQ027_Handler(void) ///< SCI7816
//                                             IRQ028_Handler(void) ///< Pulse count
//                                             IRQ029_Handler(void) ///< Reserved
//                                             IRQ030_Handler(void) ///< Reserved
    #define CTIM07_IRQHandler(void)            IRQ031_Handler(void) ///< CT ch.0-7

/******************************************************************************/
/* Global type definitions ('typedef')                                        */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief Level
 **
 ** Specifies levels.
 **
 ******************************************************************************/
typedef enum en_level
{
    DdlLow      = 0u,  ///< Low level  '0'
    DdlHigh     = 1u   ///< High level '1'
} en_level_t;

/**
 ******************************************************************************
 ** \brief Generic Flag Code
 **
 ** Specifies flags.
 **
 ******************************************************************************/
typedef enum en_flag
{
    DdlClr = 0u,       ///< Flag clr '0'
    DdlSet = 1u        ///< Flag set '1'
} en_stat_flag_t, en_irq_flag_t;
/*****************************************************************************/
/* Global variable declarations ('extern', definition in C source)           */
/*****************************************************************************/

/*****************************************************************************/
/* Global function prototypes ('extern', definition in C source)             */
/*****************************************************************************/

/******************************************************************************
 * Global function prototypes
 ******************************************************************************/
extern void ddl_memclr(void* pu32Address, uint32_t u32Count);

/**
 ******************************************************************************
 ** This hook is part of wait loops.
 ******************************************************************************/
extern void DDL_WAIT_LOOP_HOOK(void);

void Debug_UartInit(void);

void delay1ms(uint32_t u32Cnt);
#ifdef __cplusplus
}
#endif

#endif /* __DDL_H__ */

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

