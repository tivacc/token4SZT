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
/** \file ct.c
 **
 ** Composite timer driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-16  1.0  HongJH First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ct.h"


/**
 ******************************************************************************
 ** \addtogroup CtGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

#define IS_VALID_CH(x)               (CtChannel0  == (x) || \
                                      CtChannel1  == (x) || \
                                      CtChannel2  == (x) || \
                                      CtChannel3  == (x))

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/


/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/
static stc_ct_instance_data_t* CtGetInstanceDataPtr(uint8_t u8Idx);
static void CtEnableNvic(void);
static void CtDisableNvic(void);

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/* Look-up table for all enabled CT instances and their internal data  */
static stc_ct_instance_data_t m_astcCtInstanceDataLut[8] =
{
    { 
        0,                    /* CT channel */
        &CT0,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        1,                    /* CT channel */
        &CT1,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        2,                    /* CT channel */
        &CT2,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        3,                    /* CT channel */
        &CT3,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        4,                    /* CT channel */
        &CT4,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        5,                    /* CT channel */
        &CT5,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        6,                    /* CT channel */
        &CT6,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet) */
    },
    { 
        7,                    /* CT channel */
        &CT7,                 /* pstcInstance */
        {NULL, NULL, NULL}    /* stcInternData (not initialized yet)  */
    },
};

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/


/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief Return the data for a certain CT instance.
 **
 ** \param u8Idx             Channel index
 **
 ** \return Pointer to instance data or NULL if instance is not enabled (or not known)
 **
 ******************************************************************************/
static stc_ct_instance_data_t* CtGetInstanceDataPtr(uint8_t u8Idx) 
{
    /* Check parameters */
    ASSERT(IS_VALID_CH(u8Idx));

    if (u8Idx == m_astcCtInstanceDataLut[u8Idx].u32Idx)
    {
        return &m_astcCtInstanceDataLut[u8Idx];
    }

    return NULL;
} /* CtGetInstanceDataPtr */      

/**
******************************************************************************
** \brief Device dependent initialization of interrupts according CMSIS with
**        level defined in interrupt_xxx.h
**
******************************************************************************/
static void CtEnableNvic(void)
{
    NVIC_ClearPendingIRQ(CTIM0_7_FLASH_IRQn); 
    NVIC_EnableIRQ(CTIM0_7_FLASH_IRQn); 
    NVIC_SetPriority(CTIM0_7_FLASH_IRQn, DDL_IRQ_LEVEL_CT07);
} /* CtIEnableNvic */

/**
 ******************************************************************************
 ** \brief Device dependent de-initialization of interrupts according CMSIS 
 **
 ******************************************************************************/
static void CtDisableNvic(void)
{        
    NVIC_ClearPendingIRQ(CTIM0_7_FLASH_IRQn); 
    NVIC_DisableIRQ(CTIM0_7_FLASH_IRQn); 
    NVIC_SetPriority(CTIM0_7_FLASH_IRQn, DDL_IRQ_LEVEL_DEFAULT);  
} /* CtDisableNvic */


/**
 ******************************************************************************
 ** \brief  CT irq0  interrupt handler function
 **
 ** \param [in] u8Idx CT channel
 **
 ** \retval void
 **
 ******************************************************************************/
void Ct_Irq0Handler(uint8_t u8Idx)
{
    uint8_t u8Irq = 0;
    uint32_t u32BitBandPwmStaReg = 0ul;
    stc_ct_instance_data_t *pstcCtInstanceData = NULL;

    /* Check parameters */
    ASSERT(IS_VALID_CH(u8Idx));

    /* Get actual address of register list of current channel */
    pstcCtInstanceData = CtGetInstanceDataPtr(u8Idx);
    if (NULL == pstcCtInstanceData)
    {
        return;
    }
    
    // Get Interrupt Request
    u8Irq = pstcCtInstanceData->pstcInstance->STA;
    u32BitBandPwmStaReg = (uint32_t)(&(bM0P_CT0_PWM_STA_UDFIR)) + \
         ((uint32_t)(pstcCtInstanceData->pstcInstance) - M0P_CT0_PWM_BASE) * 32;

    // Duty Match Interrupt (PWM)   
    if (0x22u == (u8Irq & 0x22u)) 
    {
        // Clear Interrupt 
        *((volatile unsigned int*)(u32BitBandPwmStaReg + 4 * 1)) = 0;

        if (NULL != pstcCtInstanceData->stcInternData.pfnBit1IrqCb)
        {
            pstcCtInstanceData->stcInternData.pfnBit1IrqCb();  // Call CallBackIrq
        }
    }
    
    /* 
     * Underflow Interrupt (PWM,PPG,Reload timer)
     * Overflow Interrupt (PWC) 
     */
    if (0x11u == (u8Irq & 0x11u))
    {
        // Clear Interrupt 
        *((volatile unsigned int*)(u32BitBandPwmStaReg + 4 * 0)) = 0;
        
        if (NULL != pstcCtInstanceData->stcInternData.pfnBit0IrqCb) 
        {
            pstcCtInstanceData->stcInternData.pfnBit0IrqCb();  // Call CallBackIrq
        }
    }   
}  /* Ct_Irq0Handler */

/**
 ******************************************************************************
 ** \brief  CT irq1  interrupt handler function
 **
 ** \param [in] u8Idx CT channel
 **
 ** \retval void
 **
 ******************************************************************************/
void Ct_Irq1Handler(uint8_t u8Idx)
{
    uint8_t u8Irq = 0;
    uint32_t u32BitBandPwmStaReg = 0ul;
    stc_ct_instance_data_t *pstcCtInstanceData = NULL;

    /* Check parameters */
    ASSERT(IS_VALID_CH(u8Idx));

    /* Get actual address of register list of current channel */
    pstcCtInstanceData = CtGetInstanceDataPtr(u8Idx);
    if (NULL == pstcCtInstanceData)
    {
        return;
    }
    
    // Get Interrupt Request
    u8Irq = pstcCtInstanceData->pstcInstance->STA;

    /*
     * Trigger Interrupt (PWM,PPG,Reload timer)
     * Measurement completion Interrupt (PWC)
     */
    if ((u8Irq & 4ul) > 0) 
    {
        u32BitBandPwmStaReg = (uint32_t)(&(bM0P_CT0_PWM_STA_UDFIR)) + \
             ((uint32_t)(pstcCtInstanceData->pstcInstance) - M0P_CT0_PWM_BASE) * 32;

        //  Clear Interrupt 
        *((volatile unsigned int*)(u32BitBandPwmStaReg + 4 * 2)) = 0;

        if (NULL != pstcCtInstanceData->stcInternData.pfnBit2IrqCb) 
        {
            pstcCtInstanceData->stcInternData.pfnBit2IrqCb();  // Call CallBackIrq 
        }
    }
}  /* Ct_Irq1Handler */

