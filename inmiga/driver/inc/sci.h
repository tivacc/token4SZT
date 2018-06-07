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
/** \file sci.h
 **
 ** Smart card interface driver define.
 ** @link Sci Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __SCI_H__
#define __SCI_H__

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
 ** function prototypes.
 *****************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief SCI EDC mode
 ******************************************************************************/
typedef enum en_sci_edcmode
{
    SciEdcLrc           = 0u,      ///< LRC
    SciEdcCrc           = 1u,      ///< CRC
} en_sci_edcmode_t;

/**
 ******************************************************************************
 ** \brief SCI  clock division
 ******************************************************************************/
typedef enum en_sci_clk
{
    SciClockNoDiv  = 0u,     ///< SCI clock = PCLK
    SciClockDiv2   = 1u,     ///< SCI clock = PCLK/2 
    SciClockDiv4   = 2u,     ///< SCI clock = PCLK/4
    SciClockDiv8   = 3u,     ///< SCI clock = PCLK/8
}en_sci_clk_t;

/**
 ******************************************************************************
 ** \brief SCI data direction
 ******************************************************************************/
typedef enum en_sci_data_dir
{
    SciDataLsbFirst = 0u,       ///< LSB first
    SciDataMsbFirst = 1u,       ///< MSB first
}en_sci_data_dir_t; 

/**
 ******************************************************************************
 ** \brief SCI parity mode
 ******************************************************************************/
typedef enum en_sci_paritymode
{
    SciParityEven    = 0u,      ///< Even parity
    SciParityOdd     = 1u,      ///< Odd parity
} en_sci_paritymode_t;

/**
 ******************************************************************************
 ** \brief SCI transmit mode
 ******************************************************************************/
typedef enum en_sci_transmitmode
{
    SciT0Mode    = 0u,      ///< T = 0
    SciT1Mode    = 1u,      ///< T = 1
} en_sci_transmitmode_t;

/**
 ******************************************************************************
 ** \brief SCI interrupt types
 ******************************************************************************/
typedef enum en_sci_irq_sel
{
    SciTxIrq              = 0u,             ///< Transmit interrupt
    SciRxIrq              = 1u,             ///< Receive interrupt
    SciEtuCntIrq          = 2u,             ///< ETU count interrupt
    SciWakeupIrq          = 3u,             ///< Wake up interrupt
}en_sci_irq_sel_t;

/**
 ******************************************************************************
 ** \brief SCI interrupt enable structure
 ******************************************************************************/
typedef struct stc_sci_irq_en
{
    boolean_t bTxIrq;               ///< Transmit interrupt
    boolean_t bRxIrq;               ///< Receive interrupt
    boolean_t bEtuCntIrq;           ///< ETU count interrupt
    boolean_t bWakeupIrq;           ///< Wake up interrupt
}stc_sci_irq_en_t;

/**
 ******************************************************************************
 ** \brief SCI interrupt callback function
 ******************************************************************************/
typedef struct stc_sci_irq_cb
{
    func_ptr_t pfnTxIrqCb;          ///< Transmit interrupt callback function pointer
    func_ptr_t pfnRxIrqCb;          ///< Receive interrupt callback function pointer
    func_ptr_t pfnEtuCntIrqCb;      ///< ETU count match callback function pointer
    func_ptr_t pfnWakeupIrqCb;      ///< Wakeup interrupt callback function pointer
}stc_sci_irq_cb_t;

/**
 ******************************************************************************
 ** \brief SCI status types
 ******************************************************************************/
typedef enum en_sci_status
{
    SciRxStartNs            = 0u,   ///< Receive start bit noise
    SciOverrun              = 1u,   ///< Receive over run
    SciBusy                 = 2u,   ///< Busy
    SciTxErr                = 3u,   ///< Transmit error
    SciRxErr                = 4u,   ///< Receive error
}en_sci_status_t;

/**
 ******************************************************************************
 ** \brief SCI FIFO status types
 ******************************************************************************/
typedef enum en_sci_fifo_status
{
    SciFifoTxOvr            = 0u,   ///< Transmit over run
    SciFifoTxUdr            = 1u,   ///< Transmit under run
    SciFifoTxFul            = 2u,   ///< Transmit full
    SciFifoTxEpt            = 3u,   ///< Transmit empty
    SciFifoRxOvr            = 4u,   ///< Receive over run
    SciFifoRxUdr            = 5u,   ///< Receive under run
    SciFifoRxFul            = 6u,   ///< Receive full
    SciFifoRxEpt            = 7u,   ///< Receive empty
}en_sci_fifo_status_t;

