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
/** \file interrupts_hc32l15.c
 **
 ** Interrupt management
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of
 **                         Module.
 **
 *****************************************************************************/

/******************************************************************************
 * Include files                                                              
 *****************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"

__WEAKDEF void Nmi_IrqHandler(uint8_t u8Param);
__WEAKDEF void Hwwdt_IrqHandler(uint8_t u8Param);

__WEAKDEF void Dt_IrqHandler(uint8_t u8Param);
__WEAKDEF void Clk_CsvIrqHandler(uint8_t u8Param);
__WEAKDEF void Swwdt_IrqHandler(uint8_t u8Param);
__WEAKDEF void Lvd_IrqHandler(uint8_t u8Param);
__WEAKDEF void Exti_07IrqHandler(uint8_t u8Param);
__WEAKDEF void Exti_815IrqHandler(uint8_t u8Param);
__WEAKDEF void Uart_Rx_IrqHandler(uint8_t u8Param);
__WEAKDEF void Spi_Rx_IrqHandler(uint8_t u8Param);
__WEAKDEF void I2c_Rx_IrqHander(uint8_t u8Param);
__WEAKDEF void Uart_Tx_IrqHandler(uint8_t u8Param);
__WEAKDEF void Spi_Tx_IrqHandler(uint8_t u8Param);
__WEAKDEF void I2c_Tx_IrqHander(uint8_t u8Param);
__WEAKDEF void Uart_Stat_IrqHandler(uint8_t u8Param);
__WEAKDEF void Spi_Stat_IrqHandler(uint8_t u8Param);
__WEAKDEF void I2c_Stat_IrqHander(uint8_t u8Param);
__WEAKDEF void Clk_HSXTRdy_IrqHandler(uint8_t u8Param);
__WEAKDEF void Clk_LSXTRdy_IrqHandler(uint8_t u8Param);
__WEAKDEF void Wkup_IrqHandler(uint8_t u8Param);
__WEAKDEF void Rtc_IrqHandler(uint8_t u8Param);
__WEAKDEF void Rami_IrqHandler(uint8_t u8Param);
__WEAKDEF void Adc_ConvIrqHandler(uint8_t u8Param);
__WEAKDEF void Adc_CmpIrqHandler(uint8_t u8Param);
__WEAKDEF void Vc_IrqHandler(uint8_t u8Param);
__WEAKDEF void Sci_IrqHandler(uint8_t u8Param);
__WEAKDEF void Ct_Irq0Handler(uint8_t u8Param);
__WEAKDEF void Ct_Irq1Handler(uint8_t u8Param);


void MSCRX_IRQHander2(uint8_t u8ch,uint8_t u8mode)
{
    switch (u8mode)
    {
        case 0:
            Uart_Rx_IrqHandler(u8ch);
            break;
        case 1:
            ///< \todo
            break;
        case 2:
            Spi_Rx_IrqHandler(u8ch);
            break;
        case 4:
            I2c_Rx_IrqHander(u8ch);
            break;
        default:
            break;
    }
}

void MSCTX_IRQHander2(uint8_t u8ch,uint8_t u8mode)
{
    switch (u8mode)
    {
        case 0:
            Uart_Tx_IrqHandler(u8ch);
            break;
        case 1:
            ///< \todo
            break;
        case 2:
            Spi_Tx_IrqHandler(u8ch);
            break;
        case 4:
            I2c_Tx_IrqHander(u8ch);
            break;
        default:
            break;
    }
}

void MSCSTAT_IRQHander2(uint8_t u8ch,uint8_t u8mode)
{
    switch (u8mode)
    {
        case 0:
            Uart_Stat_IrqHandler(u8ch);
            break;
        case 1:
            ///< \todo
            break;
        case 2:
            Spi_Stat_IrqHandler(u8ch);
            break;
        case 4:
            I2c_Stat_IrqHander(u8ch);
            break;
        default:
            break;
    }
}

/******************************************************************************/
/*********************************** NMI/HWWDG ********************************/
/******************************************************************************/
void NMI_Handler(void)
{
    uint8_t u8val = 0;
    u8val = M0P_IRQC->IRQ_ST02;

    if ( (u8val&1) > 0)
    {
        Nmi_IrqHandler(0);
    }
    if ((u8val&2)> 0)
    {
        Hwwdt_IrqHandler(0);
    }
}

