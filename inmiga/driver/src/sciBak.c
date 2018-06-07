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
/** \file sci.c
 **
 ** SCI driver define.
 ** @link SCI Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "sci.h"

/**
 ******************************************************************************
 ** \addtogroup SciGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define     IS_VALID_EN(x)              ((TRUE == (x)) || (FALSE == (x)))
#define     IS_VALID_IRQSEL(x)          (SciWakeupIrq >= (x))
#define     IS_VALID_MODE(x)            ((SciT0Mode == (x)) || (SciT1Mode == (x)))
#define     IS_VALID_PARITY(x)          ((SciParityEven == (x)) || (SciParityOdd == (x)))
#define     IS_VALID_DIR(x)             ((SciDataLsbFirst == (x)) || (SciDataMsbFirst == (x)))
#define     IS_VALID_CLOCK(x)           (SciClockDiv8 >= (x))
#define     IS_VALID_STATUS(x)          (SciRxErr >= (x))
#define     IS_VALID_FIFOSTATUS(x)      (SciFifoRxEpt >= (x))
#define     IS_VALID_IRQSTATUS(x)       (SciWakeupInt >= (x))
#define     IS_VALID_F1CYCLE(x)         (7u >= (x))

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
/// SCI instance data type
typedef struct stc_sci_instance_data
{
    M0P_SCI_TypeDef       *pstcInstance;      ///< pointer to registers of an instance
    stc_sci_irq_cb_t      stcSciInternIrqCb;  ///< module internal data of instance
} stc_sci_instance_data_t;

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/ 

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static stc_sci_irq_cb_t stcSciIrqCb;

/******************************************************************************/
/* Function implementation - global ('extern') and local ('static')           */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief Device dependent initialization of transmit interrupts
 **
 **
 ******************************************************************************/
static void SciInitNvic(void)
{
    NVIC_ClearPendingIRQ(SCI_IRQn);
    NVIC_EnableIRQ(SCI_IRQn);
    NVIC_SetPriority(SCI_IRQn, DDL_IRQ_LEVEL_SCI);
} /* SciInitNvic */
   
/**
 ******************************************************************************
 *  \brief Device dependent de-initialization of interrupt
 *         according CMSIS
 **
 ******************************************************************************/