/**
 ******************************************************************************
 ** \brief SCI IRQ status types
 ******************************************************************************/
typedef enum en_sci_irq_status
{
    SciTxFinInt             = 0u,   ///< Transmit finish interrupt
    SciRxFinInt             = 1u,   ///< Receive finish interrupt
    SciEtuCntInt            = 2u,   ///< ETU count match interrupt
    SciWakeupInt            = 3u,   ///< SCI wakeup interrupt
}en_sci_irq_status_t;

/**
 ******************************************************************************
 ** \brief SCI configuration structure
 ******************************************************************************/
typedef struct stc_sci_config
{
    en_sci_transmitmode_t   enTMode;            ///< Transmit mode (0/1)
    uint16_t                u16BaudRate;        ///< Baud rate value, which is F/D. (1 ETU = (F/D) * (1/CardClock[Hz]))
    boolean_t               bParity;            ///< Parity enable
    en_sci_paritymode_t     enParity;           ///< Parity mode selection
    en_sci_data_dir_t       enBitDirection;     ///< SCI data direction
    boolean_t               bDataResend;        ///< TRUE: data resend enabled, FALSE: data resend disabled
    uint8_t                 u8ResendTimes;      ///< Retry times
    
    stc_sci_irq_en_t        *pstcIrqEn;         ///< Pointer to SCI interrupt enable structure, if set to NULL, no interrupt enabled.
    stc_sci_irq_cb_t        *pstcIrqCb;         ///< Pointer to SCI interrupt callback functions structurei, f set to NULL, no interrupt callback initialized.
    boolean_t               bTouchNvic;         ///< TRUE: enable NVIC, FALSE: don't enable NVIC
} stc_sci_config_t;

/******************************************************************************/
/* Global variable definitions ('extern')                                     */
/******************************************************************************/

/******************************************************************************/
/* Global function prototypes (definition in C source)                        */
/******************************************************************************/
// Interrupt
en_result_t Sci_EnableIrq(en_sci_irq_sel_t enIrqSel);
en_result_t Sci_DisableIrq(en_sci_irq_sel_t enIrqSel);

// Init/De-Init
en_result_t Sci_Init(stc_sci_config_t* pstcConfig);
en_result_t Sci_DeInit(boolean_t bTouchNvic);

// Function enable/disable
en_result_t Sci_Enable(void);
en_result_t Sci_Disable(void);

// Baud rate & clock
en_result_t Sci_SetClock(en_sci_clk_t enSciClock);
en_result_t Sci_EnableClock(void);
en_result_t Sci_DisableClock(void);
en_result_t Sci_SetBaudRate(uint16_t u16BaudRate);

// Status read/write
en_result_t Sci_InitStatus(void);
boolean_t Sci_GetStatus(en_sci_status_t enStatus);
en_result_t Sci_ClearStatus(en_sci_status_t enStatus);
boolean_t Sci_GetFifoStatus(en_sci_fifo_status_t enStatus);
en_result_t Sci_ClearFifoStatus(en_sci_fifo_status_t enStatus);
boolean_t Sci_GetIrqStatus(en_sci_irq_status_t enStatus);
en_result_t Sci_ClearIrqStatus(en_sci_irq_status_t enStatus);

// Data read/write
en_result_t Sci_SendData(uint8_t u8Data);
en_result_t Sci_SendEdcData(uint16_t u16Data);
uint8_t Sci_ReceiveData(void);
uint16_t Sci_ReceiveEdcData(void);

// FIFO 
en_result_t Sci_ClearWriteFifo (void);
en_result_t Sci_ClearReadFifo (void);
uint8_t Sci_GetWriteFifoCurCnt(void);
uint8_t Sci_GetReadFifoCurCnt(void);

// Misc function
en_result_t Sci_ResetHigh(void);
en_result_t Sci_ResetLow(void);
en_result_t Sci_EnableReset(void);
en_result_t Sci_DisableReset(void);
en_result_t Sci_EtuCountSet(uint16_t u16EtuCount);
en_result_t Sci_F1Set(boolean_t bF1En,uint8_t u8Cycle);

#ifdef __cplusplus
}
#endif

#endif /* __SCI_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
