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
/** \file spi.h
 **
 ** spi driver define.
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-10-31  1.0 QianCP First version for Device Driver Library of
 **                     Module.
 **
 *****************************************************************************/

#ifndef __SPI_H__
#define __SPI_H__

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

//@{

/******************************************************************************
 * Global type definitions
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief SPI channel enumeration.
 *****************************************************************************/
typedef enum en_spi_channel
{
    SpiCh0 = 0u,                ///< spi channel 0
    SpiCh1 = 1u,                ///< spi channel 1
    SpiCh2 = 2u,                ///< spi channel 2
    SpiCh4 = 4u,                ///< spi channel 4
    SpiCh5 = 5u,                ///< spi channel 5
    SpiCh6 = 6u,                ///< spi channel 6
}en_spi_channel_t;

/**
 ******************************************************************************
 ** \brief SPI data length enumeration
 *****************************************************************************/
typedef enum en_spi_datalen
{
    SpiDataLen8 = 0,            ///< len = 8
    SpiDataLen5,                ///< len = 5
    SpiDataLen6,                ///< len = 6
    SpiDataLen7,                ///< len = 7
    SpiDataLen9,                ///< len = 9
    SpiDataLen10,               ///< len = 10
    SpiDataLen11,               ///< len = 11
    SpiDataLen12,               ///< len = 12
    SpiDataLen13,               ///< len = 13
    SpiDataLen14,               ///< len = 14
    SpiDataLen15,               ///< len = 15
    SpiDataLen16,               ///< len = 16
    SpiDataLenMax,
}en_spi_datalen_t;

/**
 ******************************************************************************
 ** \brief SPI serial timer clock division
 *****************************************************************************/
typedef enum en_spi_clk_div
{
    SpiClkDiv1   = 0u,          ///< Serial Timer clock = PCLK
    SpiClkDiv2   = 1u,          ///< Serial Timer clock = PCLK/2
    SpiClkDiv4   = 2u,          ///< Serial Timer clock = PCLK/4
    SpiClkDiv8   = 3u,          ///< Serial Timer clock = PCLK/8
    SpiClkDiv16  = 4u,          ///< Serial Timer clock = PCLK/16
    SpiClkDiv32  = 5u,          ///< Serial Timer clock = PCLK/32
    SpiClkDiv64  = 6u,          ///< Serial Timer clock = PCLK/64
    SpiClkDiv128 = 7u,          ///< Serial Timer clock = PCLK/128
    SpiClkDiv256 = 8u,          ///< Serial Timer clock = PCLK/256
    SpiClkDivMax = 9u,
}en_spi_clk_div_t;

/**
 ******************************************************************************
 ** \brief SPI chip selection pin
 *****************************************************************************/
typedef enum en_spi_cspin_sel
{
    SpiCsPin0 = 0u,             ///< Use SCS0 as chip selection pin
    SpiCsPin1 = 1u,             ///< Use SCS1 as chip selection pin
    SpiCsPin2 = 2u,             ///< Use SCS2 as chip selection pin
    SpiCsPin3 = 3u,             ///< Use SCS3 as chip selection pin
    SpiCsPinMax = 0xFFu,
}en_spi_cspin_sel_t;

/**
 ******************************************************************************
 ** \brief SPI function
 *****************************************************************************/
typedef enum en_spi_func_sel
{
    SpiFuncTx,                  ///< SPI TX
    SpiFuncRx,                  ///< SPI RX
    SPiFuncSyncTx,              ///< SPI sync transmit
    SpiFuncCsFormat,            ///< SPI cs format
    SpiFuncSerialTimer,         ///< SPI Serial TImer
}en_spi_func_sel_t;

/**
 ******************************************************************************
 ** \brief SPI interrupt selection
 *****************************************************************************/
typedef enum en_spi_irq_sel
{
    SpiIrqTx           = 0u,    ///< SPI TX interrupt
    SpiIrqRx           = 1u,    ///< SPI RX interrupt
    SpiIrqTxIdle       = 2u,    ///< SPI TX idle interrupt
    SpiIrqCsErr        = 4u,    ///< SPI chip selection interrupt
    SpiIrqSerialTimer  = 5u,    ///< SPI serial timer interrupt
}en_spi_irq_sel_t;

/**
 ******************************************************************************
 ** \brief SPI interrupt enable structure
 *****************************************************************************/
typedef struct stc_spi_irq_sel
{
    boolean_t bTxIrq;           ///< SPI TX interrupt
    boolean_t bRxIrq;           ///< SPI RX interrupt
    boolean_t bCsErrIrq;        ///< SPI chip selection interrupt
    boolean_t bTxIdleIrq;       ///< SPI TX idle interrupt
    boolean_t bTimerIrq;        ///< SPI Timer interrupt
    boolean_t bSerialTimerIrq;  ///< SPI serial timer interrupt
}stc_spi_irq_sel_t;

/**
 ******************************************************************************
 ** \brief SPI interrupt callback function
 *****************************************************************************/
typedef struct stc_spi_irq_cb
{
    func_ptr_t pfnTxIrqCb;              ///< SPI TX interrupt callback function
    func_ptr_t pfnRxIrqCb;              ///< SPI RX interrupt callback function
    func_ptr_t pfnTxIdleCb;             ///< SPI TX idle interrupt callback function
    func_ptr_t pfnCsErrIrqCb;           ///< SPI chip selection interrupt callback function
    func_ptr_t pfnSerialTimerIrqCb;     ///< SPI serial timer interrupt callback function
}stc_spi_irq_cb_t;

