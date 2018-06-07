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
/** \file aes.c
 **
 ** AES driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-26  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "aes.h"

/**
 ******************************************************************************
 ** \addtogroup AES Group
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define IS_VALID_DUMMYSEL(x) ( AESDummy7  == (x) ||\
                               AESDummy15 == (x) ||\
                               AESDummy31 == (x) ||\
                               AESDummy63 == (x)     )

#define IS_VALID_KEYSEL(x)   ( AESKey128 == (x) ||\
                               AESKey192 == (x) ||\
                               AESKey256 == (x)     )     

#define IS_VALID_DFAEN(x)    ( AESDfaEnable == (x) || AESDfaDisable == (x) )

#define IS_VALID_DIV(x)      ( AESDiv0 == (x) || AESDiv2 == (x) ) 

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief AES Function Select
 ** To select the AES encrypt or decrypt
 ******************************************************************************/
typedef enum
{
    AESEncrypt        = 0u,   ///< AES encrypt set  
    AESDecrypt        = 1u    ///< AES decrypt set
} en_aes_func_t;

/**
 ******************************************************************************
 ** \brief AES DFA status
 ** 
 ** AES DFA status 
 ******************************************************************************/
typedef enum
{
    AESDfaPass          = 0u,  ///< DFA detect successful
    AESDfaFail          = 1u   ///< DFA detect failed
} en_aes_dfa_sta_t;

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
 ** \brief AES encrypt
 **
 ** This function encrypt AES data and output ciphertext.
 **
 **
 ** \param [in]  pstcConfig        AES config
 ** \param [out] pu8Ciphertext    The pointer of AES ciphertext
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - pstcConfig is invalid
 ** \retval Error If one of following conditions are met:
 **                                 - DFA fail
 *****************************************************************************/
en_result_t AES_Encrypt(stc_aes_config_t* pstcConfig, uint8_t* pu8Ciphertext)
{
    en_result_t             enResult = Ok;
    uint32_t                *pu32AESRand;
    uint32_t                *pu32AESData;
    uint32_t                *pu32AESKey;
    uint32_t                *pu32Ciphertext;
    
    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_DUMMYSEL(pstcConfig->enDummySel));
    ASSERT(IS_VALID_KEYSEL(pstcConfig->enKeySel));
    ASSERT(IS_VALID_DFAEN(pstcConfig->enDfaEn));
    ASSERT(IS_VALID_DIV(pstcConfig->enDiv));
    
    //Init
    pu32AESRand    = (uint32_t*)pstcConfig->pu8AESRand;
    pu32AESData    = (uint32_t*)pstcConfig->pu8AESData;
    pu32AESKey     = (uint32_t*)pstcConfig->pu8AESKey;
    pu32Ciphertext = (uint32_t*)pu8Ciphertext;
    
    //Random number config
    M0P_AES->RNG0 = pu32AESRand[0];
    M0P_AES->RNG1 = pu32AESRand[1];
    
    //Key config
    M0P_AES->KEY0 = pu32AESKey[0];
    M0P_AES->KEY1 = pu32AESKey[1];
    M0P_AES->KEY2 = pu32AESKey[2];
    M0P_AES->KEY3 = pu32AESKey[3];
    if(AESKey192 <= pstcConfig->enKeySel)
    {
        M0P_AES->KEY4 = pu32AESKey[4];
        M0P_AES->KEY5 = pu32AESKey[5];
        if(AESKey256 == pstcConfig->enKeySel)
        {
            M0P_AES->KEY6 = pu32AESKey[6];
            M0P_AES->KEY7 = pu32AESKey[7];
        }
        else
        {
            enResult = ErrorInvalidParameter;
        }
    }
    
    //Data config
    M0P_AES->DATA0 = pu32AESData[0];
    M0P_AES->DATA1 = pu32AESData[1];
    M0P_AES->DATA2 = pu32AESData[2];
    M0P_AES->DATA3 = pu32AESData[3];
    
    //Control config
    M0P_AES->CON_f.FUNC_SEL  = AESEncrypt;
    M0P_AES->CON_f.KEY_SEL   = pstcConfig->enKeySel;
    M0P_AES->CON_f.DUMMY_SEL = pstcConfig->enDummySel;
    M0P_AES->DIV_EN_f.DIV_EN = pstcConfig->enDiv;
    
    M0P_AES->CON_f.START = TRUE;
    while (M0P_AES->CON_f.START){;}
    
    if (AESDfaEnable == pstcConfig->enDfaEn)
    {
        if (M0P_AES->CON_f.DFA_STA)
        {
            enResult = Error;
        }
    }
    
    pu32Ciphertext[0] = M0P_AES->DATA0;
    pu32Ciphertext[1] = M0P_AES->DATA1;
    pu32Ciphertext[2] = M0P_AES->DATA2;
    pu32Ciphertext[3] = M0P_AES->DATA3;
        
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief AES decrypt
 **
 ** This function decrypt AES data and output plaintext.
 **
 ** \param [in]  pstcConfig        AES config
 ** \param [out] pu8Ciphertext    The pointer of AES plainttext
 **
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - pstcConfig is invalid
 ** \retval Error If one of following conditions are met:
 **                                 - DFA fail
 *****************************************************************************/