static void SciDeInitNvic(void)
{
    NVIC_ClearPendingIRQ(SCI_IRQn);
    NVIC_DisableIRQ(SCI_IRQn);
    NVIC_SetPriority(SCI_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/******************************************************************************
 * SCI driver functions
 ******************************************************************************/  

/**
 ******************************************************************************
 ** \brief SCI receive interrupt service routine.
 ** 
 ** This function is called on Interrupt set by the SCI. 
 **
 ******************************************************************************/
void Sci_IrqHandler(void)
{
    if(1u == M0P_SCI->STATUS_f.TX_FIN)
    {
        if(NULL != stcSciIrqCb.pfnTxIrqCb)
        {
            stcSciIrqCb.pfnTxIrqCb();
        }
    }
    if(1u == M0P_SCI->STATUS_f.RX_FIN)
    {
        if(NULL != stcSciIrqCb.pfnRxIrqCb)
        {
            stcSciIrqCb.pfnRxIrqCb();
        }
    }
    if(1u == M0P_SCI->STATUS_f.ETU_CNT_FIN)
    {
        if(NULL != stcSciIrqCb.pfnEtuCntIrqCb)
        {
            stcSciIrqCb.pfnEtuCntIrqCb();
        }
    }
    if(1u == M0P_SCI->WAKEUP_INT_f.WAKEUP_INT)
    {
        if(NULL != stcSciIrqCb.pfnWakeupIrqCb)
        {
            stcSciIrqCb.pfnWakeupIrqCb();
        }
    }
} /* SciIrqHandler */

/**
 ******************************************************************************
 ** \brief Enable one interrupt source of SCI 
 **
 ** \param [in] enIrqSel   Pointer to the selection structure of UART interrupt
 ** \arg SciTxIrq         SCI TX interrupt
 ** \arg SciRxIrq         SCI RX interrupt
 ** \arg SciEtuCntIrq     SCI ETU count interrupt
 ** \arg SciWakeupIrq     SCI wakeup interrupt
 **
 ** \retval Ok                    Interrupts has been enabled
 ** \retval ErrorInvalidParameter                   
 ** 
 ******************************************************************************/
en_result_t Sci_EnableIrq(en_sci_irq_sel_t enIrqSel)
{
    ASSERT(IS_VALID_IRQSEL(enIrqSel));
    
    switch (enIrqSel)
    {
        case SciTxIrq:
            M0P_SCI->INT_EN_f.INT_EN = 1u;
            break;
        case SciRxIrq:
            M0P_SCI->INT_EN_f.INT_EN = 1u;
            break;
        case SciEtuCntIrq:
            M0P_SCI->INT_EN_f.ETU_CNT_INT_EN = 1u;
            break;
        case SciWakeupIrq:
            M0P_SCI->INT_EN_f.WAKEUP_INT_EN = 1u;
            break;
        default:
            return (ErrorInvalidParameter);
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Disable one interrupt source of SCI 
 **
 ** \param [in] enIrqSel   Pointer to the selection structure of UART interrupt
 ** \arg SciTxIrq         SCI TX interrupt
 ** \arg SciRxIrq         SCI RX interrupt
 ** \arg SciEtuCntIrq     SCI ETU count interrupt
 ** \arg SciWakeupIrq     SCI wakeup interrupt
 **
 ** \retval Ok                    Interrupts has been enabled
 ** \retval ErrorInvalidParameter                   
 ** 
 ******************************************************************************/
en_result_t Sci_DisableIrq(en_sci_irq_sel_t enIrqSel)
{
    ASSERT(IS_VALID_IRQSEL(enIrqSel));
    
    switch (enIrqSel)
    {
        case SciTxIrq:
            M0P_SCI->INT_EN_f.INT_EN = 0u;
            break;
        case SciRxIrq:
            M0P_SCI->INT_EN_f.INT_EN = 0u;
            break;
        case SciEtuCntIrq:
            M0P_SCI->INT_EN_f.ETU_CNT_INT_EN = 0u;
            break;
        case SciWakeupIrq:
            M0P_SCI->INT_EN_f.WAKEUP_INT_EN = 0u;
            break;
        default:
            return (ErrorInvalidParameter);
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Initialization of a SCI module.
 **
 ** Set registers to active SCI.
 **
 ** \param [in]   pstcConfig      SCI configuration
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter     
 **
 ******************************************************************************/
en_result_t Sci_Init(stc_sci_config_t* pstcConfig)
{
    stc_sci_mode_field_t stcMode = { 0 };
    stc_sci_con_field_t stcCon = { 0 };

    ASSERT(IS_VALID_MODE(pstcConfig->enTMode));
    ASSERT(IS_VALID_EN(pstcConfig->bParity));
    ASSERT(IS_VALID_PARITY(pstcConfig->enParity));
    ASSERT(IS_VALID_DIR(pstcConfig->enBitDirection));
    ASSERT(IS_VALID_EN(pstcConfig->bDataResend));
    
    //Transmit mode set
    if(TRUE == pstcConfig->enTMode)
    {
        stcMode.T_MODE = 1u;
    }
    else
    {
        stcMode.T_MODE = 0u;
    }
    
    //baudrate set
    if(pstcConfig->u16BaudRate)
    {      
      Sci_SetBaudRate(pstcConfig->u16BaudRate);
    }
    
    //parity mode set
    if(TRUE == pstcConfig->bParity)
    {
        stcCon.PARITY_CHECK_EN = 1u;
        if(SciParityOdd == pstcConfig->enParity)
        {
            stcMode.PARITY = SciParityOdd;
        }
        if(SciParityEven == pstcConfig->enParity)
        {
            stcMode.PARITY = SciParityEven;
        }
        //Resend set
        if(TRUE == pstcConfig->bDataResend)
        {
            stcCon.RETRY_EN = 1u;
            stcMode.RETRY_TIMES = pstcConfig->u8ResendTimes;
        }
        else
        {
            stcCon.RETRY_EN = 0u;
        }    
    }
    else
    {
        stcCon.PARITY_CHECK_EN = 0u;
    }
    
    
    
    //Bit direction set
    if(SciDataLsbFirst == pstcConfig->enBitDirection)
    {
        stcMode.CDCVT = SciDataLsbFirst;
    }
    if(SciDataMsbFirst == pstcConfig->enBitDirection)
    {
        stcMode.CDCVT = SciDataMsbFirst;
    }
    
    /* Set the registers */
    M0P_SCI->CON_f = stcCon;
    M0P_SCI->MODE_f = stcMode;
    
    /* Configue interrupts */
    if(NULL != pstcConfig->pstcIrqEn)
    {
        if(TRUE == pstcConfig->pstcIrqEn->bTxIrq)
        {
            M0P_SCI->INT_EN_f.INT_EN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bRxIrq)
        {
            M0P_SCI->INT_EN_f.INT_EN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bEtuCntIrq)
        {
            M0P_SCI->INT_EN_f.ETU_CNT_INT_EN = 1u;
        }
        if(TRUE == pstcConfig->pstcIrqEn->bWakeupIrq)
        {
            M0P_SCI->INT_EN_f.WAKEUP_INT_EN = TRUE;
        }
    }
    
    /* Configure callback functions */
    if(NULL != pstcConfig->pstcIrqCb)
    {
        stcSciIrqCb.pfnTxIrqCb = pstcConfig->pstcIrqCb->pfnTxIrqCb;
        stcSciIrqCb.pfnRxIrqCb = pstcConfig->pstcIrqCb->pfnRxIrqCb;
        stcSciIrqCb.pfnEtuCntIrqCb = pstcConfig->pstcIrqCb->pfnEtuCntIrqCb;
        stcSciIrqCb.pfnWakeupIrqCb = pstcConfig->pstcIrqCb->pfnWakeupIrqCb;
    }
    
    /* Configure NVIC */
    if(TRUE == pstcConfig->bTouchNvic)
    {
        SciInitNvic();
    }
    
    return Ok;
}

/**
 *****************************************************************************
 ** \brief De-Initialize SCI
 **
 ** This function de-initializes the SCI.
 ** Sci-DeInit() accesses the SCI hardware register. They are reset.
 **
 ** \param [in]  bTouchNvic       Touch NVIC or not
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter 
 **
 *****************************************************************************/
en_result_t Sci_DeInit(boolean_t bTouchNvic)
{
    en_result_t            enResult  = Ok;

    M0P_SCI->MODE = 0u;
    M0P_SCI->CON = 0u;
    M0P_SCI->CLK_RST = 0u;
    M0P_SCI->INT_EN = 0u;
    M0P_SCI->SBDR = 372u;
    M0P_SCI->ETU_CNT = 9600u;
    
    /* Clear callback */
    stcSciIrqCb.pfnEtuCntIrqCb = NULL;
    stcSciIrqCb.pfnRxIrqCb = NULL;
    stcSciIrqCb.pfnTxIrqCb = NULL;
    stcSciIrqCb.pfnWakeupIrqCb = NULL;

    if (bTouchNvic == TRUE)
    {
        SciDeInitNvic();
    }

    return (enResult);

}

/**
 ******************************************************************************
 ** \brief Enable SCI function.
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_Enable(void)
{
    M0P_SCI->CON_f.EN = 1u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Enable SCI function.
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_Disable(void)
{
    M0P_SCI->CON_f.EN = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Set SCI clock division.
 **
 ** \param [in] en_sci_clk_t     SCI clock prescaler
 ** \arg   SciClockNoDiv    PCLK
 ** \arg   SciClockDiv2     PCLK/2
 ** \arg   SciClockDiv4     PCLK/4
 ** \arg   SciClockDiv8     PCLK/8
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_SetClock(en_sci_clk_t enSciClock)
{
    ASSERT(IS_VALID_CLOCK(enSciClock));
    
    M0P_SCI->CLK_RST_f.CLK_SEL = enSciClock;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Enable SCI clock function.
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_EnableClock(void)
{
    M0P_SCI->CLK_RST_f.CLK_EN = 1u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Disable SCI clock function.
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_DisableClock(void)
{
    M0P_SCI->CLK_RST_f.CLK_EN = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Set SCI baud rate.
 ** 
 ** \param [in] u16BaudRate     SCI communication baud rate
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_SetBaudRate(uint16_t u16BaudRate)
{
    M0P_SCI->SBDR_f.SBDR = u16BaudRate;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Init the Sci statusby cleaning all.
 ** 
 ** \retval Ok                    Function has been enabled normally
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_InitStatus(void)
{
    M0P_SCI->STATUS = 0x00;
    
    return Ok;    
}

/**
 ******************************************************************************
 ** \brief Get status of SCI according to status type
 **
 ** \param [in] enStatus     SCI status type
 ** \arg   SciRxStartNs      SCI start bit noise flag
 ** \arg   SciOverrun        SCI receive over run flag
 ** \arg   SciBusy           SCI in work flag
 ** \arg   SciTxErr          SCI transmit error flag
 ** \arg   SciRxErr          SCI receive error flag
 ** 
 ** \retval FALSE                 If one of following conditions are met:
 **                               - No SCI first bit noise detected [enStatus = SciRxStartNs]
 **                               - No SCI receive over run error [enStatus = SciOverrun]     
 **                               - SCI not in work [enStatus = SciBusy]
 **                               - No SCI transmit error [enStatus = SciTxErr]
 **                               - No SCI receive error [enStatus = SciRxError]
 ** \retval TRUE                 If one of following conditions are met:
 **                               - SCI first bit noise detected [enStatus = SciRxStartNs]
 **                               - SCI receive over run error [enStatus = SciOverrun]    
 **                               - SCI in work [enStatus = SciBusy]
 **                               - SCI transmit error [enStatus = SciTxErr]
 **                               - SCI receive error [enStatus = SciRxError]
 ** 
 ******************************************************************************/
boolean_t Sci_GetStatus(en_sci_status_t enStatus)
{
    boolean_t bResult = FALSE;

    ASSERT(IS_VALID_STATUS(enStatus));
    
    switch(enStatus)
    {
        case SciRxStartNs:
            bResult = (M0P_SCI->STATUS_f.RX_NE == 1u) ? TRUE : FALSE;
            break;  
        case SciOverrun:
            bResult = (M0P_SCI->STATUS_f.RX_OVR == 1u) ? TRUE : FALSE;
            break;  
        case SciBusy:
            bResult = (M0P_SCI->STATUS_f.STAT == 1u) ? TRUE : FALSE;
            break;  
        case SciTxErr:
            bResult = (M0P_SCI->STATUS_f.TX_ERR == 1u) ? TRUE : FALSE;
            break;  
        case SciRxErr:
            bResult = (M0P_SCI->STATUS_f.RX_ERR == 1u) ? TRUE : FALSE;
            break;  
        default:
            break;  
    }
    
    return bResult;
}

/**
 ******************************************************************************
 ** \brief Clear status of SCI according to status type
 **
 ** \param [in] enStatus     SCI status type
 ** \arg   SciRxStartNs      SCI start bit noise flag
 ** \arg   SciOverrun        SCI receive over run flag
 ** \arg   SciBusy           SCI in work flag
 ** \arg   SciTxErr          SCI transmit error flag
 ** \arg   SciRxErr          SCI receive error flag
 ** 
 ** \retval Ok                    Status has been cleared normally
 ** \retval ErrorInvalidParameter 
 ** 
 ** 
 ** Note: SciRxStartNs/SciOverrun/SciBusy status can't be cleared
 ** 
 ******************************************************************************/
en_result_t Sci_ClearStatus(en_sci_status_t enStatus)
{
    ASSERT(IS_VALID_STATUS(enStatus));
    
    switch(enStatus)
    {
        case SciRxStartNs:
        case SciOverrun:
        case SciBusy:
            break;
        case SciTxErr:
            M0P_SCI->STATUS_f.TX_ERR = 0u;
            break;
        case SciRxErr:
            M0P_SCI->STATUS_f.RX_ERR = 0u;
            break;
        default:
            return ErrorInvalidParameter;  
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Get FIFO status of SCI according to status type
 **
 ** \param [in] enStatus     SCI FIFO status type
 ** \arg   SciFifoTxOvr      SCI TX FIFO over run
 ** \arg   SciFifoTxUdr      SCI TX FIFO under run
 ** \arg   SciFifoTxFul      SCI TX FIFO full
 ** \arg   SciFifoTxEpt      SCI TX FIFO empty
 ** \arg   SciFifoRxOvr      SCI RX FIFO over run
 ** \arg   SciFifoRxUdr      SCI RX FIFO under run
 ** \arg   SciFifoRxFul      SCI RX FIFO full
 ** \arg   SciFifoRxEpt      SCI RX FIFO empty
 ** 
 ** \retval FALSE                 If one of following conditions are met:
 **                               - No Transmit FIFO over run
 **                               - No Transmit FIFO under run
 **                               - No Transmit FIFO full
 **                               - No Transmit FIFO empty
 **                               - No Receive FIFO over run
 **                               - No Receive FIFO under run
 **                               - No Receive FIFO full
 **                               - No Receive FIFO empty
 ** \retval TRUE                 If one of following conditions are met:
 **                               - Transmit FIFO over run
 **                               - Transmit FIFO under run
 **                               - Transmit FIFO full
 **                               - Transmit FIFO empty
 **                               - Receive FIFO over run
 **                               - Receive FIFO under run
 **                               - Receive FIFO full
 **                               - Receive FIFO empty
 ** 
 ******************************************************************************/
boolean_t Sci_GetFifoStatus(en_sci_fifo_status_t enStatus)
{
    boolean_t bResult = FALSE;

    ASSERT(IS_VALID_FIFOSTATUS(enStatus));
        
    switch(enStatus)
    {
        case SciFifoTxOvr:
            bResult = (M0P_SCI->FIFO_STATUS_f.TX_EPT == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoTxUdr:
            bResult = (M0P_SCI->FIFO_STATUS_f.TX_UDR == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoTxFul:
            bResult = (M0P_SCI->FIFO_STATUS_f.TX_FUL == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoTxEpt:
            bResult = (M0P_SCI->FIFO_STATUS_f.TX_EPTB == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoRxOvr:
            bResult = (M0P_SCI->FIFO_STATUS_f.RX_OVR == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoRxUdr:
            bResult = (M0P_SCI->FIFO_STATUS_f.RX_UDR == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoRxFul:
            bResult = (M0P_SCI->FIFO_STATUS_f.RX_FUL == 1u) ? TRUE : FALSE;
            break;  
        case SciFifoRxEpt:
            bResult = (M0P_SCI->FIFO_STATUS_f.RX_EPTB == 1u) ? TRUE : FALSE;
            break;  
        default:
            break;  
    }
    
    return bResult;
}

/**
 ******************************************************************************
 ** \brief Clear FIFO status of SCI according to status type
 **
 ** \param [in] enStatus     SCI FIFO status type
 ** \arg   SciFifoTxOvr      SCI TX FIFO over run
 ** \arg   SciFifoTxUdr      SCI TX FIFO under run
 ** \arg   SciFifoTxFul      SCI TX FIFO full
 ** \arg   SciFifoTxEpt      SCI TX FIFO empty
 ** \arg   SciFifoRxOvr      SCI RX FIFO over run
 ** \arg   SciFifoRxUdr      SCI RX FIFO under run
 ** \arg   SciFifoRxFul      SCI RX FIFO full
 ** \arg   SciFifoRxEpt      SCI RX FIFO empty
 ** 
 ** \retval Ok                    Status has been cleared normally
 ** \retval ErrorInvalidParameter 
 ** 
 ** 
 ** 
 ******************************************************************************/
en_result_t Sci_ClearFifoStatus(en_sci_fifo_status_t enStatus)
{
    ASSERT(IS_VALID_FIFOSTATUS(enStatus));
        
    switch(enStatus)
    {
        case SciFifoTxOvr:
        case SciFifoTxUdr:
        case SciFifoTxFul:
        case SciFifoTxEpt:
            M0P_SCI->CON_f.TX_FIFO_CLR = 1u;
            break;
        case SciFifoRxOvr:
        case SciFifoRxUdr:
        case SciFifoRxFul:
        case SciFifoRxEpt:
            M0P_SCI->CON_f.RX_FIFO_CLR = 1u;
            break;
        default:
            return ErrorInvalidParameter;  
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Get IRQ status of SCI according to status type
 **
 ** \param [in] enStatus     SCI status type
 ** \arg   SciTxFinInt       SCI TX finish
 ** \arg   SciRxFinInt       SCI RX finish
 ** \arg   SciEtuCntInt      SCI ETU count match
 ** \arg   SciWakeupInt      SCI wakeup
 ** 
 ** \retval FALSE                 If one of following conditions are met:
 **                               - No SCI first bit noise detected [enStatus = SciRxStartNs]
 **                               - No SCI receive over run error [enStatus = SciOverrun]     
 **                               - SCI not in work [enStatus = SciBusy]
 **                               - No SCI transmit error [enStatus = SciTxErr]
 **                               - No SCI receive error [enStatus = SciRxError]
 ** \retval TRUE                 If one of following conditions are met:
 **                               - SCI TX finish interrupt
 **                               - SCI RX finish interrupt
 **                               - SCI ETU count match interrupt
 **                               - SCI wakeup interrupt
 ** 
 ******************************************************************************/
boolean_t Sci_GetIrqStatus(en_sci_irq_status_t enStatus)
{
    boolean_t bResult = FALSE;

    ASSERT(IS_VALID_IRQSTATUS(enStatus));
        
    switch(enStatus)
    {
        case SciTxFinInt:
            bResult = (M0P_SCI->STATUS_f.TX_FIN == 1u) ? TRUE : FALSE;
            break;  
        case SciRxFinInt:
            bResult = (M0P_SCI->STATUS_f.RX_FIN == 1u) ? TRUE : FALSE;
            break;  
        case SciEtuCntInt:
            bResult = (M0P_SCI->STATUS_f.ETU_CNT_FIN == 1u) ? TRUE : FALSE;
            break;  
        case SciWakeupInt:
            bResult = (M0P_SCI->WAKEUP_INT_f.WAKEUP_INT == 1u) ? TRUE : FALSE;
            break;  
        default:
            break;  
    }
    
    return bResult;
}

/**
 ******************************************************************************
 ** \brief Clear Irq status of SCI according to status type
 **
 ** \param [in] enStatus     SCI IRQ status type
 ** \arg   SciTxFinInt       SCI TX finish
 ** \arg   SciRxFinInt       SCI RX finish
 ** \arg   SciEtuCntInt      SCI ETU count match
 ** \arg   SciWakeupInt      SCI wakeup
 ** 
 ** \retval Ok                    Status has been cleared normally
 ** \retval ErrorInvalidParameter 
 ** 
 ** 
 ** 
 ******************************************************************************/
en_result_t Sci_ClearIrqStatus(en_sci_irq_status_t enStatus)
{
    ASSERT(IS_VALID_IRQSTATUS(enStatus));
        
    switch(enStatus)
    {
        case SciTxFinInt:
            M0P_SCI->STATUS_f.TX_FIN = 0u;
            break;
        case SciRxFinInt:
            M0P_SCI->STATUS_f.RX_FIN = 0u;
            break;
        case SciEtuCntInt:
            M0P_SCI->STATUS_f.ETU_CNT_FIN = 0u;
            break;
        case SciWakeupInt:
            M0P_SCI->WAKEUP_INT_f.WAKEUP_INT = 0u;
            break;
        default:
            return ErrorInvalidParameter;  
    }
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Write SCI data buffer
 **
 ** \param [in] u8Data    Send data
 ** 
 ** \retval Ok                    Data has been successfully sent
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_SendData(uint8_t u8Data)
{
    M0P_SCI->DATA = u8Data;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Read SCI data buffer
 **
 ** \retval Receive data        
 ** 
 ******************************************************************************/
uint8_t Sci_ReceiveData(void)
{    
    return (M0P_SCI->DATA);
}

/**
 ******************************************************************************
 ** \brief Write SCI EDC data buffer
 **
 ** \param [in] u16Data    Send EDC data
 ** 
 ** \retval Ok                    Data has been successfully sent
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_SendEdcData(uint16_t u16Data)
{
    M0P_SCI->EDC_DATA = u16Data;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Read SCI EDC data buffer
 **
 ** \retval Receive data        
 ** 
 ******************************************************************************/
uint16_t Sci_ReceiveEdcData(void)
{
    return (M0P_SCI->EDC_DATA);
}

/**
 ******************************************************************************
 ** \brief Clear SCI Write FIFO and status
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_ClearWriteFifo(void)
{    
    M0P_SCI->CON_f.TX_FIFO_CLR = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Clear SCI Read FIFO and status
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_ClearReadFifo(void)
{    
    M0P_SCI->CON_f.RX_FIFO_CLR = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Read SCI Write FIFO buffer depth
 **
 ** \retval Write FIFO buffer depth        
 ** 
 ******************************************************************************/
uint8_t Sci_GetWriteFifoCurCnt(void)
{
    return (M0P_SCI->FIFO_DEPTH_f.TX_FIFO_DEPTH);
}

/**
 ******************************************************************************
 ** \brief Read SCI Read FIFO buffer depth
 **
 ** \retval Read FIFO buffer depth        
 ** 
 ******************************************************************************/
uint8_t Sci_GetReadFifoCurCnt(void)
{
    return (M0P_SCI->FIFO_DEPTH_f.RX_FIFO_DEPTH);
}

/**
 ******************************************************************************
 ** \brief Set SCI Reset pin as high
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_ResetHigh(void)
{    
    M0P_SCI->CLK_RST_f.RESET = 1u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Set SCI Reset pin as low
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_ResetLow(void)
{    
    M0P_SCI->CLK_RST_f.RESET = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Enable SCI Reset pin
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_EnableReset(void)
{    
    M0P_SCI->CLK_RST_f.RESET_EN = 1u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Disable SCI Reset pin
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_DisableReset(void)
{    
    M0P_SCI->CLK_RST_f.RESET_EN = 0u;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Set ETU count
 **
 ** \retval Ok                    
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_EtuCountSet(uint16_t u16EtuCount)
{    
    M0P_SCI->ETU_CNT = u16EtuCount;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Set Force high level cycle
 **
 ** \retval Ok
 ** \retval ErrorInvalidParameter 
 ** 
 ******************************************************************************/
en_result_t Sci_F1Set(boolean_t bF1En,uint8_t u8Cycle)
{    
    ASSERT(IS_VALID_EN(bF1En));
    ASSERT(IS_VALID_F1CYCLE(u8Cycle));
    
    if(FALSE == bF1En)
    {
        M0P_SCI->CON_f.FL_EN = 1u;
    }
    else
    {
        M0P_SCI->CON_f.FL_EN = 0u;
    }
        
    M0P_SCI->F1_NUM = u8Cycle;
    
    return Ok;
}

//@}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