/**
 ******************************************************************************
 ** \brief Configure CT IO mode
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIoMode      CT IO mode
 ** \arg         CtIoMode0        CT IO mode 0
 ** \arg         CtIoMode1        CT IO mode 1
 ** \arg         CtIoMode2        CT IO mode 2
 ** \arg         CtIoMode3        CT IO mode 3
 ** \arg         CtIoMode4        CT IO mode 4
 ** \arg         CtIoMode5        CT IO mode 5
 ** \arg         CtIoMode6        CT IO mode 6
 ** \arg         CtIoMode7        CT IO mode 7
 ** \arg         CtIoMode8        CT IO mode 8
 **
 ** \retval Ok             CT IO mode has been set successfully
 ** \retval ErrorInvalidParameter If one of following cases match:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIoMode is invalid
 **
 ******************************************************************************/
en_result_t Ct_ConfigIOMode(uint8_t u8Idx, en_ct_io_mode_t enIoMode)
{
    /* Pointer to internal data */
    stc_ct_instance_data_t* pstcCtInstanceData;
     
    /* Check parameters */
    ASSERT(u8Idx < CtChannelMax);
    ASSERT(enIoMode <= CtIoMode8);
 
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    if((CtChannel0 == u8Idx) || (CtChannel1 == u8Idx))
    {
        M0P_CTIOSEL03->CTSEL0123_f.SEL01 = (uint8_t)enIoMode; 
    }
    else if((CtChannel2 == u8Idx) || (CtChannel3 == u8Idx))
    {
        M0P_CTIOSEL03->CTSEL0123_f.SEL23 = (uint8_t)enIoMode; 
    }
    else if((CtChannel4 == u8Idx) || (CtChannel5 == u8Idx))
    {
        M0P_CTIOSEL47->CTSEL4567_f.SEL45 = (uint8_t)enIoMode;
    }
    else if((CtChannel6 == u8Idx) || (CtChannel7 == u8Idx))
    {
        M0P_CTIOSEL47->CTSEL4567_f.SEL67 = (uint8_t)enIoMode;
    }else{
        ;
    }
    
    return Ok;
} /* Ct_ConfigIOMode */

/**
 ******************************************************************************
 ** \brief Set the Simultaneous Start register of Composite timer
 **
 ** This function is only valid in CTIO mode 5 and mode 6, otherwise don't 
 ** use this function!
 **
 ** \param [in]  u16Value      Bit0 ----- Ch.0
 **                            Bit1 ----- Ch.1
 **                                  ...
 **                            Bit7 ----- Ch.7
 **
 ** \retval None
 **
 ******************************************************************************/
void Ct_SetSimultaneousStart(uint8_t u8Value)
{
    M0P_SBSSR->CTSSSR = u8Value;
} /* Ct_SetSimultaneousStart */