en_result_t AES_Decrypt(stc_aes_config_t* pstcConfig, uint8_t* pu8Plaintext)
{
    en_result_t             enResult = Ok;
    uint32_t                *pu32AESRand;
    uint32_t                *pu32AESData;
    uint32_t                *pu32AESKey;
    uint32_t                *pu32Plaintext;
    
    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_DUMMYSEL(pstcConfig->enDummySel));
    ASSERT(IS_VALID_KEYSEL(pstcConfig->enKeySel));
    ASSERT(IS_VALID_DFAEN(pstcConfig->enDfaEn));
    ASSERT(IS_VALID_DIV(pstcConfig->enDiv));
    
    //Init
    pu32AESRand    = (uint32_t*)pstcConfig->pu8AESRand;
    pu32AESData    = (uint32_t*)pstcConfig->pu8AESData;
    pu32AESKey     = (uint32_t*)pstcConfig->pu8AESKey;
    pu32Plaintext  = (uint32_t*)pu8Plaintext;
    
    //Random number config
    M0P_AES->RNG0 = pu32AESRand[0];
    M0P_AES->RNG1 = pu32AESRand[1];
    
    //Key config
    M0P_AES->KEY0 = pu32AESKey[0];
    M0P_AES->KEY1 = pu32AESKey[1];
    M0P_AES->KEY2 = pu32AESKey[2];
    M0P_AES->KEY3 = pu32AESKey[3];
    if(AESKey192 <= pstcConfig->enKeySel)
    {
        M0P_AES->KEY4 = pu32AESKey[4];
        M0P_AES->KEY5 = pu32AESKey[5];
        if(AESKey256 == pstcConfig->enKeySel)
        {
            M0P_AES->KEY6 = pu32AESKey[6];
            M0P_AES->KEY7 = pu32AESKey[7];
        }
        else
        {
            enResult = ErrorInvalidParameter;
        }
    }
    
    //Data config
    M0P_AES->DATA0 = pu32AESData[0];
    M0P_AES->DATA1 = pu32AESData[1];
    M0P_AES->DATA2 = pu32AESData[2];
    M0P_AES->DATA3 = pu32AESData[3];
    
    //Control config
    M0P_AES->CON_f.FUNC_SEL  = AESDecrypt;
    M0P_AES->CON_f.KEY_SEL   = pstcConfig->enKeySel;
    M0P_AES->CON_f.DUMMY_SEL = pstcConfig->enDummySel;
    M0P_AES->DIV_EN_f.DIV_EN = pstcConfig->enDiv;
    
    M0P_AES->CON_f.START = TRUE;
    while (M0P_AES->CON_f.START){;}
    
    if (AESDfaEnable == pstcConfig->enDfaEn)
    {
        if (M0P_AES->CON_f.DFA_STA)
        {
            enResult = Error;
        }
    }
    
    pu32Plaintext[0] = M0P_AES->DATA0;
    pu32Plaintext[1] = M0P_AES->DATA1;
    pu32Plaintext[2] = M0P_AES->DATA2;
    pu32Plaintext[3] = M0P_AES->DATA3;
    
    return (enResult);
}

//@} // AES Group


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

