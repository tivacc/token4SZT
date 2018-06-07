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
/** \file flash.c
 **
 ** FLASH driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-27  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "flash.h"

/**
 ******************************************************************************
 ** \addtogroup FLASHGroup
 ******************************************************************************/
//@{
/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define IS_VALID_FUDR(x) ( FUDR0 == (x) ||\
                           FUDR1 == (x) ||\
                           FUDR2 == (x) ||\
                           FUDR3 == (x)    )

#define IS_VALID_UIDR(x) ( UIDR0 == (x) ||\
                           UIDR1 == (x) ||\
                           UIDR2 == (x)    )

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
#define FRWPW                       (0x1ACC0000u)
#define FLASH_END_ADDR              (0x0001FFFFu)
/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
/**
 ******************************************************************************
 ** \brief FLASH FOCR
 ** 
 ** To select the operation of FLASH control 
 ******************************************************************************/
typedef enum
{
    Prgm      = 0x1ACC0001u,   ///< program mode
    Pers      = 0x1ACC0002u,  ///< page erase mode
    Cers      = 0x1ACC0004u,  ///< chip erase mode
    Dpstb     = 0x1ACC0008u   ///< deep sleep mode
} en_flash_focr_t;

/**
 ******************************************************************************
 ** \brief FLASH FLC
 ** 
 ** To select flash page lock
 ******************************************************************************/
typedef enum
{
    LockDisable   = 0u,       ///<Flash page lock2K enable
    LockEnable    = 1u        ///<Flash page lock2K disable                
} en_flash_lock_t;

/**
 ******************************************************************************
 ** \brief FLASH Programing Timer
 ** 
 ** To define flash programing timer register (4MHz)
 ******************************************************************************/
typedef enum
{
    Tnvs      = 24u,
    Tprog     = 24u,
    Tpgs      = 24u,
    Trcv_pgm  = 24u,
    Trcv_pers = 25u,
    Trcv_cers = 7u,
    Tpers     = 16u,
    Tcers     = 32u,
} en_flash_prg_timer_t;


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
 ** \brief FLASH UDR write
 **
 ** This function set flash user data register.
 **
 ** \param [in] en_Udr            User data register number
 ** \param [in] u32Data           User data
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - en_Udr is invalid                                
 *****************************************************************************/
