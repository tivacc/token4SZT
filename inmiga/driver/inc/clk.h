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
/** \file clk.h
 **
 ** Headerfile for CLK functions
 **
 **
 ** History:
 **   - 2016-10-31   R
 **
 *****************************************************************************/

#ifndef __CLK_H__
#define __CLK_H__

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"
#include "system_hc32l15.h"

#ifdef __cplusplus
extern "C"
{
#endif


/**
 ******************************************************************************
 ** function prototypes.
 *****************************************************************************/

/******************************************************************************
 * Global definitions
 *****************************************************************************/
#define CLK_LICR_VAL            (32*1000)           ///< LICR fix frequency
#define CLK_LSXT_VAL            (32768)             ///< LSXT fix freq
#ifndef CLK_HSXT_VAL
    #define CLK_HSXT_VAL        (32*1000*1000)      ///< HSXT fix frequency
#endif
/**
 ******************************************************************************
 ** \brief clk input source enum
 **
 ** \note MCU clock source input enumeration
 *****************************************************************************/
typedef enum en_clk_source
{
    ClkHICR = 0u,           ///< Internal High CR Clock Oscillator
    ClkHSXT = 1u,           ///< External High CR Clock Oscillator
    ClkLICR = 4u,           ///< Internal Low CR Clock Oscillator
    ClkLSXT = 5u,           ///< external low CR Clock Oscillator
}en_clk_source_t;

/**
 ******************************************************************************
 ** \brief all peripheral device enum
 **
 ** \note mcu peripheral clock list enumeration
 *****************************************************************************/
typedef enum en_clk_periph_idx
{
    //apb0
    ClkPeriphralClock,
    ClkPeriphralReset,
    ClkPeriphralHwwdg,
    ClkPeriphralSwwdg,
    ClkPeriphralDt,
    //apb1
    ClkPeriphralCt,
    ClkPeriphralAdc,
    ClkPeriphralCal,
    ClkPeriphralExti,
    ClkPeriphralLcd,
    ClkPeriphralGpio,
    ClkPeriphralLvd,
    ClkPeriphralDs,
    ClkPeriphralMsc,
    ClkPeriphralRtc,
    ClkPeriphralBuzz,
    ClkPeriphralVc,
    ClkPeriphralSci,
    //apb
    ClkPeriphralAes,
    ClkPeriphralFlash,
    ClkPeriphralMax,
}en_clk_periph_idx_t;

/**
 ******************************************************************************
 ** \brief high cr stable wait time
 **
 *****************************************************************************/
typedef enum en_clk_waitmain
{
    ClkCswtMain64us = 0,
    ClkCswtMain256us,
    ClkCswtMain1ms,
    ClkCswtMain4ms,
    ClkCswtMain8ms,
    ClkCswtMain16ms,
    ClkCswtMain32ms,
    ClkCswtMain65ms,
    ClkCswtMain131ms,
    ClkCswtMain262ms,
    ClkCswtMain524ms,
    ClkCswtMain1s,
    ClkCswtMain2s,
    ClkCswtMain1us,
    ClkCswtMain4us,
    ClkCswtMain16us,
}en_clk_waitmain_t;

/**
 ******************************************************************************
 ** \brief low cr stable wait time 
 **  
 *****************************************************************************/
typedef enum en_clk_waitsub
{
    ClkCswtSub01ms = 0,
    ClkCswtSub05ms,
    ClkCswtSub2ms,
    ClkCswtSub8ms,
    ClkCswtSub16ms,
    ClkCswtSub32ms,
    ClkCswtSub64ms,
    ClkCswtSub128ms,
    ClkCswtSub256ms,
    ClkCswtSub512ms,
    ClkCswtSub1s,
    ClkCswtSub2s,
    ClkCswtSub4s,
    ClkCswtSub8s,
    ClkCswtSub16s,
    ClkCswtSub32s,
}en_clk_waitsub_t;


/**
 ******************************************************************************
 ** \brief clock base division value enum
 **
 ** \note osc source -> base div -> (base clock)cpu
 *****************************************************************************/
typedef enum en_clk_basediv
{
    ClkBaseDiv1 = 0,            ///< no div
    ClkBaseDiv2,
    ClkBaseDiv3,
    ClkBaseDiv4,
    ClkBaseDiv6,
    ClkBaseDiv8,
    ClkBaseDiv16,
}en_clk_basediv_t;

/**
 ******************************************************************************
 ** \brief apb0 bus division value enum
 **
 ** \note  base clock -> apb0 div -> apb0 clock
 *****************************************************************************/
typedef enum en_clk_apb0div
{
    ClkApb0Div1 = 0,            ///< no div
    ClkApb0Div2,
    ClkApb0Div4,
    ClkApb0Div8,
}en_clk_apb0div_t;

/**
 ******************************************************************************
 ** \brief apb1 bus division value enum
 **
 ** \note  base clock -> apb1 div -> apb1 clock
 *****************************************************************************/
typedef enum en_clk_apb1div
{
    ClkApb1Div1 = 0,            ///< no div
    ClkApb1Div2,
    ClkApb1Div4,
    ClkApb1Div8,
}en_clk_apb1div_t;

/**
 ******************************************************************************
 ** \brief hcr value setting
 **
 ** \note  high cr can be set to 2/4/8/16 Mhz
 *****************************************************************************/
typedef enum en_clk_hicrfreq
{
    ClkHICR2Mhz,
    ClkHICR4Mhz,
    ClkHICR8Mhz,
    ClkHICR16Mhz,
}en_clk_hicrfreq_t;

/**
 ******************************************************************************
 ** \brief clk irq type
 ** 
 *****************************************************************************/
typedef enum en_clk_irq_sel
{
    ClkIrqFcs,
    ClkIrqLSXT,
    ClkIrqHSXT,
    ClkIrqLSXTRdy,
    ClkIrqHSXTrRdy,
}en_clk_irq_sel_t;


/**
 ******************************************************************************
 ** \brief swwdg division setting
 **
 *****************************************************************************/
typedef enum en_clk_swwdg_div
{
    ClkDiv1 = 0,            ///< no div
    ClkDiv2,
    ClkDiv4,
    ClkDiv8,
}en_clk_swwdg_div_t;

/**
 ******************************************************************************
 ** \brief fcs division setting
 **
 *****************************************************************************/
typedef enum en_clk_fcs_div
{
    ClkFcsDiv256 = 5,
    ClkFcsDiv512 = 6,
    ClkFcsDiv1024 = 7,
}en_clk_fcs_div_t;

/**
 ******************************************************************************
 ** \brief fcs stat query index
 **
 *****************************************************************************/
typedef enum en_clk_fcs_stat
{
    ClkCsvLSXT,
    ClkCsvHSXT,
}en_clk_fcs_stat_t;

/**
 ******************************************************************************
 ** \brief clock module function setting event enumeration
 **
 *****************************************************************************/
typedef enum en_clk_func
{
    ClkFuncDt,
    ClkFuncHWWDG,
    ClkFuncSWWDG,
    ClkFuncFcsReset,
    ClkFuncFcs,
    ClkFuncLSXTReset,
    ClkFuncHSXTReset,
    ClkFuncLSXT,
    ClkFuncHSXT,
}en_clk_func_t;

/**
 ******************************************************************************
 ** \brief system reset cause flag
 **
 ** \note  may contain multiple event
 *****************************************************************************/
typedef struct stc_clk_rstcause
{
    boolean_t   bSoftware;              ///< software reset 
    boolean_t   bAFreq;                 ///< abnormal frequency reset
    boolean_t   bCSV;                   ///< csv reset
    boolean_t   bHwwdg;                 ///< hardware watchdog reset
    boolean_t   bSwwdg;                 ///< software watchdog reset
    boolean_t   bLVD;                   ///< low voltage reset
    boolean_t   bRstPin;                ///< reset pin reset
    boolean_t   bPowerOn;               ///< power on reset
}stc_clk_rstcause_t;

/**
 ******************************************************************************
 ** \brief Clock configuration
 **
 ** The Clock configuration settings
 *****************************************************************************/
typedef struct stc_clk_config
{
    en_clk_basediv_t      enBaseClkDiv;     ///< base clk division value
    en_clk_apb0div_t      enAPB0Div;        ///< APB0 clk division value
    en_clk_apb1div_t      enAPB1Div;        ///< APB1 clk division value
    en_clk_waitmain_t     enclkWaitMain;    ///< external high cr stable time
    en_clk_waitsub_t      enclkWaitSub;     ///< external low cr stable time

    boolean_t             bHSXTIrq;         ///< enable external high cr stable callback
    boolean_t             bLSXTIrq;         ///< enable external low cr stable callback
    func_ptr_t            pfnHSXTRdyCb;     ///< pointer to external high cr stable callback function.
    func_ptr_t            pfnLSXTRdyCb;     ///< pointer to external low cr stable callback function.
}stc_clk_config_t;


typedef struct stc_clk_fcs_irq_sel
{
    boolean_t           bHSXTFailIrqEn;     ///< enable ext high cr fail interrrupt.
    boolean_t           bLSXTFailIrqEn;     ///< enable ext low cr fail interrrupt.
    boolean_t           bFcsIrqEn;          ///< enable fcs interrrupt.
}stc_clk_fcs_irq_sel_t;

typedef struct stc_clk_fcs_irq_cb
{
    func_ptr_t          pfnHSXTFailIrqCb;   ///< Pointer to ext high cr fail callback function
    func_ptr_t          pfnLSXTFailIrqCb;   ///< Pointer to ext low cr fail callback function 
    func_ptr_t          pfnFcsIrqCb;        ///< Pointer to fcs callback function
}stc_clk_fcs_irq_cb_t;

/**
 ******************************************************************************
 ** \brief Clock Fcs configuration
 **
 ** The Clock Fcs configuration settings
 *****************************************************************************/
typedef struct stc_clk_fcs_config
{
    en_clk_fcs_div_t        enFcsDiv;           ///< fcs division 
    boolean_t               bFcsResetEn;        ///< enable fcs reset
    boolean_t               bFcsEn;             ///< enable fcs function
    boolean_t               bLSXTFailResetEn;   ///< enable ext low cr fail reset 
    boolean_t               bHSXTFailResetEn;   ///< enable ext high cr fail reset 
    boolean_t               bLSXTFailDetectEn;  ///< enable ext low cr fail detect
    boolean_t               bHSXTFailDetectEn;  ///< enable ext high cr fail detect
    stc_clk_fcs_irq_sel_t   *pstcFcsIrqSel;     ///< pointer to fcs irq select
    stc_clk_fcs_irq_cb_t    *pstcFcsIrqCb;      ///< pointer to fcs irq callback
}stc_clk_fcs_config_t;

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/******************************************************************************
 * Global variable declarations ('extern', definition in C source)
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)
 *****************************************************************************/
//clk init/deinit
en_result_t Clk_Init(stc_clk_config_t *pstcCfg);
en_result_t Clk_DeInit(boolean_t bNvic);

//clk source basic function
en_result_t Clk_Enable(en_clk_source_t enSource, boolean_t bFlag);
en_result_t Clk_SetSource(en_clk_source_t enSource);
boolean_t Clk_GetClkRdy(en_clk_source_t enSource);
en_clk_source_t Clk_GetCurSource(void);

//clk switch advanced function
en_result_t Clk_SwitchTo(en_clk_source_t enSrc);

en_result_t Clk_SetHICRFreq(en_clk_hicrfreq_t enVal);
uint32_t Clk_GetSourceFreq(en_clk_source_t enSrc);

//clk frequency function
uint32_t Clk_GetSystemClk(void);

//abp function
uint32_t Clk_GetPeripheralClk(en_clk_periph_idx_t enIdx);
en_result_t Clk_EnableAPB1(boolean_t bFlag);

//clock function enable/disable
en_result_t Clk_EnableFunc(en_clk_func_t enFunc);
en_result_t Clk_DisableFunc(en_clk_func_t enFunc);

//clock fcs setting
en_result_t Clk_SetSwwdgDiv(en_clk_swwdg_div_t  enDiv);

en_result_t Clk_FcsInit(stc_clk_fcs_config_t *pstcCfg);
en_result_t Clk_SetFcsDiv(en_clk_fcs_div_t enDiv);
boolean_t Clk_GetFcsStat(en_clk_fcs_stat_t enType);
en_result_t Clk_SetFcsWindow(uint16_t u16Low, uint16_t u16High);
uint16_t Clk_GetFcsFreq(void);

en_result_t Clk_GetResetCause(stc_clk_rstcause_t *pstcData);

en_result_t Clk_EnableIrq(en_clk_irq_sel_t enSel);
en_result_t Clk_DisableIrq(en_clk_irq_sel_t enSel);
boolean_t Clk_GetIrqStat(en_clk_irq_sel_t enSel);
en_result_t Clk_ClearIrq(en_clk_irq_sel_t enSel);

//@} // ClkGroup

#ifdef __cplusplus
#endif


#endif /* __CLK_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


