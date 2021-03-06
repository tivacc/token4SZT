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
/** \file uid.c
 **
 ** Unique ID driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2017-05-23  1.0   First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "uid.h"

/**
 ******************************************************************************
 ** \addtogroup UidGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
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


/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/

/**
 ******************************************************************************
 ** \brief Read Unique ID registers
 **
 **
 ** \param  [out] pstcUniqueId     Pointer to the Unique ID structure
 **
 ** \retval Ok                     Unique ID successfully read
 ** \retval ErrorInvalidParameter  pstcUniqueId == NULL
 ******************************************************************************/
en_result_t Uid_ReadUniqueId(M0P_UID_TypeDef *pstcUniqueId)
{
    if (NULL == pstcUniqueId)
    {
        return ErrorInvalidParameter;
    }

    pstcUniqueId->UIDR0 = M0P_UID->UIDR0;
    pstcUniqueId->UIDR1 = M0P_UID->UIDR1;
    pstcUniqueId->UIDR2 = M0P_UID->UIDR2 & 0x0000FFFF;
  
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Read Unique ID registers 0 
 **
 ** This function reads out UIDR0 
 **
 ** \return uint32_t                  Unique ID 0
 ******************************************************************************/
uint32_t Uid_ReadUniqueId0(void)
{
    return M0P_UID->UIDR0;
}

/**
 ******************************************************************************
 ** \brief Read Unique ID registers 1 
 **
 ** This function reads out UIDR1
 **
 ** \return uint32_t                  Unique ID 1 
 ******************************************************************************/
uint32_t Uid_ReadUniqueId1(void)
{
    return M0P_UID->UIDR1;
}

/**
 ******************************************************************************
 ** \brief Read Unique ID registers 2 and masks the upper 16 bits to '0'
 **
 ** This function reads out UIDR2 and masks the upper 16 bits to '0'
 **
 ** \return uint16_t                  Unique ID 2 & 0x0000FFFF
 ******************************************************************************/
uint16_t Uid_ReadUniqueId2(void)
{
    return (uint16_t)(M0P_UID->UIDR2 & 0x0000FFFF);
}

//@} // UidGroup

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
