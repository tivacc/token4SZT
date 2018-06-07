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
/** \file adc.c
 **
 ** A detailed description is available at 
 ** @link AdcGroup ADC description @endlink
 **
 ** History:
 **   - 2016-10-31
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "adc.h"


/*! ADC Sampling frequency selection*/
#define   IS_VALID_SAMPFREQSEL(x)   ( SampFreqSysTDiv1 == (x) ||\
                                      SampFreqSysTDiv2 == (x) ||\
                                      SampFreqSysTDiv4 == (x) ||\
                                      SampFreqSysTDiv8 == (x) )

/*! ADC reference voltage*/
#define   IS_REFVOLSEL(x)           ( RefVolSelInBgr2_5  == (x) ||\
                                      RefVolSelInBgr1_5 == (x) ||\
                                      RefVolSelExtern1   == (x) ||\
                                      RefVolSelExrern2   == (x) )

/*! ADC sampling channel selection*/
#define   IS_SAMPCHSEL(x)           ( SelExInputCH0     == (x) ||\
                                      SelExInputCH1     == (x) ||\
                                      SelExInputCH2     == (x) ||\
                                      SelExInputCH3     == (x) ||\
                                      SelExInputCH4     == (x) ||\
                                      SelExInputCH5     == (x) ||\
                                      SelExInputCH6     == (x) ||\
                                      SelExInputCH7     == (x) ||\
                                      SelExInputCH8     == (x) ||\
                                      SelExInputCH9     == (x) ||\
                                      SelExInputCH10    == (x) ||\
                                      SelExInputCH11    == (x) ||\
                                      SelVccDiV2Input   == (x) ||\
                                      SelVBatDiv2Input  == (x) ||\
                                      SelInInputBgr1_2  == (x) )

/*! ADC sampling time select*/
#define   IS_SAMPTIMESEL(x)         ( AdcSmapTim_3Clk   == (x) ||\
                                      AdcSmapTim_6Clk   == (x) ||\
                                      AdcSmapTim_9Clk   == (x) )

/*! The ADC sampling results detection CMP count*/
#define   IS_RECHECKCMPCNT(x)       ( SetCmpCheckCnt1   == (x) ||\
                                      SetCmpCheckCnt2   == (x) ||\
                                      SetCmpCheckCnt3   == (x) ||\
                                      SetCmpCheckCnt4   == (x) ||\
                                      SetCmpCheckCnt5   == (x) ||\
                                      SetCmpCheckCnt6   == (x) ||\
                                      SetCmpCheckCnt7   == (x) )

/*! The ADC sampling results detection CMP count bState*/
#define   IS_REDETCMPCNTSTATE(x)    ( CurDetCmpCnt0     == (x) ||\
                                      CurDetCmpCnt1     == (x) ||\
                                      CurDetCmpCnt2     == (x) ||\
                                      CurDetCmpCnt3     == (x) ||\
                                      CurDetCmpCnt4     == (x) ||\
                                      CurDetCmpCnt5     == (x) ||\
                                      CurDetCmpCnt6     == (x) ||\
                                      CurDetCmpCnt7     == (x) )

/*! The ADC range CMP  ADCMPL register maximum */
#define   ADCMPLMAX    1024
#define   IS_ADCCMPL(x)              ( ADCMPLMAX > (x))

/*! The ADC range CMP  ADCMPH register maximum */
#define   ADCMPHMAX    1024
#define   IS_ADCCMPH(x)              ( ADCMPHMAX  > (x))



/**
  * @\brief Define global instance pointer to the callback function
  */
static stc_adc_irqcalbackfunpttypedef_t ADC_IRQCalbackFunPtInstan = { 0, 0 };


/**
 ******************************************************************************
 ** \brief Adc_ConvIrqHandler 
 **        The ADC conversion interrupt request header.
 ** 
 ** \param [IN] data    : dummy
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ConvIrqHandler(uint8_t data)
{
    /*!< Determine the ADC conversion interrupt flag bit*/
    if (M0P_ADC->CTL1_f.ADCIF == TRUE)
    {
        /*!< Clear ADC conversion interrupt flag bit*/
        M0P_ADC->CTL1_f.ADCIF = FALSE;
        /*!< ADC CONV judgment to the callback function pointer object instance is null*/
        if (ADC_IRQCalbackFunPtInstan.pfnAdcIrqCallbackFunpt != NULL)
        {
            /*!< Perform pointer to the callback ADC conversion function instance object function*/
            ADC_IRQCalbackFunPtInstan.pfnAdcIrqCallbackFunpt();
        }
    }
}


