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
/** \file exint.c
 **
 ** A detailed description is available at 
 ** @link ExintGroup Module description @endlink
 **
 ** History:
 **   - 2016-12-16  1.0
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "exint.h"

/**
 ******************************************************************************
 ** \addtogroup ExintGroup
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/
#define     IS_VALID_CH(x)          (ExintInstanceIndexMax > (x) )
#define     IS_VALID_LEVEL(x)        (   ExIntLowLevel == (x) || \
                                        ExIntHighLevel == (x) || \
                                        ExIntRisingEdge == (x) || \
                                        ExIntFallingEdge == (x) )

#define     IS_NULL_POINT(x)   (NULL != (x))

#define     IS_VALID_CNT_SZ(x)       (DtCounterSize16 == (x) || \
                                      DtCounterSize32 == (x) )

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

stc_exint_intern_data_t stcExintInternData;

const uint8_t cau8ExintReferenceLut[DDL_EXINT_CHANNELS + 1] =
{
    0u,
    1u,
    2u,
    3u,
    4u,
    5u,
    6u,
    7u,
    8u,
    9u,
    10u,
    11u,
    12u,
    13u,
    14u,
    15u,
    255u   // End of table
};




stc_exint_nmi_intern_data_t stcExintNMIInternData;


/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/


#if 0
/**
 ******************************************************************************
 ** \brief Return the internal reference index of an Exint channel
 **
 ** \param u8Channel   Exint channel number
 **
 ** \return uint8_t    Reference index (255 if not found or u8Channel > 15)
 **
 ******************************************************************************/
static uint8_t ExintGetInternDataIdx(uint8_t u8Channel)
{
    uint8_t u8Index;

    if (u8Channel > 15u)
    {
        return 255u;
    }

    for (u8Index = 0u; u8Index < DDL_EXINT_CHANNELS; u8Index++)
    {
        if (u8Channel == cau8ExintReferenceLut[u8Index])
        {
            return u8Index;
        }
    }

    return 255u;  // Should never happen ...
}
#endif

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief Interrupt handlers for External interrupts 0
 **
 ** This function clears the cause bit and calls the callback function, if
 ** specified.
 ******************************************************************************/
void Exti_07IrqHandler(uint8_t u8Channel)
{
    //uint8_t u8Reference;

    ASSERT(IS_VALID_CH(u8Channel));

    M0P_EXTINT->INTCLR &= (0xFFFFFFFFu ^ (1ul << u8Channel));

    if (0u != stcExintInternData.apfnExintCallback[u8Channel])
    {
        stcExintInternData.apfnExintCallback[u8Channel]();
    }
} // Exint_IrqHandler



/**
 ******************************************************************************
 ** \brief Exti_815IrqHandler 
 **        ext 8-15 interrupt handler
 ** 
 ** \param [IN] u8Channel   : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Exti_815IrqHandler(uint8_t u8Channel)
{
    //uint8_t u8Reference;

    ASSERT(IS_VALID_CH(u8Channel));

    M0P_EXTINT->INTCLR &= (0xFFFFFFFFu ^ (1ul << u8Channel));

    if (NULL != stcExintInternData.apfnExintCallback[u8Channel])
    {
        stcExintInternData.apfnExintCallback[u8Channel]();
    }
} // Exint_IrqHandler

/**
 ******************************************************************************
 ** \brief Nmi_IrqHandler 
 **        no maskable interrupt handler
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Nmi_IrqHandler(void)
{
    stcExintNMIInternData.pfnNmiCallback();
}

/**
 ******************************************************************************
 ** \brief Init External Interrupts
 **
 ** This function initializes the external interrupts according the given
 ** configuration.
 **
 ** \param [in]  pstcConfig        EXINT configuration parameters
 ** 
 ** \retval Ok                     EXINT initialized
 ** \retval ErrorInvalidParameter  pstcConfig == NULL or Illegal mode
 ******************************************************************************/
