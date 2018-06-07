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
/** \file rtc.c
 **
 ** RTC function driver API.
 ** @link SampleGroup Some description @endlink
 **
 **   - 2016-10-24  1.0  Min Wang First version for Device Driver Library of Module.
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "rtc.h"

/**
 ******************************************************************************
 ** \addtogroup RTCGroup
 ******************************************************************************/
//@{



/******************************************************************************/
/* Local pre-processor symbols/macros ('#define')                             */
/******************************************************************************/

/* Timeout count */
#define RTC_TIMEOUT           (Clk_GetSystemClk()/10u)
/* Error code for mktime */
#define RTC_ERR               (-1)
/* convert DEC to BCD */
#define DecToBcd(x)           ((((x)/10u)<<4) + ((x)%10u))
/* convert BCD to DEC */
#define BcdToDec(x)           ((((x)>>4)*10) + ((x)&0x0F))
   

/* define for ASSERT Function  */
#define     IS_VALID_MONTH(x)       (((x) >= RtcJanuary) && ((x) <= RtcDecember))
#define     IS_VALID_DAY(x)         (((x) >= 1) && ((x) <= 31))
#define     IS_VALID_HOUR(x)        ((x) <= 23)
#define     IS_VALID_MIN(x)         ((x) <= 59)
#define     IS_VALID_SEC(x)         ((x) <= 59)

#define     IS_VALID_IRQ_SEL(x)     (RtcHalfSecondIrq == (x) ||\
                                     RtcOneSecondIrq == (x) ||\
                                     RtcOneMinuteIrq == (x) ||\
                                     RtcOneHourIrq == (x) ||\
                                     RtcTimerIrq == (x) ||\
                                     RtcAlarmIrq == (x) ||\
                                     RtcTimeRewriteErrorIrq == (x) )

#define     IS_VALID_CLK_SEL(x)     (RtcLSXTClk == (x) ||\
                                     RtcLICRClk == (x))
#define     IS_VALID_CLK_PRESCAL(x) (((x) ==32768) || ((x) == 32000))
#define     IS_VALID_DIV_RATIO(x)   (RtcDivRatio1 == (x) ||\
                                     RtcDivRatio2 == (x) ||\
                                     RtcDivRatio4 == (x) ||\
                                     RtcDivRatio8 == (x) ||\
                                     RtcDivRatio16 == (x) ||\
                                     RtcDivRatio32 == (x) ||\
                                     RtcDivRatio64 == (x) ||\
                                     RtcDivRatio128 == (x) ||\
                                     RtcDivRatio256 == (x) ||\
                                     RtcDivRatio512 == (x) )
#define     IS_VALID_RTCCO_SEL(x)   (RtccoOutput2Hz == (x) ||\
                                     RtccoOutput1Hz == (x) )
#define     IS_VALID_TIMER_MODE(x)   (RtcTimerOneshot == (x) ||\
                                     RtcTimerPeriod == (x) )
#define     IS_VALID_FUNC(x)        (RtcCount == (x) ||\
                                     RtcTimer == (x) ||\
                                     RtcFreqCorr == (x) ||\
                                     RtcAlarmYearEn == (x) ||\
                                     RtcAlarmMonthEn == (x) ||\
                                     RtcAlarmDayEn == (x) ||\
                                     RtcAlarmHourEn == (x) ||\
                                     RtcAlarmMinEn == (x) ||\
                                     RtcAlarmSecEn == (x) )
#define     IS_VALID_STATUS(x)        (RtcRunStatus == (x) ||\
                                     RtcTimerStatus == (x) )

#define     IS_VALID_FREQCORR_VALUE(x) ((x) <= RTC_MAX_FREQ_CORR_VALUE)
#define     IS_VALID_FREQCORR_CYCLE(x) ((x) <= RTC_MAX_FREQ_CORR_CYCLE_SET_VALUE)

#define     HAS_ENABLED_INT(x)      ((M0P_RTC->RTCCTL1 & 0xFF000000u) == 0 ? FALSE : TRUE)
                                     
/* Disable interrupt */
#define     DISABLE_INT(x)          (M0P_RTC->RTCCTL1 &= 0x00FFFFFFu)

/* Restore interrupt */
#define     RESTORE_INT(x)          (M0P_RTC->RTCCTL1 |= ((x) & 0xFF000000u))//

/* Clear all interrupt flags */
#define     CLEAR_INT_FLAG(x)       (M0P_RTC->RTCCTL1 &= 0xFF00FFFFu)

/* Convert time to value for TVAL register.*/
#define     TIME_TO_TVAL(time)      (((time) * 2u) - 1u)

/* Convert MCLK to value for CCS register.*/
#define     MCLK_TO_CCS(MCLK)       (((MCLK) / 4u) - 1u)

#define     WAIT(x, timeout, timeoutFlag)                           \
do{                                                                 \
    if( TRUE == ( !!( x ) ) )                                      \
    {                                                               \
        (timeoutFlag) = FALSE;                                        \
        break;                                                      \
    }                                                               \
    else                                                            \
    {                                                               \
        (timeout)--;                                                  \
        if(0u == (timeout))                                           \
        {                                                           \
            (timeoutFlag) = TRUE;                                     \
            break;                                                  \
        }                                                           \
    }                                                               \
}while(1)

#define     WAIT_CLK_STABLE(rinClkType, timeout, timeoutFlag)    WAIT((rinClkType) == M0P_RTC->SCLKS_f.SCLKS, (timeout), (timeoutFlag))
#define     WAIT_CLKDIV_RDY(timeout, timeoutFlag)                WAIT(TRUE == M0P_RTC->CLKDIVC_f.DIVRDY, (timeout), (timeoutFlag))


/* NVIC ISR*/
#ifndef NVIC_ISR
#define NVIC_ISR                    (NVIC->ISER[0])
#else
#error "Check the consistency for NVIC_ISR definitions."
#endif

#define     BACKUP_RTC_NVIC(x)      (u32NvicData = NVIC_ISR)

#define     RTC_YEAR_BASE           2000u
#define     TM_YEAR_BASE            1900u

#define     INDEX_TO_MONTH_OFFSET   1u

/******************************************************************************/
/* Global variable definitions (declared in header file with 'extern')        */
/******************************************************************************/


/******************************************************************************/
/* Local type definitions ('typedef')                                         */
/******************************************************************************/
typedef enum en_rtc_rin_clk_status
{
    RtcRInClkSub                = 0x2u,  ///< Choose sub clock as input for rin_clk.
    RtcRInClkLowCr              = 0x3u,  ///< Choose low cr clock as input for rin_clk.
}en_rtc_rin_clk_status_t;


/******************************************************************************/
/* Local function prototypes ('static')                                       */
/******************************************************************************/
static en_result_t RtcToTm( stc_rtc_time_t* pstcRtcTime,
                     struct tm*      pstcTime);
static en_result_t TmToRtc( stc_rtc_time_t* pstcRtcTime,
                     struct tm*      pstcTime);

static void RtcDisableNvic(void);
static void RtcRestoreNvic(void);

static void RtcInitNvic(void);
static void RtcDeInitNvic(void);
static stc_rtc_intern_cb_t* RtcGetInternDataCb(void);

/******************************************************************************/
/* Local variable definitions ('static')                                      */
/******************************************************************************/
static uint32_t u32NvicData;
static stc_rtc_intern_cb_t stcRtcIrqCb;



/*****************************************************************************/
/* Function implementation - global ('extern') and local ('static')          */
/*****************************************************************************/



/**
 ******************************************************************************
 ** \brief  Disable RTC NVIC and save original value.
 **
 ** \param [in]     none
 **
 ** \retval   none
 **
 ******************************************************************************/
static void RtcDisableNvic(void)
{
    /* Backup the interrupt set enable register of NVIC. */
    BACKUP_RTC_NVIC(x);

    /* Disable the interrupt of RTC. */
    NVIC_DisableIRQ(OSC_WU_RTC_IRQn);
}


/**
 ******************************************************************************
 ** \brief  Restore RTC NVIC.
 **
 ** \param [in]     none
 **
 ** \retval   none
 **
 ******************************************************************************/