/**
 ******************************************************************************
 ** \brief Adc_CmpIrqHandler 
 **        Range of the ADC interrupt request header.
 ** 
 ** \param [IN] data    :None 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_CmpIrqHandler(uint8_t data)
{
    /*!< Determine the ADC CMP interrupt flag bit*/
    if (M0P_ADC->ADCMPIF_f.CMPIF == TRUE)
    {
        /*!< Clear the ADC CMP interrupt flag bit*/
        M0P_ADC->ADCMPIF_f.CMPIF = FALSE;
        /*!< Judgment pointer to the callback ADC range comparison function instance object is null*/
        if (ADC_IRQCalbackFunPtInstan.pfnAdcRangCmpIrqCallbackFunpt != NULL)
        {
            /*!< Perform pointer to the callback ADC range comparison function instance object function*/
            ADC_IRQCalbackFunPtInstan.pfnAdcRangCmpIrqCallbackFunpt();

        }

    }
}


/**
 ******************************************************************************
 ** \brief ADC_NVICCmd 
 **        the ADC interrupt enable or disable.
 ** 
 ** \param [IN] bState  :       ENABLE OR DISABLE.
 ** 
 ** \retval void 
 ******************************************************************************/
static void ADC_NVICCmd(boolean_t bState)
{
    /*!< ENABLE ADC interrupt*/
    if (bState == TRUE)
    {
        NVIC_ClearPendingIRQ(ADC_IRQn);
        NVIC_EnableIRQ(ADC_IRQn);
        NVIC_SetPriority(ADC_IRQn, DDL_IRQ_LEVEL_ADC);

    }
    /*!< DISABLE ADC interrupt*/
    if (bState == FALSE)
    {
        NVIC_ClearPendingIRQ(ADC_IRQn);
        NVIC_DisableIRQ(ADC_IRQn);
        NVIC_SetPriority(DTIM_IRQn, DDL_IRQ_LEVEL_ADC);

    }
}


/**
 ******************************************************************************
 ** \brief Adc_InitConfig 
 **        According to the structure to initialize the ADC peripheral
 **        registers.
 ** 
 ** \param [IN] pstcAdcInitConfigSruct  :   ADC initialization structure entry
 ** address.
 ** 
 ** \retval OK:         Init Ok
 **         others:     Init failed.
 ******************************************************************************/
