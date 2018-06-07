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
/** \file hwwdt.c
 **
 ** HW watchdog timer driver define.
 ** @link HWWDT Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "hwwdt.h"

/**
 ******************************************************************************
 ** \addtogroup HwwdtGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
/* for WDT_CTL */
#define HWWDT_CTL_INTEN         (0x01u)
#define HWWDT_CTL_INTDIS        (0xFEu)
#define HWWDT_CTL_RESEN         (0x02u)
#define HWWDT_CTL_RESDIS        (0xFDu)
#define HWWDT_CTL_CLKSRC_EXT    (0x04u)
#define HWWDT_CTL_CLKSRC_LCR    (0xFBu)
     
/* for checking magic word (Hwwdt_DeInit) */
#define HWWDT_MAGIC_WORD_CHK1       (0x38D1AE5Cu)
#define HWWDT_MAGIC_WORD_CHK2       (0x7624D1BCu)
#define HWWDT_MAGIC_WORD_CHK_RESULT (0xFFFFFFFFu)

/* for WDOGLOCK */
#define HWWDT_REG_UNLOCK_1  (0x1ACCE551u)
#define HWWDT_REG_UNLOCK_2  (0xE5331AAEu)

#define     IS_VALID_EN(x)          ((TRUE == (x)) || (FALSE == (x)))

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
static func_ptr_t pfnHwwdtCallback; ///< callback function pointer for HW-Wdg Irq

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/******************************************************************************/
/* Static inline functions                                                    */
/******************************************************************************/
 
/**
 ******************************************************************************
 ** \brief Hwwdt_IrqHandler 
 **        Hardware Watchdog Interrupt Handler
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Hwwdt_IrqHandler(void)
{
    /* Check hardware interrupt status */
    if (TRUE == M0P_HWWDT->WDT_STA_f.STA)
    {
        if (NULL != pfnHwwdtCallback)
        {
            pfnHwwdtCallback();
        }
    }
} /* HwwdtIrqHandler */

/**
 ******************************************************************************
 ** \brief Initialize Hardware Watchdog
 **
 ** \param [in] pstcConfig   Pointer to Hardware Watchdog configuration
 **
 ** \retval Ok                      Setup successful
 ** \retval ErrorInvalidParameter   pstcConfig == NULL
 **
 ** \note This function only set the Hardware Watchdog configuration.
 **       If Hwwdt_Start() is called, MCU start the Hardware Watchdog.
 ******************************************************************************/
en_result_t Hwwdt_Init(stc_hwwdt_config_t* pstcConfig)
{
    en_result_t enResult;
    uint8_t     u8WdogControl = 0u;      /* Preset register */

    ASSERT(IS_VALID_EN(pstcConfig->bResetEnable));
    
    enResult = ErrorInvalidParameter;
    /* Check for NULL Pointer */
    if (NULL != pstcConfig)
    {
        /* Release Lock */
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;
        M0P_HWWDT->WDT_LD = pstcConfig->u32LoadValue; 

        if (TRUE == pstcConfig->bResetEnable)
        {
            /* RESEN bit */
            u8WdogControl |= HWWDT_CTL_RESEN;
        }
        else
        {
            u8WdogControl &= HWWDT_CTL_RESDIS;
        }

        if (LowCr == pstcConfig->enClkSrc)
        {
            /* CLKSRC bit */
            u8WdogControl |= HWWDT_CTL_CLKSRC_EXT;
        }
        else
        {
            u8WdogControl &= HWWDT_CTL_CLKSRC_LCR;
        }

        /* HW Watchdog Control Register unlock sequence */
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_2;

        /* Setup HW-Watchdog and start */
        M0P_HWWDT->WDT_CTL = u8WdogControl;

        /* Initialize callback to NULL */
        pfnHwwdtCallback = pstcConfig->pfnHwwdtIrqCb;

        enResult = Ok;
    }

    return (enResult);
} /* Hwwdt_Init */

/**
 ******************************************************************************
 ** \brief Un-Initialize Hardware Watchdog
 **
 ** This function disables and un-initializes the Hardware Watchdog, when the
 ** first argument is 0xC72E51A3 and the second agrument 0x89DB2E43.
 ** The magic words are together 64-bit wide and have a balanced entropy.
 ** (32 zero and 32 one bits)
 **
 ** \param [in] u32MagicWord1   1st Magic word for disabling (0xC72E51A3)
 ** \param [in] u32MagicWord2   2nd Magic word for disabling (0x89DB2E43)
 **
 ** \retval Ok                      disable sucessful
 ** \retval ErrorInvalidParameter   not diabled => magic word is wrong!
 **
 ******************************************************************************/
