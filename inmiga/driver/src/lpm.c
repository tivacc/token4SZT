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
/** \file lpm.c
 **
 ** low power mode function driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-27  1.0  Min Wang First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "lpm.h"

/**
 ******************************************************************************
 ** \addtogroup LPMGroup
 ******************************************************************************/
//@{

/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/
//Core CSR register address
#define CM_CORE_CSR  *((volatile unsigned int*)(0xE000ED10UL))
   
// Backup registers base address   
#define LPCM_BACKUP_REG_BASE   ((volatile uint8_t*)0x40035700)

#define SLEEPDEEP_BIT (uint32_t)0x01<<2

#define LPM_CTL_KEY    (uint32_t)0x1ACC<<16
#define SPLV_BIT       (uint32_t)1<<4
#define DSTB_EN_BIT    (uint32_t)1<<2
#define STBM_BIT       (uint32_t)0x02

#define LPM_LDO_KEY   0x55AA


#define    IS_VALID_WORKMODE(x)    (StbIdleMode == (x) ||\
                                    StbStopMode == (x) ||\
                                    StbRtcMode == (x) ||\
                                    DeepStbRtcMode == (x) ||\
                                    DeepStbStopMode == (x) )
#define    IS_VALID_WKUPPININDEX(x) (WkupPin0 == (x) ||\
                                    WkupPin1 == (x) ||\
                                    WkupPin2 == (x) ||\
                                    WkupPin3 == (x) )

#define    IS_VALID_WKUPLEVEL(x)    (WkupLowLevelValid == (x) ||\
                                    WkupHighLevelValid == (x) )


#define    IS_VALID_LDO_SWITCHMODE(x)    (SwitchNormal == (x) ||\
                                          SwitchAuto == (x) )

#define    IS_VALID_LPM_CLKOUT(x)    (ClkUart == (x) ||\
                                      ClkWdt == (x) ||\
                                      ClkLcdc == (x) ||\
                                      ClkRtc == (x) )
#define    IS_VALID_BACKUPREG_INDEX(x)    (BackupReg1 == (x) ||\
                                           BackupReg2 == (x) ||\
                                           BackupReg3 == (x) ||\
                                           BackupReg4 == (x) ||\
                                           BackupReg5 == (x) ||\
                                           BackupReg6 == (x) ||\
                                           BackupReg7 == (x) ||\
                                           BackupReg8 == (x) ||\
                                           BackupReg9 == (x) ||\
                                           BackupReg10 == (x) ||\
                                           BackupReg11 == (x) ||\
                                           BackupReg12 == (x) ||\
                                           BackupReg13 == (x) ||\
                                           BackupReg14 == (x) ||\
                                           BackupReg15 == (x) ||\
                                           BackupReg16 == (x) )

    
    
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
 ******************************************************************************
 ** \brief WRFSR dummy read
 ******************************************************************************/
static uint16_t WRFSRDummyRead(void)
{
    uint16_t Dummy;
    Dummy = M0P_WSUNIT->WAKE_RSR;
    return Dummy;
}

/**
 ******************************************************************************
 ** \brief WRFSR dummy read
 ******************************************************************************/
static uint16_t WIFSRDummyRead(void)
{
    uint16_t Dummy;
    Dummy = M0P_WSUNIT->WAKE_ISR;
    return Dummy;
}

/**
 ******************************************************************************
 ** \brief go to standby mode
 **
 ** \param enMode the type of standby mode.
 **        This parameter can be one of the following values:
 ** \arg   StbIdleMode    Sleep mode
 ** \arg   StbStopMode     Stop mode
 ** \arg   StbRtcMode      RTC mode
 ** \arg   DeepStbRtcMode  deep standby RTC mode
 ** \arg   DeepStbStopMode deep standby stop mode

 ** \param bIoRemain Set io status when enter standby mode.
 **        This parameter can be one of the following values:
 ** \arg   FALSE Set IO to Hi-z
 ** \arg   TRUE  Remain IO status
 ******************************************************************************/
