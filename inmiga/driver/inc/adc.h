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

/******************************************************************************/
/** \file adc.h
 **
 ** Headerfile for ADC functions
 **
 ** History:
 **   - 2016-10-31
 **
 ******************************************************************************/

#ifndef __ADC_H__
#define __ADC_H__


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
 ** \brief defgroup adc Group(adc)
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Global type definitions
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of adc register structure
 *****************************************************************************/ 
typedef  M0P_ADC_TypeDef  stc_adc_regtypdef_t;
   
/**
 ******************************************************************************
 ** \brief ADC Enable OR Disable
 *****************************************************************************/
typedef enum en_adc_enordis
{
    AdcDisable  =  0,             /*!< ADC Disable*/
    AdcEnable   =  1,             /*!< ADC Enable*/
  
}en_Adc_EnOrDis_t;

/**
 ******************************************************************************
 ** \brief ADC Sampling frequency selection
 *****************************************************************************/
typedef enum en_adc_samp_freq_sel
{
    SampFreqSysTDiv1  = 0,        /*!< The ADC sampling frequency for the system sample frequency, regardless of frequency*/
    SampFreqSysTDiv2  = 1,        /*!< The ADC sampling frequency for the system frequency dividing 2 */
    SampFreqSysTDiv4  = 2,        /*!< The ADC sampling frequency for the system frequency dividing 4 */
    SampFreqSysTDiv8  = 3,        /*!< The ADC sampling frequency for the system frequency dividing 8 */
      
} en_adc_samp_freq_sel_t;

/**
 ******************************************************************************
 ** \brief ADC reference voltage
 *****************************************************************************/
typedef enum en_adc_ref_vol_sel
{
    RefVolSelInBgr2_5 = 0,        /*!<Choose the ADC reference voltage of 2.5 V internal BGR*/
    RefVolSelInBgr1_5 = 1,        /*!<Choose the ADC reference voltage of 1.5 V internal BGR*/
    RefVolSelExtern1  = 2,        /*!<Choose the ADC reference voltage for the external reference voltage*/
    RefVolSelExrern2  = 3,        /*!<Choose the ADC reference voltage for the external reference voltage*/

}en_adc_ref_vol_sel_t;

/**
 ******************************************************************************
 ** \brief ADC sampling channel selection
 *****************************************************************************/
typedef enum en_adc_samp_ch_sel
{
    SelExInputCH0    =  0,        /*!<The ADC CH0 choose external input channels*/
    SelExInputCH1    =  1,        /*!<The ADC CH1 choose external input channels*/
    SelExInputCH2    =  2,        /*!<The ADC CH2 choose external input channels*/
    SelExInputCH3    =  3,        /*!<The ADC CH3 choose external input channels*/
    SelExInputCH4    =  4,        /*!<The ADC CH4 choose external input channels*/
    SelExInputCH5    =  5,        /*!<The ADC CH5 choose external input channels*/
    SelExInputCH6    =  6,        /*!<The ADC CH6 choose external input channels*/
    SelExInputCH7    =  7,        /*!<The ADC CH7 choose external input channels*/
    SelExInputCH8    =  8,        /*!<The ADC CH8 choose external input channels*/
    SelExInputCH9    =  9,        /*!<The ADC CH9 choose external input channels*/
    SelExInputCH10   =  10,       /*!<The ADC CH10 choose external input channels*/
    SelExInputCH11   =  11,       /*!<The ADC CH11 choose external input channels*/
    SelVccDiV2Input  =  12,       /*!<ADC selection 1/2 VCC as input*/
    SelVBatDiv2Input =  13,       /*!<1/2 VBAT is chosen as the ADC input*/
    SelInInputBgr1_2 =  14,       /*!<ADC selection internal BGR 1.2 V output as input*/
      
}en_adc_samp_ch_sel_t;

/**
 ******************************************************************************
 ** \brief ADC Interrupt request please enable
 *****************************************************************************/
typedef enum en_adc_irq_enordis
{
    AdcIrqDisable  =  0,          /*!< ADC IRQ DISANLE*/
    AdcIrqEnable   =  1,          /*!< ADC IRQ ENANLE*/
  
}en_adc_irq_enordis_t;

