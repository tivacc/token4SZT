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
/** \file main.c
 **
 ** Main Module
 **
 ** \brief This example shows how to init the SCI and use the interrupt mode to 
 ** receive the data from the card.
 **
 ** History:
 **   - 2016-12-08  1.0  QCP        version 1.0
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "gpio.h"
#include "sci.h"

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')                            
 ******************************************************************************/
#define ATRNUMBER 2

#define TEST_0	Gpio_SetIO(0, 7, 0)
#define TEST_1	Gpio_SetIO(0, 7, 1)

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')        
 ******************************************************************************/
uint8_t u8Data[32];
uint8_t u8DataOffset = 0;

uint8_t sciTxPendCnt = 0;
uint8_t sciTxFinFlag = 0;

/******************************************************************************
 * Local type definitions ('typedef')                                         
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/

/******************************************************************************
 * Local variable definitions ('static')                                      *
 ******************************************************************************/

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')                             
 ******************************************************************************/

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief Config the SCI io
 **
 ** \return none
 ******************************************************************************/
void SciIoConfig(void)
{
    //IO configuration
    //Disable AD function
    M0P_GPIO->ANALOG = 0;
    //P52 as RST
    M0P_GPIO->FN5_f.P52 = 1;
    //P50 as ICCLK
    M0P_GPIO->FN5_f.P50 = 1;
    //P51 as ICIO
    M0P_GPIO->FN5_f.P51 = 1;
    //EPFR09 configuration
    M0P_GPIO->FN_SEL09_f.ICCKE = 1;
    M0P_GPIO->FN_SEL09_f.ICIOB = 1;
    M0P_GPIO->FN_SEL09_f.ICRSTE = 1;
    
    Gpio_InitIO(3,6,GpioDirOut,FALSE,FALSE);
    Gpio_SetIO(3, 6, 1);
    
    Gpio_InitIO(0,7,GpioDirOut,FALSE,FALSE);
    TEST_0;
}

/**
 ******************************************************************************
 ** \brief Delay
 **
 ** \return none
 ******************************************************************************/
void Delay(unsigned int i)
{
    unsigned int j = 3000;
    while(i!=0)
    {
        for(;j>0;j--)
        {}
        for(;j>0;j--)
        {}
        for(;j>0;j--)
        {}
        i--;
    }
}

/**
 ******************************************************************************
 ** \brief Receive interrupt call back function
 **
 ** \return none
 ******************************************************************************/
void RxIntCb(void)
{
    Sci_ClearIrqStatus(SciRxFinInt);
    u8Data[u8DataOffset++] = Sci_ReceiveData();
}

void TxIntCb(void)
{
    
    if(Sci_GetIrqStatus(SciTxFinInt))
    {
      Sci_ClearIrqStatus(SciTxFinInt);
    }
    
    if(Sci_GetStatus(SciTxErr))
    {
      Sci_ClearStatus(SciTxErr);      
      sciTxPendCnt = Sci_GetWriteFifoCurCnt();
    }
    
    sciTxFinFlag = 1;
}
/**
 ******************************************************************************
 ** \brief Receive full interrupt call back function
 **
 ** \return none
 ******************************************************************************/
void SciGetDataInt(uint8_t u8Num)
{
    //Enable int
    Sci_EnableIrq(SciRxIrq);
    
    //Init the receive number
    u8DataOffset = 0;
    
    while(u8Num > u8DataOffset)
    {
        ;
    }
    
    Sci_DisableIrq(SciRxIrq);
}
extern void SciIrqHandler(uint8_t u8Dummy);
/**
 ******************************************************************************
 ** \brief  Main function of project
 **
 ** \return uint32_t return value, if needed
 **
 ** This sample
 **
 ******************************************************************************/
uint8_t temp = 0;
int32_t main(void)
{
    uint8_t txDepth = 0;
    stc_sci_config_t stcSciConfig;
    stc_sci_irq_cb_t stcSciIrqCb;
    
    //Init the variable
    DDL_ZERO_STRUCT(stcSciConfig);
    DDL_ZERO_STRUCT(stcSciIrqCb);
    
    SciIoConfig();
    
    // Initialize interrupt callback fucntion
    stcSciIrqCb.pfnRxIrqCb = RxIntCb;               //Rx Callback handler
    stcSciIrqCb.pfnTxIrqCb = TxIntCb;               //Rx Callback handler

    //Config the SCI as needed
    stcSciConfig.enTMode = SciT0Mode;               //T0 Mode
    stcSciConfig.u16BaudRate = 0x174;               //372
    stcSciConfig.bParity = TRUE;                    //Parity check on
    stcSciConfig.enParity = SciParityEven;          //Even
    stcSciConfig.bTouchNvic = TRUE;                 //Use interrupt
    stcSciConfig.enBitDirection = SciDataLsbFirst;  //LSB first
    stcSciConfig.pstcIrqEn->bRxIrq = TRUE;          //Use Interrupt  
    stcSciConfig.u8ResendTimes = 0;                 //Don't need resend
    stcSciConfig.pstcIrqCb = &stcSciIrqCb;          //Callback function
    
    //Sci init
    Sci_Init(&stcSciConfig);
    
    //Set Sci clock
    Sci_SetClock(SciClockNoDiv);

    //Enable Sci clock
    Sci_EnableClock();  
    
    Sci_EnableReset();   
    
    //Clean the Sci status
    Sci_InitStatus();    
    Sci_ClearWriteFifo();    
    Sci_ClearReadFifo();    
    
    //Enable Sci
    Sci_Enable();
    Sci_EnableIrq(SciRxIrq);
    
    Sci_ResetLow();   //rst out low
    Delay(100);    
    Sci_ResetHigh();
     
    Delay(10000);
    Sci_InitStatus();
    Sci_ClearIrqStatus(SciTxFinInt);
    Sci_ClearIrqStatus(SciRxFinInt);
    Sci_ClearIrqStatus(SciEtuCntInt);
    Sci_ClearIrqStatus(SciWakeupInt);
    Sci_ClearWriteFifo();   
    Sci_ClearReadFifo();
    
    u8DataOffset = 0;
    uint8_t sciFifoFulFlag = 0;
    uint8_t sizeArray = 0;
    uint8_t getRandomCmd[5] = {0x00,0x84,0x00,0x00,0x08};
    uint8_t getDesCmd[13] = {0x00,0x88,0x00,0x01,0x08,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
    uint8_t getCardMFCmd[7] = {0x00,0xA4,0x00,0x00,0x02,0x3F,0x00 };
    uint8_t createCardMFCmd[18] = {0x80,0xE0,0x3F,0x00,0x0D,0x38,0xFF,0xFF,0xF0,0xF0,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
    
    sizeArray = sizeof(getCardMFCmd);
    for(uint8_t i=0;i<sizeArray;i++)
    {   
    repeat:
        sciTxFinFlag = 0;
        Sci_SendData(getCardMFCmd[i]);
        if((Sci_GetFifoStatus(SciFifoTxFul)))
        {
          Sci_ClearFifoStatus(SciFifoTxFul);
          while(!sciTxFinFlag) ;
          Sci_ClearWriteFifo();
          i = i + 1 - sciTxPendCnt;
          if(i<sizeArray)          
            goto repeat;
        }
        
        while(!sciTxFinFlag) ;
    }
    
    while(1) ;
    //Sci_DisableIrq(SciRxIrq);
    Sci_Disable();
    
    //Deinit Sci configuration
    Sci_DeInit(TRUE);
    
    
    while (1)
    {
        ;
    }
}

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