en_result_t Adc_InitConfig(stc_adc_confgtypedef_t *pstcAdcInitConfigSruct)
{
    /*!< The function returns the bState*/
    en_result_t  enresult =  Error;
    /*!< Pointer to the ADC Regist variables*/
    volatile stc_adc_regtypdef_t *pADCReg = NULL;

    /*! Pointer to interrupt callback function*/
    stc_adc_irqcalbackfunpttypedef_t *pfuncpt = NULL;

    /*!< Get ADC Regist point*/
    pADCReg = M0P_ADC;

    /*! For instance pointer to the callback function address*/
    pfuncpt = &ADC_IRQCalbackFunPtInstan;

    /*! Parameter detection*/
    ASSERT(NULL != pstcAdcInitConfigSruct);
    ASSERT(IS_VALID_SAMPFREQSEL(pstcAdcInitConfigSruct->enAdcSampFreqSel));
    ASSERT(IS_REFVOLSEL(pstcAdcInitConfigSruct->enAdcRefVolSel));
    ASSERT(IS_SAMPCHSEL(pstcAdcInitConfigSruct->enAdcSampChSel));
    ASSERT(IS_SAMPTIMESEL(pstcAdcInitConfigSruct->enAdcSampTimeSel));

    /*To determine whether a ADC register address*/
    if (pADCReg == NULL)
    {
        enresult = ErrorInvalidParameter;
        /*Provided parameter is not valid*/
        return enresult;
    }

    /*!< Setting function bState return variables*/
    enresult =  Ok;

    /*!< The ADC sampling conversion clock*/
    pADCReg->CTL1_f.ADC_CLK_SEL  = pstcAdcInitConfigSruct->enAdcSampFreqSel;
    /*!< The ADC sampling time set*/
    switch (pstcAdcInitConfigSruct->enAdcSampTimeSel)
    {
        /*!The ADC with three sampling ADC CLK clock*/
        case AdcSmapTim_3Clk:
            /*!< The ADC sampling time SEL*/
            pADCReg->CTL2_f.ADC_SAMPLE_SEL = 0;
            break;
            /*!The ADC with six sampling ADC CLK clock*/
        case AdcSmapTim_6Clk:
            /*!< The ADC sampling time SEL*/
            pADCReg->CTL2_f.ADC_SAMPLE_SEL = 2;
            break;
            /*!The ADC with nine sampling ADC CLK clock*/
        case AdcSmapTim_9Clk:
            /*!The ADC with nine sampling ADC CLK clock*/
//                              pADCReg->CTL2_f.ADC_SAMPLE_SEL = 3;
            break;

        default:
            /*Provided parameter is not valid*/
            enresult = ErrorInvalidParameter;
            break;
    }

    /*!< The ADC sampling mode*/
    pADCReg->CTL2_f.ADC_MODE  = pstcAdcInitConfigSruct->enAdcSampModeSel;
    /*!< The ADC reference voltage*/
    pADCReg->CTL1_f.ADC_VREF  = pstcAdcInitConfigSruct->enAdcRefVolSel;
    /*!< The ADC sampling channel selection*/
    pADCReg->CTL1_f.ADC_CHL_SEL  = pstcAdcInitConfigSruct->enAdcSampChSel;
    /*!< The ADC input signal amplifier enable signal*/
    pADCReg->CTL2_f.VINBUF_EN  =  pstcAdcInitConfigSruct->enAdcInSignalAmpEn;
    /*!< The ADC sampling results alignment*/
    pADCReg->CTL2_f.ADC_ALIGN  =  pstcAdcInitConfigSruct->enAdcResultAlign;

    /*! Set ADC CONV interrupt callback function */
    pfuncpt->pfnAdcIrqCallbackFunpt = pstcAdcInitConfigSruct->pfnAdcConvIrqCallback;
#if 0
    /*! In interrupt callback registry (i.e., interrupt the callback function is registered in the array user callback function pointer)*/
    /*!  in the registered user interrupt function name*/
    Intr_RegisterHandler( DDL_IRQ_ADC_CONV ,ADC_CONVIRQHandler);
#endif
    /*! ENABLE Interrupt */
    if (pstcAdcInitConfigSruct->bTouchNvic == TRUE)
    {
        ADC_NVICCmd(ENABLE);
    } else {
      ADC_NVICCmd(DISABLE);
    }
    return enresult;

}


/**
 ******************************************************************************
 ** \brief Adc_DeInit 
 **        All the ADC registers restore the default value.
 ** \param [IN]     : 
 ** 
 ** \retval OK:         Deinit Ok
 **         others:     DeInit failed.
 ******************************************************************************/
