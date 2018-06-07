/******************************************************************************
*Copyright(C)2016, Huada Semiconductor Co.,Ltd All rights reserved.
*
* This software is owned and published by:
* Huada Semiconductor Co.,Ltd("HDSC").
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

/** \file clk.c
 **
 ** Common API of clk.
 ** @link clkGroup Some description @endlink
 **
 **   - 2016-10-31
 **
 *****************************************************************************/

/*****************************************************************************
 * Include files
 *****************************************************************************/
#include "clk.h"
#include "system_hc32l15.h"

/**
 ******************************************************************************
 ** \addtogroup Clk Common Functions
 *****************************************************************************/
//@{

/*****************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/
#define CLK_TIMEOUT             (1000000u)

#define IS_VALID_SRC(x)         (   ClkHICR == (x)||\
                                    ClkHSXT == (x)||\
                                    ClkLICR == (x)||\
                                    ClkLSXT == (x) )


#define IS_VALID_FUNC(x)        (   ClkFuncDt == (x)||\
                                    ClkFuncHWWDG == (x)||\
                                    ClkFuncSWWDG == (x)||\
                                    ClkFuncFcsReset == (x)||\
                                    ClkFuncFcs == (x)||\
                                    ClkFuncLSXTReset == (x)||\
                                    ClkFuncHSXTReset == (x)||\
                                    ClkFuncLSXT == (x)||\
                                    ClkFuncHSXT == (x) )

#define IS_VALID_IRQ(x)         (   ClkIrqFcs == (x)||\
                                    ClkIrqLSXT == (x)||\
                                    ClkIrqHSXT == (x)||\
                                    ClkIrqLSXTRdy == (x)||\
                                    ClkIrqHSXTrRdy == (x) )

#define IS_VALID_FCSDIV(x)      (   ClkFcsDiv256 == (x)||\
                                    ClkFcsDiv512 == (x)||\
                                    ClkFcsDiv1024 == (x) )

#define IS_VALID_FCSSTAT(x)     (   ClkCsvLSXT == (x) || ClkCsvHSXT == (x))


/*****************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 *****************************************************************************/
extern uint32_t SystemCoreClock;
/****************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/

/*****************************************************************************
 * Local variable definitions ('static')
 *****************************************************************************/
static func_ptr_t pfnFcsCallback = NULL;
static func_ptr_t pfnHSXTCallback = NULL;
static func_ptr_t pfnLSXTCallback = NULL;
static func_ptr_t pfnHSXTFailCallback = NULL;
static func_ptr_t pfnLSXTFailCallback = NULL;


/*****************************************************************************
 * Local function prototypes ('static')
 *****************************************************************************/
static void ClkEnableNvic(void);
static void ClkDisableNvic(void);
static void ClkFcsEnableNvic(void);
static void ClkFcsDisableNvic(void);

void Clk_HSXTRdy_IrqHandler(uint8_t u8Idx);
void Clk_LSXTRdy_IrqHandler(uint8_t u8Idx);
void Clk_CsvIrqHandler(uint8_t u8Idx);