/**
 ******************************************************************************
 ** \brief Initialize PWM function of CT
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  pstcPwmConfig    Pointer to PWM configuration
 **
 ** \retval Ok             PWM function has been configured successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - pstcPwmConfig == NULL
 **                             - config data is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwm_Init(uint8_t u8Idx, stc_ct_pwm_config_t* pstcPwmConfig)
{
    uint16_t u16Pres = 0;
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to instance data */

    /* Check parameters */
    ASSERT(NULL != pstcPwmConfig);
    ASSERT(u8Idx < CtChannelMax);
    ASSERT(pstcPwmConfig->enPres <= PwmPres1Div2048);
    ASSERT(pstcPwmConfig->enRestartEn <= PwmRestartEnable);
    ASSERT(pstcPwmConfig->enOutputMask <= PwmOutputMask);
    ASSERT(pstcPwmConfig->enOutputPolarity <= PwmPolarityHigh);
    ASSERT(pstcPwmConfig->enExtTrig <= PwmExtTrigBoth);
    ASSERT(pstcPwmConfig->enMode <= PwmOneshot);

    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    /* Reset Composite Timer mode */
    pstcCt->TCR_f.FUNC = CtResetMode;
    /* Set Composite Timer to PWM mode */
    pstcCt->TCR_f.FUNC = CtPwmMode;

    do
    {
        /* Clock prescaler setting */
        u16Pres = pstcPwmConfig->enPres;  /* Workaround for MISRA-C 2004 rule 12.7 */
        switch (pstcPwmConfig->enPres)
        {
            case PwmPresNone:
            case PwmPres1Div4:
            case PwmPres1Div16:
            case PwmPres1Div128:
            case PwmPres1Div256:
            case PwmPres1ExtClkRising:
            case PwmPres1ExtClkFalling:
            case PwmPres1ExtClkBoth: 
                pstcCt->TCR2_f.CLKS3 = 0u;
                pstcCt->TCR_f.CLKS = u16Pres;
                break;
            case PwmPres1Div512:
            case PwmPres1Div1024:
            case PwmPres1Div2048:
                pstcCt->TCR2_f.CLKS3 = 1u;
                pstcCt->TCR_f.CLKS = (u16Pres & 0x07u);
                break;
            default:   
                break;
        }
        /* Restart enable setting */
        switch (pstcPwmConfig->enRestartEn)
        {
            case PwmRestartDisable:
                pstcCt->TCR_f.RSTEN = 0u;
                break;
            case PwmRestartEnable:
                pstcCt->TCR_f.RSTEN = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        /* Output Mask setting */
        switch (pstcPwmConfig->enOutputMask)
        {
            case PwmOutputNormal:
                pstcCt->TCR_f.MASK = 0u;
                break;
            case PwmOutputMask:
                pstcCt->TCR_f.MASK = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        /* Output polarity setting */
        switch (pstcPwmConfig->enOutputPolarity)
        {
            case PwmPolarityLow:
                pstcCt->TCR_f.PLRT = 0u;
                break;
            case PwmPolarityHigh:
                pstcCt->TCR_f.PLRT = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        /* External trigger setting */
        switch (pstcPwmConfig->enExtTrig)
        {
            case PwmExtTrigDisable:
                pstcCt->TCR_f.EDGS =  0u;
                break;
            case PwmExtTrigRising:
                pstcCt->TCR_f.EDGS = 1u;
                break;
            case PwmExtTrigFalling:
                pstcCt->TCR_f.EDGS = 2u;
                break;
            case PwmExtTrigBoth:
                pstcCt->TCR_f.EDGS = 3u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        /* Mode setting */
        switch (pstcPwmConfig->enMode)
        {
            case PwmContinuous:
                pstcCt->TCR_f.MODS = 0u;
                break;
            case PwmOneshot:
                pstcCt->TCR_f.MODS = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }   
            
        /* Interrupt enable setting */
        if(NULL != pstcPwmConfig->pstcPwmIrqEn)
        {
            if(TRUE == pstcPwmConfig->pstcPwmIrqEn->bPwmTrigIrq)
            { 
                pstcCt->STA_f.TRGIE = 1u;
            }
            
            if(TRUE == pstcPwmConfig->pstcPwmIrqEn->bPwmDutyMatchIrq)
            {
                pstcCt->STA_f.DTMIE = 1u;
            }
            
            if(TRUE == pstcPwmConfig->pstcPwmIrqEn->bPwmUnderflowIrq)
            {
                pstcCt->STA_f.UDFIE = 1u;
            }
        }
        
        /* Set interrupt callback function */
        if(NULL != pstcPwmConfig->pstcPwmIrqCb)
        {
            pstcCtInstanceData->stcInternData.pfnBit2IrqCb = pstcPwmConfig->pstcPwmIrqCb->pfnPwmTrigIrqCb;
            pstcCtInstanceData->stcInternData.pfnBit1IrqCb = pstcPwmConfig->pstcPwmIrqCb->pfnPwmDutyMatchIrqCb;
            pstcCtInstanceData->stcInternData.pfnBit0IrqCb = pstcPwmConfig->pstcPwmIrqCb->pfnPwmUnderflowIrqCb;
        }
        
        /* NVIC setting */
        if(TRUE == pstcPwmConfig->bTouchNvic)
        {
            CtEnableNvic();
        }
    } while (0);
    
    return Ok;
} /* Ct_Pwm_Init */

/**
 ******************************************************************************
 ** \brief De-Initialize PWM function of CT
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  bTouchNvic    Touch NVIC or not
 **
 ** \retval Ok             PWM function has been de-initialized successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_DeInit(uint8_t u8Idx, boolean_t bTouchNvic)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR = 0x0000u;
    pstcCt->TCR2 = 0x0000u;
    pstcCt->CSR = 0x0000u;
    pstcCt->STA = 0x0000u;
    pstcCt->DUT = 0x0000u;

    /* Clear callback */
    pstcCtInstanceData->stcInternData.pfnBit0IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit1IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit2IrqCb = NULL;
    
    if(TRUE == bTouchNvic)
    {
        CtDisableNvic();        
    }
    
    return Ok;
} /* Ct_Pwm_DeInit */

/**
 ******************************************************************************
 ** \brief Enable PWM timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Enable PWM timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_EnableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    ((volatile M0P_CT_PWM_TypeDef*)pstcCt)->TCR_f.ENCNT = 1u;
    
    return Ok;
} /* Ct_Pwm_EnableCount */

/**
 ******************************************************************************
 ** \brief Disable PWM timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Disable PWM timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_DisableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->TCR_f.ENCNT = 0u;
    
    return Ok;
} /* Ct_Pwm_DisableCount */

/**
 ******************************************************************************
 ** \brief Start PWM timer by software
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Start PWM timer successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_EnableSwTrig(uint8_t u8Idx)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR_f.START = 1u;
    
    return Ok;
} /* Ct_Pwm_EnableSwTrig */

/**
 ******************************************************************************
 ** \brief Write Cycle value of PWM timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  u16Cycle       Cycle value
 **
 ** \retval Ok             Write cycle value successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_WriteCycleVal(uint8_t u8Idx, uint16_t u16Cycle)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);  
    pstcCt->CSR = u16Cycle;
    
    return Ok;
} /* Ct_Pwm_WriteCycleVal */

/**
 ******************************************************************************
 ** \brief Write duty value of PWM timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  u16Duty        Duty value
 **
 ** \retval Ok             Write duty value successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Pwm_WriteDutyVal(uint8_t u8Idx, uint16_t u16Duty)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->DUT = u16Duty;
    
    return Ok;
} /* Ct_Pwm_WriteDutyVal */

/**
 ******************************************************************************
 ** \brief Read current count value of PWM timer 
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Current count value
 **
 ******************************************************************************/
uint16_t Ct_Pwm_ReadCurCnt(uint8_t u8Idx)
{ 
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return 0 ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    return pstcCt->TCNT;
} /* Ct_Pwm_ReadCurCnt */

/**
 ******************************************************************************
 ** \brief Enable PWM timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWM timer interrupt type  
 ** \arg         PwmTrigIrq           PWM trigger detection interrupt
 ** \arg         PwmDutyMatchIrq  PWM duty match interrupt 
 ** \arg         PwmUnderflowIrq   PWM underflow interrupt   
 **
 ** \retval Ok             Enable PWM timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwm_EnableIrq(uint8_t u8Idx, en_pwm_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwmUnderflowIrq); 
    
    /* Get pointer to internal data structure */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    
    switch (enIrqSel)
    {
        case PwmTrigIrq:
            pstcCt->STA_f.TRGIE = 1u;
            break;
        case PwmDutyMatchIrq:
            pstcCt->STA_f.DTMIE = 1u;
            break;
        case PwmUnderflowIrq:
            pstcCt->STA_f.UDFIE = 1u;
            break;
        default:
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Pwm_EnableIrq */

/**
 ******************************************************************************
 ** \brief Disable PWM timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWM timer interrupt type    
 ** \arg         PwmTrigIrq            PWM trigger detection interrupt
 ** \arg         PwmDutyMatchIrq  PWM duty match interrupt 
 ** \arg         PwmUnderflowIrq   PWM underflow interrupt   
 **
 ** \retval Ok             Disable PWM timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwm_DisableIrq(uint8_t u8Idx, en_pwm_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwmUnderflowIrq); 

    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    
    switch (enIrqSel)
    {
        case PwmTrigIrq:
            pstcCt->STA_f.TRGIE = 0u;
            break;
        case PwmDutyMatchIrq:
            pstcCt->STA_f.DTMIE = 0u;
            break;
        case PwmUnderflowIrq:
            pstcCt->STA_f.UDFIE = 0u;
            break;
        default:
            return ErrorInvalidParameter ;
    }

    return Ok;
} /* Ct_Pwm_DisableIrq */

/**
 ******************************************************************************
 ** \brief Get interrupt flag of PWM timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWM timer interrupt type
 ** \arg         PwmTrigIrq            PWM trigger detection interrupt
 ** \arg         PwmDutyMatchIrq  PWM duty match interrupt 
 ** \arg         PwmUnderflowIrq   PWM underflow interrupt   
 **
 ** \retval     boolean_t    the interrupt status
 ******************************************************************************/
boolean_t Ct_Pwm_GetIrqFlag(uint8_t u8Idx, en_pwm_irq_sel_t enIrqSel)
{
    boolean_t bFlag; 
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwmUnderflowIrq);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return FALSE ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case PwmTrigIrq:
            bFlag = pstcCt->STA_f.TRGIR ? TRUE : FALSE;
            break;
        case PwmDutyMatchIrq:
            bFlag = pstcCt->STA_f.DTMIR ? TRUE : FALSE;
            break;
        case PwmUnderflowIrq:
            bFlag = pstcCt->STA_f.UDFIR ? TRUE : FALSE;
            break;
        default:
            break;
    }
    
    return bFlag;
} /* Ct_Pwm_GetIrqFlag */

/**
 ******************************************************************************
 ** \brief Clear interrupt flag of PWM timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWM timer interrupt type
 ** \arg         PwmTrigIrq           PWM trigger detection interrupt
 ** \arg         PwmDutyMatchIrq  PWM duty match interrupt 
 ** \arg         PwmUnderflowIrq   PWM underflow interrupt   
 **
 ** \retval Ok             Clear interrupt flag successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwm_ClrIrqFlag(uint8_t u8Idx, en_pwm_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWM_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwmUnderflowIrq);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWM_TypeDef*)(pstcCtInstanceData->pstcInstance);
  
    switch (enIrqSel)
    {
        case PwmTrigIrq:
            pstcCt->STA_f.TRGIR = 0u;
            break;
        case PwmDutyMatchIrq:
            pstcCt->STA_f.DTMIR = 0u;
            break;
        case PwmUnderflowIrq:
            pstcCt->STA_f.UDFIR = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return Ok;
} /* Ct_Pwm_ClrIrqFlag */

/**
 ******************************************************************************
 ** \brief Initialize PPG function of CT
 **
 ** \param [in]  u8Idx                Channel index
 ** \param [in]  pstcPpgConfig    Pointer to PPG configuration
 **
 ** \retval Ok             PPG function has been configured successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - pstcPpgConfig == NULL
 **                             - config data is invalid
 **
 ******************************************************************************/
en_result_t Ct_Ppg_Init(uint8_t u8Idx, stc_ct_ppg_config_t* pstcPpgConfig)
{
    uint16_t u16Pres;
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */

    /* Check parameters */
    ASSERT(NULL != pstcPpgConfig);
    ASSERT(u8Idx < CtChannelMax);
    ASSERT(pstcPpgConfig->enPres <= PpgPres1Div2048);
    ASSERT(pstcPpgConfig->enRestartEn <= PpgRestartEnable);
    ASSERT(pstcPpgConfig->enOutputMask <= PpgOutputMask);
    ASSERT(pstcPpgConfig->enOutputPolarity <= PpgPolarityHigh);
    ASSERT(pstcPpgConfig->enExtTrig <= PpgExtTrigBoth);
    ASSERT(pstcPpgConfig->enMode <= PpgOneshot);
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    /* Reset Composite Timer mode */
    pstcCt->TCR_f.FUNC = CtResetMode;
    /* Set Composite Timer to PPG mode */
    pstcCt->TCR_f.FUNC = CtPpgMode;

    do
    {
        /* Clock prescaler setting */
        u16Pres = pstcPpgConfig->enPres; /* Workaround for MISRA-C 2004 rule 12.7 */
        switch (pstcPpgConfig->enPres)
        {
            case PpgPresNone:
            case PpgPres1Div4:
            case PpgPres1Div16:
            case PpgPres1Div128:
            case PpgPres1Div256:
            case PpgPres1ExtClkRising:
            case PpgPres1ExtClkFalling:
            case PpgPres1ExtClkBoth:
                pstcCt->TCR2_f.CLKS3 = 0u;
                pstcCt->TCR_f.CLKS = u16Pres;
                break;  
            case PpgPres1Div512:
            case PpgPres1Div1024:
            case PpgPres1Div2048:
                pstcCt->TCR2_f.CLKS3 = 1u;
                pstcCt->TCR_f.CLKS = (u16Pres & 0x7u);
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Restart enable setting */
        switch (pstcPpgConfig->enRestartEn)
        {
            case PpgRestartDisable:
                pstcCt->TCR_f.RSTEN = 0u;
                break;
            case PpgRestartEnable:
                pstcCt->TCR_f.RSTEN = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Output Mask setting */
        pstcCt->TCR_f.MASK = (uint8_t)pstcPpgConfig->enOutputMask;
        switch (pstcPpgConfig->enOutputMask)
        {
            case PpgOutputNormal:
                pstcCt->TCR_f.MASK = 0u;
                break;
            case PpgOutputMask:
                pstcCt->TCR_f.MASK = 1u;
                break;
            default:   
                return ErrorInvalidParameter ;
        }       
        /* Output polarity setting */
        switch (pstcPpgConfig->enOutputPolarity)
        {
            case PpgPolarityLow:
                pstcCt->TCR_f.PLRT = 0u;
                break;
            case PpgPolarityHigh:
                pstcCt->TCR_f.PLRT = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* External trigger setting  */   
        switch (pstcPpgConfig->enExtTrig)
        {
            case PpgExtTrigDisable:
                pstcCt->TCR_f.EDGS = 0u;
                break;
            case PpgExtTrigRising:
                pstcCt->TCR_f.EDGS = 1u;
                break;
            case PpgExtTrigFalling:
                pstcCt->TCR_f.EDGS = 2u;
                break;
            case PpgExtTrigBoth:
                pstcCt->TCR_f.EDGS = 3u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Mode setting */
        switch (pstcPpgConfig->enMode)
        {
            case PpgContinuous:
                pstcCt->TCR_f.MODS = 0u;
                break;  
            case PpgOneshot:
                pstcCt->TCR_f.MODS = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }

        /* Interrupt enable setting */
        if (NULL != pstcPpgConfig->pstcPpgIrqEn)
        {
            if(pstcPpgConfig->pstcPpgIrqEn->bPpgTrigIrq == TRUE)
            {
                pstcCt->STA_f.TRGIE = 1;   
            } 
            if(pstcPpgConfig->pstcPpgIrqEn->bPpgUnderflowIrq == TRUE)
            {
                pstcCt->STA_f.UDFIE = 1;   
            }
        }

        /* Interrupt callback functions */
        if (NULL != pstcPpgConfig->pstcPpgIrqCb)
        {
            pstcCtInstanceData->stcInternData.pfnBit2IrqCb = pstcPpgConfig->pstcPpgIrqCb->pfnPpgTrigIrqCb;
            pstcCtInstanceData->stcInternData.pfnBit0IrqCb = pstcPpgConfig->pstcPpgIrqCb->pfnPpgUnderflowIrqCb;
        }
                
        /* NVIC setting */
        if(pstcPpgConfig->bTouchNvic == TRUE)
        {
            CtEnableNvic();
        }
    } while (0);
    
    return Ok;
} /* Ct_Ppg_Init */

/**
 ******************************************************************************
 ** \brief De-Initialize PPG function of CT
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  bTouchNvic    Touch NVIC or not
 **
 ** \retval Ok             PPG function has been de-initialized successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/                    
en_result_t Ct_Ppg_DeInit(uint8_t u8Idx, boolean_t bTouchNvic)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR = 0x0000u;
    pstcCt->TCR2 = 0x0000u;
    pstcCt->STA = 0x0000u;
    pstcCt->LWRR = 0x0000u;
    pstcCt->HWRR = 0x0000u;
    
    /* Clear callback */
    pstcCtInstanceData->stcInternData.pfnBit0IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit1IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit2IrqCb = NULL;
    
    if(TRUE == bTouchNvic)
    {
        CtDisableNvic();                
    }
        
    return Ok;
} /* Ct_Ppg_DeInit */

/**
 ******************************************************************************
 ** \brief Enable PPG timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Enable PPG timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Ppg_EnableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR_f.ENCNT = 1u;
    
    return Ok;
} /* Ct_Ppg_EnableCount */

/**
 ******************************************************************************
 ** \brief Disable PPG timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Disable PPG timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Ppg_DisableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR_f.ENCNT = 0u;
    
    return Ok;
} /* Ct_Ppg_DisableCount */

/**
 ******************************************************************************
 ** \brief Start PPG timer by software
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Start PPG timer successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Ppg_EnableSwTrig(uint8_t u8Idx)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR_f.START = 1u;
    
    return Ok;
} /* Ct_Ppg_EnableSwTrig */

/**
 ******************************************************************************
 ** \brief Write low width count value of PPG timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  u16Val           Low width count value
 **
 ** \retval Ok             Write low width count value successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Ppg_WriteLowWidthVal(uint8_t u8Idx, uint16_t u16Val)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->LWRR = u16Val;
    
    return Ok;
} /* Ct_Ppg_WriteLowWidthVal */

/**
 ******************************************************************************
 ** \brief Write high width count value of PPG timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  u16Val           High width count value
 **
 ** \retval Ok             Write high width count value successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Ppg_WriteHighWidthVal(uint8_t u8Idx, uint16_t u16Val)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->HWRR = u16Val;
    
    return Ok;
} /* Ct_Ppg_WriteHighWidthVal */

/**
 ******************************************************************************
 ** \brief Read current count value of PPG timer 
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Current count value
 ******************************************************************************/
uint16_t Ct_Ppg_ReadCurCnt(uint8_t u8Idx)
{ 
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return 0 ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    return pstcCt->TCNT;
} /* Ct_Ppg_ReadCurCnt */

/**
 ******************************************************************************
 ** \brief Enable PPG timer interrupt
 **
 ** \param [in]  u8Idx              Channel index
 ** \param [in]  enIrqSel          PPG timer interrupt type 
 ** \arg         PpgTrigIrq           PPG trigger detection interrupt
 ** \arg         PpgUnderflowIrq  PPG underflow interrupt
 **
 ** \retval Ok             Enable PPG timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Ppg_EnableIrq(uint8_t u8Idx, en_ppg_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PpgUnderflowIrq);  
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case PpgTrigIrq:
            pstcCt->STA_f.TRGIE = 1u;
            break;
        case PpgUnderflowIrq:
            pstcCt->STA_f.UDFIE = 1u;
            break;
        default:
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Ppg_EnableIrq */

/**
 ******************************************************************************
 ** \brief Disable PPG timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PPG timer interrupt type 
 ** \arg         PpgTrigIrq           PPG trigger detection interrupt
 ** \arg         PpgUnderflowIrq  PPG underflow interrupt
 **
 ** \retval Ok             Disable PPG timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Ppg_DisableIrq(uint8_t u8Idx, en_ppg_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PpgUnderflowIrq); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case PpgTrigIrq:
            pstcCt->STA_f.TRGIE = 0u;
            break;
        case PpgUnderflowIrq:
            pstcCt->STA_f.UDFIE = 0u;
            break;
        default:
            return ErrorInvalidParameter ;
    }
     
    return Ok;
} /* Ct_Ppg_DisableIrq */

/**
 ******************************************************************************
 ** \brief Get interrupt flag of PPG timer 
 **
 ** \param [in]  u8Idx              Channel index
 ** \param [in]  enIrqSel          PPG timer interrupt type
 ** \arg         PpgTrigIrq           PPG trigger detection interrupt
 ** \arg         PpgUnderflowIrq  PPG underflow interrupt
 **
 ** \retval     boolean_t    the interrupt status
 **
 ******************************************************************************/
boolean_t Ct_Ppg_GetIrqFlag(uint8_t u8Idx, en_ppg_irq_sel_t enIrqSel)
{
    boolean_t bFlag; 
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PpgUnderflowIrq);  
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return FALSE ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case PpgTrigIrq:
            bFlag = pstcCt->STA_f.TRGIR ? TRUE : FALSE;
            break;
        case PpgUnderflowIrq:
            bFlag = pstcCt->STA_f.UDFIR ? TRUE : FALSE;
            break;
        default:
            break;
    }
    
    return bFlag;
} /* Ct_Ppg_GetIrqFlag */

/**
 ******************************************************************************
 ** \brief Clear interrupt flag of PPG timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PPG timer interrupt type
 ** \arg         PpgTrigIrq           PPG trigger detection interrupt
 ** \arg         PpgUnderflowIrq  PPG underflow interrupt
 **
 ** \retval Ok             Clear interrupt flag successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Ppg_ClrIrqFlag(uint8_t u8Idx, en_ppg_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PPG_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL;/* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PpgUnderflowIrq); 
    
    /* Get pointer to internal data structure ...  */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PPG_TypeDef*)(pstcCtInstanceData->pstcInstance);
  
    switch (enIrqSel)
    {
        case PpgTrigIrq:
            pstcCt->STA_f.TRGIR = 0u;
            break;
        case PpgUnderflowIrq:
            pstcCt->STA_f.UDFIR = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return Ok;
} /* Ct_Ppg_ClrIrqFlag */

/**
 ******************************************************************************
 ** \brief Initialize RT function of CT
 **
 ** \param [in]  u8Idx               Channel index
 ** \param [in]  pstcRtConfig     Pointer to RT configuration
 **
 ** \retval Ok             RT function has been configured successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - pstcRtConfig == NULL
 **                             - Configuration data is invalid
 **
 ******************************************************************************/
en_result_t Ct_Rt_Init(uint8_t u8Idx, stc_ct_rt_config_t* pstcRtConfig)
{
    uint16_t u16Pres, u16ExtTrig;
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check parameters */
    ASSERT(NULL != pstcRtConfig);
    ASSERT(u8Idx < CtChannelMax);
    ASSERT(pstcRtConfig->enPres <= RtPres1Div2048);
    ASSERT(pstcRtConfig->enSize <= RtSize32Bit);
    ASSERT(pstcRtConfig->enOutputPolarity <= RtPolarityHigh);
    ASSERT(pstcRtConfig->enExtTrig <= RtExtTiggerHighLevel);
    ASSERT(pstcRtConfig->enMode <= RtOneshot);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    /* Reset Composite Timer mode */
    pstcCt->TCR_f.FUNC = CtResetMode;
    /* Set Composite Timer to Reload Timer mode */
    pstcCt->TCR_f.FUNC = CtRtMode;

    do
    {
        /* Clock prescaler setting */
        u16Pres = pstcRtConfig->enPres; /* Workaround for MISRA-C 2004 rule 12.7 */
        switch (pstcRtConfig->enPres)
        {
            case RtPresNone:
            case RtPres1Div4:
            case RtPres1Div16:
            case RtPres1Div128:
            case RtPres1Div256:
            case RtPres1ExtClkRising:
            case RtPres1ExtClkFalling:
            case RtPres1ExtClkBoth:
                pstcCt->TCR2_f.CLKS3 = 0u;
                pstcCt->TCR_f.CLKS = u16Pres;
                break;  
            case RtPres1Div512:
            case RtPres1Div1024:
            case RtPres1Div2048:
                pstcCt->TCR2_f.CLKS3 = 1u;
                pstcCt->TCR_f.CLKS = (u16Pres & 0x7u);
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Timer size setting */
        switch (pstcRtConfig->enSize)
        {
            case RtSize16Bit:
                pstcCt->TCR_f.T32 = 0u;
                break;
            case RtSize32Bit:
                pstcCt->TCR_f.T32 = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Output polarity setting */
        switch (pstcRtConfig->enOutputPolarity)
        {
            case RtPolarityLow:
                pstcCt->TCR_f.PLRT = 0u;
                break;
            case RtPolarityHigh:
                pstcCt->TCR_f.PLRT = 1u;
                break;
            default:
                return ErrorInvalidParameter ;  
        }
        
        /* External trigger setting */
        u16ExtTrig = pstcRtConfig->enExtTrig; /* Workaround for MISRA-C 2004 rule 12.7 */
        switch (pstcRtConfig->enExtTrig)
        {
            case RtExtTiggerDisable:
            case RtExtTiggerRisingEdge:
            case RtExtTiggerFallingEdge:
            case RtExtTiggerBothEdge:
                pstcCt->TCR2_f.GTIE = 0u;        
                pstcCt->TCR_f.EDGS = u16ExtTrig;
                break;
            case RtExtTiggerLowLevel:
                pstcCt->TCR2_f.GTIE = 1u;        
                pstcCt->TCR_f.EDGS = 0u;
                break;
            case RtExtTiggerHighLevel:
                pstcCt->TCR2_f.GTIE = 1u;
                pstcCt->TCR_f.EDGS = 1u; 
                break;
            default:
                return ErrorInvalidParameter;
        }
       
        /* Mode setting */
        switch (pstcRtConfig->enMode)
        {
            case RtReload:
                pstcCt->TCR_f.MODS = 0u;
                break;
            case RtOneshot:
                pstcCt->TCR_f.MODS = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        
        /* Interrupt enable setting */
        if(NULL != pstcRtConfig->pstcRtIrqEn)
        {
            if(pstcRtConfig->pstcRtIrqEn->bRtTrigIrq == TRUE)
            {
                pstcCt->STA_f.TRGIE = 1u;
            }
            
            if(pstcRtConfig->pstcRtIrqEn->bRtUnderflowIrq == TRUE)
            {
                pstcCt->STA_f.UDFIE = 1u;
            }
        }
        /* Interrupt callback functions setting */
        if(NULL != pstcRtConfig->pstcRtIrqCb)
        {
            pstcCtInstanceData->stcInternData.pfnBit2IrqCb = pstcRtConfig->pstcRtIrqCb->pfnRtTrigIrqCb;
            pstcCtInstanceData->stcInternData.pfnBit0IrqCb = pstcRtConfig->pstcRtIrqCb->pfnRtUnderflowIrqCb;
        }
                
        /* NVIC setting */
        if(TRUE == pstcRtConfig->bTouchNvic)
        {
            CtEnableNvic();
        }
    } while (0);
    
    return Ok;
} /* Ct_Rt_Init */

/**
 ******************************************************************************
 ** \brief De-Initialize RT function of CT
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  bTouchNvic    Touch NVIC or not
 **
 ** \retval Ok             RT function has been de-initialized successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/                    
en_result_t Ct_Rt_DeInit(uint8_t u8Idx, boolean_t bTouchNvic)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR = 0x0000u;
    pstcCt->TCR2 = 0x0000u;
    pstcCt->STA = 0x0000u;
    pstcCt->CSR = 0x0000u;
    
    /* Clear callback */
    pstcCtInstanceData->stcInternData.pfnBit0IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit1IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit2IrqCb = NULL;
    
    if(TRUE == bTouchNvic)
    {
        CtDisableNvic();              
    }
        
    return Ok;
} /* Ct_Rt_DeInit */
        
/**
 ******************************************************************************
 ** \brief Enable Reload timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Enable RT timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Rt_EnableCount(uint8_t u8Idx)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR_f.ENCNT = 1u;
    
    return Ok;
} /* Ct_Rt_EnableCount */

/**
 ******************************************************************************
 ** \brief Disable Reload timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Disable RT timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Rt_DisableCount(uint8_t u8Idx)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->TCR_f.ENCNT = 0u;
    
    return Ok;
} /* Ct_Rt_DisableCount */

/**
 ******************************************************************************
 ** \brief Start Reload timer by software
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Start Reload timer successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Rt_EnableSwTrig(uint8_t u8Idx)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->TCR_f.START = 1u;
    
    return Ok;
} /* Ct_Rt_EnableSwTrig */

/**
 ******************************************************************************
 ** \brief Write count cycle of Reload timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  u16Val           Cycle value
 **
 ** \retval Ok             Write count cycle successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **
 ******************************************************************************/
en_result_t Ct_Rt_WriteCycleVal(uint8_t u8Idx, uint16_t u16Val)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->CSR = u16Val;
    
    return Ok;
} /* Ct_Rt_WriteCycleVal */

/**
 ******************************************************************************
 ** \brief Read current count value of Reload timer 
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Current count value
 ******************************************************************************/
uint16_t Ct_Rt_ReadCurCnt(uint8_t u8Idx)
{ 
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    return pstcCt->TCNT;
} /* Ct_Rt_ReadCurCnt */

/**
 ******************************************************************************
 ** \brief Enable Reload timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        Reload Timer interrupt type
 ** \arg         RtTrigIrq           Reload timer trigger detection flag
 ** \arg         RtUnderflowIrq  Reload timer underflow interrupt flag
 **
 ** \retval Ok             Enable Reload timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Rt_EnableIrq(uint8_t u8Idx, en_rt_irq_sel_t enIrqSel)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= RtUnderflowIrq);   
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);

    switch (enIrqSel)
    {
        case RtTrigIrq:
            pstcCt->STA_f.TRGIE = 1u;
            break;
        case RtUnderflowIrq:
            pstcCt->STA_f.UDFIE = 1u;
            break;
        default:
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Rt_EnableIrq */

/**
 ******************************************************************************
 ** \brief Disable Reload timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        Reload Timer interrupt type
 ** \arg         RtTrigIrq           Reload timer trigger detection flag
 ** \arg         RtUnderflowIrq  Reload timer underflow interrupt flag
 **
 ** \retval Ok             Disable Reload timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Rt_DisableIrq(uint8_t u8Idx, en_rt_irq_sel_t enIrqSel)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= RtUnderflowIrq); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case RtTrigIrq:
            pstcCt->STA_f.TRGIE = 0u;
            break;
        case RtUnderflowIrq:
            pstcCt->STA_f.UDFIE = 0u;
            break;
        default:
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Rt_DisableIrq */

/**
 ******************************************************************************
 ** \brief Get interrupt flag of Reload timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        Reload timer interrupt type
 ** \arg         RtTrigIrq           Reload timer trigger detection flag
 ** \arg         RtUnderflowIrq  Reload timer underflow interrupt flag
 **
 ** \retval      boolean_t         the interrupt status
 ******************************************************************************/
boolean_t Ct_Rt_GetIrqFlag(uint8_t u8Idx, en_rt_irq_sel_t enIrqSel)
{
    boolean_t bFlag; 
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= RtUnderflowIrq);    
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return FALSE ;
    }
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case RtTrigIrq:
            bFlag = pstcCt->STA_f.TRGIR ? TRUE : FALSE;
            break;
        case RtUnderflowIrq:
            bFlag = pstcCt->STA_f.UDFIR ? TRUE : FALSE;
            break;
        default:
            break;
    }
    
    return bFlag;
} /* Ct_Rt_GetIrqFlag */