/**
 ******************************************************************************
 ** \brief ADC IRQ Flag BIT
 *****************************************************************************/
typedef enum en_adc_irq_flag
{
     AdcCnvUnfinishITFlag  = 0,    /*!<ADC IRQ Flag,Read: 1-ADC CNV complete, 0-ADC CNV uncomplete. Write: 0-Clears interrupt flag,1-invalid*/ 
     AdcCnvFinishITFlag    = 1,    /*!<ADC IRQ Flag,Read: 1-ADC CNV complete, 0-ADC CNV uncomplete. Write: 0-Clears interrupt flag,1-invalid*/ 
  
}en_adc_irq_flag_t;


/**
 ******************************************************************************
 ** \brief ADC sampling on or off
 *****************************************************************************/
typedef enum en_adc_samp_onoroff
{    
    AdcSampOff   =  0,           /*!The ADC sampling start*/
    AdcSampStart =  1,           /*!The ADC sampling closed*/ 
    
}en_adc_samp_onoroff_t;

/**
 ******************************************************************************
 ** \brief ADC conversion results alignment 
 *****************************************************************************/
typedef enum en_adc_result_align
{
    AdcResultLeftAlign  = 0,     /*!ADC results left alignment*/ 
    AdcResultRightAlign = 1,     /*!ADC results right alignment*/ 
  
}en_adc_result_align_t;

/**
 ******************************************************************************
 ** \brief ADC sampling mode
 *****************************************************************************/
typedef enum en_adc_samp_mode
{
    AdcContinSamp  = 0,          /*!Continuous sampling ADC*/ 
    AdcSingleSmple = 1,          /*!A single sampling ADC*/ 

}en_adc_samp_mode_t;

/**
 ******************************************************************************
 ** \brief ADC input signal amplifier enabled or disability
 *****************************************************************************/
typedef enum en_adc_insignalamp
{
    AdcInSignalAmpDisable = 0,   /*!ADC input signal amplifier enabled */  
    AdcInSignalAmpEnable  = 1,   /*!ADC input signal amplifier disability*/
    
}en_adc_insignalamp_t;

/**
 ******************************************************************************
 ** \brief ADC sampling time select
 *****************************************************************************/
typedef enum en_adc_samp_time_sel
{
    AdcSmapTim_3Clk  =  0,       /*!The ADC with three sampling ADC CLK clock*/  
    AdcSmapTim_6Clk  =  2,       /*!The ADC with six sampling ADC CLK clock*/ 
    AdcSmapTim_9Clk  =  3,       /*!The ADC with nine sampling ADC CLK clock*/ 
      
}en_adc_samp_time_sel_t;

/**
 ******************************************************************************
 ** \brief ADC range compare interrupt flag
 *****************************************************************************/
typedef enum en_adc_rangecmp_it_flag
{
    AdcRangeCmpItFlagRest = 0,      /*!ADC range compare interrupt flag rest or set 0*/ 
    AdcRangeCmpItFlagSet  = 1,      /*!The ADC sampling results meet the set conditions,Interrupt flag position*/ 

}en_adc_rangecmp_it_flag_t;

/**
 ******************************************************************************
 ** \brief  The ADC range compare is beyond the threshold flag
 *****************************************************************************/
typedef enum en_adc_rangecmpovthresholdflg
{
    AdcResulLowThresholdFlg  = 0,   /*!The ADC range compare is Low the threshold flag*/ 
    AdcResulOverThresholdFlg = 1,   /*!The ADC range compare is High the threshold flag*/
  
}en_adc_rangecmpovthresholdflg_t;


/**
 ******************************************************************************
 ** \brief ADC sampling results interval is enabled or disability
 *****************************************************************************/
typedef enum en_adc_rangcmpenordis
{
    AdcRangCmpDisable   = 0,     /*!ADC sampling results interval is disable*/
    AdcRangCmpEnable    = 1,     /*!ADC sampling results interval is enable*/
  
}en_adc_rangcmpenordis_t;