en_result_t Exint_Init(uint8_t u8Channel, stc_exint_config_t *pstcConfig)
{
    //uint8_t  u8Reference;
    uint32_t u32INTLVL;
    uint32_t u32Enir;

    ASSERT(IS_VALID_CH(u8Channel));
    ASSERT(IS_NULL_POINT(pstcConfig));

    u32INTLVL  = M0P_EXTINT->INTLVL;

    u32Enir  = M0P_EXTINT->INTEN;

    if (1u == pstcConfig->bEnable)
    {
        if (u8Channel < ExintInstanceIndexMax)
        {
            switch (pstcConfig->enLevel)
            {
                case ExIntLowLevel:
                    u32INTLVL &= (~(3u << (2u * u8Channel)));
                    break;        // bits remain 2'b00
                case ExIntHighLevel:
                    u32INTLVL |= 1u << (2u * u8Channel);
                    break;
                case ExIntRisingEdge:
                    u32INTLVL |= 2u << (2u * u8Channel);
                    break;
                case ExIntFallingEdge:
                    u32INTLVL |= 3u << (2u * u8Channel);
                    break;

                default:
                    return ErrorInvalidParameter;
            }
        }
        u32Enir |= 1ul << u8Channel;
    } else
    {
        u32Enir &= ~(1ul << u8Channel);
    }
    stcExintInternData.apfnExintCallback[u8Channel] = pstcConfig->pfnExintCallback;


    // update hardware
    M0P_EXTINT->INTLVL  = u32INTLVL;

    M0P_EXTINT->INTCLR  = 0u;         // Clear all possible interrupts due to level change
    M0P_EXTINT->INTEN  = u32Enir;

    //if(TRUE == pstcConfig->bTouchNvic)
    //{
    u32Enir = M0P_EXTINT->INTEN;
    if ((u32Enir & 0x00FF) > 0u)
    {
        NVIC_ClearPendingIRQ(EXINT0_7_IRQn);
        NVIC_SetPriority(EXINT0_7_IRQn, DDL_IRQ_LEVEL_EXT07);
        NVIC_EnableIRQ(EXINT0_7_IRQn);
    }
    if ((u32Enir & 0xFF00) > 0u)
    {
        NVIC_ClearPendingIRQ(EXINT8_15_IRQn);
        NVIC_SetPriority(EXINT8_15_IRQn, DDL_IRQ_LEVEL_EXT815);
        NVIC_EnableIRQ(EXINT8_15_IRQn);
    }


    //}

    return Ok;
} // Exint_DisableChannel

/**
 ******************************************************************************
 ** \brief Init External Interrupts
 **
 **         This function de-initializes all external interrupts.
 ** 
 ** \retval Ok                     EXINT sucessful disabled
 ******************************************************************************/
en_result_t Exint_DeInit(uint8_t u8Channel) //////
{
    ASSERT(IS_VALID_CH(u8Channel));
    M0P_EXTINT->INTEN &= ~(1ul << u8Channel);   // Disable all channels
    if ((u8Channel < ExintInstanceIndexExint8) && ((M0P_EXTINT->INTEN & 0xFF) == 0))
    {
        NVIC_SetPriority(EXINT0_7_IRQn, DDL_IRQ_LEVEL_EXT07);
        NVIC_DisableIRQ(EXINT0_7_IRQn);
    } else if ((M0P_EXTINT->INTEN & 0xFF00) == 0u)
    {
        NVIC_SetPriority(EXINT8_15_IRQn, DDL_IRQ_LEVEL_EXT815);
        NVIC_DisableIRQ(EXINT8_15_IRQn);
    } else
    {}
    return Ok;  
} // Exint_DeInit

/**
 ******************************************************************************
 ** \brief Enable a single External Interrupt
 **
 **         This function enables a single External Interrupt.
 **
 ** \note This function does not set
 **       stc_exint_config_t#abEnable[u8Channel]!
 **
 ** \param [in]  u8Channel         External Interrupt channel number
 ** 
 ** \retval Ok                     Channel enabled
 ** \retval ErrorInvalidParameter  Invalid channel number
 ******************************************************************************/
en_result_t Exint_EnableChannel(uint8_t u8Channel)
{
    ASSERT(IS_VALID_CH(u8Channel));

    M0P_EXTINT->INTCLR &= 0xFFFFFFFFu ^ (1u << u8Channel);
    M0P_EXTINT->INTEN |= 1u << u8Channel;
    if ((M0P_EXTINT->INTEN & 0x00FF) > 0u)
    {
        NVIC_ClearPendingIRQ(EXINT0_7_IRQn);
        NVIC_SetPriority(EXINT0_7_IRQn, DDL_IRQ_LEVEL_EXT07);
        NVIC_EnableIRQ(EXINT0_7_IRQn);
    } else if ((M0P_EXTINT->INTEN & 0xFF00) > 0u)
    {
        NVIC_ClearPendingIRQ(EXINT8_15_IRQn);
        NVIC_SetPriority(EXINT8_15_IRQn, DDL_IRQ_LEVEL_EXT815);
        NVIC_EnableIRQ(EXINT8_15_IRQn);
    } else
    {
        ;
    }
    return Ok;

} // Exint_EnableChannel

/**
 ******************************************************************************
 ** \brief Disable a single External Interrupt
 **
 ** This function disables a single External Interrupt.
 **
 ** \note This function does not clear
 **       stc_exint_config_t#abEnable[u8Channel]!
 **
 ** \param [in]  u8Channel         External Interrupt channel number
 ** 
 ** \retval Ok                     Channel enabled
 ** \retval ErrorInvalidParameter  Invalid channel number or channel
 ******************************************************************************/
en_result_t Exint_DisableChannel(uint8_t u8Channel)
{
    ASSERT(IS_VALID_CH(u8Channel));

    M0P_EXTINT->INTEN &= (1u << u8Channel) ^ 0xFFFFFFFFu;

    return Ok;
} // Exint_DisableChannel