en_result_t Adc_DeInit(void)
{
    /*!< The function returns the bState*/
    en_result_t  enresult =  Error;
    /*!< Pointer to the ADC Regist variables*/
    volatile stc_adc_regtypdef_t *pADCReg = NULL;

    /*! Pointer to interrupt callback function*/
    stc_adc_irqcalbackfunpttypedef_t *pfuncpt = NULL;

    /*!< Get ADC Regist point*/
    pADCReg = M0P_ADC;

    /*! For instance pointer to the callback function address*/
    pfuncpt = &ADC_IRQCalbackFunPtInstan;

    /*To determine whether a ADC register address*/
    if (pADCReg == NULL)
    {
        enresult = ErrorInvalidParameter;
        /*Provided parameter is not valid*/
        return enresult;
    }
    /*!< Setting function bState return variables*/
    enresult =  Ok;

    /*!< ADC ENABLE OR DISABLE*/
    pADCReg->CTL1_f.ADC_EN  = FALSE;
    /*!< The ADC sampling conversion clock*/
    pADCReg->CTL1_f.ADC_CLK_SEL  =  0;
    /*!< The ADC reference voltage*/
    pADCReg->CTL1_f.ADC_VREF  =  1;
    /*!< The ADC sampling channel selection*/
    pADCReg->CTL1_f.ADC_CHL_SEL  =  15;
    /*!< A/D conversion interrupt request enabled*/
    pADCReg->CTL1_f.ADCIE = FALSE;
    /*!< A/D conversion interrupt request logo, write 0 effectively, write 1 is invalid*/
    pADCReg->CTL1_f.ADCIF = FALSE;

    /*!< The ADC sampling start signal*/
    pADCReg->CTL2_f.ADC_START  =  FALSE;
    /*!< The ADC sampling results alignment*/
    pADCReg->CTL2_f.ADC_ALIGN  =  FALSE;
    /*!< The ADC sampling mode*/
    pADCReg->CTL2_f.ADC_MODE  =  FALSE;
    /*!< The ADC input signal amplifier enable signal*/
    pADCReg->CTL2_f.VINBUF_EN  =  FALSE;
    /*!< The ADC sampling time SEL*/
    pADCReg->CTL2_f.ADC_SAMPLE_SEL = 2;

    /*The ADC sampling results*/
    pADCReg->RESULT = 0X00;

    /*! Set ADC CONV interrupt callback function */
    pfuncpt->pfnAdcIrqCallbackFunpt = NULL;
#if 0
    /*! In interrupt callback registry (i.e., interrupt the callback function is registered in the array user callback function pointer)*/
    /*!  in the registered user interrupt function name*/
    Intr_UnRegisterHandler(DDL_IRQ_ADC_CONV);
#endif
    /*! ENABLE Interrupt */
    ADC_NVICCmd(DISABLE);

    return enresult;
}



/**
 ******************************************************************************
 ** \brief Adc_RangCMPInitConfig 
 **        Range of the ADC is initialized structure configuration.
 ** 
 ** \param [IN] pstcAdcRangCMPInitConfigSruct   : ADC range CMP initialization
 **                                                  structure entry address.
 ** 
 ** \retval OK:         Deinit Ok
 **         others:     DeInit failed.
 ******************************************************************************/
en_result_t Adc_RangCMPInitConfig(stc_adc_rangecmpconfgtypedef_t *pstcAdcRangCMPInitConfigSruct)
{

    /*!< The function returns the bState*/
    en_result_t  enresult =  Error;
    /*!< Pointer to the ADC Regist variables*/
    volatile stc_adc_regtypdef_t *pADCReg = NULL;
    /*! Pointer to interrupt callback function*/
    stc_adc_irqcalbackfunpttypedef_t *pfuncpt = NULL;
    /*!< Get ADC Regist point*/
    pADCReg = M0P_ADC;

    /*! For instance pointer to the callback function address*/
    pfuncpt = &ADC_IRQCalbackFunPtInstan;

    /*! Parameter detection*/
    ASSERT(NULL != pstcAdcRangCMPInitConfigSruct);
    ASSERT(IS_RECHECKCMPCNT(pstcAdcRangCMPInitConfigSruct->enAdcReCmpCkCnt));
    ASSERT(IS_ADCCMPL(pstcAdcRangCMPInitConfigSruct->u16AdcCdlData));
    ASSERT(IS_ADCCMPH(pstcAdcRangCMPInitConfigSruct->u16AdcCdhData));

    /*To determine whether a ADC register address*/
    if (pADCReg == NULL)
    {
        enresult = ErrorInvalidParameter;
        /*Provided parameter is not valid*/
        return enresult;
    }

    /*!< Setting function bState return variables*/
    enresult =  Ok;

    /*! Results the ADC sampling interval comparison testing conditions (range inside and outside)*/
    pADCReg->ADCMPCTL_f.CMPTRIG = pstcAdcRangCMPInitConfigSruct->enAdcReCmpCndSel;
    /*! The ADC sampling results detection*/
    pADCReg->ADCMPCTL_f.CMPCNT = pstcAdcRangCMPInitConfigSruct->enAdcReCmpCkCnt;
    /*! ADCMPL Regist data,[15:6] effective,[5:0] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    pADCReg->ADCMPL_f.CDL = 0;
    pADCReg->ADCMPL = (pstcAdcRangCMPInitConfigSruct->u16AdcCdlData << 6);
    /*! ADCMPH Regist data,[31:22] effective,[21:16] invalid r:00*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    pADCReg->ADCMPH_f.CDH = 0;
    pADCReg->ADCMPH = (pstcAdcRangCMPInitConfigSruct->u16AdcCdhData << 6);

    /*! Set ADC CMP interrupt callback function */
    pfuncpt->pfnAdcRangCmpIrqCallbackFunpt = pstcAdcRangCMPInitConfigSruct->pfnAdcCmpIrqCallback;
#if 0
    /*! In interrupt callback registry (i.e., interrupt the callback function is registered in the array user callback function pointer)*/
    /*! in the registered user interrupt function name*/
    Intr_RegisterHandler( DDL_IRQ_ADC_CMP  ,ADC_CMPIRQHandler);
#endif
    /*! ENABLE Interrupt */
    if (pstcAdcRangCMPInitConfigSruct->bTouchNvic == TRUE)
    {
        ADC_NVICCmd(ENABLE);
    } else {
      ADC_NVICCmd(DISABLE);
    }
    
    return enresult;

}


