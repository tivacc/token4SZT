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
/** \file osc.h
 **
 ** 
 ** @link osc Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of Module.
 **
 ******************************************************************************/


#ifndef __OSC_H_
#define __OSC_H_

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************************************************************
 * Global definitions
 ******************************************************************************/
  

/**
 ******************************************************************************
 ** \brief HICR frequency division values
 **
 ** \note The division signal is output to internal Timers
 ******************************************************************************/
typedef enum en_hicr_freq_div
{
    HicrFreqDivBy4   = 0,
    HicrFreqDivBy8   = 1,
    HicrFreqDivBy16  = 2,
    HicrFreqDivBy32  = 3,
    HicrFreqDivBy64  = 4,
    HicrFreqDivBy128 = 5,
    HicrFreqDivBy256 = 6,
    HicrFreqDivBy512 = 7
}en_hicr_freq_div_t;

/**
 ******************************************************************************
 ** \brief HICR frequency selection
 **
 ** \note Selcet the HICR freq. 2/4/8/16MHz
 ******************************************************************************/
typedef enum en_hicr_freq_sel
{
    Hicr2M      = 0,
    Hicr4M      = 1,
    Hicr8M      = 2,
    Hicr16M     = 3
}en_hicr_freq_sel_t;

/**
 ******************************************************************************
 ** \brief External OSC input frequency range
 **
 ** \note Selcet the range of external OSC frequency
 ******************************************************************************/
typedef enum en_hxst_range
{
    R4M6M       = 0,
    R6M12M      = 1,
    R12M20M     = 2,
    R20M32M     = 3
}en_hxst_range_t;

typedef struct stc_osc_config
{
    en_hicr_freq_sel_t  enHicrFreq;     ///< Set HICR frequency
    uint8_t             u8HxstBias;     ///< External High-Speed Crystal bias current setting.
    en_hxst_range_t     enHxstRange;    ///< Input range of external OSC.
    uint8_t             u8LxstBias;     ///< External Low-Speed Crystal bias current setting.
    uint8_t             u8LxstAmp;      ///< External Low-Speed Crystal amplitude setting.
}stc_osc_config_t;

/******************************************************************************/
/* Global variable definitions ('extern')                                     */
/******************************************************************************/
/******************************************************************************/
/* Global function prototypes (definition in C source)                        */
/******************************************************************************/
en_result_t Hicr_SetFreqDiv(en_hicr_freq_div_t enHicrDiv);
en_hicr_freq_div_t Hicr_GetFreqDiv(void);
void Hicr_Set4MFreqTrimmingData(uint16_t u16FTrim);
uint16_t Hicr_Get4MFreqTrimmingData(void);
void Hicr_Set16MFreqTrimmingData(uint16_t u16FTrim);
uint16_t Hicr_Get16MFreqTrimmingData(void);
void Hicr_Set4MTempTrimmingData(uint8_t u8TTrim);
uint8_t Hicr_Get4MTempTrimmingData(void);
void Hicr_Set16MTempTrimmingData(uint8_t u8TTrim);
uint8_t Hicr_Get16MTempTrimmingData(void);
en_result_t Hicr_SetHicrFreq(en_hicr_freq_sel_t enHicrFreq);
en_hicr_freq_sel_t Hicr_GetHicrFreq(void);
en_result_t Osc_Init(stc_osc_config_t* pstcConfig);
en_result_t Osc_DeInit(void);

#ifdef __cplusplus
}
#endif

#endif /*__OSC_H_*/
