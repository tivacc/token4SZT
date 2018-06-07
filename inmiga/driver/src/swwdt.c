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
/** \file swwdt.c
 **
 ** SW watchdog timer driver define.
 ** @link SWWDT Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "swwdt.h"

/**
 ******************************************************************************
 ** \addtogroup SwwdtGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
/* for WDOGLOAD */
#define SWWDT_DEFAULT_VAL   (0xFFFFFFFFu)

/* for WDOGCONTROL */
#define SWWDT_CTL_INTEN     (0x01u)
#define SWWDT_CTL_RESEN     (0x02u)
#define SWWDT_CTL_TWD100    (0x00u)
#define SWWDT_CTL_TWD75     (0x04u)
#define SWWDT_CTL_TWD50     (0x08u)
#define SWWDT_CTL_TWD25     (0x0Cu)
#define SWWDT_CTL_SPM       (0x10u)

/* for WDOGSPMC */
#define SWWDT_SPMC_TGR      (0x01u)

/* for WDOGLOCK */
#define SWWDT_REG_UNLOCK    (0x1ACCE551u)

#define     IS_VALID_EN(x)          ((TRUE == (x)) || (FALSE == (x)))

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/
static func_ptr_t pfnSwwdtCallback; ///< callback function pointer for SW-Wdg Irq

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

/**
 ******************************************************************************
 ** \brief Software Watchdog Interrupt Handler
 ******************************************************************************/
void Swwdt_IrqHandler(void)
{
    /* Check software interrupt status */
    if (TRUE == M0P_SWWDT->WDT_STA_f.STA)
    {
        if (NULL != pfnSwwdtCallback)
        {
            pfnSwwdtCallback();
        }
    }
} /* SwwdtIrqHandler */

/**
 ******************************************************************************
 ** \brief Initialize Software Watchdog
 **
 ** \param [in] pstcConfig   Pointer to Software Watchdog configuration
 **
 ** \retval Ok                      Setup successful
 ** \retval ErrorInvalidParameter   pstcConfig == NULL
 **
 ** \note This function only initializes the Software Watchdog configuration.
 **       If Swwdt_Start() is called, MCU start the Software Watchdog.
 **
 ******************************************************************************/
en_result_t Swwdt_Init(stc_swwdt_config_t* pstcConfig)
{
    en_result_t enResult;
    uint8_t     u8WdogControl = 0u;  /* Preset Watchdog Control Register */

    uint8_t     u8WdogMdc    = 0u;  /* Preset Window Watchdog Control Register */

    ASSERT(IS_VALID_EN(pstcConfig->bResetEnable));
    ASSERT(IS_VALID_EN(pstcConfig->bWinWdtEnable));
    ASSERT(IS_VALID_EN(pstcConfig->bWinWdtResetEnable));
    
    enResult = ErrorInvalidParameter;

    /* Check for NULL Pointer */
    if (NULL != pstcConfig)
    {
        enResult = Ok;
        /* Un Lock */
        M0P_SWWDT->WDT_LCK = SWWDT_REG_UNLOCK;

        /* Window watchdog mode */
        if (TRUE == pstcConfig->bWinWdtEnable)
        {
            /* Set SPM bit */
            u8WdogControl |= SWWDT_CTL_SPM;
            /* Set reset enable when reload without timing window was occured */
            if (TRUE == pstcConfig->bWinWdtResetEnable)
            {
                u8WdogMdc = SWWDT_SPMC_TGR;
            }
            /* Set timing window for window watchdog mode */
            switch (pstcConfig->u8TimingWindow)
            {
                case en_swwdt_timing_window_100:
                    u8WdogControl |= SWWDT_CTL_TWD100;
                    break;
                case en_swwdt_timing_window_75:
                    u8WdogControl |= SWWDT_CTL_TWD75;
                    break;
                case en_swwdt_timing_window_50:
                    u8WdogControl |= SWWDT_CTL_TWD50;
                    break;
                case en_swwdt_timing_window_25:
                    u8WdogControl |= SWWDT_CTL_TWD25;
                    break;
                default:
                    enResult = ErrorInvalidParameter;
                    break;
            }
        }

        if (Ok == enResult)
        {
            /* Set reset enable */
            if (TRUE == pstcConfig->bResetEnable)
            {
                /* Set RESEN bit */
                u8WdogControl |= SWWDT_CTL_RESEN;
            }

            // Set interval
            M0P_SWWDT->WDT_LD = pstcConfig->u32LoadValue;

            M0P_SWWDT->WDT_MDC    = u8WdogMdc;    /* Setup Window watchdog and */

            M0P_SWWDT->WDT_CTL = u8WdogControl; /* Setup SW-Watchdog */
            M0P_SWWDT->WDT_LCK    = 0u;             /* Lock it! */

            /* Initialize callback to NULL */
            pfnSwwdtCallback = pstcConfig->pfnSwwdtIrqCb;

            /* Enable NVIC */
            NVIC_ClearPendingIRQ(SWDT_IRQn);
            NVIC_EnableIRQ(SWDT_IRQn);
            NVIC_SetPriority(SWDT_IRQn, DDL_IRQ_LEVEL_SWDT);
        }
    }

    return (enResult);
} /* Swwdt_Init */

/**
 ******************************************************************************
 ** \brief Un-Initialize Software Watchdog
 **
 ******************************************************************************/