/**
 ******************************************************************************
 ** \brief Adc_RangCMPDeInit 
 **        Range of the ADC registers, restore the default value.
 ** \param [IN]     : 
 ** 
 ** \retval OK:         Deinit Ok
 **         others:     DeInit failed.
 ******************************************************************************/
en_result_t Adc_RangCMPDeInit(void)
{
    /*!< The function returns the bState*/
    en_result_t  enresult =  Error;
    /*!< Pointer to the ADC Regist variables*/
    volatile stc_adc_regtypdef_t *pADCReg = NULL;
    /*! Pointer to interrupt callback function*/
    stc_adc_irqcalbackfunpttypedef_t *pfuncpt = NULL;
    /*!< Get ADC Regist point*/
    pADCReg = M0P_ADC;

    /*! For instance pointer to the callback function address*/
    pfuncpt = &ADC_IRQCalbackFunPtInstan;

    /*To determine whether a ADC register address*/
    if (pADCReg == NULL)
    {
        enresult = ErrorInvalidParameter;
        /*Provided parameter is not valid*/
        return enresult;
    }

    /*!< Setting function bState return variables*/
    enresult =  Ok;

    /*!Compare interrupt flag bit ADC interval*/
    pADCReg->ADCMPIF_f.CMPIF = FALSE;

    /*! ADC sampling result is enabling interval, when the ban on A/D results interval, CMPCNT [2-0] the number of bState will be initialized to 000 h*/
    pADCReg->ADCMPCTL_f.CMPEN = FALSE;
    /*! The ADC sampling interval can compare interrupt request to make*/
    pADCReg->ADCMPCTL_f.CMPIE = FALSE;
    /*! Results the ADC sampling interval comparison testing conditions (range inside and outside)*/
    pADCReg->ADCMPCTL_f.CMPTRIG = FALSE;
    /*! The ADC sampling results detection*/
    pADCReg->ADCMPCTL_f.CMPCNT = 1;

    /*! Set ADC CMP interrupt callback function */
    pfuncpt->pfnAdcRangCmpIrqCallbackFunpt = NULL;
#if 0
    /*! In interrupt callback registry (i.e., interrupt the callback function is registered in the array user callback function pointer)*/
    /*!  in the registered user interrupt function name*/
    Intr_UnRegisterHandler(DDL_IRQ_ADC_CMP);
#endif
    /*! ENABLE Interrupt */
    ADC_NVICCmd(DISABLE);

    return enresult;

}


/**
 ******************************************************************************
 ** \brief Adc_ConvCmd 
 **        Only the ADC conversion ENABLE OR DISABLE.
 ** 
 ** \param [IN] bState  : Enable = 1 or Disable = 0
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ConvCmd(boolean_t bState)
{
    M0P_ADC->CTL1_f.ADC_EN = bState;
}


/**
 ******************************************************************************
 ** \brief Adc_ConvStart 
 **        Only the ADC conversion ENABLE OR DISABLE.
 ** 
 ** \param [IN] bState  : start = 1 ,shutdown = 0
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ConvStart(boolean_t bState)
{
    /*!The ADC sampling start or shut down*/
    M0P_ADC->CTL2_f.ADC_START = bState;
}


