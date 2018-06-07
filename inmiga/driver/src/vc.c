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
/******************************************************************************/
/** \file vc.c
 **
 ** voltage compare driver API.
 ** @link VC Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "vc.h"

/**
 ******************************************************************************
 ** \addtogroup Driver Group
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define IS_VALID_STAT(x)        ( VcCmpResult==(x) || VcACmpResult == (x))
#define IS_VALID_DIV(x)         ( (x) <= 64u )
#define IS_VALID_INPUT(x)       ( (x) <= VcVCIN3 )

#define IS_VALID_INPUT_P(x)     (   VcExtDirect == (x) ||\
                                    VcConverted == (x) ||\
                                    VcIntern2_5V == (x) ||\
                                    VcNone == (x) )

#define IS_VALID_INPUT_N(x)     (   VcExtDirect == (x) || \
                                    VcConverted == (x) || \
                                    VcInnerBGR1_2V == (x) || \
                                    VcInnerBGRCvt == (x) )

#define IS_VALID_DLY(x)         (   (VcDelay30mv == (x)) ||\
                                    (VcDelay20mv == (x)) ||\
                                    (VcDelay10mv == (x)) ||\
                                    (VcDelayoff == (x)) )

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')
 ******************************************************************************/


/******************************************************************************
 * Local type definitions ('typedef')                                         
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static en_result_t VcEnableFunc(en_vc_func_sel_t enFunc, boolean_t bFlag);
static void VcEnableNvic(void);
static void VcDisableNvic(void);

/******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static func_ptr_t m_pfnAnalogCmpCb = NULL;

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief VcEnableFunc 
 **        Voltage compare function enable/disable
 ** 
 ** \param [IN] enFunc  : function enum
 ** \param [IN] bFlag   : enable/disable
 ** 
 ** \retval en_result_t Ok: set done.
 **                     others: set failed.
 ** 
 ******************************************************************************/
static en_result_t VcEnableFunc(en_vc_func_sel_t enFunc, boolean_t bFlag)
{
    en_result_t enRet = Ok;

    switch (enFunc)
    {
        case VcFuncDCvt:
            M0P_VC->CTL1_f.VCDIV_EN = bFlag;
            break;
        case VcFuncACvt:
            M0P_VC->CTL1_f.VC_EN = bFlag;
            break;
        case VcFuncFilter:
            M0P_VC->CTL2_f.VC_FILTER_EN = bFlag;
            break;
        case VcFuncInputAmplify:
            M0P_VC->CTL2_f.VC_EXBUF = bFlag;
            break;
        default:
            enRet= ErrorInvalidParameter;
            break;
    }

    return enRet;
}

/**
 ******************************************************************************
 ** \brief Vc_ConfigIrq 
 **        voltage compare interrupt enable/disable
 ** 
 ** \param [IN] enSel   : function enum
 ** \param [IN] bFlag   : enable/disable
 ** 
 ** \retval en_result_t Ok: set done.
 **                     others: set failed.
 ******************************************************************************/
en_result_t Vc_ConfigIrq(en_vc_irq_sel_t enSel, boolean_t bFlag )
{
    en_result_t enRet = Ok;

    switch (enSel)
    {
        case VcIrqCmpIrqRise:
            M0P_VC->CTL2_f.VCINT_RISING = bFlag;
            break;
        case VcIrqCmpIrqFall:
            M0P_VC->CTL2_f.VCINT_FALLING = bFlag;
            break;
        case VcIrqCmpIrqHigh:
            M0P_VC->CTL2_f.VCINT_HIGH = bFlag;
            break;

        default:
            enRet= ErrorInvalidParameter;
            break;
    }

    return enRet;
}


/**
 ******************************************************************************
 ** \brief VcEnableIrq 
 **        voltage compare enable/disable interrupt
 ** 
 ** \param [IN] bFlag   : enable/disable
 ** 
 ** \retval en_result_t Ok: set done.
 ******************************************************************************/
static en_result_t VcEnableIrq(boolean_t bFlag)
{
    
    M0P_VC->CTL2_f.VCIE = bFlag;
    if (TRUE == bFlag)
    {
        VcEnableNvic();
    }else{
        VcDisableNvic();
    }
    return Ok;
}

