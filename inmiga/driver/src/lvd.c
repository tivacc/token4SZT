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
/** \file lvd.c
 **
 ** Low Voltage Detect driver API.
 ** @link Lvd Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************
 * Include files
 ******************************************************************************/
#include "lvd.h"

/**
 ******************************************************************************
 ** \addtogroup Lvd Group
 ******************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 ******************************************************************************/
#define SES_KEY                 (0x55AA)


#define IS_VALID_TYPE(x)        ( LvdType1 == (x) || LvdType2 == (x)) 

#define IS_VALID_STAT(x)        (   Lvd1StatIrq == (x)||\
                                Lvd1StatVol == (x)||\
                                Lvd2StatIrq == (x)||\
                                Lvd2StatSense == (x)||\
                                Lvd2StatVol == (x))

#define IS_VALID_INPUT(x)       (   LvdInputVCC == (x) ||\
                                LvdInputVDD == (x) ||\
                                LvdInputPIN == (x) )

#define IS_VALID_THRESHOLD1(x)  ( (x)<=Lvd1TH3_60V )

#define IS_VALID_THRESHOLD2(x)  ( (x)<=Lvd2TH2_70V )

#define IS_VALID_FILTER(x)      ( (x)<=LvdFilter64ms )

#define IS_VALID_IRQTYPE1(x)    ( (x) <= Lvd1IrqBoth )

#define IS_VALID_SES(x)         ( (x) <= LvdSes2_00V )


/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')        *
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 ******************************************************************************/
static void LvdEnableNvic(void);
static void LvdDisableNvic(void);
static en_result_t LvdEnable(en_lvd_type_t enType, boolean_t bFlag);

/******************************************************************************
 * Local variable definitions ('static')
 ******************************************************************************/
static func_ptr_t    pfnLvdIrqCbk[LvdTypeMax];

/*****************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/
void Lvd_IrqHandler(uint8_t u8Param)
{
    if (TRUE == Lvd_GetStat(Lvd1StatIrq))
    {
        M0P_WSUNIT->LVD_CLR = 0;
        if (NULL != pfnLvdIrqCbk[LvdType1])
        {
            pfnLvdIrqCbk[LvdType1]();
        }
    }

    if (TRUE == Lvd_GetStat(Lvd2StatIrq))
    {
        if (NULL != pfnLvdIrqCbk[LvdType2])
        {
            pfnLvdIrqCbk[LvdType2]();
        }
        M0P_WSUNIT->LVD2_CLR = 0;
    }
}


/**
 * \brief   LvdEnableNvic 
 * \param   [in]             
 * \retval  void             
 */
static void LvdEnableNvic(void)
{
    NVIC_ClearPendingIRQ(LVD_IRQn);
    NVIC_SetPriority(LVD_IRQn, DDL_IRQ_LEVEL_DEFAULT);
    NVIC_EnableIRQ(LVD_IRQn);
}

/**
 * \brief   LvdDisableNvic 
 * \param   [in]             
 * \retval  void             
 */
static void LvdDisableNvic(void)
{
    NVIC_ClearPendingIRQ(LVD_IRQn);
    NVIC_DisableIRQ(LVD_IRQn);
    NVIC_SetPriority(LVD_IRQn, DDL_IRQ_LEVEL_DEFAULT);
}


/**
 * \brief   LvdEnable 
 * 
 * \param   [in]  enType    LVD channel 
 *                          LVD1
 *                          LVD2
 * \param   [in]  bFlag     TRUE = enable 
 *                          FALSE = Disable 
 * 
 * \retval  en_result_t     Ok:      Lvd Set  successfully 
 *       
 */
static en_result_t LvdEnable(en_lvd_type_t enType, boolean_t bFlag)
{
    ASSERT(IS_VALID_TYPE(enType));

    bFlag = bFlag & 1;

    //wait BGR
    M0P_WSUNIT->BGR_CTL_f.BGR_EN = bFlag;
    delay1ms(2);                         //> 30us delay.

    switch (enType)
    {
        case LvdType1:
            M0P_WSUNIT->LVD_CTRL1_f.LVD_EN = bFlag;
            break;
        case LvdType2:
            M0P_WSUNIT->LVD2_CTL_f.LVD2_EN = !bFlag;
            break;
        default:
            break;
    }

    return Ok;
}


