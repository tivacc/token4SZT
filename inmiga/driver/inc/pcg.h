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
/** \file pcg.h
 **
 ** PCG driver define.
 ** @link Pcg Group Some description @endlink
 **
 **   - 2016-10-25  1.0  LuX First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __PCG_H__
#define __PCG_H__

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
 ** \defgroup PcgGroup
 ** 
 **
 ******************************************************************************/
//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of PCG register structure 
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief peripheral selected
 ** 
 ** To determine which peripheral will be selected
 ******************************************************************************/
typedef enum
{
    MSC0          = 0u,       ///<multi serial communication channel 0
    MSC1          = 1u,       ///<multi serial communication channel 1
    MSC2          = 2u,       ///<multi serial communication channel 2
    LMSC0         = 3u,       ///<Low power multi serial communication channel 0
    LMSC1         = 4u,       ///<Low power multi serial communication channel 1
    LMSC2         = 5u,       ///<Low power multi serial communication channel 2
    ADC           = 6u,       ///<Analog to Digital Converter
    GPIO          = 7u,       ///<General Purpose Input/Output
    CTM0_3        = 8u,       ///<The basic timer control bits(channels 0-3)
    CTM4_7        = 9u,       ///<The basic timer control bits(channels 4-7)
    VC            = 10u,      ///<Voltage comparator
    BUZZER        = 11u,      ///<Buzzer
    AES           = 12u,      ///<Advanced Encryption Standard
    SCI           = 13u,      ///<ISO7816/IC (Serial Communications Interface)
    LCDC          = 14u,      ///<Liquid Crystal Display Controller
} en_peripheral_t;

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
/* Function CLK Stop/Recovery */
en_result_t Pcg_Stop(en_peripheral_t enPeri);
en_result_t Pcg_Recovery(en_peripheral_t enPeri);

/* Function  CLK Enable/Disable */
en_result_t Pcg_EnableCLK(en_peripheral_t enPeri);
en_result_t Pcg_DisableCLK(en_peripheral_t enPeri);

/* Function  RST Enable/Disable */
en_result_t Pcg_EnableRST(en_peripheral_t enPeri);
en_result_t Pcg_DisableRST(en_peripheral_t enPeri);

//@} // PcgGroup

#ifdef __cplusplus
}
#endif

#endif /* __PCG_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