/**
 ******************************************************************************
 ** \brief VcEnableNvic 
 **        voltage compare enable NVIC
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void VcEnableNvic(void)
{
    NVIC_ClearPendingIRQ(VC_IRQn);
    NVIC_EnableIRQ(VC_IRQn);
    NVIC_SetPriority(VC_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}

/**
 ******************************************************************************
 ** \brief VcDisableNvic 
 **        voltage compare disable NVIC
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval void 
 ******************************************************************************/
static void VcDisableNvic(void)
{
    NVIC_ClearPendingIRQ(VC_IRQn);
    NVIC_DisableIRQ(VC_IRQn);
    NVIC_SetPriority(VC_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}


/**
 ******************************************************************************
 ** \brief Vc_IrqHandler 
 **        volatage compare interrupt handler
 ** 
 ** \param [IN] u8Param : dummy
 ** 
 ** \retval void 
 ******************************************************************************/
void Vc_IrqHandler(uint8_t u8Param)
{
    stc_vc_ctl2_field_t stcCtl2;

    DDL_ZERO_STRUCT(stcCtl2);

    stcCtl2 = M0P_VC->CTL2_f;

    if (TRUE == stcCtl2.VCIF)
    {
        if (NULL != m_pfnAnalogCmpCb)
        {
            m_pfnAnalogCmpCb();
        }
        stcCtl2.VCIF = 0;
    }
}

/**
 ******************************************************************************
 ** \brief Vc_GetStatus 
 **        voltage compare get factor status
 ** 
 ** \param [IN] enStat  : factor index
 ** 
 ** \retval boolean_t status active/inactive
 ******************************************************************************/
boolean_t Vc_GetStatus(en_vc_stat_t enStat)
{
    boolean_t bFlag = FALSE;

    ASSERT( IS_VALID_STAT(enStat));

    switch (enStat)
    {
        case VcCmpResult:
            bFlag = M0P_VC->CTL1_f.VC_OUT;
            break;
        case VcACmpResult:
            bFlag = M0P_VC->CTL2_f.VCIF;
            break;
        default:
            break;
    }

    return bFlag;
}

/**
 ******************************************************************************
 ** \brief Vc_ClearStat 
 **        voltage compare clear a interrupt status
 ** 
 ** \param [IN] enStat  : 
 ** 
 ** \retval en_result_t 
 ******************************************************************************/
en_result_t Vc_ClearStat(en_vc_stat_t enStat)
{
    en_result_t enRet = Ok; 

    switch (enStat)
    {
        case VcACmpResult:
            M0P_VC->CTL2_f.VCIF = FALSE;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}

/**
 ******************************************************************************
 ** \brief Vc_EnableIrq 
 **        voltage compare interrupt enable
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t Ok: set done
 **                     others: set failed.
 ******************************************************************************/
en_result_t Vc_EnableIrq(void)
{
    return VcEnableIrq(TRUE);
}

/**
 *******************************************************************************
 ** \brief Vc_DisableIrq 
 **        voltage compare interrupt disable 
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t Ok: set done
 **                     others: set failed.
 ******************************************************************************/
en_result_t Vc_DisableIrq(void)
{
    return VcEnableIrq(FALSE);
}

/**
 ******************************************************************************
 ** \brief Vc_Init 
 **        voltage compare initialize
 ** 
 ** \param [IN] pstcConfig  : pointer to configure data structure.
 ** 
 ** \retval en_result_t Ok: initialize done.
 **                     others: initialize failed.
 ******************************************************************************/
en_result_t Vc_Init(stc_vc_config_t *pstcConfig)
{
    en_result_t enRet = Ok;

    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_DIV(pstcConfig->u8ConvertedDiv));
    ASSERT(IS_VALID_INPUT(pstcConfig->enVcInPin_P));
    ASSERT(IS_VALID_INPUT_P(pstcConfig->enVcAnalogInputP));
    ASSERT(IS_VALID_INPUT_N(pstcConfig->enVcAnalogInputN));
    ASSERT(IS_VALID_DLY(pstcConfig->enVcCmpDly));

    M0P_VC->CTL1_f.VCDIV_SEL = pstcConfig->enVcConvertSrc;
    M0P_VC->CTL1_f.VCVOL_SEL = pstcConfig->u8ConvertedDiv;

    switch (pstcConfig->enVcAnalogInputP)
    {
        case VcExtDirect:
            M0P_VC->CTL1_f.VC_PMODE = 0;
            break;
        case VcConverted:
            M0P_VC->CTL1_f.VC_PMODE = 1;
            break;
        case VcIntern2_5V:
            M0P_VC->CTL1_f.VC_PMODE = 2;
            break;
        case VcNone:
            M0P_VC->CTL1_f.VC_PMODE = 3;
            break;
        default:
            break;
    }

    switch (pstcConfig->enVcAnalogInputN)
    {
        case VcExtDirect:
            M0P_VC->CTL1_f.VC_NMODE = 0;
            break;
        case VcConverted:
            M0P_VC->CTL1_f.VC_NMODE = 1;
            break;
        case VcInnerBGR1_2V:
            M0P_VC->CTL1_f.VC_NMODE = 2;
            break;
        case VcInnerBGRCvt:
            M0P_VC->CTL1_f.VC_NMODE = 3;
            break;
        default:
            break;
    }

    M0P_VC->CTL2_f.VC_HYS_SEL = pstcConfig->enVcCmpDly;

    //
    if ( NULL != pstcConfig->pstcIrqSel )
    {
        Vc_ConfigIrq(VcIrqCmpIrqHigh,pstcConfig->pstcIrqSel->bVcCmpIrqHigh);
        Vc_ConfigIrq(VcIrqCmpIrqRise,pstcConfig->pstcIrqSel->bVcCmpIrqRise);
        Vc_ConfigIrq(VcIrqCmpIrqFall,pstcConfig->pstcIrqSel->bVcCmpIrqFall);
    }

    m_pfnAnalogCmpCb = pstcConfig->pfnAnalogCmpCb;

    M0P_VC->CTL2_f.VC2PT = pstcConfig->bACmpOutputReverse;
 
    M0P_VC->CTL3_f.VCIN_POS_SEL = pstcConfig->enVcInPin_P;
    M0P_VC->CTL3_f.VCIN_NEG_SEL = pstcConfig->enVcInPin_N;
    M0P_VC->CTL2_f.VC_EXBUF = pstcConfig->bVcAmpEn;
    M0P_VC->CTL3_f.VC_TM0G = pstcConfig->bTimer0Rev;
    M0P_VC->CTL3_f.VC_TM2G = pstcConfig->bTimer2Rev;

    return enRet;
}

/**
 ******************************************************************************
 ** \brief Vc_DeInit 
 **        voltage compare de-initialize
 ** 
 ** \param [IN] void    : 
 ** 
 ** \retval en_result_t Ok:  deinit done.
 ******************************************************************************/
en_result_t Vc_DeInit(void)
{
    Vc_DisableFunc(VcFuncDCvt);
    Vc_DisableFunc(VcFuncACvt);
    Vc_DisableIrq();

    m_pfnAnalogCmpCb = NULL;
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Vc_EnableFunc 
 **        voltage compare enable a function.
 ** 
 ** \param [IN] enFunc  : function enum
 ** 
 ** \retval en_result_t Ok: enabled
 **                     others: enable failed.
 ******************************************************************************/
en_result_t Vc_EnableFunc(en_vc_func_sel_t enFunc)
{
    return VcEnableFunc(enFunc, TRUE);
}

/**
 ******************************************************************************
 ** \brief Vc_DisableFunc 
 **        voltage compare disable a function.
 ** 
 ** \param [IN] enFunc  : function enum
 ** 
 ** \retval en_result_t Ok: disabled
 **                     others: disable failed.
 ******************************************************************************/
en_result_t Vc_DisableFunc(en_vc_func_sel_t enFunc)
{
    return VcEnableFunc(enFunc, FALSE);
}

//@} // VC Group


/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