/**
 * \brief   LvdEnableIrq 
 *          enable/disable a lvd interrupt event
 * \param   [in]  enType             lvd interrupt event
 * \param   [in]  bFlag              TRUE:      Enable 
 *                                   FALSE:     Disable 
 * 
 * \retval  en_result_t              Ok:     set Event done 
 *                                   ErrorInvalidParameter: invalid enType 
 */
static en_result_t LvdEnableIrq(en_lvd_irq_type_t enType, boolean_t bFlag)
{
    en_result_t enRet = Ok;
    
    ASSERT(IS_VALID_TYPE(enType));

    bFlag = bFlag & 1;

    switch (enType)
    {
        case Lvd1IrqNone:
        case Lvd1IrqLow:
        case Lvd1IrqHigh:
        case Lvd1IrqBoth:
            if (TRUE == bFlag)
            {
                M0P_WSUNIT->LVD_CTRL1_f.LVD_EN = enType;
            }else{
                M0P_WSUNIT->LVD_CTRL1_f.LVD_EN = Lvd1IrqNone;
            }
            break;
        case Lvd2Irq:
            M0P_WSUNIT->LVD_CTRL2_f.LVD_IE = bFlag;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }

    return enRet;
}


en_result_t Lvd_EnableIrq(en_lvd_irq_type_t enType)
{
    return LvdEnableIrq(enType,TRUE);
}

en_result_t Lvd_DisableIrq(en_lvd_irq_type_t enType)
{
    return LvdEnableIrq(enType,FALSE);
}

/**
 * \brief   Lvd1_Init 
 *          LVD1 init function.
 *  
 * \param   [in]  pstcConfig   Pointer to LVD1 config data
 *                             
 * \retval  en_result_t        Ok:      Lvd init successfully 
 *                             ErrorInvalidParameter: enType is invalid.
 */
en_result_t Lvd1_Init(stc_lvd1_config_t *pstcConfig)
{
    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_INPUT(pstcConfig->enInput));
    ASSERT(IS_VALID_THRESHOLD1(pstcConfig->enThreshold));
    ASSERT(IS_VALID_FILTER(pstcConfig->enFilterTime));
    ASSERT(IS_VALID_IRQTYPE1(pstcConfig->enIrqType));

    //NEED to DISABLE first.
    Lvd_Disable(LvdType1);

    M0P_WSUNIT->LVD_CTRL1_f.LVD_SRST = pstcConfig->bLvdReset;
    M0P_WSUNIT->LVD_CTRL1_f.LVD_VIN = pstcConfig->enInput;
    M0P_WSUNIT->LVD_CTRL1_f.LVD_VSET = pstcConfig->enThreshold;
    M0P_WSUNIT->LVD_CTRL2_f.LVD_HYS_EN = pstcConfig->b10mvDly;
    M0P_WSUNIT->LVD_CTRL2_f.LVD_F_EN = pstcConfig->bFilter;
    M0P_WSUNIT->LVD_CTRL2_f.LVD_F_SET = pstcConfig->enFilterTime;

    //enable irq
    pfnLvdIrqCbk[LvdType1] = NULL;
    if (pstcConfig->enIrqType != Lvd1IrqNone)
    {
        M0P_WSUNIT->LVD_CTRL2_f.LVD_IE = pstcConfig->enIrqType;
        LvdEnableNvic();
        pfnLvdIrqCbk[LvdType1] = pstcConfig->pfnIrqCbk;
    }

    return Ok;
}

/**
 * \brief   Lvd1_DeInit 
 *          Deinit LVD1 channel
 * 
 * \param   [in]  bNvic      if need to clear NVIC flag.
 * 
 * \retval  en_result_t      Ok:    deinit LVD1 done.
 */
en_result_t Lvd1_DeInit(boolean_t bNvic)
{
    Lvd_ClearIrq(LvdType1);
    pfnLvdIrqCbk[LvdType1] = NULL;
    LvdEnable(LvdType1, FALSE);

    if (TRUE == bNvic)
    {
        LvdDisableNvic();
    }

    return Ok;
}

/**
 * \brief   Lvd2_Init 
 *          LVD2 init function.
 *  
 * \param   [in]  pstcConfig   Pointer to LVD2 config data
 *                             
 * \retval  en_result_t        Ok:      Lvd init successfully 
 *                             ErrorInvalidParameter: enType is invalid.
 */
