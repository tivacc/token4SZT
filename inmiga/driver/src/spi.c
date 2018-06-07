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
/** \file spi.c
 **
 ** SPI driver API.
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-10-31  1.0  QianCP First version for Device Driver Library of
 **                      Module.
 **
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "spi.h"
#include "clk.h"

/**
 ******************************************************************************
 ** \addtogroup SPI Group
 *****************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/
#define MSC_SPI_MODE                (2)         //hardware setting
#define SPI_DATA_OUT_DEALY_MAX      (3)         //max 3bit delay

#define IS_VALID_CH(x)              (   SpiCh0 == (x) ||\
                                        SpiCh1 == (x) ||\
                                        SpiCh2 == (x) ||\
                                        SpiCh4 == (x) ||\
                                        SpiCh5 == (x) ||\
                                        SpiCh6 == (x) )

#define IS_VALID_FUNC(x)            (   SpiFuncTx == (x)||\
                                        SpiFuncRx == (x)||\
                                        SPiFuncSyncTx == (x)||\
                                        SpiFuncCsFormat == (x)||\
                                        SpiFuncSerialTimer == (x) )

#define IS_VALID_IRQ(x)             (   SpiIrqTx ==(x) || \
                                        SpiIrqRx ==(x) || \
                                        SpiIrqTxIdle ==(x) || \
                                        SpiIrqCsErr ==(x) || \
                                        SpiIrqSerialTimer ==(x) )

#define IS_VALID_STAT(x)            (   SpiOverrunError == (x)||\
                                        SpiRxFull == (x)||\
                                        SpiTxEmpty == (x)||\
                                        SpiTxIdle == (x)||\
                                        SpiCsErrIntFlag == (x)||\
                                        SpiTimerIntFlag == (x) )


/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 *****************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/
typedef struct stc_spi_instance_data
{
    uint8_t                 u8Ch;               ///< channel index
    M0P_MSC_SPI_TypeDef    *pstcInstance;       ///< pointer to SPI Base Reg
    stc_spi_irq_cb_t        stcIrqCb;           ///< irq callback function
} stc_spi_instance_data_t;

/******************************************************************************
 * Local function prototypes ('static')
 *****************************************************************************/
static void SpiEnableNvic(uint8_t u8ch, en_spi_irq_sel_t enSel);
static void SpiDisableNvic(uint8_t u8ch);
static en_result_t SpiEnableFunc(uint8_t u8Channel,
                                 en_spi_func_sel_t enFunc,
                                 boolean_t bFlag);

void Spi_Rx_IrqHandler(uint8_t u8Channel);
void Spi_Tx_IrqHandler(uint8_t u8Channel);
void Spi_Stat_IrqHandler(uint8_t u8Channel);
/******************************************************************************
 * Local variable definitions ('static')
 *****************************************************************************/