static void RtcRestoreNvic(void)
{
    /* Resume the interrupt set enable register of NVIC. */
    NVIC_ISR = u32NvicData;
}

/**
 ******************************************************************************
 ** \brief  Device dependent initialization of interrupts 
 **
 ** \param [in] none
 **  
 ** \retval   none
 **
 ******************************************************************************/
static void RtcInitNvic(void)
{
    NVIC_ClearPendingIRQ(OSC_WU_RTC_IRQn);
    NVIC_EnableIRQ(OSC_WU_RTC_IRQn);
    NVIC_SetPriority(OSC_WU_RTC_IRQn, 1);
}

/**
 ******************************************************************************
 ** \brief  Device dependent de-initialization of interrupts
 **
 ** \param [in] none
 **  
 ** \retval   none
 **
 ******************************************************************************/
static void RtcDeInitNvic(void)
{
    NVIC_ClearPendingIRQ(OSC_WU_RTC_IRQn);
    NVIC_DisableIRQ(OSC_WU_RTC_IRQn);
    NVIC_SetPriority(OSC_WU_RTC_IRQn, 1);
}

/**
 ******************************************************************************
 ** \brief  Convert RTC time structure to time.h tm structure
 **
 ** \param [in]  pstcRtcTime    RTC Time structure
 **        [out] pstcTime       tm Time structure
 **  
 ** \retval Ok                    Convert success
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - pstcRtcTime == NULL
 **                             - pstcTime == NULL
 **                             - invalid month
 **                             - invalid day
 **                             - invalid hour
 **                             - invalid minute
 **                             - invalid second
 **
 ******************************************************************************/
static en_result_t RtcToTm( stc_rtc_time_t* pstcRtcTime,
                     struct tm*      pstcTime)
{
    ASSERT(NULL != pstcRtcTime);
    ASSERT(NULL != pstcTime);
    ASSERT(IS_VALID_MONTH(pstcRtcTime->u8Month));
    ASSERT(IS_VALID_DAY(pstcRtcTime->u8Day));
    ASSERT(IS_VALID_HOUR(pstcRtcTime->u8Hour));
    ASSERT(IS_VALID_MIN(pstcRtcTime->u8Minute));
    ASSERT(IS_VALID_SEC(pstcRtcTime->u8Second));

    pstcTime->tm_year  = (int)(pstcRtcTime->u16Year - TM_YEAR_BASE);
    pstcTime->tm_mon   = (int)(pstcRtcTime->u8Month - INDEX_TO_MONTH_OFFSET);
    pstcTime->tm_mday  = (int)(pstcRtcTime->u8Day);
    pstcTime->tm_sec   = (int)(pstcRtcTime->u8Second);
    pstcTime->tm_min   = (int)(pstcRtcTime->u8Minute);
    pstcTime->tm_hour  = (int)(pstcRtcTime->u8Hour);
    pstcTime->tm_isdst = 0;

    return Ok;
}

/**
 ******************************************************************************
 ** \brief  Convert RTC time structure to time.h tm structure
 **
 ** \param [in]  pstcTime       tm Time structure
 **        [out] pstcRtcTime    RTC Time structure
 **  
 ** \retval Ok                    Convert success
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                             - pstcRtcTime == NULL
 **                             - pstcTime == NULL
 **                             - invalid month
 **                             - invalid day
 **                             - invalid hour
 **                             - invalid minute
 **                             - invalid second
 **
 ******************************************************************************/
static en_result_t TmToRtc(stc_rtc_time_t * pstcRtcTime,
                    struct tm * pstcTime)
{
    ASSERT(NULL != pstcRtcTime);
    ASSERT(NULL != pstcTime);
    ASSERT(IS_VALID_MONTH(pstcTime->tm_mon + INDEX_TO_MONTH_OFFSET));
    ASSERT(IS_VALID_DAY(pstcTime->tm_mday));
    ASSERT(IS_VALID_HOUR(pstcTime->tm_hour));
    ASSERT(IS_VALID_MIN(pstcTime->tm_min));
    ASSERT(IS_VALID_SEC(pstcTime->tm_sec));
    
    pstcRtcTime->u16Year     = (uint16_t)(pstcTime->tm_year + TM_YEAR_BASE);
    pstcRtcTime->u8Month     = (uint8_t)(pstcTime->tm_mon + INDEX_TO_MONTH_OFFSET);
    pstcRtcTime->u8Day       = (uint8_t)(pstcTime->tm_mday);
    pstcRtcTime->u8Second    = (uint8_t)(pstcTime->tm_sec);
    pstcRtcTime->u8Minute    = (uint8_t)(pstcTime->tm_min);
    pstcRtcTime->u8Hour      = (uint8_t)(pstcTime->tm_hour);
    pstcRtcTime->u8DayOfWeek = (uint8_t)(pstcTime->tm_wday);

    return Ok;
}
/**
 ******************************************************************************
 ** \brief  Return the pointer of internal data copy back for a certain RTC instance.
 **
 ** \param [in]     none
 **
 ** \retval   Pointer to internal data or NULL if instance is not enabled (or not known)
 **
 ******************************************************************************/
static stc_rtc_intern_cb_t* RtcGetInternDataCb(void) 
{
    return &stcRtcIrqCb;
}


/**
 ******************************************************************************
 ** \brief Set time and date after RTC is running
 **
 ** \param [in] pstcTimeDate      Time and date structure
 ** \param [in] bContinue         RTC counting continues or not
 ** \arg  FALSE     RTC 1-second counting reset during setting procedure
 ** \arg  TRUE      RTC 1-second continues during setting procedure
 ** \param [in] bUpdateTime       Update time or not
 ** \arg  FALSE     Don't update time
 ** \arg  TRUE      Update time
 ** \param [in] bUpdateDate       Update date or not
 ** \arg  FALSE     Don't update date
 ** \arg  TRUE      Update date
 ** 
 ** \retval Ok                    RTC time and date is set normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcTimeDate == NULL
 **                             - invalid month if bUpdateDate is TRUE
 **                             - invalid day if bUpdateDate is TRUE
 **                             - invalid hour if bUpdateTime is TRUE
 **                             - invalid minute if bUpdateTime is TRUE
 **                             - invalid second if bUpdateTime is TRUE
 ** \retval ErrorInvalidMode      RTC is running
 ** \retval ErrorTimeout          RTC rewrite timeout            
 ** 
 ******************************************************************************/