/**
 ******************************************************************************
 ** \brief  Results the ADC sampling interval can compare interrupt request make or disability
 *****************************************************************************/
typedef enum en_adc_recmpirqnnordis
{
    AdcReCmpIrqDisable  = 0,     /*!ADC sampling results interval CMP is enable*/
    AdcReCmpIrqEnable   = 1,     /*!ADC sampling results interval CMP is Disable*/
    
}en_adc_recmpirqenordis_t;

/**
 ******************************************************************************
 ** \brief  Results the ADC sampling interval comparison testing conditions (range inside and outside)
 *****************************************************************************/
typedef enum en_adc_recmpcndsel
{
    AdcReOutRangeCmp   =  0,     /*!ADC results beyond range CMP*/
    AdcReInRangeCmp    =  1,     /*!ADC results Inside range CMP*/
  
}en_adc_recmpcndsel_t;

/**
 ******************************************************************************
 ** \brief  The ADC sampling results detection CMP count
 *****************************************************************************/
typedef enum en_adc_recheckcmpcnt
{
    SetCmpCheckCnt1  =  1,      /*!Set result CMP check count 1*/
    SetCmpCheckCnt2  =  2,      /*!Set result CMP check count 2*/
    SetCmpCheckCnt3  =  3,      /*!Set result CMP check count 3*/
    SetCmpCheckCnt4  =  4,      /*!Set result CMP check count 4*/
    SetCmpCheckCnt5  =  5,      /*!Set result CMP check count 5*/
    SetCmpCheckCnt6  =  6,      /*!Set result CMP check count 6*/
    SetCmpCheckCnt7  =  7,      /*!Set result CMP check count 7*/

}en_adc_recheckcmpcnt_t;

/**
 ******************************************************************************
 ** \brief  The ADC sampling results detection CMP count bState
 *****************************************************************************/
typedef enum en_adc_redetcmpcntstate
{
    CurDetCmpCnt0  =  0,        /*!The ADC sampling results detection CMP count bState 0*/
    CurDetCmpCnt1  =  1,        /*!The ADC sampling results detection CMP count bState 1*/
    CurDetCmpCnt2  =  2,        /*!The ADC sampling results detection CMP count bState 2*/
    CurDetCmpCnt3  =  3,        /*!The ADC sampling results detection CMP count bState 3*/
    CurDetCmpCnt4  =  4,        /*!The ADC sampling results detection CMP count bState 4*/
    CurDetCmpCnt5  =  5,        /*!The ADC sampling results detection CMP count bState 5*/
    CurDetCmpCnt6  =  6,        /*!The ADC sampling results detection CMP count bState 6*/
    CurDetCmpCnt7  =  7,        /*!The ADC sampling results detection CMP count bState 7*/

}en_adc_redetcmpcntstate_t;

/******************************************************************************
 * Extern type definitions ('typedef')                                        *
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief  ADC configuration Structure type
 *****************************************************************************/
typedef struct
{
    /*! The ADC clock selection*/
    en_adc_samp_freq_sel_t  enAdcSampFreqSel;
    /*! Choose the ADC sampling clock cycle*/
    en_adc_samp_time_sel_t  enAdcSampTimeSel;
    /*! The ADC mode selection*/
    en_adc_samp_mode_t      enAdcSampModeSel;
    /*! The ADC reference voltage*/
    en_adc_ref_vol_sel_t    enAdcRefVolSel;
    /*! The ADC sampling channel selection*/
    en_adc_samp_ch_sel_t    enAdcSampChSel;
    /*! The ADC signal amplification*/
    en_adc_insignalamp_t    enAdcInSignalAmpEn;
    /*! The ADC sampling data alignment*/
    en_adc_result_align_t   enAdcResultAlign;
    
    /*! Pointer to ADC CONV interrupt callback function*/
    func_ptr_t   pfnAdcConvIrqCallback;
    /*! TRUE: enable MVIC, FALSE: don't enable NVIC*/
    boolean_t    bTouchNvic;
         
}stc_adc_confgtypedef_t;

/**
 ******************************************************************************
 ** \brief  ADC  Range CMP configuration(Initialize) Structure type
 *****************************************************************************/
