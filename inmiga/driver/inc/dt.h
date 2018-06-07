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
/** \file dt.h
 **
 ** Dual timer driver define.
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of
 **                      Module.
 **
 *****************************************************************************/

#ifndef __DT_H__
#define __DT_H__

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

/**
 ******************************************************************************
 ** \defgroup Dt Group Dual Timer (DT)
 ** 
 *                                                                           */
//@{

/******************************************************************************
 * Global type definitions
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of DT register structure 
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Dt mode
 ** 
 ** To select between Free-run, Periodic, and One-Shot mode
 *****************************************************************************/
typedef enum en_dt_mode
{
    DtModeFreeRun      = 0u,  ///< Free-running mode
    DtModePeriodic     = 1u,  ///< Periodic mode
    DtModeOneShot      = 2u   ///< One-shot mode
} en_dt_mode_t;

/**
 ******************************************************************************
 ** \brief Dt Prescaler
 ** 
 ** To select clock divider
 *****************************************************************************/
typedef enum en_dt_prescaler
{
    DtPrescalerDiv1,      ///< Prescaler divisor 1
    DtPrescalerDiv16,     ///< Prescaler divisor 16
    DtPrescalerDiv256,    ///< Prescaler divisor 256
    DtPrescalerDivMax,    ///< 
} en_dt_prescaler_t;

/**
 ******************************************************************************
 ** \brief Dt Counter Size
 ** 
 ** To select the size of the counter
 *****************************************************************************/
typedef enum en_dt_countersize
{
    DtCounterSize16     = 0u,   ///< 16 Bit counter size
    DtCounterSize32     = 1u    ///< 32 Bit counter size
} en_dt_countersize_t;

/**
 ******************************************************************************
 ** \brief Dt channel number
 *****************************************************************************/
typedef enum en_dt_channel
{
    DtChannel1     = 1u,        ///< channel 1
    DtChannel2     = 2u,        ///< channel 2
    DtChannelMax   = 0xFFu,     ///<
} en_dt_channel_t;

/**
 *****************************************************************************
 ** \brief Dt channel configuration
 ** 
 ** The DT configuration is done on a per channel basis
 *****************************************************************************/
typedef struct stc_dt_channel_config
{
    en_dt_mode_t        enMode;         ///<
    en_dt_prescaler_t   enClkDiv;       ///<
    en_dt_countersize_t enCounterSize;  ///<
    boolean_t           bIrqEnable;     ///< 
    func_ptr_t          pfnIrqCallback; ///<
    boolean_t           bTouchNvic;     ///<
} stc_dt_channel_config_t;

/******************************************************************************
 * Global definitions
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')                                     
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 *****************************************************************************/
// interrupt enable/disable function
en_result_t Dt_EnableIrq (uint8_t u8ch);
en_result_t Dt_DisableIrq(uint8_t u8ch);

//init/deinit
en_result_t Dt_Init(uint8_t u8ch, stc_dt_channel_config_t* pstcConfig);
en_result_t Dt_DeInit(uint8_t u8ch, boolean_t bTouchNvic);

//function enable/disable
en_result_t Dt_EnableCount(uint8_t u8ch);
en_result_t Dt_DisableCount(uint8_t u8ch);

//get status
boolean_t Dt_GetIrqFlag(uint8_t u8ch);
boolean_t Dt_GetMaskIrqFlag(uint8_t u8ch);
en_result_t Dt_ClrIrqFlag(uint8_t u8ch);

//counter read/write function
en_result_t Dt_WriteLoadVal(uint8_t u8ch,uint32_t u32Val);
en_result_t Dt_WriteBgLoadVal(uint8_t u8ch,uint32_t u32Val);

uint32_t Dt_ReadCurCntVal(uint8_t u8ch);

//@} // DtGroup

#ifdef __cplusplus
}
#endif

#endif /* __DT_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