/**
 ******************************************************************************
 ** \brief Clear interrupt flag of Reload timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        Reload timer interrupt type
 ** \arg         RtTrigIrq           Reload timer trigger detection flag
 ** \arg         RtUnderflowIrq  Reload timer underflow interrupt flag
 **
 ** \retval Ok             Clear interrupt flag successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Rt_ClrIrqFlag(uint8_t u8Idx, en_rt_irq_sel_t enIrqSel)
{
    volatile M0P_CT_RT_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data  */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= RtUnderflowIrq);   
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    pstcCt = (volatile M0P_CT_RT_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case RtTrigIrq:
            pstcCt->STA_f.TRGIR = 0u;
            break;
        case RtUnderflowIrq:
            pstcCt->STA_f.UDFIR = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return Ok;
} /* Ct_Rt_ClrIrqFlag */

/**
 ******************************************************************************
 ** \brief Initialize PWC function of CT
 **
 ** \param [in]  u8Idx                Channel index
 ** \param [in]  pstcPwcConfig    Pointer to PWC configuration
 **
 ** \retval Ok             PWC function has been configured successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - pstcPwcConfig == NULL
 **                             - Configuration data is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwc_Init(uint8_t u8Idx, stc_ct_pwc_config_t* pstcPwcConfig)
{
    uint16_t u16Pres;
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check parameters */
    ASSERT(NULL != pstcPwcConfig);
    ASSERT(u8Idx < CtChannelMax);
    ASSERT(pstcPwcConfig->enPres <= PwcPres1Div2048);
    ASSERT(pstcPwcConfig->enSize <= PwcSize32Bit);
    ASSERT(pstcPwcConfig->enMeasureEdge <= PwcMeasureFallingToRising);
    ASSERT(pstcPwcConfig->enMode <= PwcOneshot); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    /* Reset Composite Timer mode */
    pstcCt->TCR_f.FUNC = CtResetMode;
    /* Set Composite Timer to Reload Timer mode */
    pstcCt->TCR_f.FUNC = CtPwcMode;

    do
    {
        /* Clock prescaler setting */
        u16Pres = pstcPwcConfig->enPres; /* workaround for MISRA-C 2004 rule 12.7 */
        switch (pstcPwcConfig->enPres)
        {
            case PwcPresNone:
            case PwcPres1Div4:
            case PwcPres1Div16:
            case PwcPres1Div128:
            case PwcPres1Div256:
                pstcCt->TCR2_f.CLKS3 = 0u;
                pstcCt->TCR_f.CLKS = u16Pres;
                break;
            case PwcPres1Div512:
            case PwcPres1Div1024:
            case PwcPres1Div2048:
                pstcCt->TCR2_f.CLKS3 = 1u;
                pstcCt->TCR_f.CLKS = (u16Pres & 0x07u);
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Timer size setting */
        switch (pstcPwcConfig->enSize)
        {
            case PwcSize16Bit:
                pstcCt->TCR_f.T32 = 0u;
                break;
            case PwcSize32Bit:
                pstcCt->TCR_f.T32 = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Measurement mode setting */
        switch (pstcPwcConfig->enMeasureEdge)
        {
            case PwcMeasureRisingToFalling:
                pstcCt->TCR_f.EDGS  = 0u;
                break;  
            case PwcMeasureRisingToRising:
                pstcCt->TCR_f.EDGS  = 1u;
                break;
            case PwcMeasureFallingToFalling:
                pstcCt->TCR_f.EDGS  = 2u;
                break;
            case PwcMeasureEitherToEither:
                pstcCt->TCR_f.EDGS  = 3u;
                break;
            case PwcMeasureFallingToRising:
                pstcCt->TCR_f.EDGS  = 4u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        /* Mode setting */
        switch (pstcPwcConfig->enMode)
        {
            case PwcContinuous:
                pstcCt->TCR_f.MODS = 0u;
                break;
            case PwcOneshot:
                pstcCt->TCR_f.MODS = 1u;
                break;
            default:
                return ErrorInvalidParameter ;
        }
        
        /* Interrupt enable setting */
        if(NULL != pstcPwcConfig->pstcPwcIrqEn)
        {
            if(pstcPwcConfig->pstcPwcIrqEn->bPwcMeasureCompleteIrq == TRUE)
            {
                pstcCt->STA_f.MCIE = 1u;
            }
            
            if(pstcPwcConfig->pstcPwcIrqEn->bPwcMeasureOverflowIrq == TRUE)
            {
                pstcCt->STA_f.OVIE = 1u;
            }
        }
        
        /* Interrupt callback functions */
        if (NULL != pstcPwcConfig->pstcPwcIrqCb)
        {
            pstcCtInstanceData->stcInternData.pfnBit2IrqCb = pstcPwcConfig->pstcPwcIrqCb->pfnPwcMeasureCompleteIrqCb;
            pstcCtInstanceData->stcInternData.pfnBit0IrqCb = pstcPwcConfig->pstcPwcIrqCb->pfnPwcMeasureOverflowIrqCb;
        }
              
        /* NVIC setting */
        if(pstcPwcConfig->bTouchNvic == TRUE)
        {
            CtEnableNvic();
        }
    } while (0);
    
    return Ok;
} /* Ct_Pwc_Init */

/**
 ******************************************************************************
 ** \brief De-Initialize PWC function of CT
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  bTouchNvic    Touch NVIC or not
 **
 ** \retval Ok             PWC function has been de-initialized successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/                    
en_result_t Ct_Pwc_DeInit(uint8_t u8Idx, boolean_t bTouchNvic)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    pstcCt->TCR = 0x0000u;
    pstcCt->TCR2 = 0x0000u;
    pstcCt->STA = 0x0000u;
    
    /* Clear callback */
    pstcCtInstanceData->stcInternData.pfnBit0IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit1IrqCb = NULL;
    pstcCtInstanceData->stcInternData.pfnBit2IrqCb = NULL;
    
    if(TRUE == bTouchNvic)
    {
        CtDisableNvic();         
    }
    
    return Ok;
} /* Ct_Pwc_DeInit */

/**
 ******************************************************************************
 ** \brief Enable PWC timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Enable PWC timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Pwc_EnableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->TCR_f.ENCNT = 1u;
    
    return Ok;
} /* Ct_Pwc_EnableCount */

/**
 ******************************************************************************
 ** \brief Disable PWC timer counting
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Ok             Disable PWC timer counting successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             
 ******************************************************************************/
en_result_t Ct_Pwc_DisableCount(uint8_t u8Idx)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    pstcCt->TCR_f.ENCNT = 0u;
    
    return Ok;
} /* Ct_Pwc_DisableCount */