/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief ClkDisableNvic 
 **        clk NVIC Disable
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void ClkDisableNvic(void)
{
    NVIC_ClearPendingIRQ(OSC_WU_RTC_IRQn);
    NVIC_DisableIRQ(OSC_WU_RTC_IRQn);
    NVIC_SetPriority(OSC_WU_RTC_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/**
 ******************************************************************************
 ** \brief ClkEnableNvic 
 **        clk NVIC Enable
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void ClkEnableNvic(void)
{
    NVIC_ClearPendingIRQ(OSC_WU_RTC_IRQn);
    NVIC_EnableIRQ(OSC_WU_RTC_IRQn);
    NVIC_SetPriority(OSC_WU_RTC_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/**
 ******************************************************************************
 ** \brief ClkFcsDisableNvic 
 **        clk fcs module NVIC disable
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void ClkFcsDisableNvic(void)
{
    NVIC_ClearPendingIRQ(CSV_IRQn);
    NVIC_DisableIRQ(CSV_IRQn);
    NVIC_SetPriority(CSV_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/**
 ******************************************************************************
 ** \brief ClkFcsEnableNvic 
 **        clk fcs module NVIC enable
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void ClkFcsEnableNvic(void)
{
    NVIC_ClearPendingIRQ(CSV_IRQn);
    NVIC_EnableIRQ(CSV_IRQn);
    NVIC_SetPriority(CSV_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/**
 ******************************************************************************
 ** \brief ClkSetHICR 
 **        set clk source to hicr and wait it ready.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t   Ok: set done.
 ******************************************************************************/
static en_result_t ClkSetHICR(void)
{
    M0P_CLOCK->CTRL_f.INPUT = ClkHICR;

    while (TRUE != M0P_CLOCK->CLK_STB_f.HC_RDY)
    {
        ;
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief ClkSetHSXT 
 **        set clk source to ext high cr and wait it ready.
 ** \param [IN]     : 
 ** 
 ** \retval en_result_t   Ok: set done.
 ******************************************************************************/
static en_result_t ClkSetHSXT(void)
{
    en_clk_source_t enSrc;

    Clk_Enable(ClkHSXT, TRUE);

    enSrc = (en_clk_source_t)M0P_CLOCK->CLK_STB_f.SRC;

    if ((ClkLICR == enSrc) || (ClkLSXT == enSrc))
    {
        M0P_CLOCK->CTRL_f.INPUT = ClkHSXT;
        while (FALSE == M0P_CLOCK->CLK_STB_f.MAIN_RDY)
        {
            ;
        }
    } else
    {
        while (FALSE == M0P_CLOCK->CLK_STB_f.MAIN_RDY)
        {
            ;
        }
        M0P_CLOCK->CTRL_f.INPUT = ClkHSXT;
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief ClkSetLICR 
 **        set clk source to low cr.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t  OK: set done.
 ******************************************************************************/
static en_result_t ClkSetLICR(void)
{
    M0P_CLOCK->CTRL_f.INPUT = ClkLICR;
    return Ok;
}

/**
 ******************************************************************************
 ** \brief ClkSetLSXT 
 **        set clk source to ext low cr.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t     OK: set done.
 ******************************************************************************/
static en_result_t ClkSetLSXT(void)
{
    M0P_CLOCK->CTRL_f.SUB_EN = TRUE;

    //after the stable time, the rdy flg must be true.
    while (FALSE == M0P_CLOCK->CLK_STB_f.SUB_RDY)
    {
        ;
    }

    M0P_CLOCK->CTRL_f.INPUT = ClkLSXT;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief ClkEnableFunc 
 **        clock enable/disable 
 ** 
 ** \param [IN] enFunc  :  clock source
 ** \param [IN] bFlag   :  clock enable/disable
 ** 
 ** \retval en_result_t Ok: set done
 **                     other:  set failed.
 ******************************************************************************/
static en_result_t ClkEnableFunc(en_clk_func_t enFunc, boolean_t bFlag)
{
    en_result_t enRet = Ok;

    ASSERT(IS_VALID_FUNC(enFunc));

    switch (enFunc)
    {
        case ClkFuncDt:
            M0P_CLOCK->CLK_CTL_f.DTCKE = bFlag;
            break;
        case ClkFuncHWWDG:
            M0P_CLOCK->CLK_CTL_f.HWCKE = bFlag;
            break;
        case ClkFuncSWWDG:
            M0P_CLOCK->CLK_CTL_f.SWCKE = bFlag;
            break;
        case ClkFuncFcsReset:
            M0P_CLOCK->FCM_CTL_f.AFDRE = bFlag;
            break;
        case ClkFuncFcs:
            M0P_CLOCK->FCM_CTL_f.AFDE = bFlag;
            break;
        case ClkFuncLSXTReset:
            M0P_CLOCK->FCM_CTL_f.SFCMRE = bFlag;
            break;
        case ClkFuncHSXTReset:
            M0P_CLOCK->FCM_CTL_f.MFCMRE = bFlag;
            break;
        case ClkFuncLSXT:
            M0P_CLOCK->FCM_CTL_f.SFCME = bFlag;
            break;
        case ClkFuncHSXT:
            M0P_CLOCK->FCM_CTL_f.MFCME = bFlag;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}

/**
 ******************************************************************************
 ** \brief ClkEnableIrq 
 **        clk interrupt enable/disable.
 ** 
 ** \param [IN] enSel   :  clock interrupt factor
 ** \param [IN] bFlag   :  enable/disable
 ** 
 ** \retval en_result_t Ok: set done
 **                     other:  set failed.
 ******************************************************************************/
static en_result_t ClkEnableIrq(en_clk_irq_sel_t enSel, boolean_t bFlag)
{
    en_result_t enRet = Ok;

    ASSERT(IS_VALID_IRQ(enSel));

    bFlag = bFlag & 1u;

    switch (enSel)
    {
        case ClkIrqFcs:
            M0P_CLOCK->INT_CTRL_f.FCSEN = bFlag;
            break;
        case ClkIrqHSXT:
            M0P_CLOCK->INT_CTRL_f.SCSVIE = bFlag;
            break;
        case ClkIrqHSXTrRdy:
            M0P_CLOCK->INT_CTRL_f.MAINEN = bFlag;
            break;
        case ClkIrqLSXT:
            M0P_CLOCK->INT_CTRL_f.SCSVIE = bFlag;
            break;
        case ClkIrqLSXTRdy:
            M0P_CLOCK->INT_CTRL_f.SUBEN = bFlag;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Clk_HSXTRdy_IrqHandler 
 **        external high cr ready interrupt handler.
 ** 
 ** \param [IN] u8Idx   : dummy param
 ** 
 ** \retval void 
 ******************************************************************************/
void Clk_HSXTRdy_IrqHandler(uint8_t u8Idx)
{
    if (NULL != pfnHSXTCallback)
    {
        pfnHSXTCallback();
    }
    M0P_CLOCK->INT_CLR_f.MAIN = TRUE;       ///< 1 = clear interrupt.
}


/**
 ******************************************************************************
 ** \brief Clk_LSXTRdy_IrqHandler 
 **        external low cr ready interrupt handler.
 ** 
 ** \param [IN] u8Idx   :  dummy param
 ** 
 ** \retval void 
 ******************************************************************************/
void Clk_LSXTRdy_IrqHandler(uint8_t u8Idx)
{
    if (NULL != pfnLSXTCallback)
    {
        pfnLSXTCallback();
    }
    M0P_CLOCK->INT_CLR_f.SUB = TRUE;
}


/**
 ******************************************************************************
 ** \brief Clk_CsvIrqHandler 
 **        
 ** 
 ** \param [IN] u8Idx   :   dummy param
 ** 
 ** \retval void 
 ******************************************************************************/
void Clk_CsvIrqHandler(uint8_t u8Idx)
{
    if (TRUE == M0P_CLOCK->INT_PEND_f.FCS)
    {
        if (NULL != pfnFcsCallback)
        {
            pfnFcsCallback();
        }
        M0P_CLOCK->INT_CLR_f.FCS = TRUE;
    }

    if (TRUE == M0P_CLOCK->INT_PEND_f.MCSVI)
    {
        if (NULL != pfnHSXTFailCallback)
        {
            pfnHSXTFailCallback();
        }
        M0P_CLOCK->INT_CLR_f.MCSVC = TRUE;
    }

    if (TRUE == M0P_CLOCK->INT_PEND_f.SCSVI)
    {
        if (NULL != pfnLSXTFailCallback)
        {
            pfnLSXTFailCallback();
        }
        M0P_CLOCK->INT_CLR_f.SCSVC = TRUE;
    }
}


/**
 ******************************************************************************
 ** \brief Clk_SwitchTo 
 **        switch HCLK source to #enSrc.
 ** 
 ** \param [IN] enSrc   :   new clock source.
 ** 
 ** \retval en_result_t     Ok: set done
 **                         others: set failed
 ******************************************************************************/
en_result_t Clk_SwitchTo(en_clk_source_t enSrc)
{
    uint32_t u32To = 0;
    uint8_t u8val1 = 0;
    volatile uint8_t u8val2 = 0;

    switch (enSrc)
    {
        case ClkHICR:                   // Always possible
                                        // M0P_OSC->HICR_FMC_f.FMC = 0x3;
            ClkSetHICR();
            break;

        case ClkHSXT:
            ClkSetHSXT();
            break;

        case ClkLICR:                  // Always possible
            ClkSetLICR();
            break;

        case ClkLSXT:
            ClkSetLSXT();
            break;
        default:
            return ErrorInvalidParameter;
    }

    // Wait until switch stable
    u32To = CLK_TIMEOUT;
    u8val1 = M0P_CLOCK->CTRL_f.INPUT;

    while (u32To > 0u)
    {
        u32To -= 1;
        u8val2 = M0P_CLOCK->CLK_STB_f.SRC;
        if (u8val1 == u8val2)
        {
            break;
        }
    }

    SystemCoreClockUpdate();

    if (u8val1 == u8val2)
    {
        return Ok;
    }

    return Error;

}


/**
 ******************************************************************************
 ** \brief Clk_GetSourceFreq 
 **        get input enSrc frequency.
 ** 
 ** \param [IN] enSrc   :   which clock to get its clock
 ** 
 ** \retval uint32_t    clock frequency (Hz)
 ******************************************************************************/
uint32_t Clk_GetSourceFreq(en_clk_source_t enSrc)
{
    uint32_t u32Val = 0;
    const uint8_t u8hicr_tbl[] = { 2, 4, 8, 16 };

    ASSERT(IS_VALID_SRC(enSrc));

    switch (enSrc)
    {
        case ClkHICR:
            u32Val = u8hicr_tbl[M0P_OSC->HICR_FMC_f.FMC];
            u32Val = u32Val * 1000 * 1000;
            break;
        case ClkHSXT:
            u32Val = CLK_HSXT_VAL;
            break;
        case ClkLICR:
            u32Val = CLK_LICR_VAL;
            break;
        case ClkLSXT:
            u32Val = CLK_LSXT_VAL;
            break;
        default:
            break;
    }

    return u32Val;
}


/**
 ******************************************************************************
 ** \brief Clk_GetSystemClk 
 **        get the HCLK,
 **        and, Update the System Core Clock with current core Clock retrieved
 **        from cpu registers.
 ** \param [IN]     : 
 ** 
 ** \retval uint32_t    the current clock frequency
 ******************************************************************************/
uint32_t Clk_GetSystemClk(void)
{
    uint8_t u8Val = 0;
    uint32_t u32Val = 0;

    u8Val = M0P_CLOCK->CLK_STB_f.SRC;
    u32Val = Clk_GetSourceFreq((en_clk_source_t)u8Val);

    //base div
    u8Val = M0P_CLOCK->BC_DIV_f.DIV;

    switch (u8Val)
    {
        case ClkBaseDiv1:
            break;
        case ClkBaseDiv2:
            u32Val = u32Val / 2;
            break;
        case ClkBaseDiv3:
            u32Val = u32Val / 3;
            break;
        case ClkBaseDiv4:
            u32Val = u32Val / 4;
            break;
        case ClkBaseDiv6:
            u32Val = u32Val / 6;
            break;
        case ClkBaseDiv8:
            u32Val = u32Val / 8;
            break;
        case ClkBaseDiv16:
            u32Val = u32Val / 16;
            break;
        default:
            break;
    }

    SystemCoreClock = u32Val;

    return u32Val;
}


/**
 ******************************************************************************
 ** \brief Clk_GetPeripheralClk 
 **        
 ** 
 ** \param [IN] enIdx   :   peripheral index
 ** 
 ** \retval uint32_t    :   requested peripheral clock freqency.
 ******************************************************************************/
uint32_t Clk_GetPeripheralClk(en_clk_periph_idx_t enIdx)
{
    uint32_t u32Val = 0;
    uint8_t u8div = 0;
    const uint8_t mu8apbdiv[] = { 1, 2, 4, 8 };

    ASSERT(enIdx < ClkPeriphralMax);

    u32Val = Clk_GetSystemClk();

    switch (enIdx)
    {
        case ClkPeriphralClock:
        case ClkPeriphralReset:
        case ClkPeriphralHwwdg:
        case ClkPeriphralSwwdg:
        case ClkPeriphralDt:
            u8div = M0P_CLOCK->APB0_CTRL_f.DIV;
            break;
        case ClkPeriphralCt:
        case ClkPeriphralAdc:
        case ClkPeriphralCal:
        case ClkPeriphralExti:
        case ClkPeriphralLcd:
        case ClkPeriphralGpio:
        case ClkPeriphralLvd:
        case ClkPeriphralDs:
        case ClkPeriphralMsc:
        case ClkPeriphralRtc:
        case ClkPeriphralBuzz:
        case ClkPeriphralVc:
        case ClkPeriphralSci:
            u8div = M0P_CLOCK->APB1_CTRL_f.DIV;
            break;
        case ClkPeriphralAes:
        case ClkPeriphralFlash:
            u8div = 0;
            break;
        default:
            return 0;
    }

    u8div = u8div & 0x3;
    u8div = mu8apbdiv[u8div];
    u32Val = u32Val / u8div;

    return u32Val;
}


/**
 ******************************************************************************
 ** \brief Clk_Init 
 **        
 ** 
 ** \param [IN] pstcCfg :       pointer to clock config data
 ** 
 ** \retval en_result_t         Ok:     init done
 *                              ErrorInvalidParameter: pstcCfg is NULL
 *                              pstcCfg has invalid param
 ******************************************************************************/
en_result_t Clk_Init(stc_clk_config_t *pstcCfg)
{
    ASSERT(NULL != pstcCfg);
    ASSERT(pstcCfg->enBaseClkDiv <= ClkBaseDiv16);
    ASSERT(pstcCfg->enAPB0Div <= ClkApb0Div8);
    ASSERT(pstcCfg->enAPB1Div <= ClkApb1Div8);

    M0P_CLOCK->BC_DIV_f.DIV = pstcCfg->enBaseClkDiv;
    M0P_CLOCK->APB0_CTRL_f.DIV = pstcCfg->enAPB0Div;

    M0P_CLOCK->APB1_CTRL_f.DIV = pstcCfg->enAPB1Div;

    //set stable time.
    M0P_CLOCK->CSWT_f.MAINWT = pstcCfg->enclkWaitMain & 0xF;
    M0P_CLOCK->CSWT_f.SUBWT = pstcCfg->enclkWaitSub & 0xF;

    /* Configure interrupt */
    if (TRUE == pstcCfg->bHSXTIrq)
    {
        pfnHSXTCallback = pstcCfg->pfnHSXTRdyCb;
        M0P_CLOCK->INT_CTRL_f.MAINEN = TRUE;
        ClkEnableIrq(ClkIrqHSXTrRdy, TRUE);
    }

    if (TRUE == pstcCfg->bLSXTIrq)
    {
        pfnHSXTCallback = pstcCfg->pfnHSXTRdyCb;
        M0P_CLOCK->INT_CTRL_f.SUBEN = TRUE;
        ClkEnableIrq(ClkIrqLSXTRdy, TRUE);
    }

    if ((TRUE == pstcCfg->bLSXTIrq) ||
        (TRUE == pstcCfg->bHSXTIrq))
    {
        ClkEnableNvic();
    }

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_DeInit 
 **        clk deinit 
 ** 
 ** \param [IN] bNvic   :   if to disable NVIC.
 ** 
 ** \retval en_result_t     Ok:     init done
 ******************************************************************************/
en_result_t Clk_DeInit(boolean_t bNvic)
{
    //set clock to HCR 4Mhz
    Clk_SwitchTo(ClkHICR);
    Clk_SetHICRFreq(ClkHICR4Mhz);


    if (TRUE == bNvic)
    {
        ClkDisableNvic();
    }

    return Ok;
}


/**
 *****************************************************************************
 ** \brief Clk_Enable 
 **          enable/disalbe to a paticular clock input
 **  
 ** \param   [in]  enSource  clock source
 ** \param   [in]  u8Flag    TRUE:       enable
 **                          FALSE:      disable
 ** \retval  en_result_t     Ok:         operation done.
 **                          ErrorInvalidParameter: invalid source type
 *****************************************************************************/
en_result_t Clk_Enable(en_clk_source_t enSource, boolean_t bFlag)
{
    en_result_t enRet = Ok;

    ASSERT(IS_VALID_SRC(enSource));

    bFlag = bFlag & 1;
    switch (enSource)
    {
        case ClkHICR:
            M0P_CLOCK->CTRL_f.HC_EN = bFlag;
            break;
        case ClkHSXT:
            M0P_WSUNIT->BGR_CTL_f.BGR_EN = 1;
            M0P_FLASH->FWCICR_f.FWTC = 0;

            if (CLK_HSXT_VAL >= 20000000)                   //> 20M
            {
                M0P_FLASH->FWCICR_f.FWTC = 1;
                M0P_OSC->HSXT_PWRCTL_f.HXSEL = 3;
            } else if (CLK_HSXT_VAL >= 12000000)            // > 12M
            {
                M0P_OSC->HSXT_PWRCTL_f.HXSEL = 2;
            } else if (CLK_HSXT_VAL >= 6000000)             // > 12M
            {
                M0P_OSC->HSXT_PWRCTL_f.HXSEL = 1;           // >6M
            } else
            {
                M0P_OSC->HSXT_PWRCTL_f.HXSEL = 0;           //4M
            }
            M0P_CLOCK->CTRL_f.MAIN_EN = bFlag;
            break;

        case ClkLSXT:
            M0P_CLOCK->CTRL_f.SUB_EN = bFlag;
            break;
        case ClkLICR:
        default:
            enRet = ErrorInvalidParameter;
            break;
    }
    return enRet;
}


/**
 ******************************************************************************
 ** \brief Clk_SetSource 
 **        set input clock source that switch to.
 ** 
 ** \param [IN] enSource    : 
 ** 
 ** \param   [in]  enSource         the target clock source
 **
 ** \retval  en_result_t            Ok: set done
 **                                 ErrorInvalidParamet: enSource is invalid
 ******************************************************************************/
en_result_t Clk_SetSource(en_clk_source_t enSource)
{
    en_result_t enRet = Ok;

    ASSERT(IS_VALID_SRC(enSource));

    switch (enSource)
    {
        case ClkHSXT:
        case ClkHICR:
        case ClkLICR:
        case ClkLSXT:
            M0P_CLOCK->CTRL_f.INPUT = enSource;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }
    return enRet;
}

/**
 * \brief   Clk_GetClkRdy
 *
 * \param   [in]  enSource           
 *
 * \retval  en_result_t             
 */

/**
 ******************************************************************************
 ** \brief Clk_GetClkRdy 
 **        check if the #enSource clock is ready.
 ** 
 ** \param [IN] enSource    : clock source
 ** 
 ** \retval boolean_t       TRUE:   target clock is ready
 **                         FALSE:  target clock is not ready
 **                                  enSource is invalid
 ******************************************************************************/
boolean_t Clk_GetClkRdy(en_clk_source_t enSource)
{
    boolean_t bFlag = FALSE;

    ASSERT(IS_VALID_SRC(enSource));

    switch (enSource)
    {
        case ClkHICR:
            bFlag = M0P_CLOCK->CLK_STB_f.HC_RDY;
            break;
        case ClkHSXT:
            bFlag = M0P_CLOCK->CLK_STB_f.MAIN_RDY;
            break;
        case ClkLSXT:
            bFlag = M0P_CLOCK->CLK_STB_f.SUB_RDY;
            break;
        case ClkLICR:
            //dummy case
            bFlag = TRUE;
            break;
        default:
            break;
    }
    return bFlag;
}


/**
 ******************************************************************************
 ** \brief Clk_GetCurSource 
 **        before use the new clock source, check the new clock soruce is valid
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_clk_source_t  : the current clock source
 ******************************************************************************/
en_clk_source_t Clk_GetCurSource(void)
{
    return (en_clk_source_t)M0P_CLOCK->CLK_STB_f.SRC;
}


/**
 ******************************************************************************
 ** \brief Clk_EnableAPB1 
 **        enable/ disable apb1 bus
 ** 
 ** \param [IN] bFlag   :   enable /disable 
 ** 
 ** \retval en_result_t     OK:   set done.
 ******************************************************************************/
en_result_t Clk_EnableAPB1(boolean_t bFlag)
{
    M0P_CLOCK->APB1_CTRL_f.EN = bFlag;
    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_SetHICRFreq 
 **        set high cr source frequency.
 ** 
 ** \param [IN] enVal   :       high cr frequency value enumeration
 ** 
 ** \retval en_result_t :       Ok: set done
 **                             ErrorInvalidParameter: invalid enVal
 ******************************************************************************/
en_result_t Clk_SetHICRFreq(en_clk_hicrfreq_t enVal)
{
    en_result_t enRet = Ok;

    switch (enVal)
    {
        case ClkHICR2Mhz:
        case ClkHICR4Mhz:
        case ClkHICR8Mhz:
        case ClkHICR16Mhz:
            M0P_OSC->HICR_FMC_f.FMC = (uint8_t)enVal;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Clk_GetResetCause 
 **        get the chip reset reason
 ** 
 ** \param   [out]  pstcData         Pointer to return data structure.
 **
 ** \retval  en_result_t             Ok:        get data done
 **                                  ErrorInvalidParameter: pstcData is NULL
 ******************************************************************************/
en_result_t Clk_GetResetCause(stc_clk_rstcause_t *pstcData)
{
    stc_clock_stat_field_t stcStat;

    ASSERT(NULL != pstcData);

    stcStat = M0P_CLOCK->STAT_f;

    pstcData->bSoftware = stcStat.SW;
    pstcData->bAFreq = stcStat.AF;
    pstcData->bCSV = stcStat.CSV;
    pstcData->bHwwdg = stcStat.HWWDG;
    pstcData->bSwwdg = stcStat.SWWDG;
    pstcData->bLVD = stcStat.LVDR;
    pstcData->bRstPin = stcStat.RSTB;
    pstcData->bPowerOn = stcStat.PWR;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_EnableFunc 
 **        enable a clk peripheral funciton see #en_clk_func_t for function
 **        list.
 ** 
 ** \param [IN] enFunc  :  function enum index
 ** 
 ** \retval  Ok      :set done
 **          others  :set failed.
 ******************************************************************************/
en_result_t Clk_EnableFunc(en_clk_func_t enFunc)
{
    return ClkEnableFunc(enFunc, TRUE);
}


/**
 ******************************************************************************
 ** \brief Clk_DisableFunc 
 **        disable a clk peripheral funciton see #en_clk_func_t for function
 **        list.
 ** 
 ** \param [IN] enFunc  :               funciton event enumeration
 ** 
 ** \retval     Ok:                     disable done.
 **             ErrorInvalidParameter:  enFunc is invaild
 ******************************************************************************/
en_result_t Clk_DisableFunc(en_clk_func_t enFunc)
{
    return ClkEnableFunc(enFunc, FALSE);
}


/**
 ******************************************************************************
 ** \brief Clk_SetSwwdgDiv 
 **        set software watchdog clock frequency division
 ** 
 ** \param [IN] enDiv   :       input clock division
 ** 
 ** \retval     Ok: set done
 **             ErrorInvalidParameter: enDiv is invalid 
 ******************************************************************************/
en_result_t Clk_SetSwwdgDiv(en_clk_swwdg_div_t  enDiv)
{
    ASSERT(enDiv <= ClkDiv8);

    M0P_CLOCK->CLK_CTL_f.SWDS = enDiv;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_FcsInit 
 **        Clk_Fcs init
 ** 
 ** \param [IN] pstcCfg :  pointer to pstc configure data structure.
 ** 
 ** \retval Ok:     init done
 **         others: init failed
 ******************************************************************************/
en_result_t Clk_FcsInit(stc_clk_fcs_config_t *pstcCfg)
{
    stc_clock_fcm_ctl_field_t stcCfg;
    stc_clk_fcs_irq_sel_t   *pstcFcsIrqSel;
    stc_clk_fcs_irq_cb_t    *pstcFcsIrqCb;

    ASSERT(NULL != pstcCfg);
    ASSERT(IS_VALID_FCSDIV(pstcCfg->enFcsDiv));

    DDL_ZERO_STRUCT(stcCfg);

    stcCfg.AFDCC = pstcCfg->enFcsDiv;
    stcCfg.AFDRE = pstcCfg->bFcsResetEn;
    stcCfg.AFDE = pstcCfg->bFcsEn;
    stcCfg.SFCMRE = pstcCfg->bLSXTFailResetEn;
    stcCfg.MFCMRE = pstcCfg->bHSXTFailResetEn;
    stcCfg.SFCME = pstcCfg->bLSXTFailDetectEn;
    stcCfg.MFCME = pstcCfg->bHSXTFailDetectEn;

    M0P_CLOCK->FCM_CTL_f = stcCfg;

    if (NULL != pstcCfg->pstcFcsIrqCb)
    {
        pstcFcsIrqCb = pstcCfg->pstcFcsIrqCb;
        pfnFcsCallback = pstcFcsIrqCb->pfnFcsIrqCb;
        pfnHSXTFailCallback = pstcFcsIrqCb->pfnHSXTFailIrqCb;
        pfnLSXTFailCallback = pstcFcsIrqCb->pfnLSXTFailIrqCb;
    }

    if (NULL != pstcCfg->pstcFcsIrqSel)
    {
        pstcFcsIrqSel = pstcCfg->pstcFcsIrqSel;

        M0P_CLOCK->INT_CTRL_f.FCSEN = pstcFcsIrqSel->bFcsIrqEn;
        M0P_CLOCK->INT_CTRL_f.MCSVIE = pstcFcsIrqSel->bHSXTFailIrqEn;
        M0P_CLOCK->INT_CTRL_f.SUBEN = pstcFcsIrqSel->bLSXTFailIrqEn;

        ClkFcsEnableNvic();
    }

    return Ok;
}

/**
 ******************************************************************************
 ** \brief Clk_FcsDeInit 
 **        Clk_Fcs deinit
 ** 
 ** \param [IN]   :  
 ** 
 ** \retval Ok:     deinit done
 ******************************************************************************/
en_result_t Clk_FcsDeInit(void)
{
    ClkFcsDisableNvic();
    pfnFcsCallback = NULL;
    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_SetFcsDiv 
 **        set FCS input clock division
 ** 
 ** \param [IN] enDiv   :           division value enum
 ** 
 ** \retval en_result_t             Ok: set done.
 **                                 ErrorInvalidParameter: enDiv is invalid
 ******************************************************************************/
en_result_t Clk_SetFcsDiv(en_clk_fcs_div_t enDiv)
{
    ASSERT(IS_VALID_FCSDIV(enDiv));

    M0P_CLOCK->FCM_CTL_f.AFDCC = enDiv;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_GetFcsStat 
 **        get FCS status
 ** 
 ** \param [IN] enType  :       fcs type
 ** 
 **  \retval boolean_t   TRUE:      status is valid
 **                      FALSE:     status is invalid
 **                                 enType is invalid
 ******************************************************************************/
boolean_t Clk_GetFcsStat(en_clk_fcs_stat_t enType)
{
    boolean_t bFlag = FALSE;

    ASSERT(IS_VALID_FCSSTAT(enType));

    switch (enType)
    {
        case ClkCsvHSXT:
            bFlag = M0P_CLOCK->FCM_STR_f.MCFDF;
            break;
        case ClkCsvLSXT:
            bFlag = M0P_CLOCK->FCM_STR_f.SCFDF;
            break;
        default:
            break;
    }

    return bFlag;
}


/**
 ******************************************************************************
 ** \brief Clk_SetFcsWindow 
 **        set fcs detect range.
 ** 
 ** \param [IN] u16Low  :   window upper value
 ** \param [IN] u16High :   window lower value
 ** 
 ** \retval en_result_t     Ok: Set done
 ******************************************************************************/
en_result_t Clk_SetFcsWindow(uint16_t u16Low, uint16_t u16High)
{
    M0P_CLOCK->AFDWH_CTL = u16High;
    M0P_CLOCK->AFDWL_CTL = u16Low;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Clk_GetFcsFreq 
 **        
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval uint16_t    fcs frequency
 ******************************************************************************/
uint16_t Clk_GetFcsFreq(void)
{
    return M0P_CLOCK->AFDC_CTL;
}


/**
 ******************************************************************************
 ** \brief Clk_EnableIrq 
 **        
 ** 
 ** \param [IN] enSel   : irq interrupt factor index
 ** 
 ** \retval en_result_t  Ok:  done.
 **                      others: failed.
 ******************************************************************************/
en_result_t Clk_EnableIrq(en_clk_irq_sel_t enSel)
{
    return ClkEnableIrq(enSel, TRUE);
}


/**
 ******************************************************************************
 ** \brief Clk_DisableIrq 
 **        
 ** 
 ** \param [IN] enSel   :   irq interrupt factor index
 ** 
 ** \retval en_result_t     Ok:  done.
 **                         others: failed.
 ******************************************************************************/
en_result_t Clk_DisableIrq(en_clk_irq_sel_t enSel)
{
    return ClkEnableIrq(enSel, FALSE);
}


/**
 ******************************************************************************
 ** \brief Clk_GetIrqStat 
 **        get irq factor status
 ** 
 ** \param [IN] enSel   : irq interrupt factor index
 ** 
 ** \retval boolean_t  #enSel factor status
 ******************************************************************************/
boolean_t Clk_GetIrqStat(en_clk_irq_sel_t enSel)
{
    boolean_t bRet = FALSE;

    ASSERT(IS_VALID_IRQ(enSel));

    switch (enSel)
    {
        case ClkIrqFcs:
            bRet = M0P_CLOCK->INT_PEND_f.FCS;
            break;
        case ClkIrqHSXT:
            bRet = M0P_CLOCK->INT_PEND_f.MCSVI;
            break;
        case ClkIrqHSXTrRdy:
            bRet = M0P_CLOCK->INT_PEND_f.MAIN;
            break;
        case ClkIrqLSXT:
            bRet = M0P_CLOCK->INT_PEND_f.SCSVI;
            break;
        case ClkIrqLSXTRdy:
            bRet = M0P_CLOCK->INT_PEND_f.SUB;
            break;
        default:
            ;
            break;
    }

    return bRet;

}

/**
 ******************************************************************************
 ** \brief Clk_ClearIrq 
 **        clear a clock interrupt factor.
 ** 
 ** \param [IN] enSel   : irq interrupt factor index
 ** 
 ** \retval en_result_t Ok: done
 **                     others: failed
 ******************************************************************************/
en_result_t Clk_ClearIrq(en_clk_irq_sel_t enSel)
{
    en_result_t enRet = Ok;
    switch (enSel)
    {
        case ClkIrqFcs:
            M0P_CLOCK->INT_CLR_f.FCS = TRUE;
            break;
        case ClkIrqHSXT:
            M0P_CLOCK->INT_CLR_f.MCSVC = TRUE;
            break;
        case ClkIrqHSXTrRdy:
            M0P_CLOCK->INT_CLR_f.MAIN = TRUE;
            break;
        case ClkIrqLSXT:
            M0P_CLOCK->INT_CLR_f.SCSVC = TRUE;
            break;
        case ClkIrqLSXTRdy:
            M0P_CLOCK->INT_CLR_f.SUB = TRUE;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}
//@} // Clk Functions

/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/


