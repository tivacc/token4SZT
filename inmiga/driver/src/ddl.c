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
/** \file ddl.c
 **
 ** Common API of DDL.
 ** @link ddlGroup Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/*****************************************************************************/
/* Include files                                                             */
/*****************************************************************************/
#include "ddl.h"
#include "clk.h"

/**
 ******************************************************************************
 ** \addtogroup DDL Common Functions
 ******************************************************************************/
//@{

/*****************************************************************************/
/* Local pre-processor symbols/macros ('#define')                            */
/*****************************************************************************/

/*****************************************************************************/
/* Global variable definitions (declared in header file with 'extern')       */
/*****************************************************************************/

/*****************************************************************************/
/* Local type definitions ('typedef')                                        */
/*****************************************************************************/

/*****************************************************************************/
/* Local variable definitions ('static')                                     */
/*****************************************************************************/

/*****************************************************************************/
/* Local function prototypes ('static')                                      */
/*****************************************************************************/
#include <stdio.h>


typedef int FILEHANDLE;
/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/**
 *****************************************************************************
 ** \brief Memory clear function
 *****************************************************************************/
void ddl_memclr(void *pu32Address, uint32_t u32Count)
{
    uint8_t *pu8Addr = (uint8_t *)pu32Address;

    if (NULL == pu8Addr)
    {
        return;
    }

    while (u32Count > 0)
    {
        u32Count -= 1u;
        *pu8Addr = 0u;
        pu8Addr+=1;
    }
}

/**
 *****************************************************************************
 ** \brief Hook function, which is called in polling loops
 *****************************************************************************/
void DDL_WAIT_LOOP_HOOK(void)
{
    // Place code for triggering Watchdog counters here, if needed
}

/**
 *****************************************************************************
 ** \brief debug printf function.
 *****************************************************************************/
void Debug_UartInit(void)
{
#ifdef __DEBUG
    uint32_t u32Pclk1 =  0;
    volatile uint32_t u32ReloadVal = 0;
    M0P_MSC_UART_TypeDef *pstcUart = M0P_MSC0_UART;

    //SOT0_0/P12
    M0P_GPIO->FN1_f.P12 = 1;
    M0P_GPIO->FN_SEL05_f.SOT0B = 1;

    pstcUart->MR_f.MODE = 0u;
    pstcUart->MR_f.DOE = 1;
    pstcUart->MR_f.SBLS = 1;

    u32Pclk1 = Clk_GetPeripheralClk(ClkPeriphralMsc);
    u32ReloadVal = u32Pclk1 / 115200 - 1;
    pstcUart->ECR_f.PS = 1;
    pstcUart->BRS_f.BRS = u32ReloadVal;

    pstcUart->CR_f.TXE = 1;

#endif
}


void Debug_Output(uint8_t u8Data)
{
    M0P_MSC_UART_TypeDef *pstcUart = M0P_MSC0_UART;

    while (TRUE != pstcUart->SR_f.TDEF)
    {
        ;
    }
    pstcUart->TXDR = u8Data;
}


/**
 ******************************************************************************
 ** \brief delay1ms 
 **        delay aproximately 1ms.
 ** 
 ** \param [IN] u32Cnt  :  numbers of 1ms
 ** 
 ** \retval void 
 ******************************************************************************/
void delay1ms(uint32_t u32Cnt)
{
    volatile uint32_t i = 0;
    uint32_t u32Cyc = 0;

    u32Cyc = Clk_GetSystemClk();
    u32Cyc = u32Cyc / 100000;

    while ( u32Cnt > 0u)
    {
        u32Cnt -=1u;
        i = u32Cyc;
        while (i> 0u)
        {
            i = i-1;
        }
    }
}




extern void Debug_UartInit(void);
extern void Debug_Output(uint8_t u8Data);

#if defined (__CC_ARM)          //KEIL
#pragma import(__use_no_semihosting)
_sys_exit(int x)
{
    x = x;
}
struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
/* is required. */
};
/* FILE is typedef¡¯ d in stdio.h. */
FILE __stdout;

#endif


/**
 ******************************************************************************
 ** \brief  Re-target putchar function
 ******************************************************************************/
int fputc(int ch, FILE *f)
{

    if (((uint8_t)ch) == '\n')
    {
        Debug_Output('\r');
    }
    Debug_Output(ch);

    return ch;
}

void _ttywrch(int c)
{
}


int __backspace(void)
{
    return 0;
}
//@} // DDL Functions

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