/**
 ******************************************************************************
 ** \brief Set external interrupt detect mode
 **
 ** \param u8Channel   0~15
 ** \param enLevel
 ** \arg ExIntLowLevel       Low level is active edge for interrupt detection 
 ** \arg ExIntHighLevel      High level is active edge for interrupt detection 
 ** \arg ExIntRisingEdge     Rising edge is active edge for interrupt detection 
 ** \arg ExIntFallingEdge    Falling edge is active edge for interrupt detection
 **         
 ** \retval Ok                         Interreupt detection edge set normmally
 ** \retval ErrorInvalidParameter      u8Ch > EXINT_MAX_CH_INDEX
 **                                    invalid setting for enLevel
 **
 ******************************************************************************/
en_result_t Exint_SetDetectMode(uint8_t u8Channel, en_exint_level_t enLevel)
{
    ASSERT(IS_VALID_CH(u8Channel));
    ASSERT(IS_VALID_LEVEL(enLevel));
    switch (enLevel)
    {
        case ExIntLowLevel:
        case ExIntHighLevel:
        case ExIntRisingEdge:
        case ExIntFallingEdge:
            M0P_EXTINT->INTLVL &= ~(3ul << (2u * u8Channel));
            M0P_EXTINT->INTLVL |= ((uint8_t)(enLevel << (2u * u8Channel)));
            break;
        default:
            return ErrorInvalidParameter;
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief Get the external interrupt detection mode 
 **
 ** \param u8Channel   0~15
 **         
 ** \retval ExIntLowLevel       Low level is active edge for interrupt detection 
 ** \retval ExIntHighLevel      High level is active edge for interrupt detection 
 ** \retval ExIntRisingEdge     Rising edge is active edge for interrupt detection 
 ** \retval ExIntFallingEdge    Falling edge is active edge for interrupt detection
 **
 ******************************************************************************/
en_exint_level_t Exint_GetDetectMode(uint8_t u8Channel)
{
    uint8_t u8Level;
    ASSERT(IS_VALID_CH(u8Channel));
    u8Level = (M0P_EXTINT->INTLVL & (3ul << (2u * u8Channel))) >> (2u * u8Channel);
    return (en_exint_level_t)u8Level;
}

/**
 ******************************************************************************
 ** \brief Interrupt handler for None-Maskable Interrupt (NMI)
 **
 ** This function clears the cause bit and calls the NMI callback function, if
 ** specified.
 ******************************************************************************/
void Exint_Nmi_IrqHandler(void)
{
    if ((M0P_EXTINT->NMISRC & 0x01u) == 0x01u)
    {
        M0P_EXTINT->NMICLR = 0u;

        if (0u != stcExintNMIInternData.pfnNmiCallback)
        {
            stcExintNMIInternData.pfnNmiCallback();
        }
    }
}

/**
 ******************************************************************************
 ** \brief Init Non-Maskable Interrupt (NMI)
 **
 ** This function initializes the NMI according to the given
 ** configuration.
 **
 ** \param [in]  pstcConfig        NMI configuration parameters
 ** 
 ** \retval Ok                     NMI initialized
 ** \retval ErrorInvalidParameter  pstcConfig == NULL
 **
 ******************************************************************************/
en_result_t Exint_Nmi_Init(stc_exint_nmi_config_t *pstcConfig)
{
    if (pstcConfig == NULL)
    {
        return ErrorInvalidParameter;
    }

    // Set internal data
    stcExintNMIInternData.pfnNmiCallback = pstcConfig->pfnNmiCallback;

    return Ok;
} // Exint_Nmi_Init

/**
 ******************************************************************************
 ** \brief De-Init Non-Maskable Interrupt (NMI)
 **
 ** This function de-initializes the NMI according to the given
 ** configuration.
 **
 ** \param [in]  pstcConfig        NMI configuration parameters
 ** 
 ** \retval Ok                     NMI initialized
 ** \retval ErrorInvalidParameter  pstcConfig == NULL
 **
 ******************************************************************************/
en_result_t Exint_Nmi_DeInit(stc_exint_nmi_config_t *pstcConfig)
{
    if (pstcConfig == NULL)
    {
        return ErrorInvalidParameter;
    }

    // Set internal data
    stcExintNMIInternData.pfnNmiCallback = NULL;

    return Ok;
} // Exint_Nmi_DeInit

/**
 ******************************************************************************
 ** \brief De-Init Non-Maskable Interrupt (NMI)
 **
 ** This function de-initializes the NMI according to the given
 ** configuration.
 **
 ** \param [in]  pstcConfig        NMI configuration parameters
 ** 
 ** \retval Ok                     NMI initialized
 ** \retval ErrorInvalidParameter  pstcConfig == NULL
 **
 ******************************************************************************/
en_result_t Exint_Nmi_IrqFlagClear(void)
{

    // Set internal data
    M0P_EXTINT->NMICLR = 0;

    return Ok;
} // Exint_Nmi_DeInit

//@} // ExintGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
