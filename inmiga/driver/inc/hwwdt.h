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
/** \file hwwdt.h
 **
 ** hardware watch dog driver define.
 ** @link hwwdt Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __HWWDT_H__
#define __HWWDT_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** function prototypes.
 *****************************************************************************/
    
/*****************************************************************************/
/* Global pre-processor symbols/macros ('#define')                           */
/*****************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief Hardware Clock Select
 ******************************************************************************/
typedef enum en_hwwdt_clksrc
{
    ExtOsc           = 0u,      ///< External
    LowCr            = 1u,      ///< Internal
} en_hwwdt_clksrc_t;

/**
 *****************************************************************************
 ** \brief Hardware Watchdog configuration
 *****************************************************************************/
typedef struct stc_hwwdt_config
{
    en_hwwdt_clksrc_t   enClkSrc;        ///< Count clock source
    uint32_t            u32LoadValue;    ///< Timer interval
    boolean_t           bResetEnable;    ///< TRUE:  Enables Hardware watchdog reset
    func_ptr_t          pfnHwwdtIrqCb;   ///< Pointer to hardware watchdog interrupt callback function
} stc_hwwdt_config_t;

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Global variable definitions ('extern')                                     */
/******************************************************************************/

/******************************************************************************/
/* Global function prototypes (definition in C source)                        */
/******************************************************************************/
/* Setup(Initialize)/Disable(Un-initialize) */
en_result_t Hwwdt_Init(stc_hwwdt_config_t* pstcConfig);
en_result_t Hwwdt_DeInit(uint32_t u32MagicWord1,
                         uint32_t u32MagicWord2 );

/* Start/Stop */
en_result_t Hwwdt_Start(void);
void Hwwdt_Stop(void);

/* Write/Read for counter */
void Hwwdt_WritewdtLoad(uint32_t u32LoadValue);
uint32_t Hwwdt_ReadwdtValue(void);

/* Feed watchdog */
void Hwwdt_Feed(uint8_t u8ClearPattern1, uint8_t u8ClearPattern2);

void Hwwdt_EnableDbgBrkwdtCtl(void);
void Hwwdt_DisableDbgBrkwdtCtl(void);

void Hwwdt_EnableDbgBrkWdgCtl(void);

#ifdef __cplusplus
}
#endif

#endif /* __HWWDT_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
