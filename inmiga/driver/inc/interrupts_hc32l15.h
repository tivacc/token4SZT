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
/** \file interrupts_hc32l15.h
 **
 ** Interrupt common define.
 ** @link IRQGroup Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/
#ifndef __INTERRUPTS_HC32L15_H___
#define __INTERRUPTS_HC32L15_H___

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/

//CSV
#define DDL_IRQ_LEVEL_CSV                       3u

//SWDT
#define DDL_IRQ_LEVEL_SWDT                      3u

//LVD
#define DDL_IRQ_LEVEL_LVD                       3u

//EXT0-7
#define DDL_IRQ_LEVEL_EXT07                     3u

//EXT8-15
#define DDL_IRQ_LEVEL_EXT815                    3u

//DTIM
#define DDL_IRQ_LEVEL_DTIM                      3u

//MSC0RX
#define DDL_IRQ_LEVEL_MSC0RX                    3u

//MSC0TX
#define DDL_IRQ_LEVEL_MSC0TX                    3u

//MSC1RX
#define DDL_IRQ_LEVEL_MSC1RX                    3u

//MSC1TX
#define DDL_IRQ_LEVEL_MSC1TX                    3u

//MSC2RX
#define DDL_IRQ_LEVEL_MSC2RX                    3u

//MSC2TX
#define DDL_IRQ_LEVEL_MSC2TX                    3u

//MSC4RX
#define DDL_IRQ_LEVEL_MSC4RX                    3u

//MSC4TX
#define DDL_IRQ_LEVEL_MSC4TX                    3u

//MSC5RX
#define DDL_IRQ_LEVEL_MSC5RX                    3u

//MSC5TX
#define DDL_IRQ_LEVEL_MSC5TX                    3u

//MSC6RX
#define DDL_IRQ_LEVEL_MSC6RX                    3u

//MSC6TX
#define DDL_IRQ_LEVEL_MSC6TX                    3u

//OSC/WU/RTC
#define DDL_IRQ_LEVEL_OSCWURTC                  3u

//ADC
#define DDL_IRQ_LEVEL_ADC                       3u

//VC
#define DDL_IRQ_LEVEL_VC                        3u

//SCI
#define DDL_IRQ_LEVEL_SCI                       3u

//CT
#define DDL_IRQ_LEVEL_CT07                      3u

#define DDL_IRQ_LEVEL_DEFAULT                   3u

#ifdef __cplusplus
}
#endif


#endif /* __INTERRUPTS_H__ */

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
