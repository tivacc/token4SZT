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
/** \file lvd.h
 **
 ** low voltage detect driver define.
 ** @link LVD Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __LVD_H__
#define __LVD_H__

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

/**
 ******************************************************************************
 ** \defgroup LVD Group 
 ** 
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief LVD type selection
 ******************************************************************************/
typedef enum en_lvd_type
{
    LvdType1,               ///< LVD type 1
    LvdType2,               ///< LVD type 2
    LvdTypeMax,
}en_lvd_type_t;

/**
 ******************************************************************************
 ** \brief LVD1 input voltage source
 **
 ** \note lvd1 has 3 input source
 ******************************************************************************/
typedef enum en_lvd_input
{
    LvdInputVCC,            ///< VCC
    LvdInputVDD,            ///< VDD
    LvdInputPIN,            ///< LVD input pin
}en_lvd_input_t;

/**
 ******************************************************************************
 ** \brief LVD2 threshold value enum
 ******************************************************************************/
typedef enum en_lvd_threshold2
{   
    Lvd2TH1_75V = 0,        ///< lvd2 threshod 1.75v
    Lvd2TH1_80V,            ///< lvd2 threshod 1.80v
    Lvd2TH1_90V,            ///< lvd2 threshod 1.90v
    Lvd2TH2_10V,            ///< lvd2 threshod 2.10v
    Lvd2TH2_20V,            ///< lvd2 threshod 2.20v
    Lvd2TH2_50V,            ///< lvd2 threshod 2.50v
    Lvd2TH2_70V,            ///< lvd2 threshod 2.70v
}en_lvd_threshold2_t;

/**
 ******************************************************************************
 ** \brief LVD1 threshold value enum
 ******************************************************************************/
typedef enum en_lvd_threshold1
{
    Lvd1TH2_00V = 0,        ///< lvd1 threshod 2.00v
    Lvd1TH2_10V,            ///< lvd1 threshod 2.10v
    Lvd1TH2_20V,            ///< lvd1 threshod 2.20v
    Lvd1TH2_30V,            ///< lvd1 threshod 2.30v
    Lvd1TH2_40V,            ///< lvd1 threshod 2.40v
    Lvd1TH2_50V,            ///< lvd1 threshod 2.50v
    Lvd1TH2_61V,            ///< lvd1 threshod 2.61v
    Lvd1TH2_72V,            ///< lvd1 threshod 2.72v
    Lvd1TH2_83V,            ///< lvd1 threshod 2.83v
    Lvd1TH2_94V,            ///< lvd1 threshod 2.94v
    Lvd1TH3_05V,            ///< lvd1 threshod 3.05v
    Lvd1TH3_16V,            ///< lvd1 threshod 3.16v
    Lvd1TH3_27V,            ///< lvd1 threshod 3.27v
    Lvd1TH3_38V,            ///< lvd1 threshod 3.38v
    Lvd1TH3_49V,            ///< lvd1 threshod 3.49v
    Lvd1TH3_60V,            ///< lvd1 threshod 3.60v
}en_lvd_threshold1_t;

/**
 ******************************************************************************
 ** \brief LVD ses value enum
 ******************************************************************************/
typedef enum en_lvd_ses_threshold
{
    LvdSes1_65V,            ///< 1.65v
    LvdSes1_70V,            ///< 1.70v
    LvdSes1_75V,            ///< 1.75v
    LvdSes1_80V,            ///< 1.80v
    LvdSes1_85V,            ///< 1.85v
    LvdSes1_90V,            ///< 1.90v
    LvdSes1_95V,            ///< 1.95v
    LvdSes2_00V,            ///< 2.00v
}en_lvd_ses_threshold_t;
/**
 ******************************************************************************
 ** \brief LVD filter time value enum
 **
 ******************************************************************************/