/******************************************************************************/
/*********************************** CSV **************************************/
/******************************************************************************/
void CSV_IRQHandler(void)
{
    //uint8_t u8val = 0;
    //u8val = M0P_IRQC->IRQ00PEND;
    //driver to do
    Clk_CsvIrqHandler(0);
}

/******************************************************************************/
/******************************* SW watchdog **********************************/
/******************************************************************************/
void SWDT_IRQHandler(void)
{
     Swwdt_IrqHandler(0);
}

/******************************************************************************/
/*********************************** LVD **************************************/
/******************************************************************************/
void LVD_IRQHandler(void)
{
     Lvd_IrqHandler(0);
}

/******************************************************************************/
/*********************************** EXT 0-7 **********************************/
/******************************************************************************/
void EXTI07_IRQHandler(void)
{
    uint8_t u8val = 0;
    uint8_t i = 0;

    u8val = M0P_IRQC->IRQ04PEND;

    for (i = 0; i < 8; i++)
    {
        if ( (u8val &(1u<<i)) > 0)
        {
            Exti_07IrqHandler(i);
        }
    }
}

/******************************************************************************/
/*********************************** EXT 8-15 *********************************/
/******************************************************************************/
void EXTI815_IRQHandler(void)
{
    uint8_t u8val = 0;
    uint8_t i = 0;

    u8val = M0P_IRQC->IRQ05PEND;

    for (i = 0; i < 8; i++)
    {
        if ( (u8val&(1u<<i)) > 0 )
        {
            Exti_815IrqHandler(8+i);
        }
    }
}

/******************************************************************************/
/*********************************** DTIM *************************************/
/******************************************************************************/
void DTIM_IRQHandler(void)
{
    uint32_t u32IrqMon = M0P_IRQC->IRQ06PEND;         // DT interrupt.

    if (0u != (u32IrqMon & 0x00000001ul))
    {
        Dt_IrqHandler(1);
    }

    if (0u != (u32IrqMon & 0x00000002ul))
    {
        Dt_IrqHandler(2);
    }
}
/******************************************************************************/
/*********************************** MSC0 - RX ********************************/
/******************************************************************************/
void MSC0RX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC0_UART->MR_f.MODE;
    MSCRX_IRQHander2(0,u8Mode);
   
}

/******************************************************************************/
/*********************************** MSC0 - TX ********************************/
/******************************************************************************/
void MSC0TX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC0_UART->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ08PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(0,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(0,u8Mode);
    }
}

/******************************************************************************/
/*********************************** MSC1 - RX ********************************/
/******************************************************************************/
void MSC1RX_IRQHandler(void)
{ 
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC1_UART->MR_f.MODE;
    MSCRX_IRQHander2(1,u8Mode);
}

/******************************************************************************/
/*********************************** MSC1 - TX ********************************/
/******************************************************************************/
void MSC1TX_IRQHandler(void)
{ 
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC1_UART->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ10PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(1,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(1,u8Mode);
    }
}

/******************************************************************************/
/*********************************** MSC2 - RX ********************************/
/******************************************************************************/
void MSC2RX_IRQHandler(void)
{ 
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC2_UART->MR_f.MODE;
    MSCRX_IRQHander2(2,u8Mode);
}

/******************************************************************************/
/*********************************** MSC2 - TX ********************************/
/******************************************************************************/
void MSC2TX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC2_UART->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ12PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(2,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(2,u8Mode);
    }
}

