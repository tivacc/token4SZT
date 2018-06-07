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
/** \file aes.h
 **
 ** AES driver define.
 ** @link AES Group Some description @endlink
 **
 **   - 2016-10-26  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __AES_H__
#define __AES_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
 ** \defgroup AES Group
 **
 ** 
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of AES register structure 
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief AES DUMMY_SEL
 ** 
 ** To select the number of false operation round 
 ******************************************************************************/
typedef enum
{
    AESDummy7      = 0u,  ///< 7  rounds
    AESDummy15     = 1u,  ///< 15 rounds
    AESDummy31     = 2u,  ///< 31 rounds
    AESDummy63     = 3u   ///< 63 rounds
} en_aes_dummysel_t;

/**
 ******************************************************************************
 ** \brief AES KEY_SEL
 ** 
 ** To select key length
 ******************************************************************************/
typedef enum
{
    AESKey128     = 0u,  ///< 128 bits key
    AESKey192     = 1u,  ///< 192 bits key
    AESKey256     = 2u   ///< 256 bits key
} en_aes_keysel_t;

/**
 ******************************************************************************
 ** \brief AES HCLK Div
 ** 
 ** To select the HCLK, (AES can only work within 20 MHZ)
 ******************************************************************************/
typedef enum
{
    AESDfaEnable          = 0u,  ///< DFA detect enable
    AESDfaDisable         = 1u   ///< DFA detect disable
} en_aes_dfa_en_t;

/**
 ******************************************************************************
 ** \brief AES HCLK Div
 ** 
 ** To select the HCLK, (AES can only work within 20 MHZ)
 ******************************************************************************/
typedef enum
{
    AESDiv0           = 0u,  ///< HCLK no divide
    AESDiv2           = 1u   ///< HCLK 2 divide (need set "1", when HCLK > 20MHz)
} en_aes_div_t;

/**
 *****************************************************************************
 ** \brief AES configuration
 ** 
 ** The AES configuration
 *****************************************************************************/
typedef struct stc_aes_config
{
    en_aes_div_t        enDiv;          ///< HCLK DIV, see description of #en_aes_div_t
    en_aes_dummysel_t   enDummySel;     ///< DUMMY_SEL, see description of #en_aes_dummy_t
    en_aes_dfa_en_t     enDfaEn;        ///< DFA enable, see description of #en_aes_dfa_en_t
    en_aes_keysel_t     enKeySel;       ///< KEY_SEL, see description of #en_aes_keysel_t
    uint8_t             *pu8AESData;    ///< The pointer of AES data
    uint8_t             *pu8AESKey;     ///< The pointer of AES key
    uint8_t             *pu8AESRand;    ///< The pointer of AES random number
} stc_aes_config_t;

/******************************************************************************
 * Global definitions
 ******************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/
/* AES encrypt and decrypt */
en_result_t AES_Encrypt(stc_aes_config_t* pstcConfig, uint8_t* pu8Ciphertext);
en_result_t AES_Decrypt(stc_aes_config_t* pstcConfig, uint8_t* pu8Plaintext);

//@} // AESGroup

#ifdef __cplusplus
}
#endif

#endif /* __AES_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
