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
/** \file rtc.h
 **
 ** RTC function driver define.
 ** @link RTC Group Some description @endlink
 **
 **   - 2016-10-24  1.0  Min Wang First version for Device Driver Library of Module.
 **
 ******************************************************************************/

#ifndef __RTC_H__
#define __RTC_H__

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include <time.h>
#include "ddl.h"
#include "interrupts_hc32l15.h"
#include "clk.h"

/* C binding of definitions if building with C++ compiler */
#ifdef __cplusplus
extern "C"
{
#endif

//@{

/******************************************************************************
 * Global type definitions
 ******************************************************************************/
/**
 ******************************************************************************
 ** \brief Maximum Frequency Correction Value
 ******************************************************************************/
#define RTC_MAX_FREQ_CORR_VALUE (0x7Fu)

/**
 ******************************************************************************
 ** \brief Maximum Frequency Correction Cycle Value
 ******************************************************************************/
#define RTC_MAX_FREQ_CORR_CYCLE_SET_VALUE (0x1FFu)

/**
 ******************************************************************************
 ** \brief Maxmimum Timer Setting Value [unit: second]
 ******************************************************************************/
#define RTC_MAX_TIMER_SET_VALUE (172799)

/**
 ******************************************************************************
 ** \brief RTC clock source frequency
 ******************************************************************************/
#define RTC_CLOCK_PRES             32768

/**
 ******************************************************************************
 ** \brief RTC clock source
 **
 ** To select RTC clock source input
 ******************************************************************************/
typedef enum en_rtc_clk_sel
{
    RtcLSXTClk = 0u,                ///< external low cr 
    RtcLICRClk = 1u,                ///< internal low cr 
}en_rtc_clk_sel_t;

/**
 ******************************************************************************
 ** \brief RTC work mode status definition
 **
 ** To select RTC module work mode
 ******************************************************************************/
typedef enum en_rtc_status
{
    RtcRunStatus             = 0u,  ///< RTC counter run status
    RtcTimerStatus           = 1u,  ///< RTC timer status
}en_rtc_status_t;


/**
 ******************************************************************************
 ** \brief RTCCO pin output frequence definition
 **
 ** To select RTCCO output frequence
 ******************************************************************************/
typedef enum en_rtc_rtcco_sel
{
    RtccoOutput2Hz = 0u,    ///< Output 2Hz signal at RTCCO pin
    RtccoOutput1Hz = 1u,    ///< Output 1Hz signal at RTCCO pin
}en_rtc_rtcco_sel_t;


/**
 ******************************************************************************
 ** \brief RTC correct function definition
 **
 ** To config the RTC correct function
 ******************************************************************************/
typedef struct stc_rtc_freq_corr
{
    uint16_t u16FreqCorrValue;  ///< Frequency correction value. Max 0x7F.
    uint16_t u16FreqCorrCycle;  ///< Frequency correction cycle. Max 0x1FF.
}stc_rtc_freq_corr_t;


/**
 ******************************************************************************
 ** \brief RTC function type definition
 ******************************************************************************/
typedef enum en_rtc_func
{
    RtcCount         = 0u,    ///< RTC counting
    RtcTimer         = 1u,    ///< RTC timer
    RtcFreqCorr      = 2u,    ///< RTC frequency correction module
    RtcAlarmYearEn   = 3u,    ///< Year comparison enable of RTC alarm
    RtcAlarmMonthEn  = 4u,    ///< Month comparison enable of RTC alarm
    RtcAlarmDayEn    = 5u,    ///< D comparison enable of RTC alarm
    RtcAlarmHourEn   = 6u,    ///< Hour comparison enable of RTC alarm
    RtcAlarmMinEn    = 7u,    ///< Minute comparison enable of RTC alarm
    RtcAlarmSecEn    = 8u,    ///< Second comparison enable of RTC alarm
}en_rtc_func_t;


/**
 *****************************************************************************
 ** \brief RTC timmer function configuration definition
 **
 ** The config the RTC timmer function
 *****************************************************************************/
typedef enum en_rtc_time_mode
{
    RtcTimerOneshot = 0u,  ///< One-shot mode
    RtcTimerPeriod  = 1u,  ///< Periodical mode
}en_rtc_time_mode_t;

typedef struct stc_rtc_timer
{
    en_rtc_time_mode_t       enMode;            ///< Timer mode
    uint32_t                 u32TimerCycle;     ///< The cycle [uint: second] of timer, after these seconds elapse, timer interrpt will occur
}stc_rtc_timer_t;

/**
 *****************************************************************************
 ** \brief RTC clock divider definition
 **
 ** The config the RTC clock RIN divider ratio
 *****************************************************************************/
typedef enum en_rtc_div_ratio
{
    RtcDivRatio1     = 0x00u,    ///< RIN clock is not divided
    RtcDivRatio2     = 0x01u,    ///< RIN clock is divided by 2
    RtcDivRatio4     = 0x02u,    ///< RIN clock is divided by 4
    RtcDivRatio8     = 0x03u,    ///< RIN clock is divided by 8
    RtcDivRatio16    = 0x04u,    ///< RIN clock is divided by 16
    RtcDivRatio32    = 0x05u,    ///< RIN clock is divided by 32
    RtcDivRatio64    = 0x06u,    ///< RIN clock is divided by 64
    RtcDivRatio128   = 0x07u,    ///< RIN clock is divided by 128
    RtcDivRatio256   = 0x08u,    ///< RIN clock is divided by 256
    RtcDivRatio512   = 0x09u,    ///< RIN clock is divided by 512
} en_rtc_div_ratio_t ;

/**
 *****************************************************************************
 ** \brief RTC time and date variable definition
 **
 **
 *****************************************************************************/
typedef struct stc_rtc_time
{
    uint8_t  u8Second;      ///< Second (Format 0...59)
    uint8_t  u8Minute;      ///< Minutes (Format 0...59)
    uint8_t  u8Hour;        ///< Hour (Format 0...23)
    uint8_t  u8Day;	        ///< Day (Format 1...31)
    uint8_t  u8DayOfWeek;   ///< Day of the week (Format 0...6)
    uint8_t  u8Month;       ///< Month (Format 1...12)
    uint16_t u16Year;       ///< Year (Format 1...99) + 2000
} stc_rtc_time_t;

/**
 *****************************************************************************
 ** \brief RTC alarm variable definition
 **
 **
 *****************************************************************************/
typedef struct stc_rtc_alarm
{
    uint8_t  u8Second; ///< Alarm second (Format 1...59)
    uint8_t  u8Minute; ///< Alarm minutes (Format 1...59)
    uint8_t  u8Hour;   ///< Alarm hour (Format 0...23)
    uint8_t  u8Day;    ///< Alarm day (Format 1...31)
    uint8_t  u8Month;  ///< Alarm month (Foramt 1...12)
    uint16_t u16Year;  ///< Alarm year (Format 1...99) + 2000
} stc_rtc_alarm_t;

/**
 *****************************************************************************
 ** \brief RTC day of week definition
 **
 **
 *****************************************************************************/
typedef enum en_rtc_day_of_week
{
    RtcSunday    = 0u,     ///< Sunday
    RtcMonday    = 1u,     ///< Monday
    RtcTuesday   = 2u,     ///< Tuesday
    RtcWednesday = 3u,     ///< Wednesday
    RtcThursday  = 4u,     ///< Thursday
    RtcFriday    = 5u,     ///< Friday
    RtcSaturday  = 6u,     ///< Saturday
} en_rtc_day_of_week_t;

/**
 *****************************************************************************
 ** \brief RTC month definition
 **
 **
 *****************************************************************************/
typedef enum en_rtc_month
{
    RtcJanuary   = 1u,   ///< January
    RtcFebuary   = 2u,   ///< February
    RtcMarch     = 3u,   ///< March
    RtcApril     = 4u,   ///< April
    RtcMay       = 5u,   ///< May
    RtcJune      = 6u,   ///< June
    RtcJuly      = 7u,   ///< July
    RtcAugust    = 8u,   ///< August
    RtcSeptember = 9u,   ///< September
    RtcOctober   = 10u,  ///< October
    RtcNovember  = 11u,  ///< November
    RtcDecember  = 12u,  ///< December
} en_rtc_month_t;

/**
 *****************************************************************************
 ** \brief RTC function interrupt source definition
 **
 **
 *****************************************************************************/
typedef struct stc_rtc_irq_en
{
    boolean_t   bHalfSecondIrq;        ///< TRUE:  0.5-Second interrupt enabled
                                       ///< FALSE: 0.5-Second interrupt disabled
    boolean_t   bOneSecondIrq;         ///< TRUE:  1-Second interrupt enabled
                                       ///< FALSE: 1-Second interrupt disabled
    boolean_t   bOneMinuteIrq;         ///< TRUE:  1-Minute interrupt enabled
                                       ///< FALSE: 1-Minute interrupt disabled
    boolean_t   bOneHourIrq;           ///< TRUE:  1-Hour interrupt enabled
                                       ///< FALSE: 1-Hour interrupt disabled
    boolean_t   bTimerIrq;             ///< TRUE:  Timer interrupt enabled
                                       ///< FALSE: Timer interrupt disabled
    boolean_t   bAlarmIrq;             ///< TRUE:  Alarm interrupt enabled
                                       ///< FALSE: Alarm interrupt disabled
    boolean_t   bTimeRewriteErrorIrq;  ///< TRUE:  Time Rewrite Error interrupt enabled
                                       ///< FALSE: Time Rewrite Error interrupt disabled
} stc_rtc_irq_en_t;

/**
 *****************************************************************************
 ** \brief RTC function interrupt status definition
 **
 **
 *****************************************************************************/
typedef enum en_rtc_irq_sel
{
    RtcHalfSecondIrq = 0u,   ///< 0.5-second count-up interrupt request
    RtcOneSecondIrq  = 1u,   ///< 1-second count-up interrupt request
    RtcOneMinuteIrq  = 2u,   ///< 1-Minute count-up interrupt request
    RtcOneHourIrq    = 3u,   ///< 1-hour count-up interrupt request
    RtcTimerIrq      = 4u,   ///< Timer underflow interrupt request
    RtcAlarmIrq      = 5u,   ///< Alarm interrupt request
    RtcTimeRewriteErrorIrq = 6u, ///< Rewrite error interrupt request
} en_rtc_irq_sel_t;

/**
 *****************************************************************************
 ** \brief RTC function interrupt copyback function definition
 **
 **
 *****************************************************************************/
typedef struct stc_rtc_irq_cb
{
    func_ptr_t               pfnTimeWrtErrIrqCb; ///< Callback function pointer for Timer writing error Interrupt
    func_ptr_t               pfnAlarmIrqCb;      ///< Callback function pointer for Alarm Interrupt
    func_ptr_t               pfnTimerIrqCb;      ///< Callback function pointer for Timer Interrupt
    func_ptr_t               pfnHalfSecondIrqCb; ///< Callback function pointer for 0.5-Second Interrupt
    func_ptr_t               pfnOneSecondIrqCb;  ///< Callback function pointer for One Second Interrupt
    func_ptr_t               pfnOneMinuteIrqCb;  ///< Callback function pointer for One Minute Interrupt
    func_ptr_t               pfnOneHourIrqCb;    ///< Callback function pointer for One Hour Interrupt
}stc_rtc_irq_cb_t, stc_rtc_intern_cb_t;

/**
 *****************************************************************************
 ** \brief RTC function config definition
 **
 **
 *****************************************************************************/
typedef struct stc_rtc_config
{
    uint32_t                 u32ClkPrescaler;      ///< RTC source clock prescaler
    boolean_t                bEnSuboutDivider;     ///< TRUE:  Enable Divider for Divider Ratio
                                                   ///< FALSE: Disable Divider for Divider Ratio
    en_rtc_clk_sel_t         enClkSel;             ///< TRUE:  RTC clock selection
    en_rtc_div_ratio_t       enDividerRatio;       ///< Divider ratio for SUBOUT
    en_rtc_rtcco_sel_t       enRtccoSel;           ///< Divider of CO signal, see #en_rtc_rtcco_sel_t for details

    stc_rtc_freq_corr_t*     pstcFreqCorrConfig;   ///< Pointer to frequency correction configuration, if it is set to NULL, frequency correction function will not be initialized.
    stc_rtc_time_t*          pstcTimeDate;         ///< Pointer to time configuration structure, if it is set to NULL, time and date will not be initialized.
    stc_rtc_alarm_t*         pstcAlarm;            ///< Pointer to alarm configuration structure, if it is set to NULL, alarm will not be initialized.
    stc_rtc_timer_t*         pstcTimer;            ///< Pointer to timer configuration structure, if it is set to NULL, timer will not be initialized.
    stc_rtc_irq_en_t*        pstcIrqEn;            ///< Pointer to interrupt enable structure, if it is set to NULL, no interrupts will not be enabled.
    stc_rtc_irq_cb_t*        pstcIrqCb;            ///< Pointer to interrupt callback function structure, if it is set to NULL, no interrupt callback functions will not be set.
    boolean_t                bTouchNvic;           ///< TRUE: enable NVIC, FALSE: don't enable NVIC
    boolean_t                bRunNotInit;          ///< TRUE: don't initialize RTC when RTC is running, FALSE: Initialize RTC any time
} stc_rtc_config_t;


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
/* interrupt config */
en_result_t Rtc_EnableIrq(en_rtc_irq_sel_t enIrqSel);
en_result_t Rtc_DisableIrq(en_rtc_irq_sel_t enIrqSel);

/* Init/Deinit */
en_result_t Rtc_Init(stc_rtc_config_t* pstcConfig);
en_result_t Rtc_DeInit(boolean_t bTouchNvic);


/* Function Enable/Disable */
en_result_t Rtc_EnableFunc(en_rtc_func_t enFunc);
en_result_t Rtc_DisableFunc(en_rtc_func_t enFunc);


/* Get/Clr irq flag */
boolean_t Rtc_GetIrqFlag(en_rtc_irq_sel_t enIrqSel);
en_result_t Rtc_ClrIrqFlag(en_rtc_irq_sel_t enIrqSel);


/* Write/Read count value */
en_result_t Rtc_SetDateTime(stc_rtc_time_t* pstcTimeDate,
                            boolean_t bContinue,
                            boolean_t bUpdateTime,
                            boolean_t bUpdateDate);
en_result_t Rtc_ReadDateTime(stc_rtc_time_t* pstcTimeDate);

/* rtc timer value */
en_result_t Rtc_SetTimerCycle(uint32_t u32TimerCycle);

/* rtc correct function config */
en_result_t Rtc_SetFreqCorrCfg(stc_rtc_freq_corr_t* pstcFreqCorrCfg);

/* rtc alarm information set and get */
en_result_t Rtc_SetAlarmDateTime(stc_rtc_alarm_t* pstcAlarm,
                                 boolean_t bUpdateAlarmTime,
                                 boolean_t bUpdateAlarmDate);
en_result_t Rtc_GetAlarmDateTime(stc_rtc_alarm_t* pstcAlarm);

/* rtc week set */
en_result_t Rtc_SetDayOfWeek(stc_rtc_time_t* pstcRtcTime);

/* rtc time and raw time convert */
time_t Rtc_DateTimeToRawTime(stc_rtc_time_t* pstcRtcTime);
en_result_t Rtc_RawTimeToDateTime(stc_rtc_time_t* pstcRtcTime,
                                    time_t tRawTime);


/* other function */
boolean_t Rtc_GetStatus(en_rtc_status_t enStatus);
en_result_t Rtc_Reset(void);




//@} // RTCGroup

#ifdef __cplusplus
}
#endif

#endif /* __RTC_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/