typedef struct
{   
    /*! ADC  Range CMP condition selection*/
    en_adc_recmpcndsel_t   enAdcReCmpCndSel;
    /*! ADC  Range CMP testing number set*/
    en_adc_recheckcmpcnt_t enAdcReCmpCkCnt;
    /*! ADCMPL Regist data,[15:6] effective,[5:0] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    /*! Note: The maximum value set no more than 1024, that is, only 16 variables set [9:0], [he] is 0*/
    volatile uint16_t u16AdcCdlData;
    /*! ADCMPH Regist data,[31:22] effective,[21:16] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    /*! Note: The maximum value set no more than 1024, that is, only 16 variables set [9:0], [he] is 0*/
    volatile uint16_t u16AdcCdhData;
          
    /*! Pointer to ADC CMP interrupt callback function*/
    func_ptr_t   pfnAdcCmpIrqCallback;
    /*! TRUE: enable MVIC, FALSE: don't enable NVIC*/
    boolean_t    bTouchNvic;
     
}stc_adc_rangecmpconfgtypedef_t;


/**
 ******************************************************************************
 ** \brief  ADC Enable OR Disable Structure type
 *****************************************************************************/
typedef struct
{
    /*!<ADC Enable = "1" or Disable = "0"*/
    en_Adc_EnOrDis_t         enAdcEn;
    /*!<The ADC interrupt enable,ENABLE = "1",DISABLE = "0"*/
    en_adc_irq_enordis_t     enAdcIrqEn;
    /*!The ADC sampling start or shut down*/
    en_adc_samp_onoroff_t    enAdcSampStart;
    /*!The ADC signal amplification*/
    en_adc_insignalamp_t     enAdcInSignalAmpEn; 
    
    /*!ADC Result Range CMP enable or disable instance*/
    en_adc_rangcmpenordis_t  enAdcRangCmpEn; 
    /*!ADC Result Range CMP  IRQ enable or disable instance*/
    en_adc_recmpirqenordis_t enAdcReCmpIrqEn; 
      
}stc_adc_cmdtypedef_t;

/**
 ******************************************************************************
 ** \brief  ADC IRQ  Structure type
 *****************************************************************************/
typedef struct
{
    /*!<ADC IRQ Flag*/
    boolean_t  enAdcIrqFlag;
    /*!ADC range compare interrupt flag*/ 
    boolean_t  enAdcRangeCmpItFlag;  
      
}stc_adc_irqtypedef_t;

/**
 ******************************************************************************
 ** \brief  ADC bState & flag Structure type
 *****************************************************************************/
typedef struct
{
    /*!ADC The ADC range comparison threshold range flag*/ 
    boolean_t  bAdcRangCmpOvThresholdFlg;
    /*!ADC Result Range CMP count bState instance*/ 
    uint8_t    u8AdcReDetCmpCntState; 
  
}stc_adc_state_flagtpyedef_t;

/**
 ******************************************************************************
 ** \brief  ADC data Structure type
 *****************************************************************************/
