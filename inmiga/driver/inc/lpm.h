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
/** \file lpm.h
 **
 ** low power mode function driver define.
 ** @link LPM Group Some description @endlink
 **
 **   - 2016-10-27  1.0  Min Wang First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __LPM_H__
#define __LPM_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "ddl.h"
#include "interrupts_hc32l15.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
//total backup register number
#define DDL_BACK_UP_REGISTERS       (16u)   
  
//register bit offset
#define WAKE_ISR_RERTCI             (1ul<<0u)
#define WAKE_ISR_RELVDI             (1ul<<1u)
#define WAKE_ISR_REWU0I             (1ul<<2u)
#define WAKE_ISR_REWU1I             (1ul<<3u)
#define WAKE_ISR_REWU2I             (1ul<<4u)
#define WAKE_ISR_REWU3I             (1ul<<5u)
  
#define WAKE_RSR_REINTX             (1ul<<0u)
#define WAKE_RSR_RELVDR             (1ul<<1u)
  
/**
 *****************************************************************************
 ** \brief low power mode type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_lpm_mode
{
    StbIdleMode    = 0u,    //!< standby Idle mode
    StbStopMode     = 1u,   //!< standby stop mode     
    StbRtcMode      = 2u,   //!< standby RTC mode 
    DeepStbRtcMode  = 3u,   //!< deep standby RTC mode
    DeepStbStopMode = 4u,   //!< deep standby stop mode      
} en_lpm_mode_t;



/**
 ******************************************************************************
 ** \brief Deep standby mode return cause
 *******************************************************************************/
typedef struct stc_ret_cause
{
    boolean_t   bRtcEn;     //!< Return from RTC interrupt enable
    boolean_t   bLvdEn;     //!< Return from LVD interrupt enable
    boolean_t   bWakeup0En; //!< Return from Wakeup0 pin enable
    boolean_t   bWakeup1En; //!< Return from Wakeup1 pin enable
    boolean_t   bWakeup2En; //!< Return from Wakeup2 pin enable
    boolean_t   bWakeup3En; //!< Return from Wakeup3 pin enable
}stc_dstb_ret_cause_t;



/**
 *****************************************************************************
 ** \brief standby mode return cause type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_ret_cause_flag
{
    DeepStbNoFlag    = 0u,     ///< No flag set
    DeepStbInitx     = 1u,     ///< return from INITX input reset
    DeepStbLvdReset  = 2u,     ///< return from LVD reset
    DeepStbRtcInt    = 3u,     ///< return from RTC interrupt
    DeepStbLvdInt    = 4u,     ///< return from LVD interrupt
    DeepStbWkupPin0  = 5u,     ///< return from Wkup pin1 detection
    DeepStbWkupPin1  = 6u,     ///< return from Wkup pin1 detection
    DeepStbWkupPin2  = 7u,     ///< return from Wkup pin2 detection
    DeepStbWkupPin3  = 8u,     ///< return from Wkup pin3 detection
} en_dstb_ret_cause_t;


/**
 *****************************************************************************
 ** \brief Wakeup pin wake up function invalid level type define
 ** 
 ** 
 *****************************************************************************/
typedef enum en_wkup_valid_level
{
    WkupLowLevelValid   = 0u,  ///< Set low level as valid level
    WkupHighLevelValid  = 1u,  ///< Set high level as valid level
}en_wkup_valid_level_t;


/**
******************************************************************************
 ** \brief define wkup pin index
******************************************************************************/
typedef enum en_dstb_wkup_pin
{
    WkupPin0 = 0u,      ///< index of wkup pin 1
    WkupPin1 = 1u,      ///< index of wkup pin 2
    WkupPin2 = 2u,      ///< index of wkup pin 3
    WkupPin3 = 3u,      ///< index of wkup pin 4
    WkupPinMax = 4u,
} en_dstb_wkup_pin_t;
    