/**
  * @Func   void Adc_ConvCmd(boolean_t bState)
  * @brief  
  * @param  bState: ENABLE OR DISABLE.
  * @retval None. 
  */

/**
 ******************************************************************************
 ** \brief Adc_RangCmpCmd 
 **        Only the ADC range CMP ENABLE OR DISABLE.
 ** 
 ** \param [IN] bState  :       Enable = 1 , Disable = 0.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_RangCmpCmd(boolean_t bState)
{
    /*!ADC Result Range CMP enable or disable instance*/
    M0P_ADC->ADCMPCTL_f.CMPEN = bState;
}


/**
 ******************************************************************************
 ** \brief Adc_ConvItCmd 
 **        Only the ADC CONV IT ENABLE OR DISABLE.
 ** 
 ** \param [IN] bState  : ENABLE = 1,DISABLE = 0
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ConvItCmd(boolean_t bState)
{
    M0P_ADC->CTL1_f.ADCIE = bState;

}


/**
 ******************************************************************************
 ** \brief Adc_RangItCmd 
 **        Only the ADC RANGE IT ENABLE OR DISABLE.
 ** 
 ** \param [IN] bState  :       ENABLE = 1,DISABLE = 0
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_RangItCmd(boolean_t bState)
{
    /*!ADC Result Range CMP  IRQ enable or disable instance*/
    M0P_ADC->ADCMPCTL_f.CMPIE = bState;
}


/**
 ******************************************************************************
 ** \brief Adc_StructCmd 
 **        The ADC structure  ENABLE OR DISABLE.
 ** 
 ** \param [IN] pstcAdcCmdConfig    : Pointer to configure structure. 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_StructCmd(stc_adc_cmdtypedef_t *pstcAdcCmdConfig)
{
    /*!<ADC Enable = "1" or Disable = "0"*/
    M0P_ADC->CTL1_f.ADC_EN = pstcAdcCmdConfig->enAdcEn;
    /*!The ADC sampling start or shut down*/
    M0P_ADC->CTL2_f.ADC_START = pstcAdcCmdConfig->enAdcSampStart;
    /*!<ADC Enable = "1" or Disable = "0"*/
    M0P_ADC->CTL2_f.VINBUF_EN = pstcAdcCmdConfig->enAdcInSignalAmpEn;
    /*!ADC Result Range CMP enable or disable instance*/
    M0P_ADC->ADCMPCTL_f.CMPEN = pstcAdcCmdConfig->enAdcRangCmpEn;

    /*!<The ADC interrupt enable,ENABLE = "1",DISABLE = "0"*/
    M0P_ADC->CTL1_f.ADCIE = pstcAdcCmdConfig->enAdcIrqEn;
    /*!ADC Result Range CMP  IRQ enable or disable instance*/
    M0P_ADC->ADCMPCTL_f.CMPIE = pstcAdcCmdConfig->enAdcReCmpIrqEn;
}


/**
 ******************************************************************************
 ** \brief Adc_ModeSet 
 **        The ADC sampling mode setting.
 ** 
 ** \param [IN] enSampMode  :   AdcContinSamp or AdcSingleSmple.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ModeSet(en_adc_samp_mode_t enSampMode)
{
    M0P_ADC->CTL2_f.ADC_MODE = enSampMode;
}


/**
 ******************************************************************************
 ** \brief Adc_GetConversionValue 
 **        Get ADC Conversion Value.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval uint16_t converted value.
 ******************************************************************************/
uint16_t Adc_GetConversionValue(void)
{
    return (M0P_ADC->RESULT);
}


/**
 ******************************************************************************
 ** \brief Adc_GetAllValue 
 **        Get ADC ALL Value.
 ** 
 ** \param [OUT] pstcADCDatabuff :  Pointer to Read data structure.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_GetAllValue(stc_adc_datatypedef_t *pstcADCDatabuff)
{
    /*! Get ADC Conversion Value*/
    pstcADCDatabuff->u16AdcResultData = M0P_ADC->RESULT;
    /*! Get*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    pstcADCDatabuff->u16AdcCdhData = M0P_ADC->ADCMPH;
    /*! Get*/
    /*! After the ADC range compare features enabled*/
    /*! high ADC sampling results of 10 will be compared with the lower limit threshold, low two won't compare*/
    pstcADCDatabuff->u16AdcCdlData = M0P_ADC->ADCMPL;

}