typedef struct
{
    /*! ADC result Regist configuration*/
    __IO  uint16_t   u16AdcResultData; 
    /*! ADCMPL Regist data,[15:6] effective,[5:0] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    __IO uint16_t u16AdcCdlData;
    /*! ADCMPH Regist data,[31:22] effective,[21:16] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    __IO uint16_t u16AdcCdhData;
  
}stc_adc_datatypedef_t;

/**
 ******************************************************************************
 ** \brief  ADC interrupt callback function & internal data structure.
 *****************************************************************************/
typedef struct
{
    /*! ADC IRQ callback function Point*/
    func_ptr_t  pfnAdcIrqCallbackFunpt;
    /*! ADC Rang compare IRQ callback function Point*/
    func_ptr_t  pfnAdcRangCmpIrqCallbackFunpt;
  
}stc_adc_irqcalbackfunpttypedef_t;


/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

#ifndef ENABLE
        #define ENABLE TRUE             /*!< ENABLE DEFINE */
#endif

#ifndef DISABLE
        #define DISABLE FALSE           /*!< DISABLE DEFINE */
#endif

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/
/*! The ADC conversion initialization configuration*/
en_result_t Adc_InitConfig(stc_adc_confgtypedef_t* pstcAdcInitConfigSruct);
/*! The ADC conversion restore the default value*/
en_result_t Adc_DeInit(void);

/*! Range of the ADC is initialized structure configuration*/
en_result_t Adc_RangCMPInitConfig(stc_adc_rangecmpconfgtypedef_t* pstcAdcRangCMPInitConfigSruct);
/*! Range of the ADC registers, restore the default value*/
en_result_t Adc_RangCMPDeInit(void);

/*! Only the ADC conversion ENABLE OR DISABLE*/
void Adc_ConvCmd(boolean_t bState);
/*! Only the ADC conversion start OR off*/
void Adc_ConvStart(boolean_t bState);
/*! Only the ADC range CMP ENABLE OR DISABLE*/
void Adc_RangCmpCmd(boolean_t bState);

/*! Only the ADC CONV IT ENABLE OR DISABLE*/
void Adc_ConvItCmd(boolean_t bState);
/*! Only the ADC RANGE IT ENABLE OR DISABLE*/
void Adc_RangItCmd(boolean_t bState);
/*! The ADC structure  ENABLE OR DISABLE*/
void Adc_StructCmd(stc_adc_cmdtypedef_t* pstcAdcCmdConfig);
#if 1
/*! The ADC sampling mode setting*/
void Adc_ModeSet(en_adc_samp_mode_t enSampMode);
#endif
/*! Get ADC Conversion Value*/
uint16_t Adc_GetConversionValue(void);
/*! Get ADC ALL Value*/
void Adc_GetAllValue(stc_adc_datatypedef_t* pstcADCDatabuff);

/*! Set range CMP Upper Limit Value*/
/*! Note:u16upperLimitValue Shall not be greater than 1024,Only 10 bit low effective*/
void Adc_SetRangCmpUpperLimitValue(uint16_t u16upperLimitValue);
/*! Set range CMP low Limit Value*/
/*! Note:u16lowLimitValue Shall not be greater than 1024,Only 10 bit low effective*/
void Adc_SetRangCmpLowLimitValue(uint16_t u16lowLimitValue);

/*! Get ADC conv IT Flag bState*/
boolean_t Adc_GetConvItFlagState(void);
/*! Get ADC range CMP IT Flag bState*/
boolean_t Adc_GetRangCmpItFlagState(void);
/*! Get ALL IT Flag bState*/
void Adc_GetAllItFlagState(stc_adc_irqtypedef_t* pstcAdcAllIrqState);

/*! Get Over Rage CMP Flag State*/
boolean_t Adc_GetOverRageCmpFlagState(void);
/*! Get ALL Flag bState*/
void Adc_GetRageCmpFlagState(stc_adc_state_flagtpyedef_t* pstcAdcAllState);

/*! Clear ADC conv IT Flag*/
void Adc_ClearConvIrqFlag(void);
/*! Clear ADC range CMP IT Flag*/
void Adc_ClearRangCmpIrqFlag(void);
/*! Clear ADC range CMP & CONV all IT Flag*/
void Adc_ClearAllIrqFlag(void);

/*! Remove the ADC range relatively lower limit value registers*/
void Adc_ClearAllDataRegValue(void);

/*! Configure the ADC module working frequency, sampling time, and the conversion time specified channel*/
/*! ADC IP working frequency = APB0 bus clock cycle (PCLK0)* ADC divider freq coefficient.   */
/*! ADC samp time = ADC IP working frequency(time) * ADC samp Cycles(adc_samp_time_sel). */
/*! ADC cnv time  = ADC IP working frequency(time) * (15+2).  */
/*! ADC total time = ADC samp time + ADC cnv time.  */
void ADC_RegularChannelConfig(en_adc_samp_ch_sel_t enAdcChannel,en_adc_samp_freq_sel_t enAdcSampFreq,en_adc_samp_time_sel_t enAdcSampTime);

//@}
#ifdef __cplusplus
}
#endif

#endif /* __ADC_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