/******************************************************************************/
/*********************************** MSC4 - RX ********************************/
/******************************************************************************/
void MSC4RX_IRQHandler(void)
{ 
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC4_SPI->MR_f.MODE;
    MSCRX_IRQHander2(4,u8Mode);
}

/******************************************************************************/
/*********************************** MSC4 - TX ********************************/
/******************************************************************************/
void MSC4TX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC4_SPI->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ16PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(4,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(4,u8Mode);
    }
}

/******************************************************************************/
/*********************************** MSC5 - RX ********************************/
/******************************************************************************/
void MSC5RX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC5_SPI->MR_f.MODE;
    MSCRX_IRQHander2(5,u8Mode);
}

/******************************************************************************/
/*********************************** MSC5 - TX ********************************/
/******************************************************************************/
void MSC5TX_IRQHandler(void)
{ 
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC5_SPI->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ18PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(5,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(5,u8Mode);
    }

}

/******************************************************************************/
/*********************************** MSC6 - RX ********************************/
/******************************************************************************/
void MSC6RX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    u8Mode = M0P_MSC6_SPI->MR_f.MODE;
    MSCRX_IRQHander2(6,u8Mode);
}

/******************************************************************************/
/*********************************** MSC6 - TX ********************************/
/******************************************************************************/
void MSC6TX_IRQHandler(void)
{
    uint8_t u8Mode = 0;
    uint32_t u32Val = 0;

    u8Mode = M0P_MSC6_SPI->MR_f.MODE;
    u32Val = M0P_IRQC->IRQ20PEND;

    if (0u != (u32Val & 0x2u))
    {
        MSCSTAT_IRQHander2(6,u8Mode);
    }
    if (0u != (u32Val & 0x1u))
    {
        MSCTX_IRQHander2(6,u8Mode);
    }
}

/******************************************************************************/
/******************************* OSC/WU/RTC ***********************************/
/*****ext hcr, ext lcr, RTC, MSC DS,RAM     ***********************************/
/******************************************************************************/
void OSC_WU_RTC_IRQHandler(void)
{
    uint32_t u32Val = M0P_IRQC->IRQ24PEND;

    if (0u != (u32Val & (1 << 0)))
    {
        Clk_HSXTRdy_IrqHandler(0);
    }

    if (0u != (u32Val & (1 << 1)))
    {
        Clk_HSXTRdy_IrqHandler(0);
    }

    if (0u != (u32Val & (1 << 5)))
    {
        Rtc_IrqHandler(1);
    }

    if (0u != (u32Val & (1 << 6)))
    {
        Wkup_IrqHandler(0);
    }

    if (0u != (u32Val & (1 << 7)))
    {
        Rami_IrqHandler(0);
    }

}

/******************************************************************************/
/*********************************** ADC **************************************/
/******************************************************************************/
void ADC_IRQHandler(void)
{
    uint32_t u32Val = M0P_IRQC->IRQ25PEND;

    if (0u != (u32Val & (1 << 0)))
    {
        Adc_ConvIrqHandler(0);
    }

    if (0u != (u32Val & (1 << 4)))
    {
        Adc_CmpIrqHandler(0);
    }

}

/******************************************************************************/
/*********************************** VC ***************************************/
/******************************************************************************/
void VC_IRQHandler(void)
{
    Vc_IrqHandler(0);
}

/******************************************************************************/
/*********************************** SCI **************************************/
/******************************************************************************/
void SCI_IRQHandler(void)
{ 
    Sci_IrqHandler(0);
}

/******************************************************************************/
/************************************* CT *************************************/
/******************************************************************************/
void CTIM07_IRQHandler(void)
{
    uint8_t i = 0;
    uint32_t u32Val = M0P_IRQC->IRQ31PEND;

    for (i = 0; i < 8u; i++)
    {
        if ((u32Val & (1u<< (2*i))) > 0)
        {
            Ct_Irq0Handler(i);
        }
        
        if ( (u32Val & (2u << (2*i))) > 0 )
        {
            Ct_Irq1Handler(i);
        }
    }
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
