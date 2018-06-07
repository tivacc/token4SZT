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
/** \file flash.h
 **
 ** FLASH driver define.
 ** @link FLASH Group Some description @endlink
 **
 **   - 2016-10-27  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __FLASH_H__
#define __FLASH_H__

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
 ** \defgroup FLASH Group
 **
 **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of FLASH register structure 
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief FLASH FUDR
 **
 ** To select the FLASH User Data Register
 ******************************************************************************/
typedef enum
{
    FUDR0        = 0u,       ///<Flash user data register0
    FUDR1        = 1u,       ///<Flash user data register1
    FUDR2        = 2u,       ///<Flash user data register2
    FUDR3        = 3u        ///<Flash user data register3
} en_flash_fudr_t;

/**
 ******************************************************************************
 ** \brief UIDR
 **
 ** To select the User ID Register
 ******************************************************************************/
typedef enum
{
    UIDR0        = 0u,       ///<User ID register0
    UIDR1        = 1u,       ///<User ID register1
    UIDR2        = 2u        ///<User ID register2
} en_flash_uidr_t;


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
/* Flash User Data Register write and read */
en_result_t Flash_UdrWrite(en_flash_fudr_t enFudr, uint32_t u32Data);
en_result_t Flash_UdrRead(en_flash_fudr_t enFudr, uint32_t* pu32Data);

/* Flash write */
en_result_t Flash_WriteByte(uint32_t u32Addr, uint8_t u8Data);
en_result_t Flash_WriteHalfWord(uint32_t u32Addr, uint16_t u16Data);
en_result_t Flash_WriteWord(uint32_t u32Addr, uint32_t u32Data);

/* Flash erase */
en_result_t Flash_PageErase(uint32_t u32PageAddr);

/* Flash timer set */
en_result_t Flash_PgmTimerConfig(uint8_t u8FreqCfg);

//@} // FLASHGroup

#ifdef __cplusplus
}
#endif

#endif /* __FLASH_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
