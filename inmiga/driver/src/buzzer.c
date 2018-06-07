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
/** \file buzzer.c
 **
 ** Buzzer driver API.
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of
 **                      Module.
 **
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "buzzer.h"

/**
 ******************************************************************************
 ** \addtogroup Buzz Group
 *****************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/
#define IS_VALID_CLKSRC(x)              ( (ClkHICR == (x)) || (ClkLICR == (x)))

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')        *
 *****************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 *****************************************************************************/
static en_result_t BuzzerStart(boolean_t bFlag);


/******************************************************************************
 * Local variable definitions ('static')
 *****************************************************************************/
static en_result_t BuzzerStart(boolean_t bFlag)
{
    bFlag = bFlag & 0x1;

    M0P_BUZZER->BUZ_CTL_f.BUZ_ST = bFlag;

    return Ok;
}
/******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/


/**
 ******************************************************************************
 ** \brief Buzzer_Init 
 **        buzzer modude init
 ** 
 ** \param [IN] enSrc   : 
 ** 
 * \param   [in]  enSrc         buzz module clock source
 *                              Hcr -> Hcr/512
 *                              Lcr -> 8k
 * \retval  en_result_t         Ok:     init done
 *                              ErrorInvalidParameter: enSrc is invalid
 ******************************************************************************/
en_result_t Buzzer_Init(en_clk_source_t enSrc)
{
    en_result_t enRet = Ok;
    ASSERT(IS_VALID_CLKSRC(enSrc));
    switch (enSrc)
    {
        case ClkHICR:
            M0P_BUZZER->BUZ_CTL_f.CLK_SEL = 0;
            break;
        case ClkLICR:
            M0P_BUZZER->BUZ_CTL_f.CLK_SEL = 1;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;

    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief Buzzer_DeInit 
 **        Buzzer_DeInit the buzz module
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t     Ok: reset done.
 ******************************************************************************/
en_result_t Buzzer_DeInit(void)
{
    Buzzer_Stop();
    M0P_BUZZER->BUZ_CTL_f.CLK_SEL = 0u;
    return Ok;
}


/**
 ******************************************************************************
 ** \brief Buzzer_Start 
 **        start buzz pin output.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t     Ok: set done.
 ******************************************************************************/
en_result_t Buzzer_Start(void)
{
    return BuzzerStart(TRUE);
}


/**
 ******************************************************************************
 ** \brief Buzzer_Stop 
 **        stop buzz pin output.
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t     Ok: set done.
 ******************************************************************************/
en_result_t Buzzer_Stop(void)
{
    return BuzzerStart(FALSE);
}


/**
 ******************************************************************************
 ** \brief Buzzer_GetCount 
 **        get the buzz ouput clock
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval uint32_t    output clock number.
 ******************************************************************************/
uint32_t Buzzer_GetCount(void)
{
    return M0P_BUZZER->BUZ_CNT;
}


/**
 ******************************************************************************
 ** \brief Buzzer_SetCount 
 **        set the buzz output count. formula is:
 **
 **        freq = (apb)/512/(256-u8Cnt) eg. u8Cnt = 250, apb=4Mhz,output wave
 **        is: freq = 4M(apb)/512/(256-250) = /2 = 651hz;
 ** 
 ** \param [IN] u8Cnt   : 
 ** 
 ** \retval en_result_t     Ok: set done.
 ******************************************************************************/
en_result_t Buzzer_SetCount(uint8_t u8Cnt)
{
    M0P_BUZZER->BUZ_CNT = u8Cnt;
    return Ok;
}

//@} // Buzzer Group
/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