void Lpm_GoToStandByMode(en_lpm_mode_t enMode, boolean_t bIoRemain)
{
    WRFSRDummyRead();
    WIFSRDummyRead();
  
    ASSERT(IS_VALID_WORKMODE(enMode));
    switch (enMode)
    {
        case StbIdleMode:
            CM_CORE_CSR &= ~(SLEEPDEEP_BIT);          /* SLEEPDEEP=0 */
            __WFI();
            break;
        case StbStopMode:
            M0P_WSUNIT->CLK_CTL1_f.RTCE = 0;          /* disable RTC mode */
            if( TRUE == bIoRemain )
            {
                /* Retains status of each pin */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT;
            }
            else
            {
                /* Sets the status of each pin to high impedance */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | SPLV_BIT;
            }
            CM_CORE_CSR |= SLEEPDEEP_BIT;            /* SLEEPDEEP=1 */
            __WFI();
            break;
        case StbRtcMode:
            M0P_WSUNIT->CLK_CTL1_f.RTCE = 1;         /* Enable RTC mode */
            if( TRUE == bIoRemain )
            {
                /* Retains status of each pin */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT;
            }
            else
            {
                /* Sets the status of each pin to high impedance */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | SPLV_BIT;
            }
            CM_CORE_CSR |= SLEEPDEEP_BIT;            /* SLEEPDEEP=1 */
            __WFI();
            break;
        case DeepStbRtcMode: 
            M0P_WSUNIT->CLK_CTL1_f.RTCE = 1;        /* Enable RTC mode */
            if( TRUE == bIoRemain )
            {
                /* Retains status of each pin */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | DSTB_EN_BIT;
            }
            else
            {
                /* Sets the status of each pin to high impedance */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | DSTB_EN_BIT | SPLV_BIT;
            }
            CM_CORE_CSR |= SLEEPDEEP_BIT;           /* SLEEPDEEP=1 */
            __WFI();
            break;
        case DeepStbStopMode:
            M0P_WSUNIT->CLK_CTL1_f.RTCE = 0;        /* disable RTC mode */
            if( TRUE == bIoRemain )
            {
                /* Retains status of each pin */
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | DSTB_EN_BIT;
            }
            else
            {
                /* Sets the status of each pin to high impedance */ 
                M0P_CLOCK->LPM_CTL = LPM_CTL_KEY | STBM_BIT | DSTB_EN_BIT | SPLV_BIT ;
            }
            CM_CORE_CSR |= SLEEPDEEP_BIT;          /* SLEEPDEEP=1 */
            __WFI();
            break;                       
        default:
            break;
    }
}


/**
 ******************************************************************************
 ** \brief Configure return cause from deep standby mode
 **
 ** \param pstcCause Pointer to structure of return cause types
 **         
 ** \retval Ok  Deep standby mode is configured normally
 **
 ** \note Wakeup from WKUP0 pin is always enabled
 **
 ******************************************************************************/
en_result_t Lpm_ConfigDeepStbRetCause(stc_dstb_ret_cause_t* pstcCause)
{
    ASSERT(NULL != pstcCause);
  
    //if(NULL == pstcCause)
    //{
    //    return ErrorInvalidParameter;
    //};
    
    bM0P_WSUNIT_WAKE_IER_RERTCE = ((pstcCause->bRtcEn == TRUE) ? 1u : 0u);
    bM0P_WSUNIT_WAKE_IER_RELVDE = ((pstcCause->bLvdEn == TRUE)? 1u : 0u);
    bM0P_WSUNIT_WAKE_IER_REWU0E = ((pstcCause->bWakeup0En == TRUE) ? 1u : 0u);
    bM0P_WSUNIT_WAKE_IER_REWU1E = ((pstcCause->bWakeup1En == TRUE) ? 1u : 0u);
    bM0P_WSUNIT_WAKE_IER_REWU2E = ((pstcCause->bWakeup2En == TRUE) ? 1u : 0u);
    bM0P_WSUNIT_WAKE_IER_REWU3E = ((pstcCause->bWakeup3En == TRUE) ? 1u : 0u);

    return Ok;
}

/**
 ******************************************************************************
 ** \brief Read deep standby mode return cause flag 
 **         
 ** \retval DeepStbNoFlag      No flag set
 ** \retval DeepStbInitx       Wakeup from deep standby mode by INITX reset
 ** \retval DeepStbLvdReset    Wakeup from deep standby mode by LVD reset
 ** \retval DeepStbRtcInt      Wakeup from deep standby mode by RTC interrupt
 ** \retval DeepStbLvdInt      Wakeup from deep standby mode by LVD interrupt
 ** \retval DeepStbWkupPin0    Wakeup from deep standby mode by WKUP0
 ** \retval DeepStbWkupPin1    Wakeup from deep standby mode by WKUP1
 ** \retval DeepStbWkupPin2    Wakeup from deep standby mode by WKUP2
 ** \retval DeepStbWkupPin3    Wakeup from deep standby mode by WKUP3
 ** 
 ** \retval DeepStbNoFlag      No flag set
 ** \retval DeepStbInitx       return from INITX input reset
 ** \retval DeepStbLvdReset    return from LVD reset
 ** \retval DeepStbRtcInt      return from RTC interrupt
 ** \retval DeepStbLvdInt      return from LVD interrupt
 ** \retval DeepStbWkupPinx    return from Wkup pinx detection£¨x 0~3£©
 **
 ******************************************************************************/
