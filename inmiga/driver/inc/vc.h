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
/** \file vc.h
 **
 ** Voltage compare driver define.
 ** @link VC Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __VC_H__
#define __VC_H__

/******************************************************************************
 * Include files
 ******************************************************************************/
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
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief VC convert source select
 *****************************************************************************/
typedef enum en_vc_convert_src
{
    VcSrcPositive,              ///< positive 
    VcSrcNegative,              ///< negative
}en_vc_convert_src_t;

/**
 ******************************************************************************
 ** \brief VC convert function select
 *****************************************************************************/
typedef enum en_vc_func_sel
{
    VcFuncDCvt,                 ///< VC base voltage select
    VcFuncACvt,                 ///< VC enable
    VcFuncFilter,               ///< VC filter 
    VcFuncInputAmplify,         ///< VC input amplify
}en_vc_func_sel_t;

/**
 ******************************************************************************
 ** \brief VC convert analog source select
 *****************************************************************************/
typedef enum en_vc_analog_src
{
    VcExtDirect,                ///< external input voltage
    VcConverted,                ///< external input voltage converted
    VcIntern2_5V,               ///< internal 2.5v
    VcNone,                     ///< none
    VcInnerBGR1_2V,             ///< internal 1.2v
    VcInnerBGRCvt,              ///< internal bgr converted
}en_vc_analog_src_t;

/**
 ******************************************************************************
 ** \brief VC delay select. high or low this setting value more than standard
 **         will be valid
 *****************************************************************************/
typedef enum en_vc_cmp_delay
{
    VcDelayoff = 0u,
    VcDelay10mv,
    VcDelay20mv,
    VcDelay30mv,
}en_vc_cmp_delay_t;

/**
 ******************************************************************************
 ** \brief VC filter time 
 *****************************************************************************/
typedef enum en_vc_resp_filter
{
    VcFilter2cycle,
    VcFilter4cycle,
    VcFilter8cycle,
    VcFilter32cycle,
    VcFilter128cycle,
    VcFilter512cycle,
    VcFilter2048cycle,
    VcFilter8192cycle,
}en_vc_resp_filter_t;

/**
 ******************************************************************************
 ** \brief VC input pin select
 *****************************************************************************/
typedef enum en_vc_input_src
{
    VcVCIN0,                ///< input pin VCIN0
    VcVCIN1,                ///< input pin VCIN1
    VcVCIN2,                ///< input pin VCIN2
    VcVCIN3,                ///< input pin VCIN3
}en_vc_input_src_t,en_vc_inputbase_src_t;

/**
 ******************************************************************************
 ** \brief VC interrupt mode
 *****************************************************************************/
typedef enum en_vc_irq_sel
{
    VcIrqCmpIrqRise,            ///< rising edge
    VcIrqCmpIrqFall,            ///< falling edge
    VcIrqCmpIrqHigh,            ///< high
}en_vc_irq_sel_t;

/**
 ******************************************************************************
 ** \brief VC compare result status
 *****************************************************************************/
typedef enum en_vc_stat
{
    VcCmpResult,                ///< VC compare result
    VcACmpResult,               ///< VC compare result request.
}en_vc_stat_t;

/**
 ******************************************************************************
 ** \brief VC interrupt function configure 
 **        1. banalogCmp to enable the interrupt.
 **        2. bVcCmpIrqRise,bVcCmpIrqFall to enable if rising/falling to produce
 **           a interrupt.
 *****************************************************************************/
typedef struct stc_vc_irq_sel
{
    boolean_t   bVcCmpIrqRise;         ///< rising edge  
    boolean_t   bVcCmpIrqFall;         ///< falling edge 
    boolean_t   bVcCmpIrqHigh;         ///< high
}stc_vc_irq_sel_t;


/**
 ******************************************************************************
 ** \brief VC init configuration
 *****************************************************************************/
typedef struct stc_vc_config
{
    en_vc_convert_src_t     enVcConvertSrc;     ///< convert source
    uint8_t                 u8ConvertedDiv;     ///< convert freq division
    en_vc_analog_src_t      enVcAnalogInputP;   ///< analog input positive 
    en_vc_analog_src_t      enVcAnalogInputN;   ///< analog input nagative
    en_vc_cmp_delay_t       enVcCmpDly;         ///< if enable compare delay
    boolean_t               bACmpOutputReverse; ///< if reserve output 
    boolean_t               bVcAmpEn;           ///< ampify enable
    en_vc_resp_filter_t     enVcFilterTime;     ///< filter time
    en_vc_input_src_t       enVcInPin_P;        ///< vc input PIN +
    en_vc_inputbase_src_t   enVcInPin_N;        ///< vc input PIN -
    boolean_t               bTimer2Rev;         ///< 
    boolean_t               bTimer0Rev;         ///< 
    stc_vc_irq_sel_t        *pstcIrqSel;        ///< irq select configure
    func_ptr_t              pfnAnalogCmpCb;
}stc_vc_config_t;

/******************************************************************************
 * Global definitions
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/
//get status
boolean_t   Vc_GetStatus(en_vc_stat_t enStat);
//clear stat
en_result_t Vc_ClearStat(en_vc_stat_t enStat);

//irq enable/disable
en_result_t Vc_EnableIrq(void);
en_result_t Vc_DisableIrq( void);
en_result_t Vc_ConfigIrq(en_vc_irq_sel_t enSel,boolean_t bFlag );

// init /deinit
en_result_t Vc_Init(stc_vc_config_t *pstcConfig);
en_result_t Vc_DeInit(void);

//enable /disable function
en_result_t Vc_EnableFunc(en_vc_func_sel_t enFunc);
en_result_t Vc_DisableFunc(en_vc_func_sel_t enFunc);

//@} // vc Group

#ifdef __cplusplus
}
#endif

#endif /* __VC_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