/**
 ******************************************************************************
 ** \brief Get 16 bits measure data of PWC timer
 **
 ** This function reads measure data in 16-bit timer mode.
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Measure data       
 ******************************************************************************/
uint16_t Ct_Pwc_Get16BitMeasureData(uint8_t u8Idx)
{ 
    uint16_t u16RegDtbf;
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return 0 ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    u16RegDtbf = pstcCt->DBUF;
    
    return u16RegDtbf;
} /* Ct_Pwc_Get16BitMeasureData */

/**
 ******************************************************************************
 ** \brief Get 32 bits measure data of PWC timer
 **
 ** This function reads measure data in 32-bit timer mode, the input CT instance
 ** should point to register base address of even channel. 
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval Measure data 
 ******************************************************************************/
uint32_t Ct_Pwc_Get32BitMeasureData(uint8_t u8Idx)
{ 
    uint16_t u16RegLow, u16RegHigh;
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */
    
    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT((CtChannel0 == u8Idx) || (CtChannel2 == u8Idx) \
        || (CtChannel4 == u8Idx)||(CtChannel6 == u8Idx)); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return 0ul ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    u16RegLow = pstcCt->DBUF;
    u16RegHigh = ((volatile M0P_CT_PWC_TypeDef*)((volatile uint8_t*)pstcCt + 0x40u))->DBUF;
    return (((uint32_t)u16RegHigh<<16) | (uint32_t)u16RegLow);
} /* Ct_Pwc_Get32BitMeasureData */