en_result_t Rtc_SetDateTime(stc_rtc_time_t* pstcTimeDate, 
                            boolean_t bContinue,
                            boolean_t bUpdateTime,
                            boolean_t bUpdateDate)
{
    uint32_t u32TimeOut;
    uint32_t u32Rtcctl1;

    ASSERT(NULL != pstcTimeDate);

    /* Don't set time and date with this function before RTC starts */
    if(0u == M0P_RTC->RTCCTL1_f.STAT)
    {
        return ErrorInvalidMode;
    }

    if(1u == M0P_RTC->RTCCTL1_f.BUSY)
    {
        /*  Wait until rewrite idle */
        u32TimeOut = RTC_TIMEOUT;

        while(1)
        {
            if(TRUE == bContinue)
            {
                if((0u == M0P_RTC->RTCCTL1_f.BUSY) && (0u == M0P_RTC->RTCCTL1_f.SENSP))
                {
                    break;
                }
            }
            else
            {
                if((0u == M0P_RTC->RTCCTL1_f.BUSY) && (0u == M0P_RTC->RTCCTL1_f.SENRST))
                {
                    break;
                }
            }
            u32TimeOut--;
            if(0u == u32TimeOut)
            {
                return ErrorTimeout;
            }
        }       
    }
             
    /* Backup Interrupt Settings */
    u32Rtcctl1 = M0P_RTC->RTCCTL1;
    
    /* Disable RTC NVIC */
    RtcDisableNvic();
    
    /* Disable interrupt */
    DISABLE_INT(x);
    /* Clear every second interrupt */
    M0P_RTC->RTCCTL1_f.INTSF = 0u;
    
    /* Enable every second interrupt */
    M0P_RTC->RTCCTL1_f.INTSIEN = 1u;
                    
    /* Wait to occur interrupt */
    while (1u != M0P_RTC->RTCCTL1_f.INTSF)
    {
    }    
    
    /* Clear every second interrupt */
    M0P_RTC->RTCCTL1_f.INTSF = 0u;
    
    if(TRUE == bContinue)
    {
        /* Stop 1 second output */
        M0P_RTC->RTCCTL1_f.SENSP = 1u;
    }
    else
    {
        /* Reset 1 second counter */
        M0P_RTC->RTCCTL1_f.SENRST = 1u;
    }
    
    /* Set time and date */
    if (TRUE == bUpdateTime)
    {
        ASSERT(IS_VALID_HOUR(pstcTimeDate->u8Hour));
        ASSERT(IS_VALID_MIN(pstcTimeDate->u8Minute));
        ASSERT(IS_VALID_SEC(pstcTimeDate->u8Second));
        
        M0P_RTC->SEN  = DecToBcd(pstcTimeDate->u8Second);
        M0P_RTC->MIN = DecToBcd(pstcTimeDate->u8Minute);
        M0P_RTC->HOUR  = DecToBcd(pstcTimeDate->u8Hour);
    }
    
    if (TRUE == bUpdateDate)
    {
        ASSERT(IS_VALID_MONTH(pstcTimeDate->u8Month));
        ASSERT(IS_VALID_DAY(pstcTimeDate->u8Day));
        
        M0P_RTC->DATE  = DecToBcd(pstcTimeDate->u8Day);
        M0P_RTC->MON = DecToBcd(pstcTimeDate->u8Month);
        M0P_RTC->YEAR  = DecToBcd(pstcTimeDate->u16Year - RTC_YEAR_BASE);
        M0P_RTC->WEEK  = DecToBcd(pstcTimeDate->u8DayOfWeek);
    }

    if(TRUE == bContinue)
    {
        /* Refresh the time and date */
        M0P_RTC->RTCCTL1_f.SENSP = 0u;
    }
    else
    {
        /* Refresh the time and date  */
        M0P_RTC->RTCCTL1_f.SENRST = 0u;
    }
    
    /* Retrieve Interrupt Settings */
    DISABLE_INT(x);
    RESTORE_INT(u32Rtcctl1);
    
    /* Retrieve NVIC */
    RtcRestoreNvic();    
    
    /* Wait until the transfer from time and date registers to counters end */
    u32TimeOut = RTC_TIMEOUT;
    while(1)
    {
        if(TRUE == bContinue)
        {
            if((0u == M0P_RTC->RTCCTL1_f.BUSY) && (0u == M0P_RTC->RTCCTL1_f.SENSP))
            {
                break;
            }
        }
        else
        {
            if((0u == M0P_RTC->RTCCTL1_f.BUSY) && (0u == M0P_RTC->RTCCTL1_f.SENRST))
            {
                break;
            }
        }
        u32TimeOut--;
        if(0u == u32TimeOut)
        {
            return ErrorTimeout;
        }
    }    
                 
    return Ok;            
}

/**
 ******************************************************************************
 ** \brief Read RTC time and date 
 **
 ** \param [in] pstcTimeDate      Time and date structure
 ** 
 ** \retval Ok                    RTC time and date is read normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcTimeDate == NULL 
 ** \retval ErrorTimeout          Time and date read timeout
 ** 
 ******************************************************************************/
en_result_t Rtc_ReadDateTime(stc_rtc_time_t* pstcTimeDate)
{
    uint32_t u32TimeOut;
    uint8_t  u8DayOfWeek, u8BcdSec, u8BcdMin, u8BcdHour, u8Day, u8Month, u16Year = 0u;

    ASSERT(NULL != pstcTimeDate);
    
    /* Start read */
    M0P_RTC->RTCCTL2_f.RCTRL = 1u;
    
    /* Wait until read finish */
    u32TimeOut = RTC_TIMEOUT;
    while(1)
    {
        if(0u == M0P_RTC->RTCCTL2_f.RCTRL)
        {
            break;
        }
        u32TimeOut --;
        if(0u == u32TimeOut)
        {
            RtcRestoreNvic(); 
            return ErrorTimeout;
        }
    }

    /* Read time and date */    
    u8BcdSec  = M0P_RTC->SEN;
    u8BcdMin  = M0P_RTC->MIN;
    u8BcdHour = M0P_RTC->HOUR;
    u8Day     = M0P_RTC->DATE;
    u8Month   = M0P_RTC->MON;
    u16Year    = M0P_RTC->YEAR;
    u8DayOfWeek = M0P_RTC->WEEK;
    
    pstcTimeDate->u8Second = BcdToDec(u8BcdSec);
    pstcTimeDate->u8Minute = BcdToDec(u8BcdMin);
    pstcTimeDate->u8Hour   = BcdToDec(u8BcdHour);
    pstcTimeDate->u8Day    = BcdToDec(u8Day);
    pstcTimeDate->u8Month  = BcdToDec(u8Month);
    pstcTimeDate->u16Year  = BcdToDec(u16Year) + RTC_YEAR_BASE;
    pstcTimeDate->u8DayOfWeek = BcdToDec(u8DayOfWeek);

    return Ok;
}


/**
 ******************************************************************************
 ** \brief  RTC  interrupt service routine.
 **
 ** \param [in]  none
 **  
 ** \retval   none
 **
 ******************************************************************************/
void Rtc_IrqHandler(void)
{
    stc_rtc_rtcctl1_field_t stcRtcctl1;
    stc_rtc_time_t stcTime;
    boolean_t bAlarmMatch = TRUE;
    stc_rtc_intern_cb_t* pstcRtcInternCb;
    
    /* Get get interrupt copyback structure pointer */
    pstcRtcInternCb = RtcGetInternDataCb() ;

    /* Read rtc control and status register */
    stcRtcctl1 = M0P_RTC->RTCCTL1_f;

    /* Timer writing error Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTERF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTERIEN))
    {
        /* Clear INTERF Flag */
        M0P_RTC->RTCCTL1_f.INTERF = FALSE;
        
        if (NULL != pstcRtcInternCb->pfnTimeWrtErrIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnTimeWrtErrIrqCb();
        }
    }

    /* Alarm Completion? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTALF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTALIEN))
    {
        /* Clear INTALI Flag */
        M0P_RTC->RTCCTL1_f.INTALF = FALSE;
        
        Rtc_ReadDateTime(&stcTime);
        
        if(stcRtcctl1.SENE)
        {
          if(M0P_RTC->ASEN != DecToBcd(stcTime.u8Second)) 
          {
            bAlarmMatch = FALSE;
          }
        }
        if(stcRtcctl1.MINE)
        {
            if(M0P_RTC->AMIN != DecToBcd(stcTime.u8Minute))
            {
              bAlarmMatch = FALSE;
            }
        }
        if(stcRtcctl1.HOUE)
        {
            if(M0P_RTC->AHOUR != DecToBcd(stcTime.u8Hour)) 
            {
              bAlarmMatch = FALSE;
            }
        }
        if(stcRtcctl1.DAYE)
        {
            if(M0P_RTC->ADATE != DecToBcd(stcTime.u8Day)) 
            {
              bAlarmMatch = FALSE;
            }
        }
        if(stcRtcctl1.MONE)
        {
            if(M0P_RTC->AMON != DecToBcd(stcTime.u8Month)) 
            {
                bAlarmMatch = FALSE;
            }
        }
        if(stcRtcctl1.YEAE)
        {
            if(M0P_RTC->AYEAR != DecToBcd(stcTime.u16Year - RTC_YEAR_BASE)) 
            {
              bAlarmMatch = FALSE;
            }
        }

        if(bAlarmMatch == TRUE)
        {
            if (NULL != pstcRtcInternCb->pfnAlarmIrqCb)
            {
                /* Callback */
                pstcRtcInternCb->pfnAlarmIrqCb();
            }
        }
    }

    /* Timer Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTTMF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTTMIEN))
    {
        /* Clear INTTMF Flag */
        M0P_RTC->RTCCTL1_f.INTTMF = FALSE;

        if (NULL != pstcRtcInternCb->pfnTimerIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnTimerIrqCb();
        }
    }

    /* 0.5-Second Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTSSF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTSSIEN))
    {
        /* Clear INTSSF Flag */
        M0P_RTC->RTCCTL1_f.INTSSF = FALSE;
        
        if (NULL != pstcRtcInternCb->pfnHalfSecondIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnHalfSecondIrqCb();
        }
    }

    /* One Second Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTSF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTSIEN))
    {
        /* Clear INTSF Flag */
        M0P_RTC->RTCCTL1_f.INTSF = FALSE;
        
        if (NULL != pstcRtcInternCb->pfnOneSecondIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnOneSecondIrqCb();
        }
    }

    /* One Minute Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTMF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTMIEN))
    {
        /* Clear INTMF Flag */
        M0P_RTC->RTCCTL1_f.INTMF = FALSE;

        if (NULL != pstcRtcInternCb->pfnOneMinuteIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnOneMinuteIrqCb();
        }
    }

    /* One Hour Interrupt? */
    if ((TRUE == M0P_RTC->RTCCTL1_f.INTHF)&&(TRUE == M0P_RTC->RTCCTL1_f.INTHIEN))
    {
        /* Clear INTHF Flag */
        M0P_RTC->RTCCTL1_f.INTHF = FALSE;
        
        if (NULL != pstcRtcInternCb->pfnOneHourIrqCb)
        {
            /* Callback */
            pstcRtcInternCb->pfnOneHourIrqCb();
        }
    }
}