en_result_t Lvd2_Init(stc_lvd2_config_t *pstcConfig)
{
    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_THRESHOLD2(pstcConfig->enThreshold));

    M0P_WSUNIT->LVD2_CTL_f.LVD2_VSET = pstcConfig->enThreshold;

    //enable irq
    pfnLvdIrqCbk[LvdType2] = NULL;
    M0P_WSUNIT->LVD_CTRL2_f.LVD_IE = pstcConfig->bIrqEn;

    if (TRUE == pstcConfig->bIrqEn)
    {
        LvdEnableNvic();
        pfnLvdIrqCbk[LvdType2] = pstcConfig->pfnIrqCbk;
    }

    return Ok;
}

/**
 * \brief   Lvd2_DeInit 
 *          Deinit LVD2 channel
 * 
 * \param   [in]  bNvic      if need to clear NVIC flag. 
 * \retval  en_result_t      Ok:    deinit LVD2 done.
 */
en_result_t Lvd2_DeInit(boolean_t bNvic)
{
    Lvd_ClearIrq(LvdType2);

    LvdEnable(LvdType2, FALSE);

    if (TRUE == bNvic)
    {
        LvdDisableNvic();
    }
    pfnLvdIrqCbk[LvdType2] = NULL;

    return Ok;
}


/**
 * \brief   LvdEnable 
 * 
 * \param   [in]  enType    LVD channel 
 *                          LVD1
 *                          LVD2
 * \param   [in]  bFlag     TRUE = enable 
 *                          FALSE = Disable 
 * 
 * \retval  en_result_t     Ok:      Lvd Set  successfully 
 *                          ErrorInvalidParameter:  enType is
 *                          invalid.
 *       
 */
en_result_t Lvd_Enable(en_lvd_type_t enType)
{
    return LvdEnable(enType, TRUE);
}

/**
 * \brief   LvdDisable 
 * 
 * \param   [in]  enType    LVD channel 
 *                          LVD1
 *                          LVD2
 * \param   [in]  bFlag     TRUE = enable 
 *                          FALSE = Disable 
 * 
 * \retval  en_result_t     Ok:      Lvd Set  successfully 
 *                          ErrorInvalidParameter:  enType is
 *                          invalid.
 */
en_result_t Lvd_Disable(en_lvd_type_t enType)
{
    return LvdEnable(enType, FALSE);
}

/**
 * \brief   Lvd_GetStat 
 *          Get LVD status flag
 * 
 * \param   [in]  enStat     LVD status type
 * 
 * \retval  boolean_t        the requested type of event flag
 */
boolean_t Lvd_GetStat(en_lvd_stat_t enStat)
{
    boolean_t bFlag = FALSE;

    ASSERT(IS_VALID_STAT(enStat));

    switch (enStat)
    {
        case Lvd1StatIrq:
            bFlag = M0P_WSUNIT->LVD_STR_f.LVD_IRQ;
            break;
        case Lvd1StatVol:
            bFlag = M0P_WSUNIT->LVD_STR_f.LVD_OUT;
            break;
        case Lvd2StatIrq:
            bFlag = M0P_WSUNIT->LVD2_STR_f.LVD2_IRQ;
            break;
        case Lvd2StatSense:
            bFlag = M0P_WSUNIT->LVD2_STR_f.SENSE_STA;
            break;
        case Lvd2StatVol:
            bFlag = M0P_WSUNIT->LVD2_STR_f.LVD2_STA;
            break;
        default:
            break;
    }

    return bFlag;
}

/**
 * \brief   Lvd_ClearIrq 
 *          Clear a requested type of LVD event.
 *  
 * \param   [in]  enType     the LVD type to clear
 * 
 * \retval  en_result_t      Ok:     clear done 
 *                           ErrorInvalidParameter: invalid enType
 */
en_result_t Lvd_ClearIrq(en_lvd_type_t enType)
{
    en_result_t enRet = Ok;

    switch (enType)
    {
        case LvdType1:
            M0P_WSUNIT->LVD_CLR_f.LVD_CLR = FALSE;
            break;
        case LvdType2:
            M0P_WSUNIT->LVD2_CLR_f.LVD2_CLR = FALSE;
            break;
        default:
            enRet = ErrorInvalidParameter;
            break;
    }
    return enRet;
}


//@} // Lvd Group

/******************************************************************************
 * EOF (not truncated)
 ******************************************************************************/