en_result_t Flash_UdrWrite(en_flash_fudr_t enFudr, uint32_t u32Data)
{
    en_result_t             enResult = Ok;
    
    ASSERT(IS_VALID_FUDR(enFudr));
    
    (&(M0P_FLASH->FUDR0))[enFudr] = u32Data;
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH UDR read
 **
 ** This function read flash user data register.
 **
 ** \param [in]  en_Udr            User data register number
 ** \param [out] pu32Data          The pointer of user data
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - en_Udr is invalid                                
 *****************************************************************************/
en_result_t Flash_UdrRead(en_flash_fudr_t enFudr, uint32_t* pu32Data)
{
    en_result_t             enResult = Ok;
    
    ASSERT(IS_VALID_FUDR(enFudr));
    
    *pu32Data = (&(M0P_FLASH->FUDR0))[enFudr];
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH write byte
 **
 ** This function write 1 byte data to flash.
 **
 ** \param [in]  u32Addr           Flash address
 ** \param [in]  u8Data          The pointer of user ID
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - u32Addr is invalid                                
 *****************************************************************************/
en_result_t Flash_WriteByte(uint32_t u32Addr, uint8_t u8Data)
{
    en_result_t             enResult = Ok;
    
    if (FLASH_END_ADDR < u32Addr)
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }
    
    //unlock flash
    M0P_FLASH->FLCR0 = 0;
    M0P_FLASH->FLCR1 = 0;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //set PRGM
    M0P_FLASH->FOCR = Prgm;
    
    //write data
    *((volatile uint8_t*)u32Addr) = u8Data;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //clear PRGM
    M0P_FLASH->FOCR = FRWPW;
    
    //lock flash
    M0P_FLASH->FLCR0 = 0xFFFFFFFFu;
    M0P_FLASH->FLCR1 = 0xFFFFFFFFu;
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH write byte
 **
 ** This function write 1 halfword(2 bytes) data to flash.
 **
 ** \param [in]  u32Addr           Flash address
 ** \param [in]  u16Data          The pointer of user ID
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - u32Addr is invalid                                
 *****************************************************************************/
en_result_t Flash_WriteHalfWord(uint32_t u32Addr, uint16_t u16Data)
{
    en_result_t             enResult = Ok;

    if ((FLASH_END_ADDR < u32Addr) || (u32Addr % 2))
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }
    
    //unlock flash
    M0P_FLASH->FLCR0 = 0;
    M0P_FLASH->FLCR1 = 0;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //set PRGM
    M0P_FLASH->FOCR = Prgm;
    
    //write data
    *((volatile uint16_t*)u32Addr) = u16Data;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //clear PRGM
    M0P_FLASH->FOCR = FRWPW;
    
    //lock flash
    M0P_FLASH->FLCR0 = 0xFFFFFFFFu;
    M0P_FLASH->FLCR1 = 0xFFFFFFFFu;
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH write byte
 **
 ** This function write 1 word(4 bytes) data to flash.
 **
 ** \param [in]  u32Addr           Flash address
 ** \param [in]  u32Data          The pointer of user ID
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - u32Addr is invalid                                
 *****************************************************************************/
en_result_t Flash_WriteWord(uint32_t u32Addr, uint32_t u32Data)
{
    en_result_t             enResult = Ok;

    if ((FLASH_END_ADDR < u32Addr) || (u32Addr % 4))
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }
    
    //unlock flash
    M0P_FLASH->FLCR0 = 0;
    M0P_FLASH->FLCR1 = 0;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //set PRGM
    M0P_FLASH->FOCR = Prgm;
    
    //write data
    *((volatile uint32_t*)u32Addr) = u32Data;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //clear PRGM
    M0P_FLASH->FOCR = FRWPW;
    
    //lock flash
    M0P_FLASH->FLCR0 = 0xFFFFFFFFu;
    M0P_FLASH->FLCR1 = 0xFFFFFFFFu;
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH page erase
 **
 ** This function erase flash page.
 **
 ** \param [in]  u32PageAddr           Flash page address
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - u32PageAddr is invalid                                
 *****************************************************************************/
en_result_t Flash_PageErase(uint32_t u32PageAddr)
{
    en_result_t             enResult = Ok;

    if (FLASH_END_ADDR < u32PageAddr)
    {
        enResult = ErrorInvalidParameter;
        return (enResult);
    }
    
    //unlock flash
    M0P_FLASH->FLCR0 = 0;
    M0P_FLASH->FLCR1 = 0;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //set PRGM
    M0P_FLASH->FOCR = Pers;
    
    //write invalid data
    *((volatile uint32_t*)(u32PageAddr&0xFFFFFFFCu)) = 0u;
    
    //busy?
    while (TRUE == M0P_FLASH->FSTR_f.BUSY)
    {
        ;
    }
    
    //lock flash
    M0P_FLASH->FLCR0 = 0xFFFFFFFFu;
    M0P_FLASH->FLCR1 = 0xFFFFFFFFu;
    
    return (enResult);
}

/**
 *****************************************************************************
 ** \brief FLASH programing timer config
 **
 ** This function is config FLASH programing timer register.
 **
 ** \param [in]  u8FreqCfg        The frequence of Fchip
 **                               u8FreqCfg - Fchip
 **                                  0      - (0,4]MHz;
 **                                  1      - (4,8]MHz;
 **                                  2      - (8,16]MHz;
 **                                  3      - (16,32]MHz;
 **                                 other   -  Invalid                                                  
 ** 
 ** \retval Ok                    Process successfully done.
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                                 - u32PageAddr is invalid                                
 *****************************************************************************/
en_result_t Flash_PgmTimerConfig(uint8_t u8FreqCfg)
{
    en_result_t             enResult = Ok;
    
    if (u8FreqCfg > 3)
    {
        enResult = ErrorInvalidParameter;
    }

    //flash timer register config
    M0P_FLASH->TNVS     = Tnvs << u8FreqCfg;
    M0P_FLASH->TPROG    = Tprog << u8FreqCfg;
    M0P_FLASH->TPGS     = Tpgs << u8FreqCfg;
    M0P_FLASH->TRCVPGM  = Trcv_pgm << u8FreqCfg;
    M0P_FLASH->TRCVPERS = Trcv_pers << u8FreqCfg;
    M0P_FLASH->TRCVCERS = Trcv_cers << u8FreqCfg;
    M0P_FLASH->TPERS    = Tpers << u8FreqCfg;
    M0P_FLASH->TCERS    = Tcers << u8FreqCfg; 
    if (u8FreqCfg == 3)
    {
        M0P_FLASH->TCERS = ~(uint8_t)((Tcers << u8FreqCfg));
    }
        
    return (enResult);
}


//@} // FLASH Group


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