/**
 ******************************************************************************
 ** \brief  Enable RTC (and Timer) Interrupt
 **
 ** \param [in]  enIrqSel        RTC interrupt type
 **  
 ** \retval Ok                    Interrupt selected is enabled
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcRtc == NULL
 **                               - enIrqSel out of range
 ******************************************************************************/
en_result_t Rtc_EnableIrq(en_rtc_irq_sel_t enIrqSel)
{
    ASSERT(IS_VALID_IRQ_SEL(enIrqSel));
    
    switch (enIrqSel)
    {
        case RtcHalfSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSSIEN = 1u;
            break;
        case RtcOneSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSIEN = 1u;
            break;
        case RtcOneMinuteIrq:
            M0P_RTC->RTCCTL1_f.INTMIEN = 1u;
            break;
        case RtcOneHourIrq:
            M0P_RTC->RTCCTL1_f.INTHIEN = 1u;
            break;
        case RtcTimerIrq:
            M0P_RTC->RTCCTL1_f.INTTMIEN = 1u;
            break;
        case RtcAlarmIrq:
            M0P_RTC->RTCCTL1_f.INTALIEN = 1u;
            break;
        case RtcTimeRewriteErrorIrq:
            M0P_RTC->RTCCTL1_f.INTERIEN = 1u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return (Ok);
}



/**
 ******************************************************************************
 ** \brief  Disable RTC (and Timer) Interrupt
 **
 ** \param [in]  enIrqSel        RTC interrupt type
 **  
 ** \retval Ok                    Interrupt selected is disabled
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcRtc == NULL
 **                               - enIrqSel out of range
 ******************************************************************************/
en_result_t Rtc_DisableIrq(en_rtc_irq_sel_t enIrqSel)
{
    ASSERT(IS_VALID_IRQ_SEL(enIrqSel));
    
    switch (enIrqSel)
    {
        case RtcHalfSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSSIEN = 0u;
            break;
        case RtcOneSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSIEN = 0u;
            break;
        case RtcOneMinuteIrq:
            M0P_RTC->RTCCTL1_f.INTMIEN = 0u;
            break;
        case RtcOneHourIrq:
            M0P_RTC->RTCCTL1_f.INTHIEN = 0u;
            break;
        case RtcTimerIrq:
            M0P_RTC->RTCCTL1_f.INTTMIEN = 0u;
            break;
        case RtcAlarmIrq:
            M0P_RTC->RTCCTL1_f.INTALIEN = 0u;
            break;
        case RtcTimeRewriteErrorIrq:
            M0P_RTC->RTCCTL1_f.INTERIEN = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }
   
    return (Ok);
}

/**
 ******************************************************************************
 ** \brief  This function initializes the RTC module
 **
 ** \param [in] pstcConfig        Pointer to RTC configuration structure
 **  
 ** \retval Ok                    RTC initialization completed normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcConfig == NULL
 **                               - Invalid value of a pstcConfig's element
 ******************************************************************************/
en_result_t Rtc_Init(stc_rtc_config_t* pstcConfig)
{
    boolean_t bTimeout = FALSE;
    stc_rtc_intern_cb_t* pstcRtcInternCb;
    uint32_t u32Count;
    
    /* calculate the timeout count */
    uint32_t u32Timeout = RTC_TIMEOUT;

    ASSERT(NULL != pstcConfig);
    ASSERT(IS_VALID_CLK_SEL(pstcConfig->enClkSel));
    ASSERT(IS_VALID_CLK_PRESCAL(pstcConfig->u32ClkPrescaler));
    ASSERT(IS_VALID_DIV_RATIO(pstcConfig->enDividerRatio));
    ASSERT(IS_VALID_RTCCO_SEL(pstcConfig->enRtccoSel));
    
    /* Get get interrupt copyback structure pointer */
    pstcRtcInternCb = RtcGetInternDataCb() ;
    
    /* Check for instance available or not */
    if(NULL == pstcRtcInternCb)
    {
        return ErrorInvalidParameter ;
    }
    
    if((TRUE == pstcConfig->bRunNotInit) && (1u == M0P_RTC->RTCCTL1_f.ST)) /* RTC is running ? */
    {
        /*
         * If bRunNotInit is TRUE, don't do initialization RTC is aready running. 
         * However the interrupt callback and NVIC still need updating.
         */
         
        /* Clear all interrupt flags */
        CLEAR_INT_FLAG(x);
        
        /* re-configure RTC timer */
        if((M0P_RTC->RTCCTL2_f.TCST == 0)&&(M0P_RTC->RTCCTL2_f.TCEN == 0)&&(M0P_RTC->RTCCTL2_f.TCRUN == 0))
        {
            if(NULL != pstcConfig->pstcTimer)
            {
                switch (pstcConfig->pstcTimer->enMode)
                {
                    case RtcTimerOneshot:
                        M0P_RTC->RTCCTL2_f.TCEN = 0u;
                        break;
                    case RtcTimerPeriod:
                        M0P_RTC->RTCCTL2_f.TCEN = 1u;
                        break;
                    default:
                        return ErrorInvalidParameter;
                }
      
                if(pstcConfig->pstcTimer->u32TimerCycle > RTC_MAX_TIMER_SET_VALUE)
                {
                        return ErrorInvalidParameter;
                }
                    
                u32Count = TIME_TO_TVAL(pstcConfig->pstcTimer->u32TimerCycle);
                
                M0P_RTC->TVAL = u32Count;

            }
        }
 
        /* re-configure interrupt */
        if(FALSE == HAS_ENABLED_INT(x))
        {
            if (NULL != pstcConfig->pstcIrqEn)
            {
                if(TRUE == pstcConfig->pstcIrqEn->bTimeRewriteErrorIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTERIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bAlarmIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTALIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bTimerIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTTMIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bOneHourIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTHIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bOneMinuteIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTMIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bOneSecondIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTSIEN = 1u;
                }
                
                if(TRUE == pstcConfig->pstcIrqEn->bHalfSecondIrq)
                {
                    M0P_RTC->RTCCTL1_f.INTSSIEN = 1u;
                }
            }       
        }
        /* Configure interrupt callback functions */
        if (NULL != pstcConfig->pstcIrqCb)
        {
            pstcRtcInternCb->pfnTimeWrtErrIrqCb = pstcConfig->pstcIrqCb->pfnTimeWrtErrIrqCb;
            pstcRtcInternCb->pfnAlarmIrqCb = pstcConfig->pstcIrqCb->pfnAlarmIrqCb;
            pstcRtcInternCb->pfnTimerIrqCb = pstcConfig->pstcIrqCb->pfnTimerIrqCb;
            pstcRtcInternCb->pfnOneHourIrqCb = pstcConfig->pstcIrqCb->pfnOneHourIrqCb;
            pstcRtcInternCb->pfnOneMinuteIrqCb = pstcConfig->pstcIrqCb->pfnOneMinuteIrqCb;
            pstcRtcInternCb->pfnOneSecondIrqCb = pstcConfig->pstcIrqCb->pfnOneSecondIrqCb;
            pstcRtcInternCb->pfnHalfSecondIrqCb = pstcConfig->pstcIrqCb->pfnHalfSecondIrqCb;
        }
        
        /* Configure NVIC */
        if (TRUE == pstcConfig->bTouchNvic)
        {
            RtcInitNvic();
        }

        BACKUP_RTC_NVIC(x);
        
        return Ok;
    }
      
    /* For initialization: Force all bits of RTCCTL1 and RTCCTL2 (inclusive ST bit) */
    /*   to '0'  */
    M0P_RTC->RTCCTL1 = 0;
    M0P_RTC->RTCCTL2 = 0;

    /* Select source clock for RTC */
    switch (pstcConfig->enClkSel)
    {
        case RtcLSXTClk:
            /* Select sub clock as source clock */
            M0P_RTC->SCLKI_f.SCLKI = 0;
            
            /* Wait until sub clock stable */
            WAIT_CLK_STABLE(RtcRInClkSub,u32Timeout,bTimeout);
            if(TRUE == bTimeout)
            {
                return ErrorTimeout;
            }
            
            M0P_RTC->CCS = MCLK_TO_CCS(pstcConfig->u32ClkPrescaler); /* set 0.5s as sub-second interval */

            break;
  
        case RtcLICRClk:
            /* Select Low CR clock as source clock */
            M0P_RTC->SCLKI_f.SCLKI = 1;
            /* Wait until low CR clock stable */
            WAIT_CLK_STABLE(RtcRInClkLowCr,u32Timeout,bTimeout);
            if(TRUE == bTimeout)
            {
                return ErrorTimeout;
            }
            
            M0P_RTC->CCS = MCLK_TO_CCS(pstcConfig->u32ClkPrescaler); /* set 0.5s as sub-second interval */

            break;
        default:
            return ErrorInvalidParameter;
    }
       
    if(pstcConfig->bEnSuboutDivider == TRUE)
    {
        /* Disable divider */
        M0P_RTC->CLKDIVC_f.DIVEN = 0;
        
        /* Set Divider ratio */
        switch (pstcConfig->enDividerRatio)
        {
            case RtcDivRatio1:
            case RtcDivRatio2:
            case RtcDivRatio4:
            case RtcDivRatio8:
            case RtcDivRatio16:
            case RtcDivRatio32:
            case RtcDivRatio64:
            case RtcDivRatio128:
            case RtcDivRatio256:
            case RtcDivRatio512:
                M0P_RTC->CLKDIVX = pstcConfig->enDividerRatio;
                break;
            default:
                return  ErrorInvalidParameter;
        }
        
        /*  Enable divider */
        u32Timeout = RTC_TIMEOUT;
        M0P_RTC->CLKDIVC_f.DIVEN = 1u;

        WAIT_CLKDIV_RDY(u32Timeout, bTimeout);
        if(TRUE == bTimeout)
        {
            return ErrorInvalidParameter;
        }
    }
    
    /* Initial frequency correction module */
    if(NULL != pstcConfig->pstcFreqCorrConfig)
    {
        if(FALSE == IS_VALID_FREQCORR_VALUE(pstcConfig->pstcFreqCorrConfig->u16FreqCorrValue))
        {
            return ErrorInvalidParameter;
        }
        M0P_RTC->CALVAL = (uint8_t)pstcConfig->pstcFreqCorrConfig->u16FreqCorrValue;

        if(FALSE == IS_VALID_FREQCORR_CYCLE(pstcConfig->pstcFreqCorrConfig->u16FreqCorrCycle))
        {
            return ErrorInvalidParameter;
        }
        M0P_RTC->CALCYC = pstcConfig->pstcFreqCorrConfig->u16FreqCorrCycle - 1;
    }
    
    /* Configure RTCCO output */
    switch (pstcConfig->enRtccoSel)
    {
        case RtccoOutput2Hz:
            M0P_RTC->RTCODIV_f.CODIV2 = 0u; 
            break;
        case RtccoOutput1Hz:
            M0P_RTC->RTCODIV_f.CODIV2 = 1u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    /* Initialize time and date */
    if(NULL != pstcConfig->pstcTimeDate)
    {
        M0P_RTC->SEN  = DecToBcd(pstcConfig->pstcTimeDate->u8Second);
        M0P_RTC->MIN = DecToBcd(pstcConfig->pstcTimeDate->u8Minute);
        M0P_RTC->HOUR  = DecToBcd(pstcConfig->pstcTimeDate->u8Hour);
        M0P_RTC->DATE  = DecToBcd(pstcConfig->pstcTimeDate->u8Day);
        M0P_RTC->MON = DecToBcd(pstcConfig->pstcTimeDate->u8Month);
        M0P_RTC->YEAR  = DecToBcd(pstcConfig->pstcTimeDate->u16Year - RTC_YEAR_BASE);
        M0P_RTC->WEEK  = DecToBcd(pstcConfig->pstcTimeDate->u8DayOfWeek);
    }
    
    /* Initialize Alarm */
    if(NULL != pstcConfig->pstcAlarm)
    {
        M0P_RTC->ASEN  = DecToBcd(pstcConfig->pstcAlarm->u8Second);
        M0P_RTC->AMIN = DecToBcd(pstcConfig->pstcAlarm->u8Minute);
        M0P_RTC->AHOUR  = DecToBcd(pstcConfig->pstcAlarm->u8Hour);
        M0P_RTC->ADATE  = DecToBcd(pstcConfig->pstcAlarm->u8Day);
        M0P_RTC->AMON = DecToBcd(pstcConfig->pstcAlarm->u8Month);
        M0P_RTC->AYEAR  = DecToBcd(pstcConfig->pstcAlarm->u16Year - RTC_YEAR_BASE);
    }
    
    if(NULL != pstcConfig->pstcTimer)
    {
        switch (pstcConfig->pstcTimer->enMode)
        {
            case RtcTimerOneshot:
                M0P_RTC->RTCCTL2_f.TCEN = 0u;
                break;
            case RtcTimerPeriod:
                M0P_RTC->RTCCTL2_f.TCEN = 1u;
                break;
            default:
                return ErrorInvalidParameter;
        }
        
        if(pstcConfig->pstcTimer->u32TimerCycle > RTC_MAX_TIMER_SET_VALUE)
        {
            return ErrorInvalidParameter;
        }
        
        u32Count = TIME_TO_TVAL(pstcConfig->pstcTimer->u32TimerCycle);
        
        M0P_RTC->TVAL = (uint8_t)u32Count;
    }
  
    /* Configure interrupt */
    if (NULL != pstcConfig->pstcIrqEn)
    {
        /* Set interrupt callback function */
        //Intr_RegisterHandler((en_intr_idx_t)(DDL_IRQ_RTC), Rtc_IrqHandler);
      
        if(TRUE == pstcConfig->pstcIrqEn->bTimeRewriteErrorIrq)
        {
            M0P_RTC->RTCCTL1_f.INTERIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bAlarmIrq)
        {
            M0P_RTC->RTCCTL1_f.INTALIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bTimerIrq)
        {
            M0P_RTC->RTCCTL1_f.INTTMIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bOneHourIrq)
        {
            M0P_RTC->RTCCTL1_f.INTHIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bOneMinuteIrq)
        {
            M0P_RTC->RTCCTL1_f.INTMIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bOneSecondIrq)
        {
            M0P_RTC->RTCCTL1_f.INTSIEN = 1u;
        }
        
        if(TRUE == pstcConfig->pstcIrqEn->bHalfSecondIrq)
        {
            M0P_RTC->RTCCTL1_f.INTSSIEN = 1u;
        }
    }
    
    /* Configure interrupt callback functions */
    if (NULL != pstcConfig->pstcIrqCb)
    {
        pstcRtcInternCb->pfnTimeWrtErrIrqCb = pstcConfig->pstcIrqCb->pfnTimeWrtErrIrqCb;
        pstcRtcInternCb->pfnAlarmIrqCb = pstcConfig->pstcIrqCb->pfnAlarmIrqCb;
        pstcRtcInternCb->pfnTimerIrqCb = pstcConfig->pstcIrqCb->pfnTimerIrqCb;
        pstcRtcInternCb->pfnOneHourIrqCb = pstcConfig->pstcIrqCb->pfnOneHourIrqCb;
        pstcRtcInternCb->pfnOneMinuteIrqCb = pstcConfig->pstcIrqCb->pfnOneMinuteIrqCb;
        pstcRtcInternCb->pfnOneSecondIrqCb = pstcConfig->pstcIrqCb->pfnOneSecondIrqCb;
        pstcRtcInternCb->pfnHalfSecondIrqCb = pstcConfig->pstcIrqCb->pfnHalfSecondIrqCb;
    }
    
    /* Configure NVIC */
    if (TRUE == pstcConfig->bTouchNvic)
    {
        RtcInitNvic();
    }

    BACKUP_RTC_NVIC(x);
    
    return (Ok);
} /* Rtc_Init */


/**
 ******************************************************************************
 ** \brief  De-Initialize RTC
 **
 ** \param [in] bTouchNvic         Touch NVIC or not
 **  
 ** This function stops and resets the RTC module and its interrupts.
 **
 ** \retval  Ok                     RTC de-initialization normally
 ******************************************************************************/
en_result_t Rtc_DeInit(boolean_t bTouchNvic)
{
    /* Set all registers of RTC instance to '0' */
    M0P_RTC->RTCCTL1 = 0u;
    M0P_RTC->RTCCTL2 = 0u;
    M0P_RTC->CCS     = 0u;
    
    M0P_RTC->CALVAL  = 0u;
    M0P_RTC->CALEN   = 0u;
    M0P_RTC->CALCYC  = 0u;
    
    M0P_RTC->CLKDIVC  = 0u;
    M0P_RTC->CLKDIVX  = 0u;

    M0P_RTC->SCLKI    = 0u;
    M0P_RTC->RTCODIV  = 0u;
    
    M0P_RTC->DATE    = 0u;
    M0P_RTC->HOUR    = 0u;
    M0P_RTC->MIN     = 0u;
    M0P_RTC->SEN     = 0u;
    M0P_RTC->YEAR    = 0u;
    M0P_RTC->MON     = 0u;
    M0P_RTC->WEEK    = 0u;
    
    M0P_RTC->ADATE   = 0u;
    M0P_RTC->AHOUR   = 0u;
    M0P_RTC->AMIN    = 0u;
    M0P_RTC->ASEN    = 0u;
    M0P_RTC->AYEAR   = 0u;
        
    if(TRUE == bTouchNvic)
    {
        RtcDeInitNvic();
    }
    
    return (Ok);
} /* Rtc_DeInit */

/**
 ******************************************************************************
 ** \brief  Enable functions of RTC
 **
 ** These functions includes RTC counting, Timer, Alarm compariron and frequency
 ** correction module.
 **
 ** \param [in] enFunc       Function types
 ** \arg   RtcCount          RTC counting
 ** \arg   RtcTimer          RTC timer
 ** \arg   RtcFreqCorr       RTC frequency correction module
 ** \arg   RtcAlarmYearEn    Year comparison enable of RTC alarm
 ** \arg   RtcAlarmMonthEn   Month comparison enable of RTC alarm
 ** \arg   RtcAlarmDayEn     Day comparison enable of RTC alarm
 ** \arg   RtcAlarmHourEn    Hour comparison enable of RTC alarm 
 ** \arg   RtcAlarmMinEn     Minute comparison enable of RTC alarm
 **  
 ** \retval Ok                    RTC functions enabled normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - Invalid value of enFunc 
 ******************************************************************************/
en_result_t Rtc_EnableFunc(en_rtc_func_t enFunc)
{
    ASSERT(IS_VALID_FUNC(enFunc));
    
    switch (enFunc)
    {
        case RtcCount:
            M0P_RTC->RTCCTL1_f.ST = 1u;
            break;
        case RtcTimer:
            M0P_RTC->RTCCTL2_f.TCST = 1u;
            break;
        case RtcFreqCorr:
            M0P_RTC->CALEN_f.CALEN = 1u;
            break;
        case RtcAlarmYearEn:
            M0P_RTC->RTCCTL1_f.YEAE = 1u;
            break;
        case RtcAlarmMonthEn:
            M0P_RTC->RTCCTL1_f.MONE = 1u;
            break;
        case RtcAlarmDayEn:
            M0P_RTC->RTCCTL1_f.DAYE = 1u;
            break;
        case RtcAlarmHourEn:
            M0P_RTC->RTCCTL1_f.HOUE = 1u;
            break;
        case RtcAlarmMinEn:
            M0P_RTC->RTCCTL1_f.MINE = 1u;
            break;
        case RtcAlarmSecEn:
            M0P_RTC->RTCCTL1_f.SENE = 1u;
            break;
        default:
            return ErrorInvalidParameter;
    }
    
    return Ok;
} /* Rtc_EnableFunc */

/**
 ******************************************************************************
 ** \brief  Disable functions of RTC
 **
 ** These functions includes RTC counting, Timer, Alarm compariron and frequency
 ** correction module.
 **
 ** \param [in] enFunc       Function types
 ** \arg   RtcCount          RTC counting
 ** \arg   RtcTimer          RTC timer
 ** \arg   RtcFreqCorr       RTC frequency correction module
 ** \arg   RtcAlarmYearEn    Year comparison enable of RTC alarm
 ** \arg   RtcAlarmMonthEn   Month comparison enable of RTC alarm
 ** \arg   RtcAlarmDayEn     Day comparison enable of RTC alarm
 ** \arg   RtcAlarmHourEn    Hour comparison enable of RTC alarm 
 ** \arg   RtcAlarmMinEn     Minute comparison enable of RTC alarm
 **
 ** \retval Ok                    RTC functions disabled normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - Invalid value of enFunc 
 **
 ******************************************************************************/
en_result_t Rtc_DisableFunc(en_rtc_func_t enFunc)
{
    ASSERT(IS_VALID_FUNC(enFunc));

    switch (enFunc)
    {
        case RtcCount:
            M0P_RTC->RTCCTL1_f.ST = 0u;
            break;
        case RtcTimer:
            M0P_RTC->RTCCTL2_f.TCST = 0u;
            break;
        case RtcFreqCorr:
            M0P_RTC->CALEN_f.CALEN = 0u;
            break;
        case RtcAlarmYearEn:
            M0P_RTC->RTCCTL1_f.YEAE = 0u;
            break;
        case RtcAlarmMonthEn:
            M0P_RTC->RTCCTL1_f.MONE = 0u;
            break;
        case RtcAlarmDayEn:
            M0P_RTC->RTCCTL1_f.DAYE = 0u;
            break;
        case RtcAlarmHourEn:
            M0P_RTC->RTCCTL1_f.HOUE = 0u;
            break;
        case RtcAlarmMinEn:
            M0P_RTC->RTCCTL1_f.MINE = 0u;
            break;
        case RtcAlarmSecEn:
            M0P_RTC->RTCCTL1_f.SENE = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }

    return Ok;
} /* Rtc_DisableFunc */

/**
 ******************************************************************************
 ** \brief Get RTC interrupt flag according to interrupt type
 **
 ** \param [in] enIrqSel           RTC interrupt type
 ** \arg   RtcRewriteError         RTC rewrite error interrupt flag
 ** \arg   RtcAlarmIrq             RTC alarm interrupt flag
 ** \arg   RtcTimerUnderFlow       RTC Timer underflow interrupt flag
 ** \arg   RtcOneHourFlag          1-hour count-up interrupt flag
 ** \arg   RtcOneMiniteFlag        1-Minute count-up interrupt flag
 ** \arg   RtcOneSecondFlag        1-second count-up interrupt flag
 ** \arg   RtcHalfSecondFlag       0.5-second count-up interrupt flag
 ** 
 ** \retval FALSE                 If one of following conditions are met:
 **                               - No RTC rewrite error [enStatus = RtcRewriteError]
 **                               - No element of alarm matchs [enStatus = RtcAlarmElementMatch]     
 **                               - RTC timer underflow doesn't occurs [enStatus = RtcTimerUnderFlow]
 **                               - 1-hour count-up flag is not set [enStatus = RtcOneHourFlag]
 **                               - 1-minute count-up flag is not set [enStatus = RtcOneMiniteFlag]
 **                               - 1-second count-up flag is not set [enStatus = RtcOneSecondFlag]
 **                               - 0.5-second count-up flag is not set [enStatus = RtcHalfSecondFlag]
 **                               - RTC is running [enStatus = RtcRunStatus]
 **                               - RTC timer is running [enStatus = RtcTimerStatus]
 ** \retval TRUE                 If one of following conditions are met:
 **                               - RTC rewrite error occurs [enStatus = RtcRewriteError]
 **                               - One of an element of alarm matchs [enStatus = RtcAlarmElementMatch]     
 **                               - RTC timer underflow doesn't occurs [enStatus = RtcTimerUnderFlow]
 **                               - 1-hour count-up flag is set [enStatus = RtcOneHourFlag]
 **                               - 1-minute count-up flag is set [enStatus = RtcOneMiniteFlag]
 **                               - 1-second count-up flag is set [enStatus = RtcOneSecondFlag]
 **                               - 0.5-second count-up flag is set [enStatus = RtcHalfSecondFlag]
 ** 
 ******************************************************************************/
boolean_t Rtc_GetIrqFlag(en_rtc_irq_sel_t enIrqSel)
{
    boolean_t bRet = FALSE;

    ASSERT(IS_VALID_IRQ_SEL(enIrqSel));
  
    switch (enIrqSel)
    {
        case RtcHalfSecondIrq:
            (M0P_RTC->RTCCTL1_f.INTSSF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcOneSecondIrq:
            (M0P_RTC->RTCCTL1_f.INTSF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcOneMinuteIrq:
            (M0P_RTC->RTCCTL1_f.INTMF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcOneHourIrq:
            (M0P_RTC->RTCCTL1_f.INTHF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcTimerIrq:
            (M0P_RTC->RTCCTL1_f.INTTMF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcAlarmIrq:
            (M0P_RTC->RTCCTL1_f.INTALF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcTimeRewriteErrorIrq:
            (M0P_RTC->RTCCTL1_f.INTERF == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        default:
            break;
    }
    
    return bRet;
} /* Rtc_GetIrqFlag */

/**
 ******************************************************************************
 ** \brief Clear RTC interrupt flag according to interrupt type
 **
 ** \param [in] enIrqSel           RTC interrupt type
 ** \arg   RtcRewriteError         RTC rewrite error interrupt flag
 ** \arg   RtcAlarmIrq             RTC alarm interrupt flag
 ** \arg   RtcTimerUnderFlow       RTC Timer underflow interrupt flag
 ** \arg   RtcOneHourFlag          1-hour count-up interrupt flag
 ** \arg   RtcOneMiniteFlag        1-Minute count-up interrupt flag
 ** \arg   RtcOneSecondFlag        1-second count-up interrupt flag
 ** \arg   RtcHalfSecondFlag       0.5-second count-up interrupt flag
 ** 
 ** \retval Ok                    RTC interrupt flag is cleared normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - Invalid value of enStatus 
 ** 
 ******************************************************************************/
en_result_t Rtc_ClrIrqFlag(en_rtc_irq_sel_t enIrqSel)
{      
    ASSERT(IS_VALID_IRQ_SEL(enIrqSel));

    switch (enIrqSel)
    {
        case RtcHalfSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSSF = 0u;
            break;
        case RtcOneSecondIrq:
            M0P_RTC->RTCCTL1_f.INTSF = 0u;
            break;
        case RtcOneMinuteIrq:
            M0P_RTC->RTCCTL1_f.INTMF = 0u;
            break;
        case RtcOneHourIrq:
            M0P_RTC->RTCCTL1_f.INTHF = 0u;
            break;
        case RtcTimerIrq:
            M0P_RTC->RTCCTL1_f.INTTMF = 0u;
            break;
        case RtcAlarmIrq:
            M0P_RTC->RTCCTL1_f.INTALF = 0u;
            break;
        case RtcTimeRewriteErrorIrq:
            M0P_RTC->RTCCTL1_f.INTERF = 0u;
            break;
        default:
            return ErrorInvalidParameter;
    }

    return Ok;
} /* Rtc_ClrIrqFlag */

/**
 ******************************************************************************
 ** \brief Get status of RTC according to status type
 **
 ** \param [in] enStatus           RTC status
 ** \arg   RtcRunStatus            RTC counter run status
 ** \arg   RtcTimerStatus          RTC timer status
 ** 
 ** \retval FALSE                 If one of following conditions are met:
 **                               - RTC is running [enStatus = RtcRunStatus]
 **                               - RTC timer is running [enStatus = RtcTimerStatus]
 ** \retval TRUE                 If one of following conditions are met:
 **                               - RTC counter stops [enStatus = RtcRunStatus]
 **                               - RTC timer stops [enStatus = RtcTimerStatus]
 ** 
 ******************************************************************************/
boolean_t Rtc_GetStatus(en_rtc_status_t enStatus)
{
    boolean_t bRet = FALSE;

    ASSERT(IS_VALID_STATUS(enStatus));
    
    switch(enStatus)
    {
        case RtcRunStatus:
            (M0P_RTC->RTCCTL1_f.STAT == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        case RtcTimerStatus:
            (M0P_RTC->RTCCTL2_f.TCRUN == 1u) ? (bRet = TRUE) : (bRet = FALSE);
            break;
        default:
            break;  
    }
    
    return bRet;
} /* Rtc_GetStatus */


/**
 ******************************************************************************
 ** \brief Reset RTC
 **
 ** \param [in] none
 ******************************************************************************/
en_result_t Rtc_Reset(void)
{
    M0P_RTC->RTCCTL1_f.SWRST = 1;

    return Ok;
} /* Rtc_Reset */

/**
 ******************************************************************************
 ** \brief Set time and date information of Alarm
 **
 ** \param [in] pstcAlarm         Time and date structure 
 ** \param [in] bUpdateAlarmTime  Update alarm time or not
 ** \param [in] bUpdateAlarmDate  Update alarm date or not

 ** \retval Ok                    RTC Alarm time and date is set normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcAlarm == NULL
 **                               - invalid month if bUpdateAlarmDate is TRUE
 **                               - invalid day if bUpdateAlarmDate is TRUE
 **                               - invalid hour if bUpdateAlarmTime is TRUE
 **                               - invalid minute if bUpdateAlarmTime is TRUE
 **                               - invalid second if bUpdateAlarmTime is TRUE
 ** 
 ******************************************************************************/
en_result_t Rtc_SetAlarmDateTime(stc_rtc_alarm_t* pstcAlarm,
                                 boolean_t bUpdateAlarmTime,
                                 boolean_t bUpdateAlarmDate)
{
    ASSERT(NULL != pstcAlarm);   
  
    if(TRUE == bUpdateAlarmTime)
    {
        ASSERT(IS_VALID_HOUR(pstcAlarm->u8Hour));
        ASSERT(IS_VALID_MIN(pstcAlarm->u8Minute));
        ASSERT(IS_VALID_SEC(pstcAlarm->u8Second));
        
        M0P_RTC->ASEN  = DecToBcd(pstcAlarm->u8Second);
        M0P_RTC->AMIN = DecToBcd(pstcAlarm->u8Minute);
        M0P_RTC->AHOUR  = DecToBcd(pstcAlarm->u8Hour);
    }
    
    if(TRUE == bUpdateAlarmDate)
    {
        ASSERT(IS_VALID_MONTH(pstcAlarm->u8Month));
        ASSERT(IS_VALID_DAY(pstcAlarm->u8Day));
        
        M0P_RTC->ADATE  = (uint8_t)DecToBcd(pstcAlarm->u8Day);
        M0P_RTC->AMON = DecToBcd(pstcAlarm->u8Month);
        M0P_RTC->AYEAR  = DecToBcd(pstcAlarm->u16Year - RTC_YEAR_BASE);
    }
    
    return Ok;
} /* Rtc_SetAlarmDateTime */


/**
 ******************************************************************************
 ** \brief Get time and date information of Alarm
 **
 ** \param [in] pstcAlarm         Time and date structure 
 ** \retval Ok                    RTC Alarm time and date is read normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcAlarm == NULL 
 ** 
 ******************************************************************************/
en_result_t Rtc_GetAlarmDateTime(stc_rtc_alarm_t* pstcAlarm)
{
    uint8_t u8BcdSec, u8BcdMin, u8BcdHour, u8Day, u8Month, u8Year;

    ASSERT(NULL != pstcAlarm);

    u8BcdSec  = M0P_RTC->ASEN;
    u8BcdMin  = M0P_RTC->AMIN;
    u8BcdHour = M0P_RTC->AHOUR;
    u8Day     = M0P_RTC->ADATE;
    u8Month   = M0P_RTC->AMON;
    u8Year    = M0P_RTC->AYEAR;
    
    pstcAlarm->u8Second = BcdToDec(u8BcdSec);
    pstcAlarm->u8Minute = BcdToDec(u8BcdMin);
    pstcAlarm->u8Hour   = BcdToDec(u8BcdHour);
    pstcAlarm->u8Day    = BcdToDec(u8Day);
    pstcAlarm->u8Month  = BcdToDec(u8Month);
    pstcAlarm->u16Year  = BcdToDec(u8Year) + RTC_YEAR_BASE;
    
    return Ok;
} /* Rtc_GetAlarmDateTime */

/**
 ******************************************************************************
 ** \brief Set Day of the Week
 **
 ** This function calculates the day of the week from YY-MM-DD in the Time
 ** structure. It uses mktime of time.h library.
 **
 ** \param  [in,out] pstcRtcTime     RTC Time structure
 **
 ** \retval Ok                       Internal data has been setup
 ** \retval ErrorInvalidParameter    pstcRtcTime == NULL or mktime failed
 **
 ******************************************************************************/
en_result_t Rtc_SetDayOfWeek(stc_rtc_time_t* pstcRtcTime)
{
    en_result_t enResult;
    struct tm stcTime;

    enResult = ErrorInvalidParameter;

    ASSERT(NULL != pstcRtcTime);
    
    /* Check for NULL pointer */
    if (NULL != pstcRtcTime)
    {
        enResult = Ok;
        /* Convert RTC time structure to time.h tm structure */
        RtcToTm(pstcRtcTime, &stcTime);

        /* Calculated raw time (UNIX time) is error */
        if ((time_t)RTC_ERR == mktime(&stcTime))
        {
            enResult = ErrorInvalidParameter;
        }

        if (Ok == enResult)
        {
            /* Set calculated the day of week */
            pstcRtcTime->u8DayOfWeek = (uint8_t)(stcTime.tm_wday);
        }
    }

    return (enResult);
} /* Rtc_SetDayOfWeek */
                

/**
 ******************************************************************************
 ** \brief Set cycle of RTC timer
 **
 ** \param [in] u32TimerCycle     Timer cycle
 ** \retval Ok                    RTC timer cycle is set normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - u32TimerCycle > RTC_MAX_TIMER_SET_VALUE
 ** 
 ** \note The unit of parameter u32TimerCycle is second.
 ** 
 ******************************************************************************/
en_result_t Rtc_SetTimerCycle(uint32_t u32TimerCycle)
{
    uint32_t u32Count;
  
    if(u32TimerCycle > RTC_MAX_TIMER_SET_VALUE)
    {
        return ErrorInvalidParameter;
    }
    
    u32Count = TIME_TO_TVAL(u32TimerCycle);
    
    M0P_RTC->TVAL = (uint8_t)u32Count;
    
    return Ok;
} /* Rtc_SetTimerCycle */

/**
 ******************************************************************************
 ** \brief Set calibration value and cycle for RTC frequency correction module
 **
 ** \param [in] pstcFreqCorrCfg   RTC frequency correction structure
 ** \retval Ok                    RTC frequency correction value is set normally
 ** \retval ErrorInvalidParameter If one of following conditions are met:
 **                               - pstcFreqCorrCfg->u16FreqCorrValue > RTC_MAX_FREQ_CORR_VALUE
 **                               - pstcFreqCorrCfg->u16FreqCorrCycle > RTC_MAX_FREQ_CORR_CYCLE_SET_VALUE
 ** 
 ******************************************************************************/
en_result_t Rtc_SetFreqCorrCfg(stc_rtc_freq_corr_t* pstcFreqCorrCfg)
{
    ASSERT(NULL != pstcFreqCorrCfg);
    ASSERT(IS_VALID_FREQCORR_VALUE(pstcFreqCorrCfg->u16FreqCorrValue));
    ASSERT(IS_VALID_FREQCORR_CYCLE(pstcFreqCorrCfg->u16FreqCorrCycle));
     
    M0P_RTC->CALVAL = (uint8_t)pstcFreqCorrCfg->u16FreqCorrValue;
    M0P_RTC->CALCYC = pstcFreqCorrCfg->u16FreqCorrCycle - 1;
    
    return Ok;
} /* Rtc_SetFreqCorrCfg */


/**
 ******************************************************************************
 ** \brief Convert the RTC time structure to raw time
 **
 ** This function calculates the "raw" time ('UNIX time') from RTC time structure.
 **
 ** \param [in] pstcRtcTime     Pointer to RTC Time structure
 **
 ** \return     Calculated time or '-1' on error
 **
 ******************************************************************************/
time_t Rtc_DateTimeToRawTime(stc_rtc_time_t* pstcRtcTime)
{
    time_t uiTime;
    struct tm stcTime;
    
    /* Check for NULL pointer */
    if (NULL == pstcRtcTime)
    {
        uiTime = (time_t)RTC_ERR;
    }
    else
    {
        /* Convert RTC time structure to time.h tm structure */
        RtcToTm(pstcRtcTime, &stcTime);
        uiTime = mktime(&stcTime);
    }

    /* Return raw time (UNIX time) */
    return (uiTime);
} /* Rtc_DateTimeToRawTime */


/**
 ******************************************************************************
 ** \brief Convert the raw time to RTC time structure
 **
 ** This function calculates the RTC time structure from "raw" time ('UNIX time')
 ** ('UNIX time').
 **
 ** \param [out] pstcRtcTime         RTC Time structure
 ** \param [in]  tRawTime            "Raw" time
 **
 ** \retval Ok                       Internal data has been setup
 ** \retval ErrorInvalidParameter    pstcRtcTime == NULL or localtime failed
 **
 ******************************************************************************/
en_result_t Rtc_RawTimeToDateTime( stc_rtc_time_t* pstcRtcTime,
                                            time_t          tRawTime)
{
    en_result_t enResult;
    struct tm* pstcTime;
    enResult = ErrorInvalidParameter;

    ASSERT(NULL != pstcRtcTime);    
        
    /* Check for NULL pointer */
    if (NULL != pstcRtcTime)
    {
        /* Get the pointer which converted to RTC time structure from raw time */
        /* The result of year begin with 1900. */
        /* The result of month is 0(Jan.) to 11(Dec.). */
        /* The result of week is 0(Sun.) to 6(Sat.). */
        pstcTime = localtime((const time_t*) &tRawTime);

        /* Un-success */
        if (NULL == pstcTime)
        {
            enResult = ErrorInvalidParameter;
        }
        else
        {
            TmToRtc(pstcRtcTime, pstcTime);
            
            enResult = Ok;
        }
    }

    return (enResult);
} /* Rtc_RawTimeToDateTime */

//@} // RTCGroup


/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

