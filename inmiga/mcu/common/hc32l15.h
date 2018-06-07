/*******************************************************************************
* Copyright (C) 2017, Huada Semiconductor Co.,Ltd All rights reserved.
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
/** \\file HC32L15.h
**
** Auto generate.
** Headerfile for HC32L15 series MCU
**
** History:
**
**   - 2017-07-04  0.1   First version for Device Driver Library of Module.
**
******************************************************************************/

#ifndef __HC32L15_H__
#define __HC32L15_H__

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************************************
* Configuration of the Cortex-M0P Processor and Core Peripherals
******************************************************************************/
#define __MPU_PRESENT           0 /* No MPU                                       */
#define __NVIC_PRIO_BITS        2 /* M0P uses 2 Bits for the Priority Levels      */
#define __Vendor_SysTickConfig  0 /* Set to 1 if different SysTick Config is used */

/******************************************************************************
* Interrupt Number Definition
******************************************************************************/
typedef enum IRQn
{
    NMI_IRQn            = -14, /*  2 Non Maskable                            */
    HardFault_IRQn      = -13, /*  3 Hard Fault                              */
    SVC_IRQn            = -5,  /* 11 SV Call                                 */
    PendSV_IRQn         = -2,  /* 14 Pend SV                                 */
    SysTick_IRQn        = -1,  /* 15 System Tick                             */
    
    CSV_IRQn            = 0 ,
    SWDT_IRQn           = 1 ,
    LVD_IRQn            = 2 ,
    EXINT0_7_IRQn       = 4 ,
    EXINT8_15_IRQn      = 5 ,
    DTIM_IRQn           = 6 ,
    MSC0RX_IRQn         = 7 ,
    MSC0TX_IRQn         = 8 ,
    MSC1RX_IRQn         = 9 ,
    MSC1TX_IRQn         = 10,
    MSC2RX_IRQn         = 11,
    MSC2TX_IRQn         = 12,
    MSC4RX_IRQn         = 15,
    MSC4TX_IRQn         = 16,
    MSC5RX_IRQn         = 17,
    MSC5TX_IRQn         = 18,
    MSC6RX_IRQn         = 19,
    MSC6TX_IRQn         = 20,
    OSC_WU_RTC_IRQn     = 24,
    ADC_IRQn            = 25,
    VC_IRQn             = 26,
    SCI_IRQn            = 27,
    CTIM0_7_FLASH_IRQn  = 31,
    
    
} IRQn_Type;


#include <core_cm0plus.h>
#include <stdint.h>

#define SUCCESS         (0)
#define ERROR           (-1)

#ifndef NULL
#define NULL            (0)
#endif


/******************************************************************************/
/*                Device Specific Peripheral Registers structures             */
/******************************************************************************/

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

typedef struct
{
    __IO uint32_t ADC_EN                    : 1;
    __IO uint32_t ADC_CLK_SEL               : 2;
    uint32_t RESERVED3                      : 3;
    __IO uint32_t ADC_VREF                  : 1;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t ADC_CHL_SEL               : 4;
    uint32_t RESERVED12                     : 4;
    __IO uint32_t ADCIE                     : 1;
    __IO uint32_t ADCIF                     : 1;
} stc_adc_ctl1_field_t;

typedef struct
{
    __IO uint8_t ADC_START                  : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t ADC_ALIGN                  : 1;
    __IO uint8_t ADC_MODE                   : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t VINBUF_EN                  : 1;
    __IO uint8_t ADC_SAMPLE_SEL             : 2;
} stc_adc_ctl2_field_t;

typedef struct
{
    __IO uint16_t RESULT                    :16;
} stc_adc_result_field_t;

typedef struct
{
    __IO uint32_t CMPIF                     : 1;
} stc_adc_adcmpif_field_t;

typedef struct
{
    __IO uint32_t CMPF                      : 1;
} stc_adc_adcmpf_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 2;
    __IO uint16_t CMPEN                     : 1;
    __IO uint16_t CMPIE                     : 1;
    __IO uint16_t CMPTRIG                   : 1;
    __IO uint16_t CMPCNT                    : 3;
    uint16_t RESERVED8                      : 5;
    __IO uint16_t CMPCNT_ST                 : 3;
} stc_adc_adcmpctl_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 6;
    __IO uint16_t CDL                       :10;
} stc_adc_adcmpl_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 6;
    __IO uint16_t CDH                       :10;
} stc_adc_adcmph_field_t;

typedef struct
{
    __IO uint16_t START                     : 1;
    __IO uint16_t FUNC_SEL                  : 2;
    __IO uint16_t KEY_SEL                   : 2;
    __IO uint16_t STEP_EN                   : 1;
    uint16_t RESERVED6                      : 1;
    __IO uint16_t DFA_EN                    : 1;
    __IO uint16_t DFA_STA                   : 1;
    __IO uint16_t RAND_TEN                  : 1;
    __IO uint16_t DUMMY_EN                  : 1;
    __IO uint16_t DUMMY_SEL                 : 2;
} stc_aes_con_field_t;

typedef struct
{
    __IO uint32_t DATA0                     :32;
} stc_aes_data0_field_t;

typedef struct
{
    __IO uint32_t DATA1                     :32;
} stc_aes_data1_field_t;

typedef struct
{
    __IO uint32_t DATA2                     :32;
} stc_aes_data2_field_t;

typedef struct
{
    __IO uint32_t DATA3                     :32;
} stc_aes_data3_field_t;

typedef struct
{
    __IO uint32_t KEY0                      :32;
} stc_aes_key0_field_t;

typedef struct
{
    __IO uint32_t KEY1                      :32;
} stc_aes_key1_field_t;

typedef struct
{
    __IO uint32_t KEY2                      :32;
} stc_aes_key2_field_t;

typedef struct
{
    __IO uint32_t KEY3                      :32;
} stc_aes_key3_field_t;

typedef struct
{
    __IO uint32_t KEY4                      :32;
} stc_aes_key4_field_t;

typedef struct
{
    __IO uint32_t KEY5                      :32;
} stc_aes_key5_field_t;

typedef struct
{
    __IO uint32_t KEY6                      :32;
} stc_aes_key6_field_t;

typedef struct
{
    __IO uint32_t KEY7                      :32;
} stc_aes_key7_field_t;

typedef struct
{
    __IO uint32_t RNG0                      :32;
} stc_aes_rng0_field_t;

typedef struct
{
    __IO uint32_t RNG1                      :32;
} stc_aes_rng1_field_t;

typedef struct
{
    __IO uint8_t INT_EN                     : 1;
    __IO uint8_t ALM_INT                    : 1;
} stc_aes_int_con_field_t;

typedef struct
{
    __IO uint8_t DIV_EN                     : 1;
} stc_aes_div_en_field_t;

typedef struct
{
    __IO uint8_t CLK_SEL                    : 1;
    __IO uint8_t BUZ_ST                     : 1;
} stc_buzzer_buz_ctl_field_t;

typedef struct
{
    __IO uint8_t BUZ_CNT                    : 8;
} stc_buzzer_buz_cnt_field_t;

typedef struct
{
    __IO uint8_t HC_EN                      : 1;
    __IO uint8_t MAIN_EN                    : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t SUB_EN                     : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t INPUT                      : 3;
} stc_clock_ctrl_field_t;

typedef struct
{
    __IO uint8_t HC_RDY                     : 1;
    __IO uint8_t MAIN_RDY                   : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t SUB_RDY                    : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t SRC                        : 3;
} stc_clock_clk_stb_field_t;

typedef struct
{
    __IO uint32_t STBM                      : 2;
    __IO uint32_t DSTBEN                    : 1;
    uint32_t RESERVED3                      : 1;
    __IO uint32_t SPLV                      : 1;
    uint32_t RESERVED5                      :11;
    __IO uint32_t KEY                       :16;
} stc_clock_lpm_ctl_field_t;

typedef struct
{
    __IO uint16_t PWR                       : 1;
    __IO uint16_t RSTB                      : 1;
    uint16_t RESERVED2                      : 1;
    __IO uint16_t LVDR                      : 1;
    __IO uint16_t SWWDG                     : 1;
    __IO uint16_t HWWDG                     : 1;
    __IO uint16_t CSV                       : 1;
    __IO uint16_t AF                        : 1;
    __IO uint16_t SW                        : 1;
} stc_clock_stat_field_t;

typedef struct
{
    __IO uint8_t DIV                        : 3;
} stc_clock_bc_div_field_t;

typedef struct
{
    __IO uint8_t DIV                        : 2;
} stc_clock_apb0_ctrl_field_t;

typedef struct
{
    __IO uint8_t DIV                        : 2;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t RST                        : 1;
    uint8_t RESERVED5                       : 2;
    __IO uint8_t EN                         : 1;
} stc_clock_apb1_ctrl_field_t;

typedef struct
{
    __IO uint8_t SWDS                       : 2;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t SWCKE                      : 1;
    __IO uint8_t HWCKE                      : 1;
    __IO uint8_t DTCKE                      : 1;
} stc_clock_clk_ctl_field_t;

typedef struct
{
    __IO uint8_t MAINWT                     : 4;
    __IO uint8_t SUBWT                      : 4;
} stc_clock_cswt_field_t;

typedef struct
{
    __IO uint16_t MFCME                     : 1;
    __IO uint16_t SFCME                     : 1;
    __IO uint16_t MFCMRE                    : 1;
    __IO uint16_t SFCMRE                    : 1;
    uint16_t RESERVED4                      : 4;
    __IO uint16_t AFDE                      : 1;
    __IO uint16_t AFDRE                     : 1;
    uint16_t RESERVED10                     : 2;
    __IO uint16_t AFDCC                     : 3;
} stc_clock_fcm_ctl_field_t;

typedef struct
{
    __IO uint8_t MCFDF                      : 1;
    __IO uint8_t SCFDF                      : 1;
} stc_clock_fcm_str_field_t;

typedef struct
{
    __IO uint16_t AFDWH                     :16;
} stc_clock_afdwh_ctl_field_t;

typedef struct
{
    __IO uint16_t AFDWL                     :16;
} stc_clock_afdwl_ctl_field_t;

typedef struct
{
    __IO uint16_t AFDC                      :16;
} stc_clock_afdc_ctl_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 5;
    __IO uint8_t SWWDG_BRK                  : 1;
    uint8_t RESERVED6                       : 1;
    __IO uint8_t HWWDG_BRK                  : 1;
} stc_clock_dbwdt_ctrl_field_t;

typedef struct
{
    __IO uint8_t MAINEN                     : 1;
    __IO uint8_t SUBEN                      : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t MCSVIE                     : 1;
    __IO uint8_t SCSVIE                     : 1;
    __IO uint8_t FCSEN                      : 1;
} stc_clock_int_ctrl_field_t;

typedef struct
{
    __IO uint8_t MAIN                       : 1;
    __IO uint8_t SUB                        : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t MCSVI                      : 1;
    __IO uint8_t SCSVI                      : 1;
    __IO uint8_t FCS                        : 1;
} stc_clock_int_pend_field_t;

typedef struct
{
    __IO uint8_t MAIN                       : 1;
    __IO uint8_t SUB                        : 1;
    uint8_t RESERVED2                       : 1;
    __IO uint8_t MCSVC                      : 1;
    __IO uint8_t SCSVC                      : 1;
    __IO uint8_t FCS                        : 1;
} stc_clock_int_clr_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 8;
    __IO uint16_t SEL01                     : 4;
    __IO uint16_t SEL23                     : 4;
} stc_ctiosel03_ctsel0123_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 8;
    __IO uint16_t SEL45                     : 4;
    __IO uint16_t SEL67                     : 4;
} stc_ctiosel47_ctsel4567_field_t;

typedef struct
{
    __IO uint16_t START                     : 1;
    __IO uint16_t ENCNT                     : 1;
    __IO uint16_t MODS                      : 1;
    __IO uint16_t PLRT                      : 1;
    __IO uint16_t FUNC                      : 3;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t EDGS                      : 2;
    __IO uint16_t MASK                      : 1;
    __IO uint16_t RSTEN                     : 1;
    __IO uint16_t CLKS                      : 3;
} stc_ct_ppg_tcr_field_t;

typedef struct
{
    __IO uint8_t UDFIR                      : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t TRGIR                      : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t UDFIE                      : 1;
    uint8_t RESERVED5                       : 1;
    __IO uint8_t TRGIE                      : 1;
} stc_ct_ppg_sta_field_t;

typedef struct
{
    __IO uint8_t CLKS3                      : 1;
} stc_ct_ppg_tcr2_field_t;

typedef struct
{
    uint16_t RESERVED0                      : 1;
    __IO uint16_t ENCNT                     : 1;
    __IO uint16_t MODS                      : 1;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t FUNC                      : 3;
    __IO uint16_t T32                       : 1;
    __IO uint16_t EDGS                      : 3;
    uint16_t RESERVED11                     : 1;
    __IO uint16_t CLKS                      : 3;
} stc_ct_pwc_tcr_field_t;

typedef struct
{
    __IO uint8_t OVIR                       : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t MCIR                       : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t OVIE                       : 1;
    uint8_t RESERVED5                       : 1;
    __IO uint8_t MCIE                       : 1;
    __IO uint8_t ERR                        : 1;
} stc_ct_pwc_sta_field_t;

typedef struct
{
    __IO uint8_t CLKS3                      : 1;
} stc_ct_pwc_tcr2_field_t;

typedef struct
{
    __IO uint16_t START                     : 1;
    __IO uint16_t ENCNT                     : 1;
    __IO uint16_t MODS                      : 1;
    __IO uint16_t PLRT                      : 1;
    __IO uint16_t FUNC                      : 3;
    uint16_t RESERVED7                      : 1;
    __IO uint16_t EDGS                      : 2;
    __IO uint16_t MASK                      : 1;
    __IO uint16_t RSTEN                     : 1;
    __IO uint16_t CLKS                      : 3;
} stc_ct_pwm_tcr_field_t;

typedef struct
{
    __IO uint8_t UDFIR                      : 1;
    __IO uint8_t DTMIR                      : 1;
    __IO uint8_t TRGIR                      : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t UDFIE                      : 1;
    __IO uint8_t DTMIE                      : 1;
    __IO uint8_t TRGIE                      : 1;
} stc_ct_pwm_sta_field_t;

typedef struct
{
    __IO uint8_t CLKS3                      : 1;
} stc_ct_pwm_tcr2_field_t;

typedef struct
{
    __IO uint16_t START                     : 1;
    __IO uint16_t ENCNT                     : 1;
    __IO uint16_t MODS                      : 1;
    __IO uint16_t PLRT                      : 1;
    __IO uint16_t FUNC                      : 3;
    __IO uint16_t T32                       : 1;
    __IO uint16_t EDGS                      : 2;
    uint16_t RESERVED10                     : 2;
    __IO uint16_t CLKS                      : 3;
} stc_ct_rt_tcr_field_t;

typedef struct
{
    __IO uint8_t UDFIR                      : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t TRGIR                      : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t UDFIE                      : 1;
    uint8_t RESERVED5                       : 1;
    __IO uint8_t TRGIE                      : 1;
} stc_ct_rt_sta_field_t;

typedef struct
{
    __IO uint8_t CLKS3                      : 1;
    uint8_t RESERVED1                       : 6;
    __IO uint8_t GTIE                       : 1;
} stc_ct_rt_tcr2_field_t;

typedef struct
{
    __IO uint32_t ONESHOT                   : 1;
    __IO uint32_t TMRSIZE                   : 1;
    __IO uint32_t TMRPRE                    : 2;
    uint32_t RESERVED4                      : 1;
    __IO uint32_t INTEN                     : 1;
    __IO uint32_t TMRMODE                   : 1;
    __IO uint32_t TMREN                     : 1;
} stc_dtim_timerctrl_field_t;

typedef struct
{
    __IO uint32_t TMRINTST                  : 1;
} stc_dtim_timerris_field_t;

typedef struct
{
    __IO uint32_t TMRMINTST                 : 1;
} stc_dtim_timermis_field_t;

typedef struct
{
    __IO uint32_t EN0                       : 1;
    __IO uint32_t EN1                       : 1;
    __IO uint32_t EN2                       : 1;
    __IO uint32_t EN3                       : 1;
    __IO uint32_t EN4                       : 1;
    __IO uint32_t EN5                       : 1;
    __IO uint32_t EN6                       : 1;
    __IO uint32_t EN7                       : 1;
    __IO uint32_t EN8                       : 1;
    __IO uint32_t EN9                       : 1;
    __IO uint32_t EN10                      : 1;
    __IO uint32_t EN11                      : 1;
    __IO uint32_t EN12                      : 1;
    __IO uint32_t EN13                      : 1;
    __IO uint32_t EN14                      : 1;
    __IO uint32_t EN15                      : 1;
} stc_extint_inten_field_t;

typedef struct
{
    __IO uint32_t SRC0                      : 1;
    __IO uint32_t SRC1                      : 1;
    __IO uint32_t SRC2                      : 1;
    __IO uint32_t SRC3                      : 1;
    __IO uint32_t SRC4                      : 1;
    __IO uint32_t SRC5                      : 1;
    __IO uint32_t SRC6                      : 1;
    __IO uint32_t SRC7                      : 1;
    __IO uint32_t SRC8                      : 1;
    __IO uint32_t SRC9                      : 1;
    __IO uint32_t SRC10                     : 1;
    __IO uint32_t SRC11                     : 1;
    __IO uint32_t SRC12                     : 1;
    __IO uint32_t SRC13                     : 1;
    __IO uint32_t SRC14                     : 1;
    __IO uint32_t SRC15                     : 1;
} stc_extint_intsrc_field_t;

typedef struct
{
    __IO uint32_t CLR0                      : 1;
    __IO uint32_t CLR1                      : 1;
    __IO uint32_t CLR2                      : 1;
    __IO uint32_t CLR3                      : 1;
    __IO uint32_t CLR4                      : 1;
    __IO uint32_t CLR5                      : 1;
    __IO uint32_t CLR6                      : 1;
    __IO uint32_t CLR7                      : 1;
    __IO uint32_t CLR8                      : 1;
    __IO uint32_t CLR9                      : 1;
    __IO uint32_t CLR10                     : 1;
    __IO uint32_t CLR11                     : 1;
    __IO uint32_t CLR12                     : 1;
    __IO uint32_t CLR13                     : 1;
    __IO uint32_t CLR14                     : 1;
    __IO uint32_t CLR15                     : 1;
} stc_extint_intclr_field_t;

typedef struct
{
    __IO uint32_t LVLL0                     : 1;
    __IO uint32_t LVLH0                     : 1;
    __IO uint32_t LVLL1                     : 1;
    __IO uint32_t LVLH1                     : 1;
    __IO uint32_t LVLL2                     : 1;
    __IO uint32_t LVLH2                     : 1;
    __IO uint32_t LVLL3                     : 1;
    __IO uint32_t LVLH3                     : 1;
    __IO uint32_t LVLL4                     : 1;
    __IO uint32_t LVLH4                     : 1;
    __IO uint32_t LVLL5                     : 1;
    __IO uint32_t LVLH5                     : 1;
    __IO uint32_t LVLL6                     : 1;
    __IO uint32_t LVLH6                     : 1;
    __IO uint32_t LVLL7                     : 1;
    __IO uint32_t LVLH7                     : 1;
    __IO uint32_t LVLL8                     : 1;
    __IO uint32_t LVLH8                     : 1;
    __IO uint32_t LVLL9                     : 1;
    __IO uint32_t LVLH9                     : 1;
    __IO uint32_t LVLL10                    : 1;
    __IO uint32_t LVLH10                    : 1;
    __IO uint32_t LVLL11                    : 1;
    __IO uint32_t LVLH11                    : 1;
    __IO uint32_t LVLL12                    : 1;
    __IO uint32_t LVLH12                    : 1;
    __IO uint32_t LVLL13                    : 1;
    __IO uint32_t LVLH13                    : 1;
    __IO uint32_t LVLL14                    : 1;
    __IO uint32_t LVLH14                    : 1;
    __IO uint32_t LVLL15                    : 1;
    __IO uint32_t LVLH15                    : 1;
} stc_extint_intlvl_field_t;

typedef struct
{
    __IO uint16_t SRC                       : 1;
} stc_extint_nmisrc_field_t;

typedef struct
{
    __IO uint16_t CLR                       : 1;
} stc_extint_nmiclr_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget0_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget1_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget2_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget3_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget4_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget5_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fget6_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
} stc_fastio_fget7_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
} stc_fastio_fget8_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset0_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset1_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset2_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset3_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset4_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset5_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
    __IO uint8_t P6                         : 1;
    __IO uint8_t P7                         : 1;
} stc_fastio_fset6_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
    __IO uint8_t P1                         : 1;
    __IO uint8_t P2                         : 1;
    __IO uint8_t P3                         : 1;
    __IO uint8_t P4                         : 1;
    __IO uint8_t P5                         : 1;
} stc_fastio_fset7_field_t;

typedef struct
{
    __IO uint8_t P0                         : 1;
} stc_fastio_fset8_field_t;

typedef struct
{
    __IO uint32_t PRGM                      : 1;
    __IO uint32_t PERS                      : 1;
    __IO uint32_t CERS                      : 1;
    __IO uint32_t DPSTB                     : 1;
    uint32_t RESERVED4                      :12;
    __IO uint32_t FRWPW                     :16;
} stc_flash_focr_field_t;

typedef struct
{
    __IO uint32_t LOCK2K                    :32;
} stc_flash_flcr0_field_t;

typedef struct
{
    __IO uint32_t LOCK2K                    :32;
} stc_flash_flcr1_field_t;

typedef struct
{
    __IO uint32_t BUSY                      : 1;
    __IO uint32_t KEYVIO                    : 1;
    __IO uint32_t ACCVIO                    : 1;
    __IO uint32_t ERR                       : 1;
    __IO uint32_t OPVIO                     : 1;
    __IO uint32_t CFM                       : 1;
    uint32_t RESERVED6                      :10;
    __IO uint32_t FRWPW                     :16;
} stc_flash_fstr_field_t;

typedef struct
{
    __IO uint32_t FIE                       : 1;
    uint32_t RESERVED1                      : 3;
    __IO uint32_t FWTC                      : 2;
} stc_flash_fwcicr_field_t;

typedef struct
{
    __IO uint32_t UD0                       :32;
} stc_flash_fudr0_field_t;

typedef struct
{
    __IO uint32_t UD1                       :32;
} stc_flash_fudr1_field_t;

typedef struct
{
    __IO uint32_t UD2                       :32;
} stc_flash_fudr2_field_t;

typedef struct
{
    __IO uint32_t UD3                       :32;
} stc_flash_fudr3_field_t;

typedef struct
{
    __IO uint8_t TNVS                       : 8;
} stc_flash_tnvs_field_t;

typedef struct
{
    __IO uint8_t TPROG                      : 8;
} stc_flash_tprog_field_t;

typedef struct
{
    __IO uint8_t TPGS                       : 8;
} stc_flash_tpgs_field_t;

typedef struct
{
    __IO uint8_t TRCVPGM                    : 8;
} stc_flash_trcvpgm_field_t;

typedef struct
{
    __IO uint8_t TRCVPERS                   : 8;
} stc_flash_trcvpers_field_t;

typedef struct
{
    __IO uint8_t TRCVCERS                   : 8;
} stc_flash_trcvcers_field_t;

typedef struct
{
    __IO uint8_t TPERS                      : 8;
} stc_flash_tpers_field_t;

typedef struct
{
    __IO uint8_t TCERS                      : 8;
} stc_flash_tcers_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_fn0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_fn1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_fn2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_fn3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_fn4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_fn5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_fn6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_fn7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_fn8_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_pu0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_pu1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_pu2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_pu3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_pu4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_pu5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_pu6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_pu7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_pu8_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_dir0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_dir1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_dir2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_dir3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_dir4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_dir5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_dir6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_dir7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_dir8_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_get0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_get1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_get2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_get3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_get4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_get5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_get6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_get7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_get8_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_set0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_set1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_set2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_set3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_set4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_set5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_set6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_set7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_set8_field_t;

typedef struct
{
    __IO uint16_t ADE00                     : 1;
    __IO uint16_t ADE01                     : 1;
    __IO uint16_t ADE02                     : 1;
    __IO uint16_t ADE03                     : 1;
    __IO uint16_t ADE04                     : 1;
    __IO uint16_t ADE05                     : 1;
    __IO uint16_t ADE06                     : 1;
    __IO uint16_t ADE07                     : 1;
    __IO uint16_t ADE08                     : 1;
    __IO uint16_t ADE09                     : 1;
    __IO uint16_t ADE10                     : 1;
    __IO uint16_t ADE11                     : 1;
    __IO uint16_t ADE12                     : 1;
    __IO uint16_t ADE13                     : 1;
    __IO uint16_t ADE14                     : 1;
    __IO uint16_t ADE15                     : 1;
} stc_gpio_analog_field_t;

typedef struct
{
    __IO uint8_t SUBCS                      : 2;
    __IO uint8_t MAINCS                     : 2;
} stc_gpio_sps_field_t;

typedef struct
{
    __IO uint16_t NMIS                      : 1;
    __IO uint16_t CROUTE                    : 2;
    uint16_t RESERVED3                      : 1;
    __IO uint16_t RTCCOE                    : 2;
    __IO uint16_t SUBOUTE                   : 2;
    __IO uint16_t SWDEN                     : 1;
} stc_gpio_fn_sel00_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t TIOA0E                    : 2;
    __IO uint32_t TIOB0S                    : 3;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t TIOA1S                    : 2;
    __IO uint32_t TIOA1E                    : 2;
    __IO uint32_t TIOB1S                    : 2;
    uint32_t RESERVED14                     : 4;
    __IO uint32_t TIOA2E                    : 2;
    __IO uint32_t TIOB2S                    : 3;
    uint32_t RESERVED23                     : 1;
    __IO uint32_t TIOA3S                    : 2;
    __IO uint32_t TIOA3E                    : 2;
    __IO uint32_t TIOB3S                    : 2;
} stc_gpio_fn_sel02_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 2;
    __IO uint32_t TIOA4E                    : 2;
    __IO uint32_t TIOB4S                    : 2;
    uint32_t RESERVED6                      : 2;
    __IO uint32_t TIOA5S                    : 2;
    __IO uint32_t TIOA5E                    : 2;
    __IO uint32_t TIOB5S                    : 2;
    uint32_t RESERVED14                     : 4;
    __IO uint32_t TIOA6E                    : 2;
    __IO uint32_t TIOB6S                    : 2;
    uint32_t RESERVED22                     : 2;
    __IO uint32_t TIOA7S                    : 2;
    __IO uint32_t TIOA7E                    : 2;
    __IO uint32_t TIOB7S                    : 2;
} stc_gpio_fn_sel03_field_t;

typedef struct
{
    __IO uint32_t EINT00S                   : 2;
    __IO uint32_t EINT01S                   : 2;
    __IO uint32_t EINT02S                   : 2;
    __IO uint32_t EINT03S                   : 2;
    __IO uint32_t EINT04S                   : 2;
    __IO uint32_t EINT05S                   : 2;
    __IO uint32_t EINT06S                   : 2;
    __IO uint32_t EINT07S                   : 2;
    __IO uint32_t EINT08S                   : 2;
    __IO uint32_t EINT09S                   : 2;
    __IO uint32_t EINT10S                   : 2;
    __IO uint32_t EINT11S                   : 2;
    __IO uint32_t EINT12S                   : 2;
    __IO uint32_t EINT13S                   : 2;
    __IO uint32_t EINT14S                   : 2;
    __IO uint32_t EINT15S                   : 2;
} stc_gpio_fn_sel04_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t SIN0S                     : 2;
    __IO uint32_t SOT0B                     : 2;
    __IO uint32_t SCK0B                     : 2;
    uint32_t RESERVED10                     : 6;
    __IO uint32_t RTS1E                     : 2;
    __IO uint32_t CTS1S                     : 2;
    __IO uint32_t SIN1S                     : 2;
    __IO uint32_t SOT1B                     : 2;
    __IO uint32_t SCK1B                     : 2;
    __IO uint32_t SCS10B                    : 2;
} stc_gpio_fn_sel05_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t SIN2S                     : 2;
    __IO uint32_t SOT2B                     : 2;
    __IO uint32_t SCK2B                     : 2;
    __IO uint32_t SCS20B                    : 2;
    __IO uint32_t SCS21E                    : 2;
    __IO uint32_t SCS22E                    : 2;
} stc_gpio_fn_sel06_field_t;

typedef struct
{
    __IO uint32_t RTS4E                     : 2;
    __IO uint32_t CTS4S                     : 2;
    __IO uint32_t SIN4S                     : 2;
    __IO uint32_t SOT4B                     : 2;
    __IO uint32_t SCK4B                     : 2;
    __IO uint32_t SCS40B                    : 2;
    __IO uint32_t SCS41E                    : 2;
    uint32_t RESERVED14                     : 6;
    __IO uint32_t SIN5S                     : 2;
    __IO uint32_t SOT5B                     : 2;
    __IO uint32_t SCK5B                     : 2;
    __IO uint32_t SCS50B                    : 2;
} stc_gpio_fn_sel07_field_t;

typedef struct
{
    __IO uint32_t RTS6E                     : 2;
    __IO uint32_t CTS6S                     : 2;
    __IO uint32_t SIN6S                     : 2;
    __IO uint32_t SOT6B                     : 2;
    __IO uint32_t SCK6B                     : 2;
    __IO uint32_t SCS60B                    : 2;
    __IO uint32_t SCS61E                    : 2;
    __IO uint32_t SCS62E                    : 2;
} stc_gpio_fn_sel08_field_t;

typedef struct
{
    __IO uint16_t VCOE                      : 2;
    uint16_t RESERVED2                      : 2;
    __IO uint16_t BZOE                      : 2;
    uint16_t RESERVED6                      : 2;
    __IO uint16_t ICCKE                     : 2;
    __IO uint16_t ICIOB                     : 2;
    __IO uint16_t ICRSTE                    : 2;
} stc_gpio_fn_sel09_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_odr0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_odr1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_odr2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_odr3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_odr4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_odr5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_odr6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_odr7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_odr8_field_t;

typedef struct
{
    __IO uint8_t LVDIE                      : 1;
} stc_gpio_lvdie_field_t;

typedef struct
{
    __IO uint8_t P00                        : 1;
    __IO uint8_t P01                        : 1;
    __IO uint8_t P02                        : 1;
    __IO uint8_t P03                        : 1;
    __IO uint8_t P04                        : 1;
    __IO uint8_t P05                        : 1;
    __IO uint8_t P06                        : 1;
    __IO uint8_t P07                        : 1;
} stc_gpio_fsete0_field_t;

typedef struct
{
    __IO uint8_t P10                        : 1;
    __IO uint8_t P11                        : 1;
    __IO uint8_t P12                        : 1;
    __IO uint8_t P13                        : 1;
    __IO uint8_t P14                        : 1;
    __IO uint8_t P15                        : 1;
    __IO uint8_t P16                        : 1;
    __IO uint8_t P17                        : 1;
} stc_gpio_fsete1_field_t;

typedef struct
{
    __IO uint8_t P20                        : 1;
    __IO uint8_t P21                        : 1;
    __IO uint8_t P22                        : 1;
    __IO uint8_t P23                        : 1;
    __IO uint8_t P24                        : 1;
    __IO uint8_t P25                        : 1;
    __IO uint8_t P26                        : 1;
    __IO uint8_t P27                        : 1;
} stc_gpio_fsete2_field_t;

typedef struct
{
    __IO uint8_t P30                        : 1;
    __IO uint8_t P31                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t P34                        : 1;
    __IO uint8_t P35                        : 1;
    __IO uint8_t P36                        : 1;
    __IO uint8_t P37                        : 1;
} stc_gpio_fsete3_field_t;

typedef struct
{
    __IO uint8_t P40                        : 1;
    __IO uint8_t P41                        : 1;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t P45                        : 1;
    __IO uint8_t P46                        : 1;
    __IO uint8_t P47                        : 1;
} stc_gpio_fsete4_field_t;

typedef struct
{
    __IO uint8_t P50                        : 1;
    __IO uint8_t P51                        : 1;
    __IO uint8_t P52                        : 1;
    __IO uint8_t P53                        : 1;
    __IO uint8_t P54                        : 1;
    __IO uint8_t P55                        : 1;
    __IO uint8_t P56                        : 1;
    __IO uint8_t P57                        : 1;
} stc_gpio_fsete5_field_t;

typedef struct
{
    __IO uint8_t P60                        : 1;
    __IO uint8_t P61                        : 1;
    __IO uint8_t P62                        : 1;
    __IO uint8_t P63                        : 1;
    __IO uint8_t P64                        : 1;
    __IO uint8_t P65                        : 1;
    __IO uint8_t P66                        : 1;
    __IO uint8_t P67                        : 1;
} stc_gpio_fsete6_field_t;

typedef struct
{
    __IO uint8_t P70                        : 1;
    __IO uint8_t P71                        : 1;
    __IO uint8_t P72                        : 1;
    __IO uint8_t P73                        : 1;
    __IO uint8_t P74                        : 1;
} stc_gpio_fsete7_field_t;

typedef struct
{
    __IO uint8_t P80                        : 1;
} stc_gpio_fsete8_field_t;

typedef struct
{
    __IO uint8_t IE                         : 1;
    __IO uint8_t RSTEN                      : 1;
    __IO uint8_t CLKS                       : 1;
} stc_hwwdt_wdt_ctl_field_t;

typedef struct
{
    __IO uint8_t STA                        : 1;
} stc_hwwdt_wdt_sta_field_t;

typedef struct
{
    __IO uint32_t NMI                       : 1;
    __IO uint32_t HWWDG                     : 1;
} stc_irqc_irq_st02_field_t;

typedef struct
{
    __IO uint32_t AFDI                      : 1;
    __IO uint32_t MCSV                      : 1;
    __IO uint32_t SCSV                      : 1;
} stc_irqc_irq00pend_field_t;

typedef struct
{
    __IO uint32_t SWWDG                     : 1;
} stc_irqc_irq01pend_field_t;

typedef struct
{
    __IO uint32_t LVD                       : 1;
} stc_irqc_irq02pend_field_t;

typedef struct
{
    __IO uint32_t EXTI0                     : 1;
    __IO uint32_t EXTI1                     : 1;
    __IO uint32_t EXTI2                     : 1;
    __IO uint32_t EXTI3                     : 1;
    __IO uint32_t EXTI4                     : 1;
    __IO uint32_t EXTI5                     : 1;
    __IO uint32_t EXTI6                     : 1;
    __IO uint32_t EXTI7                     : 1;
} stc_irqc_irq04pend_field_t;

typedef struct
{
    __IO uint32_t EXTI8                     : 1;
    __IO uint32_t EXTI9                     : 1;
    __IO uint32_t EXTI10                    : 1;
    __IO uint32_t EXTI11                    : 1;
    __IO uint32_t EXTI12                    : 1;
    __IO uint32_t EXTI13                    : 1;
    __IO uint32_t EXTI14                    : 1;
    __IO uint32_t EXTI15                    : 1;
} stc_irqc_irq05pend_field_t;

typedef struct
{
    __IO uint32_t DTI1                      : 1;
    __IO uint32_t DTI2                      : 1;
} stc_irqc_irq06pend_field_t;

typedef struct
{
    __IO uint32_t MSC0INT                   : 1;
} stc_irqc_irq07pend_field_t;

typedef struct
{
    __IO uint32_t MSC0INT0                  : 1;
    __IO uint32_t MSC0INT1                  : 1;
} stc_irqc_irq08pend_field_t;

typedef struct
{
    __IO uint32_t MSC1INT                   : 1;
} stc_irqc_irq09pend_field_t;

typedef struct
{
    __IO uint32_t MSC1INT0                  : 1;
    __IO uint32_t MSC1INT1                  : 1;
} stc_irqc_irq10pend_field_t;

typedef struct
{
    __IO uint32_t MSC2INT                   : 1;
} stc_irqc_irq11pend_field_t;

typedef struct
{
    __IO uint32_t MSC2INT0                  : 1;
    __IO uint32_t MSC2INT1                  : 1;
} stc_irqc_irq12pend_field_t;

typedef struct
{
    __IO uint32_t MSC4INT                   : 1;
} stc_irqc_irq15pend_field_t;

typedef struct
{
    __IO uint32_t MSC4INT0                  : 1;
    __IO uint32_t MSC4INT1                  : 1;
} stc_irqc_irq16pend_field_t;

typedef struct
{
    __IO uint32_t MSC5INT                   : 1;
} stc_irqc_irq17pend_field_t;

typedef struct
{
    __IO uint32_t MSC5INT0                  : 1;
    __IO uint32_t MSC5INT1                  : 1;
} stc_irqc_irq18pend_field_t;

typedef struct
{
    __IO uint32_t MSC6INT                   : 1;
} stc_irqc_irq19pend_field_t;

typedef struct
{
    __IO uint32_t MSC6INT0                  : 1;
    __IO uint32_t MSC6INT1                  : 1;
} stc_irqc_irq20pend_field_t;

typedef struct
{
    __IO uint32_t MOSCI                     : 1;
    __IO uint32_t SOSCI                     : 1;
    uint32_t RESERVED2                      : 3;
    __IO uint32_t RTCI                      : 1;
    uint32_t RESERVED6                      : 1;
    __IO uint32_t RAMI                      : 1;
} stc_irqc_irq24pend_field_t;

typedef struct
{
    __IO uint32_t ADCCNVI                   : 1;
    uint32_t RESERVED1                      : 3;
    __IO uint32_t ADCCMPI                   : 1;
} stc_irqc_irq25pend_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 5;
    __IO uint32_t VCI                       : 1;
} stc_irqc_irq26pend_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 6;
    __IO uint32_t ICCI                      : 1;
} stc_irqc_irq27pend_field_t;

typedef struct
{
    __IO uint32_t CTIIRQ0CH0                : 1;
    __IO uint32_t CTIIRQ1CH0                : 1;
    __IO uint32_t CTIIRQ0CH1                : 1;
    __IO uint32_t CTIIRQ1CH1                : 1;
    __IO uint32_t CTIIRQ0CH2                : 1;
    __IO uint32_t CTIIRQ1CH2                : 1;
    __IO uint32_t CTIIRQ0CH3                : 1;
    __IO uint32_t CTIIRQ1CH3                : 1;
    __IO uint32_t CTIIRQ0CH4                : 1;
    __IO uint32_t CTIIRQ1CH4                : 1;
    __IO uint32_t CTIIRQ0CH5                : 1;
    __IO uint32_t CTIIRQ1CH5                : 1;
    __IO uint32_t CTIIRQ0CH6                : 1;
    __IO uint32_t CTIIRQ1CH6                : 1;
    __IO uint32_t CTIIRQ0CH7                : 1;
    __IO uint32_t CTIIRQ1CH7                : 1;
    uint32_t RESERVED16                     :11;
    __IO uint32_t FLASHI                    : 1;
} stc_irqc_irq31pend_field_t;

typedef struct
{
    __IO uint8_t CLKSEL                     : 1;
    __IO uint8_t LCD_FRAME                  : 2;
    __IO uint8_t BIAS                       : 2;
    __IO uint8_t LCD_MODE                   : 3;
} stc_lcdc_lcdcr0_field_t;

typedef struct
{
    __IO uint8_t VLCD                       : 3;
    __IO uint8_t CT                         : 3;
    __IO uint8_t CMOD                       : 1;
} stc_lcdc_lcdcr1_field_t;

typedef struct
{
    __IO uint8_t CP_FREQ                    : 2;
    uint8_t RESERVED2                       : 3;
    __IO uint8_t VSEL                       : 2;
    __IO uint8_t WSEL                       : 1;
} stc_lcdc_lcdcr2_field_t;

typedef struct
{
    __IO uint8_t LCD_EN                     : 1;
    uint8_t RESERVED1                       : 3;
    __IO uint8_t LCD_BUF                    : 2;
} stc_lcdc_lcdcr3_field_t;

typedef struct
{
    __IO uint8_t VE0                        : 1;
    __IO uint8_t VE1                        : 1;
    __IO uint8_t VE2                        : 1;
    __IO uint8_t VE3                        : 1;
    __IO uint8_t VE4                        : 1;
} stc_lcdc_lcddvc_field_t;

typedef struct
{
    __IO uint8_t COME0                      : 1;
    __IO uint8_t COME1                      : 1;
    __IO uint8_t COME2                      : 1;
    __IO uint8_t COME3                      : 1;
    __IO uint8_t COME4                      : 1;
    __IO uint8_t COME5                      : 1;
    __IO uint8_t COME6                      : 1;
    __IO uint8_t COME7                      : 1;
} stc_lcdc_lcdce0_field_t;

typedef struct
{
    __IO uint8_t SEGE0                      : 1;
    __IO uint8_t SEGE1                      : 1;
    __IO uint8_t SEGE2                      : 1;
    __IO uint8_t SEGE3                      : 1;
    __IO uint8_t SEGE4                      : 1;
    __IO uint8_t SEGE5                      : 1;
    __IO uint8_t SEGE6                      : 1;
    __IO uint8_t SEGE7                      : 1;
} stc_lcdc_lcdse0_field_t;

typedef struct
{
    __IO uint8_t SEGE8                      : 1;
    __IO uint8_t SEGE9                      : 1;
    __IO uint8_t SEGE10                     : 1;
    __IO uint8_t SEGE11                     : 1;
    __IO uint8_t SEGE12                     : 1;
    __IO uint8_t SEGE13                     : 1;
    __IO uint8_t SEGE14                     : 1;
    __IO uint8_t SEGE15                     : 1;
} stc_lcdc_lcdse1_field_t;

typedef struct
{
    __IO uint8_t SEGE16                     : 1;
    __IO uint8_t SEGE17                     : 1;
    __IO uint8_t SEGE18                     : 1;
    __IO uint8_t SEGE19                     : 1;
    __IO uint8_t SEGE20                     : 1;
    __IO uint8_t SEGE21                     : 1;
    __IO uint8_t SEGE22                     : 1;
    __IO uint8_t SEGE23                     : 1;
} stc_lcdc_lcdse2_field_t;

typedef struct
{
    __IO uint8_t SEGE24                     : 1;
    __IO uint8_t SEGE25                     : 1;
    __IO uint8_t SEGE26                     : 1;
    __IO uint8_t SEGE27                     : 1;
    __IO uint8_t SEGE28                     : 1;
    __IO uint8_t SEGE29                     : 1;
    __IO uint8_t SEGE30                     : 1;
    __IO uint8_t SEGE31                     : 1;
} stc_lcdc_lcdse3_field_t;

typedef struct
{
    __IO uint8_t SEGE32                     : 1;
    __IO uint8_t SEGE33                     : 1;
    __IO uint8_t SEGE34                     : 1;
    __IO uint8_t SEGE35                     : 1;
    __IO uint8_t SEGE36                     : 1;
    __IO uint8_t SEGE37                     : 1;
    __IO uint8_t SEGE38                     : 1;
    __IO uint8_t SEGE39                     : 1;
} stc_lcdc_lcdse4_field_t;

typedef struct
{
    uint8_t RESERVED0                       : 2;
    __IO uint8_t TXIE                       : 1;
    __IO uint8_t RXIE                       : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t MODE                       : 3;
} stc_msc_i2c_mr_field_t;

typedef struct
{
    __IO uint8_t INTF                       : 1;
    __IO uint8_t BERF                       : 1;
    __IO uint8_t INTE                       : 1;
    __IO uint8_t CNDDIE                     : 1;
    __IO uint8_t WTSEL                      : 1;
    __IO uint8_t ACKE                       : 1;
    __IO uint8_t OFITS                      : 1;
    __IO uint8_t MSS                        : 1;
} stc_msc_i2c_bc_field_t;

typedef struct
{
    __IO uint8_t BSS                        : 1;
    __IO uint8_t STPCC                      : 1;
    __IO uint8_t ITSCC                      : 1;
    __IO uint8_t ABL                        : 1;
    __IO uint8_t TRX                        : 1;
    __IO uint8_t RAD                        : 1;
    __IO uint8_t ACKF                       : 1;
    __IO uint8_t FBB                        : 1;
} stc_msc_i2c_bs_field_t;

typedef struct
{
    __IO uint8_t TBIF                       : 1;
    __IO uint8_t TDEF                       : 1;
    __IO uint8_t RDFF                       : 1;
    __IO uint8_t ORF                        : 1;
    __IO uint8_t TBIIE                      : 1;
    uint8_t RESERVED5                       : 1;
    __IO uint8_t TEFS                       : 1;
    __IO uint8_t RECLR                      : 1;
} stc_msc_i2c_sr_field_t;

typedef struct
{
    __IO uint16_t BRS                       :15;
} stc_msc_i2c_brs_field_t;

typedef struct
{
    __IO uint8_t ADDR                       : 7;
    __IO uint8_t AE                         : 1;
} stc_msc_i2c_sa_field_t;

typedef struct
{
    __IO uint8_t MSK                        : 7;
    __IO uint8_t EN                         : 1;
} stc_msc_i2c_samsk_field_t;

typedef struct
{
    __IO uint8_t BEC                        : 1;
    __IO uint8_t DOE                        : 1;
    __IO uint8_t SCLOC                      : 1;
    __IO uint8_t SDAOC                      : 1;
    __IO uint8_t SCLS                       : 1;
    __IO uint8_t SDAS                       : 1;
} stc_msc_i2c_ebcr_field_t;

typedef struct
{
    __IO uint8_t DOE                        : 1;
    __IO uint8_t CKE                        : 1;
    __IO uint8_t TDS                        : 1;
    __IO uint8_t CINV                       : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t MODE                       : 3;
} stc_msc_spi_mr_field_t;

typedef struct
{
    __IO uint8_t TXE                        : 1;
    __IO uint8_t RXE                        : 1;
    __IO uint8_t TBIE                       : 1;
    __IO uint8_t TXIE                       : 1;
    __IO uint8_t RXIE                       : 1;
    __IO uint8_t SPIMODE                    : 1;
    __IO uint8_t MSS                        : 1;
    __IO uint8_t PCL                        : 1;
} stc_msc_spi_cr_field_t;

typedef struct
{
    __IO uint8_t DL                         : 3;
    __IO uint8_t DTRWS                      : 2;
    __IO uint8_t CSFE                       : 1;
    __IO uint8_t DL3                        : 1;
    __IO uint8_t SOPS                       : 1;
} stc_msc_spi_ecr_field_t;

typedef struct
{
    __IO uint8_t TBIF                       : 1;
    __IO uint8_t TDEF                       : 1;
    __IO uint8_t RDFF                       : 1;
    __IO uint8_t ORF                        : 1;
    uint8_t RESERVED4                       : 3;
    __IO uint8_t RECLR                      : 1;
} stc_msc_spi_sr_field_t;

typedef struct
{
    __IO uint16_t BRS                       :15;
} stc_msc_spi_brs_field_t;

typedef struct
{
    __IO uint8_t CSHDLY                     : 8;
} stc_msc_spi_cstmg0_field_t;

typedef struct
{
    __IO uint8_t CSSDLY                     : 8;
} stc_msc_spi_cstmg1_field_t;

typedef struct
{
    __IO uint16_t CSDS                      :16;
} stc_msc_spi_cstmg32_field_t;

typedef struct
{
    __IO uint16_t TMRE                      : 1;
    __IO uint16_t CLKDIV                    : 4;
    uint16_t RESERVED5                      : 1;
    __IO uint16_t SYNTE                     : 1;
    __IO uint16_t TIE                       : 1;
    __IO uint16_t TIF                       : 1;
    uint16_t RESERVED9                      : 2;
    __IO uint16_t CSER                      : 1;
    __IO uint16_t CSEIE                     : 1;
    __IO uint16_t TBEE                      : 1;
} stc_msc_spi_eacr_field_t;

typedef struct
{
    __IO uint16_t TMR                       :16;
} stc_msc_spi_tmr_field_t;

typedef struct
{
    __IO uint16_t TMC                       :16;
} stc_msc_spi_tmc_field_t;

typedef struct
{
    __IO uint16_t CSOE                      : 1;
    __IO uint16_t CSEN0                     : 1;
    __IO uint16_t CSEN1                     : 1;
    __IO uint16_t CSEN2                     : 1;
    __IO uint16_t CSEN3                     : 1;
    __IO uint16_t CSLVS                     : 1;
    __IO uint16_t CSTODIV                   : 3;
    __IO uint16_t CSAH                      : 1;
    __IO uint16_t CSAD                      : 2;
    __IO uint16_t CSAE                      : 2;
    __IO uint16_t CSAS                      : 2;
} stc_msc_spi_cscr_field_t;

typedef struct
{
    __IO uint8_t CS1DL                      : 4;
    __IO uint8_t CS1TDS                     : 1;
    __IO uint8_t CS1SPI                     : 1;
    __IO uint8_t CS1CINV                    : 1;
    __IO uint8_t CS1CSLVS                   : 1;
} stc_msc_spi_csfr0_field_t;

typedef struct
{
    __IO uint8_t CS2DL                      : 4;
    __IO uint8_t CS2TDS                     : 1;
    __IO uint8_t CS2SPI                     : 1;
    __IO uint8_t CS2CINV                    : 1;
    __IO uint8_t CS2CSLVS                   : 1;
} stc_msc_spi_csfr1_field_t;

typedef struct
{
    __IO uint8_t CS3DL                      : 4;
    __IO uint8_t CS3TDS                     : 1;
    __IO uint8_t CS3SPI                     : 1;
    __IO uint8_t CS3CINV                    : 1;
    __IO uint8_t CS3CSLVS                   : 1;
} stc_msc_spi_csfr2_field_t;

typedef struct
{
    __IO uint8_t DOE                        : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t TDS                        : 1;
    __IO uint8_t SBLS                       : 1;
    uint8_t RESERVED4                       : 1;
    __IO uint8_t MODE                       : 3;
} stc_msc_uart_mr_field_t;

typedef struct
{
    __IO uint8_t TXE                        : 1;
    __IO uint8_t RXE                        : 1;
    __IO uint8_t TBIE                       : 1;
    __IO uint8_t TXIE                       : 1;
    __IO uint8_t RXIE                       : 1;
    uint8_t RESERVED5                       : 2;
    __IO uint8_t PCL                        : 1;
} stc_msc_uart_cr_field_t;

typedef struct
{
    __IO uint8_t DL                         : 3;
    __IO uint8_t PS                         : 1;
    __IO uint8_t PE                         : 1;
    __IO uint8_t INV                        : 1;
    __IO uint8_t ESBLS                      : 1;
    __IO uint8_t FCEB                       : 1;
} stc_msc_uart_ecr_field_t;

typedef struct
{
    __IO uint8_t TBIF                       : 1;
    __IO uint8_t TDEF                       : 1;
    __IO uint8_t RDFF                       : 1;
    __IO uint8_t ORF                        : 1;
    __IO uint8_t FEF                        : 1;
    __IO uint8_t PEF                        : 1;
    uint8_t RESERVED6                       : 1;
    __IO uint8_t RECLR                      : 1;
} stc_msc_uart_sr_field_t;

typedef struct
{
    __IO uint16_t BRS                       :15;
    __IO uint16_t EXT                       : 1;
} stc_msc_uart_brs_field_t;

typedef struct
{
    __IO uint16_t COMP                      :10;
    uint16_t RESERVED10                     : 5;
    __IO uint16_t CEN                       : 1;
} stc_msc_uart_comp_field_t;

typedef struct
{
    __IO uint32_t TRMKEY                    :32;
} stc_osc_hicr_trmkey_field_t;

typedef struct
{
    __IO uint32_t CR4MFTRM                  : 9;
    uint32_t RESERVED9                      : 7;
    __IO uint32_t CR16MFTRM                 : 9;
} stc_osc_hicr_ftrm_field_t;

typedef struct
{
    __IO uint32_t CR4MTTRM                  : 4;
    uint32_t RESERVED4                      :12;
    __IO uint32_t CR16MTTRM                 : 4;
} stc_osc_hicr_ttrm_field_t;

typedef struct
{
    __IO uint8_t FMC                        : 2;
} stc_osc_hicr_fmc_field_t;

typedef struct
{
    __IO uint8_t CSR                        : 3;
} stc_osc_hicr_csr_field_t;

typedef struct
{
    __IO uint32_t HXSEL                     : 2;
    uint32_t RESERVED2                      :14;
    __IO uint32_t HIBS                      : 2;
} stc_osc_hsxt_pwrctl_field_t;

typedef struct
{
    __IO uint32_t LCSEL                     : 2;
    uint32_t RESERVED2                      :14;
    __IO uint32_t LIBS                      : 2;
} stc_osc_lsxt_pwrctl_field_t;

typedef struct
{
    __IO uint8_t PE                         : 1;
    __IO uint8_t PIE                        : 1;
    uint8_t RESERVED2                       : 2;
    __IO uint8_t PERROR                     : 1;
} stc_parity_ctl_field_t;

typedef struct
{
    __IO uint32_t ADDR                      :32;
} stc_parity_addr_field_t;

typedef struct
{
    __IO uint32_t MSCCLK0                   : 1;
    __IO uint32_t MSCCLK1                   : 1;
    __IO uint32_t MSCCLK2                   : 1;
    __IO uint32_t MSCCLK4                   : 1;
    __IO uint32_t MSCCLK5                   : 1;
    __IO uint32_t MSCCLK6                   : 1;
    uint32_t RESERVED6                      :10;
    __IO uint32_t ADCCLK                    : 1;
    uint32_t RESERVED17                     :11;
    __IO uint32_t GIOCLK                    : 1;
} stc_pcg_clken0_field_t;

typedef struct
{
    __IO uint32_t MSCRST0                   : 1;
    __IO uint32_t MSCRST1                   : 1;
    __IO uint32_t MSCRST2                   : 1;
    __IO uint32_t MSCRST4                   : 1;
    __IO uint32_t MSCRST5                   : 1;
    __IO uint32_t MSCRST6                   : 1;
    uint32_t RESERVED6                      :10;
    __IO uint32_t ADCRST                    : 1;
} stc_pcg_rstctl0_field_t;

typedef struct
{
    __IO uint32_t CTMCLK0123                : 1;
    __IO uint32_t CTMCLK4567                : 1;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t VCCLK                     : 1;
} stc_pcg_clken1_field_t;

typedef struct
{
    __IO uint32_t CTMRST0123                : 1;
    __IO uint32_t CTMRST4567                : 1;
    uint32_t RESERVED2                      : 2;
    __IO uint32_t VCRST                     : 1;
} stc_pcg_rstctl1_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t BUZCLK                    : 1;
    uint32_t RESERVED5                      : 3;
    __IO uint32_t AESCLK                    : 1;
    uint32_t RESERVED9                      : 3;
    __IO uint32_t SCICLK                    : 1;
    uint32_t RESERVED13                     : 3;
    __IO uint32_t LCDCCLK                   : 1;
} stc_pcg_clken2_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 4;
    __IO uint32_t BUZRST                    : 1;
    uint32_t RESERVED5                      : 3;
    __IO uint32_t AESRST                    : 1;
    uint32_t RESERVED9                      : 3;
    __IO uint32_t SCIRST                    : 1;
    uint32_t RESERVED13                     : 3;
    __IO uint32_t LCDCRST                   : 1;
} stc_pcg_rstctl2_field_t;

typedef struct
{
    __IO uint32_t ST                        : 1;
    uint32_t RESERVED1                      : 1;
    __IO uint32_t STAT                      : 1;
    __IO uint32_t SWRST                     : 1;
    __IO uint32_t SENSP                     : 1;
    __IO uint32_t SENRST                    : 1;
    __IO uint32_t BUSY                      : 1;
    uint32_t RESERVED7                      : 1;
    __IO uint32_t SENE                      : 1;
    __IO uint32_t MINE                      : 1;
    __IO uint32_t HOUE                      : 1;
    __IO uint32_t DAYE                      : 1;
    __IO uint32_t MONE                      : 1;
    __IO uint32_t YEAE                      : 1;
    uint32_t RESERVED14                     : 2;
    __IO uint32_t INTSSF                    : 1;
    __IO uint32_t INTSF                     : 1;
    __IO uint32_t INTMF                     : 1;
    __IO uint32_t INTHF                     : 1;
    __IO uint32_t INTTMF                    : 1;
    __IO uint32_t INTALF                    : 1;
    __IO uint32_t INTERF                    : 1;
    __IO uint32_t INTCRF                    : 1;
    __IO uint32_t INTSSIEN                  : 1;
    __IO uint32_t INTSIEN                   : 1;
    __IO uint32_t INTMIEN                   : 1;
    __IO uint32_t INTHIEN                   : 1;
    __IO uint32_t INTTMIEN                  : 1;
    __IO uint32_t INTALIEN                  : 1;
    __IO uint32_t INTERIEN                  : 1;
    __IO uint32_t INTCRIEN                  : 1;
} stc_rtc_rtcctl1_field_t;

typedef struct
{
    __IO uint32_t RCTRL                     : 1;
    uint32_t RESERVED1                      : 7;
    __IO uint32_t TCST                      : 1;
    __IO uint32_t TCEN                      : 1;
    __IO uint32_t TCRUN                     : 1;
} stc_rtc_rtcctl2_field_t;

typedef struct
{
    __IO uint32_t CC                        :24;
} stc_rtc_ccs_field_t;

typedef struct
{
    __IO uint8_t LS                         : 4;
    __IO uint8_t HS                         : 3;
} stc_rtc_sen_field_t;

typedef struct
{
    __IO uint8_t LM                         : 4;
    __IO uint8_t HM                         : 3;
} stc_rtc_min_field_t;

typedef struct
{
    __IO uint8_t LH                         : 4;
    __IO uint8_t HH                         : 2;
} stc_rtc_hour_field_t;

typedef struct
{
    __IO uint8_t LD                         : 4;
    __IO uint8_t HD                         : 2;
} stc_rtc_date_field_t;

typedef struct
{
    __IO uint8_t WK                         : 3;
} stc_rtc_week_field_t;

typedef struct
{
    __IO uint8_t LMON                       : 4;
    __IO uint8_t HMON                       : 1;
} stc_rtc_mon_field_t;

typedef struct
{
    __IO uint8_t LY                         : 4;
    __IO uint8_t HY                         : 4;
} stc_rtc_year_field_t;

typedef struct
{
    __IO uint8_t LS                         : 4;
    __IO uint8_t HS                         : 3;
} stc_rtc_asen_field_t;

typedef struct
{
    __IO uint8_t LM                         : 4;
    __IO uint8_t HM                         : 3;
} stc_rtc_amin_field_t;

typedef struct
{
    __IO uint8_t LH                         : 4;
    __IO uint8_t HH                         : 2;
} stc_rtc_ahour_field_t;

typedef struct
{
    __IO uint8_t LD                         : 4;
    __IO uint8_t HD                         : 2;
} stc_rtc_adate_field_t;

typedef struct
{
    __IO uint8_t LMON                       : 4;
    __IO uint8_t HMON                       : 1;
} stc_rtc_amon_field_t;

typedef struct
{
    __IO uint8_t LY                         : 4;
    __IO uint8_t HY                         : 4;
} stc_rtc_ayear_field_t;

typedef struct
{
    __IO uint32_t VAL                       :18;
} stc_rtc_tval_field_t;

typedef struct
{
    __IO uint8_t SCLKI                      : 1;
} stc_rtc_sclki_field_t;

typedef struct
{
    __IO uint8_t SCLKS                      : 2;
} stc_rtc_sclks_field_t;

typedef struct
{
    __IO uint16_t CALVAL                    :10;
} stc_rtc_calval_field_t;

typedef struct
{
    __IO uint8_t CALEN                      : 1;
} stc_rtc_calen_field_t;

typedef struct
{
    __IO uint8_t DIVX                       : 4;
} stc_rtc_clkdivx_field_t;

typedef struct
{
    __IO uint8_t DIVEN                      : 1;
    __IO uint8_t DIVRDY                     : 1;
} stc_rtc_clkdivc_field_t;

typedef struct
{
    __IO uint16_t CALCYC                    : 9;
} stc_rtc_calcyc_field_t;

typedef struct
{
    __IO uint8_t CODIV2                     : 1;
} stc_rtc_rtcodiv_field_t;

typedef struct
{
    __IO uint16_t SSSR0                     : 1;
    __IO uint16_t SSSR1                     : 1;
    __IO uint16_t SSSR2                     : 1;
    __IO uint16_t SSSR3                     : 1;
    __IO uint16_t SSSR4                     : 1;
    __IO uint16_t SSSR5                     : 1;
    __IO uint16_t SSSR6                     : 1;
    __IO uint16_t SSSR7                     : 1;
} stc_sbssr_ctsssr_field_t;

typedef struct
{
    __IO uint8_t EN                         : 1;
    __IO uint8_t FL_EN                      : 1;
    __IO uint8_t PARITY_CHECK_EN            : 1;
    __IO uint8_t RETRY_EN                   : 1;
    __IO uint8_t EDC_EN                     : 1;
    __IO uint8_t ETU_CNT_EN                 : 1;
    __IO uint8_t RX_FIFO_CLR                : 1;
    __IO uint8_t TX_FIFO_CLR                : 1;
} stc_sci_con_field_t;

typedef struct
{
    __IO uint8_t T_MODE                     : 1;
    __IO uint8_t PARITY                     : 1;
    __IO uint8_t CDCVT                      : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t EDC_MODE                   : 1;
    __IO uint8_t RETRY_TIMES                : 3;
} stc_sci_mode_field_t;

typedef struct
{
    __IO uint8_t RX_FIN                     : 1;
    __IO uint8_t RX_ERR                     : 1;
    __IO uint8_t TX_FIN                     : 1;
    __IO uint8_t TX_ERR                     : 1;
    __IO uint8_t ETU_CNT_FIN                : 1;
    __IO uint8_t STAT                       : 1;
    __IO uint8_t RX_OVR                     : 1;
    __IO uint8_t RX_NE                      : 1;
} stc_sci_status_field_t;

typedef struct
{
    __IO uint8_t RX_EPTB                    : 1;
    __IO uint8_t RX_FUL                     : 1;
    __IO uint8_t RX_UDR                     : 1;
    __IO uint8_t RX_OVR                     : 1;
    __IO uint8_t TX_EPTB                    : 1;
    __IO uint8_t TX_FUL                     : 1;
    __IO uint8_t TX_UDR                     : 1;
    __IO uint8_t TX_EPT                     : 1;
} stc_sci_fifo_status_field_t;

typedef struct
{
    __IO uint8_t RX_FIFO_DEPTH              : 4;
    __IO uint8_t TX_FIFO_DEPTH              : 4;
} stc_sci_fifo_depth_field_t;

typedef struct
{
    __IO uint8_t DATA                       : 8;
} stc_sci_data_field_t;

typedef struct
{
    __IO uint16_t EDC_DATA                  :16;
} stc_sci_edc_data_field_t;

typedef struct
{
    __IO uint16_t SBDR                      :14;
    __IO uint16_t ETU_SEL                   : 2;
} stc_sci_sbdr_field_t;

typedef struct
{
    __IO uint16_t ETU_CNT                   :16;
} stc_sci_etu_cnt_field_t;

typedef struct
{
    __IO uint8_t FL_NUM                     : 3;
} stc_sci_f1_num_field_t;

typedef struct
{
    __IO uint8_t RESET_EN                   : 1;
    __IO uint8_t RESET                      : 1;
    __IO uint8_t CLK_EN                     : 1;
    __IO uint8_t CLK_SEL                    : 2;
} stc_sci_clk_rst_field_t;

typedef struct
{
    __IO uint8_t WAKEUP_INT_EN              : 1;
    __IO uint8_t ETU_CNT_INT_EN             : 1;
    __IO uint8_t INT_EN                     : 1;
} stc_sci_int_en_field_t;

typedef struct
{
    __IO uint8_t WAKEUP_INT                 : 1;
} stc_sci_wakeup_int_field_t;

typedef struct
{
    __IO uint8_t IE                         : 1;
    __IO uint8_t RSTEN                      : 1;
    __IO uint8_t TMWD                       : 2;
    __IO uint8_t WDM                        : 1;
} stc_swwdt_wdt_ctl_field_t;

typedef struct
{
    __IO uint8_t STA                        : 1;
} stc_swwdt_wdt_sta_field_t;

typedef struct
{
    __IO uint8_t TRG                        : 1;
} stc_swwdt_wdt_mdc_field_t;

typedef struct
{
    __IO uint32_t UID                       :32;
} stc_uid_uidr0_field_t;

typedef struct
{
    __IO uint32_t UID                       :32;
} stc_uid_uidr1_field_t;

typedef struct
{
    __IO uint32_t UID                       :16;
} stc_uid_uidr2_field_t;

typedef struct
{
    __IO uint16_t VC_EN                     : 1;
    __IO uint16_t VC_OUT                    : 1;
    __IO uint16_t VC_NMODE                  : 2;
    __IO uint16_t VC_PMODE                  : 2;
    uint16_t RESERVED6                      : 2;
    __IO uint16_t VCVOL_SEL                 : 6;
    __IO uint16_t VCDIV_EN                  : 1;
    __IO uint16_t VCDIV_SEL                 : 1;
} stc_vc_ctl1_field_t;

typedef struct
{
    __IO uint16_t VC_FILTER_EN              : 1;
    __IO uint16_t VC_RESPONSE               : 3;
    __IO uint16_t VC_EXBUF                  : 1;
    __IO uint16_t VCINT_FALLING             : 1;
    __IO uint16_t VCINT_RISING              : 1;
    __IO uint16_t VCINT_HIGH                : 1;
    __IO uint16_t VC2PT                     : 1;
    __IO uint16_t VCIE                      : 1;
    __IO uint16_t VCIF                      : 1;
    __IO uint16_t VC_HYS_SEL                : 2;
} stc_vc_ctl2_field_t;

typedef struct
{
    __IO uint8_t VC_TM0G                    : 1;
    uint8_t RESERVED1                       : 1;
    __IO uint8_t VC_TM2G                    : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t VCIN_NEG_SEL               : 2;
    __IO uint8_t VCIN_POS_SEL               : 2;
} stc_vc_ctl3_field_t;

typedef struct
{
    __IO uint8_t LVD_EN                     : 1;
    __IO uint8_t LVD_SRST                   : 1;
    __IO uint8_t LVD_VIN                    : 2;
    __IO uint8_t LVD_VSET                   : 4;
} stc_wsunit_lvd_ctrl1_field_t;

typedef struct
{
    __IO uint8_t LVD_HYS_EN                 : 1;
    __IO uint8_t LVD_F_EN                   : 1;
    __IO uint8_t LVD_F_SET                  : 3;
    __IO uint8_t LVD_IE                     : 2;
} stc_wsunit_lvd_ctrl2_field_t;

typedef struct
{
    __IO uint16_t LVD_IRQ                   : 1;
    uint16_t RESERVED1                      : 7;
    __IO uint16_t LVD_OUT                   : 1;
} stc_wsunit_lvd_str_field_t;

typedef struct
{
    __IO uint8_t LVD_CLR                    : 1;
} stc_wsunit_lvd_clr_field_t;

typedef struct
{
    __IO uint8_t LVD2_EN                    : 1;
    __IO uint8_t LVD2_VSET                  : 3;
    __IO uint8_t LVD2_IE                    : 1;
} stc_wsunit_lvd2_ctl_field_t;

typedef struct
{
    __IO uint16_t LVD2_IRQ                  : 1;
    uint16_t RESERVED1                      : 7;
    __IO uint16_t SENSE_STA                 : 1;
    __IO uint16_t LVD2_STA                  : 1;
} stc_wsunit_lvd2_str_field_t;

typedef struct
{
    __IO uint8_t LVD2_CLR                   : 1;
} stc_wsunit_lvd2_clr_field_t;

typedef struct
{
    uint32_t RESERVED0                      : 8;
    __IO uint32_t AUTOSWEN                  : 1;
    uint32_t RESERVED9                      : 7;
    __IO uint32_t KEY                       :16;
} stc_wsunit_ldo_ctl_field_t;

typedef struct
{
    __IO uint8_t BGR_EN                     : 1;
} stc_wsunit_bgr_ctl_field_t;

typedef struct
{
    __IO uint8_t RTCE                       : 1;
} stc_wsunit_clk_ctl1_field_t;

typedef struct
{
    __IO uint8_t RTCCKE                     : 1;
    __IO uint8_t LCDCKE                     : 1;
    __IO uint8_t WDTCKE                     : 1;
    uint8_t RESERVED3                       : 1;
    __IO uint8_t UARTCKE                    : 1;
} stc_wsunit_clk_ctl2_field_t;

typedef struct
{
    __IO uint8_t IMAINSEL                   : 2;
} stc_wsunit_mosc_ctl_field_t;

typedef struct
{
    __IO uint8_t RAMP                       : 1;
} stc_wsunit_ds_ramp_field_t;

typedef struct
{
    __IO uint8_t REINTX                     : 1;
    __IO uint8_t RELVDR                     : 1;
} stc_wsunit_wake_rsr_field_t;

typedef struct
{
    __IO uint8_t RERTCI                     : 1;
    __IO uint8_t RELVDI                     : 1;
    __IO uint8_t REWU0I                     : 1;
    __IO uint8_t REWU1I                     : 1;
    __IO uint8_t REWU2I                     : 1;
    __IO uint8_t REWU3I                     : 1;
} stc_wsunit_wake_isr_field_t;

typedef struct
{
    __IO uint8_t RERTCE                     : 1;
    __IO uint8_t RELVDE                     : 1;
    __IO uint8_t REWU0E                     : 1;
    __IO uint8_t REWU1E                     : 1;
    __IO uint8_t REWU2E                     : 1;
    __IO uint8_t REWU3E                     : 1;
} stc_wsunit_wake_ier_field_t;

typedef struct
{
    __IO uint8_t WUI0LV                     : 1;
    __IO uint8_t WUI1LV                     : 1;
    __IO uint8_t WUI2LV                     : 1;
    __IO uint8_t WUI3LV                     : 1;
} stc_wsunit_wake_lvr_field_t;


typedef struct
{
    union
    {
        __IO uint32_t CTL1;
        stc_adc_ctl1_field_t CTL1_f;
    };
    union
    {
        __IO uint8_t CTL2;
        stc_adc_ctl2_field_t CTL2_f;
    };
    uint8_t RESERVED2[7];
    union
    {
        __IO uint16_t RESULT;
        stc_adc_result_field_t RESULT_f;
    };
    uint8_t RESERVED3[2];
    union
    {
        __IO uint32_t ADCMPIF;
        stc_adc_adcmpif_field_t ADCMPIF_f;
    };
    union
    {
        __IO uint32_t ADCMPF;
        stc_adc_adcmpf_field_t ADCMPF_f;
    };
    union
    {
        __IO uint16_t ADCMPCTL;
        stc_adc_adcmpctl_field_t ADCMPCTL_f;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint16_t ADCMPL;
        stc_adc_adcmpl_field_t ADCMPL_f;
    };
    union
    {
        __IO uint16_t ADCMPH;
        stc_adc_adcmph_field_t ADCMPH_f;
    };
}M0P_ADC_TypeDef;

typedef struct
{
    union
    {
        __IO uint16_t CON;
        stc_aes_con_field_t CON_f;
    };
    uint8_t RESERVED1[14];
    union
    {
        __IO uint32_t DATA0;
        stc_aes_data0_field_t DATA0_f;
    };
    union
    {
        __IO uint32_t DATA1;
        stc_aes_data1_field_t DATA1_f;
    };
    union
    {
        __IO uint32_t DATA2;
        stc_aes_data2_field_t DATA2_f;
    };
    union
    {
        __IO uint32_t DATA3;
        stc_aes_data3_field_t DATA3_f;
    };
    union
    {
        __IO uint32_t KEY0;
        stc_aes_key0_field_t KEY0_f;
    };
    union
    {
        __IO uint32_t KEY1;
        stc_aes_key1_field_t KEY1_f;
    };
    union
    {
        __IO uint32_t KEY2;
        stc_aes_key2_field_t KEY2_f;
    };
    union
    {
        __IO uint32_t KEY3;
        stc_aes_key3_field_t KEY3_f;
    };
    union
    {
        __IO uint32_t KEY4;
        stc_aes_key4_field_t KEY4_f;
    };
    union
    {
        __IO uint32_t KEY5;
        stc_aes_key5_field_t KEY5_f;
    };
    union
    {
        __IO uint32_t KEY6;
        stc_aes_key6_field_t KEY6_f;
    };
    union
    {
        __IO uint32_t KEY7;
        stc_aes_key7_field_t KEY7_f;
    };
    union
    {
        __IO uint32_t RNG0;
        stc_aes_rng0_field_t RNG0_f;
    };
    union
    {
        __IO uint32_t RNG1;
        stc_aes_rng1_field_t RNG1_f;
    };
    uint8_t RESERVED15[8];
    union
    {
        __IO uint8_t INT_CON;
        stc_aes_int_con_field_t INT_CON_f;
    };
    uint8_t RESERVED16[15];
    union
    {
        __IO uint8_t DIV_EN;
        stc_aes_div_en_field_t DIV_EN_f;
    };
}M0P_AES_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t BUZ_CTL;
        stc_buzzer_buz_ctl_field_t BUZ_CTL_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t BUZ_CNT;
        stc_buzzer_buz_cnt_field_t BUZ_CNT_f;
    };
}M0P_BUZZER_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t CTRL;
        stc_clock_ctrl_field_t CTRL_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t CLK_STB;
        stc_clock_clk_stb_field_t CLK_STB_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint32_t LPM_CTL;
        stc_clock_lpm_ctl_field_t LPM_CTL_f;
    };
    union
    {
        __IO uint16_t STAT;
        stc_clock_stat_field_t STAT_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint8_t BC_DIV;
        stc_clock_bc_div_field_t BC_DIV_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t APB0_CTRL;
        stc_clock_apb0_ctrl_field_t APB0_CTRL_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint8_t APB1_CTRL;
        stc_clock_apb1_ctrl_field_t APB1_CTRL_f;
    };
    uint8_t RESERVED7[7];
    union
    {
        __IO uint8_t CLK_CTL;
        stc_clock_clk_ctl_field_t CLK_CTL_f;
    };
    uint8_t RESERVED8[15];
    union
    {
        __IO uint8_t CSWT;
        stc_clock_cswt_field_t CSWT_f;
    };
    uint8_t RESERVED9[15];
    union
    {
        __IO uint16_t FCM_CTL;
        stc_clock_fcm_ctl_field_t FCM_CTL_f;
    };
    uint8_t RESERVED10[2];
    union
    {
        __IO uint8_t FCM_STR;
        stc_clock_fcm_str_field_t FCM_STR_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint16_t AFDWH_CTL;
        stc_clock_afdwh_ctl_field_t AFDWH_CTL_f;
    };
    uint8_t RESERVED12[2];
    union
    {
        __IO uint16_t AFDWL_CTL;
        stc_clock_afdwl_ctl_field_t AFDWL_CTL_f;
    };
    uint8_t RESERVED13[2];
    union
    {
        __IO uint16_t AFDC_CTL;
        stc_clock_afdc_ctl_field_t AFDC_CTL_f;
    };
    uint8_t RESERVED14[2];
    union
    {
        __IO uint8_t DBWDT_CTRL;
        stc_clock_dbwdt_ctrl_field_t DBWDT_CTRL_f;
    };
    uint8_t RESERVED15[11];
    union
    {
        __IO uint8_t INT_CTRL;
        stc_clock_int_ctrl_field_t INT_CTRL_f;
    };
    uint8_t RESERVED16[3];
    union
    {
        __IO uint8_t INT_PEND;
        stc_clock_int_pend_field_t INT_PEND_f;
    };
    uint8_t RESERVED17[3];
    union
    {
        __IO uint8_t INT_CLR;
        stc_clock_int_clr_field_t INT_CLR_f;
    };
}M0P_CLOCK_TypeDef;

typedef struct
{
    union
    {
        __IO uint16_t CTSEL0123;
        stc_ctiosel03_ctsel0123_field_t CTSEL0123_f;
    };
}M0P_CTIOSEL03_TypeDef;

typedef struct
{
    union
    {
        __IO uint16_t CTSEL4567;
        stc_ctiosel47_ctsel4567_field_t CTSEL4567_f;
    };
}M0P_CTIOSEL47_TypeDef;

typedef struct
{
    __IO uint16_t LWRR;
    uint8_t RESERVED1[2];
    __IO uint16_t HWRR;
    uint8_t RESERVED2[2];
    __IO uint16_t TCNT;
    uint8_t RESERVED3[2];
    union
    {
        __IO uint16_t TCR;
        stc_ct_ppg_tcr_field_t TCR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint8_t STA;
        stc_ct_ppg_sta_field_t STA_f;
    };
    union
    {
        __IO uint8_t TCR2;
        stc_ct_ppg_tcr2_field_t TCR2_f;
    };
}M0P_CT_PPG_TypeDef;

typedef struct
{
    uint8_t RESERVED0[4];
    __IO uint16_t DBUF;
    uint8_t RESERVED1[6];
    union
    {
        __IO uint16_t TCR;
        stc_ct_pwc_tcr_field_t TCR_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint8_t STA;
        stc_ct_pwc_sta_field_t STA_f;
    };
    union
    {
        __IO uint8_t TCR2;
        stc_ct_pwc_tcr2_field_t TCR2_f;
    };
}M0P_CT_PWC_TypeDef;

typedef struct
{
    __IO uint16_t CSR;
    uint8_t RESERVED1[2];
    __IO uint16_t DUT;
    uint8_t RESERVED2[2];
    __IO uint16_t TCNT;
    uint8_t RESERVED3[2];
    union
    {
        __IO uint16_t TCR;
        stc_ct_pwm_tcr_field_t TCR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint8_t STA;
        stc_ct_pwm_sta_field_t STA_f;
    };
    union
    {
        __IO uint8_t TCR2;
        stc_ct_pwm_tcr2_field_t TCR2_f;
    };
}M0P_CT_PWM_TypeDef;

typedef struct
{
    __IO uint16_t CSR;
    uint8_t RESERVED1[6];
    __IO uint16_t TCNT;
    uint8_t RESERVED2[2];
    union
    {
        __IO uint16_t TCR;
        stc_ct_rt_tcr_field_t TCR_f;
    };
    uint8_t RESERVED3[2];
    union
    {
        __IO uint8_t STA;
        stc_ct_rt_sta_field_t STA_f;
    };
    union
    {
        __IO uint8_t TCR2;
        stc_ct_rt_tcr2_field_t TCR2_f;
    };
}M0P_CT_RT_TypeDef;

typedef struct
{
    __IO uint32_t TIMERLOAD;
    __IO uint32_t TIMERVALUE;
    union
    {
        __IO uint32_t TIMERCTRL;
        stc_dtim_timerctrl_field_t TIMERCTRL_f;
    };
    __IO uint32_t TIMERINTCLR;
    union
    {
        __IO uint32_t TIMERRIS;
        stc_dtim_timerris_field_t TIMERRIS_f;
    };
    union
    {
        __IO uint32_t TIMERMIS;
        stc_dtim_timermis_field_t TIMERMIS_f;
    };
    __IO uint32_t TIMERBGLOAD;
}M0P_DTIM_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t INTEN;
        stc_extint_inten_field_t INTEN_f;
    };
    union
    {
        __IO uint32_t INTSRC;
        stc_extint_intsrc_field_t INTSRC_f;
    };
    union
    {
        __IO uint32_t INTCLR;
        stc_extint_intclr_field_t INTCLR_f;
    };
    union
    {
        __IO uint32_t INTLVL;
        stc_extint_intlvl_field_t INTLVL_f;
    };
    uint8_t RESERVED4[4];
    union
    {
        __IO uint16_t NMISRC;
        stc_extint_nmisrc_field_t NMISRC_f;
    };
    uint8_t RESERVED5[2];
    union
    {
        __IO uint16_t NMICLR;
        stc_extint_nmiclr_field_t NMICLR_f;
    };
}M0P_EXTINT_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t FGET0;
        stc_fastio_fget0_field_t FGET0_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t FGET1;
        stc_fastio_fget1_field_t FGET1_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t FGET2;
        stc_fastio_fget2_field_t FGET2_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint8_t FGET3;
        stc_fastio_fget3_field_t FGET3_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t FGET4;
        stc_fastio_fget4_field_t FGET4_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t FGET5;
        stc_fastio_fget5_field_t FGET5_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint8_t FGET6;
        stc_fastio_fget6_field_t FGET6_f;
    };
    uint8_t RESERVED7[3];
    union
    {
        __IO uint8_t FGET7;
        stc_fastio_fget7_field_t FGET7_f;
    };
    uint8_t RESERVED8[3];
    union
    {
        __IO uint8_t FGET8;
        stc_fastio_fget8_field_t FGET8_f;
    };
    uint8_t RESERVED9[31];
    union
    {
        __IO uint8_t FSET0;
        stc_fastio_fset0_field_t FSET0_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t FSET1;
        stc_fastio_fset1_field_t FSET1_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t FSET2;
        stc_fastio_fset2_field_t FSET2_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t FSET3;
        stc_fastio_fset3_field_t FSET3_f;
    };
    uint8_t RESERVED13[3];
    union
    {
        __IO uint8_t FSET4;
        stc_fastio_fset4_field_t FSET4_f;
    };
    uint8_t RESERVED14[3];
    union
    {
        __IO uint8_t FSET5;
        stc_fastio_fset5_field_t FSET5_f;
    };
    uint8_t RESERVED15[3];
    union
    {
        __IO uint8_t FSET6;
        stc_fastio_fset6_field_t FSET6_f;
    };
    uint8_t RESERVED16[3];
    union
    {
        __IO uint8_t FSET7;
        stc_fastio_fset7_field_t FSET7_f;
    };
    uint8_t RESERVED17[3];
    union
    {
        __IO uint8_t FSET8;
        stc_fastio_fset8_field_t FSET8_f;
    };
}M0P_FASTIO_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t FOCR;
        stc_flash_focr_field_t FOCR_f;
    };
    union
    {
        __IO uint32_t FLCR0;
        stc_flash_flcr0_field_t FLCR0_f;
    };
    union
    {
        __IO uint32_t FLCR1;
        stc_flash_flcr1_field_t FLCR1_f;
    };
    union
    {
        __IO uint32_t FSTR;
        stc_flash_fstr_field_t FSTR_f;
    };
    union
    {
        __IO uint32_t FWCICR;
        stc_flash_fwcicr_field_t FWCICR_f;
    };
    union
    {
        __IO uint32_t FUDR0;
        stc_flash_fudr0_field_t FUDR0_f;
    };
    union
    {
        __IO uint32_t FUDR1;
        stc_flash_fudr1_field_t FUDR1_f;
    };
    union
    {
        __IO uint32_t FUDR2;
        stc_flash_fudr2_field_t FUDR2_f;
    };
    union
    {
        __IO uint32_t FUDR3;
        stc_flash_fudr3_field_t FUDR3_f;
    };
    union
    {
        __IO uint8_t TNVS;
        stc_flash_tnvs_field_t TNVS_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t TPROG;
        stc_flash_tprog_field_t TPROG_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t TPGS;
        stc_flash_tpgs_field_t TPGS_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t TRCVPGM;
        stc_flash_trcvpgm_field_t TRCVPGM_f;
    };
    uint8_t RESERVED13[3];
    union
    {
        __IO uint8_t TRCVPERS;
        stc_flash_trcvpers_field_t TRCVPERS_f;
    };
    uint8_t RESERVED14[3];
    union
    {
        __IO uint8_t TRCVCERS;
        stc_flash_trcvcers_field_t TRCVCERS_f;
    };
    uint8_t RESERVED15[3];
    union
    {
        __IO uint8_t TPERS;
        stc_flash_tpers_field_t TPERS_f;
    };
    uint8_t RESERVED16[3];
    union
    {
        __IO uint8_t TCERS;
        stc_flash_tcers_field_t TCERS_f;
    };
}M0P_FLASH_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t FN0;
        stc_gpio_fn0_field_t FN0_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t FN1;
        stc_gpio_fn1_field_t FN1_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t FN2;
        stc_gpio_fn2_field_t FN2_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint8_t FN3;
        stc_gpio_fn3_field_t FN3_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t FN4;
        stc_gpio_fn4_field_t FN4_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t FN5;
        stc_gpio_fn5_field_t FN5_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint8_t FN6;
        stc_gpio_fn6_field_t FN6_f;
    };
    uint8_t RESERVED7[3];
    union
    {
        __IO uint8_t FN7;
        stc_gpio_fn7_field_t FN7_f;
    };
    uint8_t RESERVED8[3];
    union
    {
        __IO uint8_t FN8;
        stc_gpio_fn8_field_t FN8_f;
    };
    uint8_t RESERVED9[223];
    union
    {
        __IO uint8_t PU0;
        stc_gpio_pu0_field_t PU0_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t PU1;
        stc_gpio_pu1_field_t PU1_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t PU2;
        stc_gpio_pu2_field_t PU2_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t PU3;
        stc_gpio_pu3_field_t PU3_f;
    };
    uint8_t RESERVED13[3];
    union
    {
        __IO uint8_t PU4;
        stc_gpio_pu4_field_t PU4_f;
    };
    uint8_t RESERVED14[3];
    union
    {
        __IO uint8_t PU5;
        stc_gpio_pu5_field_t PU5_f;
    };
    uint8_t RESERVED15[3];
    union
    {
        __IO uint8_t PU6;
        stc_gpio_pu6_field_t PU6_f;
    };
    uint8_t RESERVED16[3];
    union
    {
        __IO uint8_t PU7;
        stc_gpio_pu7_field_t PU7_f;
    };
    uint8_t RESERVED17[3];
    union
    {
        __IO uint8_t PU8;
        stc_gpio_pu8_field_t PU8_f;
    };
    uint8_t RESERVED18[223];
    union
    {
        __IO uint8_t DIR0;
        stc_gpio_dir0_field_t DIR0_f;
    };
    uint8_t RESERVED19[3];
    union
    {
        __IO uint8_t DIR1;
        stc_gpio_dir1_field_t DIR1_f;
    };
    uint8_t RESERVED20[3];
    union
    {
        __IO uint8_t DIR2;
        stc_gpio_dir2_field_t DIR2_f;
    };
    uint8_t RESERVED21[3];
    union
    {
        __IO uint8_t DIR3;
        stc_gpio_dir3_field_t DIR3_f;
    };
    uint8_t RESERVED22[3];
    union
    {
        __IO uint8_t DIR4;
        stc_gpio_dir4_field_t DIR4_f;
    };
    uint8_t RESERVED23[3];
    union
    {
        __IO uint8_t DIR5;
        stc_gpio_dir5_field_t DIR5_f;
    };
    uint8_t RESERVED24[3];
    union
    {
        __IO uint8_t DIR6;
        stc_gpio_dir6_field_t DIR6_f;
    };
    uint8_t RESERVED25[3];
    union
    {
        __IO uint8_t DIR7;
        stc_gpio_dir7_field_t DIR7_f;
    };
    uint8_t RESERVED26[3];
    union
    {
        __IO uint8_t DIR8;
        stc_gpio_dir8_field_t DIR8_f;
    };
    uint8_t RESERVED27[223];
    union
    {
        __IO uint8_t GET0;
        stc_gpio_get0_field_t GET0_f;
    };
    uint8_t RESERVED28[3];
    union
    {
        __IO uint8_t GET1;
        stc_gpio_get1_field_t GET1_f;
    };
    uint8_t RESERVED29[3];
    union
    {
        __IO uint8_t GET2;
        stc_gpio_get2_field_t GET2_f;
    };
    uint8_t RESERVED30[3];
    union
    {
        __IO uint8_t GET3;
        stc_gpio_get3_field_t GET3_f;
    };
    uint8_t RESERVED31[3];
    union
    {
        __IO uint8_t GET4;
        stc_gpio_get4_field_t GET4_f;
    };
    uint8_t RESERVED32[3];
    union
    {
        __IO uint8_t GET5;
        stc_gpio_get5_field_t GET5_f;
    };
    uint8_t RESERVED33[3];
    union
    {
        __IO uint8_t GET6;
        stc_gpio_get6_field_t GET6_f;
    };
    uint8_t RESERVED34[3];
    union
    {
        __IO uint8_t GET7;
        stc_gpio_get7_field_t GET7_f;
    };
    uint8_t RESERVED35[3];
    union
    {
        __IO uint8_t GET8;
        stc_gpio_get8_field_t GET8_f;
    };
    uint8_t RESERVED36[223];
    union
    {
        __IO uint8_t SET0;
        stc_gpio_set0_field_t SET0_f;
    };
    uint8_t RESERVED37[3];
    union
    {
        __IO uint8_t SET1;
        stc_gpio_set1_field_t SET1_f;
    };
    uint8_t RESERVED38[3];
    union
    {
        __IO uint8_t SET2;
        stc_gpio_set2_field_t SET2_f;
    };
    uint8_t RESERVED39[3];
    union
    {
        __IO uint8_t SET3;
        stc_gpio_set3_field_t SET3_f;
    };
    uint8_t RESERVED40[3];
    union
    {
        __IO uint8_t SET4;
        stc_gpio_set4_field_t SET4_f;
    };
    uint8_t RESERVED41[3];
    union
    {
        __IO uint8_t SET5;
        stc_gpio_set5_field_t SET5_f;
    };
    uint8_t RESERVED42[3];
    union
    {
        __IO uint8_t SET6;
        stc_gpio_set6_field_t SET6_f;
    };
    uint8_t RESERVED43[3];
    union
    {
        __IO uint8_t SET7;
        stc_gpio_set7_field_t SET7_f;
    };
    uint8_t RESERVED44[3];
    union
    {
        __IO uint8_t SET8;
        stc_gpio_set8_field_t SET8_f;
    };
    uint8_t RESERVED45[223];
    union
    {
        __IO uint16_t ANALOG;
        stc_gpio_analog_field_t ANALOG_f;
    };
    uint8_t RESERVED46[126];
    union
    {
        __IO uint8_t SPS;
        stc_gpio_sps_field_t SPS_f;
    };
    uint8_t RESERVED47[127];
    union
    {
        __IO uint16_t FN_SEL00;
        stc_gpio_fn_sel00_field_t FN_SEL00_f;
    };
    uint8_t RESERVED48[6];
    union
    {
        __IO uint32_t FN_SEL02;
        stc_gpio_fn_sel02_field_t FN_SEL02_f;
    };
    union
    {
        __IO uint32_t FN_SEL03;
        stc_gpio_fn_sel03_field_t FN_SEL03_f;
    };
    union
    {
        __IO uint32_t FN_SEL04;
        stc_gpio_fn_sel04_field_t FN_SEL04_f;
    };
    union
    {
        __IO uint32_t FN_SEL05;
        stc_gpio_fn_sel05_field_t FN_SEL05_f;
    };
    union
    {
        __IO uint32_t FN_SEL06;
        stc_gpio_fn_sel06_field_t FN_SEL06_f;
    };
    union
    {
        __IO uint32_t FN_SEL07;
        stc_gpio_fn_sel07_field_t FN_SEL07_f;
    };
    union
    {
        __IO uint32_t FN_SEL08;
        stc_gpio_fn_sel08_field_t FN_SEL08_f;
    };
    union
    {
        __IO uint16_t FN_SEL09;
        stc_gpio_fn_sel09_field_t FN_SEL09_f;
    };
    uint8_t RESERVED56[218];
    union
    {
        __IO uint8_t ODR0;
        stc_gpio_odr0_field_t ODR0_f;
    };
    uint8_t RESERVED57[3];
    union
    {
        __IO uint8_t ODR1;
        stc_gpio_odr1_field_t ODR1_f;
    };
    uint8_t RESERVED58[3];
    union
    {
        __IO uint8_t ODR2;
        stc_gpio_odr2_field_t ODR2_f;
    };
    uint8_t RESERVED59[3];
    union
    {
        __IO uint8_t ODR3;
        stc_gpio_odr3_field_t ODR3_f;
    };
    uint8_t RESERVED60[3];
    union
    {
        __IO uint8_t ODR4;
        stc_gpio_odr4_field_t ODR4_f;
    };
    uint8_t RESERVED61[3];
    union
    {
        __IO uint8_t ODR5;
        stc_gpio_odr5_field_t ODR5_f;
    };
    uint8_t RESERVED62[3];
    union
    {
        __IO uint8_t ODR6;
        stc_gpio_odr6_field_t ODR6_f;
    };
    uint8_t RESERVED63[3];
    union
    {
        __IO uint8_t ODR7;
        stc_gpio_odr7_field_t ODR7_f;
    };
    uint8_t RESERVED64[3];
    union
    {
        __IO uint8_t ODR8;
        stc_gpio_odr8_field_t ODR8_f;
    };
    uint8_t RESERVED65[31];
    union
    {
        __IO uint8_t LVDIE;
        stc_gpio_lvdie_field_t LVDIE_f;
    };
    uint8_t RESERVED66[447];
    union
    {
        __IO uint8_t FSETE0;
        stc_gpio_fsete0_field_t FSETE0_f;
    };
    uint8_t RESERVED67[3];
    union
    {
        __IO uint8_t FSETE1;
        stc_gpio_fsete1_field_t FSETE1_f;
    };
    uint8_t RESERVED68[3];
    union
    {
        __IO uint8_t FSETE2;
        stc_gpio_fsete2_field_t FSETE2_f;
    };
    uint8_t RESERVED69[3];
    union
    {
        __IO uint8_t FSETE3;
        stc_gpio_fsete3_field_t FSETE3_f;
    };
    uint8_t RESERVED70[3];
    union
    {
        __IO uint8_t FSETE4;
        stc_gpio_fsete4_field_t FSETE4_f;
    };
    uint8_t RESERVED71[3];
    union
    {
        __IO uint8_t FSETE5;
        stc_gpio_fsete5_field_t FSETE5_f;
    };
    uint8_t RESERVED72[3];
    union
    {
        __IO uint8_t FSETE6;
        stc_gpio_fsete6_field_t FSETE6_f;
    };
    uint8_t RESERVED73[3];
    union
    {
        __IO uint8_t FSETE7;
        stc_gpio_fsete7_field_t FSETE7_f;
    };
    uint8_t RESERVED74[3];
    union
    {
        __IO uint8_t FSETE8;
        stc_gpio_fsete8_field_t FSETE8_f;
    };
}M0P_GPIO_TypeDef;

typedef struct
{
    __IO uint32_t WDT_LD;
    __IO uint32_t WDT_VL;
    union
    {
        __IO uint8_t WDT_CTL;
        stc_hwwdt_wdt_ctl_field_t WDT_CTL_f;
    };
    uint8_t RESERVED3[3];
    __IO uint8_t WDT_INTCLR;
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t WDT_STA;
        stc_hwwdt_wdt_sta_field_t WDT_STA_f;
    };
    uint8_t RESERVED5[3];
    __IO uint32_t WDT_LCK;
}M0P_HWWDT_TypeDef;

typedef struct
{
    uint8_t RESERVED0[16];
    union
    {
        __IO uint32_t IRQ_ST02;
        stc_irqc_irq_st02_field_t IRQ_ST02_f;
    };
    union
    {
        __IO uint32_t IRQ00PEND;
        stc_irqc_irq00pend_field_t IRQ00PEND_f;
    };
    union
    {
        __IO uint32_t IRQ01PEND;
        stc_irqc_irq01pend_field_t IRQ01PEND_f;
    };
    union
    {
        __IO uint32_t IRQ02PEND;
        stc_irqc_irq02pend_field_t IRQ02PEND_f;
    };
    uint8_t RESERVED4[4];
    union
    {
        __IO uint32_t IRQ04PEND;
        stc_irqc_irq04pend_field_t IRQ04PEND_f;
    };
    union
    {
        __IO uint32_t IRQ05PEND;
        stc_irqc_irq05pend_field_t IRQ05PEND_f;
    };
    union
    {
        __IO uint32_t IRQ06PEND;
        stc_irqc_irq06pend_field_t IRQ06PEND_f;
    };
    union
    {
        __IO uint32_t IRQ07PEND;
        stc_irqc_irq07pend_field_t IRQ07PEND_f;
    };
    union
    {
        __IO uint32_t IRQ08PEND;
        stc_irqc_irq08pend_field_t IRQ08PEND_f;
    };
    union
    {
        __IO uint32_t IRQ09PEND;
        stc_irqc_irq09pend_field_t IRQ09PEND_f;
    };
    union
    {
        __IO uint32_t IRQ10PEND;
        stc_irqc_irq10pend_field_t IRQ10PEND_f;
    };
    union
    {
        __IO uint32_t IRQ11PEND;
        stc_irqc_irq11pend_field_t IRQ11PEND_f;
    };
    union
    {
        __IO uint32_t IRQ12PEND;
        stc_irqc_irq12pend_field_t IRQ12PEND_f;
    };
    uint8_t RESERVED13[8];
    union
    {
        __IO uint32_t IRQ15PEND;
        stc_irqc_irq15pend_field_t IRQ15PEND_f;
    };
    union
    {
        __IO uint32_t IRQ16PEND;
        stc_irqc_irq16pend_field_t IRQ16PEND_f;
    };
    union
    {
        __IO uint32_t IRQ17PEND;
        stc_irqc_irq17pend_field_t IRQ17PEND_f;
    };
    union
    {
        __IO uint32_t IRQ18PEND;
        stc_irqc_irq18pend_field_t IRQ18PEND_f;
    };
    union
    {
        __IO uint32_t IRQ19PEND;
        stc_irqc_irq19pend_field_t IRQ19PEND_f;
    };
    union
    {
        __IO uint32_t IRQ20PEND;
        stc_irqc_irq20pend_field_t IRQ20PEND_f;
    };
    uint8_t RESERVED19[12];
    union
    {
        __IO uint32_t IRQ24PEND;
        stc_irqc_irq24pend_field_t IRQ24PEND_f;
    };
    union
    {
        __IO uint32_t IRQ25PEND;
        stc_irqc_irq25pend_field_t IRQ25PEND_f;
    };
    union
    {
        __IO uint32_t IRQ26PEND;
        stc_irqc_irq26pend_field_t IRQ26PEND_f;
    };
    union
    {
        __IO uint32_t IRQ27PEND;
        stc_irqc_irq27pend_field_t IRQ27PEND_f;
    };
    uint8_t RESERVED23[12];
    union
    {
        __IO uint32_t IRQ31PEND;
        stc_irqc_irq31pend_field_t IRQ31PEND_f;
    };
}M0P_IRQC_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t LCDCR0;
        stc_lcdc_lcdcr0_field_t LCDCR0_f;
    };
    union
    {
        __IO uint8_t LCDCR1;
        stc_lcdc_lcdcr1_field_t LCDCR1_f;
    };
    union
    {
        __IO uint8_t LCDCR2;
        stc_lcdc_lcdcr2_field_t LCDCR2_f;
    };
    union
    {
        __IO uint8_t LCDCR3;
        stc_lcdc_lcdcr3_field_t LCDCR3_f;
    };
    union
    {
        __IO uint8_t LCDDVC;
        stc_lcdc_lcddvc_field_t LCDDVC_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t LCDCE0;
        stc_lcdc_lcdce0_field_t LCDCE0_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint8_t LCDSE0;
        stc_lcdc_lcdse0_field_t LCDSE0_f;
    };
    union
    {
        __IO uint8_t LCDSE1;
        stc_lcdc_lcdse1_field_t LCDSE1_f;
    };
    union
    {
        __IO uint8_t LCDSE2;
        stc_lcdc_lcdse2_field_t LCDSE2_f;
    };
    union
    {
        __IO uint8_t LCDSE3;
        stc_lcdc_lcdse3_field_t LCDSE3_f;
    };
    union
    {
        __IO uint8_t LCDSE4;
        stc_lcdc_lcdse4_field_t LCDSE4_f;
    };
    uint8_t RESERVED11[3];
    __IO uint8_t LCDRAM00;
    __IO uint8_t LCDRAM01;
    __IO uint8_t LCDRAM02;
    __IO uint8_t LCDRAM03;
    __IO uint8_t LCDRAM04;
    __IO uint8_t LCDRAM05;
    __IO uint8_t LCDRAM06;
    __IO uint8_t LCDRAM07;
    __IO uint8_t LCDRAM08;
    __IO uint8_t LCDRAM09;
    __IO uint8_t LCDRAM10;
    __IO uint8_t LCDRAM11;
    __IO uint8_t LCDRAM12;
    __IO uint8_t LCDRAM13;
    __IO uint8_t LCDRAM14;
    __IO uint8_t LCDRAM15;
    __IO uint8_t LCDRAM16;
    __IO uint8_t LCDRAM17;
    __IO uint8_t LCDRAM18;
    __IO uint8_t LCDRAM19;
    __IO uint8_t LCDRAM20;
    __IO uint8_t LCDRAM21;
    __IO uint8_t LCDRAM22;
    __IO uint8_t LCDRAM23;
    __IO uint8_t LCDRAM24;
    __IO uint8_t LCDRAM25;
    __IO uint8_t LCDRAM26;
    __IO uint8_t LCDRAM27;
    __IO uint8_t LCDRAM28;
    __IO uint8_t LCDRAM29;
    __IO uint8_t LCDRAM30;
    __IO uint8_t LCDRAM31;
    __IO uint8_t LCDRAM32;
    __IO uint8_t LCDRAM33;
    __IO uint8_t LCDRAM34;
    __IO uint8_t LCDRAM35;
    __IO uint8_t LCDRAM36;
    __IO uint8_t LCDRAM37;
    __IO uint8_t LCDRAM38;
    __IO uint8_t LCDRAM39;
}M0P_LCDC_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t MR;
        stc_msc_i2c_mr_field_t MR_f;
    };
    union
    {
        __IO uint8_t BC;
        stc_msc_i2c_bc_field_t BC_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint8_t BS;
        stc_msc_i2c_bs_field_t BS_f;
    };
    union
    {
        __IO uint8_t SR;
        stc_msc_i2c_sr_field_t SR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint16_t RXDR;
        __IO uint16_t TXDR;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint16_t BRS;
        stc_msc_i2c_brs_field_t BRS_f;
    };
    uint8_t RESERVED7[2];
    union
    {
        __IO uint8_t SA;
        stc_msc_i2c_sa_field_t SA_f;
    };
    union
    {
        __IO uint8_t SAMSK;
        stc_msc_i2c_samsk_field_t SAMSK_f;
    };
    uint8_t RESERVED9[11];
    union
    {
        __IO uint8_t EBCR;
        stc_msc_i2c_ebcr_field_t EBCR_f;
    };
}M0P_MSC_I2C_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t MR;
        stc_msc_spi_mr_field_t MR_f;
    };
    union
    {
        __IO uint8_t CR;
        stc_msc_spi_cr_field_t CR_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint8_t ECR;
        stc_msc_spi_ecr_field_t ECR_f;
    };
    union
    {
        __IO uint8_t SR;
        stc_msc_spi_sr_field_t SR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint16_t RXDR;
        __IO uint16_t TXDR;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint16_t BRS;
        stc_msc_spi_brs_field_t BRS_f;
    };
    uint8_t RESERVED7[14];
    union
    {
        __IO uint8_t CSTMG0;
        stc_msc_spi_cstmg0_field_t CSTMG0_f;
    };
    union
    {
        __IO uint8_t CSTMG1;
        stc_msc_spi_cstmg1_field_t CSTMG1_f;
    };
    uint8_t RESERVED9[2];
    union
    {
        __IO uint16_t CSTMG32;
        stc_msc_spi_cstmg32_field_t CSTMG32_f;
    };
    uint8_t RESERVED10[2];
    union
    {
        __IO uint16_t EACR;
        stc_msc_spi_eacr_field_t EACR_f;
    };
    uint8_t RESERVED11[2];
    union
    {
        __IO uint16_t TMR;
        stc_msc_spi_tmr_field_t TMR_f;
    };
    uint8_t RESERVED12[2];
    union
    {
        __IO uint16_t TMC;
        stc_msc_spi_tmc_field_t TMC_f;
    };
    uint8_t RESERVED13[2];
    union
    {
        __IO uint16_t CSCR;
        stc_msc_spi_cscr_field_t CSCR_f;
    };
    uint8_t RESERVED14[2];
    union
    {
        __IO uint8_t CSFR0;
        stc_msc_spi_csfr0_field_t CSFR0_f;
    };
    union
    {
        __IO uint8_t CSFR1;
        stc_msc_spi_csfr1_field_t CSFR1_f;
    };
    uint8_t RESERVED16[2];
    union
    {
        __IO uint8_t CSFR2;
        stc_msc_spi_csfr2_field_t CSFR2_f;
    };
    uint8_t RESERVED17[3];
    __IO uint8_t TDTCNT0;
    __IO uint8_t TDTCNT1;
    uint8_t RESERVED19[2];
    __IO uint8_t TDTCNT2;
    __IO uint8_t TDTCNT3;
}M0P_MSC_SPI_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t MR;
        stc_msc_uart_mr_field_t MR_f;
    };
    union
    {
        __IO uint8_t CR;
        stc_msc_uart_cr_field_t CR_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint8_t ECR;
        stc_msc_uart_ecr_field_t ECR_f;
    };
    union
    {
        __IO uint8_t SR;
        stc_msc_uart_sr_field_t SR_f;
    };
    uint8_t RESERVED4[2];
    union
    {
        __IO uint16_t RXDR;
        __IO uint16_t TXDR;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint16_t BRS;
        stc_msc_uart_brs_field_t BRS_f;
    };
    uint8_t RESERVED7[66];
    union
    {
        __IO uint16_t COMP;
        stc_msc_uart_comp_field_t COMP_f;
    };
}M0P_MSC_UART_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t HICR_TRMKEY;
        stc_osc_hicr_trmkey_field_t HICR_TRMKEY_f;
    };
    union
    {
        __IO uint32_t HICR_FTRM;
        stc_osc_hicr_ftrm_field_t HICR_FTRM_f;
    };
    union
    {
        __IO uint32_t HICR_TTRM;
        stc_osc_hicr_ttrm_field_t HICR_TTRM_f;
    };
    union
    {
        __IO uint8_t HICR_FMC;
        stc_osc_hicr_fmc_field_t HICR_FMC_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t HICR_CSR;
        stc_osc_hicr_csr_field_t HICR_CSR_f;
    };
    uint8_t RESERVED5[15];
    union
    {
        __IO uint32_t HSXT_PWRCTL;
        stc_osc_hsxt_pwrctl_field_t HSXT_PWRCTL_f;
    };
    uint8_t RESERVED6[12];
    union
    {
        __IO uint32_t LSXT_PWRCTL;
        stc_osc_lsxt_pwrctl_field_t LSXT_PWRCTL_f;
    };
}M0P_OSC_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t CTL;
        stc_parity_ctl_field_t CTL_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint32_t ADDR;
        stc_parity_addr_field_t ADDR_f;
    };
}M0P_PARITY_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t CLKEN0;
        stc_pcg_clken0_field_t CLKEN0_f;
    };
    union
    {
        __IO uint32_t RSTCTL0;
        stc_pcg_rstctl0_field_t RSTCTL0_f;
    };
    uint8_t RESERVED2[8];
    union
    {
        __IO uint32_t CLKEN1;
        stc_pcg_clken1_field_t CLKEN1_f;
    };
    union
    {
        __IO uint32_t RSTCTL1;
        stc_pcg_rstctl1_field_t RSTCTL1_f;
    };
    uint8_t RESERVED4[8];
    union
    {
        __IO uint32_t CLKEN2;
        stc_pcg_clken2_field_t CLKEN2_f;
    };
    union
    {
        __IO uint32_t RSTCTL2;
        stc_pcg_rstctl2_field_t RSTCTL2_f;
    };
}M0P_PCG_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t RTCCTL1;
        stc_rtc_rtcctl1_field_t RTCCTL1_f;
    };
    union
    {
        __IO uint32_t RTCCTL2;
        stc_rtc_rtcctl2_field_t RTCCTL2_f;
    };
    union
    {
        __IO uint32_t CCS;
        stc_rtc_ccs_field_t CCS_f;
    };
    union
    {
        __IO uint8_t SEN;
        stc_rtc_sen_field_t SEN_f;
    };
    union
    {
        __IO uint8_t MIN;
        stc_rtc_min_field_t MIN_f;
    };
    union
    {
        __IO uint8_t HOUR;
        stc_rtc_hour_field_t HOUR_f;
    };
    union
    {
        __IO uint8_t DATE;
        stc_rtc_date_field_t DATE_f;
    };
    union
    {
        __IO uint8_t WEEK;
        stc_rtc_week_field_t WEEK_f;
    };
    union
    {
        __IO uint8_t MON;
        stc_rtc_mon_field_t MON_f;
    };
    union
    {
        __IO uint8_t YEAR;
        stc_rtc_year_field_t YEAR_f;
    };
    uint8_t RESERVED10[1];
    union
    {
        __IO uint8_t ASEN;
        stc_rtc_asen_field_t ASEN_f;
    };
    union
    {
        __IO uint8_t AMIN;
        stc_rtc_amin_field_t AMIN_f;
    };
    union
    {
        __IO uint8_t AHOUR;
        stc_rtc_ahour_field_t AHOUR_f;
    };
    union
    {
        __IO uint8_t ADATE;
        stc_rtc_adate_field_t ADATE_f;
    };
    uint8_t RESERVED14[1];
    union
    {
        __IO uint8_t AMON;
        stc_rtc_amon_field_t AMON_f;
    };
    union
    {
        __IO uint8_t AYEAR;
        stc_rtc_ayear_field_t AYEAR_f;
    };
    uint8_t RESERVED16[1];
    union
    {
        __IO uint32_t TVAL;
        stc_rtc_tval_field_t TVAL_f;
    };
    union
    {
        __IO uint8_t SCLKI;
        stc_rtc_sclki_field_t SCLKI_f;
    };
    union
    {
        __IO uint8_t SCLKS;
        stc_rtc_sclks_field_t SCLKS_f;
    };
    uint8_t RESERVED19[2];
    union
    {
        __IO uint16_t CALVAL;
        stc_rtc_calval_field_t CALVAL_f;
    };
    union
    {
        __IO uint8_t CALEN;
        stc_rtc_calen_field_t CALEN_f;
    };
    uint8_t RESERVED21[1];
    union
    {
        __IO uint8_t CLKDIVX;
        stc_rtc_clkdivx_field_t CLKDIVX_f;
    };
    union
    {
        __IO uint8_t CLKDIVC;
        stc_rtc_clkdivc_field_t CLKDIVC_f;
    };
    uint8_t RESERVED23[2];
    union
    {
        __IO uint16_t CALCYC;
        stc_rtc_calcyc_field_t CALCYC_f;
    };
    uint8_t RESERVED24[2];
    union
    {
        __IO uint8_t RTCODIV;
        stc_rtc_rtcodiv_field_t RTCODIV_f;
    };
}M0P_RTC_TypeDef;

typedef struct
{
    uint8_t RESERVED0[252];
    union
    {
        __IO uint16_t CTSSSR;
        stc_sbssr_ctsssr_field_t CTSSSR_f;
    };
}M0P_SBSSR_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t CON;
        stc_sci_con_field_t CON_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t MODE;
        stc_sci_mode_field_t MODE_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint8_t STATUS;
        stc_sci_status_field_t STATUS_f;
    };
    uint8_t RESERVED3[3];
    union
    {
        __IO uint8_t FIFO_STATUS;
        stc_sci_fifo_status_field_t FIFO_STATUS_f;
    };
    uint8_t RESERVED4[3];
    union
    {
        __IO uint8_t FIFO_DEPTH;
        stc_sci_fifo_depth_field_t FIFO_DEPTH_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint8_t DATA;
        stc_sci_data_field_t DATA_f;
    };
    uint8_t RESERVED6[3];
    union
    {
        __IO uint16_t EDC_DATA;
        stc_sci_edc_data_field_t EDC_DATA_f;
    };
    uint8_t RESERVED7[2];
    union
    {
        __IO uint16_t SBDR;
        stc_sci_sbdr_field_t SBDR_f;
    };
    uint8_t RESERVED8[2];
    union
    {
        __IO uint16_t ETU_CNT;
        stc_sci_etu_cnt_field_t ETU_CNT_f;
    };
    uint8_t RESERVED9[2];
    union
    {
        __IO uint8_t F1_NUM;
        stc_sci_f1_num_field_t F1_NUM_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t CLK_RST;
        stc_sci_clk_rst_field_t CLK_RST_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t INT_EN;
        stc_sci_int_en_field_t INT_EN_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t WAKEUP_INT;
        stc_sci_wakeup_int_field_t WAKEUP_INT_f;
    };
}M0P_SCI_TypeDef;

typedef struct
{
    __IO uint32_t WDT_LD;
    __IO uint32_t WDT_VL;
    union
    {
        __IO uint8_t WDT_CTL;
        stc_swwdt_wdt_ctl_field_t WDT_CTL_f;
    };
    uint8_t RESERVED3[3];
    __IO uint32_t WDT_INTCLR;
    union
    {
        __IO uint8_t WDT_STA;
        stc_swwdt_wdt_sta_field_t WDT_STA_f;
    };
    uint8_t RESERVED5[7];
    union
    {
        __IO uint8_t WDT_MDC;
        stc_swwdt_wdt_mdc_field_t WDT_MDC_f;
    };
    uint8_t RESERVED6[3047];
    __IO uint32_t WDT_LCK;
}M0P_SWWDT_TypeDef;

typedef struct
{
    union
    {
        __IO uint32_t UIDR0;
        stc_uid_uidr0_field_t UIDR0_f;
    };
    union
    {
        __IO uint32_t UIDR1;
        stc_uid_uidr1_field_t UIDR1_f;
    };
    union
    {
        __IO uint32_t UIDR2;
        stc_uid_uidr2_field_t UIDR2_f;
    };
}M0P_UID_TypeDef;

typedef struct
{
    union
    {
        __IO uint16_t CTL1;
        stc_vc_ctl1_field_t CTL1_f;
    };
    uint8_t RESERVED1[2];
    union
    {
        __IO uint16_t CTL2;
        stc_vc_ctl2_field_t CTL2_f;
    };
    uint8_t RESERVED2[2];
    union
    {
        __IO uint8_t CTL3;
        stc_vc_ctl3_field_t CTL3_f;
    };
}M0P_VC_TypeDef;

typedef struct
{
    union
    {
        __IO uint8_t LVD_CTRL1;
        stc_wsunit_lvd_ctrl1_field_t LVD_CTRL1_f;
    };
    uint8_t RESERVED1[3];
    union
    {
        __IO uint8_t LVD_CTRL2;
        stc_wsunit_lvd_ctrl2_field_t LVD_CTRL2_f;
    };
    uint8_t RESERVED2[3];
    union
    {
        __IO uint16_t LVD_STR;
        stc_wsunit_lvd_str_field_t LVD_STR_f;
    };
    uint8_t RESERVED3[2];
    union
    {
        __IO uint8_t LVD_CLR;
        stc_wsunit_lvd_clr_field_t LVD_CLR_f;
    };
    uint8_t RESERVED4[7];
    union
    {
        __IO uint8_t LVD2_CTL;
        stc_wsunit_lvd2_ctl_field_t LVD2_CTL_f;
    };
    uint8_t RESERVED5[3];
    union
    {
        __IO uint16_t LVD2_STR;
        stc_wsunit_lvd2_str_field_t LVD2_STR_f;
    };
    uint8_t RESERVED6[2];
    union
    {
        __IO uint8_t LVD2_CLR;
        stc_wsunit_lvd2_clr_field_t LVD2_CLR_f;
    };
    uint8_t RESERVED7[3];
    union
    {
        __IO uint32_t LDO_CTL;
        stc_wsunit_ldo_ctl_field_t LDO_CTL_f;
    };
    uint8_t RESERVED8[12];
    union
    {
        __IO uint8_t BGR_CTL;
        stc_wsunit_bgr_ctl_field_t BGR_CTL_f;
    };
    uint8_t RESERVED9[207];
    union
    {
        __IO uint8_t CLK_CTL1;
        stc_wsunit_clk_ctl1_field_t CLK_CTL1_f;
    };
    uint8_t RESERVED10[3];
    union
    {
        __IO uint8_t CLK_CTL2;
        stc_wsunit_clk_ctl2_field_t CLK_CTL2_f;
    };
    uint8_t RESERVED11[3];
    union
    {
        __IO uint8_t MOSC_CTL;
        stc_wsunit_mosc_ctl_field_t MOSC_CTL_f;
    };
    uint8_t RESERVED12[3];
    union
    {
        __IO uint8_t DS_RAMP;
        stc_wsunit_ds_ramp_field_t DS_RAMP_f;
    };
    uint8_t RESERVED13[243];
    union
    {
        __IO uint8_t WAKE_RSR;
        stc_wsunit_wake_rsr_field_t WAKE_RSR_f;
    };
    uint8_t RESERVED14[3];
    union
    {
        __IO uint8_t WAKE_ISR;
        stc_wsunit_wake_isr_field_t WAKE_ISR_f;
    };
    uint8_t RESERVED15[3];
    union
    {
        __IO uint8_t WAKE_IER;
        stc_wsunit_wake_ier_field_t WAKE_IER_f;
    };
    uint8_t RESERVED16[3];
    union
    {
        __IO uint8_t WAKE_LVR;
        stc_wsunit_wake_lvr_field_t WAKE_LVR_f;
    };
    uint8_t RESERVED17[1267];
    __IO uint8_t BUR01;
    __IO uint8_t BUR02;
    __IO uint8_t BUR03;
    __IO uint8_t BUR04;
    __IO uint8_t BUR05;
    __IO uint8_t BUR06;
    __IO uint8_t BUR07;
    __IO uint8_t BUR08;
    __IO uint8_t BUR09;
    __IO uint8_t BUR10;
    __IO uint8_t BUR11;
    __IO uint8_t BUR12;
    __IO uint8_t BUR13;
    __IO uint8_t BUR14;
    __IO uint8_t BUR15;
    __IO uint8_t BUR16;
}M0P_WSUNIT_TypeDef;



#define M0P_PERIPH_BASE                        (0x40000000UL)
#define M0P_ADC_BASE                           (M0P_PERIPH_BASE + 0x00027000UL)
#define M0P_AES_BASE                           (M0P_PERIPH_BASE + 0x0006B000UL)
#define M0P_BUZZER_BASE                        (M0P_PERIPH_BASE + 0x0003C200UL)
#define M0P_CLOCK_BASE                         (M0P_PERIPH_BASE + 0x00010000UL)
#define M0P_CTIOSEL03_BASE                     (M0P_PERIPH_BASE + 0x00025100UL)
#define M0P_CTIOSEL47_BASE                     (M0P_PERIPH_BASE + 0x00025300UL)
#define M0P_CT0_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025000UL)
#define M0P_CT1_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025040UL)
#define M0P_CT2_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025080UL)
#define M0P_CT3_PPG_BASE                       (M0P_PERIPH_BASE + 0x000250C0UL)
#define M0P_CT4_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025200UL)
#define M0P_CT5_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025240UL)
#define M0P_CT6_PPG_BASE                       (M0P_PERIPH_BASE + 0x00025280UL)
#define M0P_CT7_PPG_BASE                       (M0P_PERIPH_BASE + 0x000252C0UL)
#define M0P_CT0_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025000UL)
#define M0P_CT1_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025040UL)
#define M0P_CT2_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025080UL)
#define M0P_CT3_PWC_BASE                       (M0P_PERIPH_BASE + 0x000250C0UL)
#define M0P_CT4_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025200UL)
#define M0P_CT5_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025240UL)
#define M0P_CT6_PWC_BASE                       (M0P_PERIPH_BASE + 0x00025280UL)
#define M0P_CT7_PWC_BASE                       (M0P_PERIPH_BASE + 0x000252C0UL)
#define M0P_CT0_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025000UL)
#define M0P_CT1_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025040UL)
#define M0P_CT2_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025080UL)
#define M0P_CT3_PWM_BASE                       (M0P_PERIPH_BASE + 0x000250C0UL)
#define M0P_CT4_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025200UL)
#define M0P_CT5_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025240UL)
#define M0P_CT6_PWM_BASE                       (M0P_PERIPH_BASE + 0x00025280UL)
#define M0P_CT7_PWM_BASE                       (M0P_PERIPH_BASE + 0x000252C0UL)
#define M0P_CT0_RT_BASE                        (M0P_PERIPH_BASE + 0x00025000UL)
#define M0P_CT1_RT_BASE                        (M0P_PERIPH_BASE + 0x00025040UL)
#define M0P_CT2_RT_BASE                        (M0P_PERIPH_BASE + 0x00025080UL)
#define M0P_CT3_RT_BASE                        (M0P_PERIPH_BASE + 0x000250C0UL)
#define M0P_CT4_RT_BASE                        (M0P_PERIPH_BASE + 0x00025200UL)
#define M0P_CT5_RT_BASE                        (M0P_PERIPH_BASE + 0x00025240UL)
#define M0P_CT6_RT_BASE                        (M0P_PERIPH_BASE + 0x00025280UL)
#define M0P_CT7_RT_BASE                        (M0P_PERIPH_BASE + 0x000252C0UL)
#define M0P_DTIM1_BASE                         (M0P_PERIPH_BASE + 0x00015000UL)
#define M0P_DTIM2_BASE                         (M0P_PERIPH_BASE + 0x00015020UL)
#define M0P_EXTINT_BASE                        (M0P_PERIPH_BASE + 0x00030000UL)
#define M0P_FLASH_BASE                         (M0P_PERIPH_BASE + 0x00000000UL)
#define M0P_GPIO_BASE                          (M0P_PERIPH_BASE + 0x00033000UL)
#define M0P_HWWDT_BASE                         (M0P_PERIPH_BASE + 0x00011000UL)
#define M0P_IRQC_BASE                          (M0P_PERIPH_BASE + 0x00031000UL)
#define M0P_LCDC_BASE                          (M0P_PERIPH_BASE + 0x00032000UL)
#define M0P_MSC0_I2C_BASE                      (M0P_PERIPH_BASE + 0x00038000UL)
#define M0P_MSC1_I2C_BASE                      (M0P_PERIPH_BASE + 0x00038100UL)
#define M0P_MSC2_I2C_BASE                      (M0P_PERIPH_BASE + 0x00038200UL)
#define M0P_MSC4_I2C_BASE                      (M0P_PERIPH_BASE + 0x00037000UL)
#define M0P_MSC5_I2C_BASE                      (M0P_PERIPH_BASE + 0x00037100UL)
#define M0P_MSC6_I2C_BASE                      (M0P_PERIPH_BASE + 0x00037200UL)
#define M0P_MSC0_SPI_BASE                      (M0P_PERIPH_BASE + 0x00038000UL)
#define M0P_MSC1_SPI_BASE                      (M0P_PERIPH_BASE + 0x00038100UL)
#define M0P_MSC2_SPI_BASE                      (M0P_PERIPH_BASE + 0x00038200UL)
#define M0P_MSC4_SPI_BASE                      (M0P_PERIPH_BASE + 0x00037000UL)
#define M0P_MSC5_SPI_BASE                      (M0P_PERIPH_BASE + 0x00037100UL)
#define M0P_MSC6_SPI_BASE                      (M0P_PERIPH_BASE + 0x00037200UL)
#define M0P_MSC0_UART_BASE                     (M0P_PERIPH_BASE + 0x00038000UL)
#define M0P_MSC1_UART_BASE                     (M0P_PERIPH_BASE + 0x00038100UL)
#define M0P_MSC2_UART_BASE                     (M0P_PERIPH_BASE + 0x00038200UL)
#define M0P_MSC4_UART_BASE                     (M0P_PERIPH_BASE + 0x00037000UL)
#define M0P_MSC5_UART_BASE                     (M0P_PERIPH_BASE + 0x00037100UL)
#define M0P_MSC6_UART_BASE                     (M0P_PERIPH_BASE + 0x00037200UL)
#define M0P_OSC_BASE                           (M0P_PERIPH_BASE + 0x0002E000UL)
#define M0P_PARITY_BASE                        (M0P_PERIPH_BASE + 0x0003C000UL)
#define M0P_PCG_BASE                           (M0P_PERIPH_BASE + 0x0003C100UL)
#define M0P_RTC_BASE                           (M0P_PERIPH_BASE + 0x0003B000UL)
#define M0P_SBSSR_BASE                         (M0P_PERIPH_BASE + 0x00025F00UL)
#define M0P_SCI_BASE                           (M0P_PERIPH_BASE + 0x0003C800UL)
#define M0P_SWWDT_BASE                         (M0P_PERIPH_BASE + 0x00012000UL)
#define M0P_UID_BASE                           (M0P_PERIPH_BASE + 0x00000100UL)
#define M0P_VC_BASE                            (M0P_PERIPH_BASE + 0x0003C300UL)
#define M0P_WSUNIT_BASE                        (M0P_PERIPH_BASE + 0x00035000UL)


#define M0P_ADC                                ((M0P_ADC_TypeDef *)0x40027000UL)
#define M0P_AES                                ((M0P_AES_TypeDef *)0x4006B000UL)
#define M0P_BUZZER                             ((M0P_BUZZER_TypeDef *)0x4003C200UL)
#define M0P_CLOCK                              ((M0P_CLOCK_TypeDef *)0x40010000UL)
#define M0P_CTIOSEL03                          ((M0P_CTIOSEL03_TypeDef *)0x40025100UL)
#define M0P_CTIOSEL47                          ((M0P_CTIOSEL47_TypeDef *)0x40025300UL)
#define M0P_CT0_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025000UL)
#define M0P_CT1_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025040UL)
#define M0P_CT2_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025080UL)
#define M0P_CT3_PPG                            ((M0P_CT_PPG_TypeDef *)0x400250C0UL)
#define M0P_CT4_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025200UL)
#define M0P_CT5_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025240UL)
#define M0P_CT6_PPG                            ((M0P_CT_PPG_TypeDef *)0x40025280UL)
#define M0P_CT7_PPG                            ((M0P_CT_PPG_TypeDef *)0x400252C0UL)
#define M0P_CT0_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025000UL)
#define M0P_CT1_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025040UL)
#define M0P_CT2_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025080UL)
#define M0P_CT3_PWC                            ((M0P_CT_PWC_TypeDef *)0x400250C0UL)
#define M0P_CT4_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025200UL)
#define M0P_CT5_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025240UL)
#define M0P_CT6_PWC                            ((M0P_CT_PWC_TypeDef *)0x40025280UL)
#define M0P_CT7_PWC                            ((M0P_CT_PWC_TypeDef *)0x400252C0UL)
#define M0P_CT0_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025000UL)
#define M0P_CT1_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025040UL)
#define M0P_CT2_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025080UL)
#define M0P_CT3_PWM                            ((M0P_CT_PWM_TypeDef *)0x400250C0UL)
#define M0P_CT4_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025200UL)
#define M0P_CT5_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025240UL)
#define M0P_CT6_PWM                            ((M0P_CT_PWM_TypeDef *)0x40025280UL)
#define M0P_CT7_PWM                            ((M0P_CT_PWM_TypeDef *)0x400252C0UL)
#define M0P_CT0_RT                             ((M0P_CT_RT_TypeDef *)0x40025000UL)
#define M0P_CT1_RT                             ((M0P_CT_RT_TypeDef *)0x40025040UL)
#define M0P_CT2_RT                             ((M0P_CT_RT_TypeDef *)0x40025080UL)
#define M0P_CT3_RT                             ((M0P_CT_RT_TypeDef *)0x400250C0UL)
#define M0P_CT4_RT                             ((M0P_CT_RT_TypeDef *)0x40025200UL)
#define M0P_CT5_RT                             ((M0P_CT_RT_TypeDef *)0x40025240UL)
#define M0P_CT6_RT                             ((M0P_CT_RT_TypeDef *)0x40025280UL)
#define M0P_CT7_RT                             ((M0P_CT_RT_TypeDef *)0x400252C0UL)
#define M0P_DTIM1                              ((M0P_DTIM_TypeDef *)0x40015000UL)
#define M0P_DTIM2                              ((M0P_DTIM_TypeDef *)0x40015020UL)
#define M0P_EXTINT                             ((M0P_EXTINT_TypeDef *)0x40030000UL)
#define M0P_FASTIO                             ((M0P_FASTIO_TypeDef *)0xF8000000UL)
#define M0P_FLASH                              ((M0P_FLASH_TypeDef *)0x40000000UL)
#define M0P_GPIO                               ((M0P_GPIO_TypeDef *)0x40033000UL)
#define M0P_HWWDT                              ((M0P_HWWDT_TypeDef *)0x40011000UL)
#define M0P_IRQC                               ((M0P_IRQC_TypeDef *)0x40031000UL)
#define M0P_LCDC                               ((M0P_LCDC_TypeDef *)0x40032000UL)
#define M0P_MSC0_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40038000UL)
#define M0P_MSC1_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40038100UL)
#define M0P_MSC2_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40038200UL)
#define M0P_MSC4_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40037000UL)
#define M0P_MSC5_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40037100UL)
#define M0P_MSC6_I2C                           ((M0P_MSC_I2C_TypeDef *)0x40037200UL)
#define M0P_MSC0_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40038000UL)
#define M0P_MSC1_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40038100UL)
#define M0P_MSC2_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40038200UL)
#define M0P_MSC4_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40037000UL)
#define M0P_MSC5_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40037100UL)
#define M0P_MSC6_SPI                           ((M0P_MSC_SPI_TypeDef *)0x40037200UL)
#define M0P_MSC0_UART                          ((M0P_MSC_UART_TypeDef *)0x40038000UL)
#define M0P_MSC1_UART                          ((M0P_MSC_UART_TypeDef *)0x40038100UL)
#define M0P_MSC2_UART                          ((M0P_MSC_UART_TypeDef *)0x40038200UL)
#define M0P_MSC4_UART                          ((M0P_MSC_UART_TypeDef *)0x40037000UL)
#define M0P_MSC5_UART                          ((M0P_MSC_UART_TypeDef *)0x40037100UL)
#define M0P_MSC6_UART                          ((M0P_MSC_UART_TypeDef *)0x40037200UL)
#define M0P_OSC                                ((M0P_OSC_TypeDef *)0x4002E000UL)
#define M0P_PARITY                             ((M0P_PARITY_TypeDef *)0x4003C000UL)
#define M0P_PCG                                ((M0P_PCG_TypeDef *)0x4003C100UL)
#define M0P_RTC                                ((M0P_RTC_TypeDef *)0x4003B000UL)
#define M0P_SBSSR                              ((M0P_SBSSR_TypeDef *)0x40025F00UL)
#define M0P_SCI                                ((M0P_SCI_TypeDef *)0x4003C800UL)
#define M0P_SWWDT                              ((M0P_SWWDT_TypeDef *)0x40012000UL)
#define M0P_UID                                ((M0P_UID_TypeDef *)0x40000100UL)
#define M0P_VC                                 ((M0P_VC_TypeDef *)0x4003C300UL)
#define M0P_WSUNIT                             ((M0P_WSUNIT_TypeDef *)0x40035000UL)


#define bM0P_ADC_CTL1_ADC_EN                            *((volatile unsigned int*)(0x424E0000UL))
#define bM0P_ADC_CTL1_ADC_CLK_SEL0                      *((volatile unsigned int*)(0x424E0004UL))
#define bM0P_ADC_CTL1_ADC_CLK_SEL1                      *((volatile unsigned int*)(0x424E0008UL))
#define bM0P_ADC_CTL1_ADC_VREF                          *((volatile unsigned int*)(0x424E0018UL))
#define bM0P_ADC_CTL1_ADC_CHL_SEL0                      *((volatile unsigned int*)(0x424E0020UL))
#define bM0P_ADC_CTL1_ADC_CHL_SEL1                      *((volatile unsigned int*)(0x424E0024UL))
#define bM0P_ADC_CTL1_ADC_CHL_SEL2                      *((volatile unsigned int*)(0x424E0028UL))
#define bM0P_ADC_CTL1_ADC_CHL_SEL3                      *((volatile unsigned int*)(0x424E002CUL))
#define bM0P_ADC_CTL1_ADCIE                             *((volatile unsigned int*)(0x424E0040UL))
#define bM0P_ADC_CTL1_ADCIF                             *((volatile unsigned int*)(0x424E0044UL))
#define bM0P_ADC_CTL2_ADC_START                         *((volatile unsigned int*)(0x424E0080UL))
#define bM0P_ADC_CTL2_ADC_ALIGN                         *((volatile unsigned int*)(0x424E0088UL))
#define bM0P_ADC_CTL2_ADC_MODE                          *((volatile unsigned int*)(0x424E008CUL))
#define bM0P_ADC_CTL2_VINBUF_EN                         *((volatile unsigned int*)(0x424E0094UL))
#define bM0P_ADC_CTL2_ADC_SAMPLE_SEL0                   *((volatile unsigned int*)(0x424E0098UL))
#define bM0P_ADC_CTL2_ADC_SAMPLE_SEL1                   *((volatile unsigned int*)(0x424E009CUL))
#define bM0P_ADC_RESULT_RESULT0                         *((volatile unsigned int*)(0x424E0180UL))
#define bM0P_ADC_RESULT_RESULT1                         *((volatile unsigned int*)(0x424E0184UL))
#define bM0P_ADC_RESULT_RESULT2                         *((volatile unsigned int*)(0x424E0188UL))
#define bM0P_ADC_RESULT_RESULT3                         *((volatile unsigned int*)(0x424E018CUL))
#define bM0P_ADC_RESULT_RESULT4                         *((volatile unsigned int*)(0x424E0190UL))
#define bM0P_ADC_RESULT_RESULT5                         *((volatile unsigned int*)(0x424E0194UL))
#define bM0P_ADC_RESULT_RESULT6                         *((volatile unsigned int*)(0x424E0198UL))
#define bM0P_ADC_RESULT_RESULT7                         *((volatile unsigned int*)(0x424E019CUL))
#define bM0P_ADC_RESULT_RESULT8                         *((volatile unsigned int*)(0x424E01A0UL))
#define bM0P_ADC_RESULT_RESULT9                         *((volatile unsigned int*)(0x424E01A4UL))
#define bM0P_ADC_RESULT_RESULT10                        *((volatile unsigned int*)(0x424E01A8UL))
#define bM0P_ADC_RESULT_RESULT11                        *((volatile unsigned int*)(0x424E01ACUL))
#define bM0P_ADC_RESULT_RESULT12                        *((volatile unsigned int*)(0x424E01B0UL))
#define bM0P_ADC_RESULT_RESULT13                        *((volatile unsigned int*)(0x424E01B4UL))
#define bM0P_ADC_RESULT_RESULT14                        *((volatile unsigned int*)(0x424E01B8UL))
#define bM0P_ADC_RESULT_RESULT15                        *((volatile unsigned int*)(0x424E01BCUL))
#define bM0P_ADC_ADCMPIF_CMPIF                          *((volatile unsigned int*)(0x424E0200UL))
#define bM0P_ADC_ADCMPF_CMPF                            *((volatile unsigned int*)(0x424E0280UL))
#define bM0P_ADC_ADCMPCTL_CMPEN                         *((volatile unsigned int*)(0x424E0308UL))
#define bM0P_ADC_ADCMPCTL_CMPIE                         *((volatile unsigned int*)(0x424E030CUL))
#define bM0P_ADC_ADCMPCTL_CMPTRIG                       *((volatile unsigned int*)(0x424E0310UL))
#define bM0P_ADC_ADCMPCTL_CMPCNT0                       *((volatile unsigned int*)(0x424E0314UL))
#define bM0P_ADC_ADCMPCTL_CMPCNT1                       *((volatile unsigned int*)(0x424E0318UL))
#define bM0P_ADC_ADCMPCTL_CMPCNT2                       *((volatile unsigned int*)(0x424E031CUL))
#define bM0P_ADC_ADCMPCTL_CMPCNT_ST0                    *((volatile unsigned int*)(0x424E0334UL))
#define bM0P_ADC_ADCMPCTL_CMPCNT_ST1                    *((volatile unsigned int*)(0x424E0338UL))
#define bM0P_ADC_ADCMPCTL_CMPCNT_ST2                    *((volatile unsigned int*)(0x424E033CUL))
#define bM0P_ADC_ADCMPL_CDL0                            *((volatile unsigned int*)(0x424E0398UL))
#define bM0P_ADC_ADCMPL_CDL1                            *((volatile unsigned int*)(0x424E039CUL))
#define bM0P_ADC_ADCMPL_CDL2                            *((volatile unsigned int*)(0x424E03A0UL))
#define bM0P_ADC_ADCMPL_CDL3                            *((volatile unsigned int*)(0x424E03A4UL))
#define bM0P_ADC_ADCMPL_CDL4                            *((volatile unsigned int*)(0x424E03A8UL))
#define bM0P_ADC_ADCMPL_CDL5                            *((volatile unsigned int*)(0x424E03ACUL))
#define bM0P_ADC_ADCMPL_CDL6                            *((volatile unsigned int*)(0x424E03B0UL))
#define bM0P_ADC_ADCMPL_CDL7                            *((volatile unsigned int*)(0x424E03B4UL))
#define bM0P_ADC_ADCMPL_CDL8                            *((volatile unsigned int*)(0x424E03B8UL))
#define bM0P_ADC_ADCMPL_CDL9                            *((volatile unsigned int*)(0x424E03BCUL))
#define bM0P_ADC_ADCMPH_CDH0                            *((volatile unsigned int*)(0x424E03D8UL))
#define bM0P_ADC_ADCMPH_CDH1                            *((volatile unsigned int*)(0x424E03DCUL))
#define bM0P_ADC_ADCMPH_CDH2                            *((volatile unsigned int*)(0x424E03E0UL))
#define bM0P_ADC_ADCMPH_CDH3                            *((volatile unsigned int*)(0x424E03E4UL))
#define bM0P_ADC_ADCMPH_CDH4                            *((volatile unsigned int*)(0x424E03E8UL))
#define bM0P_ADC_ADCMPH_CDH5                            *((volatile unsigned int*)(0x424E03ECUL))
#define bM0P_ADC_ADCMPH_CDH6                            *((volatile unsigned int*)(0x424E03F0UL))
#define bM0P_ADC_ADCMPH_CDH7                            *((volatile unsigned int*)(0x424E03F4UL))
#define bM0P_ADC_ADCMPH_CDH8                            *((volatile unsigned int*)(0x424E03F8UL))
#define bM0P_ADC_ADCMPH_CDH9                            *((volatile unsigned int*)(0x424E03FCUL))
#define bM0P_AES_CON_START                              *((volatile unsigned int*)(0x42D60000UL))
#define bM0P_AES_CON_FUNC_SEL0                          *((volatile unsigned int*)(0x42D60004UL))
#define bM0P_AES_CON_FUNC_SEL1                          *((volatile unsigned int*)(0x42D60008UL))
#define bM0P_AES_CON_KEY_SEL0                           *((volatile unsigned int*)(0x42D6000CUL))
#define bM0P_AES_CON_KEY_SEL1                           *((volatile unsigned int*)(0x42D60010UL))
#define bM0P_AES_CON_STEP_EN                            *((volatile unsigned int*)(0x42D60014UL))
#define bM0P_AES_CON_DFA_EN                             *((volatile unsigned int*)(0x42D6001CUL))
#define bM0P_AES_CON_DFA_STA                            *((volatile unsigned int*)(0x42D60020UL))
#define bM0P_AES_CON_RAND_TEN                           *((volatile unsigned int*)(0x42D60024UL))
#define bM0P_AES_CON_DUMMY_EN                           *((volatile unsigned int*)(0x42D60028UL))
#define bM0P_AES_CON_DUMMY_SEL0                         *((volatile unsigned int*)(0x42D6002CUL))
#define bM0P_AES_CON_DUMMY_SEL1                         *((volatile unsigned int*)(0x42D60030UL))
#define bM0P_AES_DATA0_DATA00                           *((volatile unsigned int*)(0x42D60200UL))
#define bM0P_AES_DATA0_DATA01                           *((volatile unsigned int*)(0x42D60204UL))
#define bM0P_AES_DATA0_DATA02                           *((volatile unsigned int*)(0x42D60208UL))
#define bM0P_AES_DATA0_DATA03                           *((volatile unsigned int*)(0x42D6020CUL))
#define bM0P_AES_DATA0_DATA04                           *((volatile unsigned int*)(0x42D60210UL))
#define bM0P_AES_DATA0_DATA05                           *((volatile unsigned int*)(0x42D60214UL))
#define bM0P_AES_DATA0_DATA06                           *((volatile unsigned int*)(0x42D60218UL))
#define bM0P_AES_DATA0_DATA07                           *((volatile unsigned int*)(0x42D6021CUL))
#define bM0P_AES_DATA0_DATA08                           *((volatile unsigned int*)(0x42D60220UL))
#define bM0P_AES_DATA0_DATA09                           *((volatile unsigned int*)(0x42D60224UL))
#define bM0P_AES_DATA0_DATA010                          *((volatile unsigned int*)(0x42D60228UL))
#define bM0P_AES_DATA0_DATA011                          *((volatile unsigned int*)(0x42D6022CUL))
#define bM0P_AES_DATA0_DATA012                          *((volatile unsigned int*)(0x42D60230UL))
#define bM0P_AES_DATA0_DATA013                          *((volatile unsigned int*)(0x42D60234UL))
#define bM0P_AES_DATA0_DATA014                          *((volatile unsigned int*)(0x42D60238UL))
#define bM0P_AES_DATA0_DATA015                          *((volatile unsigned int*)(0x42D6023CUL))
#define bM0P_AES_DATA0_DATA016                          *((volatile unsigned int*)(0x42D60240UL))
#define bM0P_AES_DATA0_DATA017                          *((volatile unsigned int*)(0x42D60244UL))
#define bM0P_AES_DATA0_DATA018                          *((volatile unsigned int*)(0x42D60248UL))
#define bM0P_AES_DATA0_DATA019                          *((volatile unsigned int*)(0x42D6024CUL))
#define bM0P_AES_DATA0_DATA020                          *((volatile unsigned int*)(0x42D60250UL))
#define bM0P_AES_DATA0_DATA021                          *((volatile unsigned int*)(0x42D60254UL))
#define bM0P_AES_DATA0_DATA022                          *((volatile unsigned int*)(0x42D60258UL))
#define bM0P_AES_DATA0_DATA023                          *((volatile unsigned int*)(0x42D6025CUL))
#define bM0P_AES_DATA0_DATA024                          *((volatile unsigned int*)(0x42D60260UL))
#define bM0P_AES_DATA0_DATA025                          *((volatile unsigned int*)(0x42D60264UL))
#define bM0P_AES_DATA0_DATA026                          *((volatile unsigned int*)(0x42D60268UL))
#define bM0P_AES_DATA0_DATA027                          *((volatile unsigned int*)(0x42D6026CUL))
#define bM0P_AES_DATA0_DATA028                          *((volatile unsigned int*)(0x42D60270UL))
#define bM0P_AES_DATA0_DATA029                          *((volatile unsigned int*)(0x42D60274UL))
#define bM0P_AES_DATA0_DATA030                          *((volatile unsigned int*)(0x42D60278UL))
#define bM0P_AES_DATA0_DATA031                          *((volatile unsigned int*)(0x42D6027CUL))
#define bM0P_AES_DATA1_DATA10                           *((volatile unsigned int*)(0x42D60280UL))
#define bM0P_AES_DATA1_DATA11                           *((volatile unsigned int*)(0x42D60284UL))
#define bM0P_AES_DATA1_DATA12                           *((volatile unsigned int*)(0x42D60288UL))
#define bM0P_AES_DATA1_DATA13                           *((volatile unsigned int*)(0x42D6028CUL))
#define bM0P_AES_DATA1_DATA14                           *((volatile unsigned int*)(0x42D60290UL))
#define bM0P_AES_DATA1_DATA15                           *((volatile unsigned int*)(0x42D60294UL))
#define bM0P_AES_DATA1_DATA16                           *((volatile unsigned int*)(0x42D60298UL))
#define bM0P_AES_DATA1_DATA17                           *((volatile unsigned int*)(0x42D6029CUL))
#define bM0P_AES_DATA1_DATA18                           *((volatile unsigned int*)(0x42D602A0UL))
#define bM0P_AES_DATA1_DATA19                           *((volatile unsigned int*)(0x42D602A4UL))
#define bM0P_AES_DATA1_DATA110                          *((volatile unsigned int*)(0x42D602A8UL))
#define bM0P_AES_DATA1_DATA111                          *((volatile unsigned int*)(0x42D602ACUL))
#define bM0P_AES_DATA1_DATA112                          *((volatile unsigned int*)(0x42D602B0UL))
#define bM0P_AES_DATA1_DATA113                          *((volatile unsigned int*)(0x42D602B4UL))
#define bM0P_AES_DATA1_DATA114                          *((volatile unsigned int*)(0x42D602B8UL))
#define bM0P_AES_DATA1_DATA115                          *((volatile unsigned int*)(0x42D602BCUL))
#define bM0P_AES_DATA1_DATA116                          *((volatile unsigned int*)(0x42D602C0UL))
#define bM0P_AES_DATA1_DATA117                          *((volatile unsigned int*)(0x42D602C4UL))
#define bM0P_AES_DATA1_DATA118                          *((volatile unsigned int*)(0x42D602C8UL))
#define bM0P_AES_DATA1_DATA119                          *((volatile unsigned int*)(0x42D602CCUL))
#define bM0P_AES_DATA1_DATA120                          *((volatile unsigned int*)(0x42D602D0UL))
#define bM0P_AES_DATA1_DATA121                          *((volatile unsigned int*)(0x42D602D4UL))
#define bM0P_AES_DATA1_DATA122                          *((volatile unsigned int*)(0x42D602D8UL))
#define bM0P_AES_DATA1_DATA123                          *((volatile unsigned int*)(0x42D602DCUL))
#define bM0P_AES_DATA1_DATA124                          *((volatile unsigned int*)(0x42D602E0UL))
#define bM0P_AES_DATA1_DATA125                          *((volatile unsigned int*)(0x42D602E4UL))
#define bM0P_AES_DATA1_DATA126                          *((volatile unsigned int*)(0x42D602E8UL))
#define bM0P_AES_DATA1_DATA127                          *((volatile unsigned int*)(0x42D602ECUL))
#define bM0P_AES_DATA1_DATA128                          *((volatile unsigned int*)(0x42D602F0UL))
#define bM0P_AES_DATA1_DATA129                          *((volatile unsigned int*)(0x42D602F4UL))
#define bM0P_AES_DATA1_DATA130                          *((volatile unsigned int*)(0x42D602F8UL))
#define bM0P_AES_DATA1_DATA131                          *((volatile unsigned int*)(0x42D602FCUL))
#define bM0P_AES_DATA2_DATA20                           *((volatile unsigned int*)(0x42D60300UL))
#define bM0P_AES_DATA2_DATA21                           *((volatile unsigned int*)(0x42D60304UL))
#define bM0P_AES_DATA2_DATA22                           *((volatile unsigned int*)(0x42D60308UL))
#define bM0P_AES_DATA2_DATA23                           *((volatile unsigned int*)(0x42D6030CUL))
#define bM0P_AES_DATA2_DATA24                           *((volatile unsigned int*)(0x42D60310UL))
#define bM0P_AES_DATA2_DATA25                           *((volatile unsigned int*)(0x42D60314UL))
#define bM0P_AES_DATA2_DATA26                           *((volatile unsigned int*)(0x42D60318UL))
#define bM0P_AES_DATA2_DATA27                           *((volatile unsigned int*)(0x42D6031CUL))
#define bM0P_AES_DATA2_DATA28                           *((volatile unsigned int*)(0x42D60320UL))
#define bM0P_AES_DATA2_DATA29                           *((volatile unsigned int*)(0x42D60324UL))
#define bM0P_AES_DATA2_DATA210                          *((volatile unsigned int*)(0x42D60328UL))
#define bM0P_AES_DATA2_DATA211                          *((volatile unsigned int*)(0x42D6032CUL))
#define bM0P_AES_DATA2_DATA212                          *((volatile unsigned int*)(0x42D60330UL))
#define bM0P_AES_DATA2_DATA213                          *((volatile unsigned int*)(0x42D60334UL))
#define bM0P_AES_DATA2_DATA214                          *((volatile unsigned int*)(0x42D60338UL))
#define bM0P_AES_DATA2_DATA215                          *((volatile unsigned int*)(0x42D6033CUL))
#define bM0P_AES_DATA2_DATA216                          *((volatile unsigned int*)(0x42D60340UL))
#define bM0P_AES_DATA2_DATA217                          *((volatile unsigned int*)(0x42D60344UL))
#define bM0P_AES_DATA2_DATA218                          *((volatile unsigned int*)(0x42D60348UL))
#define bM0P_AES_DATA2_DATA219                          *((volatile unsigned int*)(0x42D6034CUL))
#define bM0P_AES_DATA2_DATA220                          *((volatile unsigned int*)(0x42D60350UL))
#define bM0P_AES_DATA2_DATA221                          *((volatile unsigned int*)(0x42D60354UL))
#define bM0P_AES_DATA2_DATA222                          *((volatile unsigned int*)(0x42D60358UL))
#define bM0P_AES_DATA2_DATA223                          *((volatile unsigned int*)(0x42D6035CUL))
#define bM0P_AES_DATA2_DATA224                          *((volatile unsigned int*)(0x42D60360UL))
#define bM0P_AES_DATA2_DATA225                          *((volatile unsigned int*)(0x42D60364UL))
#define bM0P_AES_DATA2_DATA226                          *((volatile unsigned int*)(0x42D60368UL))
#define bM0P_AES_DATA2_DATA227                          *((volatile unsigned int*)(0x42D6036CUL))
#define bM0P_AES_DATA2_DATA228                          *((volatile unsigned int*)(0x42D60370UL))
#define bM0P_AES_DATA2_DATA229                          *((volatile unsigned int*)(0x42D60374UL))
#define bM0P_AES_DATA2_DATA230                          *((volatile unsigned int*)(0x42D60378UL))
#define bM0P_AES_DATA2_DATA231                          *((volatile unsigned int*)(0x42D6037CUL))
#define bM0P_AES_DATA3_DATA30                           *((volatile unsigned int*)(0x42D60380UL))
#define bM0P_AES_DATA3_DATA31                           *((volatile unsigned int*)(0x42D60384UL))
#define bM0P_AES_DATA3_DATA32                           *((volatile unsigned int*)(0x42D60388UL))
#define bM0P_AES_DATA3_DATA33                           *((volatile unsigned int*)(0x42D6038CUL))
#define bM0P_AES_DATA3_DATA34                           *((volatile unsigned int*)(0x42D60390UL))
#define bM0P_AES_DATA3_DATA35                           *((volatile unsigned int*)(0x42D60394UL))
#define bM0P_AES_DATA3_DATA36                           *((volatile unsigned int*)(0x42D60398UL))
#define bM0P_AES_DATA3_DATA37                           *((volatile unsigned int*)(0x42D6039CUL))
#define bM0P_AES_DATA3_DATA38                           *((volatile unsigned int*)(0x42D603A0UL))
#define bM0P_AES_DATA3_DATA39                           *((volatile unsigned int*)(0x42D603A4UL))
#define bM0P_AES_DATA3_DATA310                          *((volatile unsigned int*)(0x42D603A8UL))
#define bM0P_AES_DATA3_DATA311                          *((volatile unsigned int*)(0x42D603ACUL))
#define bM0P_AES_DATA3_DATA312                          *((volatile unsigned int*)(0x42D603B0UL))
#define bM0P_AES_DATA3_DATA313                          *((volatile unsigned int*)(0x42D603B4UL))
#define bM0P_AES_DATA3_DATA314                          *((volatile unsigned int*)(0x42D603B8UL))
#define bM0P_AES_DATA3_DATA315                          *((volatile unsigned int*)(0x42D603BCUL))
#define bM0P_AES_DATA3_DATA316                          *((volatile unsigned int*)(0x42D603C0UL))
#define bM0P_AES_DATA3_DATA317                          *((volatile unsigned int*)(0x42D603C4UL))
#define bM0P_AES_DATA3_DATA318                          *((volatile unsigned int*)(0x42D603C8UL))
#define bM0P_AES_DATA3_DATA319                          *((volatile unsigned int*)(0x42D603CCUL))
#define bM0P_AES_DATA3_DATA320                          *((volatile unsigned int*)(0x42D603D0UL))
#define bM0P_AES_DATA3_DATA321                          *((volatile unsigned int*)(0x42D603D4UL))
#define bM0P_AES_DATA3_DATA322                          *((volatile unsigned int*)(0x42D603D8UL))
#define bM0P_AES_DATA3_DATA323                          *((volatile unsigned int*)(0x42D603DCUL))
#define bM0P_AES_DATA3_DATA324                          *((volatile unsigned int*)(0x42D603E0UL))
#define bM0P_AES_DATA3_DATA325                          *((volatile unsigned int*)(0x42D603E4UL))
#define bM0P_AES_DATA3_DATA326                          *((volatile unsigned int*)(0x42D603E8UL))
#define bM0P_AES_DATA3_DATA327                          *((volatile unsigned int*)(0x42D603ECUL))
#define bM0P_AES_DATA3_DATA328                          *((volatile unsigned int*)(0x42D603F0UL))
#define bM0P_AES_DATA3_DATA329                          *((volatile unsigned int*)(0x42D603F4UL))
#define bM0P_AES_DATA3_DATA330                          *((volatile unsigned int*)(0x42D603F8UL))
#define bM0P_AES_DATA3_DATA331                          *((volatile unsigned int*)(0x42D603FCUL))
#define bM0P_AES_KEY0_KEY00                             *((volatile unsigned int*)(0x42D60400UL))
#define bM0P_AES_KEY0_KEY01                             *((volatile unsigned int*)(0x42D60404UL))
#define bM0P_AES_KEY0_KEY02                             *((volatile unsigned int*)(0x42D60408UL))
#define bM0P_AES_KEY0_KEY03                             *((volatile unsigned int*)(0x42D6040CUL))
#define bM0P_AES_KEY0_KEY04                             *((volatile unsigned int*)(0x42D60410UL))
#define bM0P_AES_KEY0_KEY05                             *((volatile unsigned int*)(0x42D60414UL))
#define bM0P_AES_KEY0_KEY06                             *((volatile unsigned int*)(0x42D60418UL))
#define bM0P_AES_KEY0_KEY07                             *((volatile unsigned int*)(0x42D6041CUL))
#define bM0P_AES_KEY0_KEY08                             *((volatile unsigned int*)(0x42D60420UL))
#define bM0P_AES_KEY0_KEY09                             *((volatile unsigned int*)(0x42D60424UL))
#define bM0P_AES_KEY0_KEY010                            *((volatile unsigned int*)(0x42D60428UL))
#define bM0P_AES_KEY0_KEY011                            *((volatile unsigned int*)(0x42D6042CUL))
#define bM0P_AES_KEY0_KEY012                            *((volatile unsigned int*)(0x42D60430UL))
#define bM0P_AES_KEY0_KEY013                            *((volatile unsigned int*)(0x42D60434UL))
#define bM0P_AES_KEY0_KEY014                            *((volatile unsigned int*)(0x42D60438UL))
#define bM0P_AES_KEY0_KEY015                            *((volatile unsigned int*)(0x42D6043CUL))
#define bM0P_AES_KEY0_KEY016                            *((volatile unsigned int*)(0x42D60440UL))
#define bM0P_AES_KEY0_KEY017                            *((volatile unsigned int*)(0x42D60444UL))
#define bM0P_AES_KEY0_KEY018                            *((volatile unsigned int*)(0x42D60448UL))
#define bM0P_AES_KEY0_KEY019                            *((volatile unsigned int*)(0x42D6044CUL))
#define bM0P_AES_KEY0_KEY020                            *((volatile unsigned int*)(0x42D60450UL))
#define bM0P_AES_KEY0_KEY021                            *((volatile unsigned int*)(0x42D60454UL))
#define bM0P_AES_KEY0_KEY022                            *((volatile unsigned int*)(0x42D60458UL))
#define bM0P_AES_KEY0_KEY023                            *((volatile unsigned int*)(0x42D6045CUL))
#define bM0P_AES_KEY0_KEY024                            *((volatile unsigned int*)(0x42D60460UL))
#define bM0P_AES_KEY0_KEY025                            *((volatile unsigned int*)(0x42D60464UL))
#define bM0P_AES_KEY0_KEY026                            *((volatile unsigned int*)(0x42D60468UL))
#define bM0P_AES_KEY0_KEY027                            *((volatile unsigned int*)(0x42D6046CUL))
#define bM0P_AES_KEY0_KEY028                            *((volatile unsigned int*)(0x42D60470UL))
#define bM0P_AES_KEY0_KEY029                            *((volatile unsigned int*)(0x42D60474UL))
#define bM0P_AES_KEY0_KEY030                            *((volatile unsigned int*)(0x42D60478UL))
#define bM0P_AES_KEY0_KEY031                            *((volatile unsigned int*)(0x42D6047CUL))
#define bM0P_AES_KEY1_KEY10                             *((volatile unsigned int*)(0x42D60480UL))
#define bM0P_AES_KEY1_KEY11                             *((volatile unsigned int*)(0x42D60484UL))
#define bM0P_AES_KEY1_KEY12                             *((volatile unsigned int*)(0x42D60488UL))
#define bM0P_AES_KEY1_KEY13                             *((volatile unsigned int*)(0x42D6048CUL))
#define bM0P_AES_KEY1_KEY14                             *((volatile unsigned int*)(0x42D60490UL))
#define bM0P_AES_KEY1_KEY15                             *((volatile unsigned int*)(0x42D60494UL))
#define bM0P_AES_KEY1_KEY16                             *((volatile unsigned int*)(0x42D60498UL))
#define bM0P_AES_KEY1_KEY17                             *((volatile unsigned int*)(0x42D6049CUL))
#define bM0P_AES_KEY1_KEY18                             *((volatile unsigned int*)(0x42D604A0UL))
#define bM0P_AES_KEY1_KEY19                             *((volatile unsigned int*)(0x42D604A4UL))
#define bM0P_AES_KEY1_KEY110                            *((volatile unsigned int*)(0x42D604A8UL))
#define bM0P_AES_KEY1_KEY111                            *((volatile unsigned int*)(0x42D604ACUL))
#define bM0P_AES_KEY1_KEY112                            *((volatile unsigned int*)(0x42D604B0UL))
#define bM0P_AES_KEY1_KEY113                            *((volatile unsigned int*)(0x42D604B4UL))
#define bM0P_AES_KEY1_KEY114                            *((volatile unsigned int*)(0x42D604B8UL))
#define bM0P_AES_KEY1_KEY115                            *((volatile unsigned int*)(0x42D604BCUL))
#define bM0P_AES_KEY1_KEY116                            *((volatile unsigned int*)(0x42D604C0UL))
#define bM0P_AES_KEY1_KEY117                            *((volatile unsigned int*)(0x42D604C4UL))
#define bM0P_AES_KEY1_KEY118                            *((volatile unsigned int*)(0x42D604C8UL))
#define bM0P_AES_KEY1_KEY119                            *((volatile unsigned int*)(0x42D604CCUL))
#define bM0P_AES_KEY1_KEY120                            *((volatile unsigned int*)(0x42D604D0UL))
#define bM0P_AES_KEY1_KEY121                            *((volatile unsigned int*)(0x42D604D4UL))
#define bM0P_AES_KEY1_KEY122                            *((volatile unsigned int*)(0x42D604D8UL))
#define bM0P_AES_KEY1_KEY123                            *((volatile unsigned int*)(0x42D604DCUL))
#define bM0P_AES_KEY1_KEY124                            *((volatile unsigned int*)(0x42D604E0UL))
#define bM0P_AES_KEY1_KEY125                            *((volatile unsigned int*)(0x42D604E4UL))
#define bM0P_AES_KEY1_KEY126                            *((volatile unsigned int*)(0x42D604E8UL))
#define bM0P_AES_KEY1_KEY127                            *((volatile unsigned int*)(0x42D604ECUL))
#define bM0P_AES_KEY1_KEY128                            *((volatile unsigned int*)(0x42D604F0UL))
#define bM0P_AES_KEY1_KEY129                            *((volatile unsigned int*)(0x42D604F4UL))
#define bM0P_AES_KEY1_KEY130                            *((volatile unsigned int*)(0x42D604F8UL))
#define bM0P_AES_KEY1_KEY131                            *((volatile unsigned int*)(0x42D604FCUL))
#define bM0P_AES_KEY2_KEY20                             *((volatile unsigned int*)(0x42D60500UL))
#define bM0P_AES_KEY2_KEY21                             *((volatile unsigned int*)(0x42D60504UL))
#define bM0P_AES_KEY2_KEY22                             *((volatile unsigned int*)(0x42D60508UL))
#define bM0P_AES_KEY2_KEY23                             *((volatile unsigned int*)(0x42D6050CUL))
#define bM0P_AES_KEY2_KEY24                             *((volatile unsigned int*)(0x42D60510UL))
#define bM0P_AES_KEY2_KEY25                             *((volatile unsigned int*)(0x42D60514UL))
#define bM0P_AES_KEY2_KEY26                             *((volatile unsigned int*)(0x42D60518UL))
#define bM0P_AES_KEY2_KEY27                             *((volatile unsigned int*)(0x42D6051CUL))
#define bM0P_AES_KEY2_KEY28                             *((volatile unsigned int*)(0x42D60520UL))
#define bM0P_AES_KEY2_KEY29                             *((volatile unsigned int*)(0x42D60524UL))
#define bM0P_AES_KEY2_KEY210                            *((volatile unsigned int*)(0x42D60528UL))
#define bM0P_AES_KEY2_KEY211                            *((volatile unsigned int*)(0x42D6052CUL))
#define bM0P_AES_KEY2_KEY212                            *((volatile unsigned int*)(0x42D60530UL))
#define bM0P_AES_KEY2_KEY213                            *((volatile unsigned int*)(0x42D60534UL))
#define bM0P_AES_KEY2_KEY214                            *((volatile unsigned int*)(0x42D60538UL))
#define bM0P_AES_KEY2_KEY215                            *((volatile unsigned int*)(0x42D6053CUL))
#define bM0P_AES_KEY2_KEY216                            *((volatile unsigned int*)(0x42D60540UL))
#define bM0P_AES_KEY2_KEY217                            *((volatile unsigned int*)(0x42D60544UL))
#define bM0P_AES_KEY2_KEY218                            *((volatile unsigned int*)(0x42D60548UL))
#define bM0P_AES_KEY2_KEY219                            *((volatile unsigned int*)(0x42D6054CUL))
#define bM0P_AES_KEY2_KEY220                            *((volatile unsigned int*)(0x42D60550UL))
#define bM0P_AES_KEY2_KEY221                            *((volatile unsigned int*)(0x42D60554UL))
#define bM0P_AES_KEY2_KEY222                            *((volatile unsigned int*)(0x42D60558UL))
#define bM0P_AES_KEY2_KEY223                            *((volatile unsigned int*)(0x42D6055CUL))
#define bM0P_AES_KEY2_KEY224                            *((volatile unsigned int*)(0x42D60560UL))
#define bM0P_AES_KEY2_KEY225                            *((volatile unsigned int*)(0x42D60564UL))
#define bM0P_AES_KEY2_KEY226                            *((volatile unsigned int*)(0x42D60568UL))
#define bM0P_AES_KEY2_KEY227                            *((volatile unsigned int*)(0x42D6056CUL))
#define bM0P_AES_KEY2_KEY228                            *((volatile unsigned int*)(0x42D60570UL))
#define bM0P_AES_KEY2_KEY229                            *((volatile unsigned int*)(0x42D60574UL))
#define bM0P_AES_KEY2_KEY230                            *((volatile unsigned int*)(0x42D60578UL))
#define bM0P_AES_KEY2_KEY231                            *((volatile unsigned int*)(0x42D6057CUL))
#define bM0P_AES_KEY3_KEY30                             *((volatile unsigned int*)(0x42D60580UL))
#define bM0P_AES_KEY3_KEY31                             *((volatile unsigned int*)(0x42D60584UL))
#define bM0P_AES_KEY3_KEY32                             *((volatile unsigned int*)(0x42D60588UL))
#define bM0P_AES_KEY3_KEY33                             *((volatile unsigned int*)(0x42D6058CUL))
#define bM0P_AES_KEY3_KEY34                             *((volatile unsigned int*)(0x42D60590UL))
#define bM0P_AES_KEY3_KEY35                             *((volatile unsigned int*)(0x42D60594UL))
#define bM0P_AES_KEY3_KEY36                             *((volatile unsigned int*)(0x42D60598UL))
#define bM0P_AES_KEY3_KEY37                             *((volatile unsigned int*)(0x42D6059CUL))
#define bM0P_AES_KEY3_KEY38                             *((volatile unsigned int*)(0x42D605A0UL))
#define bM0P_AES_KEY3_KEY39                             *((volatile unsigned int*)(0x42D605A4UL))
#define bM0P_AES_KEY3_KEY310                            *((volatile unsigned int*)(0x42D605A8UL))
#define bM0P_AES_KEY3_KEY311                            *((volatile unsigned int*)(0x42D605ACUL))
#define bM0P_AES_KEY3_KEY312                            *((volatile unsigned int*)(0x42D605B0UL))
#define bM0P_AES_KEY3_KEY313                            *((volatile unsigned int*)(0x42D605B4UL))
#define bM0P_AES_KEY3_KEY314                            *((volatile unsigned int*)(0x42D605B8UL))
#define bM0P_AES_KEY3_KEY315                            *((volatile unsigned int*)(0x42D605BCUL))
#define bM0P_AES_KEY3_KEY316                            *((volatile unsigned int*)(0x42D605C0UL))
#define bM0P_AES_KEY3_KEY317                            *((volatile unsigned int*)(0x42D605C4UL))
#define bM0P_AES_KEY3_KEY318                            *((volatile unsigned int*)(0x42D605C8UL))
#define bM0P_AES_KEY3_KEY319                            *((volatile unsigned int*)(0x42D605CCUL))
#define bM0P_AES_KEY3_KEY320                            *((volatile unsigned int*)(0x42D605D0UL))
#define bM0P_AES_KEY3_KEY321                            *((volatile unsigned int*)(0x42D605D4UL))
#define bM0P_AES_KEY3_KEY322                            *((volatile unsigned int*)(0x42D605D8UL))
#define bM0P_AES_KEY3_KEY323                            *((volatile unsigned int*)(0x42D605DCUL))
#define bM0P_AES_KEY3_KEY324                            *((volatile unsigned int*)(0x42D605E0UL))
#define bM0P_AES_KEY3_KEY325                            *((volatile unsigned int*)(0x42D605E4UL))
#define bM0P_AES_KEY3_KEY326                            *((volatile unsigned int*)(0x42D605E8UL))
#define bM0P_AES_KEY3_KEY327                            *((volatile unsigned int*)(0x42D605ECUL))
#define bM0P_AES_KEY3_KEY328                            *((volatile unsigned int*)(0x42D605F0UL))
#define bM0P_AES_KEY3_KEY329                            *((volatile unsigned int*)(0x42D605F4UL))
#define bM0P_AES_KEY3_KEY330                            *((volatile unsigned int*)(0x42D605F8UL))
#define bM0P_AES_KEY3_KEY331                            *((volatile unsigned int*)(0x42D605FCUL))
#define bM0P_AES_KEY4_KEY40                             *((volatile unsigned int*)(0x42D60600UL))
#define bM0P_AES_KEY4_KEY41                             *((volatile unsigned int*)(0x42D60604UL))
#define bM0P_AES_KEY4_KEY42                             *((volatile unsigned int*)(0x42D60608UL))
#define bM0P_AES_KEY4_KEY43                             *((volatile unsigned int*)(0x42D6060CUL))
#define bM0P_AES_KEY4_KEY44                             *((volatile unsigned int*)(0x42D60610UL))
#define bM0P_AES_KEY4_KEY45                             *((volatile unsigned int*)(0x42D60614UL))
#define bM0P_AES_KEY4_KEY46                             *((volatile unsigned int*)(0x42D60618UL))
#define bM0P_AES_KEY4_KEY47                             *((volatile unsigned int*)(0x42D6061CUL))
#define bM0P_AES_KEY4_KEY48                             *((volatile unsigned int*)(0x42D60620UL))
#define bM0P_AES_KEY4_KEY49                             *((volatile unsigned int*)(0x42D60624UL))
#define bM0P_AES_KEY4_KEY410                            *((volatile unsigned int*)(0x42D60628UL))
#define bM0P_AES_KEY4_KEY411                            *((volatile unsigned int*)(0x42D6062CUL))
#define bM0P_AES_KEY4_KEY412                            *((volatile unsigned int*)(0x42D60630UL))
#define bM0P_AES_KEY4_KEY413                            *((volatile unsigned int*)(0x42D60634UL))
#define bM0P_AES_KEY4_KEY414                            *((volatile unsigned int*)(0x42D60638UL))
#define bM0P_AES_KEY4_KEY415                            *((volatile unsigned int*)(0x42D6063CUL))
#define bM0P_AES_KEY4_KEY416                            *((volatile unsigned int*)(0x42D60640UL))
#define bM0P_AES_KEY4_KEY417                            *((volatile unsigned int*)(0x42D60644UL))
#define bM0P_AES_KEY4_KEY418                            *((volatile unsigned int*)(0x42D60648UL))
#define bM0P_AES_KEY4_KEY419                            *((volatile unsigned int*)(0x42D6064CUL))
#define bM0P_AES_KEY4_KEY420                            *((volatile unsigned int*)(0x42D60650UL))
#define bM0P_AES_KEY4_KEY421                            *((volatile unsigned int*)(0x42D60654UL))
#define bM0P_AES_KEY4_KEY422                            *((volatile unsigned int*)(0x42D60658UL))
#define bM0P_AES_KEY4_KEY423                            *((volatile unsigned int*)(0x42D6065CUL))
#define bM0P_AES_KEY4_KEY424                            *((volatile unsigned int*)(0x42D60660UL))
#define bM0P_AES_KEY4_KEY425                            *((volatile unsigned int*)(0x42D60664UL))
#define bM0P_AES_KEY4_KEY426                            *((volatile unsigned int*)(0x42D60668UL))
#define bM0P_AES_KEY4_KEY427                            *((volatile unsigned int*)(0x42D6066CUL))
#define bM0P_AES_KEY4_KEY428                            *((volatile unsigned int*)(0x42D60670UL))
#define bM0P_AES_KEY4_KEY429                            *((volatile unsigned int*)(0x42D60674UL))
#define bM0P_AES_KEY4_KEY430                            *((volatile unsigned int*)(0x42D60678UL))
#define bM0P_AES_KEY4_KEY431                            *((volatile unsigned int*)(0x42D6067CUL))
#define bM0P_AES_KEY5_KEY50                             *((volatile unsigned int*)(0x42D60680UL))
#define bM0P_AES_KEY5_KEY51                             *((volatile unsigned int*)(0x42D60684UL))
#define bM0P_AES_KEY5_KEY52                             *((volatile unsigned int*)(0x42D60688UL))
#define bM0P_AES_KEY5_KEY53                             *((volatile unsigned int*)(0x42D6068CUL))
#define bM0P_AES_KEY5_KEY54                             *((volatile unsigned int*)(0x42D60690UL))
#define bM0P_AES_KEY5_KEY55                             *((volatile unsigned int*)(0x42D60694UL))
#define bM0P_AES_KEY5_KEY56                             *((volatile unsigned int*)(0x42D60698UL))
#define bM0P_AES_KEY5_KEY57                             *((volatile unsigned int*)(0x42D6069CUL))
#define bM0P_AES_KEY5_KEY58                             *((volatile unsigned int*)(0x42D606A0UL))
#define bM0P_AES_KEY5_KEY59                             *((volatile unsigned int*)(0x42D606A4UL))
#define bM0P_AES_KEY5_KEY510                            *((volatile unsigned int*)(0x42D606A8UL))
#define bM0P_AES_KEY5_KEY511                            *((volatile unsigned int*)(0x42D606ACUL))
#define bM0P_AES_KEY5_KEY512                            *((volatile unsigned int*)(0x42D606B0UL))
#define bM0P_AES_KEY5_KEY513                            *((volatile unsigned int*)(0x42D606B4UL))
#define bM0P_AES_KEY5_KEY514                            *((volatile unsigned int*)(0x42D606B8UL))
#define bM0P_AES_KEY5_KEY515                            *((volatile unsigned int*)(0x42D606BCUL))
#define bM0P_AES_KEY5_KEY516                            *((volatile unsigned int*)(0x42D606C0UL))
#define bM0P_AES_KEY5_KEY517                            *((volatile unsigned int*)(0x42D606C4UL))
#define bM0P_AES_KEY5_KEY518                            *((volatile unsigned int*)(0x42D606C8UL))
#define bM0P_AES_KEY5_KEY519                            *((volatile unsigned int*)(0x42D606CCUL))
#define bM0P_AES_KEY5_KEY520                            *((volatile unsigned int*)(0x42D606D0UL))
#define bM0P_AES_KEY5_KEY521                            *((volatile unsigned int*)(0x42D606D4UL))
#define bM0P_AES_KEY5_KEY522                            *((volatile unsigned int*)(0x42D606D8UL))
#define bM0P_AES_KEY5_KEY523                            *((volatile unsigned int*)(0x42D606DCUL))
#define bM0P_AES_KEY5_KEY524                            *((volatile unsigned int*)(0x42D606E0UL))
#define bM0P_AES_KEY5_KEY525                            *((volatile unsigned int*)(0x42D606E4UL))
#define bM0P_AES_KEY5_KEY526                            *((volatile unsigned int*)(0x42D606E8UL))
#define bM0P_AES_KEY5_KEY527                            *((volatile unsigned int*)(0x42D606ECUL))
#define bM0P_AES_KEY5_KEY528                            *((volatile unsigned int*)(0x42D606F0UL))
#define bM0P_AES_KEY5_KEY529                            *((volatile unsigned int*)(0x42D606F4UL))
#define bM0P_AES_KEY5_KEY530                            *((volatile unsigned int*)(0x42D606F8UL))
#define bM0P_AES_KEY5_KEY531                            *((volatile unsigned int*)(0x42D606FCUL))
#define bM0P_AES_KEY6_KEY60                             *((volatile unsigned int*)(0x42D60700UL))
#define bM0P_AES_KEY6_KEY61                             *((volatile unsigned int*)(0x42D60704UL))
#define bM0P_AES_KEY6_KEY62                             *((volatile unsigned int*)(0x42D60708UL))
#define bM0P_AES_KEY6_KEY63                             *((volatile unsigned int*)(0x42D6070CUL))
#define bM0P_AES_KEY6_KEY64                             *((volatile unsigned int*)(0x42D60710UL))
#define bM0P_AES_KEY6_KEY65                             *((volatile unsigned int*)(0x42D60714UL))
#define bM0P_AES_KEY6_KEY66                             *((volatile unsigned int*)(0x42D60718UL))
#define bM0P_AES_KEY6_KEY67                             *((volatile unsigned int*)(0x42D6071CUL))
#define bM0P_AES_KEY6_KEY68                             *((volatile unsigned int*)(0x42D60720UL))
#define bM0P_AES_KEY6_KEY69                             *((volatile unsigned int*)(0x42D60724UL))
#define bM0P_AES_KEY6_KEY610                            *((volatile unsigned int*)(0x42D60728UL))
#define bM0P_AES_KEY6_KEY611                            *((volatile unsigned int*)(0x42D6072CUL))
#define bM0P_AES_KEY6_KEY612                            *((volatile unsigned int*)(0x42D60730UL))
#define bM0P_AES_KEY6_KEY613                            *((volatile unsigned int*)(0x42D60734UL))
#define bM0P_AES_KEY6_KEY614                            *((volatile unsigned int*)(0x42D60738UL))
#define bM0P_AES_KEY6_KEY615                            *((volatile unsigned int*)(0x42D6073CUL))
#define bM0P_AES_KEY6_KEY616                            *((volatile unsigned int*)(0x42D60740UL))
#define bM0P_AES_KEY6_KEY617                            *((volatile unsigned int*)(0x42D60744UL))
#define bM0P_AES_KEY6_KEY618                            *((volatile unsigned int*)(0x42D60748UL))
#define bM0P_AES_KEY6_KEY619                            *((volatile unsigned int*)(0x42D6074CUL))
#define bM0P_AES_KEY6_KEY620                            *((volatile unsigned int*)(0x42D60750UL))
#define bM0P_AES_KEY6_KEY621                            *((volatile unsigned int*)(0x42D60754UL))
#define bM0P_AES_KEY6_KEY622                            *((volatile unsigned int*)(0x42D60758UL))
#define bM0P_AES_KEY6_KEY623                            *((volatile unsigned int*)(0x42D6075CUL))
#define bM0P_AES_KEY6_KEY624                            *((volatile unsigned int*)(0x42D60760UL))
#define bM0P_AES_KEY6_KEY625                            *((volatile unsigned int*)(0x42D60764UL))
#define bM0P_AES_KEY6_KEY626                            *((volatile unsigned int*)(0x42D60768UL))
#define bM0P_AES_KEY6_KEY627                            *((volatile unsigned int*)(0x42D6076CUL))
#define bM0P_AES_KEY6_KEY628                            *((volatile unsigned int*)(0x42D60770UL))
#define bM0P_AES_KEY6_KEY629                            *((volatile unsigned int*)(0x42D60774UL))
#define bM0P_AES_KEY6_KEY630                            *((volatile unsigned int*)(0x42D60778UL))
#define bM0P_AES_KEY6_KEY631                            *((volatile unsigned int*)(0x42D6077CUL))
#define bM0P_AES_KEY7_KEY70                             *((volatile unsigned int*)(0x42D60780UL))
#define bM0P_AES_KEY7_KEY71                             *((volatile unsigned int*)(0x42D60784UL))
#define bM0P_AES_KEY7_KEY72                             *((volatile unsigned int*)(0x42D60788UL))
#define bM0P_AES_KEY7_KEY73                             *((volatile unsigned int*)(0x42D6078CUL))
#define bM0P_AES_KEY7_KEY74                             *((volatile unsigned int*)(0x42D60790UL))
#define bM0P_AES_KEY7_KEY75                             *((volatile unsigned int*)(0x42D60794UL))
#define bM0P_AES_KEY7_KEY76                             *((volatile unsigned int*)(0x42D60798UL))
#define bM0P_AES_KEY7_KEY77                             *((volatile unsigned int*)(0x42D6079CUL))
#define bM0P_AES_KEY7_KEY78                             *((volatile unsigned int*)(0x42D607A0UL))
#define bM0P_AES_KEY7_KEY79                             *((volatile unsigned int*)(0x42D607A4UL))
#define bM0P_AES_KEY7_KEY710                            *((volatile unsigned int*)(0x42D607A8UL))
#define bM0P_AES_KEY7_KEY711                            *((volatile unsigned int*)(0x42D607ACUL))
#define bM0P_AES_KEY7_KEY712                            *((volatile unsigned int*)(0x42D607B0UL))
#define bM0P_AES_KEY7_KEY713                            *((volatile unsigned int*)(0x42D607B4UL))
#define bM0P_AES_KEY7_KEY714                            *((volatile unsigned int*)(0x42D607B8UL))
#define bM0P_AES_KEY7_KEY715                            *((volatile unsigned int*)(0x42D607BCUL))
#define bM0P_AES_KEY7_KEY716                            *((volatile unsigned int*)(0x42D607C0UL))
#define bM0P_AES_KEY7_KEY717                            *((volatile unsigned int*)(0x42D607C4UL))
#define bM0P_AES_KEY7_KEY718                            *((volatile unsigned int*)(0x42D607C8UL))
#define bM0P_AES_KEY7_KEY719                            *((volatile unsigned int*)(0x42D607CCUL))
#define bM0P_AES_KEY7_KEY720                            *((volatile unsigned int*)(0x42D607D0UL))
#define bM0P_AES_KEY7_KEY721                            *((volatile unsigned int*)(0x42D607D4UL))
#define bM0P_AES_KEY7_KEY722                            *((volatile unsigned int*)(0x42D607D8UL))
#define bM0P_AES_KEY7_KEY723                            *((volatile unsigned int*)(0x42D607DCUL))
#define bM0P_AES_KEY7_KEY724                            *((volatile unsigned int*)(0x42D607E0UL))
#define bM0P_AES_KEY7_KEY725                            *((volatile unsigned int*)(0x42D607E4UL))
#define bM0P_AES_KEY7_KEY726                            *((volatile unsigned int*)(0x42D607E8UL))
#define bM0P_AES_KEY7_KEY727                            *((volatile unsigned int*)(0x42D607ECUL))
#define bM0P_AES_KEY7_KEY728                            *((volatile unsigned int*)(0x42D607F0UL))
#define bM0P_AES_KEY7_KEY729                            *((volatile unsigned int*)(0x42D607F4UL))
#define bM0P_AES_KEY7_KEY730                            *((volatile unsigned int*)(0x42D607F8UL))
#define bM0P_AES_KEY7_KEY731                            *((volatile unsigned int*)(0x42D607FCUL))
#define bM0P_AES_RNG0_RNG00                             *((volatile unsigned int*)(0x42D60800UL))
#define bM0P_AES_RNG0_RNG01                             *((volatile unsigned int*)(0x42D60804UL))
#define bM0P_AES_RNG0_RNG02                             *((volatile unsigned int*)(0x42D60808UL))
#define bM0P_AES_RNG0_RNG03                             *((volatile unsigned int*)(0x42D6080CUL))
#define bM0P_AES_RNG0_RNG04                             *((volatile unsigned int*)(0x42D60810UL))
#define bM0P_AES_RNG0_RNG05                             *((volatile unsigned int*)(0x42D60814UL))
#define bM0P_AES_RNG0_RNG06                             *((volatile unsigned int*)(0x42D60818UL))
#define bM0P_AES_RNG0_RNG07                             *((volatile unsigned int*)(0x42D6081CUL))
#define bM0P_AES_RNG0_RNG08                             *((volatile unsigned int*)(0x42D60820UL))
#define bM0P_AES_RNG0_RNG09                             *((volatile unsigned int*)(0x42D60824UL))
#define bM0P_AES_RNG0_RNG010                            *((volatile unsigned int*)(0x42D60828UL))
#define bM0P_AES_RNG0_RNG011                            *((volatile unsigned int*)(0x42D6082CUL))
#define bM0P_AES_RNG0_RNG012                            *((volatile unsigned int*)(0x42D60830UL))
#define bM0P_AES_RNG0_RNG013                            *((volatile unsigned int*)(0x42D60834UL))
#define bM0P_AES_RNG0_RNG014                            *((volatile unsigned int*)(0x42D60838UL))
#define bM0P_AES_RNG0_RNG015                            *((volatile unsigned int*)(0x42D6083CUL))
#define bM0P_AES_RNG0_RNG016                            *((volatile unsigned int*)(0x42D60840UL))
#define bM0P_AES_RNG0_RNG017                            *((volatile unsigned int*)(0x42D60844UL))
#define bM0P_AES_RNG0_RNG018                            *((volatile unsigned int*)(0x42D60848UL))
#define bM0P_AES_RNG0_RNG019                            *((volatile unsigned int*)(0x42D6084CUL))
#define bM0P_AES_RNG0_RNG020                            *((volatile unsigned int*)(0x42D60850UL))
#define bM0P_AES_RNG0_RNG021                            *((volatile unsigned int*)(0x42D60854UL))
#define bM0P_AES_RNG0_RNG022                            *((volatile unsigned int*)(0x42D60858UL))
#define bM0P_AES_RNG0_RNG023                            *((volatile unsigned int*)(0x42D6085CUL))
#define bM0P_AES_RNG0_RNG024                            *((volatile unsigned int*)(0x42D60860UL))
#define bM0P_AES_RNG0_RNG025                            *((volatile unsigned int*)(0x42D60864UL))
#define bM0P_AES_RNG0_RNG026                            *((volatile unsigned int*)(0x42D60868UL))
#define bM0P_AES_RNG0_RNG027                            *((volatile unsigned int*)(0x42D6086CUL))
#define bM0P_AES_RNG0_RNG028                            *((volatile unsigned int*)(0x42D60870UL))
#define bM0P_AES_RNG0_RNG029                            *((volatile unsigned int*)(0x42D60874UL))
#define bM0P_AES_RNG0_RNG030                            *((volatile unsigned int*)(0x42D60878UL))
#define bM0P_AES_RNG0_RNG031                            *((volatile unsigned int*)(0x42D6087CUL))
#define bM0P_AES_RNG1_RNG10                             *((volatile unsigned int*)(0x42D60880UL))
#define bM0P_AES_RNG1_RNG11                             *((volatile unsigned int*)(0x42D60884UL))
#define bM0P_AES_RNG1_RNG12                             *((volatile unsigned int*)(0x42D60888UL))
#define bM0P_AES_RNG1_RNG13                             *((volatile unsigned int*)(0x42D6088CUL))
#define bM0P_AES_RNG1_RNG14                             *((volatile unsigned int*)(0x42D60890UL))
#define bM0P_AES_RNG1_RNG15                             *((volatile unsigned int*)(0x42D60894UL))
#define bM0P_AES_RNG1_RNG16                             *((volatile unsigned int*)(0x42D60898UL))
#define bM0P_AES_RNG1_RNG17                             *((volatile unsigned int*)(0x42D6089CUL))
#define bM0P_AES_RNG1_RNG18                             *((volatile unsigned int*)(0x42D608A0UL))
#define bM0P_AES_RNG1_RNG19                             *((volatile unsigned int*)(0x42D608A4UL))
#define bM0P_AES_RNG1_RNG110                            *((volatile unsigned int*)(0x42D608A8UL))
#define bM0P_AES_RNG1_RNG111                            *((volatile unsigned int*)(0x42D608ACUL))
#define bM0P_AES_RNG1_RNG112                            *((volatile unsigned int*)(0x42D608B0UL))
#define bM0P_AES_RNG1_RNG113                            *((volatile unsigned int*)(0x42D608B4UL))
#define bM0P_AES_RNG1_RNG114                            *((volatile unsigned int*)(0x42D608B8UL))
#define bM0P_AES_RNG1_RNG115                            *((volatile unsigned int*)(0x42D608BCUL))
#define bM0P_AES_RNG1_RNG116                            *((volatile unsigned int*)(0x42D608C0UL))
#define bM0P_AES_RNG1_RNG117                            *((volatile unsigned int*)(0x42D608C4UL))
#define bM0P_AES_RNG1_RNG118                            *((volatile unsigned int*)(0x42D608C8UL))
#define bM0P_AES_RNG1_RNG119                            *((volatile unsigned int*)(0x42D608CCUL))
#define bM0P_AES_RNG1_RNG120                            *((volatile unsigned int*)(0x42D608D0UL))
#define bM0P_AES_RNG1_RNG121                            *((volatile unsigned int*)(0x42D608D4UL))
#define bM0P_AES_RNG1_RNG122                            *((volatile unsigned int*)(0x42D608D8UL))
#define bM0P_AES_RNG1_RNG123                            *((volatile unsigned int*)(0x42D608DCUL))
#define bM0P_AES_RNG1_RNG124                            *((volatile unsigned int*)(0x42D608E0UL))
#define bM0P_AES_RNG1_RNG125                            *((volatile unsigned int*)(0x42D608E4UL))
#define bM0P_AES_RNG1_RNG126                            *((volatile unsigned int*)(0x42D608E8UL))
#define bM0P_AES_RNG1_RNG127                            *((volatile unsigned int*)(0x42D608ECUL))
#define bM0P_AES_RNG1_RNG128                            *((volatile unsigned int*)(0x42D608F0UL))
#define bM0P_AES_RNG1_RNG129                            *((volatile unsigned int*)(0x42D608F4UL))
#define bM0P_AES_RNG1_RNG130                            *((volatile unsigned int*)(0x42D608F8UL))
#define bM0P_AES_RNG1_RNG131                            *((volatile unsigned int*)(0x42D608FCUL))
#define bM0P_AES_INT_CON_INT_EN                         *((volatile unsigned int*)(0x42D60A00UL))
#define bM0P_AES_INT_CON_ALM_INT                        *((volatile unsigned int*)(0x42D60A04UL))
#define bM0P_AES_DIV_EN_DIV_EN                          *((volatile unsigned int*)(0x42D60C00UL))
#define bM0P_BUZZER_BUZ_CTL_CLK_SEL                     *((volatile unsigned int*)(0x42784000UL))
#define bM0P_BUZZER_BUZ_CTL_BUZ_ST                      *((volatile unsigned int*)(0x42784004UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT0                    *((volatile unsigned int*)(0x42784080UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT1                    *((volatile unsigned int*)(0x42784084UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT2                    *((volatile unsigned int*)(0x42784088UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT3                    *((volatile unsigned int*)(0x4278408CUL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT4                    *((volatile unsigned int*)(0x42784090UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT5                    *((volatile unsigned int*)(0x42784094UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT6                    *((volatile unsigned int*)(0x42784098UL))
#define bM0P_BUZZER_BUZ_CNT_BUZ_CNT7                    *((volatile unsigned int*)(0x4278409CUL))
#define bM0P_CLOCK_CTRL_HC_EN                           *((volatile unsigned int*)(0x42200000UL))
#define bM0P_CLOCK_CTRL_MAIN_EN                         *((volatile unsigned int*)(0x42200004UL))
#define bM0P_CLOCK_CTRL_SUB_EN                          *((volatile unsigned int*)(0x4220000CUL))
#define bM0P_CLOCK_CTRL_INPUT0                          *((volatile unsigned int*)(0x42200014UL))
#define bM0P_CLOCK_CTRL_INPUT1                          *((volatile unsigned int*)(0x42200018UL))
#define bM0P_CLOCK_CTRL_INPUT2                          *((volatile unsigned int*)(0x4220001CUL))
#define bM0P_CLOCK_CLK_STB_HC_RDY                       *((volatile unsigned int*)(0x42200080UL))
#define bM0P_CLOCK_CLK_STB_MAIN_RDY                     *((volatile unsigned int*)(0x42200084UL))
#define bM0P_CLOCK_CLK_STB_SUB_RDY                      *((volatile unsigned int*)(0x4220008CUL))
#define bM0P_CLOCK_CLK_STB_SRC0                         *((volatile unsigned int*)(0x42200094UL))
#define bM0P_CLOCK_CLK_STB_SRC1                         *((volatile unsigned int*)(0x42200098UL))
#define bM0P_CLOCK_CLK_STB_SRC2                         *((volatile unsigned int*)(0x4220009CUL))
#define bM0P_CLOCK_LPM_CTL_STBM0                        *((volatile unsigned int*)(0x42200100UL))
#define bM0P_CLOCK_LPM_CTL_STBM1                        *((volatile unsigned int*)(0x42200104UL))
#define bM0P_CLOCK_LPM_CTL_DSTBEN                       *((volatile unsigned int*)(0x42200108UL))
#define bM0P_CLOCK_LPM_CTL_SPLV                         *((volatile unsigned int*)(0x42200110UL))
#define bM0P_CLOCK_LPM_CTL_KEY0                         *((volatile unsigned int*)(0x42200140UL))
#define bM0P_CLOCK_LPM_CTL_KEY1                         *((volatile unsigned int*)(0x42200144UL))
#define bM0P_CLOCK_LPM_CTL_KEY2                         *((volatile unsigned int*)(0x42200148UL))
#define bM0P_CLOCK_LPM_CTL_KEY3                         *((volatile unsigned int*)(0x4220014CUL))
#define bM0P_CLOCK_LPM_CTL_KEY4                         *((volatile unsigned int*)(0x42200150UL))
#define bM0P_CLOCK_LPM_CTL_KEY5                         *((volatile unsigned int*)(0x42200154UL))
#define bM0P_CLOCK_LPM_CTL_KEY6                         *((volatile unsigned int*)(0x42200158UL))
#define bM0P_CLOCK_LPM_CTL_KEY7                         *((volatile unsigned int*)(0x4220015CUL))
#define bM0P_CLOCK_LPM_CTL_KEY8                         *((volatile unsigned int*)(0x42200160UL))
#define bM0P_CLOCK_LPM_CTL_KEY9                         *((volatile unsigned int*)(0x42200164UL))
#define bM0P_CLOCK_LPM_CTL_KEY10                        *((volatile unsigned int*)(0x42200168UL))
#define bM0P_CLOCK_LPM_CTL_KEY11                        *((volatile unsigned int*)(0x4220016CUL))
#define bM0P_CLOCK_LPM_CTL_KEY12                        *((volatile unsigned int*)(0x42200170UL))
#define bM0P_CLOCK_LPM_CTL_KEY13                        *((volatile unsigned int*)(0x42200174UL))
#define bM0P_CLOCK_LPM_CTL_KEY14                        *((volatile unsigned int*)(0x42200178UL))
#define bM0P_CLOCK_LPM_CTL_KEY15                        *((volatile unsigned int*)(0x4220017CUL))
#define bM0P_CLOCK_STAT_PWR                             *((volatile unsigned int*)(0x42200180UL))
#define bM0P_CLOCK_STAT_RSTB                            *((volatile unsigned int*)(0x42200184UL))
#define bM0P_CLOCK_STAT_LVDR                            *((volatile unsigned int*)(0x4220018CUL))
#define bM0P_CLOCK_STAT_SWWDG                           *((volatile unsigned int*)(0x42200190UL))
#define bM0P_CLOCK_STAT_HWWDG                           *((volatile unsigned int*)(0x42200194UL))
#define bM0P_CLOCK_STAT_CSV                             *((volatile unsigned int*)(0x42200198UL))
#define bM0P_CLOCK_STAT_AF                              *((volatile unsigned int*)(0x4220019CUL))
#define bM0P_CLOCK_STAT_SW                              *((volatile unsigned int*)(0x422001A0UL))
#define bM0P_CLOCK_BC_DIV_DIV0                          *((volatile unsigned int*)(0x42200200UL))
#define bM0P_CLOCK_BC_DIV_DIV1                          *((volatile unsigned int*)(0x42200204UL))
#define bM0P_CLOCK_BC_DIV_DIV2                          *((volatile unsigned int*)(0x42200208UL))
#define bM0P_CLOCK_APB0_CTRL_DIV0                       *((volatile unsigned int*)(0x42200280UL))
#define bM0P_CLOCK_APB0_CTRL_DIV1                       *((volatile unsigned int*)(0x42200284UL))
#define bM0P_CLOCK_APB1_CTRL_DIV0                       *((volatile unsigned int*)(0x42200300UL))
#define bM0P_CLOCK_APB1_CTRL_DIV1                       *((volatile unsigned int*)(0x42200304UL))
#define bM0P_CLOCK_APB1_CTRL_RST                        *((volatile unsigned int*)(0x42200310UL))
#define bM0P_CLOCK_APB1_CTRL_EN                         *((volatile unsigned int*)(0x4220031CUL))
#define bM0P_CLOCK_CLK_CTL_SWDS0                        *((volatile unsigned int*)(0x42200400UL))
#define bM0P_CLOCK_CLK_CTL_SWDS1                        *((volatile unsigned int*)(0x42200404UL))
#define bM0P_CLOCK_CLK_CTL_SWCKE                        *((volatile unsigned int*)(0x42200410UL))
#define bM0P_CLOCK_CLK_CTL_HWCKE                        *((volatile unsigned int*)(0x42200414UL))
#define bM0P_CLOCK_CLK_CTL_DTCKE                        *((volatile unsigned int*)(0x42200418UL))
#define bM0P_CLOCK_CSWT_MAINWT0                         *((volatile unsigned int*)(0x42200600UL))
#define bM0P_CLOCK_CSWT_MAINWT1                         *((volatile unsigned int*)(0x42200604UL))
#define bM0P_CLOCK_CSWT_MAINWT2                         *((volatile unsigned int*)(0x42200608UL))
#define bM0P_CLOCK_CSWT_MAINWT3                         *((volatile unsigned int*)(0x4220060CUL))
#define bM0P_CLOCK_CSWT_SUBWT0                          *((volatile unsigned int*)(0x42200610UL))
#define bM0P_CLOCK_CSWT_SUBWT1                          *((volatile unsigned int*)(0x42200614UL))
#define bM0P_CLOCK_CSWT_SUBWT2                          *((volatile unsigned int*)(0x42200618UL))
#define bM0P_CLOCK_CSWT_SUBWT3                          *((volatile unsigned int*)(0x4220061CUL))
#define bM0P_CLOCK_FCM_CTL_MFCME                        *((volatile unsigned int*)(0x42200800UL))
#define bM0P_CLOCK_FCM_CTL_SFCME                        *((volatile unsigned int*)(0x42200804UL))
#define bM0P_CLOCK_FCM_CTL_MFCMRE                       *((volatile unsigned int*)(0x42200808UL))
#define bM0P_CLOCK_FCM_CTL_SFCMRE                       *((volatile unsigned int*)(0x4220080CUL))
#define bM0P_CLOCK_FCM_CTL_AFDE                         *((volatile unsigned int*)(0x42200820UL))
#define bM0P_CLOCK_FCM_CTL_AFDRE                        *((volatile unsigned int*)(0x42200824UL))
#define bM0P_CLOCK_FCM_CTL_AFDCC0                       *((volatile unsigned int*)(0x42200830UL))
#define bM0P_CLOCK_FCM_CTL_AFDCC1                       *((volatile unsigned int*)(0x42200834UL))
#define bM0P_CLOCK_FCM_CTL_AFDCC2                       *((volatile unsigned int*)(0x42200838UL))
#define bM0P_CLOCK_FCM_STR_MCFDF                        *((volatile unsigned int*)(0x42200880UL))
#define bM0P_CLOCK_FCM_STR_SCFDF                        *((volatile unsigned int*)(0x42200884UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH0                     *((volatile unsigned int*)(0x42200900UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH1                     *((volatile unsigned int*)(0x42200904UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH2                     *((volatile unsigned int*)(0x42200908UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH3                     *((volatile unsigned int*)(0x4220090CUL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH4                     *((volatile unsigned int*)(0x42200910UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH5                     *((volatile unsigned int*)(0x42200914UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH6                     *((volatile unsigned int*)(0x42200918UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH7                     *((volatile unsigned int*)(0x4220091CUL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH8                     *((volatile unsigned int*)(0x42200920UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH9                     *((volatile unsigned int*)(0x42200924UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH10                    *((volatile unsigned int*)(0x42200928UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH11                    *((volatile unsigned int*)(0x4220092CUL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH12                    *((volatile unsigned int*)(0x42200930UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH13                    *((volatile unsigned int*)(0x42200934UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH14                    *((volatile unsigned int*)(0x42200938UL))
#define bM0P_CLOCK_AFDWH_CTL_AFDWH15                    *((volatile unsigned int*)(0x4220093CUL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL0                     *((volatile unsigned int*)(0x42200980UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL1                     *((volatile unsigned int*)(0x42200984UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL2                     *((volatile unsigned int*)(0x42200988UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL3                     *((volatile unsigned int*)(0x4220098CUL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL4                     *((volatile unsigned int*)(0x42200990UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL5                     *((volatile unsigned int*)(0x42200994UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL6                     *((volatile unsigned int*)(0x42200998UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL7                     *((volatile unsigned int*)(0x4220099CUL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL8                     *((volatile unsigned int*)(0x422009A0UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL9                     *((volatile unsigned int*)(0x422009A4UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL10                    *((volatile unsigned int*)(0x422009A8UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL11                    *((volatile unsigned int*)(0x422009ACUL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL12                    *((volatile unsigned int*)(0x422009B0UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL13                    *((volatile unsigned int*)(0x422009B4UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL14                    *((volatile unsigned int*)(0x422009B8UL))
#define bM0P_CLOCK_AFDWL_CTL_AFDWL15                    *((volatile unsigned int*)(0x422009BCUL))
#define bM0P_CLOCK_AFDC_CTL_AFDC0                       *((volatile unsigned int*)(0x42200A00UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC1                       *((volatile unsigned int*)(0x42200A04UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC2                       *((volatile unsigned int*)(0x42200A08UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC3                       *((volatile unsigned int*)(0x42200A0CUL))
#define bM0P_CLOCK_AFDC_CTL_AFDC4                       *((volatile unsigned int*)(0x42200A10UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC5                       *((volatile unsigned int*)(0x42200A14UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC6                       *((volatile unsigned int*)(0x42200A18UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC7                       *((volatile unsigned int*)(0x42200A1CUL))
#define bM0P_CLOCK_AFDC_CTL_AFDC8                       *((volatile unsigned int*)(0x42200A20UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC9                       *((volatile unsigned int*)(0x42200A24UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC10                      *((volatile unsigned int*)(0x42200A28UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC11                      *((volatile unsigned int*)(0x42200A2CUL))
#define bM0P_CLOCK_AFDC_CTL_AFDC12                      *((volatile unsigned int*)(0x42200A30UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC13                      *((volatile unsigned int*)(0x42200A34UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC14                      *((volatile unsigned int*)(0x42200A38UL))
#define bM0P_CLOCK_AFDC_CTL_AFDC15                      *((volatile unsigned int*)(0x42200A3CUL))
#define bM0P_CLOCK_DBWDT_CTRL_SWWDG_BRK                 *((volatile unsigned int*)(0x42200A94UL))
#define bM0P_CLOCK_DBWDT_CTRL_HWWDG_BRK                 *((volatile unsigned int*)(0x42200A9CUL))
#define bM0P_CLOCK_INT_CTRL_MAINEN                      *((volatile unsigned int*)(0x42200C00UL))
#define bM0P_CLOCK_INT_CTRL_SUBEN                       *((volatile unsigned int*)(0x42200C04UL))
#define bM0P_CLOCK_INT_CTRL_MCSVIE                      *((volatile unsigned int*)(0x42200C0CUL))
#define bM0P_CLOCK_INT_CTRL_SCSVIE                      *((volatile unsigned int*)(0x42200C10UL))
#define bM0P_CLOCK_INT_CTRL_FCSEN                       *((volatile unsigned int*)(0x42200C14UL))
#define bM0P_CLOCK_INT_PEND_MAIN                        *((volatile unsigned int*)(0x42200C80UL))
#define bM0P_CLOCK_INT_PEND_SUB                         *((volatile unsigned int*)(0x42200C84UL))
#define bM0P_CLOCK_INT_PEND_MCSVI                       *((volatile unsigned int*)(0x42200C8CUL))
#define bM0P_CLOCK_INT_PEND_SCSVI                       *((volatile unsigned int*)(0x42200C90UL))
#define bM0P_CLOCK_INT_PEND_FCS                         *((volatile unsigned int*)(0x42200C94UL))
#define bM0P_CLOCK_INT_CLR_MAIN                         *((volatile unsigned int*)(0x42200D00UL))
#define bM0P_CLOCK_INT_CLR_SUB                          *((volatile unsigned int*)(0x42200D04UL))
#define bM0P_CLOCK_INT_CLR_MCSVC                        *((volatile unsigned int*)(0x42200D0CUL))
#define bM0P_CLOCK_INT_CLR_SCSVC                        *((volatile unsigned int*)(0x42200D10UL))
#define bM0P_CLOCK_INT_CLR_FCS                          *((volatile unsigned int*)(0x42200D14UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL010                 *((volatile unsigned int*)(0x424A2020UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL011                 *((volatile unsigned int*)(0x424A2024UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL012                 *((volatile unsigned int*)(0x424A2028UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL013                 *((volatile unsigned int*)(0x424A202CUL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL230                 *((volatile unsigned int*)(0x424A2030UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL231                 *((volatile unsigned int*)(0x424A2034UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL232                 *((volatile unsigned int*)(0x424A2038UL))
#define bM0P_CTIOSEL03_CTSEL0123_SEL233                 *((volatile unsigned int*)(0x424A203CUL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL450                 *((volatile unsigned int*)(0x424A6020UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL451                 *((volatile unsigned int*)(0x424A6024UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL452                 *((volatile unsigned int*)(0x424A6028UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL453                 *((volatile unsigned int*)(0x424A602CUL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL670                 *((volatile unsigned int*)(0x424A6030UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL671                 *((volatile unsigned int*)(0x424A6034UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL672                 *((volatile unsigned int*)(0x424A6038UL))
#define bM0P_CTIOSEL47_CTSEL4567_SEL673                 *((volatile unsigned int*)(0x424A603CUL))
#define bM0P_CT0_PPG_TCR_START                          *((volatile unsigned int*)(0x424A0180UL))
#define bM0P_CT0_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0184UL))
#define bM0P_CT0_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A0188UL))
#define bM0P_CT0_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A018CUL))
#define bM0P_CT0_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0190UL))
#define bM0P_CT0_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0194UL))
#define bM0P_CT0_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0198UL))
#define bM0P_CT0_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A01A0UL))
#define bM0P_CT0_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A01A4UL))
#define bM0P_CT0_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A01A8UL))
#define bM0P_CT0_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A01ACUL))
#define bM0P_CT0_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A01B0UL))
#define bM0P_CT0_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A01B4UL))
#define bM0P_CT0_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A01B8UL))
#define bM0P_CT0_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A0200UL))
#define bM0P_CT0_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A0208UL))
#define bM0P_CT0_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A0210UL))
#define bM0P_CT0_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A0218UL))
#define bM0P_CT0_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0220UL))
#define bM0P_CT1_PPG_TCR_START                          *((volatile unsigned int*)(0x424A0980UL))
#define bM0P_CT1_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0984UL))
#define bM0P_CT1_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A0988UL))
#define bM0P_CT1_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A098CUL))
#define bM0P_CT1_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0990UL))
#define bM0P_CT1_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0994UL))
#define bM0P_CT1_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0998UL))
#define bM0P_CT1_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A09A0UL))
#define bM0P_CT1_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A09A4UL))
#define bM0P_CT1_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A09A8UL))
#define bM0P_CT1_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A09ACUL))
#define bM0P_CT1_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A09B0UL))
#define bM0P_CT1_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A09B4UL))
#define bM0P_CT1_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A09B8UL))
#define bM0P_CT1_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A0A00UL))
#define bM0P_CT1_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A0A08UL))
#define bM0P_CT1_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A0A10UL))
#define bM0P_CT1_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A0A18UL))
#define bM0P_CT1_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0A20UL))
#define bM0P_CT2_PPG_TCR_START                          *((volatile unsigned int*)(0x424A1180UL))
#define bM0P_CT2_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1184UL))
#define bM0P_CT2_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A1188UL))
#define bM0P_CT2_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A118CUL))
#define bM0P_CT2_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1190UL))
#define bM0P_CT2_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1194UL))
#define bM0P_CT2_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1198UL))
#define bM0P_CT2_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A11A0UL))
#define bM0P_CT2_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A11A4UL))
#define bM0P_CT2_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A11A8UL))
#define bM0P_CT2_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A11ACUL))
#define bM0P_CT2_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A11B0UL))
#define bM0P_CT2_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A11B4UL))
#define bM0P_CT2_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A11B8UL))
#define bM0P_CT2_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A1200UL))
#define bM0P_CT2_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A1208UL))
#define bM0P_CT2_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A1210UL))
#define bM0P_CT2_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A1218UL))
#define bM0P_CT2_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1220UL))
#define bM0P_CT3_PPG_TCR_START                          *((volatile unsigned int*)(0x424A1980UL))
#define bM0P_CT3_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1984UL))
#define bM0P_CT3_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A1988UL))
#define bM0P_CT3_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A198CUL))
#define bM0P_CT3_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1990UL))
#define bM0P_CT3_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1994UL))
#define bM0P_CT3_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1998UL))
#define bM0P_CT3_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A19A0UL))
#define bM0P_CT3_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A19A4UL))
#define bM0P_CT3_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A19A8UL))
#define bM0P_CT3_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A19ACUL))
#define bM0P_CT3_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A19B0UL))
#define bM0P_CT3_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A19B4UL))
#define bM0P_CT3_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A19B8UL))
#define bM0P_CT3_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A1A00UL))
#define bM0P_CT3_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A1A08UL))
#define bM0P_CT3_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A1A10UL))
#define bM0P_CT3_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A1A18UL))
#define bM0P_CT3_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1A20UL))
#define bM0P_CT4_PPG_TCR_START                          *((volatile unsigned int*)(0x424A4180UL))
#define bM0P_CT4_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4184UL))
#define bM0P_CT4_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A4188UL))
#define bM0P_CT4_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A418CUL))
#define bM0P_CT4_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4190UL))
#define bM0P_CT4_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4194UL))
#define bM0P_CT4_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4198UL))
#define bM0P_CT4_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A41A0UL))
#define bM0P_CT4_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A41A4UL))
#define bM0P_CT4_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A41A8UL))
#define bM0P_CT4_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A41ACUL))
#define bM0P_CT4_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A41B0UL))
#define bM0P_CT4_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A41B4UL))
#define bM0P_CT4_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A41B8UL))
#define bM0P_CT4_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A4200UL))
#define bM0P_CT4_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A4208UL))
#define bM0P_CT4_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A4210UL))
#define bM0P_CT4_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A4218UL))
#define bM0P_CT4_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4220UL))
#define bM0P_CT5_PPG_TCR_START                          *((volatile unsigned int*)(0x424A4980UL))
#define bM0P_CT5_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4984UL))
#define bM0P_CT5_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A4988UL))
#define bM0P_CT5_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A498CUL))
#define bM0P_CT5_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4990UL))
#define bM0P_CT5_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4994UL))
#define bM0P_CT5_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4998UL))
#define bM0P_CT5_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A49A0UL))
#define bM0P_CT5_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A49A4UL))
#define bM0P_CT5_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A49A8UL))
#define bM0P_CT5_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A49ACUL))
#define bM0P_CT5_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A49B0UL))
#define bM0P_CT5_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A49B4UL))
#define bM0P_CT5_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A49B8UL))
#define bM0P_CT5_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A4A00UL))
#define bM0P_CT5_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A4A08UL))
#define bM0P_CT5_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A4A10UL))
#define bM0P_CT5_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A4A18UL))
#define bM0P_CT5_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4A20UL))
#define bM0P_CT6_PPG_TCR_START                          *((volatile unsigned int*)(0x424A5180UL))
#define bM0P_CT6_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5184UL))
#define bM0P_CT6_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A5188UL))
#define bM0P_CT6_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A518CUL))
#define bM0P_CT6_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5190UL))
#define bM0P_CT6_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5194UL))
#define bM0P_CT6_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5198UL))
#define bM0P_CT6_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A51A0UL))
#define bM0P_CT6_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A51A4UL))
#define bM0P_CT6_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A51A8UL))
#define bM0P_CT6_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A51ACUL))
#define bM0P_CT6_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A51B0UL))
#define bM0P_CT6_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A51B4UL))
#define bM0P_CT6_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A51B8UL))
#define bM0P_CT6_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A5200UL))
#define bM0P_CT6_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A5208UL))
#define bM0P_CT6_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A5210UL))
#define bM0P_CT6_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A5218UL))
#define bM0P_CT6_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5220UL))
#define bM0P_CT7_PPG_TCR_START                          *((volatile unsigned int*)(0x424A5980UL))
#define bM0P_CT7_PPG_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5984UL))
#define bM0P_CT7_PPG_TCR_MODS                           *((volatile unsigned int*)(0x424A5988UL))
#define bM0P_CT7_PPG_TCR_PLRT                           *((volatile unsigned int*)(0x424A598CUL))
#define bM0P_CT7_PPG_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5990UL))
#define bM0P_CT7_PPG_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5994UL))
#define bM0P_CT7_PPG_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5998UL))
#define bM0P_CT7_PPG_TCR_EDGS0                          *((volatile unsigned int*)(0x424A59A0UL))
#define bM0P_CT7_PPG_TCR_EDGS1                          *((volatile unsigned int*)(0x424A59A4UL))
#define bM0P_CT7_PPG_TCR_MASK                           *((volatile unsigned int*)(0x424A59A8UL))
#define bM0P_CT7_PPG_TCR_RSTEN                          *((volatile unsigned int*)(0x424A59ACUL))
#define bM0P_CT7_PPG_TCR_CLKS0                          *((volatile unsigned int*)(0x424A59B0UL))
#define bM0P_CT7_PPG_TCR_CLKS1                          *((volatile unsigned int*)(0x424A59B4UL))
#define bM0P_CT7_PPG_TCR_CLKS2                          *((volatile unsigned int*)(0x424A59B8UL))
#define bM0P_CT7_PPG_STA_UDFIR                          *((volatile unsigned int*)(0x424A5A00UL))
#define bM0P_CT7_PPG_STA_TRGIR                          *((volatile unsigned int*)(0x424A5A08UL))
#define bM0P_CT7_PPG_STA_UDFIE                          *((volatile unsigned int*)(0x424A5A10UL))
#define bM0P_CT7_PPG_STA_TRGIE                          *((volatile unsigned int*)(0x424A5A18UL))
#define bM0P_CT7_PPG_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5A20UL))
#define bM0P_CT0_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0184UL))
#define bM0P_CT0_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A0188UL))
#define bM0P_CT0_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0190UL))
#define bM0P_CT0_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0194UL))
#define bM0P_CT0_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0198UL))
#define bM0P_CT0_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A019CUL))
#define bM0P_CT0_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A01A0UL))
#define bM0P_CT0_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A01A4UL))
#define bM0P_CT0_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A01A8UL))
#define bM0P_CT0_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A01B0UL))
#define bM0P_CT0_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A01B4UL))
#define bM0P_CT0_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A01B8UL))
#define bM0P_CT0_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A0200UL))
#define bM0P_CT0_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A0208UL))
#define bM0P_CT0_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A0210UL))
#define bM0P_CT0_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A0218UL))
#define bM0P_CT0_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A021CUL))
#define bM0P_CT0_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0220UL))
#define bM0P_CT1_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0984UL))
#define bM0P_CT1_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A0988UL))
#define bM0P_CT1_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0990UL))
#define bM0P_CT1_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0994UL))
#define bM0P_CT1_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0998UL))
#define bM0P_CT1_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A099CUL))
#define bM0P_CT1_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A09A0UL))
#define bM0P_CT1_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A09A4UL))
#define bM0P_CT1_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A09A8UL))
#define bM0P_CT1_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A09B0UL))
#define bM0P_CT1_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A09B4UL))
#define bM0P_CT1_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A09B8UL))
#define bM0P_CT1_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A0A00UL))
#define bM0P_CT1_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A0A08UL))
#define bM0P_CT1_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A0A10UL))
#define bM0P_CT1_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A0A18UL))
#define bM0P_CT1_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A0A1CUL))
#define bM0P_CT1_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0A20UL))
#define bM0P_CT2_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1184UL))
#define bM0P_CT2_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A1188UL))
#define bM0P_CT2_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1190UL))
#define bM0P_CT2_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1194UL))
#define bM0P_CT2_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1198UL))
#define bM0P_CT2_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A119CUL))
#define bM0P_CT2_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A11A0UL))
#define bM0P_CT2_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A11A4UL))
#define bM0P_CT2_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A11A8UL))
#define bM0P_CT2_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A11B0UL))
#define bM0P_CT2_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A11B4UL))
#define bM0P_CT2_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A11B8UL))
#define bM0P_CT2_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A1200UL))
#define bM0P_CT2_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A1208UL))
#define bM0P_CT2_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A1210UL))
#define bM0P_CT2_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A1218UL))
#define bM0P_CT2_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A121CUL))
#define bM0P_CT2_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1220UL))
#define bM0P_CT3_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1984UL))
#define bM0P_CT3_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A1988UL))
#define bM0P_CT3_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1990UL))
#define bM0P_CT3_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1994UL))
#define bM0P_CT3_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1998UL))
#define bM0P_CT3_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A199CUL))
#define bM0P_CT3_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A19A0UL))
#define bM0P_CT3_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A19A4UL))
#define bM0P_CT3_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A19A8UL))
#define bM0P_CT3_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A19B0UL))
#define bM0P_CT3_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A19B4UL))
#define bM0P_CT3_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A19B8UL))
#define bM0P_CT3_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A1A00UL))
#define bM0P_CT3_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A1A08UL))
#define bM0P_CT3_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A1A10UL))
#define bM0P_CT3_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A1A18UL))
#define bM0P_CT3_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A1A1CUL))
#define bM0P_CT3_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1A20UL))
#define bM0P_CT4_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4184UL))
#define bM0P_CT4_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A4188UL))
#define bM0P_CT4_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4190UL))
#define bM0P_CT4_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4194UL))
#define bM0P_CT4_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4198UL))
#define bM0P_CT4_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A419CUL))
#define bM0P_CT4_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A41A0UL))
#define bM0P_CT4_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A41A4UL))
#define bM0P_CT4_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A41A8UL))
#define bM0P_CT4_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A41B0UL))
#define bM0P_CT4_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A41B4UL))
#define bM0P_CT4_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A41B8UL))
#define bM0P_CT4_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A4200UL))
#define bM0P_CT4_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A4208UL))
#define bM0P_CT4_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A4210UL))
#define bM0P_CT4_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A4218UL))
#define bM0P_CT4_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A421CUL))
#define bM0P_CT4_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4220UL))
#define bM0P_CT5_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4984UL))
#define bM0P_CT5_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A4988UL))
#define bM0P_CT5_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4990UL))
#define bM0P_CT5_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4994UL))
#define bM0P_CT5_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4998UL))
#define bM0P_CT5_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A499CUL))
#define bM0P_CT5_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A49A0UL))
#define bM0P_CT5_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A49A4UL))
#define bM0P_CT5_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A49A8UL))
#define bM0P_CT5_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A49B0UL))
#define bM0P_CT5_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A49B4UL))
#define bM0P_CT5_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A49B8UL))
#define bM0P_CT5_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A4A00UL))
#define bM0P_CT5_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A4A08UL))
#define bM0P_CT5_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A4A10UL))
#define bM0P_CT5_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A4A18UL))
#define bM0P_CT5_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A4A1CUL))
#define bM0P_CT5_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4A20UL))
#define bM0P_CT6_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5184UL))
#define bM0P_CT6_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A5188UL))
#define bM0P_CT6_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5190UL))
#define bM0P_CT6_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5194UL))
#define bM0P_CT6_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5198UL))
#define bM0P_CT6_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A519CUL))
#define bM0P_CT6_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A51A0UL))
#define bM0P_CT6_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A51A4UL))
#define bM0P_CT6_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A51A8UL))
#define bM0P_CT6_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A51B0UL))
#define bM0P_CT6_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A51B4UL))
#define bM0P_CT6_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A51B8UL))
#define bM0P_CT6_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A5200UL))
#define bM0P_CT6_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A5208UL))
#define bM0P_CT6_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A5210UL))
#define bM0P_CT6_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A5218UL))
#define bM0P_CT6_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A521CUL))
#define bM0P_CT6_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5220UL))
#define bM0P_CT7_PWC_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5984UL))
#define bM0P_CT7_PWC_TCR_MODS                           *((volatile unsigned int*)(0x424A5988UL))
#define bM0P_CT7_PWC_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5990UL))
#define bM0P_CT7_PWC_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5994UL))
#define bM0P_CT7_PWC_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5998UL))
#define bM0P_CT7_PWC_TCR_T32                            *((volatile unsigned int*)(0x424A599CUL))
#define bM0P_CT7_PWC_TCR_EDGS0                          *((volatile unsigned int*)(0x424A59A0UL))
#define bM0P_CT7_PWC_TCR_EDGS1                          *((volatile unsigned int*)(0x424A59A4UL))
#define bM0P_CT7_PWC_TCR_EDGS2                          *((volatile unsigned int*)(0x424A59A8UL))
#define bM0P_CT7_PWC_TCR_CLKS0                          *((volatile unsigned int*)(0x424A59B0UL))
#define bM0P_CT7_PWC_TCR_CLKS1                          *((volatile unsigned int*)(0x424A59B4UL))
#define bM0P_CT7_PWC_TCR_CLKS2                          *((volatile unsigned int*)(0x424A59B8UL))
#define bM0P_CT7_PWC_STA_OVIR                           *((volatile unsigned int*)(0x424A5A00UL))
#define bM0P_CT7_PWC_STA_MCIR                           *((volatile unsigned int*)(0x424A5A08UL))
#define bM0P_CT7_PWC_STA_OVIE                           *((volatile unsigned int*)(0x424A5A10UL))
#define bM0P_CT7_PWC_STA_MCIE                           *((volatile unsigned int*)(0x424A5A18UL))
#define bM0P_CT7_PWC_STA_ERR                            *((volatile unsigned int*)(0x424A5A1CUL))
#define bM0P_CT7_PWC_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5A20UL))
#define bM0P_CT0_PWM_TCR_START                          *((volatile unsigned int*)(0x424A0180UL))
#define bM0P_CT0_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0184UL))
#define bM0P_CT0_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A0188UL))
#define bM0P_CT0_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A018CUL))
#define bM0P_CT0_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0190UL))
#define bM0P_CT0_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0194UL))
#define bM0P_CT0_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0198UL))
#define bM0P_CT0_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A01A0UL))
#define bM0P_CT0_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A01A4UL))
#define bM0P_CT0_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A01A8UL))
#define bM0P_CT0_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A01ACUL))
#define bM0P_CT0_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A01B0UL))
#define bM0P_CT0_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A01B4UL))
#define bM0P_CT0_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A01B8UL))
#define bM0P_CT0_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A0200UL))
#define bM0P_CT0_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A0204UL))
#define bM0P_CT0_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A0208UL))
#define bM0P_CT0_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A0210UL))
#define bM0P_CT0_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A0214UL))
#define bM0P_CT0_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A0218UL))
#define bM0P_CT0_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0220UL))
#define bM0P_CT1_PWM_TCR_START                          *((volatile unsigned int*)(0x424A0980UL))
#define bM0P_CT1_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A0984UL))
#define bM0P_CT1_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A0988UL))
#define bM0P_CT1_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A098CUL))
#define bM0P_CT1_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A0990UL))
#define bM0P_CT1_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A0994UL))
#define bM0P_CT1_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A0998UL))
#define bM0P_CT1_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A09A0UL))
#define bM0P_CT1_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A09A4UL))
#define bM0P_CT1_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A09A8UL))
#define bM0P_CT1_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A09ACUL))
#define bM0P_CT1_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A09B0UL))
#define bM0P_CT1_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A09B4UL))
#define bM0P_CT1_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A09B8UL))
#define bM0P_CT1_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A0A00UL))
#define bM0P_CT1_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A0A04UL))
#define bM0P_CT1_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A0A08UL))
#define bM0P_CT1_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A0A10UL))
#define bM0P_CT1_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A0A14UL))
#define bM0P_CT1_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A0A18UL))
#define bM0P_CT1_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A0A20UL))
#define bM0P_CT2_PWM_TCR_START                          *((volatile unsigned int*)(0x424A1180UL))
#define bM0P_CT2_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1184UL))
#define bM0P_CT2_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A1188UL))
#define bM0P_CT2_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A118CUL))
#define bM0P_CT2_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1190UL))
#define bM0P_CT2_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1194UL))
#define bM0P_CT2_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1198UL))
#define bM0P_CT2_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A11A0UL))
#define bM0P_CT2_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A11A4UL))
#define bM0P_CT2_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A11A8UL))
#define bM0P_CT2_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A11ACUL))
#define bM0P_CT2_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A11B0UL))
#define bM0P_CT2_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A11B4UL))
#define bM0P_CT2_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A11B8UL))
#define bM0P_CT2_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A1200UL))
#define bM0P_CT2_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A1204UL))
#define bM0P_CT2_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A1208UL))
#define bM0P_CT2_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A1210UL))
#define bM0P_CT2_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A1214UL))
#define bM0P_CT2_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A1218UL))
#define bM0P_CT2_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1220UL))
#define bM0P_CT3_PWM_TCR_START                          *((volatile unsigned int*)(0x424A1980UL))
#define bM0P_CT3_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A1984UL))
#define bM0P_CT3_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A1988UL))
#define bM0P_CT3_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A198CUL))
#define bM0P_CT3_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A1990UL))
#define bM0P_CT3_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A1994UL))
#define bM0P_CT3_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A1998UL))
#define bM0P_CT3_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A19A0UL))
#define bM0P_CT3_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A19A4UL))
#define bM0P_CT3_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A19A8UL))
#define bM0P_CT3_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A19ACUL))
#define bM0P_CT3_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A19B0UL))
#define bM0P_CT3_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A19B4UL))
#define bM0P_CT3_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A19B8UL))
#define bM0P_CT3_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A1A00UL))
#define bM0P_CT3_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A1A04UL))
#define bM0P_CT3_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A1A08UL))
#define bM0P_CT3_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A1A10UL))
#define bM0P_CT3_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A1A14UL))
#define bM0P_CT3_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A1A18UL))
#define bM0P_CT3_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A1A20UL))
#define bM0P_CT4_PWM_TCR_START                          *((volatile unsigned int*)(0x424A4180UL))
#define bM0P_CT4_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4184UL))
#define bM0P_CT4_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A4188UL))
#define bM0P_CT4_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A418CUL))
#define bM0P_CT4_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4190UL))
#define bM0P_CT4_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4194UL))
#define bM0P_CT4_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4198UL))
#define bM0P_CT4_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A41A0UL))
#define bM0P_CT4_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A41A4UL))
#define bM0P_CT4_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A41A8UL))
#define bM0P_CT4_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A41ACUL))
#define bM0P_CT4_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A41B0UL))
#define bM0P_CT4_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A41B4UL))
#define bM0P_CT4_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A41B8UL))
#define bM0P_CT4_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A4200UL))
#define bM0P_CT4_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A4204UL))
#define bM0P_CT4_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A4208UL))
#define bM0P_CT4_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A4210UL))
#define bM0P_CT4_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A4214UL))
#define bM0P_CT4_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A4218UL))
#define bM0P_CT4_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4220UL))
#define bM0P_CT5_PWM_TCR_START                          *((volatile unsigned int*)(0x424A4980UL))
#define bM0P_CT5_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A4984UL))
#define bM0P_CT5_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A4988UL))
#define bM0P_CT5_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A498CUL))
#define bM0P_CT5_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A4990UL))
#define bM0P_CT5_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A4994UL))
#define bM0P_CT5_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A4998UL))
#define bM0P_CT5_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A49A0UL))
#define bM0P_CT5_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A49A4UL))
#define bM0P_CT5_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A49A8UL))
#define bM0P_CT5_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A49ACUL))
#define bM0P_CT5_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A49B0UL))
#define bM0P_CT5_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A49B4UL))
#define bM0P_CT5_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A49B8UL))
#define bM0P_CT5_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A4A00UL))
#define bM0P_CT5_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A4A04UL))
#define bM0P_CT5_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A4A08UL))
#define bM0P_CT5_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A4A10UL))
#define bM0P_CT5_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A4A14UL))
#define bM0P_CT5_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A4A18UL))
#define bM0P_CT5_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A4A20UL))
#define bM0P_CT6_PWM_TCR_START                          *((volatile unsigned int*)(0x424A5180UL))
#define bM0P_CT6_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5184UL))
#define bM0P_CT6_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A5188UL))
#define bM0P_CT6_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A518CUL))
#define bM0P_CT6_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5190UL))
#define bM0P_CT6_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5194UL))
#define bM0P_CT6_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5198UL))
#define bM0P_CT6_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A51A0UL))
#define bM0P_CT6_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A51A4UL))
#define bM0P_CT6_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A51A8UL))
#define bM0P_CT6_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A51ACUL))
#define bM0P_CT6_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A51B0UL))
#define bM0P_CT6_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A51B4UL))
#define bM0P_CT6_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A51B8UL))
#define bM0P_CT6_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A5200UL))
#define bM0P_CT6_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A5204UL))
#define bM0P_CT6_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A5208UL))
#define bM0P_CT6_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A5210UL))
#define bM0P_CT6_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A5214UL))
#define bM0P_CT6_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A5218UL))
#define bM0P_CT6_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5220UL))
#define bM0P_CT7_PWM_TCR_START                          *((volatile unsigned int*)(0x424A5980UL))
#define bM0P_CT7_PWM_TCR_ENCNT                          *((volatile unsigned int*)(0x424A5984UL))
#define bM0P_CT7_PWM_TCR_MODS                           *((volatile unsigned int*)(0x424A5988UL))
#define bM0P_CT7_PWM_TCR_PLRT                           *((volatile unsigned int*)(0x424A598CUL))
#define bM0P_CT7_PWM_TCR_FUNC0                          *((volatile unsigned int*)(0x424A5990UL))
#define bM0P_CT7_PWM_TCR_FUNC1                          *((volatile unsigned int*)(0x424A5994UL))
#define bM0P_CT7_PWM_TCR_FUNC2                          *((volatile unsigned int*)(0x424A5998UL))
#define bM0P_CT7_PWM_TCR_EDGS0                          *((volatile unsigned int*)(0x424A59A0UL))
#define bM0P_CT7_PWM_TCR_EDGS1                          *((volatile unsigned int*)(0x424A59A4UL))
#define bM0P_CT7_PWM_TCR_MASK                           *((volatile unsigned int*)(0x424A59A8UL))
#define bM0P_CT7_PWM_TCR_RSTEN                          *((volatile unsigned int*)(0x424A59ACUL))
#define bM0P_CT7_PWM_TCR_CLKS0                          *((volatile unsigned int*)(0x424A59B0UL))
#define bM0P_CT7_PWM_TCR_CLKS1                          *((volatile unsigned int*)(0x424A59B4UL))
#define bM0P_CT7_PWM_TCR_CLKS2                          *((volatile unsigned int*)(0x424A59B8UL))
#define bM0P_CT7_PWM_STA_UDFIR                          *((volatile unsigned int*)(0x424A5A00UL))
#define bM0P_CT7_PWM_STA_DTMIR                          *((volatile unsigned int*)(0x424A5A04UL))
#define bM0P_CT7_PWM_STA_TRGIR                          *((volatile unsigned int*)(0x424A5A08UL))
#define bM0P_CT7_PWM_STA_UDFIE                          *((volatile unsigned int*)(0x424A5A10UL))
#define bM0P_CT7_PWM_STA_DTMIE                          *((volatile unsigned int*)(0x424A5A14UL))
#define bM0P_CT7_PWM_STA_TRGIE                          *((volatile unsigned int*)(0x424A5A18UL))
#define bM0P_CT7_PWM_TCR2_CLKS3                         *((volatile unsigned int*)(0x424A5A20UL))
#define bM0P_CT0_RT_TCR_START                           *((volatile unsigned int*)(0x424A0180UL))
#define bM0P_CT0_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A0184UL))
#define bM0P_CT0_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A0188UL))
#define bM0P_CT0_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A018CUL))
#define bM0P_CT0_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A0190UL))
#define bM0P_CT0_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A0194UL))
#define bM0P_CT0_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A0198UL))
#define bM0P_CT0_RT_TCR_T32                             *((volatile unsigned int*)(0x424A019CUL))
#define bM0P_CT0_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A01A0UL))
#define bM0P_CT0_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A01A4UL))
#define bM0P_CT0_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A01B0UL))
#define bM0P_CT0_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A01B4UL))
#define bM0P_CT0_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A01B8UL))
#define bM0P_CT0_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A0200UL))
#define bM0P_CT0_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A0208UL))
#define bM0P_CT0_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A0210UL))
#define bM0P_CT0_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A0218UL))
#define bM0P_CT0_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A0220UL))
#define bM0P_CT0_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A023CUL))
#define bM0P_CT1_RT_TCR_START                           *((volatile unsigned int*)(0x424A0980UL))
#define bM0P_CT1_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A0984UL))
#define bM0P_CT1_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A0988UL))
#define bM0P_CT1_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A098CUL))
#define bM0P_CT1_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A0990UL))
#define bM0P_CT1_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A0994UL))
#define bM0P_CT1_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A0998UL))
#define bM0P_CT1_RT_TCR_T32                             *((volatile unsigned int*)(0x424A099CUL))
#define bM0P_CT1_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A09A0UL))
#define bM0P_CT1_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A09A4UL))
#define bM0P_CT1_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A09B0UL))
#define bM0P_CT1_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A09B4UL))
#define bM0P_CT1_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A09B8UL))
#define bM0P_CT1_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A0A00UL))
#define bM0P_CT1_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A0A08UL))
#define bM0P_CT1_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A0A10UL))
#define bM0P_CT1_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A0A18UL))
#define bM0P_CT1_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A0A20UL))
#define bM0P_CT1_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A0A3CUL))
#define bM0P_CT2_RT_TCR_START                           *((volatile unsigned int*)(0x424A1180UL))
#define bM0P_CT2_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A1184UL))
#define bM0P_CT2_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A1188UL))
#define bM0P_CT2_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A118CUL))
#define bM0P_CT2_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A1190UL))
#define bM0P_CT2_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A1194UL))
#define bM0P_CT2_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A1198UL))
#define bM0P_CT2_RT_TCR_T32                             *((volatile unsigned int*)(0x424A119CUL))
#define bM0P_CT2_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A11A0UL))
#define bM0P_CT2_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A11A4UL))
#define bM0P_CT2_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A11B0UL))
#define bM0P_CT2_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A11B4UL))
#define bM0P_CT2_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A11B8UL))
#define bM0P_CT2_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A1200UL))
#define bM0P_CT2_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A1208UL))
#define bM0P_CT2_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A1210UL))
#define bM0P_CT2_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A1218UL))
#define bM0P_CT2_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A1220UL))
#define bM0P_CT2_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A123CUL))
#define bM0P_CT3_RT_TCR_START                           *((volatile unsigned int*)(0x424A1980UL))
#define bM0P_CT3_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A1984UL))
#define bM0P_CT3_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A1988UL))
#define bM0P_CT3_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A198CUL))
#define bM0P_CT3_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A1990UL))
#define bM0P_CT3_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A1994UL))
#define bM0P_CT3_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A1998UL))
#define bM0P_CT3_RT_TCR_T32                             *((volatile unsigned int*)(0x424A199CUL))
#define bM0P_CT3_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A19A0UL))
#define bM0P_CT3_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A19A4UL))
#define bM0P_CT3_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A19B0UL))
#define bM0P_CT3_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A19B4UL))
#define bM0P_CT3_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A19B8UL))
#define bM0P_CT3_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A1A00UL))
#define bM0P_CT3_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A1A08UL))
#define bM0P_CT3_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A1A10UL))
#define bM0P_CT3_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A1A18UL))
#define bM0P_CT3_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A1A20UL))
#define bM0P_CT3_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A1A3CUL))
#define bM0P_CT4_RT_TCR_START                           *((volatile unsigned int*)(0x424A4180UL))
#define bM0P_CT4_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A4184UL))
#define bM0P_CT4_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A4188UL))
#define bM0P_CT4_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A418CUL))
#define bM0P_CT4_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A4190UL))
#define bM0P_CT4_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A4194UL))
#define bM0P_CT4_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A4198UL))
#define bM0P_CT4_RT_TCR_T32                             *((volatile unsigned int*)(0x424A419CUL))
#define bM0P_CT4_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A41A0UL))
#define bM0P_CT4_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A41A4UL))
#define bM0P_CT4_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A41B0UL))
#define bM0P_CT4_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A41B4UL))
#define bM0P_CT4_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A41B8UL))
#define bM0P_CT4_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A4200UL))
#define bM0P_CT4_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A4208UL))
#define bM0P_CT4_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A4210UL))
#define bM0P_CT4_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A4218UL))
#define bM0P_CT4_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A4220UL))
#define bM0P_CT4_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A423CUL))
#define bM0P_CT5_RT_TCR_START                           *((volatile unsigned int*)(0x424A4980UL))
#define bM0P_CT5_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A4984UL))
#define bM0P_CT5_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A4988UL))
#define bM0P_CT5_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A498CUL))
#define bM0P_CT5_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A4990UL))
#define bM0P_CT5_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A4994UL))
#define bM0P_CT5_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A4998UL))
#define bM0P_CT5_RT_TCR_T32                             *((volatile unsigned int*)(0x424A499CUL))
#define bM0P_CT5_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A49A0UL))
#define bM0P_CT5_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A49A4UL))
#define bM0P_CT5_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A49B0UL))
#define bM0P_CT5_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A49B4UL))
#define bM0P_CT5_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A49B8UL))
#define bM0P_CT5_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A4A00UL))
#define bM0P_CT5_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A4A08UL))
#define bM0P_CT5_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A4A10UL))
#define bM0P_CT5_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A4A18UL))
#define bM0P_CT5_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A4A20UL))
#define bM0P_CT5_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A4A3CUL))
#define bM0P_CT6_RT_TCR_START                           *((volatile unsigned int*)(0x424A5180UL))
#define bM0P_CT6_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A5184UL))
#define bM0P_CT6_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A5188UL))
#define bM0P_CT6_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A518CUL))
#define bM0P_CT6_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A5190UL))
#define bM0P_CT6_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A5194UL))
#define bM0P_CT6_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A5198UL))
#define bM0P_CT6_RT_TCR_T32                             *((volatile unsigned int*)(0x424A519CUL))
#define bM0P_CT6_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A51A0UL))
#define bM0P_CT6_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A51A4UL))
#define bM0P_CT6_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A51B0UL))
#define bM0P_CT6_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A51B4UL))
#define bM0P_CT6_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A51B8UL))
#define bM0P_CT6_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A5200UL))
#define bM0P_CT6_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A5208UL))
#define bM0P_CT6_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A5210UL))
#define bM0P_CT6_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A5218UL))
#define bM0P_CT6_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A5220UL))
#define bM0P_CT6_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A523CUL))
#define bM0P_CT7_RT_TCR_START                           *((volatile unsigned int*)(0x424A5980UL))
#define bM0P_CT7_RT_TCR_ENCNT                           *((volatile unsigned int*)(0x424A5984UL))
#define bM0P_CT7_RT_TCR_MODS                            *((volatile unsigned int*)(0x424A5988UL))
#define bM0P_CT7_RT_TCR_PLRT                            *((volatile unsigned int*)(0x424A598CUL))
#define bM0P_CT7_RT_TCR_FUNC0                           *((volatile unsigned int*)(0x424A5990UL))
#define bM0P_CT7_RT_TCR_FUNC1                           *((volatile unsigned int*)(0x424A5994UL))
#define bM0P_CT7_RT_TCR_FUNC2                           *((volatile unsigned int*)(0x424A5998UL))
#define bM0P_CT7_RT_TCR_T32                             *((volatile unsigned int*)(0x424A599CUL))
#define bM0P_CT7_RT_TCR_EDGS0                           *((volatile unsigned int*)(0x424A59A0UL))
#define bM0P_CT7_RT_TCR_EDGS1                           *((volatile unsigned int*)(0x424A59A4UL))
#define bM0P_CT7_RT_TCR_CLKS0                           *((volatile unsigned int*)(0x424A59B0UL))
#define bM0P_CT7_RT_TCR_CLKS1                           *((volatile unsigned int*)(0x424A59B4UL))
#define bM0P_CT7_RT_TCR_CLKS2                           *((volatile unsigned int*)(0x424A59B8UL))
#define bM0P_CT7_RT_STA_UDFIR                           *((volatile unsigned int*)(0x424A5A00UL))
#define bM0P_CT7_RT_STA_TRGIR                           *((volatile unsigned int*)(0x424A5A08UL))
#define bM0P_CT7_RT_STA_UDFIE                           *((volatile unsigned int*)(0x424A5A10UL))
#define bM0P_CT7_RT_STA_TRGIE                           *((volatile unsigned int*)(0x424A5A18UL))
#define bM0P_CT7_RT_TCR2_CLKS3                          *((volatile unsigned int*)(0x424A5A20UL))
#define bM0P_CT7_RT_TCR2_GTIE                           *((volatile unsigned int*)(0x424A5A3CUL))
#define bM0P_DTIM1_TIMERCTRL_ONESHOT                    *((volatile unsigned int*)(0x422A0100UL))
#define bM0P_DTIM1_TIMERCTRL_TMRSIZE                    *((volatile unsigned int*)(0x422A0104UL))
#define bM0P_DTIM1_TIMERCTRL_TMRPRE0                    *((volatile unsigned int*)(0x422A0108UL))
#define bM0P_DTIM1_TIMERCTRL_TMRPRE1                    *((volatile unsigned int*)(0x422A010CUL))
#define bM0P_DTIM1_TIMERCTRL_INTEN                      *((volatile unsigned int*)(0x422A0114UL))
#define bM0P_DTIM1_TIMERCTRL_TMRMODE                    *((volatile unsigned int*)(0x422A0118UL))
#define bM0P_DTIM1_TIMERCTRL_TMREN                      *((volatile unsigned int*)(0x422A011CUL))
#define bM0P_DTIM1_TIMERRIS_TMRINTST                    *((volatile unsigned int*)(0x422A0200UL))
#define bM0P_DTIM1_TIMERMIS_TMRMINTST                   *((volatile unsigned int*)(0x422A0280UL))
#define bM0P_DTIM2_TIMERCTRL_ONESHOT                    *((volatile unsigned int*)(0x422A0500UL))
#define bM0P_DTIM2_TIMERCTRL_TMRSIZE                    *((volatile unsigned int*)(0x422A0504UL))
#define bM0P_DTIM2_TIMERCTRL_TMRPRE0                    *((volatile unsigned int*)(0x422A0508UL))
#define bM0P_DTIM2_TIMERCTRL_TMRPRE1                    *((volatile unsigned int*)(0x422A050CUL))
#define bM0P_DTIM2_TIMERCTRL_INTEN                      *((volatile unsigned int*)(0x422A0514UL))
#define bM0P_DTIM2_TIMERCTRL_TMRMODE                    *((volatile unsigned int*)(0x422A0518UL))
#define bM0P_DTIM2_TIMERCTRL_TMREN                      *((volatile unsigned int*)(0x422A051CUL))
#define bM0P_DTIM2_TIMERRIS_TMRINTST                    *((volatile unsigned int*)(0x422A0600UL))
#define bM0P_DTIM2_TIMERMIS_TMRMINTST                   *((volatile unsigned int*)(0x422A0680UL))
#define bM0P_EXTINT_INTEN_EN0                           *((volatile unsigned int*)(0x42600000UL))
#define bM0P_EXTINT_INTEN_EN1                           *((volatile unsigned int*)(0x42600004UL))
#define bM0P_EXTINT_INTEN_EN2                           *((volatile unsigned int*)(0x42600008UL))
#define bM0P_EXTINT_INTEN_EN3                           *((volatile unsigned int*)(0x4260000CUL))
#define bM0P_EXTINT_INTEN_EN4                           *((volatile unsigned int*)(0x42600010UL))
#define bM0P_EXTINT_INTEN_EN5                           *((volatile unsigned int*)(0x42600014UL))
#define bM0P_EXTINT_INTEN_EN6                           *((volatile unsigned int*)(0x42600018UL))
#define bM0P_EXTINT_INTEN_EN7                           *((volatile unsigned int*)(0x4260001CUL))
#define bM0P_EXTINT_INTEN_EN8                           *((volatile unsigned int*)(0x42600020UL))
#define bM0P_EXTINT_INTEN_EN9                           *((volatile unsigned int*)(0x42600024UL))
#define bM0P_EXTINT_INTEN_EN10                          *((volatile unsigned int*)(0x42600028UL))
#define bM0P_EXTINT_INTEN_EN11                          *((volatile unsigned int*)(0x4260002CUL))
#define bM0P_EXTINT_INTEN_EN12                          *((volatile unsigned int*)(0x42600030UL))
#define bM0P_EXTINT_INTEN_EN13                          *((volatile unsigned int*)(0x42600034UL))
#define bM0P_EXTINT_INTEN_EN14                          *((volatile unsigned int*)(0x42600038UL))
#define bM0P_EXTINT_INTEN_EN15                          *((volatile unsigned int*)(0x4260003CUL))
#define bM0P_EXTINT_INTSRC_SRC0                         *((volatile unsigned int*)(0x42600080UL))
#define bM0P_EXTINT_INTSRC_SRC1                         *((volatile unsigned int*)(0x42600084UL))
#define bM0P_EXTINT_INTSRC_SRC2                         *((volatile unsigned int*)(0x42600088UL))
#define bM0P_EXTINT_INTSRC_SRC3                         *((volatile unsigned int*)(0x4260008CUL))
#define bM0P_EXTINT_INTSRC_SRC4                         *((volatile unsigned int*)(0x42600090UL))
#define bM0P_EXTINT_INTSRC_SRC5                         *((volatile unsigned int*)(0x42600094UL))
#define bM0P_EXTINT_INTSRC_SRC6                         *((volatile unsigned int*)(0x42600098UL))
#define bM0P_EXTINT_INTSRC_SRC7                         *((volatile unsigned int*)(0x4260009CUL))
#define bM0P_EXTINT_INTSRC_SRC8                         *((volatile unsigned int*)(0x426000A0UL))
#define bM0P_EXTINT_INTSRC_SRC9                         *((volatile unsigned int*)(0x426000A4UL))
#define bM0P_EXTINT_INTSRC_SRC10                        *((volatile unsigned int*)(0x426000A8UL))
#define bM0P_EXTINT_INTSRC_SRC11                        *((volatile unsigned int*)(0x426000ACUL))
#define bM0P_EXTINT_INTSRC_SRC12                        *((volatile unsigned int*)(0x426000B0UL))
#define bM0P_EXTINT_INTSRC_SRC13                        *((volatile unsigned int*)(0x426000B4UL))
#define bM0P_EXTINT_INTSRC_SRC14                        *((volatile unsigned int*)(0x426000B8UL))
#define bM0P_EXTINT_INTSRC_SRC15                        *((volatile unsigned int*)(0x426000BCUL))
#define bM0P_EXTINT_INTCLR_CLR0                         *((volatile unsigned int*)(0x42600100UL))
#define bM0P_EXTINT_INTCLR_CLR1                         *((volatile unsigned int*)(0x42600104UL))
#define bM0P_EXTINT_INTCLR_CLR2                         *((volatile unsigned int*)(0x42600108UL))
#define bM0P_EXTINT_INTCLR_CLR3                         *((volatile unsigned int*)(0x4260010CUL))
#define bM0P_EXTINT_INTCLR_CLR4                         *((volatile unsigned int*)(0x42600110UL))
#define bM0P_EXTINT_INTCLR_CLR5                         *((volatile unsigned int*)(0x42600114UL))
#define bM0P_EXTINT_INTCLR_CLR6                         *((volatile unsigned int*)(0x42600118UL))
#define bM0P_EXTINT_INTCLR_CLR7                         *((volatile unsigned int*)(0x4260011CUL))
#define bM0P_EXTINT_INTCLR_CLR8                         *((volatile unsigned int*)(0x42600120UL))
#define bM0P_EXTINT_INTCLR_CLR9                         *((volatile unsigned int*)(0x42600124UL))
#define bM0P_EXTINT_INTCLR_CLR10                        *((volatile unsigned int*)(0x42600128UL))
#define bM0P_EXTINT_INTCLR_CLR11                        *((volatile unsigned int*)(0x4260012CUL))
#define bM0P_EXTINT_INTCLR_CLR12                        *((volatile unsigned int*)(0x42600130UL))
#define bM0P_EXTINT_INTCLR_CLR13                        *((volatile unsigned int*)(0x42600134UL))
#define bM0P_EXTINT_INTCLR_CLR14                        *((volatile unsigned int*)(0x42600138UL))
#define bM0P_EXTINT_INTCLR_CLR15                        *((volatile unsigned int*)(0x4260013CUL))
#define bM0P_EXTINT_INTLVL_LVLL0                        *((volatile unsigned int*)(0x42600180UL))
#define bM0P_EXTINT_INTLVL_LVLH0                        *((volatile unsigned int*)(0x42600184UL))
#define bM0P_EXTINT_INTLVL_LVLL1                        *((volatile unsigned int*)(0x42600188UL))
#define bM0P_EXTINT_INTLVL_LVLH1                        *((volatile unsigned int*)(0x4260018CUL))
#define bM0P_EXTINT_INTLVL_LVLL2                        *((volatile unsigned int*)(0x42600190UL))
#define bM0P_EXTINT_INTLVL_LVLH2                        *((volatile unsigned int*)(0x42600194UL))
#define bM0P_EXTINT_INTLVL_LVLL3                        *((volatile unsigned int*)(0x42600198UL))
#define bM0P_EXTINT_INTLVL_LVLH3                        *((volatile unsigned int*)(0x4260019CUL))
#define bM0P_EXTINT_INTLVL_LVLL4                        *((volatile unsigned int*)(0x426001A0UL))
#define bM0P_EXTINT_INTLVL_LVLH4                        *((volatile unsigned int*)(0x426001A4UL))
#define bM0P_EXTINT_INTLVL_LVLL5                        *((volatile unsigned int*)(0x426001A8UL))
#define bM0P_EXTINT_INTLVL_LVLH5                        *((volatile unsigned int*)(0x426001ACUL))
#define bM0P_EXTINT_INTLVL_LVLL6                        *((volatile unsigned int*)(0x426001B0UL))
#define bM0P_EXTINT_INTLVL_LVLH6                        *((volatile unsigned int*)(0x426001B4UL))
#define bM0P_EXTINT_INTLVL_LVLL7                        *((volatile unsigned int*)(0x426001B8UL))
#define bM0P_EXTINT_INTLVL_LVLH7                        *((volatile unsigned int*)(0x426001BCUL))
#define bM0P_EXTINT_INTLVL_LVLL8                        *((volatile unsigned int*)(0x426001C0UL))
#define bM0P_EXTINT_INTLVL_LVLH8                        *((volatile unsigned int*)(0x426001C4UL))
#define bM0P_EXTINT_INTLVL_LVLL9                        *((volatile unsigned int*)(0x426001C8UL))
#define bM0P_EXTINT_INTLVL_LVLH9                        *((volatile unsigned int*)(0x426001CCUL))
#define bM0P_EXTINT_INTLVL_LVLL10                       *((volatile unsigned int*)(0x426001D0UL))
#define bM0P_EXTINT_INTLVL_LVLH10                       *((volatile unsigned int*)(0x426001D4UL))
#define bM0P_EXTINT_INTLVL_LVLL11                       *((volatile unsigned int*)(0x426001D8UL))
#define bM0P_EXTINT_INTLVL_LVLH11                       *((volatile unsigned int*)(0x426001DCUL))
#define bM0P_EXTINT_INTLVL_LVLL12                       *((volatile unsigned int*)(0x426001E0UL))
#define bM0P_EXTINT_INTLVL_LVLH12                       *((volatile unsigned int*)(0x426001E4UL))
#define bM0P_EXTINT_INTLVL_LVLL13                       *((volatile unsigned int*)(0x426001E8UL))
#define bM0P_EXTINT_INTLVL_LVLH13                       *((volatile unsigned int*)(0x426001ECUL))
#define bM0P_EXTINT_INTLVL_LVLL14                       *((volatile unsigned int*)(0x426001F0UL))
#define bM0P_EXTINT_INTLVL_LVLH14                       *((volatile unsigned int*)(0x426001F4UL))
#define bM0P_EXTINT_INTLVL_LVLL15                       *((volatile unsigned int*)(0x426001F8UL))
#define bM0P_EXTINT_INTLVL_LVLH15                       *((volatile unsigned int*)(0x426001FCUL))
#define bM0P_EXTINT_NMISRC_SRC                          *((volatile unsigned int*)(0x42600280UL))
#define bM0P_EXTINT_NMICLR_CLR                          *((volatile unsigned int*)(0x42600300UL))
#define bM0P_FLASH_FOCR_PRGM                            *((volatile unsigned int*)(0x42000000UL))
#define bM0P_FLASH_FOCR_PERS                            *((volatile unsigned int*)(0x42000004UL))
#define bM0P_FLASH_FOCR_CERS                            *((volatile unsigned int*)(0x42000008UL))
#define bM0P_FLASH_FOCR_DPSTB                           *((volatile unsigned int*)(0x4200000CUL))
#define bM0P_FLASH_FOCR_FRWPW0                          *((volatile unsigned int*)(0x42000040UL))
#define bM0P_FLASH_FOCR_FRWPW1                          *((volatile unsigned int*)(0x42000044UL))
#define bM0P_FLASH_FOCR_FRWPW2                          *((volatile unsigned int*)(0x42000048UL))
#define bM0P_FLASH_FOCR_FRWPW3                          *((volatile unsigned int*)(0x4200004CUL))
#define bM0P_FLASH_FOCR_FRWPW4                          *((volatile unsigned int*)(0x42000050UL))
#define bM0P_FLASH_FOCR_FRWPW5                          *((volatile unsigned int*)(0x42000054UL))
#define bM0P_FLASH_FOCR_FRWPW6                          *((volatile unsigned int*)(0x42000058UL))
#define bM0P_FLASH_FOCR_FRWPW7                          *((volatile unsigned int*)(0x4200005CUL))
#define bM0P_FLASH_FOCR_FRWPW8                          *((volatile unsigned int*)(0x42000060UL))
#define bM0P_FLASH_FOCR_FRWPW9                          *((volatile unsigned int*)(0x42000064UL))
#define bM0P_FLASH_FOCR_FRWPW10                         *((volatile unsigned int*)(0x42000068UL))
#define bM0P_FLASH_FOCR_FRWPW11                         *((volatile unsigned int*)(0x4200006CUL))
#define bM0P_FLASH_FOCR_FRWPW12                         *((volatile unsigned int*)(0x42000070UL))
#define bM0P_FLASH_FOCR_FRWPW13                         *((volatile unsigned int*)(0x42000074UL))
#define bM0P_FLASH_FOCR_FRWPW14                         *((volatile unsigned int*)(0x42000078UL))
#define bM0P_FLASH_FOCR_FRWPW15                         *((volatile unsigned int*)(0x4200007CUL))
#define bM0P_FLASH_FLCR0_LOCK2K0                        *((volatile unsigned int*)(0x42000080UL))
#define bM0P_FLASH_FLCR0_LOCK2K1                        *((volatile unsigned int*)(0x42000084UL))
#define bM0P_FLASH_FLCR0_LOCK2K2                        *((volatile unsigned int*)(0x42000088UL))
#define bM0P_FLASH_FLCR0_LOCK2K3                        *((volatile unsigned int*)(0x4200008CUL))
#define bM0P_FLASH_FLCR0_LOCK2K4                        *((volatile unsigned int*)(0x42000090UL))
#define bM0P_FLASH_FLCR0_LOCK2K5                        *((volatile unsigned int*)(0x42000094UL))
#define bM0P_FLASH_FLCR0_LOCK2K6                        *((volatile unsigned int*)(0x42000098UL))
#define bM0P_FLASH_FLCR0_LOCK2K7                        *((volatile unsigned int*)(0x4200009CUL))
#define bM0P_FLASH_FLCR0_LOCK2K8                        *((volatile unsigned int*)(0x420000A0UL))
#define bM0P_FLASH_FLCR0_LOCK2K9                        *((volatile unsigned int*)(0x420000A4UL))
#define bM0P_FLASH_FLCR0_LOCK2K10                       *((volatile unsigned int*)(0x420000A8UL))
#define bM0P_FLASH_FLCR0_LOCK2K11                       *((volatile unsigned int*)(0x420000ACUL))
#define bM0P_FLASH_FLCR0_LOCK2K12                       *((volatile unsigned int*)(0x420000B0UL))
#define bM0P_FLASH_FLCR0_LOCK2K13                       *((volatile unsigned int*)(0x420000B4UL))
#define bM0P_FLASH_FLCR0_LOCK2K14                       *((volatile unsigned int*)(0x420000B8UL))
#define bM0P_FLASH_FLCR0_LOCK2K15                       *((volatile unsigned int*)(0x420000BCUL))
#define bM0P_FLASH_FLCR0_LOCK2K16                       *((volatile unsigned int*)(0x420000C0UL))
#define bM0P_FLASH_FLCR0_LOCK2K17                       *((volatile unsigned int*)(0x420000C4UL))
#define bM0P_FLASH_FLCR0_LOCK2K18                       *((volatile unsigned int*)(0x420000C8UL))
#define bM0P_FLASH_FLCR0_LOCK2K19                       *((volatile unsigned int*)(0x420000CCUL))
#define bM0P_FLASH_FLCR0_LOCK2K20                       *((volatile unsigned int*)(0x420000D0UL))
#define bM0P_FLASH_FLCR0_LOCK2K21                       *((volatile unsigned int*)(0x420000D4UL))
#define bM0P_FLASH_FLCR0_LOCK2K22                       *((volatile unsigned int*)(0x420000D8UL))
#define bM0P_FLASH_FLCR0_LOCK2K23                       *((volatile unsigned int*)(0x420000DCUL))
#define bM0P_FLASH_FLCR0_LOCK2K24                       *((volatile unsigned int*)(0x420000E0UL))
#define bM0P_FLASH_FLCR0_LOCK2K25                       *((volatile unsigned int*)(0x420000E4UL))
#define bM0P_FLASH_FLCR0_LOCK2K26                       *((volatile unsigned int*)(0x420000E8UL))
#define bM0P_FLASH_FLCR0_LOCK2K27                       *((volatile unsigned int*)(0x420000ECUL))
#define bM0P_FLASH_FLCR0_LOCK2K28                       *((volatile unsigned int*)(0x420000F0UL))
#define bM0P_FLASH_FLCR0_LOCK2K29                       *((volatile unsigned int*)(0x420000F4UL))
#define bM0P_FLASH_FLCR0_LOCK2K30                       *((volatile unsigned int*)(0x420000F8UL))
#define bM0P_FLASH_FLCR0_LOCK2K31                       *((volatile unsigned int*)(0x420000FCUL))
#define bM0P_FLASH_FLCR1_LOCK2K0                        *((volatile unsigned int*)(0x42000100UL))
#define bM0P_FLASH_FLCR1_LOCK2K1                        *((volatile unsigned int*)(0x42000104UL))
#define bM0P_FLASH_FLCR1_LOCK2K2                        *((volatile unsigned int*)(0x42000108UL))
#define bM0P_FLASH_FLCR1_LOCK2K3                        *((volatile unsigned int*)(0x4200010CUL))
#define bM0P_FLASH_FLCR1_LOCK2K4                        *((volatile unsigned int*)(0x42000110UL))
#define bM0P_FLASH_FLCR1_LOCK2K5                        *((volatile unsigned int*)(0x42000114UL))
#define bM0P_FLASH_FLCR1_LOCK2K6                        *((volatile unsigned int*)(0x42000118UL))
#define bM0P_FLASH_FLCR1_LOCK2K7                        *((volatile unsigned int*)(0x4200011CUL))
#define bM0P_FLASH_FLCR1_LOCK2K8                        *((volatile unsigned int*)(0x42000120UL))
#define bM0P_FLASH_FLCR1_LOCK2K9                        *((volatile unsigned int*)(0x42000124UL))
#define bM0P_FLASH_FLCR1_LOCK2K10                       *((volatile unsigned int*)(0x42000128UL))
#define bM0P_FLASH_FLCR1_LOCK2K11                       *((volatile unsigned int*)(0x4200012CUL))
#define bM0P_FLASH_FLCR1_LOCK2K12                       *((volatile unsigned int*)(0x42000130UL))
#define bM0P_FLASH_FLCR1_LOCK2K13                       *((volatile unsigned int*)(0x42000134UL))
#define bM0P_FLASH_FLCR1_LOCK2K14                       *((volatile unsigned int*)(0x42000138UL))
#define bM0P_FLASH_FLCR1_LOCK2K15                       *((volatile unsigned int*)(0x4200013CUL))
#define bM0P_FLASH_FLCR1_LOCK2K16                       *((volatile unsigned int*)(0x42000140UL))
#define bM0P_FLASH_FLCR1_LOCK2K17                       *((volatile unsigned int*)(0x42000144UL))
#define bM0P_FLASH_FLCR1_LOCK2K18                       *((volatile unsigned int*)(0x42000148UL))
#define bM0P_FLASH_FLCR1_LOCK2K19                       *((volatile unsigned int*)(0x4200014CUL))
#define bM0P_FLASH_FLCR1_LOCK2K20                       *((volatile unsigned int*)(0x42000150UL))
#define bM0P_FLASH_FLCR1_LOCK2K21                       *((volatile unsigned int*)(0x42000154UL))
#define bM0P_FLASH_FLCR1_LOCK2K22                       *((volatile unsigned int*)(0x42000158UL))
#define bM0P_FLASH_FLCR1_LOCK2K23                       *((volatile unsigned int*)(0x4200015CUL))
#define bM0P_FLASH_FLCR1_LOCK2K24                       *((volatile unsigned int*)(0x42000160UL))
#define bM0P_FLASH_FLCR1_LOCK2K25                       *((volatile unsigned int*)(0x42000164UL))
#define bM0P_FLASH_FLCR1_LOCK2K26                       *((volatile unsigned int*)(0x42000168UL))
#define bM0P_FLASH_FLCR1_LOCK2K27                       *((volatile unsigned int*)(0x4200016CUL))
#define bM0P_FLASH_FLCR1_LOCK2K28                       *((volatile unsigned int*)(0x42000170UL))
#define bM0P_FLASH_FLCR1_LOCK2K29                       *((volatile unsigned int*)(0x42000174UL))
#define bM0P_FLASH_FLCR1_LOCK2K30                       *((volatile unsigned int*)(0x42000178UL))
#define bM0P_FLASH_FLCR1_LOCK2K31                       *((volatile unsigned int*)(0x4200017CUL))
#define bM0P_FLASH_FSTR_BUSY                            *((volatile unsigned int*)(0x42000180UL))
#define bM0P_FLASH_FSTR_KEYVIO                          *((volatile unsigned int*)(0x42000184UL))
#define bM0P_FLASH_FSTR_ACCVIO                          *((volatile unsigned int*)(0x42000188UL))
#define bM0P_FLASH_FSTR_ERR                             *((volatile unsigned int*)(0x4200018CUL))
#define bM0P_FLASH_FSTR_OPVIO                           *((volatile unsigned int*)(0x42000190UL))
#define bM0P_FLASH_FSTR_CFM                             *((volatile unsigned int*)(0x42000194UL))
#define bM0P_FLASH_FSTR_FRWPW0                          *((volatile unsigned int*)(0x420001C0UL))
#define bM0P_FLASH_FSTR_FRWPW1                          *((volatile unsigned int*)(0x420001C4UL))
#define bM0P_FLASH_FSTR_FRWPW2                          *((volatile unsigned int*)(0x420001C8UL))
#define bM0P_FLASH_FSTR_FRWPW3                          *((volatile unsigned int*)(0x420001CCUL))
#define bM0P_FLASH_FSTR_FRWPW4                          *((volatile unsigned int*)(0x420001D0UL))
#define bM0P_FLASH_FSTR_FRWPW5                          *((volatile unsigned int*)(0x420001D4UL))
#define bM0P_FLASH_FSTR_FRWPW6                          *((volatile unsigned int*)(0x420001D8UL))
#define bM0P_FLASH_FSTR_FRWPW7                          *((volatile unsigned int*)(0x420001DCUL))
#define bM0P_FLASH_FSTR_FRWPW8                          *((volatile unsigned int*)(0x420001E0UL))
#define bM0P_FLASH_FSTR_FRWPW9                          *((volatile unsigned int*)(0x420001E4UL))
#define bM0P_FLASH_FSTR_FRWPW10                         *((volatile unsigned int*)(0x420001E8UL))
#define bM0P_FLASH_FSTR_FRWPW11                         *((volatile unsigned int*)(0x420001ECUL))
#define bM0P_FLASH_FSTR_FRWPW12                         *((volatile unsigned int*)(0x420001F0UL))
#define bM0P_FLASH_FSTR_FRWPW13                         *((volatile unsigned int*)(0x420001F4UL))
#define bM0P_FLASH_FSTR_FRWPW14                         *((volatile unsigned int*)(0x420001F8UL))
#define bM0P_FLASH_FSTR_FRWPW15                         *((volatile unsigned int*)(0x420001FCUL))
#define bM0P_FLASH_FWCICR_FIE                           *((volatile unsigned int*)(0x42000200UL))
#define bM0P_FLASH_FWCICR_FWTC0                         *((volatile unsigned int*)(0x42000210UL))
#define bM0P_FLASH_FWCICR_FWTC1                         *((volatile unsigned int*)(0x42000214UL))
#define bM0P_FLASH_FUDR0_UD00                           *((volatile unsigned int*)(0x42000280UL))
#define bM0P_FLASH_FUDR0_UD01                           *((volatile unsigned int*)(0x42000284UL))
#define bM0P_FLASH_FUDR0_UD02                           *((volatile unsigned int*)(0x42000288UL))
#define bM0P_FLASH_FUDR0_UD03                           *((volatile unsigned int*)(0x4200028CUL))
#define bM0P_FLASH_FUDR0_UD04                           *((volatile unsigned int*)(0x42000290UL))
#define bM0P_FLASH_FUDR0_UD05                           *((volatile unsigned int*)(0x42000294UL))
#define bM0P_FLASH_FUDR0_UD06                           *((volatile unsigned int*)(0x42000298UL))
#define bM0P_FLASH_FUDR0_UD07                           *((volatile unsigned int*)(0x4200029CUL))
#define bM0P_FLASH_FUDR0_UD08                           *((volatile unsigned int*)(0x420002A0UL))
#define bM0P_FLASH_FUDR0_UD09                           *((volatile unsigned int*)(0x420002A4UL))
#define bM0P_FLASH_FUDR0_UD010                          *((volatile unsigned int*)(0x420002A8UL))
#define bM0P_FLASH_FUDR0_UD011                          *((volatile unsigned int*)(0x420002ACUL))
#define bM0P_FLASH_FUDR0_UD012                          *((volatile unsigned int*)(0x420002B0UL))
#define bM0P_FLASH_FUDR0_UD013                          *((volatile unsigned int*)(0x420002B4UL))
#define bM0P_FLASH_FUDR0_UD014                          *((volatile unsigned int*)(0x420002B8UL))
#define bM0P_FLASH_FUDR0_UD015                          *((volatile unsigned int*)(0x420002BCUL))
#define bM0P_FLASH_FUDR0_UD016                          *((volatile unsigned int*)(0x420002C0UL))
#define bM0P_FLASH_FUDR0_UD017                          *((volatile unsigned int*)(0x420002C4UL))
#define bM0P_FLASH_FUDR0_UD018                          *((volatile unsigned int*)(0x420002C8UL))
#define bM0P_FLASH_FUDR0_UD019                          *((volatile unsigned int*)(0x420002CCUL))
#define bM0P_FLASH_FUDR0_UD020                          *((volatile unsigned int*)(0x420002D0UL))
#define bM0P_FLASH_FUDR0_UD021                          *((volatile unsigned int*)(0x420002D4UL))
#define bM0P_FLASH_FUDR0_UD022                          *((volatile unsigned int*)(0x420002D8UL))
#define bM0P_FLASH_FUDR0_UD023                          *((volatile unsigned int*)(0x420002DCUL))
#define bM0P_FLASH_FUDR0_UD024                          *((volatile unsigned int*)(0x420002E0UL))
#define bM0P_FLASH_FUDR0_UD025                          *((volatile unsigned int*)(0x420002E4UL))
#define bM0P_FLASH_FUDR0_UD026                          *((volatile unsigned int*)(0x420002E8UL))
#define bM0P_FLASH_FUDR0_UD027                          *((volatile unsigned int*)(0x420002ECUL))
#define bM0P_FLASH_FUDR0_UD028                          *((volatile unsigned int*)(0x420002F0UL))
#define bM0P_FLASH_FUDR0_UD029                          *((volatile unsigned int*)(0x420002F4UL))
#define bM0P_FLASH_FUDR0_UD030                          *((volatile unsigned int*)(0x420002F8UL))
#define bM0P_FLASH_FUDR0_UD031                          *((volatile unsigned int*)(0x420002FCUL))
#define bM0P_FLASH_FUDR1_UD10                           *((volatile unsigned int*)(0x42000300UL))
#define bM0P_FLASH_FUDR1_UD11                           *((volatile unsigned int*)(0x42000304UL))
#define bM0P_FLASH_FUDR1_UD12                           *((volatile unsigned int*)(0x42000308UL))
#define bM0P_FLASH_FUDR1_UD13                           *((volatile unsigned int*)(0x4200030CUL))
#define bM0P_FLASH_FUDR1_UD14                           *((volatile unsigned int*)(0x42000310UL))
#define bM0P_FLASH_FUDR1_UD15                           *((volatile unsigned int*)(0x42000314UL))
#define bM0P_FLASH_FUDR1_UD16                           *((volatile unsigned int*)(0x42000318UL))
#define bM0P_FLASH_FUDR1_UD17                           *((volatile unsigned int*)(0x4200031CUL))
#define bM0P_FLASH_FUDR1_UD18                           *((volatile unsigned int*)(0x42000320UL))
#define bM0P_FLASH_FUDR1_UD19                           *((volatile unsigned int*)(0x42000324UL))
#define bM0P_FLASH_FUDR1_UD110                          *((volatile unsigned int*)(0x42000328UL))
#define bM0P_FLASH_FUDR1_UD111                          *((volatile unsigned int*)(0x4200032CUL))
#define bM0P_FLASH_FUDR1_UD112                          *((volatile unsigned int*)(0x42000330UL))
#define bM0P_FLASH_FUDR1_UD113                          *((volatile unsigned int*)(0x42000334UL))
#define bM0P_FLASH_FUDR1_UD114                          *((volatile unsigned int*)(0x42000338UL))
#define bM0P_FLASH_FUDR1_UD115                          *((volatile unsigned int*)(0x4200033CUL))
#define bM0P_FLASH_FUDR1_UD116                          *((volatile unsigned int*)(0x42000340UL))
#define bM0P_FLASH_FUDR1_UD117                          *((volatile unsigned int*)(0x42000344UL))
#define bM0P_FLASH_FUDR1_UD118                          *((volatile unsigned int*)(0x42000348UL))
#define bM0P_FLASH_FUDR1_UD119                          *((volatile unsigned int*)(0x4200034CUL))
#define bM0P_FLASH_FUDR1_UD120                          *((volatile unsigned int*)(0x42000350UL))
#define bM0P_FLASH_FUDR1_UD121                          *((volatile unsigned int*)(0x42000354UL))
#define bM0P_FLASH_FUDR1_UD122                          *((volatile unsigned int*)(0x42000358UL))
#define bM0P_FLASH_FUDR1_UD123                          *((volatile unsigned int*)(0x4200035CUL))
#define bM0P_FLASH_FUDR1_UD124                          *((volatile unsigned int*)(0x42000360UL))
#define bM0P_FLASH_FUDR1_UD125                          *((volatile unsigned int*)(0x42000364UL))
#define bM0P_FLASH_FUDR1_UD126                          *((volatile unsigned int*)(0x42000368UL))
#define bM0P_FLASH_FUDR1_UD127                          *((volatile unsigned int*)(0x4200036CUL))
#define bM0P_FLASH_FUDR1_UD128                          *((volatile unsigned int*)(0x42000370UL))
#define bM0P_FLASH_FUDR1_UD129                          *((volatile unsigned int*)(0x42000374UL))
#define bM0P_FLASH_FUDR1_UD130                          *((volatile unsigned int*)(0x42000378UL))
#define bM0P_FLASH_FUDR1_UD131                          *((volatile unsigned int*)(0x4200037CUL))
#define bM0P_FLASH_FUDR2_UD20                           *((volatile unsigned int*)(0x42000380UL))
#define bM0P_FLASH_FUDR2_UD21                           *((volatile unsigned int*)(0x42000384UL))
#define bM0P_FLASH_FUDR2_UD22                           *((volatile unsigned int*)(0x42000388UL))
#define bM0P_FLASH_FUDR2_UD23                           *((volatile unsigned int*)(0x4200038CUL))
#define bM0P_FLASH_FUDR2_UD24                           *((volatile unsigned int*)(0x42000390UL))
#define bM0P_FLASH_FUDR2_UD25                           *((volatile unsigned int*)(0x42000394UL))
#define bM0P_FLASH_FUDR2_UD26                           *((volatile unsigned int*)(0x42000398UL))
#define bM0P_FLASH_FUDR2_UD27                           *((volatile unsigned int*)(0x4200039CUL))
#define bM0P_FLASH_FUDR2_UD28                           *((volatile unsigned int*)(0x420003A0UL))
#define bM0P_FLASH_FUDR2_UD29                           *((volatile unsigned int*)(0x420003A4UL))
#define bM0P_FLASH_FUDR2_UD210                          *((volatile unsigned int*)(0x420003A8UL))
#define bM0P_FLASH_FUDR2_UD211                          *((volatile unsigned int*)(0x420003ACUL))
#define bM0P_FLASH_FUDR2_UD212                          *((volatile unsigned int*)(0x420003B0UL))
#define bM0P_FLASH_FUDR2_UD213                          *((volatile unsigned int*)(0x420003B4UL))
#define bM0P_FLASH_FUDR2_UD214                          *((volatile unsigned int*)(0x420003B8UL))
#define bM0P_FLASH_FUDR2_UD215                          *((volatile unsigned int*)(0x420003BCUL))
#define bM0P_FLASH_FUDR2_UD216                          *((volatile unsigned int*)(0x420003C0UL))
#define bM0P_FLASH_FUDR2_UD217                          *((volatile unsigned int*)(0x420003C4UL))
#define bM0P_FLASH_FUDR2_UD218                          *((volatile unsigned int*)(0x420003C8UL))
#define bM0P_FLASH_FUDR2_UD219                          *((volatile unsigned int*)(0x420003CCUL))
#define bM0P_FLASH_FUDR2_UD220                          *((volatile unsigned int*)(0x420003D0UL))
#define bM0P_FLASH_FUDR2_UD221                          *((volatile unsigned int*)(0x420003D4UL))
#define bM0P_FLASH_FUDR2_UD222                          *((volatile unsigned int*)(0x420003D8UL))
#define bM0P_FLASH_FUDR2_UD223                          *((volatile unsigned int*)(0x420003DCUL))
#define bM0P_FLASH_FUDR2_UD224                          *((volatile unsigned int*)(0x420003E0UL))
#define bM0P_FLASH_FUDR2_UD225                          *((volatile unsigned int*)(0x420003E4UL))
#define bM0P_FLASH_FUDR2_UD226                          *((volatile unsigned int*)(0x420003E8UL))
#define bM0P_FLASH_FUDR2_UD227                          *((volatile unsigned int*)(0x420003ECUL))
#define bM0P_FLASH_FUDR2_UD228                          *((volatile unsigned int*)(0x420003F0UL))
#define bM0P_FLASH_FUDR2_UD229                          *((volatile unsigned int*)(0x420003F4UL))
#define bM0P_FLASH_FUDR2_UD230                          *((volatile unsigned int*)(0x420003F8UL))
#define bM0P_FLASH_FUDR2_UD231                          *((volatile unsigned int*)(0x420003FCUL))
#define bM0P_FLASH_FUDR3_UD30                           *((volatile unsigned int*)(0x42000400UL))
#define bM0P_FLASH_FUDR3_UD31                           *((volatile unsigned int*)(0x42000404UL))
#define bM0P_FLASH_FUDR3_UD32                           *((volatile unsigned int*)(0x42000408UL))
#define bM0P_FLASH_FUDR3_UD33                           *((volatile unsigned int*)(0x4200040CUL))
#define bM0P_FLASH_FUDR3_UD34                           *((volatile unsigned int*)(0x42000410UL))
#define bM0P_FLASH_FUDR3_UD35                           *((volatile unsigned int*)(0x42000414UL))
#define bM0P_FLASH_FUDR3_UD36                           *((volatile unsigned int*)(0x42000418UL))
#define bM0P_FLASH_FUDR3_UD37                           *((volatile unsigned int*)(0x4200041CUL))
#define bM0P_FLASH_FUDR3_UD38                           *((volatile unsigned int*)(0x42000420UL))
#define bM0P_FLASH_FUDR3_UD39                           *((volatile unsigned int*)(0x42000424UL))
#define bM0P_FLASH_FUDR3_UD310                          *((volatile unsigned int*)(0x42000428UL))
#define bM0P_FLASH_FUDR3_UD311                          *((volatile unsigned int*)(0x4200042CUL))
#define bM0P_FLASH_FUDR3_UD312                          *((volatile unsigned int*)(0x42000430UL))
#define bM0P_FLASH_FUDR3_UD313                          *((volatile unsigned int*)(0x42000434UL))
#define bM0P_FLASH_FUDR3_UD314                          *((volatile unsigned int*)(0x42000438UL))
#define bM0P_FLASH_FUDR3_UD315                          *((volatile unsigned int*)(0x4200043CUL))
#define bM0P_FLASH_FUDR3_UD316                          *((volatile unsigned int*)(0x42000440UL))
#define bM0P_FLASH_FUDR3_UD317                          *((volatile unsigned int*)(0x42000444UL))
#define bM0P_FLASH_FUDR3_UD318                          *((volatile unsigned int*)(0x42000448UL))
#define bM0P_FLASH_FUDR3_UD319                          *((volatile unsigned int*)(0x4200044CUL))
#define bM0P_FLASH_FUDR3_UD320                          *((volatile unsigned int*)(0x42000450UL))
#define bM0P_FLASH_FUDR3_UD321                          *((volatile unsigned int*)(0x42000454UL))
#define bM0P_FLASH_FUDR3_UD322                          *((volatile unsigned int*)(0x42000458UL))
#define bM0P_FLASH_FUDR3_UD323                          *((volatile unsigned int*)(0x4200045CUL))
#define bM0P_FLASH_FUDR3_UD324                          *((volatile unsigned int*)(0x42000460UL))
#define bM0P_FLASH_FUDR3_UD325                          *((volatile unsigned int*)(0x42000464UL))
#define bM0P_FLASH_FUDR3_UD326                          *((volatile unsigned int*)(0x42000468UL))
#define bM0P_FLASH_FUDR3_UD327                          *((volatile unsigned int*)(0x4200046CUL))
#define bM0P_FLASH_FUDR3_UD328                          *((volatile unsigned int*)(0x42000470UL))
#define bM0P_FLASH_FUDR3_UD329                          *((volatile unsigned int*)(0x42000474UL))
#define bM0P_FLASH_FUDR3_UD330                          *((volatile unsigned int*)(0x42000478UL))
#define bM0P_FLASH_FUDR3_UD331                          *((volatile unsigned int*)(0x4200047CUL))
#define bM0P_FLASH_TNVS_TNVS0                           *((volatile unsigned int*)(0x42000480UL))
#define bM0P_FLASH_TNVS_TNVS1                           *((volatile unsigned int*)(0x42000484UL))
#define bM0P_FLASH_TNVS_TNVS2                           *((volatile unsigned int*)(0x42000488UL))
#define bM0P_FLASH_TNVS_TNVS3                           *((volatile unsigned int*)(0x4200048CUL))
#define bM0P_FLASH_TNVS_TNVS4                           *((volatile unsigned int*)(0x42000490UL))
#define bM0P_FLASH_TNVS_TNVS5                           *((volatile unsigned int*)(0x42000494UL))
#define bM0P_FLASH_TNVS_TNVS6                           *((volatile unsigned int*)(0x42000498UL))
#define bM0P_FLASH_TNVS_TNVS7                           *((volatile unsigned int*)(0x4200049CUL))
#define bM0P_FLASH_TPROG_TPROG0                         *((volatile unsigned int*)(0x42000500UL))
#define bM0P_FLASH_TPROG_TPROG1                         *((volatile unsigned int*)(0x42000504UL))
#define bM0P_FLASH_TPROG_TPROG2                         *((volatile unsigned int*)(0x42000508UL))
#define bM0P_FLASH_TPROG_TPROG3                         *((volatile unsigned int*)(0x4200050CUL))
#define bM0P_FLASH_TPROG_TPROG4                         *((volatile unsigned int*)(0x42000510UL))
#define bM0P_FLASH_TPROG_TPROG5                         *((volatile unsigned int*)(0x42000514UL))
#define bM0P_FLASH_TPROG_TPROG6                         *((volatile unsigned int*)(0x42000518UL))
#define bM0P_FLASH_TPROG_TPROG7                         *((volatile unsigned int*)(0x4200051CUL))
#define bM0P_FLASH_TPGS_TPGS0                           *((volatile unsigned int*)(0x42000580UL))
#define bM0P_FLASH_TPGS_TPGS1                           *((volatile unsigned int*)(0x42000584UL))
#define bM0P_FLASH_TPGS_TPGS2                           *((volatile unsigned int*)(0x42000588UL))
#define bM0P_FLASH_TPGS_TPGS3                           *((volatile unsigned int*)(0x4200058CUL))
#define bM0P_FLASH_TPGS_TPGS4                           *((volatile unsigned int*)(0x42000590UL))
#define bM0P_FLASH_TPGS_TPGS5                           *((volatile unsigned int*)(0x42000594UL))
#define bM0P_FLASH_TPGS_TPGS6                           *((volatile unsigned int*)(0x42000598UL))
#define bM0P_FLASH_TPGS_TPGS7                           *((volatile unsigned int*)(0x4200059CUL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM0                     *((volatile unsigned int*)(0x42000600UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM1                     *((volatile unsigned int*)(0x42000604UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM2                     *((volatile unsigned int*)(0x42000608UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM3                     *((volatile unsigned int*)(0x4200060CUL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM4                     *((volatile unsigned int*)(0x42000610UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM5                     *((volatile unsigned int*)(0x42000614UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM6                     *((volatile unsigned int*)(0x42000618UL))
#define bM0P_FLASH_TRCVPGM_TRCVPGM7                     *((volatile unsigned int*)(0x4200061CUL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS0                   *((volatile unsigned int*)(0x42000680UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS1                   *((volatile unsigned int*)(0x42000684UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS2                   *((volatile unsigned int*)(0x42000688UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS3                   *((volatile unsigned int*)(0x4200068CUL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS4                   *((volatile unsigned int*)(0x42000690UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS5                   *((volatile unsigned int*)(0x42000694UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS6                   *((volatile unsigned int*)(0x42000698UL))
#define bM0P_FLASH_TRCVPERS_TRCVPERS7                   *((volatile unsigned int*)(0x4200069CUL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS0                   *((volatile unsigned int*)(0x42000700UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS1                   *((volatile unsigned int*)(0x42000704UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS2                   *((volatile unsigned int*)(0x42000708UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS3                   *((volatile unsigned int*)(0x4200070CUL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS4                   *((volatile unsigned int*)(0x42000710UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS5                   *((volatile unsigned int*)(0x42000714UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS6                   *((volatile unsigned int*)(0x42000718UL))
#define bM0P_FLASH_TRCVCERS_TRCVCERS7                   *((volatile unsigned int*)(0x4200071CUL))
#define bM0P_FLASH_TPERS_TPERS0                         *((volatile unsigned int*)(0x42000780UL))
#define bM0P_FLASH_TPERS_TPERS1                         *((volatile unsigned int*)(0x42000784UL))
#define bM0P_FLASH_TPERS_TPERS2                         *((volatile unsigned int*)(0x42000788UL))
#define bM0P_FLASH_TPERS_TPERS3                         *((volatile unsigned int*)(0x4200078CUL))
#define bM0P_FLASH_TPERS_TPERS4                         *((volatile unsigned int*)(0x42000790UL))
#define bM0P_FLASH_TPERS_TPERS5                         *((volatile unsigned int*)(0x42000794UL))
#define bM0P_FLASH_TPERS_TPERS6                         *((volatile unsigned int*)(0x42000798UL))
#define bM0P_FLASH_TPERS_TPERS7                         *((volatile unsigned int*)(0x4200079CUL))
#define bM0P_FLASH_TCERS_TCERS0                         *((volatile unsigned int*)(0x42000800UL))
#define bM0P_FLASH_TCERS_TCERS1                         *((volatile unsigned int*)(0x42000804UL))
#define bM0P_FLASH_TCERS_TCERS2                         *((volatile unsigned int*)(0x42000808UL))
#define bM0P_FLASH_TCERS_TCERS3                         *((volatile unsigned int*)(0x4200080CUL))
#define bM0P_FLASH_TCERS_TCERS4                         *((volatile unsigned int*)(0x42000810UL))
#define bM0P_FLASH_TCERS_TCERS5                         *((volatile unsigned int*)(0x42000814UL))
#define bM0P_FLASH_TCERS_TCERS6                         *((volatile unsigned int*)(0x42000818UL))
#define bM0P_FLASH_TCERS_TCERS7                         *((volatile unsigned int*)(0x4200081CUL))
#define bM0P_GPIO_FN0_P00                               *((volatile unsigned int*)(0x42660000UL))
#define bM0P_GPIO_FN0_P01                               *((volatile unsigned int*)(0x42660004UL))
#define bM0P_GPIO_FN0_P02                               *((volatile unsigned int*)(0x42660008UL))
#define bM0P_GPIO_FN0_P03                               *((volatile unsigned int*)(0x4266000CUL))
#define bM0P_GPIO_FN0_P04                               *((volatile unsigned int*)(0x42660010UL))
#define bM0P_GPIO_FN0_P05                               *((volatile unsigned int*)(0x42660014UL))
#define bM0P_GPIO_FN0_P06                               *((volatile unsigned int*)(0x42660018UL))
#define bM0P_GPIO_FN0_P07                               *((volatile unsigned int*)(0x4266001CUL))
#define bM0P_GPIO_FN1_P10                               *((volatile unsigned int*)(0x42660080UL))
#define bM0P_GPIO_FN1_P11                               *((volatile unsigned int*)(0x42660084UL))
#define bM0P_GPIO_FN1_P12                               *((volatile unsigned int*)(0x42660088UL))
#define bM0P_GPIO_FN1_P13                               *((volatile unsigned int*)(0x4266008CUL))
#define bM0P_GPIO_FN1_P14                               *((volatile unsigned int*)(0x42660090UL))
#define bM0P_GPIO_FN1_P15                               *((volatile unsigned int*)(0x42660094UL))
#define bM0P_GPIO_FN1_P16                               *((volatile unsigned int*)(0x42660098UL))
#define bM0P_GPIO_FN1_P17                               *((volatile unsigned int*)(0x4266009CUL))
#define bM0P_GPIO_FN2_P20                               *((volatile unsigned int*)(0x42660100UL))
#define bM0P_GPIO_FN2_P21                               *((volatile unsigned int*)(0x42660104UL))
#define bM0P_GPIO_FN2_P22                               *((volatile unsigned int*)(0x42660108UL))
#define bM0P_GPIO_FN2_P23                               *((volatile unsigned int*)(0x4266010CUL))
#define bM0P_GPIO_FN2_P24                               *((volatile unsigned int*)(0x42660110UL))
#define bM0P_GPIO_FN2_P25                               *((volatile unsigned int*)(0x42660114UL))
#define bM0P_GPIO_FN2_P26                               *((volatile unsigned int*)(0x42660118UL))
#define bM0P_GPIO_FN2_P27                               *((volatile unsigned int*)(0x4266011CUL))
#define bM0P_GPIO_FN3_P30                               *((volatile unsigned int*)(0x42660180UL))
#define bM0P_GPIO_FN3_P31                               *((volatile unsigned int*)(0x42660184UL))
#define bM0P_GPIO_FN3_P34                               *((volatile unsigned int*)(0x42660190UL))
#define bM0P_GPIO_FN3_P35                               *((volatile unsigned int*)(0x42660194UL))
#define bM0P_GPIO_FN3_P36                               *((volatile unsigned int*)(0x42660198UL))
#define bM0P_GPIO_FN3_P37                               *((volatile unsigned int*)(0x4266019CUL))
#define bM0P_GPIO_FN4_P40                               *((volatile unsigned int*)(0x42660200UL))
#define bM0P_GPIO_FN4_P41                               *((volatile unsigned int*)(0x42660204UL))
#define bM0P_GPIO_FN4_P45                               *((volatile unsigned int*)(0x42660214UL))
#define bM0P_GPIO_FN4_P46                               *((volatile unsigned int*)(0x42660218UL))
#define bM0P_GPIO_FN4_P47                               *((volatile unsigned int*)(0x4266021CUL))
#define bM0P_GPIO_FN5_P50                               *((volatile unsigned int*)(0x42660280UL))
#define bM0P_GPIO_FN5_P51                               *((volatile unsigned int*)(0x42660284UL))
#define bM0P_GPIO_FN5_P52                               *((volatile unsigned int*)(0x42660288UL))
#define bM0P_GPIO_FN5_P53                               *((volatile unsigned int*)(0x4266028CUL))
#define bM0P_GPIO_FN5_P54                               *((volatile unsigned int*)(0x42660290UL))
#define bM0P_GPIO_FN5_P55                               *((volatile unsigned int*)(0x42660294UL))
#define bM0P_GPIO_FN5_P56                               *((volatile unsigned int*)(0x42660298UL))
#define bM0P_GPIO_FN5_P57                               *((volatile unsigned int*)(0x4266029CUL))
#define bM0P_GPIO_FN6_P60                               *((volatile unsigned int*)(0x42660300UL))
#define bM0P_GPIO_FN6_P61                               *((volatile unsigned int*)(0x42660304UL))
#define bM0P_GPIO_FN6_P62                               *((volatile unsigned int*)(0x42660308UL))
#define bM0P_GPIO_FN6_P63                               *((volatile unsigned int*)(0x4266030CUL))
#define bM0P_GPIO_FN6_P64                               *((volatile unsigned int*)(0x42660310UL))
#define bM0P_GPIO_FN6_P65                               *((volatile unsigned int*)(0x42660314UL))
#define bM0P_GPIO_FN6_P66                               *((volatile unsigned int*)(0x42660318UL))
#define bM0P_GPIO_FN6_P67                               *((volatile unsigned int*)(0x4266031CUL))
#define bM0P_GPIO_FN7_P70                               *((volatile unsigned int*)(0x42660380UL))
#define bM0P_GPIO_FN7_P71                               *((volatile unsigned int*)(0x42660384UL))
#define bM0P_GPIO_FN7_P72                               *((volatile unsigned int*)(0x42660388UL))
#define bM0P_GPIO_FN7_P73                               *((volatile unsigned int*)(0x4266038CUL))
#define bM0P_GPIO_FN7_P74                               *((volatile unsigned int*)(0x42660390UL))
#define bM0P_GPIO_FN8_P80                               *((volatile unsigned int*)(0x42660400UL))
#define bM0P_GPIO_PU0_P00                               *((volatile unsigned int*)(0x42662000UL))
#define bM0P_GPIO_PU0_P01                               *((volatile unsigned int*)(0x42662004UL))
#define bM0P_GPIO_PU0_P02                               *((volatile unsigned int*)(0x42662008UL))
#define bM0P_GPIO_PU0_P03                               *((volatile unsigned int*)(0x4266200CUL))
#define bM0P_GPIO_PU0_P04                               *((volatile unsigned int*)(0x42662010UL))
#define bM0P_GPIO_PU0_P05                               *((volatile unsigned int*)(0x42662014UL))
#define bM0P_GPIO_PU0_P06                               *((volatile unsigned int*)(0x42662018UL))
#define bM0P_GPIO_PU0_P07                               *((volatile unsigned int*)(0x4266201CUL))
#define bM0P_GPIO_PU1_P10                               *((volatile unsigned int*)(0x42662080UL))
#define bM0P_GPIO_PU1_P11                               *((volatile unsigned int*)(0x42662084UL))
#define bM0P_GPIO_PU1_P12                               *((volatile unsigned int*)(0x42662088UL))
#define bM0P_GPIO_PU1_P13                               *((volatile unsigned int*)(0x4266208CUL))
#define bM0P_GPIO_PU1_P14                               *((volatile unsigned int*)(0x42662090UL))
#define bM0P_GPIO_PU1_P15                               *((volatile unsigned int*)(0x42662094UL))
#define bM0P_GPIO_PU1_P16                               *((volatile unsigned int*)(0x42662098UL))
#define bM0P_GPIO_PU1_P17                               *((volatile unsigned int*)(0x4266209CUL))
#define bM0P_GPIO_PU2_P20                               *((volatile unsigned int*)(0x42662100UL))
#define bM0P_GPIO_PU2_P21                               *((volatile unsigned int*)(0x42662104UL))
#define bM0P_GPIO_PU2_P22                               *((volatile unsigned int*)(0x42662108UL))
#define bM0P_GPIO_PU2_P23                               *((volatile unsigned int*)(0x4266210CUL))
#define bM0P_GPIO_PU2_P24                               *((volatile unsigned int*)(0x42662110UL))
#define bM0P_GPIO_PU2_P25                               *((volatile unsigned int*)(0x42662114UL))
#define bM0P_GPIO_PU2_P26                               *((volatile unsigned int*)(0x42662118UL))
#define bM0P_GPIO_PU2_P27                               *((volatile unsigned int*)(0x4266211CUL))
#define bM0P_GPIO_PU3_P30                               *((volatile unsigned int*)(0x42662180UL))
#define bM0P_GPIO_PU3_P31                               *((volatile unsigned int*)(0x42662184UL))
#define bM0P_GPIO_PU3_P34                               *((volatile unsigned int*)(0x42662190UL))
#define bM0P_GPIO_PU3_P35                               *((volatile unsigned int*)(0x42662194UL))
#define bM0P_GPIO_PU3_P36                               *((volatile unsigned int*)(0x42662198UL))
#define bM0P_GPIO_PU3_P37                               *((volatile unsigned int*)(0x4266219CUL))
#define bM0P_GPIO_PU4_P40                               *((volatile unsigned int*)(0x42662200UL))
#define bM0P_GPIO_PU4_P41                               *((volatile unsigned int*)(0x42662204UL))
#define bM0P_GPIO_PU4_P45                               *((volatile unsigned int*)(0x42662214UL))
#define bM0P_GPIO_PU4_P46                               *((volatile unsigned int*)(0x42662218UL))
#define bM0P_GPIO_PU4_P47                               *((volatile unsigned int*)(0x4266221CUL))
#define bM0P_GPIO_PU5_P50                               *((volatile unsigned int*)(0x42662280UL))
#define bM0P_GPIO_PU5_P51                               *((volatile unsigned int*)(0x42662284UL))
#define bM0P_GPIO_PU5_P52                               *((volatile unsigned int*)(0x42662288UL))
#define bM0P_GPIO_PU5_P53                               *((volatile unsigned int*)(0x4266228CUL))
#define bM0P_GPIO_PU5_P54                               *((volatile unsigned int*)(0x42662290UL))
#define bM0P_GPIO_PU5_P55                               *((volatile unsigned int*)(0x42662294UL))
#define bM0P_GPIO_PU5_P56                               *((volatile unsigned int*)(0x42662298UL))
#define bM0P_GPIO_PU5_P57                               *((volatile unsigned int*)(0x4266229CUL))
#define bM0P_GPIO_PU6_P60                               *((volatile unsigned int*)(0x42662300UL))
#define bM0P_GPIO_PU6_P61                               *((volatile unsigned int*)(0x42662304UL))
#define bM0P_GPIO_PU6_P62                               *((volatile unsigned int*)(0x42662308UL))
#define bM0P_GPIO_PU6_P63                               *((volatile unsigned int*)(0x4266230CUL))
#define bM0P_GPIO_PU6_P64                               *((volatile unsigned int*)(0x42662310UL))
#define bM0P_GPIO_PU6_P65                               *((volatile unsigned int*)(0x42662314UL))
#define bM0P_GPIO_PU6_P66                               *((volatile unsigned int*)(0x42662318UL))
#define bM0P_GPIO_PU6_P67                               *((volatile unsigned int*)(0x4266231CUL))
#define bM0P_GPIO_PU7_P70                               *((volatile unsigned int*)(0x42662380UL))
#define bM0P_GPIO_PU7_P71                               *((volatile unsigned int*)(0x42662384UL))
#define bM0P_GPIO_PU7_P72                               *((volatile unsigned int*)(0x42662388UL))
#define bM0P_GPIO_PU7_P73                               *((volatile unsigned int*)(0x4266238CUL))
#define bM0P_GPIO_PU7_P74                               *((volatile unsigned int*)(0x42662390UL))
#define bM0P_GPIO_PU8_P80                               *((volatile unsigned int*)(0x42662400UL))
#define bM0P_GPIO_DIR0_P00                              *((volatile unsigned int*)(0x42664000UL))
#define bM0P_GPIO_DIR0_P01                              *((volatile unsigned int*)(0x42664004UL))
#define bM0P_GPIO_DIR0_P02                              *((volatile unsigned int*)(0x42664008UL))
#define bM0P_GPIO_DIR0_P03                              *((volatile unsigned int*)(0x4266400CUL))
#define bM0P_GPIO_DIR0_P04                              *((volatile unsigned int*)(0x42664010UL))
#define bM0P_GPIO_DIR0_P05                              *((volatile unsigned int*)(0x42664014UL))
#define bM0P_GPIO_DIR0_P06                              *((volatile unsigned int*)(0x42664018UL))
#define bM0P_GPIO_DIR0_P07                              *((volatile unsigned int*)(0x4266401CUL))
#define bM0P_GPIO_DIR1_P10                              *((volatile unsigned int*)(0x42664080UL))
#define bM0P_GPIO_DIR1_P11                              *((volatile unsigned int*)(0x42664084UL))
#define bM0P_GPIO_DIR1_P12                              *((volatile unsigned int*)(0x42664088UL))
#define bM0P_GPIO_DIR1_P13                              *((volatile unsigned int*)(0x4266408CUL))
#define bM0P_GPIO_DIR1_P14                              *((volatile unsigned int*)(0x42664090UL))
#define bM0P_GPIO_DIR1_P15                              *((volatile unsigned int*)(0x42664094UL))
#define bM0P_GPIO_DIR1_P16                              *((volatile unsigned int*)(0x42664098UL))
#define bM0P_GPIO_DIR1_P17                              *((volatile unsigned int*)(0x4266409CUL))
#define bM0P_GPIO_DIR2_P20                              *((volatile unsigned int*)(0x42664100UL))
#define bM0P_GPIO_DIR2_P21                              *((volatile unsigned int*)(0x42664104UL))
#define bM0P_GPIO_DIR2_P22                              *((volatile unsigned int*)(0x42664108UL))
#define bM0P_GPIO_DIR2_P23                              *((volatile unsigned int*)(0x4266410CUL))
#define bM0P_GPIO_DIR2_P24                              *((volatile unsigned int*)(0x42664110UL))
#define bM0P_GPIO_DIR2_P25                              *((volatile unsigned int*)(0x42664114UL))
#define bM0P_GPIO_DIR2_P26                              *((volatile unsigned int*)(0x42664118UL))
#define bM0P_GPIO_DIR2_P27                              *((volatile unsigned int*)(0x4266411CUL))
#define bM0P_GPIO_DIR3_P30                              *((volatile unsigned int*)(0x42664180UL))
#define bM0P_GPIO_DIR3_P31                              *((volatile unsigned int*)(0x42664184UL))
#define bM0P_GPIO_DIR3_P34                              *((volatile unsigned int*)(0x42664190UL))
#define bM0P_GPIO_DIR3_P35                              *((volatile unsigned int*)(0x42664194UL))
#define bM0P_GPIO_DIR3_P36                              *((volatile unsigned int*)(0x42664198UL))
#define bM0P_GPIO_DIR3_P37                              *((volatile unsigned int*)(0x4266419CUL))
#define bM0P_GPIO_DIR4_P40                              *((volatile unsigned int*)(0x42664200UL))
#define bM0P_GPIO_DIR4_P41                              *((volatile unsigned int*)(0x42664204UL))
#define bM0P_GPIO_DIR4_P45                              *((volatile unsigned int*)(0x42664214UL))
#define bM0P_GPIO_DIR4_P46                              *((volatile unsigned int*)(0x42664218UL))
#define bM0P_GPIO_DIR4_P47                              *((volatile unsigned int*)(0x4266421CUL))
#define bM0P_GPIO_DIR5_P50                              *((volatile unsigned int*)(0x42664280UL))
#define bM0P_GPIO_DIR5_P51                              *((volatile unsigned int*)(0x42664284UL))
#define bM0P_GPIO_DIR5_P52                              *((volatile unsigned int*)(0x42664288UL))
#define bM0P_GPIO_DIR5_P53                              *((volatile unsigned int*)(0x4266428CUL))
#define bM0P_GPIO_DIR5_P54                              *((volatile unsigned int*)(0x42664290UL))
#define bM0P_GPIO_DIR5_P55                              *((volatile unsigned int*)(0x42664294UL))
#define bM0P_GPIO_DIR5_P56                              *((volatile unsigned int*)(0x42664298UL))
#define bM0P_GPIO_DIR5_P57                              *((volatile unsigned int*)(0x4266429CUL))
#define bM0P_GPIO_DIR6_P60                              *((volatile unsigned int*)(0x42664300UL))
#define bM0P_GPIO_DIR6_P61                              *((volatile unsigned int*)(0x42664304UL))
#define bM0P_GPIO_DIR6_P62                              *((volatile unsigned int*)(0x42664308UL))
#define bM0P_GPIO_DIR6_P63                              *((volatile unsigned int*)(0x4266430CUL))
#define bM0P_GPIO_DIR6_P64                              *((volatile unsigned int*)(0x42664310UL))
#define bM0P_GPIO_DIR6_P65                              *((volatile unsigned int*)(0x42664314UL))
#define bM0P_GPIO_DIR6_P66                              *((volatile unsigned int*)(0x42664318UL))
#define bM0P_GPIO_DIR6_P67                              *((volatile unsigned int*)(0x4266431CUL))
#define bM0P_GPIO_DIR7_P70                              *((volatile unsigned int*)(0x42664380UL))
#define bM0P_GPIO_DIR7_P71                              *((volatile unsigned int*)(0x42664384UL))
#define bM0P_GPIO_DIR7_P72                              *((volatile unsigned int*)(0x42664388UL))
#define bM0P_GPIO_DIR7_P73                              *((volatile unsigned int*)(0x4266438CUL))
#define bM0P_GPIO_DIR7_P74                              *((volatile unsigned int*)(0x42664390UL))
#define bM0P_GPIO_DIR8_P80                              *((volatile unsigned int*)(0x42664400UL))
#define bM0P_GPIO_GET0_P00                              *((volatile unsigned int*)(0x42666000UL))
#define bM0P_GPIO_GET0_P01                              *((volatile unsigned int*)(0x42666004UL))
#define bM0P_GPIO_GET0_P02                              *((volatile unsigned int*)(0x42666008UL))
#define bM0P_GPIO_GET0_P03                              *((volatile unsigned int*)(0x4266600CUL))
#define bM0P_GPIO_GET0_P04                              *((volatile unsigned int*)(0x42666010UL))
#define bM0P_GPIO_GET0_P05                              *((volatile unsigned int*)(0x42666014UL))
#define bM0P_GPIO_GET0_P06                              *((volatile unsigned int*)(0x42666018UL))
#define bM0P_GPIO_GET0_P07                              *((volatile unsigned int*)(0x4266601CUL))
#define bM0P_GPIO_GET1_P10                              *((volatile unsigned int*)(0x42666080UL))
#define bM0P_GPIO_GET1_P11                              *((volatile unsigned int*)(0x42666084UL))
#define bM0P_GPIO_GET1_P12                              *((volatile unsigned int*)(0x42666088UL))
#define bM0P_GPIO_GET1_P13                              *((volatile unsigned int*)(0x4266608CUL))
#define bM0P_GPIO_GET1_P14                              *((volatile unsigned int*)(0x42666090UL))
#define bM0P_GPIO_GET1_P15                              *((volatile unsigned int*)(0x42666094UL))
#define bM0P_GPIO_GET1_P16                              *((volatile unsigned int*)(0x42666098UL))
#define bM0P_GPIO_GET1_P17                              *((volatile unsigned int*)(0x4266609CUL))
#define bM0P_GPIO_GET2_P20                              *((volatile unsigned int*)(0x42666100UL))
#define bM0P_GPIO_GET2_P21                              *((volatile unsigned int*)(0x42666104UL))
#define bM0P_GPIO_GET2_P22                              *((volatile unsigned int*)(0x42666108UL))
#define bM0P_GPIO_GET2_P23                              *((volatile unsigned int*)(0x4266610CUL))
#define bM0P_GPIO_GET2_P24                              *((volatile unsigned int*)(0x42666110UL))
#define bM0P_GPIO_GET2_P25                              *((volatile unsigned int*)(0x42666114UL))
#define bM0P_GPIO_GET2_P26                              *((volatile unsigned int*)(0x42666118UL))
#define bM0P_GPIO_GET2_P27                              *((volatile unsigned int*)(0x4266611CUL))
#define bM0P_GPIO_GET3_P30                              *((volatile unsigned int*)(0x42666180UL))
#define bM0P_GPIO_GET3_P31                              *((volatile unsigned int*)(0x42666184UL))
#define bM0P_GPIO_GET3_P34                              *((volatile unsigned int*)(0x42666190UL))
#define bM0P_GPIO_GET3_P35                              *((volatile unsigned int*)(0x42666194UL))
#define bM0P_GPIO_GET3_P36                              *((volatile unsigned int*)(0x42666198UL))
#define bM0P_GPIO_GET3_P37                              *((volatile unsigned int*)(0x4266619CUL))
#define bM0P_GPIO_GET4_P40                              *((volatile unsigned int*)(0x42666200UL))
#define bM0P_GPIO_GET4_P41                              *((volatile unsigned int*)(0x42666204UL))
#define bM0P_GPIO_GET4_P45                              *((volatile unsigned int*)(0x42666214UL))
#define bM0P_GPIO_GET4_P46                              *((volatile unsigned int*)(0x42666218UL))
#define bM0P_GPIO_GET4_P47                              *((volatile unsigned int*)(0x4266621CUL))
#define bM0P_GPIO_GET5_P50                              *((volatile unsigned int*)(0x42666280UL))
#define bM0P_GPIO_GET5_P51                              *((volatile unsigned int*)(0x42666284UL))
#define bM0P_GPIO_GET5_P52                              *((volatile unsigned int*)(0x42666288UL))
#define bM0P_GPIO_GET5_P53                              *((volatile unsigned int*)(0x4266628CUL))
#define bM0P_GPIO_GET5_P54                              *((volatile unsigned int*)(0x42666290UL))
#define bM0P_GPIO_GET5_P55                              *((volatile unsigned int*)(0x42666294UL))
#define bM0P_GPIO_GET5_P56                              *((volatile unsigned int*)(0x42666298UL))
#define bM0P_GPIO_GET5_P57                              *((volatile unsigned int*)(0x4266629CUL))
#define bM0P_GPIO_GET6_P60                              *((volatile unsigned int*)(0x42666300UL))
#define bM0P_GPIO_GET6_P61                              *((volatile unsigned int*)(0x42666304UL))
#define bM0P_GPIO_GET6_P62                              *((volatile unsigned int*)(0x42666308UL))
#define bM0P_GPIO_GET6_P63                              *((volatile unsigned int*)(0x4266630CUL))
#define bM0P_GPIO_GET6_P64                              *((volatile unsigned int*)(0x42666310UL))
#define bM0P_GPIO_GET6_P65                              *((volatile unsigned int*)(0x42666314UL))
#define bM0P_GPIO_GET6_P66                              *((volatile unsigned int*)(0x42666318UL))
#define bM0P_GPIO_GET6_P67                              *((volatile unsigned int*)(0x4266631CUL))
#define bM0P_GPIO_GET7_P70                              *((volatile unsigned int*)(0x42666380UL))
#define bM0P_GPIO_GET7_P71                              *((volatile unsigned int*)(0x42666384UL))
#define bM0P_GPIO_GET7_P72                              *((volatile unsigned int*)(0x42666388UL))
#define bM0P_GPIO_GET7_P73                              *((volatile unsigned int*)(0x4266638CUL))
#define bM0P_GPIO_GET7_P74                              *((volatile unsigned int*)(0x42666390UL))
#define bM0P_GPIO_GET8_P80                              *((volatile unsigned int*)(0x42666400UL))
#define bM0P_GPIO_SET0_P00                              *((volatile unsigned int*)(0x42668000UL))
#define bM0P_GPIO_SET0_P01                              *((volatile unsigned int*)(0x42668004UL))
#define bM0P_GPIO_SET0_P02                              *((volatile unsigned int*)(0x42668008UL))
#define bM0P_GPIO_SET0_P03                              *((volatile unsigned int*)(0x4266800CUL))
#define bM0P_GPIO_SET0_P04                              *((volatile unsigned int*)(0x42668010UL))
#define bM0P_GPIO_SET0_P05                              *((volatile unsigned int*)(0x42668014UL))
#define bM0P_GPIO_SET0_P06                              *((volatile unsigned int*)(0x42668018UL))
#define bM0P_GPIO_SET0_P07                              *((volatile unsigned int*)(0x4266801CUL))
#define bM0P_GPIO_SET1_P10                              *((volatile unsigned int*)(0x42668080UL))
#define bM0P_GPIO_SET1_P11                              *((volatile unsigned int*)(0x42668084UL))
#define bM0P_GPIO_SET1_P12                              *((volatile unsigned int*)(0x42668088UL))
#define bM0P_GPIO_SET1_P13                              *((volatile unsigned int*)(0x4266808CUL))
#define bM0P_GPIO_SET1_P14                              *((volatile unsigned int*)(0x42668090UL))
#define bM0P_GPIO_SET1_P15                              *((volatile unsigned int*)(0x42668094UL))
#define bM0P_GPIO_SET1_P16                              *((volatile unsigned int*)(0x42668098UL))
#define bM0P_GPIO_SET1_P17                              *((volatile unsigned int*)(0x4266809CUL))
#define bM0P_GPIO_SET2_P20                              *((volatile unsigned int*)(0x42668100UL))
#define bM0P_GPIO_SET2_P21                              *((volatile unsigned int*)(0x42668104UL))
#define bM0P_GPIO_SET2_P22                              *((volatile unsigned int*)(0x42668108UL))
#define bM0P_GPIO_SET2_P23                              *((volatile unsigned int*)(0x4266810CUL))
#define bM0P_GPIO_SET2_P24                              *((volatile unsigned int*)(0x42668110UL))
#define bM0P_GPIO_SET2_P25                              *((volatile unsigned int*)(0x42668114UL))
#define bM0P_GPIO_SET2_P26                              *((volatile unsigned int*)(0x42668118UL))
#define bM0P_GPIO_SET2_P27                              *((volatile unsigned int*)(0x4266811CUL))
#define bM0P_GPIO_SET3_P30                              *((volatile unsigned int*)(0x42668180UL))
#define bM0P_GPIO_SET3_P31                              *((volatile unsigned int*)(0x42668184UL))
#define bM0P_GPIO_SET3_P34                              *((volatile unsigned int*)(0x42668190UL))
#define bM0P_GPIO_SET3_P35                              *((volatile unsigned int*)(0x42668194UL))
#define bM0P_GPIO_SET3_P36                              *((volatile unsigned int*)(0x42668198UL))
#define bM0P_GPIO_SET3_P37                              *((volatile unsigned int*)(0x4266819CUL))
#define bM0P_GPIO_SET4_P40                              *((volatile unsigned int*)(0x42668200UL))
#define bM0P_GPIO_SET4_P41                              *((volatile unsigned int*)(0x42668204UL))
#define bM0P_GPIO_SET4_P45                              *((volatile unsigned int*)(0x42668214UL))
#define bM0P_GPIO_SET4_P46                              *((volatile unsigned int*)(0x42668218UL))
#define bM0P_GPIO_SET4_P47                              *((volatile unsigned int*)(0x4266821CUL))
#define bM0P_GPIO_SET5_P50                              *((volatile unsigned int*)(0x42668280UL))
#define bM0P_GPIO_SET5_P51                              *((volatile unsigned int*)(0x42668284UL))
#define bM0P_GPIO_SET5_P52                              *((volatile unsigned int*)(0x42668288UL))
#define bM0P_GPIO_SET5_P53                              *((volatile unsigned int*)(0x4266828CUL))
#define bM0P_GPIO_SET5_P54                              *((volatile unsigned int*)(0x42668290UL))
#define bM0P_GPIO_SET5_P55                              *((volatile unsigned int*)(0x42668294UL))
#define bM0P_GPIO_SET5_P56                              *((volatile unsigned int*)(0x42668298UL))
#define bM0P_GPIO_SET5_P57                              *((volatile unsigned int*)(0x4266829CUL))
#define bM0P_GPIO_SET6_P60                              *((volatile unsigned int*)(0x42668300UL))
#define bM0P_GPIO_SET6_P61                              *((volatile unsigned int*)(0x42668304UL))
#define bM0P_GPIO_SET6_P62                              *((volatile unsigned int*)(0x42668308UL))
#define bM0P_GPIO_SET6_P63                              *((volatile unsigned int*)(0x4266830CUL))
#define bM0P_GPIO_SET6_P64                              *((volatile unsigned int*)(0x42668310UL))
#define bM0P_GPIO_SET6_P65                              *((volatile unsigned int*)(0x42668314UL))
#define bM0P_GPIO_SET6_P66                              *((volatile unsigned int*)(0x42668318UL))
#define bM0P_GPIO_SET6_P67                              *((volatile unsigned int*)(0x4266831CUL))
#define bM0P_GPIO_SET7_P70                              *((volatile unsigned int*)(0x42668380UL))
#define bM0P_GPIO_SET7_P71                              *((volatile unsigned int*)(0x42668384UL))
#define bM0P_GPIO_SET7_P72                              *((volatile unsigned int*)(0x42668388UL))
#define bM0P_GPIO_SET7_P73                              *((volatile unsigned int*)(0x4266838CUL))
#define bM0P_GPIO_SET7_P74                              *((volatile unsigned int*)(0x42668390UL))
#define bM0P_GPIO_SET8_P80                              *((volatile unsigned int*)(0x42668400UL))
#define bM0P_GPIO_ANALOG_ADE00                          *((volatile unsigned int*)(0x4266A000UL))
#define bM0P_GPIO_ANALOG_ADE01                          *((volatile unsigned int*)(0x4266A004UL))
#define bM0P_GPIO_ANALOG_ADE02                          *((volatile unsigned int*)(0x4266A008UL))
#define bM0P_GPIO_ANALOG_ADE03                          *((volatile unsigned int*)(0x4266A00CUL))
#define bM0P_GPIO_ANALOG_ADE04                          *((volatile unsigned int*)(0x4266A010UL))
#define bM0P_GPIO_ANALOG_ADE05                          *((volatile unsigned int*)(0x4266A014UL))
#define bM0P_GPIO_ANALOG_ADE06                          *((volatile unsigned int*)(0x4266A018UL))
#define bM0P_GPIO_ANALOG_ADE07                          *((volatile unsigned int*)(0x4266A01CUL))
#define bM0P_GPIO_ANALOG_ADE08                          *((volatile unsigned int*)(0x4266A020UL))
#define bM0P_GPIO_ANALOG_ADE09                          *((volatile unsigned int*)(0x4266A024UL))
#define bM0P_GPIO_ANALOG_ADE10                          *((volatile unsigned int*)(0x4266A028UL))
#define bM0P_GPIO_ANALOG_ADE11                          *((volatile unsigned int*)(0x4266A02CUL))
#define bM0P_GPIO_ANALOG_ADE12                          *((volatile unsigned int*)(0x4266A030UL))
#define bM0P_GPIO_ANALOG_ADE13                          *((volatile unsigned int*)(0x4266A034UL))
#define bM0P_GPIO_ANALOG_ADE14                          *((volatile unsigned int*)(0x4266A038UL))
#define bM0P_GPIO_ANALOG_ADE15                          *((volatile unsigned int*)(0x4266A03CUL))
#define bM0P_GPIO_SPS_SUBCS0                            *((volatile unsigned int*)(0x4266B000UL))
#define bM0P_GPIO_SPS_SUBCS1                            *((volatile unsigned int*)(0x4266B004UL))
#define bM0P_GPIO_SPS_MAINCS0                           *((volatile unsigned int*)(0x4266B008UL))
#define bM0P_GPIO_SPS_MAINCS1                           *((volatile unsigned int*)(0x4266B00CUL))
#define bM0P_GPIO_FN_SEL00_NMIS                         *((volatile unsigned int*)(0x4266C000UL))
#define bM0P_GPIO_FN_SEL00_CROUTE0                      *((volatile unsigned int*)(0x4266C004UL))
#define bM0P_GPIO_FN_SEL00_CROUTE1                      *((volatile unsigned int*)(0x4266C008UL))
#define bM0P_GPIO_FN_SEL00_RTCCOE0                      *((volatile unsigned int*)(0x4266C010UL))
#define bM0P_GPIO_FN_SEL00_RTCCOE1                      *((volatile unsigned int*)(0x4266C014UL))
#define bM0P_GPIO_FN_SEL00_SUBOUTE0                     *((volatile unsigned int*)(0x4266C018UL))
#define bM0P_GPIO_FN_SEL00_SUBOUTE1                     *((volatile unsigned int*)(0x4266C01CUL))
#define bM0P_GPIO_FN_SEL00_SWDEN                        *((volatile unsigned int*)(0x4266C020UL))
#define bM0P_GPIO_FN_SEL02_TIOA0E0                      *((volatile unsigned int*)(0x4266C108UL))
#define bM0P_GPIO_FN_SEL02_TIOA0E1                      *((volatile unsigned int*)(0x4266C10CUL))
#define bM0P_GPIO_FN_SEL02_TIOB0S0                      *((volatile unsigned int*)(0x4266C110UL))
#define bM0P_GPIO_FN_SEL02_TIOB0S1                      *((volatile unsigned int*)(0x4266C114UL))
#define bM0P_GPIO_FN_SEL02_TIOB0S2                      *((volatile unsigned int*)(0x4266C118UL))
#define bM0P_GPIO_FN_SEL02_TIOA1S0                      *((volatile unsigned int*)(0x4266C120UL))
#define bM0P_GPIO_FN_SEL02_TIOA1S1                      *((volatile unsigned int*)(0x4266C124UL))
#define bM0P_GPIO_FN_SEL02_TIOA1E0                      *((volatile unsigned int*)(0x4266C128UL))
#define bM0P_GPIO_FN_SEL02_TIOA1E1                      *((volatile unsigned int*)(0x4266C12CUL))
#define bM0P_GPIO_FN_SEL02_TIOB1S0                      *((volatile unsigned int*)(0x4266C130UL))
#define bM0P_GPIO_FN_SEL02_TIOB1S1                      *((volatile unsigned int*)(0x4266C134UL))
#define bM0P_GPIO_FN_SEL02_TIOA2E0                      *((volatile unsigned int*)(0x4266C148UL))
#define bM0P_GPIO_FN_SEL02_TIOA2E1                      *((volatile unsigned int*)(0x4266C14CUL))
#define bM0P_GPIO_FN_SEL02_TIOB2S0                      *((volatile unsigned int*)(0x4266C150UL))
#define bM0P_GPIO_FN_SEL02_TIOB2S1                      *((volatile unsigned int*)(0x4266C154UL))
#define bM0P_GPIO_FN_SEL02_TIOB2S2                      *((volatile unsigned int*)(0x4266C158UL))
#define bM0P_GPIO_FN_SEL02_TIOA3S0                      *((volatile unsigned int*)(0x4266C160UL))
#define bM0P_GPIO_FN_SEL02_TIOA3S1                      *((volatile unsigned int*)(0x4266C164UL))
#define bM0P_GPIO_FN_SEL02_TIOA3E0                      *((volatile unsigned int*)(0x4266C168UL))
#define bM0P_GPIO_FN_SEL02_TIOA3E1                      *((volatile unsigned int*)(0x4266C16CUL))
#define bM0P_GPIO_FN_SEL02_TIOB3S0                      *((volatile unsigned int*)(0x4266C170UL))
#define bM0P_GPIO_FN_SEL02_TIOB3S1                      *((volatile unsigned int*)(0x4266C174UL))
#define bM0P_GPIO_FN_SEL03_TIOA4E0                      *((volatile unsigned int*)(0x4266C188UL))
#define bM0P_GPIO_FN_SEL03_TIOA4E1                      *((volatile unsigned int*)(0x4266C18CUL))
#define bM0P_GPIO_FN_SEL03_TIOB4S0                      *((volatile unsigned int*)(0x4266C190UL))
#define bM0P_GPIO_FN_SEL03_TIOB4S1                      *((volatile unsigned int*)(0x4266C194UL))
#define bM0P_GPIO_FN_SEL03_TIOA5S0                      *((volatile unsigned int*)(0x4266C1A0UL))
#define bM0P_GPIO_FN_SEL03_TIOA5S1                      *((volatile unsigned int*)(0x4266C1A4UL))
#define bM0P_GPIO_FN_SEL03_TIOA5E0                      *((volatile unsigned int*)(0x4266C1A8UL))
#define bM0P_GPIO_FN_SEL03_TIOA5E1                      *((volatile unsigned int*)(0x4266C1ACUL))
#define bM0P_GPIO_FN_SEL03_TIOB5S0                      *((volatile unsigned int*)(0x4266C1B0UL))
#define bM0P_GPIO_FN_SEL03_TIOB5S1                      *((volatile unsigned int*)(0x4266C1B4UL))
#define bM0P_GPIO_FN_SEL03_TIOA6E0                      *((volatile unsigned int*)(0x4266C1C8UL))
#define bM0P_GPIO_FN_SEL03_TIOA6E1                      *((volatile unsigned int*)(0x4266C1CCUL))
#define bM0P_GPIO_FN_SEL03_TIOB6S0                      *((volatile unsigned int*)(0x4266C1D0UL))
#define bM0P_GPIO_FN_SEL03_TIOB6S1                      *((volatile unsigned int*)(0x4266C1D4UL))
#define bM0P_GPIO_FN_SEL03_TIOA7S0                      *((volatile unsigned int*)(0x4266C1E0UL))
#define bM0P_GPIO_FN_SEL03_TIOA7S1                      *((volatile unsigned int*)(0x4266C1E4UL))
#define bM0P_GPIO_FN_SEL03_TIOA7E0                      *((volatile unsigned int*)(0x4266C1E8UL))
#define bM0P_GPIO_FN_SEL03_TIOA7E1                      *((volatile unsigned int*)(0x4266C1ECUL))
#define bM0P_GPIO_FN_SEL03_TIOB7S0                      *((volatile unsigned int*)(0x4266C1F0UL))
#define bM0P_GPIO_FN_SEL03_TIOB7S1                      *((volatile unsigned int*)(0x4266C1F4UL))
#define bM0P_GPIO_FN_SEL04_EINT00S0                     *((volatile unsigned int*)(0x4266C200UL))
#define bM0P_GPIO_FN_SEL04_EINT00S1                     *((volatile unsigned int*)(0x4266C204UL))
#define bM0P_GPIO_FN_SEL04_EINT01S0                     *((volatile unsigned int*)(0x4266C208UL))
#define bM0P_GPIO_FN_SEL04_EINT01S1                     *((volatile unsigned int*)(0x4266C20CUL))
#define bM0P_GPIO_FN_SEL04_EINT02S0                     *((volatile unsigned int*)(0x4266C210UL))
#define bM0P_GPIO_FN_SEL04_EINT02S1                     *((volatile unsigned int*)(0x4266C214UL))
#define bM0P_GPIO_FN_SEL04_EINT03S0                     *((volatile unsigned int*)(0x4266C218UL))
#define bM0P_GPIO_FN_SEL04_EINT03S1                     *((volatile unsigned int*)(0x4266C21CUL))
#define bM0P_GPIO_FN_SEL04_EINT04S0                     *((volatile unsigned int*)(0x4266C220UL))
#define bM0P_GPIO_FN_SEL04_EINT04S1                     *((volatile unsigned int*)(0x4266C224UL))
#define bM0P_GPIO_FN_SEL04_EINT05S0                     *((volatile unsigned int*)(0x4266C228UL))
#define bM0P_GPIO_FN_SEL04_EINT05S1                     *((volatile unsigned int*)(0x4266C22CUL))
#define bM0P_GPIO_FN_SEL04_EINT06S0                     *((volatile unsigned int*)(0x4266C230UL))
#define bM0P_GPIO_FN_SEL04_EINT06S1                     *((volatile unsigned int*)(0x4266C234UL))
#define bM0P_GPIO_FN_SEL04_EINT07S0                     *((volatile unsigned int*)(0x4266C238UL))
#define bM0P_GPIO_FN_SEL04_EINT07S1                     *((volatile unsigned int*)(0x4266C23CUL))
#define bM0P_GPIO_FN_SEL04_EINT08S0                     *((volatile unsigned int*)(0x4266C240UL))
#define bM0P_GPIO_FN_SEL04_EINT08S1                     *((volatile unsigned int*)(0x4266C244UL))
#define bM0P_GPIO_FN_SEL04_EINT09S0                     *((volatile unsigned int*)(0x4266C248UL))
#define bM0P_GPIO_FN_SEL04_EINT09S1                     *((volatile unsigned int*)(0x4266C24CUL))
#define bM0P_GPIO_FN_SEL04_EINT10S0                     *((volatile unsigned int*)(0x4266C250UL))
#define bM0P_GPIO_FN_SEL04_EINT10S1                     *((volatile unsigned int*)(0x4266C254UL))
#define bM0P_GPIO_FN_SEL04_EINT11S0                     *((volatile unsigned int*)(0x4266C258UL))
#define bM0P_GPIO_FN_SEL04_EINT11S1                     *((volatile unsigned int*)(0x4266C25CUL))
#define bM0P_GPIO_FN_SEL04_EINT12S0                     *((volatile unsigned int*)(0x4266C260UL))
#define bM0P_GPIO_FN_SEL04_EINT12S1                     *((volatile unsigned int*)(0x4266C264UL))
#define bM0P_GPIO_FN_SEL04_EINT13S0                     *((volatile unsigned int*)(0x4266C268UL))
#define bM0P_GPIO_FN_SEL04_EINT13S1                     *((volatile unsigned int*)(0x4266C26CUL))
#define bM0P_GPIO_FN_SEL04_EINT14S0                     *((volatile unsigned int*)(0x4266C270UL))
#define bM0P_GPIO_FN_SEL04_EINT14S1                     *((volatile unsigned int*)(0x4266C274UL))
#define bM0P_GPIO_FN_SEL04_EINT15S0                     *((volatile unsigned int*)(0x4266C278UL))
#define bM0P_GPIO_FN_SEL04_EINT15S1                     *((volatile unsigned int*)(0x4266C27CUL))
#define bM0P_GPIO_FN_SEL05_SIN0S0                       *((volatile unsigned int*)(0x4266C290UL))
#define bM0P_GPIO_FN_SEL05_SIN0S1                       *((volatile unsigned int*)(0x4266C294UL))
#define bM0P_GPIO_FN_SEL05_SOT0B0                       *((volatile unsigned int*)(0x4266C298UL))
#define bM0P_GPIO_FN_SEL05_SOT0B1                       *((volatile unsigned int*)(0x4266C29CUL))
#define bM0P_GPIO_FN_SEL05_SCK0B0                       *((volatile unsigned int*)(0x4266C2A0UL))
#define bM0P_GPIO_FN_SEL05_SCK0B1                       *((volatile unsigned int*)(0x4266C2A4UL))
#define bM0P_GPIO_FN_SEL05_RTS1E0                       *((volatile unsigned int*)(0x4266C2C0UL))
#define bM0P_GPIO_FN_SEL05_RTS1E1                       *((volatile unsigned int*)(0x4266C2C4UL))
#define bM0P_GPIO_FN_SEL05_CTS1S0                       *((volatile unsigned int*)(0x4266C2C8UL))
#define bM0P_GPIO_FN_SEL05_CTS1S1                       *((volatile unsigned int*)(0x4266C2CCUL))
#define bM0P_GPIO_FN_SEL05_SIN1S0                       *((volatile unsigned int*)(0x4266C2D0UL))
#define bM0P_GPIO_FN_SEL05_SIN1S1                       *((volatile unsigned int*)(0x4266C2D4UL))
#define bM0P_GPIO_FN_SEL05_SOT1B0                       *((volatile unsigned int*)(0x4266C2D8UL))
#define bM0P_GPIO_FN_SEL05_SOT1B1                       *((volatile unsigned int*)(0x4266C2DCUL))
#define bM0P_GPIO_FN_SEL05_SCK1B0                       *((volatile unsigned int*)(0x4266C2E0UL))
#define bM0P_GPIO_FN_SEL05_SCK1B1                       *((volatile unsigned int*)(0x4266C2E4UL))
#define bM0P_GPIO_FN_SEL05_SCS10B0                      *((volatile unsigned int*)(0x4266C2E8UL))
#define bM0P_GPIO_FN_SEL05_SCS10B1                      *((volatile unsigned int*)(0x4266C2ECUL))
#define bM0P_GPIO_FN_SEL06_SIN2S0                       *((volatile unsigned int*)(0x4266C310UL))
#define bM0P_GPIO_FN_SEL06_SIN2S1                       *((volatile unsigned int*)(0x4266C314UL))
#define bM0P_GPIO_FN_SEL06_SOT2B0                       *((volatile unsigned int*)(0x4266C318UL))
#define bM0P_GPIO_FN_SEL06_SOT2B1                       *((volatile unsigned int*)(0x4266C31CUL))
#define bM0P_GPIO_FN_SEL06_SCK2B0                       *((volatile unsigned int*)(0x4266C320UL))
#define bM0P_GPIO_FN_SEL06_SCK2B1                       *((volatile unsigned int*)(0x4266C324UL))
#define bM0P_GPIO_FN_SEL06_SCS20B0                      *((volatile unsigned int*)(0x4266C328UL))
#define bM0P_GPIO_FN_SEL06_SCS20B1                      *((volatile unsigned int*)(0x4266C32CUL))
#define bM0P_GPIO_FN_SEL06_SCS21E0                      *((volatile unsigned int*)(0x4266C330UL))
#define bM0P_GPIO_FN_SEL06_SCS21E1                      *((volatile unsigned int*)(0x4266C334UL))
#define bM0P_GPIO_FN_SEL06_SCS22E0                      *((volatile unsigned int*)(0x4266C338UL))
#define bM0P_GPIO_FN_SEL06_SCS22E1                      *((volatile unsigned int*)(0x4266C33CUL))
#define bM0P_GPIO_FN_SEL07_RTS4E0                       *((volatile unsigned int*)(0x4266C380UL))
#define bM0P_GPIO_FN_SEL07_RTS4E1                       *((volatile unsigned int*)(0x4266C384UL))
#define bM0P_GPIO_FN_SEL07_CTS4S0                       *((volatile unsigned int*)(0x4266C388UL))
#define bM0P_GPIO_FN_SEL07_CTS4S1                       *((volatile unsigned int*)(0x4266C38CUL))
#define bM0P_GPIO_FN_SEL07_SIN4S0                       *((volatile unsigned int*)(0x4266C390UL))
#define bM0P_GPIO_FN_SEL07_SIN4S1                       *((volatile unsigned int*)(0x4266C394UL))
#define bM0P_GPIO_FN_SEL07_SOT4B0                       *((volatile unsigned int*)(0x4266C398UL))
#define bM0P_GPIO_FN_SEL07_SOT4B1                       *((volatile unsigned int*)(0x4266C39CUL))
#define bM0P_GPIO_FN_SEL07_SCK4B0                       *((volatile unsigned int*)(0x4266C3A0UL))
#define bM0P_GPIO_FN_SEL07_SCK4B1                       *((volatile unsigned int*)(0x4266C3A4UL))
#define bM0P_GPIO_FN_SEL07_SCS40B0                      *((volatile unsigned int*)(0x4266C3A8UL))
#define bM0P_GPIO_FN_SEL07_SCS40B1                      *((volatile unsigned int*)(0x4266C3ACUL))
#define bM0P_GPIO_FN_SEL07_SCS41E0                      *((volatile unsigned int*)(0x4266C3B0UL))
#define bM0P_GPIO_FN_SEL07_SCS41E1                      *((volatile unsigned int*)(0x4266C3B4UL))
#define bM0P_GPIO_FN_SEL07_SIN5S0                       *((volatile unsigned int*)(0x4266C3D0UL))
#define bM0P_GPIO_FN_SEL07_SIN5S1                       *((volatile unsigned int*)(0x4266C3D4UL))
#define bM0P_GPIO_FN_SEL07_SOT5B0                       *((volatile unsigned int*)(0x4266C3D8UL))
#define bM0P_GPIO_FN_SEL07_SOT5B1                       *((volatile unsigned int*)(0x4266C3DCUL))
#define bM0P_GPIO_FN_SEL07_SCK5B0                       *((volatile unsigned int*)(0x4266C3E0UL))
#define bM0P_GPIO_FN_SEL07_SCK5B1                       *((volatile unsigned int*)(0x4266C3E4UL))
#define bM0P_GPIO_FN_SEL07_SCS50B0                      *((volatile unsigned int*)(0x4266C3E8UL))
#define bM0P_GPIO_FN_SEL07_SCS50B1                      *((volatile unsigned int*)(0x4266C3ECUL))
#define bM0P_GPIO_FN_SEL08_RTS6E0                       *((volatile unsigned int*)(0x4266C400UL))
#define bM0P_GPIO_FN_SEL08_RTS6E1                       *((volatile unsigned int*)(0x4266C404UL))
#define bM0P_GPIO_FN_SEL08_CTS6S0                       *((volatile unsigned int*)(0x4266C408UL))
#define bM0P_GPIO_FN_SEL08_CTS6S1                       *((volatile unsigned int*)(0x4266C40CUL))
#define bM0P_GPIO_FN_SEL08_SIN6S0                       *((volatile unsigned int*)(0x4266C410UL))
#define bM0P_GPIO_FN_SEL08_SIN6S1                       *((volatile unsigned int*)(0x4266C414UL))
#define bM0P_GPIO_FN_SEL08_SOT6B0                       *((volatile unsigned int*)(0x4266C418UL))
#define bM0P_GPIO_FN_SEL08_SOT6B1                       *((volatile unsigned int*)(0x4266C41CUL))
#define bM0P_GPIO_FN_SEL08_SCK6B0                       *((volatile unsigned int*)(0x4266C420UL))
#define bM0P_GPIO_FN_SEL08_SCK6B1                       *((volatile unsigned int*)(0x4266C424UL))
#define bM0P_GPIO_FN_SEL08_SCS60B0                      *((volatile unsigned int*)(0x4266C428UL))
#define bM0P_GPIO_FN_SEL08_SCS60B1                      *((volatile unsigned int*)(0x4266C42CUL))
#define bM0P_GPIO_FN_SEL08_SCS61E0                      *((volatile unsigned int*)(0x4266C430UL))
#define bM0P_GPIO_FN_SEL08_SCS61E1                      *((volatile unsigned int*)(0x4266C434UL))
#define bM0P_GPIO_FN_SEL08_SCS62E0                      *((volatile unsigned int*)(0x4266C438UL))
#define bM0P_GPIO_FN_SEL08_SCS62E1                      *((volatile unsigned int*)(0x4266C43CUL))
#define bM0P_GPIO_FN_SEL09_VCOE0                        *((volatile unsigned int*)(0x4266C480UL))
#define bM0P_GPIO_FN_SEL09_VCOE1                        *((volatile unsigned int*)(0x4266C484UL))
#define bM0P_GPIO_FN_SEL09_BZOE0                        *((volatile unsigned int*)(0x4266C490UL))
#define bM0P_GPIO_FN_SEL09_BZOE1                        *((volatile unsigned int*)(0x4266C494UL))
#define bM0P_GPIO_FN_SEL09_ICCKE0                       *((volatile unsigned int*)(0x4266C4A0UL))
#define bM0P_GPIO_FN_SEL09_ICCKE1                       *((volatile unsigned int*)(0x4266C4A4UL))
#define bM0P_GPIO_FN_SEL09_ICIOB0                       *((volatile unsigned int*)(0x4266C4A8UL))
#define bM0P_GPIO_FN_SEL09_ICIOB1                       *((volatile unsigned int*)(0x4266C4ACUL))
#define bM0P_GPIO_FN_SEL09_ICRSTE0                      *((volatile unsigned int*)(0x4266C4B0UL))
#define bM0P_GPIO_FN_SEL09_ICRSTE1                      *((volatile unsigned int*)(0x4266C4B4UL))
#define bM0P_GPIO_ODR0_P00                              *((volatile unsigned int*)(0x4266E000UL))
#define bM0P_GPIO_ODR0_P01                              *((volatile unsigned int*)(0x4266E004UL))
#define bM0P_GPIO_ODR0_P02                              *((volatile unsigned int*)(0x4266E008UL))
#define bM0P_GPIO_ODR0_P03                              *((volatile unsigned int*)(0x4266E00CUL))
#define bM0P_GPIO_ODR0_P04                              *((volatile unsigned int*)(0x4266E010UL))
#define bM0P_GPIO_ODR0_P05                              *((volatile unsigned int*)(0x4266E014UL))
#define bM0P_GPIO_ODR0_P06                              *((volatile unsigned int*)(0x4266E018UL))
#define bM0P_GPIO_ODR0_P07                              *((volatile unsigned int*)(0x4266E01CUL))
#define bM0P_GPIO_ODR1_P10                              *((volatile unsigned int*)(0x4266E080UL))
#define bM0P_GPIO_ODR1_P11                              *((volatile unsigned int*)(0x4266E084UL))
#define bM0P_GPIO_ODR1_P12                              *((volatile unsigned int*)(0x4266E088UL))
#define bM0P_GPIO_ODR1_P13                              *((volatile unsigned int*)(0x4266E08CUL))
#define bM0P_GPIO_ODR1_P14                              *((volatile unsigned int*)(0x4266E090UL))
#define bM0P_GPIO_ODR1_P15                              *((volatile unsigned int*)(0x4266E094UL))
#define bM0P_GPIO_ODR1_P16                              *((volatile unsigned int*)(0x4266E098UL))
#define bM0P_GPIO_ODR1_P17                              *((volatile unsigned int*)(0x4266E09CUL))
#define bM0P_GPIO_ODR2_P20                              *((volatile unsigned int*)(0x4266E100UL))
#define bM0P_GPIO_ODR2_P21                              *((volatile unsigned int*)(0x4266E104UL))
#define bM0P_GPIO_ODR2_P22                              *((volatile unsigned int*)(0x4266E108UL))
#define bM0P_GPIO_ODR2_P23                              *((volatile unsigned int*)(0x4266E10CUL))
#define bM0P_GPIO_ODR2_P24                              *((volatile unsigned int*)(0x4266E110UL))
#define bM0P_GPIO_ODR2_P25                              *((volatile unsigned int*)(0x4266E114UL))
#define bM0P_GPIO_ODR2_P26                              *((volatile unsigned int*)(0x4266E118UL))
#define bM0P_GPIO_ODR2_P27                              *((volatile unsigned int*)(0x4266E11CUL))
#define bM0P_GPIO_ODR3_P30                              *((volatile unsigned int*)(0x4266E180UL))
#define bM0P_GPIO_ODR3_P31                              *((volatile unsigned int*)(0x4266E184UL))
#define bM0P_GPIO_ODR3_P34                              *((volatile unsigned int*)(0x4266E190UL))
#define bM0P_GPIO_ODR3_P35                              *((volatile unsigned int*)(0x4266E194UL))
#define bM0P_GPIO_ODR3_P36                              *((volatile unsigned int*)(0x4266E198UL))
#define bM0P_GPIO_ODR3_P37                              *((volatile unsigned int*)(0x4266E19CUL))
#define bM0P_GPIO_ODR4_P40                              *((volatile unsigned int*)(0x4266E200UL))
#define bM0P_GPIO_ODR4_P41                              *((volatile unsigned int*)(0x4266E204UL))
#define bM0P_GPIO_ODR4_P45                              *((volatile unsigned int*)(0x4266E214UL))
#define bM0P_GPIO_ODR4_P46                              *((volatile unsigned int*)(0x4266E218UL))
#define bM0P_GPIO_ODR4_P47                              *((volatile unsigned int*)(0x4266E21CUL))
#define bM0P_GPIO_ODR5_P50                              *((volatile unsigned int*)(0x4266E280UL))
#define bM0P_GPIO_ODR5_P51                              *((volatile unsigned int*)(0x4266E284UL))
#define bM0P_GPIO_ODR5_P52                              *((volatile unsigned int*)(0x4266E288UL))
#define bM0P_GPIO_ODR5_P53                              *((volatile unsigned int*)(0x4266E28CUL))
#define bM0P_GPIO_ODR5_P54                              *((volatile unsigned int*)(0x4266E290UL))
#define bM0P_GPIO_ODR5_P55                              *((volatile unsigned int*)(0x4266E294UL))
#define bM0P_GPIO_ODR5_P56                              *((volatile unsigned int*)(0x4266E298UL))
#define bM0P_GPIO_ODR5_P57                              *((volatile unsigned int*)(0x4266E29CUL))
#define bM0P_GPIO_ODR6_P60                              *((volatile unsigned int*)(0x4266E300UL))
#define bM0P_GPIO_ODR6_P61                              *((volatile unsigned int*)(0x4266E304UL))
#define bM0P_GPIO_ODR6_P62                              *((volatile unsigned int*)(0x4266E308UL))
#define bM0P_GPIO_ODR6_P63                              *((volatile unsigned int*)(0x4266E30CUL))
#define bM0P_GPIO_ODR6_P64                              *((volatile unsigned int*)(0x4266E310UL))
#define bM0P_GPIO_ODR6_P65                              *((volatile unsigned int*)(0x4266E314UL))
#define bM0P_GPIO_ODR6_P66                              *((volatile unsigned int*)(0x4266E318UL))
#define bM0P_GPIO_ODR6_P67                              *((volatile unsigned int*)(0x4266E31CUL))
#define bM0P_GPIO_ODR7_P70                              *((volatile unsigned int*)(0x4266E380UL))
#define bM0P_GPIO_ODR7_P71                              *((volatile unsigned int*)(0x4266E384UL))
#define bM0P_GPIO_ODR7_P72                              *((volatile unsigned int*)(0x4266E388UL))
#define bM0P_GPIO_ODR7_P73                              *((volatile unsigned int*)(0x4266E38CUL))
#define bM0P_GPIO_ODR7_P74                              *((volatile unsigned int*)(0x4266E390UL))
#define bM0P_GPIO_ODR8_P80                              *((volatile unsigned int*)(0x4266E400UL))
#define bM0P_GPIO_LVDIE_LVDIE                           *((volatile unsigned int*)(0x4266E800UL))
#define bM0P_GPIO_FSETE0_P00                            *((volatile unsigned int*)(0x42672000UL))
#define bM0P_GPIO_FSETE0_P01                            *((volatile unsigned int*)(0x42672004UL))
#define bM0P_GPIO_FSETE0_P02                            *((volatile unsigned int*)(0x42672008UL))
#define bM0P_GPIO_FSETE0_P03                            *((volatile unsigned int*)(0x4267200CUL))
#define bM0P_GPIO_FSETE0_P04                            *((volatile unsigned int*)(0x42672010UL))
#define bM0P_GPIO_FSETE0_P05                            *((volatile unsigned int*)(0x42672014UL))
#define bM0P_GPIO_FSETE0_P06                            *((volatile unsigned int*)(0x42672018UL))
#define bM0P_GPIO_FSETE0_P07                            *((volatile unsigned int*)(0x4267201CUL))
#define bM0P_GPIO_FSETE1_P10                            *((volatile unsigned int*)(0x42672080UL))
#define bM0P_GPIO_FSETE1_P11                            *((volatile unsigned int*)(0x42672084UL))
#define bM0P_GPIO_FSETE1_P12                            *((volatile unsigned int*)(0x42672088UL))
#define bM0P_GPIO_FSETE1_P13                            *((volatile unsigned int*)(0x4267208CUL))
#define bM0P_GPIO_FSETE1_P14                            *((volatile unsigned int*)(0x42672090UL))
#define bM0P_GPIO_FSETE1_P15                            *((volatile unsigned int*)(0x42672094UL))
#define bM0P_GPIO_FSETE1_P16                            *((volatile unsigned int*)(0x42672098UL))
#define bM0P_GPIO_FSETE1_P17                            *((volatile unsigned int*)(0x4267209CUL))
#define bM0P_GPIO_FSETE2_P20                            *((volatile unsigned int*)(0x42672100UL))
#define bM0P_GPIO_FSETE2_P21                            *((volatile unsigned int*)(0x42672104UL))
#define bM0P_GPIO_FSETE2_P22                            *((volatile unsigned int*)(0x42672108UL))
#define bM0P_GPIO_FSETE2_P23                            *((volatile unsigned int*)(0x4267210CUL))
#define bM0P_GPIO_FSETE2_P24                            *((volatile unsigned int*)(0x42672110UL))
#define bM0P_GPIO_FSETE2_P25                            *((volatile unsigned int*)(0x42672114UL))
#define bM0P_GPIO_FSETE2_P26                            *((volatile unsigned int*)(0x42672118UL))
#define bM0P_GPIO_FSETE2_P27                            *((volatile unsigned int*)(0x4267211CUL))
#define bM0P_GPIO_FSETE3_P30                            *((volatile unsigned int*)(0x42672180UL))
#define bM0P_GPIO_FSETE3_P31                            *((volatile unsigned int*)(0x42672184UL))
#define bM0P_GPIO_FSETE3_P34                            *((volatile unsigned int*)(0x42672190UL))
#define bM0P_GPIO_FSETE3_P35                            *((volatile unsigned int*)(0x42672194UL))
#define bM0P_GPIO_FSETE3_P36                            *((volatile unsigned int*)(0x42672198UL))
#define bM0P_GPIO_FSETE3_P37                            *((volatile unsigned int*)(0x4267219CUL))
#define bM0P_GPIO_FSETE4_P40                            *((volatile unsigned int*)(0x42672200UL))
#define bM0P_GPIO_FSETE4_P41                            *((volatile unsigned int*)(0x42672204UL))
#define bM0P_GPIO_FSETE4_P45                            *((volatile unsigned int*)(0x42672214UL))
#define bM0P_GPIO_FSETE4_P46                            *((volatile unsigned int*)(0x42672218UL))
#define bM0P_GPIO_FSETE4_P47                            *((volatile unsigned int*)(0x4267221CUL))
#define bM0P_GPIO_FSETE5_P50                            *((volatile unsigned int*)(0x42672280UL))
#define bM0P_GPIO_FSETE5_P51                            *((volatile unsigned int*)(0x42672284UL))
#define bM0P_GPIO_FSETE5_P52                            *((volatile unsigned int*)(0x42672288UL))
#define bM0P_GPIO_FSETE5_P53                            *((volatile unsigned int*)(0x4267228CUL))
#define bM0P_GPIO_FSETE5_P54                            *((volatile unsigned int*)(0x42672290UL))
#define bM0P_GPIO_FSETE5_P55                            *((volatile unsigned int*)(0x42672294UL))
#define bM0P_GPIO_FSETE5_P56                            *((volatile unsigned int*)(0x42672298UL))
#define bM0P_GPIO_FSETE5_P57                            *((volatile unsigned int*)(0x4267229CUL))
#define bM0P_GPIO_FSETE6_P60                            *((volatile unsigned int*)(0x42672300UL))
#define bM0P_GPIO_FSETE6_P61                            *((volatile unsigned int*)(0x42672304UL))
#define bM0P_GPIO_FSETE6_P62                            *((volatile unsigned int*)(0x42672308UL))
#define bM0P_GPIO_FSETE6_P63                            *((volatile unsigned int*)(0x4267230CUL))
#define bM0P_GPIO_FSETE6_P64                            *((volatile unsigned int*)(0x42672310UL))
#define bM0P_GPIO_FSETE6_P65                            *((volatile unsigned int*)(0x42672314UL))
#define bM0P_GPIO_FSETE6_P66                            *((volatile unsigned int*)(0x42672318UL))
#define bM0P_GPIO_FSETE6_P67                            *((volatile unsigned int*)(0x4267231CUL))
#define bM0P_GPIO_FSETE7_P70                            *((volatile unsigned int*)(0x42672380UL))
#define bM0P_GPIO_FSETE7_P71                            *((volatile unsigned int*)(0x42672384UL))
#define bM0P_GPIO_FSETE7_P72                            *((volatile unsigned int*)(0x42672388UL))
#define bM0P_GPIO_FSETE7_P73                            *((volatile unsigned int*)(0x4267238CUL))
#define bM0P_GPIO_FSETE7_P74                            *((volatile unsigned int*)(0x42672390UL))
#define bM0P_GPIO_FSETE8_P80                            *((volatile unsigned int*)(0x42672400UL))
#define bM0P_HWWDT_WDT_CTL_IE                           *((volatile unsigned int*)(0x42220100UL))
#define bM0P_HWWDT_WDT_CTL_RSTEN                        *((volatile unsigned int*)(0x42220104UL))
#define bM0P_HWWDT_WDT_CTL_CLKS                         *((volatile unsigned int*)(0x42220108UL))
#define bM0P_HWWDT_WDT_STA_STA                          *((volatile unsigned int*)(0x42220200UL))
#define bM0P_IRQC_IRQ_ST02_NMI                          *((volatile unsigned int*)(0x42620200UL))
#define bM0P_IRQC_IRQ_ST02_HWWDG                        *((volatile unsigned int*)(0x42620204UL))
#define bM0P_IRQC_IRQ00PEND_AFDI                        *((volatile unsigned int*)(0x42620280UL))
#define bM0P_IRQC_IRQ00PEND_MCSV                        *((volatile unsigned int*)(0x42620284UL))
#define bM0P_IRQC_IRQ00PEND_SCSV                        *((volatile unsigned int*)(0x42620288UL))
#define bM0P_IRQC_IRQ01PEND_SWWDG                       *((volatile unsigned int*)(0x42620300UL))
#define bM0P_IRQC_IRQ02PEND_LVD                         *((volatile unsigned int*)(0x42620380UL))
#define bM0P_IRQC_IRQ04PEND_EXTI0                       *((volatile unsigned int*)(0x42620480UL))
#define bM0P_IRQC_IRQ04PEND_EXTI1                       *((volatile unsigned int*)(0x42620484UL))
#define bM0P_IRQC_IRQ04PEND_EXTI2                       *((volatile unsigned int*)(0x42620488UL))
#define bM0P_IRQC_IRQ04PEND_EXTI3                       *((volatile unsigned int*)(0x4262048CUL))
#define bM0P_IRQC_IRQ04PEND_EXTI4                       *((volatile unsigned int*)(0x42620490UL))
#define bM0P_IRQC_IRQ04PEND_EXTI5                       *((volatile unsigned int*)(0x42620494UL))
#define bM0P_IRQC_IRQ04PEND_EXTI6                       *((volatile unsigned int*)(0x42620498UL))
#define bM0P_IRQC_IRQ04PEND_EXTI7                       *((volatile unsigned int*)(0x4262049CUL))
#define bM0P_IRQC_IRQ05PEND_EXTI8                       *((volatile unsigned int*)(0x42620500UL))
#define bM0P_IRQC_IRQ05PEND_EXTI9                       *((volatile unsigned int*)(0x42620504UL))
#define bM0P_IRQC_IRQ05PEND_EXTI10                      *((volatile unsigned int*)(0x42620508UL))
#define bM0P_IRQC_IRQ05PEND_EXTI11                      *((volatile unsigned int*)(0x4262050CUL))
#define bM0P_IRQC_IRQ05PEND_EXTI12                      *((volatile unsigned int*)(0x42620510UL))
#define bM0P_IRQC_IRQ05PEND_EXTI13                      *((volatile unsigned int*)(0x42620514UL))
#define bM0P_IRQC_IRQ05PEND_EXTI14                      *((volatile unsigned int*)(0x42620518UL))
#define bM0P_IRQC_IRQ05PEND_EXTI15                      *((volatile unsigned int*)(0x4262051CUL))
#define bM0P_IRQC_IRQ06PEND_DTI1                        *((volatile unsigned int*)(0x42620580UL))
#define bM0P_IRQC_IRQ06PEND_DTI2                        *((volatile unsigned int*)(0x42620584UL))
#define bM0P_IRQC_IRQ07PEND_MSC0INT                     *((volatile unsigned int*)(0x42620600UL))
#define bM0P_IRQC_IRQ08PEND_MSC0INT0                    *((volatile unsigned int*)(0x42620680UL))
#define bM0P_IRQC_IRQ08PEND_MSC0INT1                    *((volatile unsigned int*)(0x42620684UL))
#define bM0P_IRQC_IRQ09PEND_MSC1INT                     *((volatile unsigned int*)(0x42620700UL))
#define bM0P_IRQC_IRQ10PEND_MSC1INT0                    *((volatile unsigned int*)(0x42620780UL))
#define bM0P_IRQC_IRQ10PEND_MSC1INT1                    *((volatile unsigned int*)(0x42620784UL))
#define bM0P_IRQC_IRQ11PEND_MSC2INT                     *((volatile unsigned int*)(0x42620800UL))
#define bM0P_IRQC_IRQ12PEND_MSC2INT0                    *((volatile unsigned int*)(0x42620880UL))
#define bM0P_IRQC_IRQ12PEND_MSC2INT1                    *((volatile unsigned int*)(0x42620884UL))
#define bM0P_IRQC_IRQ15PEND_MSC4INT                     *((volatile unsigned int*)(0x42620A00UL))
#define bM0P_IRQC_IRQ16PEND_MSC4INT0                    *((volatile unsigned int*)(0x42620A80UL))
#define bM0P_IRQC_IRQ16PEND_MSC4INT1                    *((volatile unsigned int*)(0x42620A84UL))
#define bM0P_IRQC_IRQ17PEND_MSC5INT                     *((volatile unsigned int*)(0x42620B00UL))
#define bM0P_IRQC_IRQ18PEND_MSC5INT0                    *((volatile unsigned int*)(0x42620B80UL))
#define bM0P_IRQC_IRQ18PEND_MSC5INT1                    *((volatile unsigned int*)(0x42620B84UL))
#define bM0P_IRQC_IRQ19PEND_MSC6INT                     *((volatile unsigned int*)(0x42620C00UL))
#define bM0P_IRQC_IRQ20PEND_MSC6INT0                    *((volatile unsigned int*)(0x42620C80UL))
#define bM0P_IRQC_IRQ20PEND_MSC6INT1                    *((volatile unsigned int*)(0x42620C84UL))
#define bM0P_IRQC_IRQ24PEND_MOSCI                       *((volatile unsigned int*)(0x42620E80UL))
#define bM0P_IRQC_IRQ24PEND_SOSCI                       *((volatile unsigned int*)(0x42620E84UL))
#define bM0P_IRQC_IRQ24PEND_RTCI                        *((volatile unsigned int*)(0x42620E94UL))
#define bM0P_IRQC_IRQ24PEND_RAMI                        *((volatile unsigned int*)(0x42620E9CUL))
#define bM0P_IRQC_IRQ25PEND_ADCCNVI                     *((volatile unsigned int*)(0x42620F00UL))
#define bM0P_IRQC_IRQ25PEND_ADCCMPI                     *((volatile unsigned int*)(0x42620F10UL))
#define bM0P_IRQC_IRQ26PEND_VCI                         *((volatile unsigned int*)(0x42620F94UL))
#define bM0P_IRQC_IRQ27PEND_ICCI                        *((volatile unsigned int*)(0x42621018UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH0                  *((volatile unsigned int*)(0x42621200UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH0                  *((volatile unsigned int*)(0x42621204UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH1                  *((volatile unsigned int*)(0x42621208UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH1                  *((volatile unsigned int*)(0x4262120CUL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH2                  *((volatile unsigned int*)(0x42621210UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH2                  *((volatile unsigned int*)(0x42621214UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH3                  *((volatile unsigned int*)(0x42621218UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH3                  *((volatile unsigned int*)(0x4262121CUL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH4                  *((volatile unsigned int*)(0x42621220UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH4                  *((volatile unsigned int*)(0x42621224UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH5                  *((volatile unsigned int*)(0x42621228UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH5                  *((volatile unsigned int*)(0x4262122CUL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH6                  *((volatile unsigned int*)(0x42621230UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH6                  *((volatile unsigned int*)(0x42621234UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ0CH7                  *((volatile unsigned int*)(0x42621238UL))
#define bM0P_IRQC_IRQ31PEND_CTIIRQ1CH7                  *((volatile unsigned int*)(0x4262123CUL))
#define bM0P_IRQC_IRQ31PEND_FLASHI                      *((volatile unsigned int*)(0x4262126CUL))
#define bM0P_LCDC_LCDCR0_CLKSEL                         *((volatile unsigned int*)(0x42640000UL))
#define bM0P_LCDC_LCDCR0_LCD_FRAME0                     *((volatile unsigned int*)(0x42640004UL))
#define bM0P_LCDC_LCDCR0_LCD_FRAME1                     *((volatile unsigned int*)(0x42640008UL))
#define bM0P_LCDC_LCDCR0_BIAS0                          *((volatile unsigned int*)(0x4264000CUL))
#define bM0P_LCDC_LCDCR0_BIAS1                          *((volatile unsigned int*)(0x42640010UL))
#define bM0P_LCDC_LCDCR0_LCD_MODE0                      *((volatile unsigned int*)(0x42640014UL))
#define bM0P_LCDC_LCDCR0_LCD_MODE1                      *((volatile unsigned int*)(0x42640018UL))
#define bM0P_LCDC_LCDCR0_LCD_MODE2                      *((volatile unsigned int*)(0x4264001CUL))
#define bM0P_LCDC_LCDCR1_VLCD0                          *((volatile unsigned int*)(0x42640020UL))
#define bM0P_LCDC_LCDCR1_VLCD1                          *((volatile unsigned int*)(0x42640024UL))
#define bM0P_LCDC_LCDCR1_VLCD2                          *((volatile unsigned int*)(0x42640028UL))
#define bM0P_LCDC_LCDCR1_CT0                            *((volatile unsigned int*)(0x4264002CUL))
#define bM0P_LCDC_LCDCR1_CT1                            *((volatile unsigned int*)(0x42640030UL))
#define bM0P_LCDC_LCDCR1_CT2                            *((volatile unsigned int*)(0x42640034UL))
#define bM0P_LCDC_LCDCR1_CMOD                           *((volatile unsigned int*)(0x42640038UL))
#define bM0P_LCDC_LCDCR2_CP_FREQ0                       *((volatile unsigned int*)(0x42640040UL))
#define bM0P_LCDC_LCDCR2_CP_FREQ1                       *((volatile unsigned int*)(0x42640044UL))
#define bM0P_LCDC_LCDCR2_VSEL0                          *((volatile unsigned int*)(0x42640054UL))
#define bM0P_LCDC_LCDCR2_VSEL1                          *((volatile unsigned int*)(0x42640058UL))
#define bM0P_LCDC_LCDCR2_WSEL                           *((volatile unsigned int*)(0x4264005CUL))
#define bM0P_LCDC_LCDCR3_LCD_EN                         *((volatile unsigned int*)(0x42640060UL))
#define bM0P_LCDC_LCDCR3_LCD_BUF0                       *((volatile unsigned int*)(0x42640070UL))
#define bM0P_LCDC_LCDCR3_LCD_BUF1                       *((volatile unsigned int*)(0x42640074UL))
#define bM0P_LCDC_LCDDVC_VE0                            *((volatile unsigned int*)(0x42640080UL))
#define bM0P_LCDC_LCDDVC_VE1                            *((volatile unsigned int*)(0x42640084UL))
#define bM0P_LCDC_LCDDVC_VE2                            *((volatile unsigned int*)(0x42640088UL))
#define bM0P_LCDC_LCDDVC_VE3                            *((volatile unsigned int*)(0x4264008CUL))
#define bM0P_LCDC_LCDDVC_VE4                            *((volatile unsigned int*)(0x42640090UL))
#define bM0P_LCDC_LCDCE0_COME0                          *((volatile unsigned int*)(0x42640100UL))
#define bM0P_LCDC_LCDCE0_COME1                          *((volatile unsigned int*)(0x42640104UL))
#define bM0P_LCDC_LCDCE0_COME2                          *((volatile unsigned int*)(0x42640108UL))
#define bM0P_LCDC_LCDCE0_COME3                          *((volatile unsigned int*)(0x4264010CUL))
#define bM0P_LCDC_LCDCE0_COME4                          *((volatile unsigned int*)(0x42640110UL))
#define bM0P_LCDC_LCDCE0_COME5                          *((volatile unsigned int*)(0x42640114UL))
#define bM0P_LCDC_LCDCE0_COME6                          *((volatile unsigned int*)(0x42640118UL))
#define bM0P_LCDC_LCDCE0_COME7                          *((volatile unsigned int*)(0x4264011CUL))
#define bM0P_LCDC_LCDSE0_SEGE0                          *((volatile unsigned int*)(0x42640180UL))
#define bM0P_LCDC_LCDSE0_SEGE1                          *((volatile unsigned int*)(0x42640184UL))
#define bM0P_LCDC_LCDSE0_SEGE2                          *((volatile unsigned int*)(0x42640188UL))
#define bM0P_LCDC_LCDSE0_SEGE3                          *((volatile unsigned int*)(0x4264018CUL))
#define bM0P_LCDC_LCDSE0_SEGE4                          *((volatile unsigned int*)(0x42640190UL))
#define bM0P_LCDC_LCDSE0_SEGE5                          *((volatile unsigned int*)(0x42640194UL))
#define bM0P_LCDC_LCDSE0_SEGE6                          *((volatile unsigned int*)(0x42640198UL))
#define bM0P_LCDC_LCDSE0_SEGE7                          *((volatile unsigned int*)(0x4264019CUL))
#define bM0P_LCDC_LCDSE1_SEGE8                          *((volatile unsigned int*)(0x426401A0UL))
#define bM0P_LCDC_LCDSE1_SEGE9                          *((volatile unsigned int*)(0x426401A4UL))
#define bM0P_LCDC_LCDSE1_SEGE10                         *((volatile unsigned int*)(0x426401A8UL))
#define bM0P_LCDC_LCDSE1_SEGE11                         *((volatile unsigned int*)(0x426401ACUL))
#define bM0P_LCDC_LCDSE1_SEGE12                         *((volatile unsigned int*)(0x426401B0UL))
#define bM0P_LCDC_LCDSE1_SEGE13                         *((volatile unsigned int*)(0x426401B4UL))
#define bM0P_LCDC_LCDSE1_SEGE14                         *((volatile unsigned int*)(0x426401B8UL))
#define bM0P_LCDC_LCDSE1_SEGE15                         *((volatile unsigned int*)(0x426401BCUL))
#define bM0P_LCDC_LCDSE2_SEGE16                         *((volatile unsigned int*)(0x426401C0UL))
#define bM0P_LCDC_LCDSE2_SEGE17                         *((volatile unsigned int*)(0x426401C4UL))
#define bM0P_LCDC_LCDSE2_SEGE18                         *((volatile unsigned int*)(0x426401C8UL))
#define bM0P_LCDC_LCDSE2_SEGE19                         *((volatile unsigned int*)(0x426401CCUL))
#define bM0P_LCDC_LCDSE2_SEGE20                         *((volatile unsigned int*)(0x426401D0UL))
#define bM0P_LCDC_LCDSE2_SEGE21                         *((volatile unsigned int*)(0x426401D4UL))
#define bM0P_LCDC_LCDSE2_SEGE22                         *((volatile unsigned int*)(0x426401D8UL))
#define bM0P_LCDC_LCDSE2_SEGE23                         *((volatile unsigned int*)(0x426401DCUL))
#define bM0P_LCDC_LCDSE3_SEGE24                         *((volatile unsigned int*)(0x426401E0UL))
#define bM0P_LCDC_LCDSE3_SEGE25                         *((volatile unsigned int*)(0x426401E4UL))
#define bM0P_LCDC_LCDSE3_SEGE26                         *((volatile unsigned int*)(0x426401E8UL))
#define bM0P_LCDC_LCDSE3_SEGE27                         *((volatile unsigned int*)(0x426401ECUL))
#define bM0P_LCDC_LCDSE3_SEGE28                         *((volatile unsigned int*)(0x426401F0UL))
#define bM0P_LCDC_LCDSE3_SEGE29                         *((volatile unsigned int*)(0x426401F4UL))
#define bM0P_LCDC_LCDSE3_SEGE30                         *((volatile unsigned int*)(0x426401F8UL))
#define bM0P_LCDC_LCDSE3_SEGE31                         *((volatile unsigned int*)(0x426401FCUL))
#define bM0P_LCDC_LCDSE4_SEGE32                         *((volatile unsigned int*)(0x42640200UL))
#define bM0P_LCDC_LCDSE4_SEGE33                         *((volatile unsigned int*)(0x42640204UL))
#define bM0P_LCDC_LCDSE4_SEGE34                         *((volatile unsigned int*)(0x42640208UL))
#define bM0P_LCDC_LCDSE4_SEGE35                         *((volatile unsigned int*)(0x4264020CUL))
#define bM0P_LCDC_LCDSE4_SEGE36                         *((volatile unsigned int*)(0x42640210UL))
#define bM0P_LCDC_LCDSE4_SEGE37                         *((volatile unsigned int*)(0x42640214UL))
#define bM0P_LCDC_LCDSE4_SEGE38                         *((volatile unsigned int*)(0x42640218UL))
#define bM0P_LCDC_LCDSE4_SEGE39                         *((volatile unsigned int*)(0x4264021CUL))
#define bM0P_MSC0_I2C_MR_TXIE                           *((volatile unsigned int*)(0x42700008UL))
#define bM0P_MSC0_I2C_MR_RXIE                           *((volatile unsigned int*)(0x4270000CUL))
#define bM0P_MSC0_I2C_MR_MODE0                          *((volatile unsigned int*)(0x42700014UL))
#define bM0P_MSC0_I2C_MR_MODE1                          *((volatile unsigned int*)(0x42700018UL))
#define bM0P_MSC0_I2C_MR_MODE2                          *((volatile unsigned int*)(0x4270001CUL))
#define bM0P_MSC0_I2C_BC_INTF                           *((volatile unsigned int*)(0x42700020UL))
#define bM0P_MSC0_I2C_BC_BERF                           *((volatile unsigned int*)(0x42700024UL))
#define bM0P_MSC0_I2C_BC_INTE                           *((volatile unsigned int*)(0x42700028UL))
#define bM0P_MSC0_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x4270002CUL))
#define bM0P_MSC0_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x42700030UL))
#define bM0P_MSC0_I2C_BC_ACKE                           *((volatile unsigned int*)(0x42700034UL))
#define bM0P_MSC0_I2C_BC_OFITS                          *((volatile unsigned int*)(0x42700038UL))
#define bM0P_MSC0_I2C_BC_MSS                            *((volatile unsigned int*)(0x4270003CUL))
#define bM0P_MSC0_I2C_BS_BSS                            *((volatile unsigned int*)(0x42700080UL))
#define bM0P_MSC0_I2C_BS_STPCC                          *((volatile unsigned int*)(0x42700084UL))
#define bM0P_MSC0_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x42700088UL))
#define bM0P_MSC0_I2C_BS_ABL                            *((volatile unsigned int*)(0x4270008CUL))
#define bM0P_MSC0_I2C_BS_TRX                            *((volatile unsigned int*)(0x42700090UL))
#define bM0P_MSC0_I2C_BS_RAD                            *((volatile unsigned int*)(0x42700094UL))
#define bM0P_MSC0_I2C_BS_ACKF                           *((volatile unsigned int*)(0x42700098UL))
#define bM0P_MSC0_I2C_BS_FBB                            *((volatile unsigned int*)(0x4270009CUL))
#define bM0P_MSC0_I2C_SR_TBIF                           *((volatile unsigned int*)(0x427000A0UL))
#define bM0P_MSC0_I2C_SR_TDEF                           *((volatile unsigned int*)(0x427000A4UL))
#define bM0P_MSC0_I2C_SR_RDFF                           *((volatile unsigned int*)(0x427000A8UL))
#define bM0P_MSC0_I2C_SR_ORF                            *((volatile unsigned int*)(0x427000ACUL))
#define bM0P_MSC0_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x427000B0UL))
#define bM0P_MSC0_I2C_SR_TEFS                           *((volatile unsigned int*)(0x427000B8UL))
#define bM0P_MSC0_I2C_SR_RECLR                          *((volatile unsigned int*)(0x427000BCUL))
#define bM0P_MSC0_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x42700180UL))
#define bM0P_MSC0_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x42700184UL))
#define bM0P_MSC0_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x42700188UL))
#define bM0P_MSC0_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x4270018CUL))
#define bM0P_MSC0_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x42700190UL))
#define bM0P_MSC0_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x42700194UL))
#define bM0P_MSC0_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x42700198UL))
#define bM0P_MSC0_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x4270019CUL))
#define bM0P_MSC0_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x427001A0UL))
#define bM0P_MSC0_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x427001A4UL))
#define bM0P_MSC0_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x427001A8UL))
#define bM0P_MSC0_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x427001ACUL))
#define bM0P_MSC0_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x427001B0UL))
#define bM0P_MSC0_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x427001B4UL))
#define bM0P_MSC0_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x427001B8UL))
#define bM0P_MSC0_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x42700200UL))
#define bM0P_MSC0_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x42700204UL))
#define bM0P_MSC0_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x42700208UL))
#define bM0P_MSC0_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x4270020CUL))
#define bM0P_MSC0_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x42700210UL))
#define bM0P_MSC0_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x42700214UL))
#define bM0P_MSC0_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x42700218UL))
#define bM0P_MSC0_I2C_SA_AE                             *((volatile unsigned int*)(0x4270021CUL))
#define bM0P_MSC0_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x42700220UL))
#define bM0P_MSC0_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x42700224UL))
#define bM0P_MSC0_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x42700228UL))
#define bM0P_MSC0_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x4270022CUL))
#define bM0P_MSC0_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x42700230UL))
#define bM0P_MSC0_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x42700234UL))
#define bM0P_MSC0_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x42700238UL))
#define bM0P_MSC0_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x4270023CUL))
#define bM0P_MSC0_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x427003A0UL))
#define bM0P_MSC0_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x427003A4UL))
#define bM0P_MSC0_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x427003A8UL))
#define bM0P_MSC0_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x427003ACUL))
#define bM0P_MSC0_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x427003B0UL))
#define bM0P_MSC0_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x427003B4UL))
#define bM0P_MSC1_I2C_MR_TXIE                           *((volatile unsigned int*)(0x42702008UL))
#define bM0P_MSC1_I2C_MR_RXIE                           *((volatile unsigned int*)(0x4270200CUL))
#define bM0P_MSC1_I2C_MR_MODE0                          *((volatile unsigned int*)(0x42702014UL))
#define bM0P_MSC1_I2C_MR_MODE1                          *((volatile unsigned int*)(0x42702018UL))
#define bM0P_MSC1_I2C_MR_MODE2                          *((volatile unsigned int*)(0x4270201CUL))
#define bM0P_MSC1_I2C_BC_INTF                           *((volatile unsigned int*)(0x42702020UL))
#define bM0P_MSC1_I2C_BC_BERF                           *((volatile unsigned int*)(0x42702024UL))
#define bM0P_MSC1_I2C_BC_INTE                           *((volatile unsigned int*)(0x42702028UL))
#define bM0P_MSC1_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x4270202CUL))
#define bM0P_MSC1_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x42702030UL))
#define bM0P_MSC1_I2C_BC_ACKE                           *((volatile unsigned int*)(0x42702034UL))
#define bM0P_MSC1_I2C_BC_OFITS                          *((volatile unsigned int*)(0x42702038UL))
#define bM0P_MSC1_I2C_BC_MSS                            *((volatile unsigned int*)(0x4270203CUL))
#define bM0P_MSC1_I2C_BS_BSS                            *((volatile unsigned int*)(0x42702080UL))
#define bM0P_MSC1_I2C_BS_STPCC                          *((volatile unsigned int*)(0x42702084UL))
#define bM0P_MSC1_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x42702088UL))
#define bM0P_MSC1_I2C_BS_ABL                            *((volatile unsigned int*)(0x4270208CUL))
#define bM0P_MSC1_I2C_BS_TRX                            *((volatile unsigned int*)(0x42702090UL))
#define bM0P_MSC1_I2C_BS_RAD                            *((volatile unsigned int*)(0x42702094UL))
#define bM0P_MSC1_I2C_BS_ACKF                           *((volatile unsigned int*)(0x42702098UL))
#define bM0P_MSC1_I2C_BS_FBB                            *((volatile unsigned int*)(0x4270209CUL))
#define bM0P_MSC1_I2C_SR_TBIF                           *((volatile unsigned int*)(0x427020A0UL))
#define bM0P_MSC1_I2C_SR_TDEF                           *((volatile unsigned int*)(0x427020A4UL))
#define bM0P_MSC1_I2C_SR_RDFF                           *((volatile unsigned int*)(0x427020A8UL))
#define bM0P_MSC1_I2C_SR_ORF                            *((volatile unsigned int*)(0x427020ACUL))
#define bM0P_MSC1_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x427020B0UL))
#define bM0P_MSC1_I2C_SR_TEFS                           *((volatile unsigned int*)(0x427020B8UL))
#define bM0P_MSC1_I2C_SR_RECLR                          *((volatile unsigned int*)(0x427020BCUL))
#define bM0P_MSC1_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x42702180UL))
#define bM0P_MSC1_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x42702184UL))
#define bM0P_MSC1_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x42702188UL))
#define bM0P_MSC1_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x4270218CUL))
#define bM0P_MSC1_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x42702190UL))
#define bM0P_MSC1_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x42702194UL))
#define bM0P_MSC1_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x42702198UL))
#define bM0P_MSC1_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x4270219CUL))
#define bM0P_MSC1_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x427021A0UL))
#define bM0P_MSC1_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x427021A4UL))
#define bM0P_MSC1_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x427021A8UL))
#define bM0P_MSC1_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x427021ACUL))
#define bM0P_MSC1_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x427021B0UL))
#define bM0P_MSC1_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x427021B4UL))
#define bM0P_MSC1_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x427021B8UL))
#define bM0P_MSC1_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x42702200UL))
#define bM0P_MSC1_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x42702204UL))
#define bM0P_MSC1_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x42702208UL))
#define bM0P_MSC1_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x4270220CUL))
#define bM0P_MSC1_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x42702210UL))
#define bM0P_MSC1_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x42702214UL))
#define bM0P_MSC1_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x42702218UL))
#define bM0P_MSC1_I2C_SA_AE                             *((volatile unsigned int*)(0x4270221CUL))
#define bM0P_MSC1_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x42702220UL))
#define bM0P_MSC1_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x42702224UL))
#define bM0P_MSC1_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x42702228UL))
#define bM0P_MSC1_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x4270222CUL))
#define bM0P_MSC1_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x42702230UL))
#define bM0P_MSC1_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x42702234UL))
#define bM0P_MSC1_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x42702238UL))
#define bM0P_MSC1_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x4270223CUL))
#define bM0P_MSC1_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x427023A0UL))
#define bM0P_MSC1_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x427023A4UL))
#define bM0P_MSC1_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x427023A8UL))
#define bM0P_MSC1_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x427023ACUL))
#define bM0P_MSC1_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x427023B0UL))
#define bM0P_MSC1_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x427023B4UL))
#define bM0P_MSC2_I2C_MR_TXIE                           *((volatile unsigned int*)(0x42704008UL))
#define bM0P_MSC2_I2C_MR_RXIE                           *((volatile unsigned int*)(0x4270400CUL))
#define bM0P_MSC2_I2C_MR_MODE0                          *((volatile unsigned int*)(0x42704014UL))
#define bM0P_MSC2_I2C_MR_MODE1                          *((volatile unsigned int*)(0x42704018UL))
#define bM0P_MSC2_I2C_MR_MODE2                          *((volatile unsigned int*)(0x4270401CUL))
#define bM0P_MSC2_I2C_BC_INTF                           *((volatile unsigned int*)(0x42704020UL))
#define bM0P_MSC2_I2C_BC_BERF                           *((volatile unsigned int*)(0x42704024UL))
#define bM0P_MSC2_I2C_BC_INTE                           *((volatile unsigned int*)(0x42704028UL))
#define bM0P_MSC2_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x4270402CUL))
#define bM0P_MSC2_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x42704030UL))
#define bM0P_MSC2_I2C_BC_ACKE                           *((volatile unsigned int*)(0x42704034UL))
#define bM0P_MSC2_I2C_BC_OFITS                          *((volatile unsigned int*)(0x42704038UL))
#define bM0P_MSC2_I2C_BC_MSS                            *((volatile unsigned int*)(0x4270403CUL))
#define bM0P_MSC2_I2C_BS_BSS                            *((volatile unsigned int*)(0x42704080UL))
#define bM0P_MSC2_I2C_BS_STPCC                          *((volatile unsigned int*)(0x42704084UL))
#define bM0P_MSC2_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x42704088UL))
#define bM0P_MSC2_I2C_BS_ABL                            *((volatile unsigned int*)(0x4270408CUL))
#define bM0P_MSC2_I2C_BS_TRX                            *((volatile unsigned int*)(0x42704090UL))
#define bM0P_MSC2_I2C_BS_RAD                            *((volatile unsigned int*)(0x42704094UL))
#define bM0P_MSC2_I2C_BS_ACKF                           *((volatile unsigned int*)(0x42704098UL))
#define bM0P_MSC2_I2C_BS_FBB                            *((volatile unsigned int*)(0x4270409CUL))
#define bM0P_MSC2_I2C_SR_TBIF                           *((volatile unsigned int*)(0x427040A0UL))
#define bM0P_MSC2_I2C_SR_TDEF                           *((volatile unsigned int*)(0x427040A4UL))
#define bM0P_MSC2_I2C_SR_RDFF                           *((volatile unsigned int*)(0x427040A8UL))
#define bM0P_MSC2_I2C_SR_ORF                            *((volatile unsigned int*)(0x427040ACUL))
#define bM0P_MSC2_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x427040B0UL))
#define bM0P_MSC2_I2C_SR_TEFS                           *((volatile unsigned int*)(0x427040B8UL))
#define bM0P_MSC2_I2C_SR_RECLR                          *((volatile unsigned int*)(0x427040BCUL))
#define bM0P_MSC2_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x42704180UL))
#define bM0P_MSC2_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x42704184UL))
#define bM0P_MSC2_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x42704188UL))
#define bM0P_MSC2_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x4270418CUL))
#define bM0P_MSC2_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x42704190UL))
#define bM0P_MSC2_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x42704194UL))
#define bM0P_MSC2_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x42704198UL))
#define bM0P_MSC2_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x4270419CUL))
#define bM0P_MSC2_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x427041A0UL))
#define bM0P_MSC2_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x427041A4UL))
#define bM0P_MSC2_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x427041A8UL))
#define bM0P_MSC2_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x427041ACUL))
#define bM0P_MSC2_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x427041B0UL))
#define bM0P_MSC2_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x427041B4UL))
#define bM0P_MSC2_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x427041B8UL))
#define bM0P_MSC2_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x42704200UL))
#define bM0P_MSC2_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x42704204UL))
#define bM0P_MSC2_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x42704208UL))
#define bM0P_MSC2_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x4270420CUL))
#define bM0P_MSC2_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x42704210UL))
#define bM0P_MSC2_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x42704214UL))
#define bM0P_MSC2_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x42704218UL))
#define bM0P_MSC2_I2C_SA_AE                             *((volatile unsigned int*)(0x4270421CUL))
#define bM0P_MSC2_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x42704220UL))
#define bM0P_MSC2_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x42704224UL))
#define bM0P_MSC2_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x42704228UL))
#define bM0P_MSC2_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x4270422CUL))
#define bM0P_MSC2_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x42704230UL))
#define bM0P_MSC2_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x42704234UL))
#define bM0P_MSC2_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x42704238UL))
#define bM0P_MSC2_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x4270423CUL))
#define bM0P_MSC2_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x427043A0UL))
#define bM0P_MSC2_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x427043A4UL))
#define bM0P_MSC2_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x427043A8UL))
#define bM0P_MSC2_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x427043ACUL))
#define bM0P_MSC2_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x427043B0UL))
#define bM0P_MSC2_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x427043B4UL))
#define bM0P_MSC4_I2C_MR_TXIE                           *((volatile unsigned int*)(0x426E0008UL))
#define bM0P_MSC4_I2C_MR_RXIE                           *((volatile unsigned int*)(0x426E000CUL))
#define bM0P_MSC4_I2C_MR_MODE0                          *((volatile unsigned int*)(0x426E0014UL))
#define bM0P_MSC4_I2C_MR_MODE1                          *((volatile unsigned int*)(0x426E0018UL))
#define bM0P_MSC4_I2C_MR_MODE2                          *((volatile unsigned int*)(0x426E001CUL))
#define bM0P_MSC4_I2C_BC_INTF                           *((volatile unsigned int*)(0x426E0020UL))
#define bM0P_MSC4_I2C_BC_BERF                           *((volatile unsigned int*)(0x426E0024UL))
#define bM0P_MSC4_I2C_BC_INTE                           *((volatile unsigned int*)(0x426E0028UL))
#define bM0P_MSC4_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x426E002CUL))
#define bM0P_MSC4_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x426E0030UL))
#define bM0P_MSC4_I2C_BC_ACKE                           *((volatile unsigned int*)(0x426E0034UL))
#define bM0P_MSC4_I2C_BC_OFITS                          *((volatile unsigned int*)(0x426E0038UL))
#define bM0P_MSC4_I2C_BC_MSS                            *((volatile unsigned int*)(0x426E003CUL))
#define bM0P_MSC4_I2C_BS_BSS                            *((volatile unsigned int*)(0x426E0080UL))
#define bM0P_MSC4_I2C_BS_STPCC                          *((volatile unsigned int*)(0x426E0084UL))
#define bM0P_MSC4_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x426E0088UL))
#define bM0P_MSC4_I2C_BS_ABL                            *((volatile unsigned int*)(0x426E008CUL))
#define bM0P_MSC4_I2C_BS_TRX                            *((volatile unsigned int*)(0x426E0090UL))
#define bM0P_MSC4_I2C_BS_RAD                            *((volatile unsigned int*)(0x426E0094UL))
#define bM0P_MSC4_I2C_BS_ACKF                           *((volatile unsigned int*)(0x426E0098UL))
#define bM0P_MSC4_I2C_BS_FBB                            *((volatile unsigned int*)(0x426E009CUL))
#define bM0P_MSC4_I2C_SR_TBIF                           *((volatile unsigned int*)(0x426E00A0UL))
#define bM0P_MSC4_I2C_SR_TDEF                           *((volatile unsigned int*)(0x426E00A4UL))
#define bM0P_MSC4_I2C_SR_RDFF                           *((volatile unsigned int*)(0x426E00A8UL))
#define bM0P_MSC4_I2C_SR_ORF                            *((volatile unsigned int*)(0x426E00ACUL))
#define bM0P_MSC4_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x426E00B0UL))
#define bM0P_MSC4_I2C_SR_TEFS                           *((volatile unsigned int*)(0x426E00B8UL))
#define bM0P_MSC4_I2C_SR_RECLR                          *((volatile unsigned int*)(0x426E00BCUL))
#define bM0P_MSC4_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x426E0180UL))
#define bM0P_MSC4_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x426E0184UL))
#define bM0P_MSC4_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x426E0188UL))
#define bM0P_MSC4_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x426E018CUL))
#define bM0P_MSC4_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x426E0190UL))
#define bM0P_MSC4_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x426E0194UL))
#define bM0P_MSC4_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x426E0198UL))
#define bM0P_MSC4_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x426E019CUL))
#define bM0P_MSC4_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x426E01A0UL))
#define bM0P_MSC4_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x426E01A4UL))
#define bM0P_MSC4_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x426E01A8UL))
#define bM0P_MSC4_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x426E01ACUL))
#define bM0P_MSC4_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x426E01B0UL))
#define bM0P_MSC4_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x426E01B4UL))
#define bM0P_MSC4_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x426E01B8UL))
#define bM0P_MSC4_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x426E0200UL))
#define bM0P_MSC4_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x426E0204UL))
#define bM0P_MSC4_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x426E0208UL))
#define bM0P_MSC4_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x426E020CUL))
#define bM0P_MSC4_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x426E0210UL))
#define bM0P_MSC4_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x426E0214UL))
#define bM0P_MSC4_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x426E0218UL))
#define bM0P_MSC4_I2C_SA_AE                             *((volatile unsigned int*)(0x426E021CUL))
#define bM0P_MSC4_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x426E0220UL))
#define bM0P_MSC4_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x426E0224UL))
#define bM0P_MSC4_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x426E0228UL))
#define bM0P_MSC4_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x426E022CUL))
#define bM0P_MSC4_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x426E0230UL))
#define bM0P_MSC4_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x426E0234UL))
#define bM0P_MSC4_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x426E0238UL))
#define bM0P_MSC4_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x426E023CUL))
#define bM0P_MSC4_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x426E03A0UL))
#define bM0P_MSC4_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x426E03A4UL))
#define bM0P_MSC4_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x426E03A8UL))
#define bM0P_MSC4_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x426E03ACUL))
#define bM0P_MSC4_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x426E03B0UL))
#define bM0P_MSC4_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x426E03B4UL))
#define bM0P_MSC5_I2C_MR_TXIE                           *((volatile unsigned int*)(0x426E2008UL))
#define bM0P_MSC5_I2C_MR_RXIE                           *((volatile unsigned int*)(0x426E200CUL))
#define bM0P_MSC5_I2C_MR_MODE0                          *((volatile unsigned int*)(0x426E2014UL))
#define bM0P_MSC5_I2C_MR_MODE1                          *((volatile unsigned int*)(0x426E2018UL))
#define bM0P_MSC5_I2C_MR_MODE2                          *((volatile unsigned int*)(0x426E201CUL))
#define bM0P_MSC5_I2C_BC_INTF                           *((volatile unsigned int*)(0x426E2020UL))
#define bM0P_MSC5_I2C_BC_BERF                           *((volatile unsigned int*)(0x426E2024UL))
#define bM0P_MSC5_I2C_BC_INTE                           *((volatile unsigned int*)(0x426E2028UL))
#define bM0P_MSC5_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x426E202CUL))
#define bM0P_MSC5_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x426E2030UL))
#define bM0P_MSC5_I2C_BC_ACKE                           *((volatile unsigned int*)(0x426E2034UL))
#define bM0P_MSC5_I2C_BC_OFITS                          *((volatile unsigned int*)(0x426E2038UL))
#define bM0P_MSC5_I2C_BC_MSS                            *((volatile unsigned int*)(0x426E203CUL))
#define bM0P_MSC5_I2C_BS_BSS                            *((volatile unsigned int*)(0x426E2080UL))
#define bM0P_MSC5_I2C_BS_STPCC                          *((volatile unsigned int*)(0x426E2084UL))
#define bM0P_MSC5_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x426E2088UL))
#define bM0P_MSC5_I2C_BS_ABL                            *((volatile unsigned int*)(0x426E208CUL))
#define bM0P_MSC5_I2C_BS_TRX                            *((volatile unsigned int*)(0x426E2090UL))
#define bM0P_MSC5_I2C_BS_RAD                            *((volatile unsigned int*)(0x426E2094UL))
#define bM0P_MSC5_I2C_BS_ACKF                           *((volatile unsigned int*)(0x426E2098UL))
#define bM0P_MSC5_I2C_BS_FBB                            *((volatile unsigned int*)(0x426E209CUL))
#define bM0P_MSC5_I2C_SR_TBIF                           *((volatile unsigned int*)(0x426E20A0UL))
#define bM0P_MSC5_I2C_SR_TDEF                           *((volatile unsigned int*)(0x426E20A4UL))
#define bM0P_MSC5_I2C_SR_RDFF                           *((volatile unsigned int*)(0x426E20A8UL))
#define bM0P_MSC5_I2C_SR_ORF                            *((volatile unsigned int*)(0x426E20ACUL))
#define bM0P_MSC5_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x426E20B0UL))
#define bM0P_MSC5_I2C_SR_TEFS                           *((volatile unsigned int*)(0x426E20B8UL))
#define bM0P_MSC5_I2C_SR_RECLR                          *((volatile unsigned int*)(0x426E20BCUL))
#define bM0P_MSC5_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x426E2180UL))
#define bM0P_MSC5_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x426E2184UL))
#define bM0P_MSC5_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x426E2188UL))
#define bM0P_MSC5_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x426E218CUL))
#define bM0P_MSC5_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x426E2190UL))
#define bM0P_MSC5_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x426E2194UL))
#define bM0P_MSC5_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x426E2198UL))
#define bM0P_MSC5_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x426E219CUL))
#define bM0P_MSC5_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x426E21A0UL))
#define bM0P_MSC5_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x426E21A4UL))
#define bM0P_MSC5_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x426E21A8UL))
#define bM0P_MSC5_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x426E21ACUL))
#define bM0P_MSC5_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x426E21B0UL))
#define bM0P_MSC5_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x426E21B4UL))
#define bM0P_MSC5_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x426E21B8UL))
#define bM0P_MSC5_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x426E2200UL))
#define bM0P_MSC5_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x426E2204UL))
#define bM0P_MSC5_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x426E2208UL))
#define bM0P_MSC5_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x426E220CUL))
#define bM0P_MSC5_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x426E2210UL))
#define bM0P_MSC5_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x426E2214UL))
#define bM0P_MSC5_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x426E2218UL))
#define bM0P_MSC5_I2C_SA_AE                             *((volatile unsigned int*)(0x426E221CUL))
#define bM0P_MSC5_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x426E2220UL))
#define bM0P_MSC5_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x426E2224UL))
#define bM0P_MSC5_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x426E2228UL))
#define bM0P_MSC5_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x426E222CUL))
#define bM0P_MSC5_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x426E2230UL))
#define bM0P_MSC5_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x426E2234UL))
#define bM0P_MSC5_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x426E2238UL))
#define bM0P_MSC5_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x426E223CUL))
#define bM0P_MSC5_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x426E23A0UL))
#define bM0P_MSC5_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x426E23A4UL))
#define bM0P_MSC5_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x426E23A8UL))
#define bM0P_MSC5_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x426E23ACUL))
#define bM0P_MSC5_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x426E23B0UL))
#define bM0P_MSC5_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x426E23B4UL))
#define bM0P_MSC6_I2C_MR_TXIE                           *((volatile unsigned int*)(0x426E4008UL))
#define bM0P_MSC6_I2C_MR_RXIE                           *((volatile unsigned int*)(0x426E400CUL))
#define bM0P_MSC6_I2C_MR_MODE0                          *((volatile unsigned int*)(0x426E4014UL))
#define bM0P_MSC6_I2C_MR_MODE1                          *((volatile unsigned int*)(0x426E4018UL))
#define bM0P_MSC6_I2C_MR_MODE2                          *((volatile unsigned int*)(0x426E401CUL))
#define bM0P_MSC6_I2C_BC_INTF                           *((volatile unsigned int*)(0x426E4020UL))
#define bM0P_MSC6_I2C_BC_BERF                           *((volatile unsigned int*)(0x426E4024UL))
#define bM0P_MSC6_I2C_BC_INTE                           *((volatile unsigned int*)(0x426E4028UL))
#define bM0P_MSC6_I2C_BC_CNDDIE                         *((volatile unsigned int*)(0x426E402CUL))
#define bM0P_MSC6_I2C_BC_WTSEL                          *((volatile unsigned int*)(0x426E4030UL))
#define bM0P_MSC6_I2C_BC_ACKE                           *((volatile unsigned int*)(0x426E4034UL))
#define bM0P_MSC6_I2C_BC_OFITS                          *((volatile unsigned int*)(0x426E4038UL))
#define bM0P_MSC6_I2C_BC_MSS                            *((volatile unsigned int*)(0x426E403CUL))
#define bM0P_MSC6_I2C_BS_BSS                            *((volatile unsigned int*)(0x426E4080UL))
#define bM0P_MSC6_I2C_BS_STPCC                          *((volatile unsigned int*)(0x426E4084UL))
#define bM0P_MSC6_I2C_BS_ITSCC                          *((volatile unsigned int*)(0x426E4088UL))
#define bM0P_MSC6_I2C_BS_ABL                            *((volatile unsigned int*)(0x426E408CUL))
#define bM0P_MSC6_I2C_BS_TRX                            *((volatile unsigned int*)(0x426E4090UL))
#define bM0P_MSC6_I2C_BS_RAD                            *((volatile unsigned int*)(0x426E4094UL))
#define bM0P_MSC6_I2C_BS_ACKF                           *((volatile unsigned int*)(0x426E4098UL))
#define bM0P_MSC6_I2C_BS_FBB                            *((volatile unsigned int*)(0x426E409CUL))
#define bM0P_MSC6_I2C_SR_TBIF                           *((volatile unsigned int*)(0x426E40A0UL))
#define bM0P_MSC6_I2C_SR_TDEF                           *((volatile unsigned int*)(0x426E40A4UL))
#define bM0P_MSC6_I2C_SR_RDFF                           *((volatile unsigned int*)(0x426E40A8UL))
#define bM0P_MSC6_I2C_SR_ORF                            *((volatile unsigned int*)(0x426E40ACUL))
#define bM0P_MSC6_I2C_SR_TBIIE                          *((volatile unsigned int*)(0x426E40B0UL))
#define bM0P_MSC6_I2C_SR_TEFS                           *((volatile unsigned int*)(0x426E40B8UL))
#define bM0P_MSC6_I2C_SR_RECLR                          *((volatile unsigned int*)(0x426E40BCUL))
#define bM0P_MSC6_I2C_BRS_BRS0                          *((volatile unsigned int*)(0x426E4180UL))
#define bM0P_MSC6_I2C_BRS_BRS1                          *((volatile unsigned int*)(0x426E4184UL))
#define bM0P_MSC6_I2C_BRS_BRS2                          *((volatile unsigned int*)(0x426E4188UL))
#define bM0P_MSC6_I2C_BRS_BRS3                          *((volatile unsigned int*)(0x426E418CUL))
#define bM0P_MSC6_I2C_BRS_BRS4                          *((volatile unsigned int*)(0x426E4190UL))
#define bM0P_MSC6_I2C_BRS_BRS5                          *((volatile unsigned int*)(0x426E4194UL))
#define bM0P_MSC6_I2C_BRS_BRS6                          *((volatile unsigned int*)(0x426E4198UL))
#define bM0P_MSC6_I2C_BRS_BRS7                          *((volatile unsigned int*)(0x426E419CUL))
#define bM0P_MSC6_I2C_BRS_BRS8                          *((volatile unsigned int*)(0x426E41A0UL))
#define bM0P_MSC6_I2C_BRS_BRS9                          *((volatile unsigned int*)(0x426E41A4UL))
#define bM0P_MSC6_I2C_BRS_BRS10                         *((volatile unsigned int*)(0x426E41A8UL))
#define bM0P_MSC6_I2C_BRS_BRS11                         *((volatile unsigned int*)(0x426E41ACUL))
#define bM0P_MSC6_I2C_BRS_BRS12                         *((volatile unsigned int*)(0x426E41B0UL))
#define bM0P_MSC6_I2C_BRS_BRS13                         *((volatile unsigned int*)(0x426E41B4UL))
#define bM0P_MSC6_I2C_BRS_BRS14                         *((volatile unsigned int*)(0x426E41B8UL))
#define bM0P_MSC6_I2C_SA_ADDR0                          *((volatile unsigned int*)(0x426E4200UL))
#define bM0P_MSC6_I2C_SA_ADDR1                          *((volatile unsigned int*)(0x426E4204UL))
#define bM0P_MSC6_I2C_SA_ADDR2                          *((volatile unsigned int*)(0x426E4208UL))
#define bM0P_MSC6_I2C_SA_ADDR3                          *((volatile unsigned int*)(0x426E420CUL))
#define bM0P_MSC6_I2C_SA_ADDR4                          *((volatile unsigned int*)(0x426E4210UL))
#define bM0P_MSC6_I2C_SA_ADDR5                          *((volatile unsigned int*)(0x426E4214UL))
#define bM0P_MSC6_I2C_SA_ADDR6                          *((volatile unsigned int*)(0x426E4218UL))
#define bM0P_MSC6_I2C_SA_AE                             *((volatile unsigned int*)(0x426E421CUL))
#define bM0P_MSC6_I2C_SAMSK_MSK0                        *((volatile unsigned int*)(0x426E4220UL))
#define bM0P_MSC6_I2C_SAMSK_MSK1                        *((volatile unsigned int*)(0x426E4224UL))
#define bM0P_MSC6_I2C_SAMSK_MSK2                        *((volatile unsigned int*)(0x426E4228UL))
#define bM0P_MSC6_I2C_SAMSK_MSK3                        *((volatile unsigned int*)(0x426E422CUL))
#define bM0P_MSC6_I2C_SAMSK_MSK4                        *((volatile unsigned int*)(0x426E4230UL))
#define bM0P_MSC6_I2C_SAMSK_MSK5                        *((volatile unsigned int*)(0x426E4234UL))
#define bM0P_MSC6_I2C_SAMSK_MSK6                        *((volatile unsigned int*)(0x426E4238UL))
#define bM0P_MSC6_I2C_SAMSK_EN                          *((volatile unsigned int*)(0x426E423CUL))
#define bM0P_MSC6_I2C_EBCR_BEC                          *((volatile unsigned int*)(0x426E43A0UL))
#define bM0P_MSC6_I2C_EBCR_DOE                          *((volatile unsigned int*)(0x426E43A4UL))
#define bM0P_MSC6_I2C_EBCR_SCLOC                        *((volatile unsigned int*)(0x426E43A8UL))
#define bM0P_MSC6_I2C_EBCR_SDAOC                        *((volatile unsigned int*)(0x426E43ACUL))
#define bM0P_MSC6_I2C_EBCR_SCLS                         *((volatile unsigned int*)(0x426E43B0UL))
#define bM0P_MSC6_I2C_EBCR_SDAS                         *((volatile unsigned int*)(0x426E43B4UL))
#define bM0P_MSC0_SPI_MR_DOE                            *((volatile unsigned int*)(0x42700000UL))
#define bM0P_MSC0_SPI_MR_CKE                            *((volatile unsigned int*)(0x42700004UL))
#define bM0P_MSC0_SPI_MR_TDS                            *((volatile unsigned int*)(0x42700008UL))
#define bM0P_MSC0_SPI_MR_CINV                           *((volatile unsigned int*)(0x4270000CUL))
#define bM0P_MSC0_SPI_MR_MODE0                          *((volatile unsigned int*)(0x42700014UL))
#define bM0P_MSC0_SPI_MR_MODE1                          *((volatile unsigned int*)(0x42700018UL))
#define bM0P_MSC0_SPI_MR_MODE2                          *((volatile unsigned int*)(0x4270001CUL))
#define bM0P_MSC0_SPI_CR_TXE                            *((volatile unsigned int*)(0x42700020UL))
#define bM0P_MSC0_SPI_CR_RXE                            *((volatile unsigned int*)(0x42700024UL))
#define bM0P_MSC0_SPI_CR_TBIE                           *((volatile unsigned int*)(0x42700028UL))
#define bM0P_MSC0_SPI_CR_TXIE                           *((volatile unsigned int*)(0x4270002CUL))
#define bM0P_MSC0_SPI_CR_RXIE                           *((volatile unsigned int*)(0x42700030UL))
#define bM0P_MSC0_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x42700034UL))
#define bM0P_MSC0_SPI_CR_MSS                            *((volatile unsigned int*)(0x42700038UL))
#define bM0P_MSC0_SPI_CR_PCL                            *((volatile unsigned int*)(0x4270003CUL))
#define bM0P_MSC0_SPI_ECR_DL0                           *((volatile unsigned int*)(0x42700080UL))
#define bM0P_MSC0_SPI_ECR_DL1                           *((volatile unsigned int*)(0x42700084UL))
#define bM0P_MSC0_SPI_ECR_DL2                           *((volatile unsigned int*)(0x42700088UL))
#define bM0P_MSC0_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x4270008CUL))
#define bM0P_MSC0_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x42700090UL))
#define bM0P_MSC0_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x42700094UL))
#define bM0P_MSC0_SPI_ECR_DL3                           *((volatile unsigned int*)(0x42700098UL))
#define bM0P_MSC0_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x4270009CUL))
#define bM0P_MSC0_SPI_SR_TBIF                           *((volatile unsigned int*)(0x427000A0UL))
#define bM0P_MSC0_SPI_SR_TDEF                           *((volatile unsigned int*)(0x427000A4UL))
#define bM0P_MSC0_SPI_SR_RDFF                           *((volatile unsigned int*)(0x427000A8UL))
#define bM0P_MSC0_SPI_SR_ORF                            *((volatile unsigned int*)(0x427000ACUL))
#define bM0P_MSC0_SPI_SR_RECLR                          *((volatile unsigned int*)(0x427000BCUL))
#define bM0P_MSC0_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x42700180UL))
#define bM0P_MSC0_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x42700184UL))
#define bM0P_MSC0_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x42700188UL))
#define bM0P_MSC0_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x4270018CUL))
#define bM0P_MSC0_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x42700190UL))
#define bM0P_MSC0_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x42700194UL))
#define bM0P_MSC0_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x42700198UL))
#define bM0P_MSC0_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x4270019CUL))
#define bM0P_MSC0_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x427001A0UL))
#define bM0P_MSC0_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x427001A4UL))
#define bM0P_MSC0_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x427001A8UL))
#define bM0P_MSC0_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x427001ACUL))
#define bM0P_MSC0_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x427001B0UL))
#define bM0P_MSC0_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x427001B4UL))
#define bM0P_MSC0_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x427001B8UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x42700380UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x42700384UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x42700388UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x4270038CUL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x42700390UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x42700394UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x42700398UL))
#define bM0P_MSC0_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x4270039CUL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x427003A0UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x427003A4UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x427003A8UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x427003ACUL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x427003B0UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x427003B4UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x427003B8UL))
#define bM0P_MSC0_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x427003BCUL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x42700400UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x42700404UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x42700408UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x4270040CUL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x42700410UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x42700414UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x42700418UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x4270041CUL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x42700420UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x42700424UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x42700428UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x4270042CUL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x42700430UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x42700434UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x42700438UL))
#define bM0P_MSC0_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x4270043CUL))
#define bM0P_MSC0_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x42700480UL))
#define bM0P_MSC0_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x42700484UL))
#define bM0P_MSC0_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x42700488UL))
#define bM0P_MSC0_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x4270048CUL))
#define bM0P_MSC0_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x42700490UL))
#define bM0P_MSC0_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x42700498UL))
#define bM0P_MSC0_SPI_EACR_TIE                          *((volatile unsigned int*)(0x4270049CUL))
#define bM0P_MSC0_SPI_EACR_TIF                          *((volatile unsigned int*)(0x427004A0UL))
#define bM0P_MSC0_SPI_EACR_CSER                         *((volatile unsigned int*)(0x427004ACUL))
#define bM0P_MSC0_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x427004B0UL))
#define bM0P_MSC0_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x427004B4UL))
#define bM0P_MSC0_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x42700500UL))
#define bM0P_MSC0_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x42700504UL))
#define bM0P_MSC0_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x42700508UL))
#define bM0P_MSC0_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x4270050CUL))
#define bM0P_MSC0_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x42700510UL))
#define bM0P_MSC0_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x42700514UL))
#define bM0P_MSC0_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x42700518UL))
#define bM0P_MSC0_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x4270051CUL))
#define bM0P_MSC0_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x42700520UL))
#define bM0P_MSC0_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x42700524UL))
#define bM0P_MSC0_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x42700528UL))
#define bM0P_MSC0_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x4270052CUL))
#define bM0P_MSC0_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x42700530UL))
#define bM0P_MSC0_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x42700534UL))
#define bM0P_MSC0_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x42700538UL))
#define bM0P_MSC0_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x4270053CUL))
#define bM0P_MSC0_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x42700580UL))
#define bM0P_MSC0_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x42700584UL))
#define bM0P_MSC0_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x42700588UL))
#define bM0P_MSC0_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x4270058CUL))
#define bM0P_MSC0_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x42700590UL))
#define bM0P_MSC0_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x42700594UL))
#define bM0P_MSC0_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x42700598UL))
#define bM0P_MSC0_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x4270059CUL))
#define bM0P_MSC0_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x427005A0UL))
#define bM0P_MSC0_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x427005A4UL))
#define bM0P_MSC0_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x427005A8UL))
#define bM0P_MSC0_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x427005ACUL))
#define bM0P_MSC0_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x427005B0UL))
#define bM0P_MSC0_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x427005B4UL))
#define bM0P_MSC0_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x427005B8UL))
#define bM0P_MSC0_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x427005BCUL))
#define bM0P_MSC0_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x42700600UL))
#define bM0P_MSC0_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x42700604UL))
#define bM0P_MSC0_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x42700608UL))
#define bM0P_MSC0_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x4270060CUL))
#define bM0P_MSC0_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x42700610UL))
#define bM0P_MSC0_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x42700614UL))
#define bM0P_MSC0_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x42700618UL))
#define bM0P_MSC0_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x4270061CUL))
#define bM0P_MSC0_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x42700620UL))
#define bM0P_MSC0_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x42700624UL))
#define bM0P_MSC0_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x42700628UL))
#define bM0P_MSC0_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x4270062CUL))
#define bM0P_MSC0_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x42700630UL))
#define bM0P_MSC0_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x42700634UL))
#define bM0P_MSC0_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x42700638UL))
#define bM0P_MSC0_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x4270063CUL))
#define bM0P_MSC0_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x42700680UL))
#define bM0P_MSC0_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x42700684UL))
#define bM0P_MSC0_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x42700688UL))
#define bM0P_MSC0_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x4270068CUL))
#define bM0P_MSC0_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x42700690UL))
#define bM0P_MSC0_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x42700694UL))
#define bM0P_MSC0_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x42700698UL))
#define bM0P_MSC0_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x4270069CUL))
#define bM0P_MSC0_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x427006A0UL))
#define bM0P_MSC0_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x427006A4UL))
#define bM0P_MSC0_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x427006A8UL))
#define bM0P_MSC0_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x427006ACUL))
#define bM0P_MSC0_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x427006B0UL))
#define bM0P_MSC0_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x427006B4UL))
#define bM0P_MSC0_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x427006B8UL))
#define bM0P_MSC0_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x427006BCUL))
#define bM0P_MSC0_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x42700700UL))
#define bM0P_MSC0_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x42700704UL))
#define bM0P_MSC0_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x42700708UL))
#define bM0P_MSC0_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x4270070CUL))
#define bM0P_MSC0_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x42700710UL))
#define bM0P_MSC0_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x42700714UL))
#define bM0P_MSC0_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x42700718UL))
#define bM0P_MSC0_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x4270071CUL))
#define bM0P_MSC1_SPI_MR_DOE                            *((volatile unsigned int*)(0x42702000UL))
#define bM0P_MSC1_SPI_MR_CKE                            *((volatile unsigned int*)(0x42702004UL))
#define bM0P_MSC1_SPI_MR_TDS                            *((volatile unsigned int*)(0x42702008UL))
#define bM0P_MSC1_SPI_MR_CINV                           *((volatile unsigned int*)(0x4270200CUL))
#define bM0P_MSC1_SPI_MR_MODE0                          *((volatile unsigned int*)(0x42702014UL))
#define bM0P_MSC1_SPI_MR_MODE1                          *((volatile unsigned int*)(0x42702018UL))
#define bM0P_MSC1_SPI_MR_MODE2                          *((volatile unsigned int*)(0x4270201CUL))
#define bM0P_MSC1_SPI_CR_TXE                            *((volatile unsigned int*)(0x42702020UL))
#define bM0P_MSC1_SPI_CR_RXE                            *((volatile unsigned int*)(0x42702024UL))
#define bM0P_MSC1_SPI_CR_TBIE                           *((volatile unsigned int*)(0x42702028UL))
#define bM0P_MSC1_SPI_CR_TXIE                           *((volatile unsigned int*)(0x4270202CUL))
#define bM0P_MSC1_SPI_CR_RXIE                           *((volatile unsigned int*)(0x42702030UL))
#define bM0P_MSC1_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x42702034UL))
#define bM0P_MSC1_SPI_CR_MSS                            *((volatile unsigned int*)(0x42702038UL))
#define bM0P_MSC1_SPI_CR_PCL                            *((volatile unsigned int*)(0x4270203CUL))
#define bM0P_MSC1_SPI_ECR_DL0                           *((volatile unsigned int*)(0x42702080UL))
#define bM0P_MSC1_SPI_ECR_DL1                           *((volatile unsigned int*)(0x42702084UL))
#define bM0P_MSC1_SPI_ECR_DL2                           *((volatile unsigned int*)(0x42702088UL))
#define bM0P_MSC1_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x4270208CUL))
#define bM0P_MSC1_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x42702090UL))
#define bM0P_MSC1_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x42702094UL))
#define bM0P_MSC1_SPI_ECR_DL3                           *((volatile unsigned int*)(0x42702098UL))
#define bM0P_MSC1_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x4270209CUL))
#define bM0P_MSC1_SPI_SR_TBIF                           *((volatile unsigned int*)(0x427020A0UL))
#define bM0P_MSC1_SPI_SR_TDEF                           *((volatile unsigned int*)(0x427020A4UL))
#define bM0P_MSC1_SPI_SR_RDFF                           *((volatile unsigned int*)(0x427020A8UL))
#define bM0P_MSC1_SPI_SR_ORF                            *((volatile unsigned int*)(0x427020ACUL))
#define bM0P_MSC1_SPI_SR_RECLR                          *((volatile unsigned int*)(0x427020BCUL))
#define bM0P_MSC1_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x42702180UL))
#define bM0P_MSC1_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x42702184UL))
#define bM0P_MSC1_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x42702188UL))
#define bM0P_MSC1_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x4270218CUL))
#define bM0P_MSC1_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x42702190UL))
#define bM0P_MSC1_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x42702194UL))
#define bM0P_MSC1_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x42702198UL))
#define bM0P_MSC1_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x4270219CUL))
#define bM0P_MSC1_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x427021A0UL))
#define bM0P_MSC1_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x427021A4UL))
#define bM0P_MSC1_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x427021A8UL))
#define bM0P_MSC1_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x427021ACUL))
#define bM0P_MSC1_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x427021B0UL))
#define bM0P_MSC1_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x427021B4UL))
#define bM0P_MSC1_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x427021B8UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x42702380UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x42702384UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x42702388UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x4270238CUL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x42702390UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x42702394UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x42702398UL))
#define bM0P_MSC1_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x4270239CUL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x427023A0UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x427023A4UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x427023A8UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x427023ACUL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x427023B0UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x427023B4UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x427023B8UL))
#define bM0P_MSC1_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x427023BCUL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x42702400UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x42702404UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x42702408UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x4270240CUL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x42702410UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x42702414UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x42702418UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x4270241CUL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x42702420UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x42702424UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x42702428UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x4270242CUL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x42702430UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x42702434UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x42702438UL))
#define bM0P_MSC1_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x4270243CUL))
#define bM0P_MSC1_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x42702480UL))
#define bM0P_MSC1_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x42702484UL))
#define bM0P_MSC1_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x42702488UL))
#define bM0P_MSC1_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x4270248CUL))
#define bM0P_MSC1_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x42702490UL))
#define bM0P_MSC1_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x42702498UL))
#define bM0P_MSC1_SPI_EACR_TIE                          *((volatile unsigned int*)(0x4270249CUL))
#define bM0P_MSC1_SPI_EACR_TIF                          *((volatile unsigned int*)(0x427024A0UL))
#define bM0P_MSC1_SPI_EACR_CSER                         *((volatile unsigned int*)(0x427024ACUL))
#define bM0P_MSC1_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x427024B0UL))
#define bM0P_MSC1_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x427024B4UL))
#define bM0P_MSC1_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x42702500UL))
#define bM0P_MSC1_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x42702504UL))
#define bM0P_MSC1_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x42702508UL))
#define bM0P_MSC1_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x4270250CUL))
#define bM0P_MSC1_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x42702510UL))
#define bM0P_MSC1_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x42702514UL))
#define bM0P_MSC1_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x42702518UL))
#define bM0P_MSC1_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x4270251CUL))
#define bM0P_MSC1_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x42702520UL))
#define bM0P_MSC1_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x42702524UL))
#define bM0P_MSC1_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x42702528UL))
#define bM0P_MSC1_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x4270252CUL))
#define bM0P_MSC1_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x42702530UL))
#define bM0P_MSC1_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x42702534UL))
#define bM0P_MSC1_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x42702538UL))
#define bM0P_MSC1_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x4270253CUL))
#define bM0P_MSC1_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x42702580UL))
#define bM0P_MSC1_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x42702584UL))
#define bM0P_MSC1_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x42702588UL))
#define bM0P_MSC1_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x4270258CUL))
#define bM0P_MSC1_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x42702590UL))
#define bM0P_MSC1_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x42702594UL))
#define bM0P_MSC1_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x42702598UL))
#define bM0P_MSC1_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x4270259CUL))
#define bM0P_MSC1_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x427025A0UL))
#define bM0P_MSC1_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x427025A4UL))
#define bM0P_MSC1_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x427025A8UL))
#define bM0P_MSC1_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x427025ACUL))
#define bM0P_MSC1_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x427025B0UL))
#define bM0P_MSC1_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x427025B4UL))
#define bM0P_MSC1_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x427025B8UL))
#define bM0P_MSC1_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x427025BCUL))
#define bM0P_MSC1_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x42702600UL))
#define bM0P_MSC1_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x42702604UL))
#define bM0P_MSC1_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x42702608UL))
#define bM0P_MSC1_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x4270260CUL))
#define bM0P_MSC1_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x42702610UL))
#define bM0P_MSC1_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x42702614UL))
#define bM0P_MSC1_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x42702618UL))
#define bM0P_MSC1_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x4270261CUL))
#define bM0P_MSC1_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x42702620UL))
#define bM0P_MSC1_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x42702624UL))
#define bM0P_MSC1_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x42702628UL))
#define bM0P_MSC1_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x4270262CUL))
#define bM0P_MSC1_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x42702630UL))
#define bM0P_MSC1_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x42702634UL))
#define bM0P_MSC1_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x42702638UL))
#define bM0P_MSC1_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x4270263CUL))
#define bM0P_MSC1_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x42702680UL))
#define bM0P_MSC1_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x42702684UL))
#define bM0P_MSC1_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x42702688UL))
#define bM0P_MSC1_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x4270268CUL))
#define bM0P_MSC1_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x42702690UL))
#define bM0P_MSC1_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x42702694UL))
#define bM0P_MSC1_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x42702698UL))
#define bM0P_MSC1_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x4270269CUL))
#define bM0P_MSC1_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x427026A0UL))
#define bM0P_MSC1_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x427026A4UL))
#define bM0P_MSC1_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x427026A8UL))
#define bM0P_MSC1_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x427026ACUL))
#define bM0P_MSC1_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x427026B0UL))
#define bM0P_MSC1_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x427026B4UL))
#define bM0P_MSC1_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x427026B8UL))
#define bM0P_MSC1_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x427026BCUL))
#define bM0P_MSC1_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x42702700UL))
#define bM0P_MSC1_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x42702704UL))
#define bM0P_MSC1_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x42702708UL))
#define bM0P_MSC1_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x4270270CUL))
#define bM0P_MSC1_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x42702710UL))
#define bM0P_MSC1_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x42702714UL))
#define bM0P_MSC1_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x42702718UL))
#define bM0P_MSC1_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x4270271CUL))
#define bM0P_MSC2_SPI_MR_DOE                            *((volatile unsigned int*)(0x42704000UL))
#define bM0P_MSC2_SPI_MR_CKE                            *((volatile unsigned int*)(0x42704004UL))
#define bM0P_MSC2_SPI_MR_TDS                            *((volatile unsigned int*)(0x42704008UL))
#define bM0P_MSC2_SPI_MR_CINV                           *((volatile unsigned int*)(0x4270400CUL))
#define bM0P_MSC2_SPI_MR_MODE0                          *((volatile unsigned int*)(0x42704014UL))
#define bM0P_MSC2_SPI_MR_MODE1                          *((volatile unsigned int*)(0x42704018UL))
#define bM0P_MSC2_SPI_MR_MODE2                          *((volatile unsigned int*)(0x4270401CUL))
#define bM0P_MSC2_SPI_CR_TXE                            *((volatile unsigned int*)(0x42704020UL))
#define bM0P_MSC2_SPI_CR_RXE                            *((volatile unsigned int*)(0x42704024UL))
#define bM0P_MSC2_SPI_CR_TBIE                           *((volatile unsigned int*)(0x42704028UL))
#define bM0P_MSC2_SPI_CR_TXIE                           *((volatile unsigned int*)(0x4270402CUL))
#define bM0P_MSC2_SPI_CR_RXIE                           *((volatile unsigned int*)(0x42704030UL))
#define bM0P_MSC2_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x42704034UL))
#define bM0P_MSC2_SPI_CR_MSS                            *((volatile unsigned int*)(0x42704038UL))
#define bM0P_MSC2_SPI_CR_PCL                            *((volatile unsigned int*)(0x4270403CUL))
#define bM0P_MSC2_SPI_ECR_DL0                           *((volatile unsigned int*)(0x42704080UL))
#define bM0P_MSC2_SPI_ECR_DL1                           *((volatile unsigned int*)(0x42704084UL))
#define bM0P_MSC2_SPI_ECR_DL2                           *((volatile unsigned int*)(0x42704088UL))
#define bM0P_MSC2_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x4270408CUL))
#define bM0P_MSC2_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x42704090UL))
#define bM0P_MSC2_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x42704094UL))
#define bM0P_MSC2_SPI_ECR_DL3                           *((volatile unsigned int*)(0x42704098UL))
#define bM0P_MSC2_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x4270409CUL))
#define bM0P_MSC2_SPI_SR_TBIF                           *((volatile unsigned int*)(0x427040A0UL))
#define bM0P_MSC2_SPI_SR_TDEF                           *((volatile unsigned int*)(0x427040A4UL))
#define bM0P_MSC2_SPI_SR_RDFF                           *((volatile unsigned int*)(0x427040A8UL))
#define bM0P_MSC2_SPI_SR_ORF                            *((volatile unsigned int*)(0x427040ACUL))
#define bM0P_MSC2_SPI_SR_RECLR                          *((volatile unsigned int*)(0x427040BCUL))
#define bM0P_MSC2_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x42704180UL))
#define bM0P_MSC2_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x42704184UL))
#define bM0P_MSC2_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x42704188UL))
#define bM0P_MSC2_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x4270418CUL))
#define bM0P_MSC2_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x42704190UL))
#define bM0P_MSC2_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x42704194UL))
#define bM0P_MSC2_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x42704198UL))
#define bM0P_MSC2_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x4270419CUL))
#define bM0P_MSC2_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x427041A0UL))
#define bM0P_MSC2_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x427041A4UL))
#define bM0P_MSC2_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x427041A8UL))
#define bM0P_MSC2_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x427041ACUL))
#define bM0P_MSC2_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x427041B0UL))
#define bM0P_MSC2_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x427041B4UL))
#define bM0P_MSC2_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x427041B8UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x42704380UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x42704384UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x42704388UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x4270438CUL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x42704390UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x42704394UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x42704398UL))
#define bM0P_MSC2_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x4270439CUL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x427043A0UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x427043A4UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x427043A8UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x427043ACUL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x427043B0UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x427043B4UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x427043B8UL))
#define bM0P_MSC2_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x427043BCUL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x42704400UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x42704404UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x42704408UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x4270440CUL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x42704410UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x42704414UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x42704418UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x4270441CUL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x42704420UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x42704424UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x42704428UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x4270442CUL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x42704430UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x42704434UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x42704438UL))
#define bM0P_MSC2_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x4270443CUL))
#define bM0P_MSC2_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x42704480UL))
#define bM0P_MSC2_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x42704484UL))
#define bM0P_MSC2_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x42704488UL))
#define bM0P_MSC2_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x4270448CUL))
#define bM0P_MSC2_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x42704490UL))
#define bM0P_MSC2_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x42704498UL))
#define bM0P_MSC2_SPI_EACR_TIE                          *((volatile unsigned int*)(0x4270449CUL))
#define bM0P_MSC2_SPI_EACR_TIF                          *((volatile unsigned int*)(0x427044A0UL))
#define bM0P_MSC2_SPI_EACR_CSER                         *((volatile unsigned int*)(0x427044ACUL))
#define bM0P_MSC2_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x427044B0UL))
#define bM0P_MSC2_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x427044B4UL))
#define bM0P_MSC2_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x42704500UL))
#define bM0P_MSC2_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x42704504UL))
#define bM0P_MSC2_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x42704508UL))
#define bM0P_MSC2_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x4270450CUL))
#define bM0P_MSC2_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x42704510UL))
#define bM0P_MSC2_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x42704514UL))
#define bM0P_MSC2_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x42704518UL))
#define bM0P_MSC2_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x4270451CUL))
#define bM0P_MSC2_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x42704520UL))
#define bM0P_MSC2_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x42704524UL))
#define bM0P_MSC2_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x42704528UL))
#define bM0P_MSC2_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x4270452CUL))
#define bM0P_MSC2_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x42704530UL))
#define bM0P_MSC2_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x42704534UL))
#define bM0P_MSC2_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x42704538UL))
#define bM0P_MSC2_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x4270453CUL))
#define bM0P_MSC2_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x42704580UL))
#define bM0P_MSC2_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x42704584UL))
#define bM0P_MSC2_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x42704588UL))
#define bM0P_MSC2_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x4270458CUL))
#define bM0P_MSC2_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x42704590UL))
#define bM0P_MSC2_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x42704594UL))
#define bM0P_MSC2_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x42704598UL))
#define bM0P_MSC2_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x4270459CUL))
#define bM0P_MSC2_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x427045A0UL))
#define bM0P_MSC2_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x427045A4UL))
#define bM0P_MSC2_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x427045A8UL))
#define bM0P_MSC2_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x427045ACUL))
#define bM0P_MSC2_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x427045B0UL))
#define bM0P_MSC2_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x427045B4UL))
#define bM0P_MSC2_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x427045B8UL))
#define bM0P_MSC2_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x427045BCUL))
#define bM0P_MSC2_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x42704600UL))
#define bM0P_MSC2_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x42704604UL))
#define bM0P_MSC2_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x42704608UL))
#define bM0P_MSC2_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x4270460CUL))
#define bM0P_MSC2_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x42704610UL))
#define bM0P_MSC2_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x42704614UL))
#define bM0P_MSC2_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x42704618UL))
#define bM0P_MSC2_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x4270461CUL))
#define bM0P_MSC2_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x42704620UL))
#define bM0P_MSC2_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x42704624UL))
#define bM0P_MSC2_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x42704628UL))
#define bM0P_MSC2_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x4270462CUL))
#define bM0P_MSC2_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x42704630UL))
#define bM0P_MSC2_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x42704634UL))
#define bM0P_MSC2_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x42704638UL))
#define bM0P_MSC2_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x4270463CUL))
#define bM0P_MSC2_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x42704680UL))
#define bM0P_MSC2_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x42704684UL))
#define bM0P_MSC2_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x42704688UL))
#define bM0P_MSC2_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x4270468CUL))
#define bM0P_MSC2_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x42704690UL))
#define bM0P_MSC2_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x42704694UL))
#define bM0P_MSC2_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x42704698UL))
#define bM0P_MSC2_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x4270469CUL))
#define bM0P_MSC2_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x427046A0UL))
#define bM0P_MSC2_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x427046A4UL))
#define bM0P_MSC2_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x427046A8UL))
#define bM0P_MSC2_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x427046ACUL))
#define bM0P_MSC2_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x427046B0UL))
#define bM0P_MSC2_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x427046B4UL))
#define bM0P_MSC2_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x427046B8UL))
#define bM0P_MSC2_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x427046BCUL))
#define bM0P_MSC2_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x42704700UL))
#define bM0P_MSC2_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x42704704UL))
#define bM0P_MSC2_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x42704708UL))
#define bM0P_MSC2_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x4270470CUL))
#define bM0P_MSC2_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x42704710UL))
#define bM0P_MSC2_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x42704714UL))
#define bM0P_MSC2_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x42704718UL))
#define bM0P_MSC2_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x4270471CUL))
#define bM0P_MSC4_SPI_MR_DOE                            *((volatile unsigned int*)(0x426E0000UL))
#define bM0P_MSC4_SPI_MR_CKE                            *((volatile unsigned int*)(0x426E0004UL))
#define bM0P_MSC4_SPI_MR_TDS                            *((volatile unsigned int*)(0x426E0008UL))
#define bM0P_MSC4_SPI_MR_CINV                           *((volatile unsigned int*)(0x426E000CUL))
#define bM0P_MSC4_SPI_MR_MODE0                          *((volatile unsigned int*)(0x426E0014UL))
#define bM0P_MSC4_SPI_MR_MODE1                          *((volatile unsigned int*)(0x426E0018UL))
#define bM0P_MSC4_SPI_MR_MODE2                          *((volatile unsigned int*)(0x426E001CUL))
#define bM0P_MSC4_SPI_CR_TXE                            *((volatile unsigned int*)(0x426E0020UL))
#define bM0P_MSC4_SPI_CR_RXE                            *((volatile unsigned int*)(0x426E0024UL))
#define bM0P_MSC4_SPI_CR_TBIE                           *((volatile unsigned int*)(0x426E0028UL))
#define bM0P_MSC4_SPI_CR_TXIE                           *((volatile unsigned int*)(0x426E002CUL))
#define bM0P_MSC4_SPI_CR_RXIE                           *((volatile unsigned int*)(0x426E0030UL))
#define bM0P_MSC4_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x426E0034UL))
#define bM0P_MSC4_SPI_CR_MSS                            *((volatile unsigned int*)(0x426E0038UL))
#define bM0P_MSC4_SPI_CR_PCL                            *((volatile unsigned int*)(0x426E003CUL))
#define bM0P_MSC4_SPI_ECR_DL0                           *((volatile unsigned int*)(0x426E0080UL))
#define bM0P_MSC4_SPI_ECR_DL1                           *((volatile unsigned int*)(0x426E0084UL))
#define bM0P_MSC4_SPI_ECR_DL2                           *((volatile unsigned int*)(0x426E0088UL))
#define bM0P_MSC4_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x426E008CUL))
#define bM0P_MSC4_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x426E0090UL))
#define bM0P_MSC4_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x426E0094UL))
#define bM0P_MSC4_SPI_ECR_DL3                           *((volatile unsigned int*)(0x426E0098UL))
#define bM0P_MSC4_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x426E009CUL))
#define bM0P_MSC4_SPI_SR_TBIF                           *((volatile unsigned int*)(0x426E00A0UL))
#define bM0P_MSC4_SPI_SR_TDEF                           *((volatile unsigned int*)(0x426E00A4UL))
#define bM0P_MSC4_SPI_SR_RDFF                           *((volatile unsigned int*)(0x426E00A8UL))
#define bM0P_MSC4_SPI_SR_ORF                            *((volatile unsigned int*)(0x426E00ACUL))
#define bM0P_MSC4_SPI_SR_RECLR                          *((volatile unsigned int*)(0x426E00BCUL))
#define bM0P_MSC4_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x426E0180UL))
#define bM0P_MSC4_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x426E0184UL))
#define bM0P_MSC4_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x426E0188UL))
#define bM0P_MSC4_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x426E018CUL))
#define bM0P_MSC4_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x426E0190UL))
#define bM0P_MSC4_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x426E0194UL))
#define bM0P_MSC4_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x426E0198UL))
#define bM0P_MSC4_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x426E019CUL))
#define bM0P_MSC4_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x426E01A0UL))
#define bM0P_MSC4_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x426E01A4UL))
#define bM0P_MSC4_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x426E01A8UL))
#define bM0P_MSC4_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x426E01ACUL))
#define bM0P_MSC4_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x426E01B0UL))
#define bM0P_MSC4_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x426E01B4UL))
#define bM0P_MSC4_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x426E01B8UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x426E0380UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x426E0384UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x426E0388UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x426E038CUL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x426E0390UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x426E0394UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x426E0398UL))
#define bM0P_MSC4_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x426E039CUL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x426E03A0UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x426E03A4UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x426E03A8UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x426E03ACUL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x426E03B0UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x426E03B4UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x426E03B8UL))
#define bM0P_MSC4_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x426E03BCUL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x426E0400UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x426E0404UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x426E0408UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x426E040CUL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x426E0410UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x426E0414UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x426E0418UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x426E041CUL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x426E0420UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x426E0424UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x426E0428UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x426E042CUL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x426E0430UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x426E0434UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x426E0438UL))
#define bM0P_MSC4_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x426E043CUL))
#define bM0P_MSC4_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x426E0480UL))
#define bM0P_MSC4_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x426E0484UL))
#define bM0P_MSC4_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x426E0488UL))
#define bM0P_MSC4_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x426E048CUL))
#define bM0P_MSC4_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x426E0490UL))
#define bM0P_MSC4_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x426E0498UL))
#define bM0P_MSC4_SPI_EACR_TIE                          *((volatile unsigned int*)(0x426E049CUL))
#define bM0P_MSC4_SPI_EACR_TIF                          *((volatile unsigned int*)(0x426E04A0UL))
#define bM0P_MSC4_SPI_EACR_CSER                         *((volatile unsigned int*)(0x426E04ACUL))
#define bM0P_MSC4_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x426E04B0UL))
#define bM0P_MSC4_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x426E04B4UL))
#define bM0P_MSC4_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x426E0500UL))
#define bM0P_MSC4_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x426E0504UL))
#define bM0P_MSC4_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x426E0508UL))
#define bM0P_MSC4_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x426E050CUL))
#define bM0P_MSC4_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x426E0510UL))
#define bM0P_MSC4_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x426E0514UL))
#define bM0P_MSC4_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x426E0518UL))
#define bM0P_MSC4_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x426E051CUL))
#define bM0P_MSC4_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x426E0520UL))
#define bM0P_MSC4_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x426E0524UL))
#define bM0P_MSC4_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x426E0528UL))
#define bM0P_MSC4_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x426E052CUL))
#define bM0P_MSC4_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x426E0530UL))
#define bM0P_MSC4_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x426E0534UL))
#define bM0P_MSC4_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x426E0538UL))
#define bM0P_MSC4_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x426E053CUL))
#define bM0P_MSC4_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x426E0580UL))
#define bM0P_MSC4_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x426E0584UL))
#define bM0P_MSC4_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x426E0588UL))
#define bM0P_MSC4_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x426E058CUL))
#define bM0P_MSC4_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x426E0590UL))
#define bM0P_MSC4_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x426E0594UL))
#define bM0P_MSC4_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x426E0598UL))
#define bM0P_MSC4_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x426E059CUL))
#define bM0P_MSC4_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x426E05A0UL))
#define bM0P_MSC4_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x426E05A4UL))
#define bM0P_MSC4_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x426E05A8UL))
#define bM0P_MSC4_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x426E05ACUL))
#define bM0P_MSC4_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x426E05B0UL))
#define bM0P_MSC4_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x426E05B4UL))
#define bM0P_MSC4_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x426E05B8UL))
#define bM0P_MSC4_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x426E05BCUL))
#define bM0P_MSC4_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x426E0600UL))
#define bM0P_MSC4_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x426E0604UL))
#define bM0P_MSC4_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x426E0608UL))
#define bM0P_MSC4_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x426E060CUL))
#define bM0P_MSC4_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x426E0610UL))
#define bM0P_MSC4_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x426E0614UL))
#define bM0P_MSC4_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x426E0618UL))
#define bM0P_MSC4_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x426E061CUL))
#define bM0P_MSC4_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x426E0620UL))
#define bM0P_MSC4_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x426E0624UL))
#define bM0P_MSC4_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x426E0628UL))
#define bM0P_MSC4_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x426E062CUL))
#define bM0P_MSC4_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x426E0630UL))
#define bM0P_MSC4_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x426E0634UL))
#define bM0P_MSC4_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x426E0638UL))
#define bM0P_MSC4_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x426E063CUL))
#define bM0P_MSC4_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x426E0680UL))
#define bM0P_MSC4_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x426E0684UL))
#define bM0P_MSC4_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x426E0688UL))
#define bM0P_MSC4_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x426E068CUL))
#define bM0P_MSC4_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x426E0690UL))
#define bM0P_MSC4_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x426E0694UL))
#define bM0P_MSC4_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x426E0698UL))
#define bM0P_MSC4_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x426E069CUL))
#define bM0P_MSC4_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x426E06A0UL))
#define bM0P_MSC4_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x426E06A4UL))
#define bM0P_MSC4_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x426E06A8UL))
#define bM0P_MSC4_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x426E06ACUL))
#define bM0P_MSC4_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x426E06B0UL))
#define bM0P_MSC4_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x426E06B4UL))
#define bM0P_MSC4_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x426E06B8UL))
#define bM0P_MSC4_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x426E06BCUL))
#define bM0P_MSC4_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x426E0700UL))
#define bM0P_MSC4_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x426E0704UL))
#define bM0P_MSC4_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x426E0708UL))
#define bM0P_MSC4_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x426E070CUL))
#define bM0P_MSC4_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x426E0710UL))
#define bM0P_MSC4_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x426E0714UL))
#define bM0P_MSC4_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x426E0718UL))
#define bM0P_MSC4_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x426E071CUL))
#define bM0P_MSC5_SPI_MR_DOE                            *((volatile unsigned int*)(0x426E2000UL))
#define bM0P_MSC5_SPI_MR_CKE                            *((volatile unsigned int*)(0x426E2004UL))
#define bM0P_MSC5_SPI_MR_TDS                            *((volatile unsigned int*)(0x426E2008UL))
#define bM0P_MSC5_SPI_MR_CINV                           *((volatile unsigned int*)(0x426E200CUL))
#define bM0P_MSC5_SPI_MR_MODE0                          *((volatile unsigned int*)(0x426E2014UL))
#define bM0P_MSC5_SPI_MR_MODE1                          *((volatile unsigned int*)(0x426E2018UL))
#define bM0P_MSC5_SPI_MR_MODE2                          *((volatile unsigned int*)(0x426E201CUL))
#define bM0P_MSC5_SPI_CR_TXE                            *((volatile unsigned int*)(0x426E2020UL))
#define bM0P_MSC5_SPI_CR_RXE                            *((volatile unsigned int*)(0x426E2024UL))
#define bM0P_MSC5_SPI_CR_TBIE                           *((volatile unsigned int*)(0x426E2028UL))
#define bM0P_MSC5_SPI_CR_TXIE                           *((volatile unsigned int*)(0x426E202CUL))
#define bM0P_MSC5_SPI_CR_RXIE                           *((volatile unsigned int*)(0x426E2030UL))
#define bM0P_MSC5_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x426E2034UL))
#define bM0P_MSC5_SPI_CR_MSS                            *((volatile unsigned int*)(0x426E2038UL))
#define bM0P_MSC5_SPI_CR_PCL                            *((volatile unsigned int*)(0x426E203CUL))
#define bM0P_MSC5_SPI_ECR_DL0                           *((volatile unsigned int*)(0x426E2080UL))
#define bM0P_MSC5_SPI_ECR_DL1                           *((volatile unsigned int*)(0x426E2084UL))
#define bM0P_MSC5_SPI_ECR_DL2                           *((volatile unsigned int*)(0x426E2088UL))
#define bM0P_MSC5_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x426E208CUL))
#define bM0P_MSC5_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x426E2090UL))
#define bM0P_MSC5_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x426E2094UL))
#define bM0P_MSC5_SPI_ECR_DL3                           *((volatile unsigned int*)(0x426E2098UL))
#define bM0P_MSC5_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x426E209CUL))
#define bM0P_MSC5_SPI_SR_TBIF                           *((volatile unsigned int*)(0x426E20A0UL))
#define bM0P_MSC5_SPI_SR_TDEF                           *((volatile unsigned int*)(0x426E20A4UL))
#define bM0P_MSC5_SPI_SR_RDFF                           *((volatile unsigned int*)(0x426E20A8UL))
#define bM0P_MSC5_SPI_SR_ORF                            *((volatile unsigned int*)(0x426E20ACUL))
#define bM0P_MSC5_SPI_SR_RECLR                          *((volatile unsigned int*)(0x426E20BCUL))
#define bM0P_MSC5_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x426E2180UL))
#define bM0P_MSC5_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x426E2184UL))
#define bM0P_MSC5_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x426E2188UL))
#define bM0P_MSC5_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x426E218CUL))
#define bM0P_MSC5_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x426E2190UL))
#define bM0P_MSC5_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x426E2194UL))
#define bM0P_MSC5_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x426E2198UL))
#define bM0P_MSC5_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x426E219CUL))
#define bM0P_MSC5_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x426E21A0UL))
#define bM0P_MSC5_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x426E21A4UL))
#define bM0P_MSC5_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x426E21A8UL))
#define bM0P_MSC5_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x426E21ACUL))
#define bM0P_MSC5_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x426E21B0UL))
#define bM0P_MSC5_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x426E21B4UL))
#define bM0P_MSC5_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x426E21B8UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x426E2380UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x426E2384UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x426E2388UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x426E238CUL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x426E2390UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x426E2394UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x426E2398UL))
#define bM0P_MSC5_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x426E239CUL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x426E23A0UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x426E23A4UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x426E23A8UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x426E23ACUL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x426E23B0UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x426E23B4UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x426E23B8UL))
#define bM0P_MSC5_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x426E23BCUL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x426E2400UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x426E2404UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x426E2408UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x426E240CUL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x426E2410UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x426E2414UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x426E2418UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x426E241CUL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x426E2420UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x426E2424UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x426E2428UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x426E242CUL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x426E2430UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x426E2434UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x426E2438UL))
#define bM0P_MSC5_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x426E243CUL))
#define bM0P_MSC5_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x426E2480UL))
#define bM0P_MSC5_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x426E2484UL))
#define bM0P_MSC5_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x426E2488UL))
#define bM0P_MSC5_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x426E248CUL))
#define bM0P_MSC5_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x426E2490UL))
#define bM0P_MSC5_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x426E2498UL))
#define bM0P_MSC5_SPI_EACR_TIE                          *((volatile unsigned int*)(0x426E249CUL))
#define bM0P_MSC5_SPI_EACR_TIF                          *((volatile unsigned int*)(0x426E24A0UL))
#define bM0P_MSC5_SPI_EACR_CSER                         *((volatile unsigned int*)(0x426E24ACUL))
#define bM0P_MSC5_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x426E24B0UL))
#define bM0P_MSC5_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x426E24B4UL))
#define bM0P_MSC5_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x426E2500UL))
#define bM0P_MSC5_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x426E2504UL))
#define bM0P_MSC5_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x426E2508UL))
#define bM0P_MSC5_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x426E250CUL))
#define bM0P_MSC5_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x426E2510UL))
#define bM0P_MSC5_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x426E2514UL))
#define bM0P_MSC5_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x426E2518UL))
#define bM0P_MSC5_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x426E251CUL))
#define bM0P_MSC5_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x426E2520UL))
#define bM0P_MSC5_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x426E2524UL))
#define bM0P_MSC5_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x426E2528UL))
#define bM0P_MSC5_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x426E252CUL))
#define bM0P_MSC5_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x426E2530UL))
#define bM0P_MSC5_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x426E2534UL))
#define bM0P_MSC5_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x426E2538UL))
#define bM0P_MSC5_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x426E253CUL))
#define bM0P_MSC5_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x426E2580UL))
#define bM0P_MSC5_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x426E2584UL))
#define bM0P_MSC5_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x426E2588UL))
#define bM0P_MSC5_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x426E258CUL))
#define bM0P_MSC5_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x426E2590UL))
#define bM0P_MSC5_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x426E2594UL))
#define bM0P_MSC5_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x426E2598UL))
#define bM0P_MSC5_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x426E259CUL))
#define bM0P_MSC5_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x426E25A0UL))
#define bM0P_MSC5_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x426E25A4UL))
#define bM0P_MSC5_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x426E25A8UL))
#define bM0P_MSC5_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x426E25ACUL))
#define bM0P_MSC5_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x426E25B0UL))
#define bM0P_MSC5_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x426E25B4UL))
#define bM0P_MSC5_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x426E25B8UL))
#define bM0P_MSC5_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x426E25BCUL))
#define bM0P_MSC5_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x426E2600UL))
#define bM0P_MSC5_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x426E2604UL))
#define bM0P_MSC5_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x426E2608UL))
#define bM0P_MSC5_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x426E260CUL))
#define bM0P_MSC5_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x426E2610UL))
#define bM0P_MSC5_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x426E2614UL))
#define bM0P_MSC5_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x426E2618UL))
#define bM0P_MSC5_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x426E261CUL))
#define bM0P_MSC5_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x426E2620UL))
#define bM0P_MSC5_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x426E2624UL))
#define bM0P_MSC5_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x426E2628UL))
#define bM0P_MSC5_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x426E262CUL))
#define bM0P_MSC5_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x426E2630UL))
#define bM0P_MSC5_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x426E2634UL))
#define bM0P_MSC5_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x426E2638UL))
#define bM0P_MSC5_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x426E263CUL))
#define bM0P_MSC5_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x426E2680UL))
#define bM0P_MSC5_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x426E2684UL))
#define bM0P_MSC5_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x426E2688UL))
#define bM0P_MSC5_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x426E268CUL))
#define bM0P_MSC5_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x426E2690UL))
#define bM0P_MSC5_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x426E2694UL))
#define bM0P_MSC5_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x426E2698UL))
#define bM0P_MSC5_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x426E269CUL))
#define bM0P_MSC5_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x426E26A0UL))
#define bM0P_MSC5_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x426E26A4UL))
#define bM0P_MSC5_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x426E26A8UL))
#define bM0P_MSC5_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x426E26ACUL))
#define bM0P_MSC5_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x426E26B0UL))
#define bM0P_MSC5_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x426E26B4UL))
#define bM0P_MSC5_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x426E26B8UL))
#define bM0P_MSC5_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x426E26BCUL))
#define bM0P_MSC5_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x426E2700UL))
#define bM0P_MSC5_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x426E2704UL))
#define bM0P_MSC5_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x426E2708UL))
#define bM0P_MSC5_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x426E270CUL))
#define bM0P_MSC5_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x426E2710UL))
#define bM0P_MSC5_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x426E2714UL))
#define bM0P_MSC5_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x426E2718UL))
#define bM0P_MSC5_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x426E271CUL))
#define bM0P_MSC6_SPI_MR_DOE                            *((volatile unsigned int*)(0x426E4000UL))
#define bM0P_MSC6_SPI_MR_CKE                            *((volatile unsigned int*)(0x426E4004UL))
#define bM0P_MSC6_SPI_MR_TDS                            *((volatile unsigned int*)(0x426E4008UL))
#define bM0P_MSC6_SPI_MR_CINV                           *((volatile unsigned int*)(0x426E400CUL))
#define bM0P_MSC6_SPI_MR_MODE0                          *((volatile unsigned int*)(0x426E4014UL))
#define bM0P_MSC6_SPI_MR_MODE1                          *((volatile unsigned int*)(0x426E4018UL))
#define bM0P_MSC6_SPI_MR_MODE2                          *((volatile unsigned int*)(0x426E401CUL))
#define bM0P_MSC6_SPI_CR_TXE                            *((volatile unsigned int*)(0x426E4020UL))
#define bM0P_MSC6_SPI_CR_RXE                            *((volatile unsigned int*)(0x426E4024UL))
#define bM0P_MSC6_SPI_CR_TBIE                           *((volatile unsigned int*)(0x426E4028UL))
#define bM0P_MSC6_SPI_CR_TXIE                           *((volatile unsigned int*)(0x426E402CUL))
#define bM0P_MSC6_SPI_CR_RXIE                           *((volatile unsigned int*)(0x426E4030UL))
#define bM0P_MSC6_SPI_CR_SPIMODE                        *((volatile unsigned int*)(0x426E4034UL))
#define bM0P_MSC6_SPI_CR_MSS                            *((volatile unsigned int*)(0x426E4038UL))
#define bM0P_MSC6_SPI_CR_PCL                            *((volatile unsigned int*)(0x426E403CUL))
#define bM0P_MSC6_SPI_ECR_DL0                           *((volatile unsigned int*)(0x426E4080UL))
#define bM0P_MSC6_SPI_ECR_DL1                           *((volatile unsigned int*)(0x426E4084UL))
#define bM0P_MSC6_SPI_ECR_DL2                           *((volatile unsigned int*)(0x426E4088UL))
#define bM0P_MSC6_SPI_ECR_DTRWS0                        *((volatile unsigned int*)(0x426E408CUL))
#define bM0P_MSC6_SPI_ECR_DTRWS1                        *((volatile unsigned int*)(0x426E4090UL))
#define bM0P_MSC6_SPI_ECR_CSFE                          *((volatile unsigned int*)(0x426E4094UL))
#define bM0P_MSC6_SPI_ECR_DL3                           *((volatile unsigned int*)(0x426E4098UL))
#define bM0P_MSC6_SPI_ECR_SOPS                          *((volatile unsigned int*)(0x426E409CUL))
#define bM0P_MSC6_SPI_SR_TBIF                           *((volatile unsigned int*)(0x426E40A0UL))
#define bM0P_MSC6_SPI_SR_TDEF                           *((volatile unsigned int*)(0x426E40A4UL))
#define bM0P_MSC6_SPI_SR_RDFF                           *((volatile unsigned int*)(0x426E40A8UL))
#define bM0P_MSC6_SPI_SR_ORF                            *((volatile unsigned int*)(0x426E40ACUL))
#define bM0P_MSC6_SPI_SR_RECLR                          *((volatile unsigned int*)(0x426E40BCUL))
#define bM0P_MSC6_SPI_BRS_BRS0                          *((volatile unsigned int*)(0x426E4180UL))
#define bM0P_MSC6_SPI_BRS_BRS1                          *((volatile unsigned int*)(0x426E4184UL))
#define bM0P_MSC6_SPI_BRS_BRS2                          *((volatile unsigned int*)(0x426E4188UL))
#define bM0P_MSC6_SPI_BRS_BRS3                          *((volatile unsigned int*)(0x426E418CUL))
#define bM0P_MSC6_SPI_BRS_BRS4                          *((volatile unsigned int*)(0x426E4190UL))
#define bM0P_MSC6_SPI_BRS_BRS5                          *((volatile unsigned int*)(0x426E4194UL))
#define bM0P_MSC6_SPI_BRS_BRS6                          *((volatile unsigned int*)(0x426E4198UL))
#define bM0P_MSC6_SPI_BRS_BRS7                          *((volatile unsigned int*)(0x426E419CUL))
#define bM0P_MSC6_SPI_BRS_BRS8                          *((volatile unsigned int*)(0x426E41A0UL))
#define bM0P_MSC6_SPI_BRS_BRS9                          *((volatile unsigned int*)(0x426E41A4UL))
#define bM0P_MSC6_SPI_BRS_BRS10                         *((volatile unsigned int*)(0x426E41A8UL))
#define bM0P_MSC6_SPI_BRS_BRS11                         *((volatile unsigned int*)(0x426E41ACUL))
#define bM0P_MSC6_SPI_BRS_BRS12                         *((volatile unsigned int*)(0x426E41B0UL))
#define bM0P_MSC6_SPI_BRS_BRS13                         *((volatile unsigned int*)(0x426E41B4UL))
#define bM0P_MSC6_SPI_BRS_BRS14                         *((volatile unsigned int*)(0x426E41B8UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY0                    *((volatile unsigned int*)(0x426E4380UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY1                    *((volatile unsigned int*)(0x426E4384UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY2                    *((volatile unsigned int*)(0x426E4388UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY3                    *((volatile unsigned int*)(0x426E438CUL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY4                    *((volatile unsigned int*)(0x426E4390UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY5                    *((volatile unsigned int*)(0x426E4394UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY6                    *((volatile unsigned int*)(0x426E4398UL))
#define bM0P_MSC6_SPI_CSTMG0_CSHDLY7                    *((volatile unsigned int*)(0x426E439CUL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY0                    *((volatile unsigned int*)(0x426E43A0UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY1                    *((volatile unsigned int*)(0x426E43A4UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY2                    *((volatile unsigned int*)(0x426E43A8UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY3                    *((volatile unsigned int*)(0x426E43ACUL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY4                    *((volatile unsigned int*)(0x426E43B0UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY5                    *((volatile unsigned int*)(0x426E43B4UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY6                    *((volatile unsigned int*)(0x426E43B8UL))
#define bM0P_MSC6_SPI_CSTMG1_CSSDLY7                    *((volatile unsigned int*)(0x426E43BCUL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS0                     *((volatile unsigned int*)(0x426E4400UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS1                     *((volatile unsigned int*)(0x426E4404UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS2                     *((volatile unsigned int*)(0x426E4408UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS3                     *((volatile unsigned int*)(0x426E440CUL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS4                     *((volatile unsigned int*)(0x426E4410UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS5                     *((volatile unsigned int*)(0x426E4414UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS6                     *((volatile unsigned int*)(0x426E4418UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS7                     *((volatile unsigned int*)(0x426E441CUL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS8                     *((volatile unsigned int*)(0x426E4420UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS9                     *((volatile unsigned int*)(0x426E4424UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS10                    *((volatile unsigned int*)(0x426E4428UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS11                    *((volatile unsigned int*)(0x426E442CUL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS12                    *((volatile unsigned int*)(0x426E4430UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS13                    *((volatile unsigned int*)(0x426E4434UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS14                    *((volatile unsigned int*)(0x426E4438UL))
#define bM0P_MSC6_SPI_CSTMG32_CSDS15                    *((volatile unsigned int*)(0x426E443CUL))
#define bM0P_MSC6_SPI_EACR_TMRE                         *((volatile unsigned int*)(0x426E4480UL))
#define bM0P_MSC6_SPI_EACR_CLKDIV0                      *((volatile unsigned int*)(0x426E4484UL))
#define bM0P_MSC6_SPI_EACR_CLKDIV1                      *((volatile unsigned int*)(0x426E4488UL))
#define bM0P_MSC6_SPI_EACR_CLKDIV2                      *((volatile unsigned int*)(0x426E448CUL))
#define bM0P_MSC6_SPI_EACR_CLKDIV3                      *((volatile unsigned int*)(0x426E4490UL))
#define bM0P_MSC6_SPI_EACR_SYNTE                        *((volatile unsigned int*)(0x426E4498UL))
#define bM0P_MSC6_SPI_EACR_TIE                          *((volatile unsigned int*)(0x426E449CUL))
#define bM0P_MSC6_SPI_EACR_TIF                          *((volatile unsigned int*)(0x426E44A0UL))
#define bM0P_MSC6_SPI_EACR_CSER                         *((volatile unsigned int*)(0x426E44ACUL))
#define bM0P_MSC6_SPI_EACR_CSEIE                        *((volatile unsigned int*)(0x426E44B0UL))
#define bM0P_MSC6_SPI_EACR_TBEE                         *((volatile unsigned int*)(0x426E44B4UL))
#define bM0P_MSC6_SPI_TMR_TMR0                          *((volatile unsigned int*)(0x426E4500UL))
#define bM0P_MSC6_SPI_TMR_TMR1                          *((volatile unsigned int*)(0x426E4504UL))
#define bM0P_MSC6_SPI_TMR_TMR2                          *((volatile unsigned int*)(0x426E4508UL))
#define bM0P_MSC6_SPI_TMR_TMR3                          *((volatile unsigned int*)(0x426E450CUL))
#define bM0P_MSC6_SPI_TMR_TMR4                          *((volatile unsigned int*)(0x426E4510UL))
#define bM0P_MSC6_SPI_TMR_TMR5                          *((volatile unsigned int*)(0x426E4514UL))
#define bM0P_MSC6_SPI_TMR_TMR6                          *((volatile unsigned int*)(0x426E4518UL))
#define bM0P_MSC6_SPI_TMR_TMR7                          *((volatile unsigned int*)(0x426E451CUL))
#define bM0P_MSC6_SPI_TMR_TMR8                          *((volatile unsigned int*)(0x426E4520UL))
#define bM0P_MSC6_SPI_TMR_TMR9                          *((volatile unsigned int*)(0x426E4524UL))
#define bM0P_MSC6_SPI_TMR_TMR10                         *((volatile unsigned int*)(0x426E4528UL))
#define bM0P_MSC6_SPI_TMR_TMR11                         *((volatile unsigned int*)(0x426E452CUL))
#define bM0P_MSC6_SPI_TMR_TMR12                         *((volatile unsigned int*)(0x426E4530UL))
#define bM0P_MSC6_SPI_TMR_TMR13                         *((volatile unsigned int*)(0x426E4534UL))
#define bM0P_MSC6_SPI_TMR_TMR14                         *((volatile unsigned int*)(0x426E4538UL))
#define bM0P_MSC6_SPI_TMR_TMR15                         *((volatile unsigned int*)(0x426E453CUL))
#define bM0P_MSC6_SPI_TMC_TMC0                          *((volatile unsigned int*)(0x426E4580UL))
#define bM0P_MSC6_SPI_TMC_TMC1                          *((volatile unsigned int*)(0x426E4584UL))
#define bM0P_MSC6_SPI_TMC_TMC2                          *((volatile unsigned int*)(0x426E4588UL))
#define bM0P_MSC6_SPI_TMC_TMC3                          *((volatile unsigned int*)(0x426E458CUL))
#define bM0P_MSC6_SPI_TMC_TMC4                          *((volatile unsigned int*)(0x426E4590UL))
#define bM0P_MSC6_SPI_TMC_TMC5                          *((volatile unsigned int*)(0x426E4594UL))
#define bM0P_MSC6_SPI_TMC_TMC6                          *((volatile unsigned int*)(0x426E4598UL))
#define bM0P_MSC6_SPI_TMC_TMC7                          *((volatile unsigned int*)(0x426E459CUL))
#define bM0P_MSC6_SPI_TMC_TMC8                          *((volatile unsigned int*)(0x426E45A0UL))
#define bM0P_MSC6_SPI_TMC_TMC9                          *((volatile unsigned int*)(0x426E45A4UL))
#define bM0P_MSC6_SPI_TMC_TMC10                         *((volatile unsigned int*)(0x426E45A8UL))
#define bM0P_MSC6_SPI_TMC_TMC11                         *((volatile unsigned int*)(0x426E45ACUL))
#define bM0P_MSC6_SPI_TMC_TMC12                         *((volatile unsigned int*)(0x426E45B0UL))
#define bM0P_MSC6_SPI_TMC_TMC13                         *((volatile unsigned int*)(0x426E45B4UL))
#define bM0P_MSC6_SPI_TMC_TMC14                         *((volatile unsigned int*)(0x426E45B8UL))
#define bM0P_MSC6_SPI_TMC_TMC15                         *((volatile unsigned int*)(0x426E45BCUL))
#define bM0P_MSC6_SPI_CSCR_CSOE                         *((volatile unsigned int*)(0x426E4600UL))
#define bM0P_MSC6_SPI_CSCR_CSEN0                        *((volatile unsigned int*)(0x426E4604UL))
#define bM0P_MSC6_SPI_CSCR_CSEN1                        *((volatile unsigned int*)(0x426E4608UL))
#define bM0P_MSC6_SPI_CSCR_CSEN2                        *((volatile unsigned int*)(0x426E460CUL))
#define bM0P_MSC6_SPI_CSCR_CSEN3                        *((volatile unsigned int*)(0x426E4610UL))
#define bM0P_MSC6_SPI_CSCR_CSLVS                        *((volatile unsigned int*)(0x426E4614UL))
#define bM0P_MSC6_SPI_CSCR_CSTODIV0                     *((volatile unsigned int*)(0x426E4618UL))
#define bM0P_MSC6_SPI_CSCR_CSTODIV1                     *((volatile unsigned int*)(0x426E461CUL))
#define bM0P_MSC6_SPI_CSCR_CSTODIV2                     *((volatile unsigned int*)(0x426E4620UL))
#define bM0P_MSC6_SPI_CSCR_CSAH                         *((volatile unsigned int*)(0x426E4624UL))
#define bM0P_MSC6_SPI_CSCR_CSAD0                        *((volatile unsigned int*)(0x426E4628UL))
#define bM0P_MSC6_SPI_CSCR_CSAD1                        *((volatile unsigned int*)(0x426E462CUL))
#define bM0P_MSC6_SPI_CSCR_CSAE0                        *((volatile unsigned int*)(0x426E4630UL))
#define bM0P_MSC6_SPI_CSCR_CSAE1                        *((volatile unsigned int*)(0x426E4634UL))
#define bM0P_MSC6_SPI_CSCR_CSAS0                        *((volatile unsigned int*)(0x426E4638UL))
#define bM0P_MSC6_SPI_CSCR_CSAS1                        *((volatile unsigned int*)(0x426E463CUL))
#define bM0P_MSC6_SPI_CSFR0_CS1DL0                      *((volatile unsigned int*)(0x426E4680UL))
#define bM0P_MSC6_SPI_CSFR0_CS1DL1                      *((volatile unsigned int*)(0x426E4684UL))
#define bM0P_MSC6_SPI_CSFR0_CS1DL2                      *((volatile unsigned int*)(0x426E4688UL))
#define bM0P_MSC6_SPI_CSFR0_CS1DL3                      *((volatile unsigned int*)(0x426E468CUL))
#define bM0P_MSC6_SPI_CSFR0_CS1TDS                      *((volatile unsigned int*)(0x426E4690UL))
#define bM0P_MSC6_SPI_CSFR0_CS1SPI                      *((volatile unsigned int*)(0x426E4694UL))
#define bM0P_MSC6_SPI_CSFR0_CS1CINV                     *((volatile unsigned int*)(0x426E4698UL))
#define bM0P_MSC6_SPI_CSFR0_CS1CSLVS                    *((volatile unsigned int*)(0x426E469CUL))
#define bM0P_MSC6_SPI_CSFR1_CS2DL0                      *((volatile unsigned int*)(0x426E46A0UL))
#define bM0P_MSC6_SPI_CSFR1_CS2DL1                      *((volatile unsigned int*)(0x426E46A4UL))
#define bM0P_MSC6_SPI_CSFR1_CS2DL2                      *((volatile unsigned int*)(0x426E46A8UL))
#define bM0P_MSC6_SPI_CSFR1_CS2DL3                      *((volatile unsigned int*)(0x426E46ACUL))
#define bM0P_MSC6_SPI_CSFR1_CS2TDS                      *((volatile unsigned int*)(0x426E46B0UL))
#define bM0P_MSC6_SPI_CSFR1_CS2SPI                      *((volatile unsigned int*)(0x426E46B4UL))
#define bM0P_MSC6_SPI_CSFR1_CS2CINV                     *((volatile unsigned int*)(0x426E46B8UL))
#define bM0P_MSC6_SPI_CSFR1_CS2CSLVS                    *((volatile unsigned int*)(0x426E46BCUL))
#define bM0P_MSC6_SPI_CSFR2_CS3DL0                      *((volatile unsigned int*)(0x426E4700UL))
#define bM0P_MSC6_SPI_CSFR2_CS3DL1                      *((volatile unsigned int*)(0x426E4704UL))
#define bM0P_MSC6_SPI_CSFR2_CS3DL2                      *((volatile unsigned int*)(0x426E4708UL))
#define bM0P_MSC6_SPI_CSFR2_CS3DL3                      *((volatile unsigned int*)(0x426E470CUL))
#define bM0P_MSC6_SPI_CSFR2_CS3TDS                      *((volatile unsigned int*)(0x426E4710UL))
#define bM0P_MSC6_SPI_CSFR2_CS3SPI                      *((volatile unsigned int*)(0x426E4714UL))
#define bM0P_MSC6_SPI_CSFR2_CS3CINV                     *((volatile unsigned int*)(0x426E4718UL))
#define bM0P_MSC6_SPI_CSFR2_CS3CSLVS                    *((volatile unsigned int*)(0x426E471CUL))
#define bM0P_MSC0_UART_MR_DOE                           *((volatile unsigned int*)(0x42700000UL))
#define bM0P_MSC0_UART_MR_TDS                           *((volatile unsigned int*)(0x42700008UL))
#define bM0P_MSC0_UART_MR_SBLS                          *((volatile unsigned int*)(0x4270000CUL))
#define bM0P_MSC0_UART_MR_MODE0                         *((volatile unsigned int*)(0x42700014UL))
#define bM0P_MSC0_UART_MR_MODE1                         *((volatile unsigned int*)(0x42700018UL))
#define bM0P_MSC0_UART_MR_MODE2                         *((volatile unsigned int*)(0x4270001CUL))
#define bM0P_MSC0_UART_CR_TXE                           *((volatile unsigned int*)(0x42700020UL))
#define bM0P_MSC0_UART_CR_RXE                           *((volatile unsigned int*)(0x42700024UL))
#define bM0P_MSC0_UART_CR_TBIE                          *((volatile unsigned int*)(0x42700028UL))
#define bM0P_MSC0_UART_CR_TXIE                          *((volatile unsigned int*)(0x4270002CUL))
#define bM0P_MSC0_UART_CR_RXIE                          *((volatile unsigned int*)(0x42700030UL))
#define bM0P_MSC0_UART_CR_PCL                           *((volatile unsigned int*)(0x4270003CUL))
#define bM0P_MSC0_UART_ECR_DL0                          *((volatile unsigned int*)(0x42700080UL))
#define bM0P_MSC0_UART_ECR_DL1                          *((volatile unsigned int*)(0x42700084UL))
#define bM0P_MSC0_UART_ECR_DL2                          *((volatile unsigned int*)(0x42700088UL))
#define bM0P_MSC0_UART_ECR_PS                           *((volatile unsigned int*)(0x4270008CUL))
#define bM0P_MSC0_UART_ECR_PE                           *((volatile unsigned int*)(0x42700090UL))
#define bM0P_MSC0_UART_ECR_INV                          *((volatile unsigned int*)(0x42700094UL))
#define bM0P_MSC0_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x42700098UL))
#define bM0P_MSC0_UART_ECR_FCEB                         *((volatile unsigned int*)(0x4270009CUL))
#define bM0P_MSC0_UART_SR_TBIF                          *((volatile unsigned int*)(0x427000A0UL))
#define bM0P_MSC0_UART_SR_TDEF                          *((volatile unsigned int*)(0x427000A4UL))
#define bM0P_MSC0_UART_SR_RDFF                          *((volatile unsigned int*)(0x427000A8UL))
#define bM0P_MSC0_UART_SR_ORF                           *((volatile unsigned int*)(0x427000ACUL))
#define bM0P_MSC0_UART_SR_FEF                           *((volatile unsigned int*)(0x427000B0UL))
#define bM0P_MSC0_UART_SR_PEF                           *((volatile unsigned int*)(0x427000B4UL))
#define bM0P_MSC0_UART_SR_RECLR                         *((volatile unsigned int*)(0x427000BCUL))
#define bM0P_MSC0_UART_BRS_BRS0                         *((volatile unsigned int*)(0x42700180UL))
#define bM0P_MSC0_UART_BRS_BRS1                         *((volatile unsigned int*)(0x42700184UL))
#define bM0P_MSC0_UART_BRS_BRS2                         *((volatile unsigned int*)(0x42700188UL))
#define bM0P_MSC0_UART_BRS_BRS3                         *((volatile unsigned int*)(0x4270018CUL))
#define bM0P_MSC0_UART_BRS_BRS4                         *((volatile unsigned int*)(0x42700190UL))
#define bM0P_MSC0_UART_BRS_BRS5                         *((volatile unsigned int*)(0x42700194UL))
#define bM0P_MSC0_UART_BRS_BRS6                         *((volatile unsigned int*)(0x42700198UL))
#define bM0P_MSC0_UART_BRS_BRS7                         *((volatile unsigned int*)(0x4270019CUL))
#define bM0P_MSC0_UART_BRS_BRS8                         *((volatile unsigned int*)(0x427001A0UL))
#define bM0P_MSC0_UART_BRS_BRS9                         *((volatile unsigned int*)(0x427001A4UL))
#define bM0P_MSC0_UART_BRS_BRS10                        *((volatile unsigned int*)(0x427001A8UL))
#define bM0P_MSC0_UART_BRS_BRS11                        *((volatile unsigned int*)(0x427001ACUL))
#define bM0P_MSC0_UART_BRS_BRS12                        *((volatile unsigned int*)(0x427001B0UL))
#define bM0P_MSC0_UART_BRS_BRS13                        *((volatile unsigned int*)(0x427001B4UL))
#define bM0P_MSC0_UART_BRS_BRS14                        *((volatile unsigned int*)(0x427001B8UL))
#define bM0P_MSC0_UART_BRS_EXT                          *((volatile unsigned int*)(0x427001BCUL))
#define bM0P_MSC0_UART_COMP_COMP0                       *((volatile unsigned int*)(0x42700A00UL))
#define bM0P_MSC0_UART_COMP_COMP1                       *((volatile unsigned int*)(0x42700A04UL))
#define bM0P_MSC0_UART_COMP_COMP2                       *((volatile unsigned int*)(0x42700A08UL))
#define bM0P_MSC0_UART_COMP_COMP3                       *((volatile unsigned int*)(0x42700A0CUL))
#define bM0P_MSC0_UART_COMP_COMP4                       *((volatile unsigned int*)(0x42700A10UL))
#define bM0P_MSC0_UART_COMP_COMP5                       *((volatile unsigned int*)(0x42700A14UL))
#define bM0P_MSC0_UART_COMP_COMP6                       *((volatile unsigned int*)(0x42700A18UL))
#define bM0P_MSC0_UART_COMP_COMP7                       *((volatile unsigned int*)(0x42700A1CUL))
#define bM0P_MSC0_UART_COMP_COMP8                       *((volatile unsigned int*)(0x42700A20UL))
#define bM0P_MSC0_UART_COMP_COMP9                       *((volatile unsigned int*)(0x42700A24UL))
#define bM0P_MSC0_UART_COMP_CEN                         *((volatile unsigned int*)(0x42700A3CUL))
#define bM0P_MSC1_UART_MR_DOE                           *((volatile unsigned int*)(0x42702000UL))
#define bM0P_MSC1_UART_MR_TDS                           *((volatile unsigned int*)(0x42702008UL))
#define bM0P_MSC1_UART_MR_SBLS                          *((volatile unsigned int*)(0x4270200CUL))
#define bM0P_MSC1_UART_MR_MODE0                         *((volatile unsigned int*)(0x42702014UL))
#define bM0P_MSC1_UART_MR_MODE1                         *((volatile unsigned int*)(0x42702018UL))
#define bM0P_MSC1_UART_MR_MODE2                         *((volatile unsigned int*)(0x4270201CUL))
#define bM0P_MSC1_UART_CR_TXE                           *((volatile unsigned int*)(0x42702020UL))
#define bM0P_MSC1_UART_CR_RXE                           *((volatile unsigned int*)(0x42702024UL))
#define bM0P_MSC1_UART_CR_TBIE                          *((volatile unsigned int*)(0x42702028UL))
#define bM0P_MSC1_UART_CR_TXIE                          *((volatile unsigned int*)(0x4270202CUL))
#define bM0P_MSC1_UART_CR_RXIE                          *((volatile unsigned int*)(0x42702030UL))
#define bM0P_MSC1_UART_CR_PCL                           *((volatile unsigned int*)(0x4270203CUL))
#define bM0P_MSC1_UART_ECR_DL0                          *((volatile unsigned int*)(0x42702080UL))
#define bM0P_MSC1_UART_ECR_DL1                          *((volatile unsigned int*)(0x42702084UL))
#define bM0P_MSC1_UART_ECR_DL2                          *((volatile unsigned int*)(0x42702088UL))
#define bM0P_MSC1_UART_ECR_PS                           *((volatile unsigned int*)(0x4270208CUL))
#define bM0P_MSC1_UART_ECR_PE                           *((volatile unsigned int*)(0x42702090UL))
#define bM0P_MSC1_UART_ECR_INV                          *((volatile unsigned int*)(0x42702094UL))
#define bM0P_MSC1_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x42702098UL))
#define bM0P_MSC1_UART_ECR_FCEB                         *((volatile unsigned int*)(0x4270209CUL))
#define bM0P_MSC1_UART_SR_TBIF                          *((volatile unsigned int*)(0x427020A0UL))
#define bM0P_MSC1_UART_SR_TDEF                          *((volatile unsigned int*)(0x427020A4UL))
#define bM0P_MSC1_UART_SR_RDFF                          *((volatile unsigned int*)(0x427020A8UL))
#define bM0P_MSC1_UART_SR_ORF                           *((volatile unsigned int*)(0x427020ACUL))
#define bM0P_MSC1_UART_SR_FEF                           *((volatile unsigned int*)(0x427020B0UL))
#define bM0P_MSC1_UART_SR_PEF                           *((volatile unsigned int*)(0x427020B4UL))
#define bM0P_MSC1_UART_SR_RECLR                         *((volatile unsigned int*)(0x427020BCUL))
#define bM0P_MSC1_UART_BRS_BRS0                         *((volatile unsigned int*)(0x42702180UL))
#define bM0P_MSC1_UART_BRS_BRS1                         *((volatile unsigned int*)(0x42702184UL))
#define bM0P_MSC1_UART_BRS_BRS2                         *((volatile unsigned int*)(0x42702188UL))
#define bM0P_MSC1_UART_BRS_BRS3                         *((volatile unsigned int*)(0x4270218CUL))
#define bM0P_MSC1_UART_BRS_BRS4                         *((volatile unsigned int*)(0x42702190UL))
#define bM0P_MSC1_UART_BRS_BRS5                         *((volatile unsigned int*)(0x42702194UL))
#define bM0P_MSC1_UART_BRS_BRS6                         *((volatile unsigned int*)(0x42702198UL))
#define bM0P_MSC1_UART_BRS_BRS7                         *((volatile unsigned int*)(0x4270219CUL))
#define bM0P_MSC1_UART_BRS_BRS8                         *((volatile unsigned int*)(0x427021A0UL))
#define bM0P_MSC1_UART_BRS_BRS9                         *((volatile unsigned int*)(0x427021A4UL))
#define bM0P_MSC1_UART_BRS_BRS10                        *((volatile unsigned int*)(0x427021A8UL))
#define bM0P_MSC1_UART_BRS_BRS11                        *((volatile unsigned int*)(0x427021ACUL))
#define bM0P_MSC1_UART_BRS_BRS12                        *((volatile unsigned int*)(0x427021B0UL))
#define bM0P_MSC1_UART_BRS_BRS13                        *((volatile unsigned int*)(0x427021B4UL))
#define bM0P_MSC1_UART_BRS_BRS14                        *((volatile unsigned int*)(0x427021B8UL))
#define bM0P_MSC1_UART_BRS_EXT                          *((volatile unsigned int*)(0x427021BCUL))
#define bM0P_MSC1_UART_COMP_COMP0                       *((volatile unsigned int*)(0x42702A00UL))
#define bM0P_MSC1_UART_COMP_COMP1                       *((volatile unsigned int*)(0x42702A04UL))
#define bM0P_MSC1_UART_COMP_COMP2                       *((volatile unsigned int*)(0x42702A08UL))
#define bM0P_MSC1_UART_COMP_COMP3                       *((volatile unsigned int*)(0x42702A0CUL))
#define bM0P_MSC1_UART_COMP_COMP4                       *((volatile unsigned int*)(0x42702A10UL))
#define bM0P_MSC1_UART_COMP_COMP5                       *((volatile unsigned int*)(0x42702A14UL))
#define bM0P_MSC1_UART_COMP_COMP6                       *((volatile unsigned int*)(0x42702A18UL))
#define bM0P_MSC1_UART_COMP_COMP7                       *((volatile unsigned int*)(0x42702A1CUL))
#define bM0P_MSC1_UART_COMP_COMP8                       *((volatile unsigned int*)(0x42702A20UL))
#define bM0P_MSC1_UART_COMP_COMP9                       *((volatile unsigned int*)(0x42702A24UL))
#define bM0P_MSC1_UART_COMP_CEN                         *((volatile unsigned int*)(0x42702A3CUL))
#define bM0P_MSC2_UART_MR_DOE                           *((volatile unsigned int*)(0x42704000UL))
#define bM0P_MSC2_UART_MR_TDS                           *((volatile unsigned int*)(0x42704008UL))
#define bM0P_MSC2_UART_MR_SBLS                          *((volatile unsigned int*)(0x4270400CUL))
#define bM0P_MSC2_UART_MR_MODE0                         *((volatile unsigned int*)(0x42704014UL))
#define bM0P_MSC2_UART_MR_MODE1                         *((volatile unsigned int*)(0x42704018UL))
#define bM0P_MSC2_UART_MR_MODE2                         *((volatile unsigned int*)(0x4270401CUL))
#define bM0P_MSC2_UART_CR_TXE                           *((volatile unsigned int*)(0x42704020UL))
#define bM0P_MSC2_UART_CR_RXE                           *((volatile unsigned int*)(0x42704024UL))
#define bM0P_MSC2_UART_CR_TBIE                          *((volatile unsigned int*)(0x42704028UL))
#define bM0P_MSC2_UART_CR_TXIE                          *((volatile unsigned int*)(0x4270402CUL))
#define bM0P_MSC2_UART_CR_RXIE                          *((volatile unsigned int*)(0x42704030UL))
#define bM0P_MSC2_UART_CR_PCL                           *((volatile unsigned int*)(0x4270403CUL))
#define bM0P_MSC2_UART_ECR_DL0                          *((volatile unsigned int*)(0x42704080UL))
#define bM0P_MSC2_UART_ECR_DL1                          *((volatile unsigned int*)(0x42704084UL))
#define bM0P_MSC2_UART_ECR_DL2                          *((volatile unsigned int*)(0x42704088UL))
#define bM0P_MSC2_UART_ECR_PS                           *((volatile unsigned int*)(0x4270408CUL))
#define bM0P_MSC2_UART_ECR_PE                           *((volatile unsigned int*)(0x42704090UL))
#define bM0P_MSC2_UART_ECR_INV                          *((volatile unsigned int*)(0x42704094UL))
#define bM0P_MSC2_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x42704098UL))
#define bM0P_MSC2_UART_ECR_FCEB                         *((volatile unsigned int*)(0x4270409CUL))
#define bM0P_MSC2_UART_SR_TBIF                          *((volatile unsigned int*)(0x427040A0UL))
#define bM0P_MSC2_UART_SR_TDEF                          *((volatile unsigned int*)(0x427040A4UL))
#define bM0P_MSC2_UART_SR_RDFF                          *((volatile unsigned int*)(0x427040A8UL))
#define bM0P_MSC2_UART_SR_ORF                           *((volatile unsigned int*)(0x427040ACUL))
#define bM0P_MSC2_UART_SR_FEF                           *((volatile unsigned int*)(0x427040B0UL))
#define bM0P_MSC2_UART_SR_PEF                           *((volatile unsigned int*)(0x427040B4UL))
#define bM0P_MSC2_UART_SR_RECLR                         *((volatile unsigned int*)(0x427040BCUL))
#define bM0P_MSC2_UART_BRS_BRS0                         *((volatile unsigned int*)(0x42704180UL))
#define bM0P_MSC2_UART_BRS_BRS1                         *((volatile unsigned int*)(0x42704184UL))
#define bM0P_MSC2_UART_BRS_BRS2                         *((volatile unsigned int*)(0x42704188UL))
#define bM0P_MSC2_UART_BRS_BRS3                         *((volatile unsigned int*)(0x4270418CUL))
#define bM0P_MSC2_UART_BRS_BRS4                         *((volatile unsigned int*)(0x42704190UL))
#define bM0P_MSC2_UART_BRS_BRS5                         *((volatile unsigned int*)(0x42704194UL))
#define bM0P_MSC2_UART_BRS_BRS6                         *((volatile unsigned int*)(0x42704198UL))
#define bM0P_MSC2_UART_BRS_BRS7                         *((volatile unsigned int*)(0x4270419CUL))
#define bM0P_MSC2_UART_BRS_BRS8                         *((volatile unsigned int*)(0x427041A0UL))
#define bM0P_MSC2_UART_BRS_BRS9                         *((volatile unsigned int*)(0x427041A4UL))
#define bM0P_MSC2_UART_BRS_BRS10                        *((volatile unsigned int*)(0x427041A8UL))
#define bM0P_MSC2_UART_BRS_BRS11                        *((volatile unsigned int*)(0x427041ACUL))
#define bM0P_MSC2_UART_BRS_BRS12                        *((volatile unsigned int*)(0x427041B0UL))
#define bM0P_MSC2_UART_BRS_BRS13                        *((volatile unsigned int*)(0x427041B4UL))
#define bM0P_MSC2_UART_BRS_BRS14                        *((volatile unsigned int*)(0x427041B8UL))
#define bM0P_MSC2_UART_BRS_EXT                          *((volatile unsigned int*)(0x427041BCUL))
#define bM0P_MSC2_UART_COMP_COMP0                       *((volatile unsigned int*)(0x42704A00UL))
#define bM0P_MSC2_UART_COMP_COMP1                       *((volatile unsigned int*)(0x42704A04UL))
#define bM0P_MSC2_UART_COMP_COMP2                       *((volatile unsigned int*)(0x42704A08UL))
#define bM0P_MSC2_UART_COMP_COMP3                       *((volatile unsigned int*)(0x42704A0CUL))
#define bM0P_MSC2_UART_COMP_COMP4                       *((volatile unsigned int*)(0x42704A10UL))
#define bM0P_MSC2_UART_COMP_COMP5                       *((volatile unsigned int*)(0x42704A14UL))
#define bM0P_MSC2_UART_COMP_COMP6                       *((volatile unsigned int*)(0x42704A18UL))
#define bM0P_MSC2_UART_COMP_COMP7                       *((volatile unsigned int*)(0x42704A1CUL))
#define bM0P_MSC2_UART_COMP_COMP8                       *((volatile unsigned int*)(0x42704A20UL))
#define bM0P_MSC2_UART_COMP_COMP9                       *((volatile unsigned int*)(0x42704A24UL))
#define bM0P_MSC2_UART_COMP_CEN                         *((volatile unsigned int*)(0x42704A3CUL))
#define bM0P_MSC4_UART_MR_DOE                           *((volatile unsigned int*)(0x426E0000UL))
#define bM0P_MSC4_UART_MR_TDS                           *((volatile unsigned int*)(0x426E0008UL))
#define bM0P_MSC4_UART_MR_SBLS                          *((volatile unsigned int*)(0x426E000CUL))
#define bM0P_MSC4_UART_MR_MODE0                         *((volatile unsigned int*)(0x426E0014UL))
#define bM0P_MSC4_UART_MR_MODE1                         *((volatile unsigned int*)(0x426E0018UL))
#define bM0P_MSC4_UART_MR_MODE2                         *((volatile unsigned int*)(0x426E001CUL))
#define bM0P_MSC4_UART_CR_TXE                           *((volatile unsigned int*)(0x426E0020UL))
#define bM0P_MSC4_UART_CR_RXE                           *((volatile unsigned int*)(0x426E0024UL))
#define bM0P_MSC4_UART_CR_TBIE                          *((volatile unsigned int*)(0x426E0028UL))
#define bM0P_MSC4_UART_CR_TXIE                          *((volatile unsigned int*)(0x426E002CUL))
#define bM0P_MSC4_UART_CR_RXIE                          *((volatile unsigned int*)(0x426E0030UL))
#define bM0P_MSC4_UART_CR_PCL                           *((volatile unsigned int*)(0x426E003CUL))
#define bM0P_MSC4_UART_ECR_DL0                          *((volatile unsigned int*)(0x426E0080UL))
#define bM0P_MSC4_UART_ECR_DL1                          *((volatile unsigned int*)(0x426E0084UL))
#define bM0P_MSC4_UART_ECR_DL2                          *((volatile unsigned int*)(0x426E0088UL))
#define bM0P_MSC4_UART_ECR_PS                           *((volatile unsigned int*)(0x426E008CUL))
#define bM0P_MSC4_UART_ECR_PE                           *((volatile unsigned int*)(0x426E0090UL))
#define bM0P_MSC4_UART_ECR_INV                          *((volatile unsigned int*)(0x426E0094UL))
#define bM0P_MSC4_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x426E0098UL))
#define bM0P_MSC4_UART_ECR_FCEB                         *((volatile unsigned int*)(0x426E009CUL))
#define bM0P_MSC4_UART_SR_TBIF                          *((volatile unsigned int*)(0x426E00A0UL))
#define bM0P_MSC4_UART_SR_TDEF                          *((volatile unsigned int*)(0x426E00A4UL))
#define bM0P_MSC4_UART_SR_RDFF                          *((volatile unsigned int*)(0x426E00A8UL))
#define bM0P_MSC4_UART_SR_ORF                           *((volatile unsigned int*)(0x426E00ACUL))
#define bM0P_MSC4_UART_SR_FEF                           *((volatile unsigned int*)(0x426E00B0UL))
#define bM0P_MSC4_UART_SR_PEF                           *((volatile unsigned int*)(0x426E00B4UL))
#define bM0P_MSC4_UART_SR_RECLR                         *((volatile unsigned int*)(0x426E00BCUL))
#define bM0P_MSC4_UART_BRS_BRS0                         *((volatile unsigned int*)(0x426E0180UL))
#define bM0P_MSC4_UART_BRS_BRS1                         *((volatile unsigned int*)(0x426E0184UL))
#define bM0P_MSC4_UART_BRS_BRS2                         *((volatile unsigned int*)(0x426E0188UL))
#define bM0P_MSC4_UART_BRS_BRS3                         *((volatile unsigned int*)(0x426E018CUL))
#define bM0P_MSC4_UART_BRS_BRS4                         *((volatile unsigned int*)(0x426E0190UL))
#define bM0P_MSC4_UART_BRS_BRS5                         *((volatile unsigned int*)(0x426E0194UL))
#define bM0P_MSC4_UART_BRS_BRS6                         *((volatile unsigned int*)(0x426E0198UL))
#define bM0P_MSC4_UART_BRS_BRS7                         *((volatile unsigned int*)(0x426E019CUL))
#define bM0P_MSC4_UART_BRS_BRS8                         *((volatile unsigned int*)(0x426E01A0UL))
#define bM0P_MSC4_UART_BRS_BRS9                         *((volatile unsigned int*)(0x426E01A4UL))
#define bM0P_MSC4_UART_BRS_BRS10                        *((volatile unsigned int*)(0x426E01A8UL))
#define bM0P_MSC4_UART_BRS_BRS11                        *((volatile unsigned int*)(0x426E01ACUL))
#define bM0P_MSC4_UART_BRS_BRS12                        *((volatile unsigned int*)(0x426E01B0UL))
#define bM0P_MSC4_UART_BRS_BRS13                        *((volatile unsigned int*)(0x426E01B4UL))
#define bM0P_MSC4_UART_BRS_BRS14                        *((volatile unsigned int*)(0x426E01B8UL))
#define bM0P_MSC4_UART_BRS_EXT                          *((volatile unsigned int*)(0x426E01BCUL))
#define bM0P_MSC4_UART_COMP_COMP0                       *((volatile unsigned int*)(0x426E0A00UL))
#define bM0P_MSC4_UART_COMP_COMP1                       *((volatile unsigned int*)(0x426E0A04UL))
#define bM0P_MSC4_UART_COMP_COMP2                       *((volatile unsigned int*)(0x426E0A08UL))
#define bM0P_MSC4_UART_COMP_COMP3                       *((volatile unsigned int*)(0x426E0A0CUL))
#define bM0P_MSC4_UART_COMP_COMP4                       *((volatile unsigned int*)(0x426E0A10UL))
#define bM0P_MSC4_UART_COMP_COMP5                       *((volatile unsigned int*)(0x426E0A14UL))
#define bM0P_MSC4_UART_COMP_COMP6                       *((volatile unsigned int*)(0x426E0A18UL))
#define bM0P_MSC4_UART_COMP_COMP7                       *((volatile unsigned int*)(0x426E0A1CUL))
#define bM0P_MSC4_UART_COMP_COMP8                       *((volatile unsigned int*)(0x426E0A20UL))
#define bM0P_MSC4_UART_COMP_COMP9                       *((volatile unsigned int*)(0x426E0A24UL))
#define bM0P_MSC4_UART_COMP_CEN                         *((volatile unsigned int*)(0x426E0A3CUL))
#define bM0P_MSC5_UART_MR_DOE                           *((volatile unsigned int*)(0x426E2000UL))
#define bM0P_MSC5_UART_MR_TDS                           *((volatile unsigned int*)(0x426E2008UL))
#define bM0P_MSC5_UART_MR_SBLS                          *((volatile unsigned int*)(0x426E200CUL))
#define bM0P_MSC5_UART_MR_MODE0                         *((volatile unsigned int*)(0x426E2014UL))
#define bM0P_MSC5_UART_MR_MODE1                         *((volatile unsigned int*)(0x426E2018UL))
#define bM0P_MSC5_UART_MR_MODE2                         *((volatile unsigned int*)(0x426E201CUL))
#define bM0P_MSC5_UART_CR_TXE                           *((volatile unsigned int*)(0x426E2020UL))
#define bM0P_MSC5_UART_CR_RXE                           *((volatile unsigned int*)(0x426E2024UL))
#define bM0P_MSC5_UART_CR_TBIE                          *((volatile unsigned int*)(0x426E2028UL))
#define bM0P_MSC5_UART_CR_TXIE                          *((volatile unsigned int*)(0x426E202CUL))
#define bM0P_MSC5_UART_CR_RXIE                          *((volatile unsigned int*)(0x426E2030UL))
#define bM0P_MSC5_UART_CR_PCL                           *((volatile unsigned int*)(0x426E203CUL))
#define bM0P_MSC5_UART_ECR_DL0                          *((volatile unsigned int*)(0x426E2080UL))
#define bM0P_MSC5_UART_ECR_DL1                          *((volatile unsigned int*)(0x426E2084UL))
#define bM0P_MSC5_UART_ECR_DL2                          *((volatile unsigned int*)(0x426E2088UL))
#define bM0P_MSC5_UART_ECR_PS                           *((volatile unsigned int*)(0x426E208CUL))
#define bM0P_MSC5_UART_ECR_PE                           *((volatile unsigned int*)(0x426E2090UL))
#define bM0P_MSC5_UART_ECR_INV                          *((volatile unsigned int*)(0x426E2094UL))
#define bM0P_MSC5_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x426E2098UL))
#define bM0P_MSC5_UART_ECR_FCEB                         *((volatile unsigned int*)(0x426E209CUL))
#define bM0P_MSC5_UART_SR_TBIF                          *((volatile unsigned int*)(0x426E20A0UL))
#define bM0P_MSC5_UART_SR_TDEF                          *((volatile unsigned int*)(0x426E20A4UL))
#define bM0P_MSC5_UART_SR_RDFF                          *((volatile unsigned int*)(0x426E20A8UL))
#define bM0P_MSC5_UART_SR_ORF                           *((volatile unsigned int*)(0x426E20ACUL))
#define bM0P_MSC5_UART_SR_FEF                           *((volatile unsigned int*)(0x426E20B0UL))
#define bM0P_MSC5_UART_SR_PEF                           *((volatile unsigned int*)(0x426E20B4UL))
#define bM0P_MSC5_UART_SR_RECLR                         *((volatile unsigned int*)(0x426E20BCUL))
#define bM0P_MSC5_UART_BRS_BRS0                         *((volatile unsigned int*)(0x426E2180UL))
#define bM0P_MSC5_UART_BRS_BRS1                         *((volatile unsigned int*)(0x426E2184UL))
#define bM0P_MSC5_UART_BRS_BRS2                         *((volatile unsigned int*)(0x426E2188UL))
#define bM0P_MSC5_UART_BRS_BRS3                         *((volatile unsigned int*)(0x426E218CUL))
#define bM0P_MSC5_UART_BRS_BRS4                         *((volatile unsigned int*)(0x426E2190UL))
#define bM0P_MSC5_UART_BRS_BRS5                         *((volatile unsigned int*)(0x426E2194UL))
#define bM0P_MSC5_UART_BRS_BRS6                         *((volatile unsigned int*)(0x426E2198UL))
#define bM0P_MSC5_UART_BRS_BRS7                         *((volatile unsigned int*)(0x426E219CUL))
#define bM0P_MSC5_UART_BRS_BRS8                         *((volatile unsigned int*)(0x426E21A0UL))
#define bM0P_MSC5_UART_BRS_BRS9                         *((volatile unsigned int*)(0x426E21A4UL))
#define bM0P_MSC5_UART_BRS_BRS10                        *((volatile unsigned int*)(0x426E21A8UL))
#define bM0P_MSC5_UART_BRS_BRS11                        *((volatile unsigned int*)(0x426E21ACUL))
#define bM0P_MSC5_UART_BRS_BRS12                        *((volatile unsigned int*)(0x426E21B0UL))
#define bM0P_MSC5_UART_BRS_BRS13                        *((volatile unsigned int*)(0x426E21B4UL))
#define bM0P_MSC5_UART_BRS_BRS14                        *((volatile unsigned int*)(0x426E21B8UL))
#define bM0P_MSC5_UART_BRS_EXT                          *((volatile unsigned int*)(0x426E21BCUL))
#define bM0P_MSC5_UART_COMP_COMP0                       *((volatile unsigned int*)(0x426E2A00UL))
#define bM0P_MSC5_UART_COMP_COMP1                       *((volatile unsigned int*)(0x426E2A04UL))
#define bM0P_MSC5_UART_COMP_COMP2                       *((volatile unsigned int*)(0x426E2A08UL))
#define bM0P_MSC5_UART_COMP_COMP3                       *((volatile unsigned int*)(0x426E2A0CUL))
#define bM0P_MSC5_UART_COMP_COMP4                       *((volatile unsigned int*)(0x426E2A10UL))
#define bM0P_MSC5_UART_COMP_COMP5                       *((volatile unsigned int*)(0x426E2A14UL))
#define bM0P_MSC5_UART_COMP_COMP6                       *((volatile unsigned int*)(0x426E2A18UL))
#define bM0P_MSC5_UART_COMP_COMP7                       *((volatile unsigned int*)(0x426E2A1CUL))
#define bM0P_MSC5_UART_COMP_COMP8                       *((volatile unsigned int*)(0x426E2A20UL))
#define bM0P_MSC5_UART_COMP_COMP9                       *((volatile unsigned int*)(0x426E2A24UL))
#define bM0P_MSC5_UART_COMP_CEN                         *((volatile unsigned int*)(0x426E2A3CUL))
#define bM0P_MSC6_UART_MR_DOE                           *((volatile unsigned int*)(0x426E4000UL))
#define bM0P_MSC6_UART_MR_TDS                           *((volatile unsigned int*)(0x426E4008UL))
#define bM0P_MSC6_UART_MR_SBLS                          *((volatile unsigned int*)(0x426E400CUL))
#define bM0P_MSC6_UART_MR_MODE0                         *((volatile unsigned int*)(0x426E4014UL))
#define bM0P_MSC6_UART_MR_MODE1                         *((volatile unsigned int*)(0x426E4018UL))
#define bM0P_MSC6_UART_MR_MODE2                         *((volatile unsigned int*)(0x426E401CUL))
#define bM0P_MSC6_UART_CR_TXE                           *((volatile unsigned int*)(0x426E4020UL))
#define bM0P_MSC6_UART_CR_RXE                           *((volatile unsigned int*)(0x426E4024UL))
#define bM0P_MSC6_UART_CR_TBIE                          *((volatile unsigned int*)(0x426E4028UL))
#define bM0P_MSC6_UART_CR_TXIE                          *((volatile unsigned int*)(0x426E402CUL))
#define bM0P_MSC6_UART_CR_RXIE                          *((volatile unsigned int*)(0x426E4030UL))
#define bM0P_MSC6_UART_CR_PCL                           *((volatile unsigned int*)(0x426E403CUL))
#define bM0P_MSC6_UART_ECR_DL0                          *((volatile unsigned int*)(0x426E4080UL))
#define bM0P_MSC6_UART_ECR_DL1                          *((volatile unsigned int*)(0x426E4084UL))
#define bM0P_MSC6_UART_ECR_DL2                          *((volatile unsigned int*)(0x426E4088UL))
#define bM0P_MSC6_UART_ECR_PS                           *((volatile unsigned int*)(0x426E408CUL))
#define bM0P_MSC6_UART_ECR_PE                           *((volatile unsigned int*)(0x426E4090UL))
#define bM0P_MSC6_UART_ECR_INV                          *((volatile unsigned int*)(0x426E4094UL))
#define bM0P_MSC6_UART_ECR_ESBLS                        *((volatile unsigned int*)(0x426E4098UL))
#define bM0P_MSC6_UART_ECR_FCEB                         *((volatile unsigned int*)(0x426E409CUL))
#define bM0P_MSC6_UART_SR_TBIF                          *((volatile unsigned int*)(0x426E40A0UL))
#define bM0P_MSC6_UART_SR_TDEF                          *((volatile unsigned int*)(0x426E40A4UL))
#define bM0P_MSC6_UART_SR_RDFF                          *((volatile unsigned int*)(0x426E40A8UL))
#define bM0P_MSC6_UART_SR_ORF                           *((volatile unsigned int*)(0x426E40ACUL))
#define bM0P_MSC6_UART_SR_FEF                           *((volatile unsigned int*)(0x426E40B0UL))
#define bM0P_MSC6_UART_SR_PEF                           *((volatile unsigned int*)(0x426E40B4UL))
#define bM0P_MSC6_UART_SR_RECLR                         *((volatile unsigned int*)(0x426E40BCUL))
#define bM0P_MSC6_UART_BRS_BRS0                         *((volatile unsigned int*)(0x426E4180UL))
#define bM0P_MSC6_UART_BRS_BRS1                         *((volatile unsigned int*)(0x426E4184UL))
#define bM0P_MSC6_UART_BRS_BRS2                         *((volatile unsigned int*)(0x426E4188UL))
#define bM0P_MSC6_UART_BRS_BRS3                         *((volatile unsigned int*)(0x426E418CUL))
#define bM0P_MSC6_UART_BRS_BRS4                         *((volatile unsigned int*)(0x426E4190UL))
#define bM0P_MSC6_UART_BRS_BRS5                         *((volatile unsigned int*)(0x426E4194UL))
#define bM0P_MSC6_UART_BRS_BRS6                         *((volatile unsigned int*)(0x426E4198UL))
#define bM0P_MSC6_UART_BRS_BRS7                         *((volatile unsigned int*)(0x426E419CUL))
#define bM0P_MSC6_UART_BRS_BRS8                         *((volatile unsigned int*)(0x426E41A0UL))
#define bM0P_MSC6_UART_BRS_BRS9                         *((volatile unsigned int*)(0x426E41A4UL))
#define bM0P_MSC6_UART_BRS_BRS10                        *((volatile unsigned int*)(0x426E41A8UL))
#define bM0P_MSC6_UART_BRS_BRS11                        *((volatile unsigned int*)(0x426E41ACUL))
#define bM0P_MSC6_UART_BRS_BRS12                        *((volatile unsigned int*)(0x426E41B0UL))
#define bM0P_MSC6_UART_BRS_BRS13                        *((volatile unsigned int*)(0x426E41B4UL))
#define bM0P_MSC6_UART_BRS_BRS14                        *((volatile unsigned int*)(0x426E41B8UL))
#define bM0P_MSC6_UART_BRS_EXT                          *((volatile unsigned int*)(0x426E41BCUL))
#define bM0P_MSC6_UART_COMP_COMP0                       *((volatile unsigned int*)(0x426E4A00UL))
#define bM0P_MSC6_UART_COMP_COMP1                       *((volatile unsigned int*)(0x426E4A04UL))
#define bM0P_MSC6_UART_COMP_COMP2                       *((volatile unsigned int*)(0x426E4A08UL))
#define bM0P_MSC6_UART_COMP_COMP3                       *((volatile unsigned int*)(0x426E4A0CUL))
#define bM0P_MSC6_UART_COMP_COMP4                       *((volatile unsigned int*)(0x426E4A10UL))
#define bM0P_MSC6_UART_COMP_COMP5                       *((volatile unsigned int*)(0x426E4A14UL))
#define bM0P_MSC6_UART_COMP_COMP6                       *((volatile unsigned int*)(0x426E4A18UL))
#define bM0P_MSC6_UART_COMP_COMP7                       *((volatile unsigned int*)(0x426E4A1CUL))
#define bM0P_MSC6_UART_COMP_COMP8                       *((volatile unsigned int*)(0x426E4A20UL))
#define bM0P_MSC6_UART_COMP_COMP9                       *((volatile unsigned int*)(0x426E4A24UL))
#define bM0P_MSC6_UART_COMP_CEN                         *((volatile unsigned int*)(0x426E4A3CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY0                    *((volatile unsigned int*)(0x425C0000UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY1                    *((volatile unsigned int*)(0x425C0004UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY2                    *((volatile unsigned int*)(0x425C0008UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY3                    *((volatile unsigned int*)(0x425C000CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY4                    *((volatile unsigned int*)(0x425C0010UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY5                    *((volatile unsigned int*)(0x425C0014UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY6                    *((volatile unsigned int*)(0x425C0018UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY7                    *((volatile unsigned int*)(0x425C001CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY8                    *((volatile unsigned int*)(0x425C0020UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY9                    *((volatile unsigned int*)(0x425C0024UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY10                   *((volatile unsigned int*)(0x425C0028UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY11                   *((volatile unsigned int*)(0x425C002CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY12                   *((volatile unsigned int*)(0x425C0030UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY13                   *((volatile unsigned int*)(0x425C0034UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY14                   *((volatile unsigned int*)(0x425C0038UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY15                   *((volatile unsigned int*)(0x425C003CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY16                   *((volatile unsigned int*)(0x425C0040UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY17                   *((volatile unsigned int*)(0x425C0044UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY18                   *((volatile unsigned int*)(0x425C0048UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY19                   *((volatile unsigned int*)(0x425C004CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY20                   *((volatile unsigned int*)(0x425C0050UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY21                   *((volatile unsigned int*)(0x425C0054UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY22                   *((volatile unsigned int*)(0x425C0058UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY23                   *((volatile unsigned int*)(0x425C005CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY24                   *((volatile unsigned int*)(0x425C0060UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY25                   *((volatile unsigned int*)(0x425C0064UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY26                   *((volatile unsigned int*)(0x425C0068UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY27                   *((volatile unsigned int*)(0x425C006CUL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY28                   *((volatile unsigned int*)(0x425C0070UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY29                   *((volatile unsigned int*)(0x425C0074UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY30                   *((volatile unsigned int*)(0x425C0078UL))
#define bM0P_OSC_HICR_TRMKEY_TRMKEY31                   *((volatile unsigned int*)(0x425C007CUL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM0                    *((volatile unsigned int*)(0x425C0080UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM1                    *((volatile unsigned int*)(0x425C0084UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM2                    *((volatile unsigned int*)(0x425C0088UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM3                    *((volatile unsigned int*)(0x425C008CUL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM4                    *((volatile unsigned int*)(0x425C0090UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM5                    *((volatile unsigned int*)(0x425C0094UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM6                    *((volatile unsigned int*)(0x425C0098UL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM7                    *((volatile unsigned int*)(0x425C009CUL))
#define bM0P_OSC_HICR_FTRM_CR4MFTRM8                    *((volatile unsigned int*)(0x425C00A0UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM0                   *((volatile unsigned int*)(0x425C00C0UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM1                   *((volatile unsigned int*)(0x425C00C4UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM2                   *((volatile unsigned int*)(0x425C00C8UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM3                   *((volatile unsigned int*)(0x425C00CCUL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM4                   *((volatile unsigned int*)(0x425C00D0UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM5                   *((volatile unsigned int*)(0x425C00D4UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM6                   *((volatile unsigned int*)(0x425C00D8UL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM7                   *((volatile unsigned int*)(0x425C00DCUL))
#define bM0P_OSC_HICR_FTRM_CR16MFTRM8                   *((volatile unsigned int*)(0x425C00E0UL))
#define bM0P_OSC_HICR_TTRM_CR4MTTRM0                    *((volatile unsigned int*)(0x425C0100UL))
#define bM0P_OSC_HICR_TTRM_CR4MTTRM1                    *((volatile unsigned int*)(0x425C0104UL))
#define bM0P_OSC_HICR_TTRM_CR4MTTRM2                    *((volatile unsigned int*)(0x425C0108UL))
#define bM0P_OSC_HICR_TTRM_CR4MTTRM3                    *((volatile unsigned int*)(0x425C010CUL))
#define bM0P_OSC_HICR_TTRM_CR16MTTRM0                   *((volatile unsigned int*)(0x425C0140UL))
#define bM0P_OSC_HICR_TTRM_CR16MTTRM1                   *((volatile unsigned int*)(0x425C0144UL))
#define bM0P_OSC_HICR_TTRM_CR16MTTRM2                   *((volatile unsigned int*)(0x425C0148UL))
#define bM0P_OSC_HICR_TTRM_CR16MTTRM3                   *((volatile unsigned int*)(0x425C014CUL))
#define bM0P_OSC_HICR_FMC_FMC0                          *((volatile unsigned int*)(0x425C0180UL))
#define bM0P_OSC_HICR_FMC_FMC1                          *((volatile unsigned int*)(0x425C0184UL))
#define bM0P_OSC_HICR_CSR_CSR0                          *((volatile unsigned int*)(0x425C0200UL))
#define bM0P_OSC_HICR_CSR_CSR1                          *((volatile unsigned int*)(0x425C0204UL))
#define bM0P_OSC_HICR_CSR_CSR2                          *((volatile unsigned int*)(0x425C0208UL))
#define bM0P_OSC_HSXT_PWRCTL_HXSEL0                     *((volatile unsigned int*)(0x425C0400UL))
#define bM0P_OSC_HSXT_PWRCTL_HXSEL1                     *((volatile unsigned int*)(0x425C0404UL))
#define bM0P_OSC_HSXT_PWRCTL_HIBS0                      *((volatile unsigned int*)(0x425C0440UL))
#define bM0P_OSC_HSXT_PWRCTL_HIBS1                      *((volatile unsigned int*)(0x425C0444UL))
#define bM0P_OSC_LSXT_PWRCTL_LCSEL0                     *((volatile unsigned int*)(0x425C0600UL))
#define bM0P_OSC_LSXT_PWRCTL_LCSEL1                     *((volatile unsigned int*)(0x425C0604UL))
#define bM0P_OSC_LSXT_PWRCTL_LIBS0                      *((volatile unsigned int*)(0x425C0640UL))
#define bM0P_OSC_LSXT_PWRCTL_LIBS1                      *((volatile unsigned int*)(0x425C0644UL))
#define bM0P_PARITY_CTL_PE                              *((volatile unsigned int*)(0x42780000UL))
#define bM0P_PARITY_CTL_PIE                             *((volatile unsigned int*)(0x42780004UL))
#define bM0P_PARITY_CTL_PERROR                          *((volatile unsigned int*)(0x42780010UL))
#define bM0P_PARITY_ADDR_ADDR0                          *((volatile unsigned int*)(0x42780080UL))
#define bM0P_PARITY_ADDR_ADDR1                          *((volatile unsigned int*)(0x42780084UL))
#define bM0P_PARITY_ADDR_ADDR2                          *((volatile unsigned int*)(0x42780088UL))
#define bM0P_PARITY_ADDR_ADDR3                          *((volatile unsigned int*)(0x4278008CUL))
#define bM0P_PARITY_ADDR_ADDR4                          *((volatile unsigned int*)(0x42780090UL))
#define bM0P_PARITY_ADDR_ADDR5                          *((volatile unsigned int*)(0x42780094UL))
#define bM0P_PARITY_ADDR_ADDR6                          *((volatile unsigned int*)(0x42780098UL))
#define bM0P_PARITY_ADDR_ADDR7                          *((volatile unsigned int*)(0x4278009CUL))
#define bM0P_PARITY_ADDR_ADDR8                          *((volatile unsigned int*)(0x427800A0UL))
#define bM0P_PARITY_ADDR_ADDR9                          *((volatile unsigned int*)(0x427800A4UL))
#define bM0P_PARITY_ADDR_ADDR10                         *((volatile unsigned int*)(0x427800A8UL))
#define bM0P_PARITY_ADDR_ADDR11                         *((volatile unsigned int*)(0x427800ACUL))
#define bM0P_PARITY_ADDR_ADDR12                         *((volatile unsigned int*)(0x427800B0UL))
#define bM0P_PARITY_ADDR_ADDR13                         *((volatile unsigned int*)(0x427800B4UL))
#define bM0P_PARITY_ADDR_ADDR14                         *((volatile unsigned int*)(0x427800B8UL))
#define bM0P_PARITY_ADDR_ADDR15                         *((volatile unsigned int*)(0x427800BCUL))
#define bM0P_PARITY_ADDR_ADDR16                         *((volatile unsigned int*)(0x427800C0UL))
#define bM0P_PARITY_ADDR_ADDR17                         *((volatile unsigned int*)(0x427800C4UL))
#define bM0P_PARITY_ADDR_ADDR18                         *((volatile unsigned int*)(0x427800C8UL))
#define bM0P_PARITY_ADDR_ADDR19                         *((volatile unsigned int*)(0x427800CCUL))
#define bM0P_PARITY_ADDR_ADDR20                         *((volatile unsigned int*)(0x427800D0UL))
#define bM0P_PARITY_ADDR_ADDR21                         *((volatile unsigned int*)(0x427800D4UL))
#define bM0P_PARITY_ADDR_ADDR22                         *((volatile unsigned int*)(0x427800D8UL))
#define bM0P_PARITY_ADDR_ADDR23                         *((volatile unsigned int*)(0x427800DCUL))
#define bM0P_PARITY_ADDR_ADDR24                         *((volatile unsigned int*)(0x427800E0UL))
#define bM0P_PARITY_ADDR_ADDR25                         *((volatile unsigned int*)(0x427800E4UL))
#define bM0P_PARITY_ADDR_ADDR26                         *((volatile unsigned int*)(0x427800E8UL))
#define bM0P_PARITY_ADDR_ADDR27                         *((volatile unsigned int*)(0x427800ECUL))
#define bM0P_PARITY_ADDR_ADDR28                         *((volatile unsigned int*)(0x427800F0UL))
#define bM0P_PARITY_ADDR_ADDR29                         *((volatile unsigned int*)(0x427800F4UL))
#define bM0P_PARITY_ADDR_ADDR30                         *((volatile unsigned int*)(0x427800F8UL))
#define bM0P_PARITY_ADDR_ADDR31                         *((volatile unsigned int*)(0x427800FCUL))
#define bM0P_PCG_CLKEN0_MSCCLK0                         *((volatile unsigned int*)(0x42782000UL))
#define bM0P_PCG_CLKEN0_MSCCLK1                         *((volatile unsigned int*)(0x42782004UL))
#define bM0P_PCG_CLKEN0_MSCCLK2                         *((volatile unsigned int*)(0x42782008UL))
#define bM0P_PCG_CLKEN0_MSCCLK4                         *((volatile unsigned int*)(0x4278200CUL))
#define bM0P_PCG_CLKEN0_MSCCLK5                         *((volatile unsigned int*)(0x42782010UL))
#define bM0P_PCG_CLKEN0_MSCCLK6                         *((volatile unsigned int*)(0x42782014UL))
#define bM0P_PCG_CLKEN0_ADCCLK                          *((volatile unsigned int*)(0x42782040UL))
#define bM0P_PCG_CLKEN0_GIOCLK                          *((volatile unsigned int*)(0x42782070UL))
#define bM0P_PCG_RSTCTL0_MSCRST0                        *((volatile unsigned int*)(0x42782080UL))
#define bM0P_PCG_RSTCTL0_MSCRST1                        *((volatile unsigned int*)(0x42782084UL))
#define bM0P_PCG_RSTCTL0_MSCRST2                        *((volatile unsigned int*)(0x42782088UL))
#define bM0P_PCG_RSTCTL0_MSCRST4                        *((volatile unsigned int*)(0x4278208CUL))
#define bM0P_PCG_RSTCTL0_MSCRST5                        *((volatile unsigned int*)(0x42782090UL))
#define bM0P_PCG_RSTCTL0_MSCRST6                        *((volatile unsigned int*)(0x42782094UL))
#define bM0P_PCG_RSTCTL0_ADCRST                         *((volatile unsigned int*)(0x427820C0UL))
#define bM0P_PCG_CLKEN1_CTMCLK0123                      *((volatile unsigned int*)(0x42782200UL))
#define bM0P_PCG_CLKEN1_CTMCLK4567                      *((volatile unsigned int*)(0x42782204UL))
#define bM0P_PCG_CLKEN1_VCCLK                           *((volatile unsigned int*)(0x42782210UL))
#define bM0P_PCG_RSTCTL1_CTMRST0123                     *((volatile unsigned int*)(0x42782280UL))
#define bM0P_PCG_RSTCTL1_CTMRST4567                     *((volatile unsigned int*)(0x42782284UL))
#define bM0P_PCG_RSTCTL1_VCRST                          *((volatile unsigned int*)(0x42782290UL))
#define bM0P_PCG_CLKEN2_BUZCLK                          *((volatile unsigned int*)(0x42782410UL))
#define bM0P_PCG_CLKEN2_AESCLK                          *((volatile unsigned int*)(0x42782420UL))
#define bM0P_PCG_CLKEN2_SCICLK                          *((volatile unsigned int*)(0x42782430UL))
#define bM0P_PCG_CLKEN2_LCDCCLK                         *((volatile unsigned int*)(0x42782440UL))
#define bM0P_PCG_RSTCTL2_BUZRST                         *((volatile unsigned int*)(0x42782490UL))
#define bM0P_PCG_RSTCTL2_AESRST                         *((volatile unsigned int*)(0x427824A0UL))
#define bM0P_PCG_RSTCTL2_SCIRST                         *((volatile unsigned int*)(0x427824B0UL))
#define bM0P_PCG_RSTCTL2_LCDCRST                        *((volatile unsigned int*)(0x427824C0UL))
#define bM0P_RTC_RTCCTL1_ST                             *((volatile unsigned int*)(0x42760000UL))
#define bM0P_RTC_RTCCTL1_STAT                           *((volatile unsigned int*)(0x42760008UL))
#define bM0P_RTC_RTCCTL1_SWRST                          *((volatile unsigned int*)(0x4276000CUL))
#define bM0P_RTC_RTCCTL1_SENSP                          *((volatile unsigned int*)(0x42760010UL))
#define bM0P_RTC_RTCCTL1_SENRST                         *((volatile unsigned int*)(0x42760014UL))
#define bM0P_RTC_RTCCTL1_BUSY                           *((volatile unsigned int*)(0x42760018UL))
#define bM0P_RTC_RTCCTL1_SENE                           *((volatile unsigned int*)(0x42760020UL))
#define bM0P_RTC_RTCCTL1_MINE                           *((volatile unsigned int*)(0x42760024UL))
#define bM0P_RTC_RTCCTL1_HOUE                           *((volatile unsigned int*)(0x42760028UL))
#define bM0P_RTC_RTCCTL1_DAYE                           *((volatile unsigned int*)(0x4276002CUL))
#define bM0P_RTC_RTCCTL1_MONE                           *((volatile unsigned int*)(0x42760030UL))
#define bM0P_RTC_RTCCTL1_YEAE                           *((volatile unsigned int*)(0x42760034UL))
#define bM0P_RTC_RTCCTL1_INTSSF                         *((volatile unsigned int*)(0x42760040UL))
#define bM0P_RTC_RTCCTL1_INTSF                          *((volatile unsigned int*)(0x42760044UL))
#define bM0P_RTC_RTCCTL1_INTMF                          *((volatile unsigned int*)(0x42760048UL))
#define bM0P_RTC_RTCCTL1_INTHF                          *((volatile unsigned int*)(0x4276004CUL))
#define bM0P_RTC_RTCCTL1_INTTMF                         *((volatile unsigned int*)(0x42760050UL))
#define bM0P_RTC_RTCCTL1_INTALF                         *((volatile unsigned int*)(0x42760054UL))
#define bM0P_RTC_RTCCTL1_INTERF                         *((volatile unsigned int*)(0x42760058UL))
#define bM0P_RTC_RTCCTL1_INTCRF                         *((volatile unsigned int*)(0x4276005CUL))
#define bM0P_RTC_RTCCTL1_INTSSIEN                       *((volatile unsigned int*)(0x42760060UL))
#define bM0P_RTC_RTCCTL1_INTSIEN                        *((volatile unsigned int*)(0x42760064UL))
#define bM0P_RTC_RTCCTL1_INTMIEN                        *((volatile unsigned int*)(0x42760068UL))
#define bM0P_RTC_RTCCTL1_INTHIEN                        *((volatile unsigned int*)(0x4276006CUL))
#define bM0P_RTC_RTCCTL1_INTTMIEN                       *((volatile unsigned int*)(0x42760070UL))
#define bM0P_RTC_RTCCTL1_INTALIEN                       *((volatile unsigned int*)(0x42760074UL))
#define bM0P_RTC_RTCCTL1_INTERIEN                       *((volatile unsigned int*)(0x42760078UL))
#define bM0P_RTC_RTCCTL1_INTCRIEN                       *((volatile unsigned int*)(0x4276007CUL))
#define bM0P_RTC_RTCCTL2_RCTRL                          *((volatile unsigned int*)(0x42760080UL))
#define bM0P_RTC_RTCCTL2_TCST                           *((volatile unsigned int*)(0x427600A0UL))
#define bM0P_RTC_RTCCTL2_TCEN                           *((volatile unsigned int*)(0x427600A4UL))
#define bM0P_RTC_RTCCTL2_TCRUN                          *((volatile unsigned int*)(0x427600A8UL))
#define bM0P_RTC_CCS_CC0                                *((volatile unsigned int*)(0x42760100UL))
#define bM0P_RTC_CCS_CC1                                *((volatile unsigned int*)(0x42760104UL))
#define bM0P_RTC_CCS_CC2                                *((volatile unsigned int*)(0x42760108UL))
#define bM0P_RTC_CCS_CC3                                *((volatile unsigned int*)(0x4276010CUL))
#define bM0P_RTC_CCS_CC4                                *((volatile unsigned int*)(0x42760110UL))
#define bM0P_RTC_CCS_CC5                                *((volatile unsigned int*)(0x42760114UL))
#define bM0P_RTC_CCS_CC6                                *((volatile unsigned int*)(0x42760118UL))
#define bM0P_RTC_CCS_CC7                                *((volatile unsigned int*)(0x4276011CUL))
#define bM0P_RTC_CCS_CC8                                *((volatile unsigned int*)(0x42760120UL))
#define bM0P_RTC_CCS_CC9                                *((volatile unsigned int*)(0x42760124UL))
#define bM0P_RTC_CCS_CC10                               *((volatile unsigned int*)(0x42760128UL))
#define bM0P_RTC_CCS_CC11                               *((volatile unsigned int*)(0x4276012CUL))
#define bM0P_RTC_CCS_CC12                               *((volatile unsigned int*)(0x42760130UL))
#define bM0P_RTC_CCS_CC13                               *((volatile unsigned int*)(0x42760134UL))
#define bM0P_RTC_CCS_CC14                               *((volatile unsigned int*)(0x42760138UL))
#define bM0P_RTC_CCS_CC15                               *((volatile unsigned int*)(0x4276013CUL))
#define bM0P_RTC_CCS_CC16                               *((volatile unsigned int*)(0x42760140UL))
#define bM0P_RTC_CCS_CC17                               *((volatile unsigned int*)(0x42760144UL))
#define bM0P_RTC_CCS_CC18                               *((volatile unsigned int*)(0x42760148UL))
#define bM0P_RTC_CCS_CC19                               *((volatile unsigned int*)(0x4276014CUL))
#define bM0P_RTC_CCS_CC20                               *((volatile unsigned int*)(0x42760150UL))
#define bM0P_RTC_CCS_CC21                               *((volatile unsigned int*)(0x42760154UL))
#define bM0P_RTC_CCS_CC22                               *((volatile unsigned int*)(0x42760158UL))
#define bM0P_RTC_CCS_CC23                               *((volatile unsigned int*)(0x4276015CUL))
#define bM0P_RTC_SEN_LS0                                *((volatile unsigned int*)(0x42760180UL))
#define bM0P_RTC_SEN_LS1                                *((volatile unsigned int*)(0x42760184UL))
#define bM0P_RTC_SEN_LS2                                *((volatile unsigned int*)(0x42760188UL))
#define bM0P_RTC_SEN_LS3                                *((volatile unsigned int*)(0x4276018CUL))
#define bM0P_RTC_SEN_HS0                                *((volatile unsigned int*)(0x42760190UL))
#define bM0P_RTC_SEN_HS1                                *((volatile unsigned int*)(0x42760194UL))
#define bM0P_RTC_SEN_HS2                                *((volatile unsigned int*)(0x42760198UL))
#define bM0P_RTC_MIN_LM0                                *((volatile unsigned int*)(0x427601A0UL))
#define bM0P_RTC_MIN_LM1                                *((volatile unsigned int*)(0x427601A4UL))
#define bM0P_RTC_MIN_LM2                                *((volatile unsigned int*)(0x427601A8UL))
#define bM0P_RTC_MIN_LM3                                *((volatile unsigned int*)(0x427601ACUL))
#define bM0P_RTC_MIN_HM0                                *((volatile unsigned int*)(0x427601B0UL))
#define bM0P_RTC_MIN_HM1                                *((volatile unsigned int*)(0x427601B4UL))
#define bM0P_RTC_MIN_HM2                                *((volatile unsigned int*)(0x427601B8UL))
#define bM0P_RTC_HOUR_LH0                               *((volatile unsigned int*)(0x427601C0UL))
#define bM0P_RTC_HOUR_LH1                               *((volatile unsigned int*)(0x427601C4UL))
#define bM0P_RTC_HOUR_LH2                               *((volatile unsigned int*)(0x427601C8UL))
#define bM0P_RTC_HOUR_LH3                               *((volatile unsigned int*)(0x427601CCUL))
#define bM0P_RTC_HOUR_HH0                               *((volatile unsigned int*)(0x427601D0UL))
#define bM0P_RTC_HOUR_HH1                               *((volatile unsigned int*)(0x427601D4UL))
#define bM0P_RTC_DATE_LD0                               *((volatile unsigned int*)(0x427601E0UL))
#define bM0P_RTC_DATE_LD1                               *((volatile unsigned int*)(0x427601E4UL))
#define bM0P_RTC_DATE_LD2                               *((volatile unsigned int*)(0x427601E8UL))
#define bM0P_RTC_DATE_LD3                               *((volatile unsigned int*)(0x427601ECUL))
#define bM0P_RTC_DATE_HD0                               *((volatile unsigned int*)(0x427601F0UL))
#define bM0P_RTC_DATE_HD1                               *((volatile unsigned int*)(0x427601F4UL))
#define bM0P_RTC_WEEK_WK0                               *((volatile unsigned int*)(0x42760200UL))
#define bM0P_RTC_WEEK_WK1                               *((volatile unsigned int*)(0x42760204UL))
#define bM0P_RTC_WEEK_WK2                               *((volatile unsigned int*)(0x42760208UL))
#define bM0P_RTC_MON_LMON0                              *((volatile unsigned int*)(0x42760220UL))
#define bM0P_RTC_MON_LMON1                              *((volatile unsigned int*)(0x42760224UL))
#define bM0P_RTC_MON_LMON2                              *((volatile unsigned int*)(0x42760228UL))
#define bM0P_RTC_MON_LMON3                              *((volatile unsigned int*)(0x4276022CUL))
#define bM0P_RTC_MON_HMON                               *((volatile unsigned int*)(0x42760230UL))
#define bM0P_RTC_YEAR_LY0                               *((volatile unsigned int*)(0x42760240UL))
#define bM0P_RTC_YEAR_LY1                               *((volatile unsigned int*)(0x42760244UL))
#define bM0P_RTC_YEAR_LY2                               *((volatile unsigned int*)(0x42760248UL))
#define bM0P_RTC_YEAR_LY3                               *((volatile unsigned int*)(0x4276024CUL))
#define bM0P_RTC_YEAR_HY0                               *((volatile unsigned int*)(0x42760250UL))
#define bM0P_RTC_YEAR_HY1                               *((volatile unsigned int*)(0x42760254UL))
#define bM0P_RTC_YEAR_HY2                               *((volatile unsigned int*)(0x42760258UL))
#define bM0P_RTC_YEAR_HY3                               *((volatile unsigned int*)(0x4276025CUL))
#define bM0P_RTC_ASEN_LS0                               *((volatile unsigned int*)(0x42760280UL))
#define bM0P_RTC_ASEN_LS1                               *((volatile unsigned int*)(0x42760284UL))
#define bM0P_RTC_ASEN_LS2                               *((volatile unsigned int*)(0x42760288UL))
#define bM0P_RTC_ASEN_LS3                               *((volatile unsigned int*)(0x4276028CUL))
#define bM0P_RTC_ASEN_HS0                               *((volatile unsigned int*)(0x42760290UL))
#define bM0P_RTC_ASEN_HS1                               *((volatile unsigned int*)(0x42760294UL))
#define bM0P_RTC_ASEN_HS2                               *((volatile unsigned int*)(0x42760298UL))
#define bM0P_RTC_AMIN_LM0                               *((volatile unsigned int*)(0x427602A0UL))
#define bM0P_RTC_AMIN_LM1                               *((volatile unsigned int*)(0x427602A4UL))
#define bM0P_RTC_AMIN_LM2                               *((volatile unsigned int*)(0x427602A8UL))
#define bM0P_RTC_AMIN_LM3                               *((volatile unsigned int*)(0x427602ACUL))
#define bM0P_RTC_AMIN_HM0                               *((volatile unsigned int*)(0x427602B0UL))
#define bM0P_RTC_AMIN_HM1                               *((volatile unsigned int*)(0x427602B4UL))
#define bM0P_RTC_AMIN_HM2                               *((volatile unsigned int*)(0x427602B8UL))
#define bM0P_RTC_AHOUR_LH0                              *((volatile unsigned int*)(0x427602C0UL))
#define bM0P_RTC_AHOUR_LH1                              *((volatile unsigned int*)(0x427602C4UL))
#define bM0P_RTC_AHOUR_LH2                              *((volatile unsigned int*)(0x427602C8UL))
#define bM0P_RTC_AHOUR_LH3                              *((volatile unsigned int*)(0x427602CCUL))
#define bM0P_RTC_AHOUR_HH0                              *((volatile unsigned int*)(0x427602D0UL))
#define bM0P_RTC_AHOUR_HH1                              *((volatile unsigned int*)(0x427602D4UL))
#define bM0P_RTC_ADATE_LD0                              *((volatile unsigned int*)(0x427602E0UL))
#define bM0P_RTC_ADATE_LD1                              *((volatile unsigned int*)(0x427602E4UL))
#define bM0P_RTC_ADATE_LD2                              *((volatile unsigned int*)(0x427602E8UL))
#define bM0P_RTC_ADATE_LD3                              *((volatile unsigned int*)(0x427602ECUL))
#define bM0P_RTC_ADATE_HD0                              *((volatile unsigned int*)(0x427602F0UL))
#define bM0P_RTC_ADATE_HD1                              *((volatile unsigned int*)(0x427602F4UL))
#define bM0P_RTC_AMON_LMON0                             *((volatile unsigned int*)(0x42760320UL))
#define bM0P_RTC_AMON_LMON1                             *((volatile unsigned int*)(0x42760324UL))
#define bM0P_RTC_AMON_LMON2                             *((volatile unsigned int*)(0x42760328UL))
#define bM0P_RTC_AMON_LMON3                             *((volatile unsigned int*)(0x4276032CUL))
#define bM0P_RTC_AMON_HMON                              *((volatile unsigned int*)(0x42760330UL))
#define bM0P_RTC_AYEAR_LY0                              *((volatile unsigned int*)(0x42760340UL))
#define bM0P_RTC_AYEAR_LY1                              *((volatile unsigned int*)(0x42760344UL))
#define bM0P_RTC_AYEAR_LY2                              *((volatile unsigned int*)(0x42760348UL))
#define bM0P_RTC_AYEAR_LY3                              *((volatile unsigned int*)(0x4276034CUL))
#define bM0P_RTC_AYEAR_HY0                              *((volatile unsigned int*)(0x42760350UL))
#define bM0P_RTC_AYEAR_HY1                              *((volatile unsigned int*)(0x42760354UL))
#define bM0P_RTC_AYEAR_HY2                              *((volatile unsigned int*)(0x42760358UL))
#define bM0P_RTC_AYEAR_HY3                              *((volatile unsigned int*)(0x4276035CUL))
#define bM0P_RTC_TVAL_VAL0                              *((volatile unsigned int*)(0x42760380UL))
#define bM0P_RTC_TVAL_VAL1                              *((volatile unsigned int*)(0x42760384UL))
#define bM0P_RTC_TVAL_VAL2                              *((volatile unsigned int*)(0x42760388UL))
#define bM0P_RTC_TVAL_VAL3                              *((volatile unsigned int*)(0x4276038CUL))
#define bM0P_RTC_TVAL_VAL4                              *((volatile unsigned int*)(0x42760390UL))
#define bM0P_RTC_TVAL_VAL5                              *((volatile unsigned int*)(0x42760394UL))
#define bM0P_RTC_TVAL_VAL6                              *((volatile unsigned int*)(0x42760398UL))
#define bM0P_RTC_TVAL_VAL7                              *((volatile unsigned int*)(0x4276039CUL))
#define bM0P_RTC_TVAL_VAL8                              *((volatile unsigned int*)(0x427603A0UL))
#define bM0P_RTC_TVAL_VAL9                              *((volatile unsigned int*)(0x427603A4UL))
#define bM0P_RTC_TVAL_VAL10                             *((volatile unsigned int*)(0x427603A8UL))
#define bM0P_RTC_TVAL_VAL11                             *((volatile unsigned int*)(0x427603ACUL))
#define bM0P_RTC_TVAL_VAL12                             *((volatile unsigned int*)(0x427603B0UL))
#define bM0P_RTC_TVAL_VAL13                             *((volatile unsigned int*)(0x427603B4UL))
#define bM0P_RTC_TVAL_VAL14                             *((volatile unsigned int*)(0x427603B8UL))
#define bM0P_RTC_TVAL_VAL15                             *((volatile unsigned int*)(0x427603BCUL))
#define bM0P_RTC_TVAL_VAL16                             *((volatile unsigned int*)(0x427603C0UL))
#define bM0P_RTC_TVAL_VAL17                             *((volatile unsigned int*)(0x427603C4UL))
#define bM0P_RTC_SCLKI_SCLKI                            *((volatile unsigned int*)(0x42760400UL))
#define bM0P_RTC_SCLKS_SCLKS0                           *((volatile unsigned int*)(0x42760420UL))
#define bM0P_RTC_SCLKS_SCLKS1                           *((volatile unsigned int*)(0x42760424UL))
#define bM0P_RTC_CALVAL_CALVAL0                         *((volatile unsigned int*)(0x42760480UL))
#define bM0P_RTC_CALVAL_CALVAL1                         *((volatile unsigned int*)(0x42760484UL))
#define bM0P_RTC_CALVAL_CALVAL2                         *((volatile unsigned int*)(0x42760488UL))
#define bM0P_RTC_CALVAL_CALVAL3                         *((volatile unsigned int*)(0x4276048CUL))
#define bM0P_RTC_CALVAL_CALVAL4                         *((volatile unsigned int*)(0x42760490UL))
#define bM0P_RTC_CALVAL_CALVAL5                         *((volatile unsigned int*)(0x42760494UL))
#define bM0P_RTC_CALVAL_CALVAL6                         *((volatile unsigned int*)(0x42760498UL))
#define bM0P_RTC_CALVAL_CALVAL7                         *((volatile unsigned int*)(0x4276049CUL))
#define bM0P_RTC_CALVAL_CALVAL8                         *((volatile unsigned int*)(0x427604A0UL))
#define bM0P_RTC_CALVAL_CALVAL9                         *((volatile unsigned int*)(0x427604A4UL))
#define bM0P_RTC_CALEN_CALEN                            *((volatile unsigned int*)(0x427604C0UL))
#define bM0P_RTC_CLKDIVX_DIVX0                          *((volatile unsigned int*)(0x42760500UL))
#define bM0P_RTC_CLKDIVX_DIVX1                          *((volatile unsigned int*)(0x42760504UL))
#define bM0P_RTC_CLKDIVX_DIVX2                          *((volatile unsigned int*)(0x42760508UL))
#define bM0P_RTC_CLKDIVX_DIVX3                          *((volatile unsigned int*)(0x4276050CUL))
#define bM0P_RTC_CLKDIVC_DIVEN                          *((volatile unsigned int*)(0x42760520UL))
#define bM0P_RTC_CLKDIVC_DIVRDY                         *((volatile unsigned int*)(0x42760524UL))
#define bM0P_RTC_CALCYC_CALCYC0                         *((volatile unsigned int*)(0x42760580UL))
#define bM0P_RTC_CALCYC_CALCYC1                         *((volatile unsigned int*)(0x42760584UL))
#define bM0P_RTC_CALCYC_CALCYC2                         *((volatile unsigned int*)(0x42760588UL))
#define bM0P_RTC_CALCYC_CALCYC3                         *((volatile unsigned int*)(0x4276058CUL))
#define bM0P_RTC_CALCYC_CALCYC4                         *((volatile unsigned int*)(0x42760590UL))
#define bM0P_RTC_CALCYC_CALCYC5                         *((volatile unsigned int*)(0x42760594UL))
#define bM0P_RTC_CALCYC_CALCYC6                         *((volatile unsigned int*)(0x42760598UL))
#define bM0P_RTC_CALCYC_CALCYC7                         *((volatile unsigned int*)(0x4276059CUL))
#define bM0P_RTC_CALCYC_CALCYC8                         *((volatile unsigned int*)(0x427605A0UL))
#define bM0P_RTC_RTCODIV_CODIV2                         *((volatile unsigned int*)(0x42760600UL))
#define bM0P_SBSSR_CTSSSR_SSSR0                         *((volatile unsigned int*)(0x424BFF80UL))
#define bM0P_SBSSR_CTSSSR_SSSR1                         *((volatile unsigned int*)(0x424BFF84UL))
#define bM0P_SBSSR_CTSSSR_SSSR2                         *((volatile unsigned int*)(0x424BFF88UL))
#define bM0P_SBSSR_CTSSSR_SSSR3                         *((volatile unsigned int*)(0x424BFF8CUL))
#define bM0P_SBSSR_CTSSSR_SSSR4                         *((volatile unsigned int*)(0x424BFF90UL))
#define bM0P_SBSSR_CTSSSR_SSSR5                         *((volatile unsigned int*)(0x424BFF94UL))
#define bM0P_SBSSR_CTSSSR_SSSR6                         *((volatile unsigned int*)(0x424BFF98UL))
#define bM0P_SBSSR_CTSSSR_SSSR7                         *((volatile unsigned int*)(0x424BFF9CUL))
#define bM0P_SCI_CON_EN                                 *((volatile unsigned int*)(0x42790000UL))
#define bM0P_SCI_CON_FL_EN                              *((volatile unsigned int*)(0x42790004UL))
#define bM0P_SCI_CON_PARITY_CHECK_EN                    *((volatile unsigned int*)(0x42790008UL))
#define bM0P_SCI_CON_RETRY_EN                           *((volatile unsigned int*)(0x4279000CUL))
#define bM0P_SCI_CON_EDC_EN                             *((volatile unsigned int*)(0x42790010UL))
#define bM0P_SCI_CON_ETU_CNT_EN                         *((volatile unsigned int*)(0x42790014UL))
#define bM0P_SCI_CON_RX_FIFO_CLR                        *((volatile unsigned int*)(0x42790018UL))
#define bM0P_SCI_CON_TX_FIFO_CLR                        *((volatile unsigned int*)(0x4279001CUL))
#define bM0P_SCI_MODE_T_MODE                            *((volatile unsigned int*)(0x42790080UL))
#define bM0P_SCI_MODE_PARITY                            *((volatile unsigned int*)(0x42790084UL))
#define bM0P_SCI_MODE_CDCVT                             *((volatile unsigned int*)(0x42790088UL))
#define bM0P_SCI_MODE_EDC_MODE                          *((volatile unsigned int*)(0x42790090UL))
#define bM0P_SCI_MODE_RETRY_TIMES0                      *((volatile unsigned int*)(0x42790094UL))
#define bM0P_SCI_MODE_RETRY_TIMES1                      *((volatile unsigned int*)(0x42790098UL))
#define bM0P_SCI_MODE_RETRY_TIMES2                      *((volatile unsigned int*)(0x4279009CUL))
#define bM0P_SCI_STATUS_RX_FIN                          *((volatile unsigned int*)(0x42790100UL))
#define bM0P_SCI_STATUS_RX_ERR                          *((volatile unsigned int*)(0x42790104UL))
#define bM0P_SCI_STATUS_TX_FIN                          *((volatile unsigned int*)(0x42790108UL))
#define bM0P_SCI_STATUS_TX_ERR                          *((volatile unsigned int*)(0x4279010CUL))
#define bM0P_SCI_STATUS_ETU_CNT_FIN                     *((volatile unsigned int*)(0x42790110UL))
#define bM0P_SCI_STATUS_STAT                            *((volatile unsigned int*)(0x42790114UL))
#define bM0P_SCI_STATUS_RX_OVR                          *((volatile unsigned int*)(0x42790118UL))
#define bM0P_SCI_STATUS_RX_NE                           *((volatile unsigned int*)(0x4279011CUL))
#define bM0P_SCI_FIFO_STATUS_RX_EPTB                    *((volatile unsigned int*)(0x42790180UL))
#define bM0P_SCI_FIFO_STATUS_RX_FUL                     *((volatile unsigned int*)(0x42790184UL))
#define bM0P_SCI_FIFO_STATUS_RX_UDR                     *((volatile unsigned int*)(0x42790188UL))
#define bM0P_SCI_FIFO_STATUS_RX_OVR                     *((volatile unsigned int*)(0x4279018CUL))
#define bM0P_SCI_FIFO_STATUS_TX_EPTB                    *((volatile unsigned int*)(0x42790190UL))
#define bM0P_SCI_FIFO_STATUS_TX_FUL                     *((volatile unsigned int*)(0x42790194UL))
#define bM0P_SCI_FIFO_STATUS_TX_UDR                     *((volatile unsigned int*)(0x42790198UL))
#define bM0P_SCI_FIFO_STATUS_TX_EPT                     *((volatile unsigned int*)(0x4279019CUL))
#define bM0P_SCI_FIFO_DEPTH_RX_FIFO_DEPTH0              *((volatile unsigned int*)(0x42790200UL))
#define bM0P_SCI_FIFO_DEPTH_RX_FIFO_DEPTH1              *((volatile unsigned int*)(0x42790204UL))
#define bM0P_SCI_FIFO_DEPTH_RX_FIFO_DEPTH2              *((volatile unsigned int*)(0x42790208UL))
#define bM0P_SCI_FIFO_DEPTH_RX_FIFO_DEPTH3              *((volatile unsigned int*)(0x4279020CUL))
#define bM0P_SCI_FIFO_DEPTH_TX_FIFO_DEPTH0              *((volatile unsigned int*)(0x42790210UL))
#define bM0P_SCI_FIFO_DEPTH_TX_FIFO_DEPTH1              *((volatile unsigned int*)(0x42790214UL))
#define bM0P_SCI_FIFO_DEPTH_TX_FIFO_DEPTH2              *((volatile unsigned int*)(0x42790218UL))
#define bM0P_SCI_FIFO_DEPTH_TX_FIFO_DEPTH3              *((volatile unsigned int*)(0x4279021CUL))
#define bM0P_SCI_DATA_DATA0                             *((volatile unsigned int*)(0x42790280UL))
#define bM0P_SCI_DATA_DATA1                             *((volatile unsigned int*)(0x42790284UL))
#define bM0P_SCI_DATA_DATA2                             *((volatile unsigned int*)(0x42790288UL))
#define bM0P_SCI_DATA_DATA3                             *((volatile unsigned int*)(0x4279028CUL))
#define bM0P_SCI_DATA_DATA4                             *((volatile unsigned int*)(0x42790290UL))
#define bM0P_SCI_DATA_DATA5                             *((volatile unsigned int*)(0x42790294UL))
#define bM0P_SCI_DATA_DATA6                             *((volatile unsigned int*)(0x42790298UL))
#define bM0P_SCI_DATA_DATA7                             *((volatile unsigned int*)(0x4279029CUL))
#define bM0P_SCI_EDC_DATA_EDC_DATA0                     *((volatile unsigned int*)(0x42790300UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA1                     *((volatile unsigned int*)(0x42790304UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA2                     *((volatile unsigned int*)(0x42790308UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA3                     *((volatile unsigned int*)(0x4279030CUL))
#define bM0P_SCI_EDC_DATA_EDC_DATA4                     *((volatile unsigned int*)(0x42790310UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA5                     *((volatile unsigned int*)(0x42790314UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA6                     *((volatile unsigned int*)(0x42790318UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA7                     *((volatile unsigned int*)(0x4279031CUL))
#define bM0P_SCI_EDC_DATA_EDC_DATA8                     *((volatile unsigned int*)(0x42790320UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA9                     *((volatile unsigned int*)(0x42790324UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA10                    *((volatile unsigned int*)(0x42790328UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA11                    *((volatile unsigned int*)(0x4279032CUL))
#define bM0P_SCI_EDC_DATA_EDC_DATA12                    *((volatile unsigned int*)(0x42790330UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA13                    *((volatile unsigned int*)(0x42790334UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA14                    *((volatile unsigned int*)(0x42790338UL))
#define bM0P_SCI_EDC_DATA_EDC_DATA15                    *((volatile unsigned int*)(0x4279033CUL))
#define bM0P_SCI_SBDR_SBDR0                             *((volatile unsigned int*)(0x42790380UL))
#define bM0P_SCI_SBDR_SBDR1                             *((volatile unsigned int*)(0x42790384UL))
#define bM0P_SCI_SBDR_SBDR2                             *((volatile unsigned int*)(0x42790388UL))
#define bM0P_SCI_SBDR_SBDR3                             *((volatile unsigned int*)(0x4279038CUL))
#define bM0P_SCI_SBDR_SBDR4                             *((volatile unsigned int*)(0x42790390UL))
#define bM0P_SCI_SBDR_SBDR5                             *((volatile unsigned int*)(0x42790394UL))
#define bM0P_SCI_SBDR_SBDR6                             *((volatile unsigned int*)(0x42790398UL))
#define bM0P_SCI_SBDR_SBDR7                             *((volatile unsigned int*)(0x4279039CUL))
#define bM0P_SCI_SBDR_SBDR8                             *((volatile unsigned int*)(0x427903A0UL))
#define bM0P_SCI_SBDR_SBDR9                             *((volatile unsigned int*)(0x427903A4UL))
#define bM0P_SCI_SBDR_SBDR10                            *((volatile unsigned int*)(0x427903A8UL))
#define bM0P_SCI_SBDR_SBDR11                            *((volatile unsigned int*)(0x427903ACUL))
#define bM0P_SCI_SBDR_SBDR12                            *((volatile unsigned int*)(0x427903B0UL))
#define bM0P_SCI_SBDR_SBDR13                            *((volatile unsigned int*)(0x427903B4UL))
#define bM0P_SCI_SBDR_ETU_SEL0                          *((volatile unsigned int*)(0x427903B8UL))
#define bM0P_SCI_SBDR_ETU_SEL1                          *((volatile unsigned int*)(0x427903BCUL))
#define bM0P_SCI_ETU_CNT_ETU_CNT0                       *((volatile unsigned int*)(0x42790400UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT1                       *((volatile unsigned int*)(0x42790404UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT2                       *((volatile unsigned int*)(0x42790408UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT3                       *((volatile unsigned int*)(0x4279040CUL))
#define bM0P_SCI_ETU_CNT_ETU_CNT4                       *((volatile unsigned int*)(0x42790410UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT5                       *((volatile unsigned int*)(0x42790414UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT6                       *((volatile unsigned int*)(0x42790418UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT7                       *((volatile unsigned int*)(0x4279041CUL))
#define bM0P_SCI_ETU_CNT_ETU_CNT8                       *((volatile unsigned int*)(0x42790420UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT9                       *((volatile unsigned int*)(0x42790424UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT10                      *((volatile unsigned int*)(0x42790428UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT11                      *((volatile unsigned int*)(0x4279042CUL))
#define bM0P_SCI_ETU_CNT_ETU_CNT12                      *((volatile unsigned int*)(0x42790430UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT13                      *((volatile unsigned int*)(0x42790434UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT14                      *((volatile unsigned int*)(0x42790438UL))
#define bM0P_SCI_ETU_CNT_ETU_CNT15                      *((volatile unsigned int*)(0x4279043CUL))
#define bM0P_SCI_F1_NUM_FL_NUM0                         *((volatile unsigned int*)(0x42790480UL))
#define bM0P_SCI_F1_NUM_FL_NUM1                         *((volatile unsigned int*)(0x42790484UL))
#define bM0P_SCI_F1_NUM_FL_NUM2                         *((volatile unsigned int*)(0x42790488UL))
#define bM0P_SCI_CLK_RST_RESET_EN                       *((volatile unsigned int*)(0x42790500UL))
#define bM0P_SCI_CLK_RST_RESET                          *((volatile unsigned int*)(0x42790504UL))
#define bM0P_SCI_CLK_RST_CLK_EN                         *((volatile unsigned int*)(0x42790508UL))
#define bM0P_SCI_CLK_RST_CLK_SEL0                       *((volatile unsigned int*)(0x4279050CUL))
#define bM0P_SCI_CLK_RST_CLK_SEL1                       *((volatile unsigned int*)(0x42790510UL))
#define bM0P_SCI_INT_EN_WAKEUP_INT_EN                   *((volatile unsigned int*)(0x42790580UL))
#define bM0P_SCI_INT_EN_ETU_CNT_INT_EN                  *((volatile unsigned int*)(0x42790584UL))
#define bM0P_SCI_INT_EN_INT_EN                          *((volatile unsigned int*)(0x42790588UL))
#define bM0P_SCI_WAKEUP_INT_WAKEUP_INT                  *((volatile unsigned int*)(0x42790600UL))
#define bM0P_SWWDT_WDT_CTL_IE                           *((volatile unsigned int*)(0x42240100UL))
#define bM0P_SWWDT_WDT_CTL_RSTEN                        *((volatile unsigned int*)(0x42240104UL))
#define bM0P_SWWDT_WDT_CTL_TMWD0                        *((volatile unsigned int*)(0x42240108UL))
#define bM0P_SWWDT_WDT_CTL_TMWD1                        *((volatile unsigned int*)(0x4224010CUL))
#define bM0P_SWWDT_WDT_CTL_WDM                          *((volatile unsigned int*)(0x42240110UL))
#define bM0P_SWWDT_WDT_STA_STA                          *((volatile unsigned int*)(0x42240200UL))
#define bM0P_SWWDT_WDT_MDC_TRG                          *((volatile unsigned int*)(0x42240300UL))
#define bM0P_UID_UIDR0_UID0                             *((volatile unsigned int*)(0x42004000UL))
#define bM0P_UID_UIDR0_UID1                             *((volatile unsigned int*)(0x42004004UL))
#define bM0P_UID_UIDR0_UID2                             *((volatile unsigned int*)(0x42004008UL))
#define bM0P_UID_UIDR0_UID3                             *((volatile unsigned int*)(0x4200400CUL))
#define bM0P_UID_UIDR0_UID4                             *((volatile unsigned int*)(0x42004010UL))
#define bM0P_UID_UIDR0_UID5                             *((volatile unsigned int*)(0x42004014UL))
#define bM0P_UID_UIDR0_UID6                             *((volatile unsigned int*)(0x42004018UL))
#define bM0P_UID_UIDR0_UID7                             *((volatile unsigned int*)(0x4200401CUL))
#define bM0P_UID_UIDR0_UID8                             *((volatile unsigned int*)(0x42004020UL))
#define bM0P_UID_UIDR0_UID9                             *((volatile unsigned int*)(0x42004024UL))
#define bM0P_UID_UIDR0_UID10                            *((volatile unsigned int*)(0x42004028UL))
#define bM0P_UID_UIDR0_UID11                            *((volatile unsigned int*)(0x4200402CUL))
#define bM0P_UID_UIDR0_UID12                            *((volatile unsigned int*)(0x42004030UL))
#define bM0P_UID_UIDR0_UID13                            *((volatile unsigned int*)(0x42004034UL))
#define bM0P_UID_UIDR0_UID14                            *((volatile unsigned int*)(0x42004038UL))
#define bM0P_UID_UIDR0_UID15                            *((volatile unsigned int*)(0x4200403CUL))
#define bM0P_UID_UIDR0_UID16                            *((volatile unsigned int*)(0x42004040UL))
#define bM0P_UID_UIDR0_UID17                            *((volatile unsigned int*)(0x42004044UL))
#define bM0P_UID_UIDR0_UID18                            *((volatile unsigned int*)(0x42004048UL))
#define bM0P_UID_UIDR0_UID19                            *((volatile unsigned int*)(0x4200404CUL))
#define bM0P_UID_UIDR0_UID20                            *((volatile unsigned int*)(0x42004050UL))
#define bM0P_UID_UIDR0_UID21                            *((volatile unsigned int*)(0x42004054UL))
#define bM0P_UID_UIDR0_UID22                            *((volatile unsigned int*)(0x42004058UL))
#define bM0P_UID_UIDR0_UID23                            *((volatile unsigned int*)(0x4200405CUL))
#define bM0P_UID_UIDR0_UID24                            *((volatile unsigned int*)(0x42004060UL))
#define bM0P_UID_UIDR0_UID25                            *((volatile unsigned int*)(0x42004064UL))
#define bM0P_UID_UIDR0_UID26                            *((volatile unsigned int*)(0x42004068UL))
#define bM0P_UID_UIDR0_UID27                            *((volatile unsigned int*)(0x4200406CUL))
#define bM0P_UID_UIDR0_UID28                            *((volatile unsigned int*)(0x42004070UL))
#define bM0P_UID_UIDR0_UID29                            *((volatile unsigned int*)(0x42004074UL))
#define bM0P_UID_UIDR0_UID30                            *((volatile unsigned int*)(0x42004078UL))
#define bM0P_UID_UIDR0_UID31                            *((volatile unsigned int*)(0x4200407CUL))
#define bM0P_UID_UIDR1_UID0                             *((volatile unsigned int*)(0x42004080UL))
#define bM0P_UID_UIDR1_UID1                             *((volatile unsigned int*)(0x42004084UL))
#define bM0P_UID_UIDR1_UID2                             *((volatile unsigned int*)(0x42004088UL))
#define bM0P_UID_UIDR1_UID3                             *((volatile unsigned int*)(0x4200408CUL))
#define bM0P_UID_UIDR1_UID4                             *((volatile unsigned int*)(0x42004090UL))
#define bM0P_UID_UIDR1_UID5                             *((volatile unsigned int*)(0x42004094UL))
#define bM0P_UID_UIDR1_UID6                             *((volatile unsigned int*)(0x42004098UL))
#define bM0P_UID_UIDR1_UID7                             *((volatile unsigned int*)(0x4200409CUL))
#define bM0P_UID_UIDR1_UID8                             *((volatile unsigned int*)(0x420040A0UL))
#define bM0P_UID_UIDR1_UID9                             *((volatile unsigned int*)(0x420040A4UL))
#define bM0P_UID_UIDR1_UID10                            *((volatile unsigned int*)(0x420040A8UL))
#define bM0P_UID_UIDR1_UID11                            *((volatile unsigned int*)(0x420040ACUL))
#define bM0P_UID_UIDR1_UID12                            *((volatile unsigned int*)(0x420040B0UL))
#define bM0P_UID_UIDR1_UID13                            *((volatile unsigned int*)(0x420040B4UL))
#define bM0P_UID_UIDR1_UID14                            *((volatile unsigned int*)(0x420040B8UL))
#define bM0P_UID_UIDR1_UID15                            *((volatile unsigned int*)(0x420040BCUL))
#define bM0P_UID_UIDR1_UID16                            *((volatile unsigned int*)(0x420040C0UL))
#define bM0P_UID_UIDR1_UID17                            *((volatile unsigned int*)(0x420040C4UL))
#define bM0P_UID_UIDR1_UID18                            *((volatile unsigned int*)(0x420040C8UL))
#define bM0P_UID_UIDR1_UID19                            *((volatile unsigned int*)(0x420040CCUL))
#define bM0P_UID_UIDR1_UID20                            *((volatile unsigned int*)(0x420040D0UL))
#define bM0P_UID_UIDR1_UID21                            *((volatile unsigned int*)(0x420040D4UL))
#define bM0P_UID_UIDR1_UID22                            *((volatile unsigned int*)(0x420040D8UL))
#define bM0P_UID_UIDR1_UID23                            *((volatile unsigned int*)(0x420040DCUL))
#define bM0P_UID_UIDR1_UID24                            *((volatile unsigned int*)(0x420040E0UL))
#define bM0P_UID_UIDR1_UID25                            *((volatile unsigned int*)(0x420040E4UL))
#define bM0P_UID_UIDR1_UID26                            *((volatile unsigned int*)(0x420040E8UL))
#define bM0P_UID_UIDR1_UID27                            *((volatile unsigned int*)(0x420040ECUL))
#define bM0P_UID_UIDR1_UID28                            *((volatile unsigned int*)(0x420040F0UL))
#define bM0P_UID_UIDR1_UID29                            *((volatile unsigned int*)(0x420040F4UL))
#define bM0P_UID_UIDR1_UID30                            *((volatile unsigned int*)(0x420040F8UL))
#define bM0P_UID_UIDR1_UID31                            *((volatile unsigned int*)(0x420040FCUL))
#define bM0P_UID_UIDR2_UID0                             *((volatile unsigned int*)(0x42004100UL))
#define bM0P_UID_UIDR2_UID1                             *((volatile unsigned int*)(0x42004104UL))
#define bM0P_UID_UIDR2_UID2                             *((volatile unsigned int*)(0x42004108UL))
#define bM0P_UID_UIDR2_UID3                             *((volatile unsigned int*)(0x4200410CUL))
#define bM0P_UID_UIDR2_UID4                             *((volatile unsigned int*)(0x42004110UL))
#define bM0P_UID_UIDR2_UID5                             *((volatile unsigned int*)(0x42004114UL))
#define bM0P_UID_UIDR2_UID6                             *((volatile unsigned int*)(0x42004118UL))
#define bM0P_UID_UIDR2_UID7                             *((volatile unsigned int*)(0x4200411CUL))
#define bM0P_UID_UIDR2_UID8                             *((volatile unsigned int*)(0x42004120UL))
#define bM0P_UID_UIDR2_UID9                             *((volatile unsigned int*)(0x42004124UL))
#define bM0P_UID_UIDR2_UID10                            *((volatile unsigned int*)(0x42004128UL))
#define bM0P_UID_UIDR2_UID11                            *((volatile unsigned int*)(0x4200412CUL))
#define bM0P_UID_UIDR2_UID12                            *((volatile unsigned int*)(0x42004130UL))
#define bM0P_UID_UIDR2_UID13                            *((volatile unsigned int*)(0x42004134UL))
#define bM0P_UID_UIDR2_UID14                            *((volatile unsigned int*)(0x42004138UL))
#define bM0P_UID_UIDR2_UID15                            *((volatile unsigned int*)(0x4200413CUL))
#define bM0P_VC_CTL1_VC_EN                              *((volatile unsigned int*)(0x42786000UL))
#define bM0P_VC_CTL1_VC_OUT                             *((volatile unsigned int*)(0x42786004UL))
#define bM0P_VC_CTL1_VC_NMODE0                          *((volatile unsigned int*)(0x42786008UL))
#define bM0P_VC_CTL1_VC_NMODE1                          *((volatile unsigned int*)(0x4278600CUL))
#define bM0P_VC_CTL1_VC_PMODE0                          *((volatile unsigned int*)(0x42786010UL))
#define bM0P_VC_CTL1_VC_PMODE1                          *((volatile unsigned int*)(0x42786014UL))
#define bM0P_VC_CTL1_VCVOL_SEL0                         *((volatile unsigned int*)(0x42786020UL))
#define bM0P_VC_CTL1_VCVOL_SEL1                         *((volatile unsigned int*)(0x42786024UL))
#define bM0P_VC_CTL1_VCVOL_SEL2                         *((volatile unsigned int*)(0x42786028UL))
#define bM0P_VC_CTL1_VCVOL_SEL3                         *((volatile unsigned int*)(0x4278602CUL))
#define bM0P_VC_CTL1_VCVOL_SEL4                         *((volatile unsigned int*)(0x42786030UL))
#define bM0P_VC_CTL1_VCVOL_SEL5                         *((volatile unsigned int*)(0x42786034UL))
#define bM0P_VC_CTL1_VCDIV_EN                           *((volatile unsigned int*)(0x42786038UL))
#define bM0P_VC_CTL1_VCDIV_SEL                          *((volatile unsigned int*)(0x4278603CUL))
#define bM0P_VC_CTL2_VC_FILTER_EN                       *((volatile unsigned int*)(0x42786080UL))
#define bM0P_VC_CTL2_VC_RESPONSE0                       *((volatile unsigned int*)(0x42786084UL))
#define bM0P_VC_CTL2_VC_RESPONSE1                       *((volatile unsigned int*)(0x42786088UL))
#define bM0P_VC_CTL2_VC_RESPONSE2                       *((volatile unsigned int*)(0x4278608CUL))
#define bM0P_VC_CTL2_VC_EXBUF                           *((volatile unsigned int*)(0x42786090UL))
#define bM0P_VC_CTL2_VCINT_FALLING                      *((volatile unsigned int*)(0x42786094UL))
#define bM0P_VC_CTL2_VCINT_RISING                       *((volatile unsigned int*)(0x42786098UL))
#define bM0P_VC_CTL2_VCINT_HIGH                         *((volatile unsigned int*)(0x4278609CUL))
#define bM0P_VC_CTL2_VC2PT                              *((volatile unsigned int*)(0x427860A0UL))
#define bM0P_VC_CTL2_VCIE                               *((volatile unsigned int*)(0x427860A4UL))
#define bM0P_VC_CTL2_VCIF                               *((volatile unsigned int*)(0x427860A8UL))
#define bM0P_VC_CTL2_VC_HYS_SEL0                        *((volatile unsigned int*)(0x427860ACUL))
#define bM0P_VC_CTL2_VC_HYS_SEL1                        *((volatile unsigned int*)(0x427860B0UL))
#define bM0P_VC_CTL3_VC_TM0G                            *((volatile unsigned int*)(0x42786100UL))
#define bM0P_VC_CTL3_VC_TM2G                            *((volatile unsigned int*)(0x42786108UL))
#define bM0P_VC_CTL3_VCIN_NEG_SEL0                      *((volatile unsigned int*)(0x42786110UL))
#define bM0P_VC_CTL3_VCIN_NEG_SEL1                      *((volatile unsigned int*)(0x42786114UL))
#define bM0P_VC_CTL3_VCIN_POS_SEL0                      *((volatile unsigned int*)(0x42786118UL))
#define bM0P_VC_CTL3_VCIN_POS_SEL1                      *((volatile unsigned int*)(0x4278611CUL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_EN                    *((volatile unsigned int*)(0x426A0000UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_SRST                  *((volatile unsigned int*)(0x426A0004UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VIN0                  *((volatile unsigned int*)(0x426A0008UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VIN1                  *((volatile unsigned int*)(0x426A000CUL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VSET0                 *((volatile unsigned int*)(0x426A0010UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VSET1                 *((volatile unsigned int*)(0x426A0014UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VSET2                 *((volatile unsigned int*)(0x426A0018UL))
#define bM0P_WSUNIT_LVD_CTRL1_LVD_VSET3                 *((volatile unsigned int*)(0x426A001CUL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_HYS_EN                *((volatile unsigned int*)(0x426A0080UL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_F_EN                  *((volatile unsigned int*)(0x426A0084UL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_F_SET0                *((volatile unsigned int*)(0x426A0088UL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_F_SET1                *((volatile unsigned int*)(0x426A008CUL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_F_SET2                *((volatile unsigned int*)(0x426A0090UL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_IE0                   *((volatile unsigned int*)(0x426A0094UL))
#define bM0P_WSUNIT_LVD_CTRL2_LVD_IE1                   *((volatile unsigned int*)(0x426A0098UL))
#define bM0P_WSUNIT_LVD_STR_LVD_IRQ                     *((volatile unsigned int*)(0x426A0100UL))
#define bM0P_WSUNIT_LVD_STR_LVD_OUT                     *((volatile unsigned int*)(0x426A0120UL))
#define bM0P_WSUNIT_LVD_CLR_LVD_CLR                     *((volatile unsigned int*)(0x426A0180UL))
#define bM0P_WSUNIT_LVD2_CTL_LVD2_EN                    *((volatile unsigned int*)(0x426A0280UL))
#define bM0P_WSUNIT_LVD2_CTL_LVD2_VSET0                 *((volatile unsigned int*)(0x426A0284UL))
#define bM0P_WSUNIT_LVD2_CTL_LVD2_VSET1                 *((volatile unsigned int*)(0x426A0288UL))
#define bM0P_WSUNIT_LVD2_CTL_LVD2_VSET2                 *((volatile unsigned int*)(0x426A028CUL))
#define bM0P_WSUNIT_LVD2_CTL_LVD2_IE                    *((volatile unsigned int*)(0x426A0290UL))
#define bM0P_WSUNIT_LVD2_STR_LVD2_IRQ                   *((volatile unsigned int*)(0x426A0300UL))
#define bM0P_WSUNIT_LVD2_STR_SENSE_STA                  *((volatile unsigned int*)(0x426A0320UL))
#define bM0P_WSUNIT_LVD2_STR_LVD2_STA                   *((volatile unsigned int*)(0x426A0324UL))
#define bM0P_WSUNIT_LVD2_CLR_LVD2_CLR                   *((volatile unsigned int*)(0x426A0380UL))
#define bM0P_WSUNIT_LDO_CTL_AUTOSWEN                    *((volatile unsigned int*)(0x426A0420UL))
#define bM0P_WSUNIT_LDO_CTL_KEY0                        *((volatile unsigned int*)(0x426A0440UL))
#define bM0P_WSUNIT_LDO_CTL_KEY1                        *((volatile unsigned int*)(0x426A0444UL))
#define bM0P_WSUNIT_LDO_CTL_KEY2                        *((volatile unsigned int*)(0x426A0448UL))
#define bM0P_WSUNIT_LDO_CTL_KEY3                        *((volatile unsigned int*)(0x426A044CUL))
#define bM0P_WSUNIT_LDO_CTL_KEY4                        *((volatile unsigned int*)(0x426A0450UL))
#define bM0P_WSUNIT_LDO_CTL_KEY5                        *((volatile unsigned int*)(0x426A0454UL))
#define bM0P_WSUNIT_LDO_CTL_KEY6                        *((volatile unsigned int*)(0x426A0458UL))
#define bM0P_WSUNIT_LDO_CTL_KEY7                        *((volatile unsigned int*)(0x426A045CUL))
#define bM0P_WSUNIT_LDO_CTL_KEY8                        *((volatile unsigned int*)(0x426A0460UL))
#define bM0P_WSUNIT_LDO_CTL_KEY9                        *((volatile unsigned int*)(0x426A0464UL))
#define bM0P_WSUNIT_LDO_CTL_KEY10                       *((volatile unsigned int*)(0x426A0468UL))
#define bM0P_WSUNIT_LDO_CTL_KEY11                       *((volatile unsigned int*)(0x426A046CUL))
#define bM0P_WSUNIT_LDO_CTL_KEY12                       *((volatile unsigned int*)(0x426A0470UL))
#define bM0P_WSUNIT_LDO_CTL_KEY13                       *((volatile unsigned int*)(0x426A0474UL))
#define bM0P_WSUNIT_LDO_CTL_KEY14                       *((volatile unsigned int*)(0x426A0478UL))
#define bM0P_WSUNIT_LDO_CTL_KEY15                       *((volatile unsigned int*)(0x426A047CUL))
#define bM0P_WSUNIT_BGR_CTL_BGR_EN                      *((volatile unsigned int*)(0x426A0600UL))
#define bM0P_WSUNIT_CLK_CTL1_RTCE                       *((volatile unsigned int*)(0x426A2000UL))
#define bM0P_WSUNIT_CLK_CTL2_RTCCKE                     *((volatile unsigned int*)(0x426A2080UL))
#define bM0P_WSUNIT_CLK_CTL2_LCDCKE                     *((volatile unsigned int*)(0x426A2084UL))
#define bM0P_WSUNIT_CLK_CTL2_WDTCKE                     *((volatile unsigned int*)(0x426A2088UL))
#define bM0P_WSUNIT_CLK_CTL2_UARTCKE                    *((volatile unsigned int*)(0x426A2090UL))
#define bM0P_WSUNIT_MOSC_CTL_IMAINSEL0                  *((volatile unsigned int*)(0x426A2100UL))
#define bM0P_WSUNIT_MOSC_CTL_IMAINSEL1                  *((volatile unsigned int*)(0x426A2104UL))
#define bM0P_WSUNIT_DS_RAMP_RAMP                        *((volatile unsigned int*)(0x426A2180UL))
#define bM0P_WSUNIT_WAKE_RSR_REINTX                     *((volatile unsigned int*)(0x426A4000UL))
#define bM0P_WSUNIT_WAKE_RSR_RELVDR                     *((volatile unsigned int*)(0x426A4004UL))
#define bM0P_WSUNIT_WAKE_ISR_RERTCI                     *((volatile unsigned int*)(0x426A4080UL))
#define bM0P_WSUNIT_WAKE_ISR_RELVDI                     *((volatile unsigned int*)(0x426A4084UL))
#define bM0P_WSUNIT_WAKE_ISR_REWU0I                     *((volatile unsigned int*)(0x426A4088UL))
#define bM0P_WSUNIT_WAKE_ISR_REWU1I                     *((volatile unsigned int*)(0x426A408CUL))
#define bM0P_WSUNIT_WAKE_ISR_REWU2I                     *((volatile unsigned int*)(0x426A4090UL))
#define bM0P_WSUNIT_WAKE_ISR_REWU3I                     *((volatile unsigned int*)(0x426A4094UL))
#define bM0P_WSUNIT_WAKE_IER_RERTCE                     *((volatile unsigned int*)(0x426A4100UL))
#define bM0P_WSUNIT_WAKE_IER_RELVDE                     *((volatile unsigned int*)(0x426A4104UL))
#define bM0P_WSUNIT_WAKE_IER_REWU0E                     *((volatile unsigned int*)(0x426A4108UL))
#define bM0P_WSUNIT_WAKE_IER_REWU1E                     *((volatile unsigned int*)(0x426A410CUL))
#define bM0P_WSUNIT_WAKE_IER_REWU2E                     *((volatile unsigned int*)(0x426A4110UL))
#define bM0P_WSUNIT_WAKE_IER_REWU3E                     *((volatile unsigned int*)(0x426A4114UL))
#define bM0P_WSUNIT_WAKE_LVR_WUI0LV                     *((volatile unsigned int*)(0x426A4180UL))
#define bM0P_WSUNIT_WAKE_LVR_WUI1LV                     *((volatile unsigned int*)(0x426A4184UL))
#define bM0P_WSUNIT_WAKE_LVR_WUI2LV                     *((volatile unsigned int*)(0x426A4188UL))
#define bM0P_WSUNIT_WAKE_LVR_WUI3LV                     *((volatile unsigned int*)(0x426A418CUL))


#ifdef __cplusplus
}
#endif

#endif /* __HC32L15_H__ */