void Swwdt_DeInit(void)
{
    /* Disable NVIC */
    NVIC_ClearPendingIRQ(SWDT_IRQn);
    NVIC_DisableIRQ(SWDT_IRQn);
    NVIC_SetPriority(SWDT_IRQn, DDL_IRQ_LEVEL_SWDT);  

    M0P_SWWDT->WDT_LCK    = SWWDT_REG_UNLOCK;  /* Un Lock */
    M0P_SWWDT->WDT_CTL = 0u;                 /* Reset SW-Watchdog */    
    M0P_SWWDT->WDT_MDC    = 0u;                 /* Reset Window watchdog */
    M0P_SWWDT->WDT_LD    = SWWDT_DEFAULT_VAL; /* Set default value to load value */

    pfnSwwdtCallback       = NULL;              /* Initialize callback to NULL */
} /* Swwdt_DeInit */

/**
 ******************************************************************************
 ** \brief Start the Software Watchdog
 **
 ** \retval Ok                          Setup successful
 ** \retval ErrorOperationInProgress    Software Watchdog is active now
 **
 ** \note Please initialize by calling Swwdt_Init() before executing this function.
 **
 ******************************************************************************/
en_result_t Swwdt_Start(void)
{
    en_result_t enResult;

    /* If software watchdog is active, error is returned. */
    if (TRUE == M0P_SWWDT->WDT_CTL_f.IE)
    {
        enResult = ErrorOperationInProgress;
    }
    else
    {
        M0P_SWWDT->WDT_LCK = SWWDT_REG_UNLOCK; /* Un Lock */
        M0P_SWWDT->WDT_CTL_f.IE = TRUE;  /* Enable interrupt and count */
        M0P_SWWDT->WDT_LCK = 0u;                /* Lock */

        enResult = Ok;
    }

    return (enResult);
} /* Swwdt_Start */

/**
 ******************************************************************************
 ** \brief Stop the Software Watchdog
 **
 ******************************************************************************/
void Swwdt_Stop(void)
{
    if (TRUE == M0P_SWWDT->WDT_CTL_f.IE)
    {
        M0P_SWWDT->WDT_LCK = SWWDT_REG_UNLOCK; /* Un Lock */
        M0P_SWWDT->WDT_CTL_f.IE = FALSE; /* Disable interrupt and count */
        M0P_SWWDT->WDT_LCK = 0u;                /* Lock */
    }
} /* Swwdt_Stop */

/**
 ******************************************************************************
 ** \brief Write the load value for Software Watchdog
 **
 ** \param [in]  u32LoadValue   Load value
 **
 ******************************************************************************/
void Swwdt_WriteWdtLoad(uint32_t u32LoadValue)
{
    M0P_SWWDT->WDT_LCK = SWWDT_REG_UNLOCK;     /* Un Lock */
    M0P_SWWDT->WDT_LD = u32LoadValue;         /* Write the load value */
    M0P_SWWDT->WDT_LCK = 0u;                    /* Lock */
} /* Swwdt_WriteWdgLoad */

/**
 ******************************************************************************
 ** \brief Read the count value for Software Watchdog
 **
 ** \retval uint32_t:Value of value register
 **
 ******************************************************************************/
uint32_t Swwdt_ReadWdtValue(void)
{
    return (M0P_SWWDT->WDT_VL);
} /* Swwdt_ReadWdgValue */

/**
 ******************************************************************************
 ** \brief Feed Software Watchdog (Call function)
 **
 ** This function feeds the Software Watchdog with the unlock, feed, and lock
 ** sequence.
 **
 ******************************************************************************/
void Swwdt_Feed(void)
{
    M0P_SWWDT->WDT_LCK   = SWWDT_REG_UNLOCK;   /* Release Lock */
    M0P_SWWDT->WDT_INTCLR = 1u;                  /* Clear possible interrupt and reload value */
    M0P_SWWDT->WDT_LCK   = 0u;                  /* Lock again it! */
} /* Swwdt_Feed */

/**
 ******************************************************************************
 ** \brief Enable Debug Break Watchdog Timer Control
 **
 ******************************************************************************/
void Swwdt_EnableDbgBrkWdgCtl(void)
{
    stc_clock_dbwdt_ctrl_field_t stcDBWDT_CTRL;

    stcDBWDT_CTRL         = M0P_CLOCK->DBWDT_CTRL_f;
    stcDBWDT_CTRL.SWWDG_BRK  = TRUE;
    M0P_CLOCK->DBWDT_CTRL_f = stcDBWDT_CTRL;
} /* Swwdt_EnableDbgBrkWdtCtl */

/**
 ******************************************************************************
 ** \brief Disable Debug Break Watchdog Timer Control
 **
 ******************************************************************************/
void Swwdt_DisableDbgBrkWdgCtl(void)
{
    stc_clock_dbwdt_ctrl_field_t stcDBWDT_CTRL;

    stcDBWDT_CTRL         = M0P_CLOCK->DBWDT_CTRL_f;
    stcDBWDT_CTRL.SWWDG_BRK  = FALSE;
    M0P_CLOCK->DBWDT_CTRL_f = stcDBWDT_CTRL;
} /* Swwdt_DisableDbgBrkWdtCtl */

//@} // SwwdtGroup


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
