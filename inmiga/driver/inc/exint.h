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

/******************************************************************************/
/** \file exint.h
 **
 ** Headerfile for EXINT functions
 ** @link Driver Group Some description @endlink 
 ** 
 **   - 2016-11-11  1.0  Xiaoli  First version.
 **
 ******************************************************************************/

#ifndef __EXINT_H__
#define __EXINT_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"


/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif
  
/**
 ******************************************************************************
 ** \defgroup ExintGroup External Interrupts (EXINT)
 **
 ** Provided functions of EXINT module:
 ** 
 ** - Exint_Init()
 ** - Exint_DeInit()
 ** - Exint_EnableChannel()
 ** - Exint_DisableChannel()
 ** - Exint_SetDetectMode()
 ** - Exint_GetDetectMode()
 ** - Exint_Nmi_Init()
 ** - Exint_Nmi_DeInit()
 **
 ** \brief How to use External Interrupts
 **
 ** With Exint_Init() the external interrupts are enabled as given in the
 ** configuration. Note, that both external interrupt groups (0-7 and 8-15)
 ** can be enabled individually.
 **
 ** If a single channel may be disabled and reenabled during runtime the
 ** functions Exint_DisableChannel() and Exint_EnableChannel() can be
 ** used.
 **
 ** Exint_SetDetectMode() is used to change the detect mode of single channel.
 ** And Exint_GetDetectMode gets the detect mode of single channel.
 ** 
 ** The external interrupts are disabled globally by Exint_DeInit().
 **
 ** Each channel provides an individually callback function which is handled
 ** in the interrupt service routine.
 **
 ** Exint_Nmi_Init() "initializes" the None-Maskable Interrupt, which means
 ** that the callback function is set to the dedicated internal data.
 **
 ******************************************************************************/
//@{
  
/******************************************************************************/
/* Global pre-processor symbols/macros ('#define')                            */
/******************************************************************************/
#define DDL_EXINT_CHANNELS       (16u)  

 

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
  
typedef enum en_exint_level
{
  ExIntLowLevel     = 0u,  ///< "L" level detection
  ExIntHighLevel    = 1u,  ///< "H" level detection
  ExIntRisingEdge   = 2u,  ///< Rising edge detection
  ExIntFallingEdge  = 3u,  ///< Falling edge detection
  
} en_exint_level_t;

/**
 ******************************************************************************
 ** \brief EXINT configuration
 ******************************************************************************/


/**
 *****************************************************************************
 ** \brief External Interrupt configuration
 ** 
 ** The EXINT configuration
 *****************************************************************************/
typedef struct stc_exint_config
{
  boolean_t         bEnable;           ///< TRUE: External Interrupt enable
  en_exint_level_t  enLevel;           ///< level detection, see #en_exint_level_t for details
  func_ptr_t        pfnExintCallback;  ///< Callback pointers  
  boolean_t         bTouchNvic;      ///< TRUE: Enable NVIC, FALSE: don't enable NVIC, 
  
} stc_exint_config_t;

/**
 ******************************************************************************
 ** \brief Datatype for holding internal data needed for EXINT
 ******************************************************************************/
typedef struct stc_exint_intern_data
{
  func_ptr_t    apfnExintCallback[DDL_EXINT_CHANNELS];  ///< Callback pointer array
} stc_exint_intern_data_t ;



/**
 *****************************************************************************
 ** \brief NMI configuration
 ** 
 ** The NMI configuration
 *****************************************************************************/
typedef struct stc_exint_nmi_config
{ 
  func_ptr_t        pfnNmiCallback;   ///< NMI Callback pointers
} stc_exint_nmi_config_t;

/**
 ******************************************************************************
 ** \brief Datatype for holding internal data needed for NMI
 ******************************************************************************/
typedef struct stc_exint_nmi_intern_data
{
  func_ptr_t    pfnNmiCallback;  ///< Callback pointer
} stc_exint_nmi_intern_data_t ;


/// Enumeration to define an index for each enabled external interrupt instance
typedef enum en_exint_instance_index
{
    ExintInstanceIndexExint0,
    ExintInstanceIndexExint1,
    ExintInstanceIndexExint2,
    ExintInstanceIndexExint3,
    ExintInstanceIndexExint4,
    ExintInstanceIndexExint5,
    ExintInstanceIndexExint6,
    ExintInstanceIndexExint7,
    ExintInstanceIndexExint8,
    ExintInstanceIndexExint9,
    ExintInstanceIndexExint10,
    ExintInstanceIndexExint11,
    ExintInstanceIndexExint12,
    ExintInstanceIndexExint13,
    ExintInstanceIndexExint14,
    ExintInstanceIndexExint15,
    ExintInstanceIndexMax
} en_exint_instance_index_t;

/******************************************************************************/
/* Global variable definitions ('extern')                                     */
/******************************************************************************/

extern stc_exint_intern_data_t stcExintInternData;//////

extern stc_exint_nmi_intern_data_t stcExintNMIInternData;/////

/******************************************************************************/
/* Global function prototypes (definition in C source)                        */
/******************************************************************************/

void Exint_IrqHandler(uint8_t u8Channel) ;////

en_result_t Exint_Init(uint8_t u8Channel,stc_exint_config_t* pstcConfig) ;

en_result_t Exint_DeInit(uint8_t u8Channel) ;

en_result_t Exint_EnableChannel(uint8_t u8Channel) ;

en_result_t Exint_DisableChannel(uint8_t u8Channel) ;

en_result_t Exint_SetDetectMode(uint8_t u8Channel, en_exint_level_t enLevel);

en_exint_level_t Exint_GetDetectMode(uint8_t u8Channel);

void Exint_Nmi_IrqHandler(void) ;////

en_result_t Exint_Nmi_Init(stc_exint_nmi_config_t* pstcConfig) ;

en_result_t Exint_Nmi_DeInit(stc_exint_nmi_config_t* pstcConfig) ;

en_result_t Exint_Nmi_IrqFlagClear(void);

//@} // ExintGroup

#ifdef __cplusplus
}
#endif


#endif /* __EXINT_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