/**
 ******************************************************************************
 ** \brief Enable PWC timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWC timer interrupt type
 ** \arg         PwcMeasureCompleteIrq   PWC measure complete interrupt 
 ** \arg         PwcMeasureOverflowIrq   PWC overflow interrupt
 **
 ** \retval Ok             Enable PWC timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwc_EnableIrq(uint8_t u8Idx, en_pwc_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwcMeasureOverflowIrq); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance); 

    switch (enIrqSel)
    {
        case PwcMeasureCompleteIrq:
            pstcCt->STA_f.MCIE = 1u;
            break;
        case PwcMeasureOverflowIrq:
            pstcCt->STA_f.OVIE = 1u;
            break;
        default:    
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Pwc_EnableIrq */

/**
 ******************************************************************************
 ** \brief Disable PWC timer interrupt
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWC timer interrupt type
 ** \arg         PwcMeasureCompleteIrq   PWC measure complete interrupt 
 ** \arg         PwcMeasureOverflowIrq   PWC overflow interrupt
 **
 ** \retval Ok             Disable PWC timer interrupt successfully
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwc_DisableIrq(uint8_t u8Idx, en_pwc_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwcMeasureOverflowIrq); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance); 
    
    switch (enIrqSel)
    {
        case PwcMeasureCompleteIrq:
            pstcCt->STA_f.MCIE = 0u;
            break;
        case PwcMeasureOverflowIrq:
            pstcCt->STA_f.OVIE = 0u;
            break;
        default:    
            return ErrorInvalidParameter ;
    }
    
    return Ok;
} /* Ct_Pwc_DisableIrq */