/**
 *****************************************************************************
 ** \brief LDO switch mode type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_ldo_switch_mode
{
    SwitchNormal   = 0u,  ///< Do not switch the LDO mode automatic when low frequency clock valid
    SwitchAuto  = 1u,       ///< Switch the LDO mode automatic when low frequency clock valid.
}en_ldo_switch_mode_t;

/**
 *****************************************************************************
 ** \brief LDO RF mode type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_ldo_rf_mode
{
    ModeRF1   = 0u,  ///< LDO RF1 mode valid
    ModeRF2  = 1u,       ///< LDO RF2 mode valid
    ModeNoneRF = 2,  ///< not use RF mode
}en_ldo_rf_mode_t;


/**
 *****************************************************************************
 ** \brief clock config in standby mode type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_lpm_clk_output
{
    ClkUart   = 0u,      ///< UART clock output
    ClkWdt  = 1u,        ///< Watchdog clock output
    ClkLcdc  = 1u,       ///< LCDC clock output
    ClkRtc  = 1u,        ///< RTC clock output
}en_lpm_clk_output_t;

/**
 *****************************************************************************
 ** \brief backup register struct definition
 ** 
 ** 
 *****************************************************************************/
typedef struct stc_backupreg
{
    uint8_t u8BREG01;
    uint8_t u8BREG02;
    uint8_t u8BREG03;
    uint8_t u8BREG04;
    uint8_t u8BREG05;
    uint8_t u8BREG06;
    uint8_t u8BREG07;
    uint8_t u8BREG08;
    uint8_t u8BREG09;
    uint8_t u8BREG10;
    uint8_t u8BREG11;
    uint8_t u8BREG12;
    uint8_t u8BREG13;
    uint8_t u8BREG14;
    uint8_t u8BREG15;
    uint8_t u8BREG16;
} stc_backupreg_t;

/**
 *****************************************************************************
 ** \brief backup register index type definition
 ** 
 ** 
 *****************************************************************************/
typedef enum en_dstb_bakup_reg
{
    BackupReg1 = 0u,      ///< index of backup register 1
    BackupReg2 = 1u,      ///< index of backup register 2
    BackupReg3 = 2u,      ///< index of backup register 3
    BackupReg4 = 3u,      ///< index of backup register 4
    BackupReg5 = 4u,      ///< index of backup register 5
    BackupReg6 = 5u,      ///< index of backup register 6
    BackupReg7 = 6u,      ///< index of backup register 7
    BackupReg8 = 7u,      ///< index of backup register 8
    BackupReg9 = 8u,      ///< index of backup register 9
    BackupReg10 = 9u,    ///< index of backup register 10
    BackupReg11 = 10u,    ///< index of backup register 11
    BackupReg12 = 11u,    ///< index of backup register 12
    BackupReg13 = 12u,    ///< index of backup register 13
    BackupReg14 = 13u,    ///< index of backup register 14
    BackupReg15 = 14u,    ///< index of backup register 15
    BackupReg16 = 15u,    ///< index of backup register 15
    
} en_dstb_bakup_reg_t;


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
/* enter lpm mode function */
void Lpm_GoToStandByMode(en_lpm_mode_t enMode, boolean_t bIoRemain);
/* config lpm mode function */
en_result_t Lpm_ConfigDeepStbRetCause(stc_dstb_ret_cause_t* pstcCause);
en_result_t Lpm_SetWkupPinLevel(en_dstb_wkup_pin_t enPinIndex, en_wkup_valid_level_t enLevel);
en_result_t Lpm_ConfigDeepStbRAMRetention(boolean_t bRamRetain);
en_result_t Lpm_LDOModeSet(en_ldo_switch_mode_t enSwitMode);
en_result_t Lpm_ClkCtl(en_lpm_clk_output_t enFuncClk, boolean_t bCtl);
en_result_t Lpm_BGRSet(boolean_t bBGRCtl);
/* read deep standby return cause flag*/
en_dstb_ret_cause_t Lpm_ReadDeepStbRetCause(void);
/* backup register read and write function*/
en_result_t Lpm_WriteBackupReg(en_dstb_bakup_reg_t enRegIndex, uint8_t u8Data);
en_result_t ReadBackupRegisters(stc_backupreg_t* pstcBackUpReg);



//@} // LPMGroup

#ifdef __cplusplus
}
#endif

#endif /* __LPM_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