/**
 ******************************************************************************
 ** \brief Adc_SetRangCmpUpperLimitValue 
 **        Set range CMP Upper Limit Value.
 ** 
 ** \param [IN] u16upperLimitValue  :   range CMP Upper Limit Value.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_SetRangCmpUpperLimitValue(uint16_t u16upperLimitValue)
{
    /*! Passing parameters detection*/
    ASSERT(IS_ADCCMPL(u16upperLimitValue));
    ASSERT(IS_ADCCMPH(u16upperLimitValue));

    /*! Set range CMP Upper Limit Value*/
    /*! ADCMPH Regist data,[15:6] effective,[5:0] invalid r:00*/
    M0P_ADC->ADCMPH = (u16upperLimitValue << 6);
}


/**
 ******************************************************************************
 ** \brief Adc_SetRangCmpLowLimitValue 
 **        Set range CMP low Limit Value.
 ** 
 ** \param [IN] u16lowLimitValue    :       range CMP low Limit Value.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_SetRangCmpLowLimitValue(uint16_t u16lowLimitValue)
{
    /*! Passing parameters detection*/
    ASSERT(IS_ADCCMPL(u16lowLimitValue));
    ASSERT(IS_ADCCMPH(u16lowLimitValue));

    /*! Set range CMP Upper Limit Value*/
    /*! ADCMPH Regist data,[15:6] effective,[5:0] invalid r:00*/
    M0P_ADC->ADCMPL = (u16lowLimitValue << 6);
}


/**
 ******************************************************************************
 ** \brief Adc_GetConvItFlagState 
 **        Get ADC conv IT Flag bState.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval boolean_t   0:The ADC conversion unfinished , 1:The ADC conversion
 ** finished.
 ******************************************************************************/
boolean_t Adc_GetConvItFlagState(void)
{
    /*! Get ADC conv IT Flag bState*/
    return (M0P_ADC->CTL1_f.ADCIF);

}


/**
 ******************************************************************************
 ** \brief Adc_GetRangCmpItFlagState 
 **        Get ADC range CMP IT Flag bState.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval boolean_t  bState: 0:Not overrun, 1:Detection of the ADC sampling results meet the set conditions (upper and lower threshold and testing number). 
 ******************************************************************************/
boolean_t Adc_GetRangCmpItFlagState(void)
{
    /*! Get ADC range CMP IT Flag bState*/
    return (M0P_ADC->ADCMPIF_f.CMPIF);

}


/**
 ******************************************************************************
 ** \brief Adc_GetAllItFlagState 
 **        Get ALL IT Flag bState.
 ** 
 ** \param [IN] pstcAdcAllIrqState  :   ADC all IRQ struct.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_GetAllItFlagState(stc_adc_irqtypedef_t *pstcAdcAllIrqState)
{
    /*! Get ADC conv IT Flag bState*/
    pstcAdcAllIrqState->enAdcIrqFlag = M0P_ADC->CTL1_f.ADCIF;
    /*! Get ADC range CMP IT Flag bState*/
    pstcAdcAllIrqState->enAdcRangeCmpItFlag = M0P_ADC->ADCMPIF_f.CMPIF;
}


/**
 ******************************************************************************
 ** \brief Adc_GetOverRageCmpFlagState 
 **        Get beyond beyond comparison sign.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval boolean_t:  1 - A/D results > upper limit threshold value
 **                     0 - A/D results < lower limit threshold value
 ******************************************************************************/
boolean_t Adc_GetOverRageCmpFlagState(void)
{
    /*! Get The ADC range comparison threshold range Flag*/
    return (M0P_ADC->ADCMPF_f.CMPF);
}


/**
 ******************************************************************************
 ** \brief Adc_GetRageCmpFlagState 
 **        Get ALL Flag bState.
 ** 
 ** \param [OUT] pstcAdcAllState :      ADC all flag bState struct.
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_GetRageCmpFlagState(stc_adc_state_flagtpyedef_t *pstcAdcAllState)
{
    /*! Get The ADC range comparison threshold range Flag*/
    pstcAdcAllState->bAdcRangCmpOvThresholdFlg = M0P_ADC->ADCMPF_f.CMPF;
    /*! Get The ADC range comparison threshold range bState*/
    pstcAdcAllState->u8AdcReDetCmpCntState = M0P_ADC->ADCMPCTL_f.CMPCNT_ST;
}