/// Look-up table for all SPI instances
static stc_spi_instance_data_t m_astcSpiDataLut[] =
{
    {
        SpiCh0,
        M0P_MSC0_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
    {
        SpiCh1,
        M0P_MSC1_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
    {
        SpiCh2,
        M0P_MSC2_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
    {
        SpiCh4,
        M0P_MSC4_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
    {
        SpiCh5,
        M0P_MSC5_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
    {
        SpiCh6,
        M0P_MSC6_SPI,
        { NULL, NULL, NULL, NULL, NULL },
    },
};

/******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

static stc_spi_instance_data_t* SpiGetInternDataPtr(uint8_t u8Idx)
{
    stc_spi_instance_data_t *pstcData = NULL;
    uint32_t                i = 0;

    for (i = 0; i < ARRAY_SZ(m_astcSpiDataLut); i++)
    {
        if (u8Idx == m_astcSpiDataLut[i].u8Ch)
        {
            pstcData = &m_astcSpiDataLut[i];
            break;
        }
    }

    return pstcData;
}


/**
 ******************************************************************************
 ** \brief SpiEnableNvic 
 **        enable spi NVIC
 ** 
 ** \param [IN] u8ch    :   SPI channel
 ** \param [IN] enSel   :   irq Tx/Rx selection
 ** 
 ** \retval void 
 ******************************************************************************/
static void SpiEnableNvic(uint8_t u8ch, en_spi_irq_sel_t enSel)
{
    IRQn_Type enIrq;

    switch (u8ch)
    {
        case SpiCh0:
        case SpiCh1:
        case SpiCh2:
            enIrq = (IRQn_Type)(MSC0RX_IRQn + u8ch * 2);
            break;
        case SpiCh4:
        case SpiCh5:
        case SpiCh6:
            enIrq = (IRQn_Type)(MSC4RX_IRQn + (u8ch - 4) * 2);
            break;
        default:
            return;
    }

    //rx
    if (SpiIrqRx == enSel)
    {
        NVIC_ClearPendingIRQ(enIrq);
        NVIC_EnableIRQ(enIrq);
        NVIC_SetPriority(enIrq, DDL_IRQ_LEVEL_MSC0RX);
    }

    //tx
    if (SpiIrqTx == enSel)
    {
        enIrq = (IRQn_Type)(enIrq + 1);
        NVIC_ClearPendingIRQ(enIrq);
        NVIC_EnableIRQ(enIrq);
        NVIC_SetPriority(enIrq, DDL_IRQ_LEVEL_MSC0TX);
    }
}


/**
 ******************************************************************************
 ** \brief SpiDisableNvic 
 **        disable spi NVIC
 ** 
 ** \param [IN] u8ch    :   SPI channel
 ** 
 ** \retval void 
 ******************************************************************************/
static void SpiDisableNvic(uint8_t u8ch)
{
    IRQn_Type enIrq;

    switch (u8ch)
    {
        case SpiCh0:
        case SpiCh1:
        case SpiCh2:
            enIrq = (IRQn_Type)(MSC0RX_IRQn + u8ch);
            break;
        case SpiCh4:
        case SpiCh5:
        case SpiCh6:
            enIrq = (IRQn_Type)(MSC4RX_IRQn + u8ch - 4);
            break;
        default:
            return;
    }

    //rx

    NVIC_ClearPendingIRQ(enIrq);
    NVIC_DisableIRQ(enIrq);
    NVIC_SetPriority(enIrq, DDL_IRQ_LEVEL_DEFAULT);
    //tx
    enIrq = (IRQn_Type)(enIrq + 1);
    NVIC_ClearPendingIRQ(enIrq);
    NVIC_DisableIRQ(enIrq);
    NVIC_SetPriority(enIrq, DDL_IRQ_LEVEL_DEFAULT);
}


/**
 ******************************************************************************
 ** \brief SpiEnableFunc 
 **        enable/disable a SPI function
 ** 
 ** \param [IN] u8Channel   :  SPI channel index
 ** \param [IN] enFunc  : SPI function index
 ** \param [IN] bFlag   : enable/disable
 ** 
 ** \retval en_result_t  Ok: set done
 **                      others: set failed
 ******************************************************************************/
static en_result_t SpiEnableFunc(uint8_t u8Channel,
                                 en_spi_func_sel_t enFunc,
                                 boolean_t bFlag)
{
    en_result_t enRet = Error;
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef     *pstcSPI = NULL;

    ASSERT(IS_VALID_FUNC(enFunc));

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    switch (enFunc)
    {
        case SpiFuncTx:
            pstcSPI->CR_f.TXE = bFlag;
            break;
        case SpiFuncRx:
            pstcSPI->CR_f.RXE = bFlag;
            break;
        case SPiFuncSyncTx:
            pstcSPI->EACR_f.SYNTE = bFlag;
            break;
        case SpiFuncCsFormat:
            pstcSPI->ECR_f.CSFE = bFlag;
            break;
        case SpiFuncSerialTimer:
            pstcSPI->EACR_f.TMRE = bFlag;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}

/**
 ******************************************************************************
 ** \brief SpiEnableIrq 
 **        enable/disable a SPI interrupt factor
 ** 
 ** \param [IN] u8Channel : SPI channel index
 ** \param [IN] enIrqSel  : SPI interrupt index
 ** \param [IN] bFlag     : enable/disable
 ** 
 ** \retval en_result_t  Ok: set done
 **                      others: set failed
 ******************************************************************************/
static en_result_t SpiEnableIrq(uint8_t u8Channel,
                                en_spi_irq_sel_t enIrqSel,
                                boolean_t bFlag)
{
    en_result_t enRet = Error;
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef     *pstcSPI = NULL;

    ASSERT(IS_VALID_IRQ(enIrqSel));

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    switch (enIrqSel)
    {
        case SpiIrqTx:
            pstcSPI->CR_f.TXIE = bFlag;
            break;
        case SpiIrqRx:
            pstcSPI->CR_f.RXIE = bFlag;
            break;
        case SpiIrqTxIdle:
            pstcSPI->CR_f.TBIE = bFlag;
            break;
        case SpiIrqCsErr:
            pstcSPI->EACR_f.CSEIE = bFlag;
            break;
        case SpiIrqSerialTimer:
            pstcSPI->EACR_f.TIE = bFlag;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Spi_Rx_IrqHandler 
 **        SPI irq Rx callback function.
 ** 
 ** \param [IN] u8Channel   : channel index
 ** 
 ** \retval void 
 ******************************************************************************/
void Spi_Rx_IrqHandler(uint8_t u8Channel)
{
    stc_spi_instance_data_t *pstcInst = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return;
    }

    if (NULL != pstcInst->stcIrqCb.pfnRxIrqCb)
    {
        pstcInst->stcIrqCb.pfnRxIrqCb();
    }
}


/**
 ******************************************************************************
 ** \brief Spi_Tx_IrqHandler 
 **        SPI irq Tx callback function.
 ** 
 ** \param [IN] u8Channel   : channel index
 ** 
 ** \retval void 
 ******************************************************************************/
void Spi_Tx_IrqHandler(uint8_t u8Channel)
{
    stc_spi_instance_data_t *pstcInst = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return;
    }

    if (NULL != pstcInst->stcIrqCb.pfnTxIrqCb)
    {
        pstcInst->stcIrqCb.pfnTxIrqCb();
    }
}


/**
 ******************************************************************************
 ** \brief Spi_Stat_IrqHandler 
 **        SPI irq stat callback function.
 ** 
 ** \param [IN] u8Channel   : channel index
 ** 
 ** \retval void 
 ******************************************************************************/
void Spi_Stat_IrqHandler(uint8_t u8Channel)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return;
    }

    pstcSPI = pstcInst->pstcInstance;

    if (TRUE == pstcSPI->SR_f.ORF)
    {
        ///< \todo code
    }

    if (TRUE == pstcSPI->SR_f.TBIF)
    {
        if (NULL != pstcInst->stcIrqCb.pfnTxIdleCb)
        {
            pstcInst->stcIrqCb.pfnTxIdleCb();
        }
    }

    if (TRUE == pstcSPI->EACR_f.TIF)
    {
        if (NULL != pstcInst->stcIrqCb.pfnSerialTimerIrqCb)
        {
            pstcInst->stcIrqCb.pfnSerialTimerIrqCb();
        }
        pstcSPI->EACR_f.TIF = FALSE;
    }
    pstcSPI->SR_f.RECLR = TRUE;
}


/**
 ******************************************************************************
 ** \brief Spi_GetStatus 
 **        get a SPI status from #enStatus
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enStatus    : event
 ** 
 ** \retval boolean_t            TRUE:  the event is set
 *                               FALSE: the event is not set
 *                                      u8Channel is invalid 
 ******************************************************************************/
boolean_t Spi_GetStatus(uint8_t u8Channel, en_spi_status_t enStatus)
{
    volatile boolean_t bRet = FALSE;
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    ASSERT(IS_VALID_STAT(enStatus));

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return FALSE;
    }

    pstcSPI = pstcInst->pstcInstance;

    switch (enStatus)
    {
        case SpiOverrunError:
            bRet = pstcSPI->SR_f.ORF;
            break;
        case SpiRxFull:
            bRet = pstcSPI->SR_f.RDFF;
            break;
        case SpiTxEmpty:
            bRet = pstcSPI->SR_f.TDEF;
            break;
        case SpiTxIdle:
            bRet = pstcSPI->SR_f.TBIF;
            break;
        case SpiCsErrIntFlag:
            bRet = pstcSPI->EACR_f.CSER;    //fix reg CES
            break;
        case SpiTimerIntFlag:
            bRet = pstcSPI->EACR_f.TIF;
            break;
        default:
            break;
    }

    return bRet;
}


/**
 ******************************************************************************
 ** \brief Spi_ClrStatus 
 **        clear a SPI event status
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enStatus    : event
 ** 
 ** \retval en_result_t     Ok: clear done.
 **                         ErrorInvalidParameter:   u8Channel is invalid
 **                         enStatus is invalid
 ******************************************************************************/
en_result_t Spi_ClrStatus(uint8_t u8Channel, en_spi_status_t enStatus)
{
    en_result_t enRet = Ok;
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    ASSERT(IS_VALID_STAT(enStatus));

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    switch (enStatus)
    {
        case SpiOverrunError:
            pstcSPI->SR_f.RECLR = TRUE;
            break;
        case SpiRxFull:
        case SpiTxEmpty:
        case SpiTxIdle:
            break;
        case SpiCsErrIntFlag:
            pstcSPI->EACR_f.CSER = FALSE;
            break;
        case SpiTimerIntFlag:
            pstcSPI->EACR_f.TIF = FALSE;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;

}


/**
 ******************************************************************************
 ** \brief Spi_Init 
 **        This function initializes the SPI module
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] pstcConfig  : Pointer to a config
 ** 
 ** \retval     Ok:                          Process successfully done.
 **             ErrorInvalidParameter:       If one of following conditions are
 **             met:
 **                                     -pstcConfig == NULL
 **                                     -config data is invalid
 ******************************************************************************/
en_result_t Spi_Init(uint8_t u8Channel, stc_spi_config_t *pstcConfig)
{
    en_result_t enRet = Error;
    stc_spi_instance_data_t *pstcInst = NULL;
    stc_spi_irq_sel_t       *pstcIrqsel = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    ASSERT(NULL != pstcConfig);
    ASSERT(pstcConfig->u8DataOuputDly <= SPI_DATA_OUT_DEALY_MAX);
    ASSERT(pstcConfig->enDataLen < SpiDataLenMax);

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    //reset
    pstcSPI->CR_f.PCL = TRUE;
    pstcSPI->MR_f.MODE = MSC_SPI_MODE;
    pstcSPI->CR_f.MSS = pstcConfig->bSlaveMode;
    pstcSPI->CR_f.SPIMODE = pstcConfig->bSPIMode;
    pstcSPI->MR_f.CINV = !pstcConfig->bInvertClk;
    pstcSPI->MR_f.TDS = pstcConfig->bMSB;
    pstcSPI->MR_f.CKE = pstcConfig->bOutputSCK;
    pstcSPI->ECR_f.DTRWS = pstcConfig->u8DataOuputDly;
    pstcSPI->ECR_f.SOPS = pstcConfig->bSOTHigh;
    pstcSPI->ECR_f.DL = pstcConfig->enDataLen & 0x7;
    if (pstcConfig->enDataLen >= SpiDataLen13)
    {
        pstcSPI->ECR_f.DL3 = 1;
    }

    //pstcSPI->SPI_ECR_f.DTRWS = pstcConfig->enSyncWaitTime;
    enRet = Spi_SetBaudRate(u8Channel, pstcConfig->u32BaudRate);

    //interrupt setting
    if (NULL != pstcConfig->pstcIrqCb)
    {
        pstcInst->stcIrqCb = *pstcConfig->pstcIrqCb;
    }

    pstcIrqsel = pstcConfig->pstcIrqEn;
    if (NULL != pstcIrqsel)
    {
        SpiEnableIrq(u8Channel, SpiIrqRx, pstcIrqsel->bRxIrq);
        SpiEnableIrq(u8Channel, SpiIrqTx, pstcIrqsel->bTxIrq);
        SpiEnableIrq(u8Channel, SpiIrqTxIdle, pstcIrqsel->bTxIdleIrq);
        SpiEnableIrq(u8Channel, SpiIrqCsErr, pstcIrqsel->bCsErrIrq);
        SpiEnableIrq(u8Channel, SpiIrqSerialTimer, pstcIrqsel->bSerialTimerIrq);

        if (TRUE == pstcIrqsel->bTxIrq)
        {
            SpiEnableNvic(u8Channel, SpiIrqTx);
        }
        if (TRUE == pstcIrqsel->bRxIrq)
        {
            SpiEnableNvic(u8Channel, SpiIrqRx);
        }
    }

    enRet = Ok;

    return enRet;
}

/**
 *****************************************************************************
 ** \brief De-Initialize a SPI channel
 **
 ** This function de-initializes the specified channel of SPI
 **
 ** \param [in] u8Channel           channel index
 **
 ** \retval Ok                      Process successfully done.
 ** \retval ErrorInvalidParameter   If one of following conditions are met:
 **
 **
 *****************************************************************************/
en_result_t Spi_DeInit(uint8_t u8Channel)
{
    en_result_t enRet = Ok;

    stc_spi_instance_data_t *pstcInst = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    SpiEnableIrq(u8Channel, SpiIrqTx, FALSE);
    SpiEnableIrq(u8Channel, SpiIrqRx, FALSE);
    SpiEnableIrq(u8Channel, SpiIrqTxIdle, FALSE);
    SpiEnableIrq(u8Channel, SpiIrqCsErr, FALSE);
    SpiEnableIrq(u8Channel, SpiIrqSerialTimer, FALSE);

    SpiEnableFunc(u8Channel, SpiFuncRx, FALSE);
    SpiEnableFunc(u8Channel, SpiFuncTx, FALSE);
    SpiEnableFunc(u8Channel, SPiFuncSyncTx, FALSE);
    SpiEnableFunc(u8Channel, SpiFuncCsFormat, FALSE);
    SpiEnableFunc(u8Channel, SpiFuncSerialTimer, FALSE);

    SpiDisableNvic(u8Channel);

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Spi_SetBaudRate 
 **        Set spi output data baudrate
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] u32BaudRate : baudrate value
 ** 
 *  \retval en_result_t     Ok: set done
 *                          ErrorInvalidParameter: u8Channel is invalid
 ******************************************************************************/
en_result_t Spi_SetBaudRate(uint8_t u8Channel, uint32_t u32BaudRate)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;
    uint32_t u32Val = 0;

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    u32Val = Clk_GetPeripheralClk(ClkPeriphralMsc);

    u32Val = u32Val / u32BaudRate - 1;

    pstcSPI->BRS_f.BRS = u32Val;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Spi_EnableFunc 
 **        Enable a spi function
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enFunc      : SPI function type
 ** 
 ** \retval en_result_t   Ok: set done
 *                        ErrorInvalidParameter: u8Channel is invalid
 *                        enFunc is invalid
 ******************************************************************************/
en_result_t Spi_EnableFunc(uint8_t u8Channel, en_spi_func_sel_t enFunc)
{
    return SpiEnableFunc(u8Channel, enFunc, TRUE);
}


/**
 ******************************************************************************
 ** \brief Spi_DisableFunc 
 **        Disable a spi function
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enFunc      : SPI function type
 ** 
 ** \retval en_result_t     Ok: set done
 **                         ErrorInvalidParameter: u8Channel is invalid enFunc
 **                         is invalid
 ******************************************************************************/
en_result_t Spi_DisableFunc(uint8_t u8Channel, en_spi_func_sel_t enFunc)
{
    return SpiEnableFunc(u8Channel, enFunc, FALSE);
}

/** 
 ******************************************************************************
 ** \brief   Spi_EnableIrq
 **          Enable a spi interupt event
 ** \param   [in]  u8Channel     channel index
 ** \param   [in]  enIrqSel      irq event
 **
 ** \retval  en_result_t         Ok: set done
 **                              ErrorInvalidParameter: u8Channel is invalid
 **                              enIrqSel is invalid
 ******************************************************************************/
en_result_t Spi_EnableIrq(uint8_t u8Channel, en_spi_irq_sel_t enIrqSel)
{
    return SpiEnableIrq(u8Channel, enIrqSel, TRUE);
}


/**
 ******************************************************************************
 ** \brief Spi_DisableIrq 
 **        disable a spi interupt event
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enIrqSel    : irq event
 ** 
 ** \retval en_result_t     : Ok: set done
 *                            ErrorInvalidParameter: u8Channel is invalid
 *                            enIrqSel is invalid
 ******************************************************************************/
en_result_t Spi_DisableIrq(uint8_t u8Channel, en_spi_irq_sel_t enIrqSel)
{
    return SpiEnableIrq(u8Channel, enIrqSel, FALSE);
}


/**
 ******************************************************************************
 ** \brief Spi_SendData 
 **        send out a data
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] u16Data     : data to send out
 ** 
 ** \retval en_result_t     Ok: set done
 *                          ErrorInvalidParameter:   u8Channel is invalid
 ******************************************************************************/
en_result_t Spi_SendData(uint8_t u8Channel, uint16_t u16Data)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    pstcSPI->MR_f.DOE = TRUE;
    pstcSPI->TXDR = u16Data;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Spi_ReceiveData 
 **        read a data from register
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] bMaster :   SPI current mode,should be same as previous set.
 ** 
 ** \retval uint16_t read data
 ******************************************************************************/
uint16_t Spi_ReceiveData(uint8_t u8Channel, boolean_t bMaster)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef     *pstcSPI = NULL;

    pstcInst = SpiGetInternDataPtr(u8Channel);

    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    pstcSPI->MR_f.DOE = FALSE;

    if (TRUE == bMaster)        //send SCK
    {
        pstcSPI->TXDR = 0x0;
    }
    while (FALSE == Spi_GetStatus(u8Channel, SpiRxFull))
    {
        ;
    }

    return pstcSPI->RXDR;
}


/**
 ******************************************************************************
 ** \brief Spi_SerialTimerConfig 
 **        set SPI timer mode configuration
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] enDiv   : spi timer clock prescaler
 ** \param [IN] u16Val  : timer count
 ** 
 ** \retval en_result_t Ok: set done
 *                      ErrorInvalidParameter:   u8Channel is invalid
 *                      enDiv is invalid
 ******************************************************************************/
en_result_t Spi_SerialTimerConfig(uint8_t u8Channel,
                                  en_spi_clk_div_t enDiv,
                                  uint16_t u16Val)

{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef     *pstcSPI = NULL;

    ASSERT(enDiv < SpiClkDivMax);

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }


    pstcSPI = pstcInst->pstcInstance;

    pstcSPI->TMC_f.TMC = u16Val;
    pstcSPI->EACR_f.CLKDIV = enDiv;

    return Ok;
}


/**
 ******************************************************************************
 ** \brief Spi_SetTxBytes 
 **        Set Tx byte for cs /sync mode use.
 ** 
 ** \param [IN] u8Channel   : channel index
 ** \param [IN] u8Cspin : cs pin index
 ** \param [IN] u8Val   : tx counter
 ** 
 ** \retval en_result_t Ok: set done
 *                          ErrorInvalidParameter:   u8Channel is invalid
 *                          u8Cspin is invalid
 ******************************************************************************/
en_result_t Spi_SetTxBytes(uint8_t u8Channel, uint8_t u8Cspin, uint8_t u8Val)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef     *pstcSPI = NULL;
    en_result_t enRet = Ok;

    ASSERT(u8Cspin < SpiCsPinMax);

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    switch (u8Cspin)
    {
        case SpiCsPin0:
            pstcSPI->TDTCNT0 = u8Val;
            break;
        case SpiCsPin1:
            pstcSPI->TDTCNT1 = u8Val;
            break;
        case SpiCsPin2:
            pstcSPI->TDTCNT2 = u8Val;
            break;
        case SpiCsPin3:
            pstcSPI->TDTCNT3 = u8Val;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Spi_CSCconfig 
 **        spi chip select config
 ** 
 ** \param [IN] u8Channel   : SPI channel index
 ** \param [IN] pstcConfig  : pointer to channel configure data.
 ** 
 ** \retval en_result_t    Ok: set done
 *                              ErrorInvalidParameter: pstcConfig is NULL
 *                              pstcConfig has invalid param
 ******************************************************************************/
en_result_t Spi_CSCconfig(uint8_t u8Channel, stc_spi_cs_config_t *pstcConfig)
{
    stc_spi_instance_data_t *pstcInst = NULL;
    M0P_MSC_SPI_TypeDef    *pstcSPI = NULL;

    ASSERT(NULL != pstcConfig);
    ASSERT(pstcConfig->enCsStartPin < SpiCsPinMax);
    ASSERT(pstcConfig->enCsEndPin < SpiCsPinMax);
    ASSERT(pstcConfig->enCsClkDiv <= SpiClkDiv64);

    pstcInst = SpiGetInternDataPtr(u8Channel);
    if (NULL == pstcInst)
    {
        return ErrorInvalidParameter;
    }

    pstcSPI = pstcInst->pstcInstance;

    pstcSPI->CSCR_f.CSAS = pstcConfig->enCsStartPin;
    pstcSPI->CSCR_f.CSAE = pstcConfig->enCsEndPin;  //pin error
    pstcSPI->CSCR_f.CSAH = pstcConfig->bActiveHold;
    pstcSPI->CSCR_f.CSTODIV = pstcConfig->enCsClkDiv;
    pstcSPI->CSCR_f.CSLVS = pstcConfig->bCsIdleLow; //CSLVS
    pstcSPI->CSCR_f.CSOE = pstcConfig->bCsOutputEn;

    pstcSPI->CSTMG1 = pstcConfig->u8CsDelayTime;
    pstcSPI->CSTMG0 = pstcConfig->u8CsHoldTime;
    pstcSPI->CSTMG32 = pstcConfig->u16CsDeselectTime;

    //each pin setting
    pstcSPI->CSCR_f.CSEN0 = pstcConfig->stcCsPincfg[0].bEn;
    pstcSPI->CSCR_f.CSEN1 = pstcConfig->stcCsPincfg[1].bEn;
    pstcSPI->CSCR_f.CSEN2 = pstcConfig->stcCsPincfg[2].bEn;
    pstcSPI->CSCR_f.CSEN3 = pstcConfig->stcCsPincfg[3].bEn;

    pstcSPI->CSFR0_f.CS1CSLVS = pstcConfig->stcCsPincfg[0].bCsInActiveHigh;           //inactive
    pstcSPI->CSFR0_f.CS1CINV = pstcConfig->stcCsPincfg[0].bSckInv;
    pstcSPI->CSFR0_f.CS1SPI = pstcConfig->stcCsPincfg[0].bSPIMode;
    pstcSPI->CSFR0_f.CS1TDS = pstcConfig->stcCsPincfg[0].bMSB;
    pstcSPI->CSFR0_f.CS1DL = pstcConfig->stcCsPincfg[0].enDataLen;

    pstcSPI->CSFR1_f.CS2CSLVS = pstcConfig->stcCsPincfg[1].bCsInActiveHigh;
    pstcSPI->CSFR1_f.CS2CINV = pstcConfig->stcCsPincfg[1].bSckInv;
    pstcSPI->CSFR1_f.CS2SPI = pstcConfig->stcCsPincfg[1].bSPIMode;
    pstcSPI->CSFR1_f.CS2TDS = pstcConfig->stcCsPincfg[1].bMSB;
    pstcSPI->CSFR1_f.CS2DL = pstcConfig->stcCsPincfg[1].enDataLen;

    pstcSPI->CSFR2_f.CS3CSLVS = pstcConfig->stcCsPincfg[2].bCsInActiveHigh;
    pstcSPI->CSFR2_f.CS3CINV = pstcConfig->stcCsPincfg[2].bSckInv;
    pstcSPI->CSFR2_f.CS3SPI = pstcConfig->stcCsPincfg[2].bSPIMode;
    pstcSPI->CSFR2_f.CS3TDS = pstcConfig->stcCsPincfg[2].bMSB;
    pstcSPI->CSFR2_f.CS3DL = pstcConfig->stcCsPincfg[2].enDataLen;

    return Ok;
}


//@} // SPI Group
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