/**
 ******************************************************************************
 ** \brief SPI status types
 *****************************************************************************/
typedef enum en_spi_status
{
    SpiOverrunError,                    ///< SPI overrun error
    SpiRxFull,                          ///< SPI RX completion
    SpiTxEmpty,                         ///< SPI TX buffer empty
    SpiTxIdle,                          ///< SPI TX idle
    SpiCsErrIntFlag,                    ///< SPI chip selection error occurrance
    SpiTimerIntFlag,                    ///< SPI serial timer interrupt
}en_spi_status_t;

/**
 ******************************************************************************
 ** \brief SPI chip selection configuration
 *****************************************************************************/
typedef struct stc_spi_cspin_config
{
    boolean_t           bEn;            ///< pin enable
    boolean_t           bSckInv;        ///< sck invert
    boolean_t           bCsInActiveHigh; ///< cs inactive high
    boolean_t           bSPIMode;       ///< spi mode
    boolean_t           bMSB;           ///< big/little endian
    en_spi_datalen_t    enDataLen;      ///< 5 ~ 16 bit Length
}stc_spi_cspin_config_t;

/**
 ******************************************************************************
 ** \brief SPI cs configure data
 *****************************************************************************/
typedef struct stc_spi_cs_config
{
    en_spi_cspin_sel_t      enCsStartPin;       ///< CS start pin
    en_spi_cspin_sel_t      enCsEndPin;         ///< CS end pin
    boolean_t               bActiveHold;        ///< active hold
    en_spi_clk_div_t        enCsClkDiv;         ///< CS clock division
    boolean_t               bCsIdleLow;         ///< CS pin idle level
    boolean_t               bCsOutputEn;        ///< CS output enable
    stc_spi_cspin_config_t  stcCsPincfg[4];     ///< cs pin configuration
    uint8_t                 u8CsDelayTime;      ///< cs to sck start delay time
    uint8_t                 u8CsHoldTime;       ///< sck end to cs delay time
    uint16_t                u16CsDeselectTime;  ///< cs min idle time
}stc_spi_cs_config_t;

/**
 ******************************************************************************
 ** \brief SPI configuration structure
 *****************************************************************************/
typedef struct stc_spi_config
{
    boolean_t           bSlaveMode;       ///< Master or slave mode
    boolean_t           bSPIMode;         ///< spi or normal mode
    uint32_t            u32BaudRate;      ///< Baud rate (bps)
    boolean_t           bInvertClk;       ///< FALSE: SCK idle low
                                          ///< TRUE: SCK idle high
    boolean_t           bMSB;             ///< MSB or LSB
    boolean_t           bOutputSCK;       ///< SCK output
    boolean_t           bOutputData;      ///< SOT output
    boolean_t           bSOTHigh;         ///< SOT pin state
    uint8_t             u8DataOuputDly;   ///< max to 3 bits time delay.
    en_spi_datalen_t    enDataLen;        ///< 5->16 bit Length
    stc_spi_irq_sel_t   *pstcIrqEn;       ///< Pointer to SPI interrupt enable structure, if set to NULL, no interrupt enabled.
    stc_spi_irq_cb_t    *pstcIrqCb;       ///< Pointer to SPI interrupt callback functions structurei, f set to NULL, no interrupt callback initialized.
} stc_spi_config_t;


/******************************************************************************
 * Global definitions
 *****************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')
 *****************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 *****************************************************************************/
//irq interrupt handler
void SpiIrqHandlerTx(uint8_t u8Channel);
void SpiIrqHandlerRx(uint8_t u8Channel);
void SpiIrqHandlerStatus(uint8_t u8Channel);

//irq enable/disable
en_result_t Spi_EnableIrq(uint8_t u8Channel, en_spi_irq_sel_t enIrqSel);
en_result_t Spi_DisableIrq(uint8_t u8Channel, en_spi_irq_sel_t enIrqSel);

//SPI get status
boolean_t Spi_GetStatus(uint8_t u8Channel, en_spi_status_t enStatus);
en_result_t Spi_ClrStatus(uint8_t u8Channel, en_spi_status_t enStatus);

//SPI Init/Deinit
en_result_t Spi_Init(uint8_t u8Channel, stc_spi_config_t *pstcConfig);
en_result_t Spi_DeInit(uint8_t u8Channel);
en_result_t Spi_CSCconfig(uint8_t u8Channel, stc_spi_cs_config_t *pstcConfig);
en_result_t Spi_SerialTimerConfig(uint8_t u8Channel,
                                  en_spi_clk_div_t enDiv,
                                  uint16_t u16Val);

//SPI function
en_result_t Spi_EnableFunc(uint8_t u8Channel, en_spi_func_sel_t enFunc);
en_result_t Spi_DisableFunc(uint8_t u8Channel, en_spi_func_sel_t enFunc);

//SPI data setting
en_result_t Spi_SetBaudRate(uint8_t u8Channel, uint32_t u32BaudRate);
en_result_t Spi_SetTxBytes(uint8_t u8Channel, uint8_t u8Cspin, uint8_t u8Val);

//SPI TX/RX data function
en_result_t Spi_SendData(uint8_t u8Channel, uint16_t u16Data);
uint16_t Spi_ReceiveData(uint8_t u8Channel, boolean_t bMaster);

//@} // Spi Group

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