/**
 ******************************************************************************
 ** \brief Adc_ClearConvIrqFlag 
 **        Clear ADC conv IT Flag.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ClearConvIrqFlag(void)
{
    /*! Clear ADC conv IT Flag */
    M0P_ADC->CTL1_f.ADCIF = FALSE;

}


/**
 ******************************************************************************
 ** \brief Adc_ClearRangCmpIrqFlag 
 **        Clear ADC range CMP IT Flag.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ClearRangCmpIrqFlag(void)
{
    /*! Clear ADC range CMP IT Flag */
    M0P_ADC->ADCMPIF_f.CMPIF = FALSE;

}


/**
 ******************************************************************************
 ** \brief Adc_ClearAllIrqFlag 
 **        Clear ADC range CMP & CONV all IT Flag.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ClearAllIrqFlag(void)
{
    /*! Clear ADC conv IT Flag */
    M0P_ADC->CTL1_f.ADCIF = FALSE;
    /*! Clear ADC range CMP IT Flag */
    M0P_ADC->ADCMPIF_f.CMPIF = FALSE;
}


/**
 ******************************************************************************
 ** \brief Adc_ClearAllDataRegValue 
 **        Clear ADC range CMP & CONV all IT Flag.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Adc_ClearAllDataRegValue(void)
{
    /*! Remove the ADC range limit set data registers*/
    M0P_ADC->ADCMPH = 0x00;
    /*! Remove the ADC range relatively lower limit value registers*/
    M0P_ADC->ADCMPL = 0x00;

}


/**
 ******************************************************************************
 ** \brief ADC_RegularChannelConfig 
 **        Configure the ADC module working frequency, sampling time, and the conversion time specified channel.
 **        ADC IP working frequency = APB0 总线时钟 (PCLK0) 周期 * ADC divider freq coefficient.
 **        ADC samp time = ADC IP working frequency(time) * ADC samp Cycles(adc_samp_time_sel).
 **        ADC cnv time  = ADC IP working frequency(time) * (15+2). ADC total time = ADC samp
 **        time + ADC cnv time.
 ** 
 ** \param [IN] enAdcChannel    :   ADC channel
 ** \param [IN] enAdcSampFreq   :   sample frequency enum  value
 ** \param [IN] enAdcSampTime   :   sample time enum value
 ** 
 ** \retval void 
 ******************************************************************************/
void ADC_RegularChannelConfig(en_adc_samp_ch_sel_t enAdcChannel, en_adc_samp_freq_sel_t enAdcSampFreq, en_adc_samp_time_sel_t enAdcSampTime)
{
    /*! Parameter detection*/
    ASSERT(IS_SAMPCHSEL(enAdcChannel));
    ASSERT(IS_VALID_SAMPFREQSEL(enAdcSampFreq));
    ASSERT(IS_SAMPTIMESEL(enAdcSampTime));

    /*! Configure the ADC module working frequency, sampling time, and the conversion time specified channel*/
    M0P_ADC->CTL1_f.ADC_CHL_SEL = enAdcChannel;
    M0P_ADC->CTL1_f.ADC_CLK_SEL = enAdcSampFreq;
    /*!< The ADC sampling time set*/
    switch (enAdcSampTime)
    {
        /*!The ADC with three sampling ADC CLK clock*/
        case AdcSmapTim_3Clk:
            /*!< The ADC sampling time SEL*/
            M0P_ADC->CTL2_f.ADC_SAMPLE_SEL = 0;
            break;
            /*!The ADC with six sampling ADC CLK clock*/
        case AdcSmapTim_6Clk:
            /*!< The ADC sampling time SEL*/
            M0P_ADC->CTL2_f.ADC_SAMPLE_SEL = 2;
            break;
            /*!The ADC with nine sampling ADC CLK clock*/
        case AdcSmapTim_9Clk:
            /*!The ADC with nine sampling ADC CLK clock*/
            M0P_ADC->CTL2_f.ADC_SAMPLE_SEL = 3;
            break;

        default:
            /*Provided parameter is not valid*/
            break;
    }
}

//@} // ADC Functions

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