en_result_t Hwwdt_DeInit(uint32_t u32MagicWord1,
                         uint32_t u32MagicWord2
                        )
{
    en_result_t enResult;

    enResult = ErrorInvalidParameter;

    /* Inverted magic word check is done to avoid "plain text magic word" in ROM. */
    if ((HWWDT_MAGIC_WORD_CHK_RESULT == (u32MagicWord1 ^ HWWDT_MAGIC_WORD_CHK1)) &&
        (HWWDT_MAGIC_WORD_CHK_RESULT == (u32MagicWord2 ^ HWWDT_MAGIC_WORD_CHK2))
       )
    {
        /* HW Watchdog Control Register unlock sequence */
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_2;

        /* HW Watchdog stop */
        M0P_HWWDT->WDT_CTL = 0;

        /* Initialize callback to NULL */
        pfnHwwdtCallback = NULL;

        enResult = Ok;
    }

    return (enResult);
} /* Hwwdt_DeInit */

/**
 ******************************************************************************
 ** \brief Start the Hardware Watchdog
 **
 ** \retval Ok                          Setup successful
 ** \retval ErrorOperationInProgress    Hardware Watchdog is active now
 **
 ******************************************************************************/
en_result_t Hwwdt_Start(void)
{
    en_result_t enResult;

    /* If hardware watchdog is active, error is returned. */
    if (TRUE == M0P_HWWDT->WDT_CTL_f.IE)
    {
        enResult = ErrorOperationInProgress;
    }
    else
    {
        /* HW Watchdog Control Register unlock sequence */
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_2;

        /* Enable interrupt and count */
        M0P_HWWDT->WDT_CTL_f.IE = TRUE;

        enResult = Ok;
    }

    return (enResult);
}

/**
 ******************************************************************************
 ** \brief Hwwdt_Stop 
 **        Stop the Hardware Watchdog
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Hwwdt_Stop(void)
{
    if (TRUE == M0P_HWWDT->WDT_CTL_f.IE)
    {
        /* HW Watchdog Control Register unlock sequence */
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;
        M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_2;

        /* Disable interrupt and count */
        M0P_HWWDT->WDT_CTL_f.IE = FALSE;
    }
}

/**
 ******************************************************************************
 ** \brief Write the load value for Hardware Watchdog
 **
 ** \param [in]  u32LoadValue   Load value
 **
 ******************************************************************************/
void Hwwdt_WriteWdtLoad(uint32_t u32LoadValue)
{
    M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;    /* Release Lock */
    M0P_HWWDT->WDT_LD = u32LoadValue;          /* Write load value */
} /* Hwwdt_WriteWdgLoad */

/**
 ******************************************************************************
 ** \brief Read the count value for Hardware Watchdog
 **
 ** \retval uint32_t:Value of value register
 **
 ******************************************************************************/
uint32_t Hwwdt_ReadWdtValue(void)
{
    return (M0P_HWWDT->WDT_VL);
} /* Hwwdt_ReadWdgValue */

/**
 ******************************************************************************
 ** \brief Feed Hardware Watchdog (Call function)
 **
 ** This function feeds the Hardware Watchdog with the unlock, feed, and lock
 ** sequence. Take care of the arbitrary values, because there are not checked
 ** for plausibility!
 **
 ** \param [in] u8ClearPattern1   Pattern of arbitrary value
 ** \param [in] u8ClearPattern2   Inverted arbitrary value
 **
 ******************************************************************************/
void Hwwdt_Feed(uint8_t u8ClearPattern1,
                uint8_t u8ClearPattern2
               )
{
    M0P_HWWDT->WDT_LCK = HWWDT_REG_UNLOCK_1;    /* Release Lock */
    M0P_HWWDT->WDT_INTCLR = u8ClearPattern1;       /* Clear possible interrupt and reload value, step 1 */
    M0P_HWWDT->WDT_INTCLR = u8ClearPattern2;       /* Clear possible interrupt and reload value, step 2 */
} /* Hwwdt_Feed */

/**
 ******************************************************************************
 ** \brief Hwwdt_EnableDbgBrkWdgCtl 
 **        Enable Debug Break Watchdog Timer Control
 ** \param [IN]     : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Hwwdt_EnableDbgBrkWdgCtl(void)
{
    stc_clock_dbwdt_ctrl_field_t stcDBWDT_CTRL;

    stcDBWDT_CTRL         = M0P_CLOCK->DBWDT_CTRL_f;
    stcDBWDT_CTRL.HWWDG_BRK  = TRUE;
    M0P_CLOCK->DBWDT_CTRL_f = stcDBWDT_CTRL;
} /* Hwwdt_EnableDbgBrkWdtCtl */

/**
 ******************************************************************************
 ** \brief Disable Debug Break Watchdog Timer Control
 **
 ******************************************************************************/
void Hwwdt_DisableDbgBrkWdgCtl(void)
{
    stc_clock_dbwdt_ctrl_field_t stcDBWDT_CTRL;

    stcDBWDT_CTRL         = M0P_CLOCK->DBWDT_CTRL_f;
    stcDBWDT_CTRL.HWWDG_BRK  = FALSE;
    M0P_CLOCK->DBWDT_CTRL_f = stcDBWDT_CTRL;
} /* Hwwdt_DisableDbgBrkWdtCtl */

//@} // HwwdtGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