en_dstb_ret_cause_t Lpm_ReadDeepStbRetCause(void)
{
    uint16_t rWAKE_ISR,rWAKE_RSR;
    rWAKE_RSR = M0P_WSUNIT->WAKE_RSR;
    rWAKE_ISR = M0P_WSUNIT->WAKE_ISR;
    
    if(rWAKE_RSR & WAKE_RSR_REINTX)
    {
        return DeepStbInitx;
    }
    
    if(rWAKE_RSR & WAKE_RSR_RELVDR)
    {
        return DeepStbLvdReset;
    }
    
    if(rWAKE_ISR & WAKE_ISR_RERTCI)
    {
        return DeepStbRtcInt;
    }
    else if(rWAKE_ISR & WAKE_ISR_RELVDI)
    {
        return DeepStbLvdInt;
    }
    else if(rWAKE_ISR & WAKE_ISR_REWU0I)
    {
        return DeepStbWkupPin0;
    }
    else if(rWAKE_ISR & WAKE_ISR_REWU1I)
    {
        return DeepStbWkupPin1;
    }
    else if(rWAKE_ISR & WAKE_ISR_REWU2I)
    {
        return DeepStbWkupPin2;
    }
    else if(rWAKE_ISR & WAKE_ISR_REWU3I)
    {
        return DeepStbWkupPin3;
    }else{
        ;
    }
   
    return DeepStbNoFlag;
}





/**
 ******************************************************************************
 ** \brief Set the valid level of wkup pin
 ** 
 ** \param enPinIndex Pin index
 ** \arg WkupPin0          WKUP0 pin index
 ** \arg WkupPin1          WKUP1 pin index
 ** \arg WkupPin2          WKUP2 pin index
 ** \arg WkupPin3          WKUP3 pin index
 **
 ** \param enLevel Wakeup pin valid value
 ** \arg WkupLowLevelValid     Set low as active level for WKUPx
 ** \arg WkupHighLevelValid    Set high as active level for WKUPx
 **         
 ** \retval Ok                     The valid level of wkup pin is set normally
 ** \retval ErrorInvalidParameter  Invalid value of enPinIndex
 **
 ******************************************************************************/