/**
 ******************************************************************************
 ** \brief Get interrupt flag of PWC timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWC timer interrupt type
 ** \arg         PwcMeasureCompleteIrq   PWC measure complete interrupt 
 ** \arg         PwcMeasureOverflowIrq    PWC overflow interrupt
 **
 ** \retval      boolean_t         the interrupt status
 **
 ******************************************************************************/
boolean_t Ct_Pwc_GetIrqFlag(uint8_t u8Idx, en_pwc_irq_sel_t enIrqSel)
{
    boolean_t bFlag; 
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwcMeasureOverflowIrq);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    
    switch (enIrqSel)
    {
        case PwcMeasureCompleteIrq:
            bFlag = pstcCt->STA_f.MCIR ? TRUE : FALSE;
            break;
        case PwcMeasureOverflowIrq:
            bFlag = pstcCt->STA_f.OVIR ? TRUE : FALSE;
            break;
        default:
            break;
    }
    
    return bFlag;
} /* Ct_Pwc_GetIrqFlag */

/**
 ******************************************************************************
 ** \brief Clear interrupt flag of PWC timer 
 **
 ** \param [in]  u8Idx            Channel index
 ** \param [in]  enIrqSel        PWC timer interrupt type
 ** \arg         PwcMeasureCompleteIrq   PWC measure complete interrupt 
 ** \arg         PwcMeasureOverflowIrq    PWC overflow interrupt
 **
 ** \retval Ok              Clear interrupt flag successfully
  ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - u8Idx is invalid
 **                             - Pointer to instance data is NULL
 **                             - enIrqSel is invalid
 **
 ******************************************************************************/