typedef enum en_lvd_filter_time
{
    LvdFilter16us,          ///< 16us
    LvdFilter32us,          ///< 32us
    LvdFilter64us,          ///< 64us
    LvdFilter256us,         ///< 256us
    LvdFilter1ms,           ///< 1ms
    LvdFilter4ms,           ///< 4ms
    LvdFilter16ms,          ///< 16ms
    LvdFilter64ms,          ///< 64ms
}en_lvd_filter_time_t;

/**
 ******************************************************************************
 ** \brief LVD interrupt type
 ** 
 ******************************************************************************/
typedef enum en_lvd_irq_type
{
    Lvd1IrqNone,                ///< no irq event
    Lvd1IrqLow,                 ///< voltage lower than setting 
    Lvd1IrqHigh,                ///< voltage higher than setting 
    Lvd1IrqBoth,                ///< voltage lower or higher than setting
    Lvd2Irq,                    ///< lvd2 irq event
}en_lvd_irq_type_t;

/**
 ******************************************************************************
 ** \brief LVD status type enum
 ******************************************************************************/
typedef enum en_lvd_stat
{
    Lvd1StatIrq,                ///< lvd1 interrupt signal
    Lvd1StatVol,                ///< lvd1 voltage
    Lvd2StatIrq,                ///< lvd2 interrupt signal
    Lvd2StatSense,              ///< lvd2 sense
    Lvd2StatVol,                ///< lvd2 voltage
}en_lvd_stat_t;

/**
 ******************************************************************************
 ** \brief LVD sense config
 ******************************************************************************/
typedef struct
{
    boolean_t               bEn;            ///< enable
    en_lvd_ses_threshold_t  enSes;          ///< sense config
}stc_lvd1_sense_config_t;
/**
 ******************************************************************************
 ** \brief LVD1 init configuration 
 ** \note
 ******************************************************************************/
typedef struct stc_lvd1_config
{
    boolean_t               bLvdReset;      ///< TRUE reset,FALSE interrupt
    en_lvd_input_t          enInput;        ///< LVD input source
    en_lvd_threshold1_t     enThreshold;    ///< voltage threshold
    boolean_t               b10mvDly;       ///< 10mv latitude of threshold
    boolean_t               bFilter;        ///< if enable filter
    en_lvd_filter_time_t    enFilterTime;   ///< filter time
    en_lvd_irq_type_t       enIrqType;      ///< interrupt type
    func_ptr_t              pfnIrqCbk;      ///< interrupt callback function
}stc_lvd1_config_t;

/**
 ******************************************************************************
 ** \brief LVD2 init configuration 
 ** \note
 ******************************************************************************/
typedef struct stc_lvd2_config
{
    boolean_t               bDisable;       ///< enable/disable
    en_lvd_threshold2_t     enThreshold;    ///< voltage threshold
    boolean_t               bIrqEn;         ///< interrupt enable
    func_ptr_t              pfnIrqCbk;      ///< interrupt callback function
}stc_lvd2_config_t;

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
//irq enable/disable
en_result_t Lvd_EnableIrq(en_lvd_irq_type_t enType);
en_result_t Lvd_DisableIrq(en_lvd_irq_type_t enType);

// irq function
en_result_t Lvd_ClearIrq(en_lvd_type_t enType);
boolean_t   Lvd_GetStat(en_lvd_stat_t   enStat);

//init /deinit function
en_result_t Lvd1_Init(stc_lvd1_config_t *pstcConfig);
en_result_t Lvd1_DeInit(boolean_t bNvic);
en_result_t Lvd2_Init(stc_lvd2_config_t *pstcConfig);
en_result_t Lvd2_DeInit(boolean_t bNvic);

//function enable/disable
en_result_t Lvd_Enable(en_lvd_type_t enType);
en_result_t Lvd_Disable(en_lvd_type_t enType);

//@} // LVD Group

#ifdef __cplusplus
}
#endif

#endif /* __LVD_H__ */
/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/