en_result_t Lpm_SetWkupPinLevel(en_dstb_wkup_pin_t enPinIndex, en_wkup_valid_level_t enLevel)
{
    ASSERT(IS_VALID_WKUPPININDEX(enPinIndex));
    ASSERT(IS_VALID_WKUPLEVEL(enLevel));

    if(enPinIndex >= WkupPinMax)
    {
        return ErrorInvalidParameter;
    }
  
    M0P_WSUNIT->WAKE_LVR &= ~(1ul << enPinIndex);
    M0P_WSUNIT->WAKE_LVR |= (uint8_t)(enLevel << enPinIndex);
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief Configure deep standby mode RAM retention
 ** 
 ** \param bRamRetain Whether to retain data in the RAM
 **         
 ** \retval Ok Deep standby mode RAM retention set
 **
 ******************************************************************************/
en_result_t Lpm_ConfigDeepStbRAMRetention(boolean_t bRamRetain)
{
    if(FALSE == bRamRetain)
    {
        M0P_WSUNIT->DS_RAMP_f.RAMP = 0; 
    }
    else
    {
        M0P_WSUNIT->DS_RAMP_f.RAMP = 1; 
    }
    return Ok;
}


/**
 ******************************************************************************
 ** \brief LDO mode set
 ** 
 ** \param enSwitMode  LDO Switch mode config
 **         
 ** \retval Ok config seccuss
 **
 ******************************************************************************/
en_result_t Lpm_LDOModeSet(en_ldo_switch_mode_t enSwitMode)
{
    stc_wsunit_ldo_ctl_field_t stcLdoConfig;
    
    ASSERT(IS_VALID_LDO_SWITCHMODE(enSwitMode));
    
    if(SwitchNormal == enSwitMode)
    {
        stcLdoConfig.AUTOSWEN = 0;
    }
    else
    {
        stcLdoConfig.AUTOSWEN = 1;
    }
    
    stcLdoConfig.KEY = LPM_LDO_KEY;

    M0P_WSUNIT->LDO_CTL_f = stcLdoConfig;
    
    return Ok;
}

/**
 ******************************************************************************
 ** \brief low power mode periperal clock set
 ** 
 ** \param enFuncClk  chose the function of the clock
 ** \param bCtl    config the clock. TRUE -- Enable output clock
 **                                  FALSE -- Disbale output clock
 **         
 ** \retval Ok    config seccuss
 **         ErrorInvalidMode operation not allowed
 ******************************************************************************/
en_result_t Lpm_ClkCtl(en_lpm_clk_output_t enFuncClk, boolean_t bCtl)
{
    ASSERT(IS_VALID_LPM_CLKOUT(enFuncClk));

    if(TRUE == bCtl)
    {
        if(ClkUart == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.UARTCKE = 1;
        }
        else if(ClkWdt == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.WDTCKE = 1;
        }
        else if(ClkLcdc == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.LCDCKE = 1;
        }
        else if(ClkRtc == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.RTCCKE = 1;
        }
        else
        {
            return ErrorInvalidMode;
        }
    }
    else
    {
        if(ClkUart == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.UARTCKE = 0;
        }
        else if(ClkWdt == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.WDTCKE = 0;
        }
        else if(ClkLcdc == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.LCDCKE = 0;
        }
        else if(ClkRtc == enFuncClk)
        {
            M0P_WSUNIT->CLK_CTL2_f.RTCCKE = 0;
        }
        else
        {
            return ErrorInvalidMode;
        }
    }
    return Ok;

}


/**
 ******************************************************************************
 ** \brief background reference setting
 ** 
 ** \param bBGRCtl    config the BGR function. TRUE -- Enable BGR
 **                                  FALSE -- Disbale BGR
 **         
 ** \retval Ok    config seccuss
 ** 
 ******************************************************************************/
en_result_t Lpm_BGRSet(boolean_t bBGRCtl)
{
    if(TRUE == bBGRCtl)
    {
        M0P_WSUNIT->BGR_CTL_f.BGR_EN = 1;
    }
    else
    {
        M0P_WSUNIT->BGR_CTL_f.BGR_EN = 0;
    }
    return Ok;
    
}


/**
 ******************************************************************************
 ** \brief Write the backup register
 ** 
 ** \param enRegIndex register index
 ** \arg BackupReg1     Back up register 1 index
 ** \arg BackupReg2     Back up register 2 index
 ** \arg BackupReg3     Back up register 3 index
 ** \arg BackupReg4     Back up register 4 index
 ** \arg BackupReg5     Back up register 5 index
 ** \arg BackupReg6     Back up register 6 index
 ** \arg BackupReg7     Back up register 7 index
 ** \arg BackupReg8     Back up register 8 index
 ** \arg BackupReg9     Back up register 9 index
 ** \arg BackupReg10    Back up register 10 index
 ** \arg BackupReg11    Back up register 11 index
 ** \arg BackupReg12    Back up register 12 index
 ** \arg BackupReg13    Back up register 13 index
 ** \arg BackupReg14    Back up register 14 index
 ** \arg BackupReg15    Back up register 15 index
 ** \arg BackupReg16    Back up register 16 index
 ** \param u8Data the data written into backup register
 **         
 ** \retval Ok The backup register written normally
 ** \retval ErrorInvalidParameter enRegIndex > BackupReg15
 **
 ******************************************************************************/
en_result_t Lpm_WriteBackupReg(en_dstb_bakup_reg_t enRegIndex, uint8_t u8Data)
{
    volatile uint8_t* pBufReg = (volatile uint8_t*)(&M0P_WSUNIT->BUR01);

    ASSERT(IS_VALID_BACKUPREG_INDEX(enRegIndex));
    
	
    if(enRegIndex > BackupReg16)
    {
        return ErrorInvalidParameter;
    }
    pBufReg += (uint8_t)enRegIndex;
    *pBufReg = u8Data;
    return Ok;
}


/**
 ******************************************************************************
 ** \brief Read Backup Registers
 **
 ** \param [out]  stcBackUpReg     double pointer to user backup register
 **                                structure
 **
 ** \retval Ok                     Successfully read
 ******************************************************************************/ 
en_result_t ReadBackupRegisters(stc_backupreg_t* pstcBackUpReg)
{
    uint8_t  u8Counter;
    volatile uint8_t* pBufReg = (volatile uint8_t*)&(M0P_WSUNIT->BUR01);
    uint8_t* pBufRead = &pstcBackUpReg->u8BREG01;
  
    ASSERT(NULL != pstcBackUpReg);
    
    for(u8Counter = 0u; u8Counter < DDL_BACK_UP_REGISTERS; u8Counter ++)
    {
        *pBufRead++ = *pBufReg++;
    }
  
    return Ok;
}





//@} // LPMGroup





/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