en_result_t Ct_Pwc_ClrIrqFlag(uint8_t u8Idx, en_pwc_irq_sel_t enIrqSel)
{
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    ASSERT(enIrqSel <= PwcMeasureOverflowIrq);  
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return ErrorInvalidParameter ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
  
    switch (enIrqSel)
    {
        case PwcMeasureCompleteIrq:
            break;
        case PwcMeasureOverflowIrq:
            pstcCt->STA_f.OVIR = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return Ok;
} /* Ct_Pwc_ClrIrqFlag */

/**
 ******************************************************************************
 ** \brief Get error flag of PWC timer
 **
 ** If the measured data is not read out when the next data is coming,
 ** the error flag will be set.
 **
 ** \param [in]  u8Idx            Channel index
 **
 ** \retval         boolean_t       the error flag status
 ******************************************************************************/
boolean_t Ct_Pwc_GetErrorFlag(uint8_t u8Idx)
{
    boolean_t bFlag; 
    volatile M0P_CT_PWC_TypeDef* pstcCt = NULL;
    stc_ct_instance_data_t* pstcCtInstanceData = NULL; /* Pointer to internal data */

    /* Check for CT channel */
    ASSERT(u8Idx < CtChannelMax); 
    
    /* Get pointer to internal data structure ... */
    pstcCtInstanceData = CtGetInstanceDataPtr( u8Idx ) ;
    if(NULL == pstcCtInstanceData)
    {
        return TRUE ;
    }
    
    pstcCt = (volatile M0P_CT_PWC_TypeDef*)(pstcCtInstanceData->pstcInstance);
    bFlag = pstcCt->STA_f.ERR ? TRUE : FALSE;
    
    return bFlag;
} /* Ct_Pwc_GetErrorFlag */

//@} // CtGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
