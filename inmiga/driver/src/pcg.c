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
/** \file pcg.c
 **
 ** PCG driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-25  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "pcg.h"

/**
 ******************************************************************************
 ** \addtogroup PcgGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define IS_VALID_PERIPHERAL(x) ( (x) <= LCDC )

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/

/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/

/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/

/**
 *****************************************************************************
 ** \brief Enable Peripheral's CLK
 **
 ** This function enables the peripheral's CLK.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_EnableCLK(en_peripheral_t enPeri)
{
    en_result_t             enResult = Ok;
    
    switch (enPeri)
    {
        case MSC0:
        {
            M0P_PCG->CLKEN0_f.MSCCLK0 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK0)
            {
                ;
            }
        }
        break;
        case MSC1:
        {
            M0P_PCG->CLKEN0_f.MSCCLK1 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK1)
            {
                ;
            }
        }
        break;
        case MSC2:
        {
            M0P_PCG->CLKEN0_f.MSCCLK2 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK2)
            {
                ;
            }
        }
        break;
        case LMSC0:
        {
            M0P_PCG->CLKEN0_f.MSCCLK4 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK4)
            {
                ;
            }
        }
        break;
        case LMSC1:
        {
            M0P_PCG->CLKEN0_f.MSCCLK5 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK5)
            {
                ;
            }
        }
        break;
        case LMSC2:
        {
            M0P_PCG->CLKEN0_f.MSCCLK6 = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.MSCCLK6)
            {
                ;
            }
        }
        break; 
        case ADC:
        {
            M0P_PCG->CLKEN0_f.ADCCLK  = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.ADCCLK)
            {
                ;
            }
        }
        break;
        case GPIO:
        {
            M0P_PCG->CLKEN0_f.GIOCLK  = TRUE;
            while(TRUE != M0P_PCG->CLKEN0_f.GIOCLK)
            {
                ;
            }
        }
        break;   
        case CTM0_3:
        {
            M0P_PCG->CLKEN1_f.CTMCLK0123  = TRUE;
            while(TRUE != M0P_PCG->CLKEN1_f.CTMCLK0123)
            {
                ;
            }
        }
        break;
        case CTM4_7:
        {
            M0P_PCG->CLKEN1_f.CTMCLK4567  = TRUE;
            while(TRUE != M0P_PCG->CLKEN1_f.CTMCLK4567)
            {
                ;
            }
        }
        break;
        case VC:
        {
            M0P_PCG->CLKEN1_f.VCCLK       = TRUE;
            while(TRUE != M0P_PCG->CLKEN1_f.VCCLK)
            {
                ;
            }
        }
        break;    
        case BUZZER:
        {
            M0P_PCG->CLKEN2_f.BUZCLK      = TRUE;
            while(TRUE != M0P_PCG->CLKEN2_f.BUZCLK)
            {
                ;
            }
        }
        break;
        case AES:
        {
            M0P_PCG->CLKEN2_f.AESCLK      = TRUE;
            while(TRUE != M0P_PCG->CLKEN2_f.AESCLK)
            {
                ;
            }
        }
        break;   
        case SCI:
        {
            M0P_PCG->CLKEN2_f.SCICLK      = TRUE;
            while(TRUE != M0P_PCG->CLKEN2_f.SCICLK)
            {
                ;
            }
        }
        break;   
        case LCDC:
        {
            M0P_PCG->CLKEN2_f.LCDCCLK     = TRUE;
            while(TRUE != M0P_PCG->CLKEN2_f.LCDCCLK)
            {
                ;
            }
        }
        break;  
        default:
        {
            enResult = ErrorInvalidParameter;
        }
        break;
    }

    return (enResult);
}

/**
 *****************************************************************************
 ** \brief Disable Peripheral's CLK
 **
 ** This function Disables the peripheral's CLK.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_DisableCLK(en_peripheral_t enPeri)
{
    en_result_t             enResult = Ok;
    
    switch (enPeri)
    {
        case MSC0:
        {
            M0P_PCG->CLKEN0_f.MSCCLK0 = FALSE;
        }
        break;
        case MSC1:
        {
            M0P_PCG->CLKEN0_f.MSCCLK1 = FALSE;
        }
        break;
        case MSC2:
        {
            M0P_PCG->CLKEN0_f.MSCCLK2 = FALSE;
        }
        break;
        case LMSC0:
        {
            M0P_PCG->CLKEN0_f.MSCCLK4 = FALSE;
        }
        break;
        case LMSC1:
        {
            M0P_PCG->CLKEN0_f.MSCCLK5 = FALSE;
        }
        break;
        case LMSC2:
        {
            M0P_PCG->CLKEN0_f.MSCCLK6 = FALSE;
        }
        break; 
        case ADC:
        {
            M0P_PCG->CLKEN0_f.ADCCLK  = FALSE;
        }
        break;
        case GPIO:
        {
            M0P_PCG->CLKEN0_f.GIOCLK  = FALSE;
        }
        break;   
        case CTM0_3:
        {
            M0P_PCG->CLKEN1_f.CTMCLK0123  = FALSE;
        }
        break;
        case CTM4_7:
        {
            M0P_PCG->CLKEN1_f.CTMCLK4567  = FALSE;
        }
        break;
        case VC:
        {
            M0P_PCG->CLKEN1_f.VCCLK       = FALSE;
        }
        break;    
        case BUZZER:
        {
            M0P_PCG->CLKEN2_f.BUZCLK      = FALSE;
        }
        break;
        case AES:
        {
            M0P_PCG->CLKEN2_f.AESCLK      = FALSE;
        }
        break;   
        case SCI:
        {
            M0P_PCG->CLKEN2_f.SCICLK      = FALSE;
        }
        break;   
        case LCDC:
        {
            M0P_PCG->CLKEN2_f.LCDCCLK     = FALSE;
        }
        break;  
        default:
        {
            enResult = ErrorInvalidParameter;
        }
        break;
    }

    return (enResult);
}

/**
 *****************************************************************************
 ** \brief Disable Peripheral's RST
 **
 ** This function Disables the peripheral's RST.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_EnableRST(en_peripheral_t enPeri)
{
    en_result_t             enResult = Ok;

    switch (enPeri)
    {
        case MSC0:
        {
            M0P_PCG->RSTCTL0_f.MSCRST0 = TRUE;
        }
        break;
        case MSC1:
        {
            M0P_PCG->RSTCTL0_f.MSCRST1 = TRUE;
        }
        break;
        case MSC2:
        {
            M0P_PCG->RSTCTL0_f.MSCRST2 = TRUE;
        }
        break;
        case LMSC0:
        {
            M0P_PCG->RSTCTL0_f.MSCRST4 = TRUE;
        }
        break;
        case LMSC1:
        {
            M0P_PCG->RSTCTL0_f.MSCRST5 = TRUE;
        }
        break;
        case LMSC2:
        {
            M0P_PCG->RSTCTL0_f.MSCRST6 = TRUE;
        }
        break; 
        case ADC:
        {
            M0P_PCG->RSTCTL0_f.ADCRST  = TRUE;
        }
        break;
        case CTM0_3:
        {
            M0P_PCG->RSTCTL1_f.CTMRST0123  = TRUE;
        }
        break;
        case CTM4_7:
        {
            M0P_PCG->RSTCTL1_f.CTMRST4567  = TRUE;
        }
        break;
        case VC:
        {
            M0P_PCG->RSTCTL1_f.VCRST       = TRUE;
        }
        break;    
        case BUZZER:
        {
            M0P_PCG->RSTCTL2_f.BUZRST      = TRUE;
        }
        break;
        case AES:
        {
            M0P_PCG->RSTCTL2_f.AESRST      = TRUE;
        }
        break;   
        case SCI:
        {
            M0P_PCG->RSTCTL2_f.SCIRST      = TRUE;
        }
        break;   
        case LCDC:
        {
            M0P_PCG->RSTCTL2_f.LCDCRST     = TRUE;
        }
        break;  
        default:
        {
            enResult = ErrorInvalidParameter;
        }
        break;
    }

    return (enResult);
}

/**
 *****************************************************************************
 ** \brief Disable Peripheral's RST
 **
 ** This function Disables the peripheral's RST.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_DisableRST(en_peripheral_t enPeri)
{
    en_result_t             enResult = Ok;

    switch (enPeri)
    {
        case MSC0:
        {
            M0P_PCG->RSTCTL0_f.MSCRST0 = FALSE;
        }
        break;
        case MSC1:
        {
            M0P_PCG->RSTCTL0_f.MSCRST1 = FALSE;
        }
        break;
        case MSC2:
        {
            M0P_PCG->RSTCTL0_f.MSCRST2 = FALSE;
        }
        break;
        case LMSC0:
        {
            M0P_PCG->RSTCTL0_f.MSCRST4 = FALSE;
        }
        break;
        case LMSC1:
        {
            M0P_PCG->RSTCTL0_f.MSCRST5 = FALSE;
        }
        break;
        case LMSC2:
        {
            M0P_PCG->RSTCTL0_f.MSCRST6 = FALSE;
        }
        break; 
        case ADC:
        {
            M0P_PCG->RSTCTL0_f.ADCRST  = FALSE;
        }
        break;
        case CTM0_3:
        {
            M0P_PCG->RSTCTL1_f.CTMRST0123  = FALSE;
        }
        break;
        case CTM4_7:
        {
            M0P_PCG->RSTCTL1_f.CTMRST4567  = FALSE;
        }
        break;
        case VC:
        {
            M0P_PCG->RSTCTL1_f.VCRST       = FALSE;
        }
        break;    
        case BUZZER:
        {
            M0P_PCG->RSTCTL2_f.BUZRST      = FALSE;
        }
        break;
        case AES:
        {
            M0P_PCG->RSTCTL2_f.AESRST      = FALSE;
        }
        break;   
        case SCI:
        {
            M0P_PCG->RSTCTL2_f.SCIRST      = FALSE;
        }
        break;   
        case LCDC:
        {
            M0P_PCG->RSTCTL2_f.LCDCRST     = FALSE;
        }
        break;  
        default:
        {
            enResult = ErrorInvalidParameter;
        }
        break;
    }

    return (enResult);
}

/**
 *****************************************************************************
 ** \brief Stop peripheral CLK
 **
 ** This function Stop peripheral CLK.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval Error       If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_Stop(en_peripheral_t enPeri)
{
    ASSERT(IS_VALID_PERIPHERAL(enPeri));
    
    if (Ok != Pcg_DisableCLK(enPeri))
    {
        return Error;
    }
    
    if (Ok != Pcg_EnableRST(enPeri))
    {
        return Error;
    }
    
    if (Ok != Pcg_DisableRST(enPeri))
    {
        return Error;
    }
    
    return Ok;
}

/**
 *****************************************************************************
 ** \brief Recovery peripheral CLK
 **
 ** This function Recovery peripheral CLK.
 **
 ** \param [in]  enPeri             peripheral name
 **
 ** \retval Ok                    Process successfully done.
 ** \retval Error       If one of following conditions are met:
 **                                 - enPeri is invalid
 **
 *****************************************************************************/
en_result_t Pcg_Recovery(en_peripheral_t enPeri)
{
    ASSERT(IS_VALID_PERIPHERAL(enPeri));
    
    if (Ok != Pcg_EnableRST(enPeri))
    {
        return Error;
    }
    
    if (Ok != Pcg_DisableRST(enPeri))
    {
        return Error;
    }
    
    if (Ok != Pcg_EnableCLK(enPeri))
    {
        return Error;
    }
    
    return Ok;
}

//@} // PcgGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

