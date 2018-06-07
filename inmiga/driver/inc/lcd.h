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
/******************************************************************************/
/** \file lcd.h
 **
 ** Headerfile for LCD functions
 **
 ** History:
 **   - 2016-10-31
 **
 ******************************************************************************/

#ifndef __LCD_H__
#define __LCD_H__

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

/**
 ******************************************************************************
 ** \brief defgroup Lcd Group(Lcd)
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Global type definitions
 *****************************************************************************/

/**
 ******************************************************************************
 ** \brief Redefinition of LCD register structure
 *****************************************************************************/  
typedef  M0P_LCDC_TypeDef         stc_lcdc_regtyptedef_t;

typedef  stc_lcdc_lcdse0_field_t  stc_lcd_se0typedef_t;
typedef  stc_lcdc_lcdse1_field_t  stc_lcd_se1typedef_t;
typedef  stc_lcdc_lcdse2_field_t  stc_lcd_se2typedef_t;
typedef  stc_lcdc_lcdse3_field_t  stc_lcd_se3typedef_t;
typedef  stc_lcdc_lcdse4_field_t  stc_lcd_se4typedef_t;
   
/**
 ******************************************************************************
 ** \brief LCD display clk select
 *****************************************************************************/ 
typedef enum en_lcd_display_clk_sel
{
    LcdClkSelExCrystals  = 0,        /*!< LCD display clock selected external crystals*/
    LcdClkSelInRc   =  1,            /*!< LCD display clock selected internal RC*/
      
} en_lcd_display_clk_sel_t;

/**
 ******************************************************************************
 ** \brief LCD frame refresh rate select
 *****************************************************************************/ 
typedef enum en_lcd_framereratesel
{
    LcdFrameReRateSel128Hz   =  0,    /*!< The frame refresh rate select 128hz*/
    LcdFrameReRateSel256Hz   =  1,    /*!< The frame refresh rate select 256hz*/
    LcdFrameReRateSel512Hz   =  2,    /*!< The frame refresh rate select 512hz*/
    LcdFrameReRateSel1kHz    =  3,    /*!< The frame refresh rate select 1khz*/

}en_lcd_framereratesel_t;

/**
 ******************************************************************************
 ** \brief LCD bias Settings
 *****************************************************************************/ 
typedef enum en_lcd_biasset
{
    LcdBiasSet1Div2   =  0,        /*!< LCD bias Set 1/2*/
    LcdBiasSet1Div3   =  1,        /*!< LCD bias Set 1/3*/
    Lcd_BiasSet1Div4  =  2,        /*!< LCD bias Set 1/4*/
    
}en_lcd_biasset_t;

/**
 ******************************************************************************
 ** \brief LCD display mode select
 *****************************************************************************/ 
typedef enum en_lcd_dismodesel
{
    Lcd_DisModeSelStatic  =  0,    /*!< LCD display mode select Static*/
    LcdDisModeSel2Per     =  1,    /*!< LCD display mode select 2 Period*/
    LcdDisModeSel3Per     =  2,    /*!< LCD display mode select 3 Period*/
    LcdDisModeSel4Per     =  3,    /*!< LCD display mode select 4 Period*/
    LcdDisModeSel6Per     =  5,    /*!< LCD display mode select 6 Period*/
    LcdDisModeSel8Per     =  7,    /*!< LCD display mode select 8 Period*/

}en_lcd_dismodesel_t;

/**
 ******************************************************************************
 ** \brief LCD contrast select
 *****************************************************************************/ 
typedef enum en_lcd_contrastsel
{
    LcdContrastSel60per  =  0,    /*!< LCD contrast select 60%*/
    LcdContrastSel65per  =  1,    /*!< LCD contrast select 65%*/
    LcdContrastSel70per  =  2,    /*!< LCD contrast select 70%*/
    LcdContrastSel75per  =  3,    /*!< LCD contrast select 75%*/
    LcdContrastSel80per  =  4,    /*!< LCD contrast select 80%*/
    LcdContrastSel85per  =  5,    /*!< LCD contrast select 85%*/
    LcdContrastSel90per  =  6,    /*!< LCD contrast select 90%*/
    LcdContrastSel100per =  7,    /*!< LCD contrast select 100%*/
  
}en_lcd_contrastsel_t;

/**
 ******************************************************************************
 ** \brief LCD Charge time select
 *****************************************************************************/ 
typedef enum en_lcd_rchargtimsel
{
    LcdRChargTimSel1Clk  =  0,     /*!< LCD Resistance Charge time select 1 CLK*/
    LcdRChargTimSel2Clk  =  1,     /*!< LCD Resistance Charge time select 2 CLK*/
    LcdRChargTimSel3Clk  =  2,     /*!< LCD Resistance Charge time select 3 CLK*/
    LcdRChargTimSel4Clk  =  3,     /*!< LCD Resistance Charge time select 4 CLK*/
    LcdRChargTimSel5Clk  =  4,     /*!< LCD Resistance Charge time select 5 CLK*/
    LcdRChargTimSel6Clk  =  5,     /*!< LCD Resistance Charge time select 6 CLK*/
    LcdRChargTimSel7Clk  =  6,     /*!< LCD Resistance Charge time select 7 CLK*/
    LcdRChargTimSel8Clk  =  7,     /*!< LCD Resistance Charge time select 8 CLK*/
     
}en_lcd_rchargtimsel_t;

/**
 ******************************************************************************
 ** \brief LCD Charge mode select
 *****************************************************************************/ 
typedef enum en_lcd_rchargmodesel
{
    LcdRChargModeSelFast     = 0,   /*!< LCD Resistance Charge mode select fast charge*/
    LcdRChargModeSelLargeCur = 1,   /*!< LCD Resistance Charge mode select Large current charging*/
    LcdRChargModeSelSmallCur = 2,   /*!< LCD Resistance Charge mode select small current charging*/

}en_lcd_rchargmodesel_t;

/**
 ******************************************************************************
 ** \brief LCD capacitance charge pump Charging frequency select
 *****************************************************************************/ 
typedef enum en_lcd_capchargpumpchfresel
{
    ChargPumpChFreSel2kHz  =  0,    /*!< LCD capacitance charge pump Charging frequency select 2kHz*/
    ChargPumpChFreSel4kHz  =  1,    /*!< LCD capacitance charge pump Charging frequency select 4kHz*/
    ChargPumpChFreSel8kHz  =  2,    /*!< LCD capacitance charge pump Charging frequency select 8kHz*/
    ChargPumpChFreSel16kHz =  3,    /*!< LCD capacitance charge pump Charging frequency select 16kHz*/

}en_lcd_capchargpumpchfresel_t;

/**
 ******************************************************************************
 ** \brief LCD bias circuit selection
 *****************************************************************************/ 
typedef enum en_lcd_biascircuitsel
{
    LcdBiasCircuitSelInRes   =  0,  /*!< LCD bias circuit selection Internal resistance */
    LcdBiasCircuitSelExCap   =  1,  /*!< LCD bias circuit selection  external capacitance*/
    LcdBiasCircuitSelExRes   =  2,  /*!< LCD bias circuit selection  external resistance*/

}en_lcd_biascircuitsel_t;

/**
 ******************************************************************************
 ** \brief LCD drive waveform selection
 *****************************************************************************/ 
typedef enum en_lcd_drivwavesel
{
     LcdDrivWaveSelTypeA  =  0,     /*!< LCD drive waveform selection type A*/
     LcdDrivWaveSelTypeB  =  1,     /*!< LCD drive waveform selection type B*/
  
}en_lcd_drivwavesel_t;

/**
 ******************************************************************************
 ** \brief LCD enable or disable
 *****************************************************************************/ 
typedef enum en_lcd_enordis
{
     LcdDisAble   =  0,           /*!< LCD drive enable*/
     Lcd_Enable   =  1,           /*!< LCD drive disable*/
    
}en_lcd_enordis_t;

/**
 ******************************************************************************
 ** \brief LCD drive power select
 *****************************************************************************/ 
typedef enum en_lcd_drivepowsel
{
     LcdDrivePowSelNormal  =  0,   /*!< LCD drive power select Normal*/
     LcdDrivePowSel2Times  =  1,   /*!< LCD drive power select 2T */
     LcdDrivePowSel3Times  =  2,   /*!< LCD drive power select 3T */
     LcdDrivePowSel4Times  =  3,   /*!< LCD drive power select 4T */
     
}en_lcd_drivepowsel_t;

/**
 ******************************************************************************
 ** \brief R03 port function select 
 *****************************************************************************/ 
typedef enum en_lcd_r03portfunsel
{
     LcdR03PortFunSelGpio  =  0,     /*!< R03 Port function select GPIO*/
     LcdR03PortFunSelVolIn =  1,     /*!< R03 Port function select drive voltage input*/
    
}en_lcd_r03portfunsel_t;

/**
 ******************************************************************************
 ** \brief R13 Port function select
 *****************************************************************************/ 
typedef enum en_lcd_r13portfunsel
{
     LcdR13PortFunSelGpio   =  0,   /*!< R13 Port function select GPIO*/
     LcdR13PortFunSelVolIn  =  1,   /*!< R13 Port function select drive voltage input*/

}en_lcd_r13portfunsel_t;

/**
 ******************************************************************************
 ** \brief R23 Port function select
 *****************************************************************************/
typedef enum en_lcd_r23portfunsel
{
     LcdR23PortFunSelGpio   =  0,   /*!< R23 Port function select GPIO*/
     LcdR23PortFunSelVolIn  =  1,   /*!< R23 Port function select drive voltage input*/

}en_lcd_r23portfunsel_t;

/**
 ******************************************************************************
 ** \brief R33 Port function select
 *****************************************************************************/
typedef enum en_lcd_r33portfunsel
{
     LcdR33PortFunSelGpio   =  0,   /*!< R33 Port function select GPIO*/
     LcdR33PortFunSelVolIn  =  1,   /*!< R33 Port function select drive voltage input*/

}en_lcd_r33portfunsel_t;

/**
 ******************************************************************************
 ** \brief R43 Port function select
 *****************************************************************************/
typedef enum en_lcd_r43portfunsel
{
     LcdR43PortFunSelGpio   =  0,   /*!< R43 Port function select GPIO*/
     LcdR43PortFunSelVolIn  =  1,   /*!< R43 Port function select drive voltage input*/

}en_lcd_r43portfunsel_t;

/**
 ******************************************************************************
 ** \brief COM0 Function select
 *****************************************************************************/
typedef enum en_lcd_com0funsel
{
     LcdCom0FunSelGpio    =  0,   /*!< COM0 as GPIO*/
     LcdCom0FunSelOutput  =  1,   /*!< Com0 as LCD output*/

}en_lcd_com0funsel_t;

/**
 ******************************************************************************
 ** \brief COM1 Function select
 *****************************************************************************/
typedef enum en_lcd_com1funsel
{
     LcdCom1FunSelGpio    =  0,   /*!< COM1 as GPIO*/
     LcdCom1FunSelOutput  =  1,   /*!< Com1 as LCD output*/

}en_lcd_com1funsel_t;

/**
 ******************************************************************************
 ** \brief COM2 Function select
 *****************************************************************************/
typedef enum en_lcd_com2funsel
{
     LcdCom2FunSelGpio    =  0,   /*!< COM2 as GPIO*/
     LcdCom2FunSelOutput  =  1,   /*!< Com2 as LCD output*/

}en_lcd_com2funsel_t;

/**
 ******************************************************************************
 ** \brief COM3 Function select
 *****************************************************************************/
typedef enum en_lcd_com3funsel
{
     LcdCom3FunSelGpio    =  0,   /*!< COM3 as GPIO*/
     LcdCom3FunSelOutput  =  1,   /*!< COM3 as LCD output*/

}en_lcd_com3funsel_t;

/**
 ******************************************************************************
 ** \brief COM4 Function select
 *****************************************************************************/
typedef enum en_lcd_com4funsel
{
     LcdCom4FunSelGpio    =  0,   /*!< COM4 as GPIO*/
     LcdCom4FunSelOutput  =  1,   /*!< COM4 as LCD output*/

}en_lcd_com4funsel_t;

/**
 ******************************************************************************
 ** \brief COM5 Function select
 *****************************************************************************/
typedef enum en_lcd_com5funsel
{
     LcdCom5FunSelGpio    =  0,   /*!< COM5 as GPIO*/
     LcdCom5FunSelOutput  =  1,   /*!< COM5 as LCD output*/

}en_lcd_com5funsel_t;

/**
 ******************************************************************************
 ** \brief COM6 Function select
 *****************************************************************************/
typedef enum en_lcd_com6funsel
{
     LcdCom6FunSelGpio    =  0,   /*!< COM6 as GPIO*/
     LcdCom6FunSelOutput  =  1,   /*!< COM6 as LCD output*/

}en_lcd_com6funsel_t;

/**
 ******************************************************************************
 ** \brief COM7 Function select
 *****************************************************************************/
typedef enum en_lcd_com7funsel
{
     LcdCom7FunSelGpio    =  0,   /*!< COM7 as GPIO*/
     LcdCom7FunSelOutput  =  1,   /*!< COM7 as LCD output*/

}en_lcd_com7funsel_t;

/**
 ******************************************************************************
 ** \brief LCD working mode enumerations
 *****************************************************************************/
typedef enum  en_lcd_workmodesel
{
    /*!< 8 COM mode, pin SEG0 ~ SEG35 as segment signal output pin*/
    Lcd_8Com_1Div8Duty_1Div3bias_TypeA_Max36Seg  = 0,
    /*!< */    
    Lcd_8Com_1Div8Duty_1Div3bias_TypeB_Max36Seg  = 1,
    /*!< */
    Lcd_8Com_1Div8Duty_1Div4bias_TypeA_Max36Seg  = 2,
    /*!< */
    Lcd_8Com_1Div8Duty_1Div4bias_TypeB_Max36Seg  = 3,
    
    /*!< 6 COM mode, pin SEG0 ~ SEG35, SEG38 and SEG39 as segment signal output pin.*/
    Lcd_6Com_1Div6Duty_1Div3bias_TypeA_Max38Seg  = 4,
    /*!< */
    Lcd_6Com_1Div6Duty_1Div3bias_TypeB_Max38Seg  = 5,
    /*!< */
    Lcd_6Com_1Div6Duty_1Div4bias_TypeA_Max38Seg  = 6,
    /*!< */
    Lcd_6Com_1Div6Duty_1Div4bias_TypeB_Max38Seg  = 7,
    
    /*!< 4 COM mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    Lcd_4Com_1Div2Duty_1Div2bias_TypeA_Max40Seg  = 8,
    /*!< */    
    Lcd_4Com_1Div2Duty_1Div2bias_TypeB_Max40Seg  = 9,
    /*!< */
    Lcd_4Com_1Div2Duty_1Div3bias_TypeA_Max40Seg  = 10,
    /*!< */    
    Lcd_4Com_1Div2Duty_1Div3bias_TypeB_Max40Seg  = 11,
    
    /*!< */
    Lcd_4Com_1Div3Duty_1Div2bias_TypeA_Max40Seg  = 12,
    /*!< */    
    Lcd_4Com_1Div3Duty_1Div2bias_TypeB_Max40Seg  = 13,
    /*!< */
    Lcd_4Com_1Div3Duty_1Div3bias_TypeA_Max40Seg  = 14,
    /*!< */    
    Lcd_4Com_1Div3Duty_1Div3bias_TypeB_Max40Seg  = 15,
    
    /*!< */
    Lcd_4Com_1Div4Duty_1Div3bias_TypeA_Max40Seg  = 16,
    /*!< */    
    Lcd_4Com_1Div4Duty_1Div3bias_TypeB_Max40Seg  = 17,
    /*!< */
    Lcd_4Com_1Div4Duty_1Div4bias_TypeA_Max40Seg  = 18,
    /*!< */    
    Lcd_4Com_1Div4Duty_1Div4bias_TypeB_Max40Seg  = 19,
    
    /*!< Static mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    Lcd_Com0_StaticMode_Max40Seg = 20,
    
  
}en_lcd_workmodesel_t;

/**
 ******************************************************************************
 ** \brief LCD internal R circuit configuration struct
 *****************************************************************************/
typedef struct
{
    /*!< LCD contrast select*/ 
    en_lcd_contrastsel_t    enLcdInRCirContrastSel;
    /*!< LCD Charge time select*/ 
    en_lcd_rchargtimsel_t   enLcdInRCirChargTimeSel;
    /*!< LCD Charge mode select*/ 
    en_lcd_rchargmodesel_t  enLcdInRCirChargModeSel;
       
}stc_lcd_inrcirconfigtypedef_t;

/**
 ******************************************************************************
 ** \brief LCD drive circuit configuration struct
 *****************************************************************************/
typedef struct
{
    /*!< LCD drive circuit select*/
    en_lcd_biascircuitsel_t  enLcdDriveCirSel;
    
    /*!< LCD drive circuit select EX R OR EX CAP appliction set*/
    union
    {
        /*!< LCD internal resistance、 external resistance、External capacitance circuit configuration*/    
        /*!< LCD internal R circuit configuration struct*/
        stc_lcd_inrcirconfigtypedef_t  stcLcdInRCirConfig;
        /*!< LCD external C circuit configuration struct*/
        en_lcd_capchargpumpchfresel_t  enLcdExCapChargPumpChFreqSel;
        /*!< LCD external R circuit configuration struct*/
        // none.
    };
         
}stc_lcd_drivecirconfigtypedef_t;

/******************************************************************************
 * Extern type definitions ('typedef')                                        *
 ******************************************************************************/

/**
 ******************************************************************************
 ** \brief LCD DDRAM struct
 *****************************************************************************/
/** 
  * @\brief LCD RAM0~39 struct
  *  ------------------------------------------------------------------------------
  * |地址： 0x014 ~ 0x03B                                                          |
  *  ------------------------------------------------------------------------------
  * |  Bit  |  Bit7  |  Bit6 |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
  * | Filed |  Bit7  |  Bit6 |  Bit5  |  Bit4  |  Bit3  |  Bit2  |  Bit1  |  Bit0  |
  * |  R/W  |  R/W   |  R/W  |  R/W   |   R/W  |   R/W  |   R/W  |   R/W  |   R/W  |
  * |Default|   0    |    0  |    0   |    0   |    0   |    0   |    0   |    0   |
  *  ------------------------------------------------------------------------------
  * 不同 COM 模式下， LCDRAM 各 bit 位与 COM/SEG 的对应关系如下所述。
  *  u8LcdRam00 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG0  |
  *  u8LcdRam01 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG1  |
  *  u8LcdRam02 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG2  |
  *      .      |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .    |
  *      .      |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .    |
  *      .      |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .   |  .    |
  *  u8LcdRam35 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG35 |
  *  u8LcdRam36 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG36 |
  *  u8LcdRam37 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG37 |
  *  u8LcdRam38 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG38 |
  *  u8LcdRam39 | bit7 | bit6 | bit5 | bit4 | bit3 | bit2 | bit1 | bit0 | SEG39 |
  *               COM7   COM6   COM5   COM4   COM3   COM2   COM1   COM0
  *             |             |             |      |      |      |<---->|Valid COM and bits of static mode
  *             |             |             |      |      |<----------->|Valid COM and bits of 1/2 duty
  *             |             |             |      |<------------------>|Valid COM and bits of 1/3 duty
  *             |             |             |<------------------------->|Valid COM and bits of 1/4 duty
  *             |             |<--------------------------------------->|Valid COM and bits of 1/6 duty
  *             |<----------------------------------------------------->|Valid COM and bits of 1/8 duty
  *  LCDRAM 各 bit 与 COM/SEG 对应关系 
  */
typedef struct
{
    volatile  uint8_t u8LcdRam00;     /*!< LCD RAM00 */
    volatile  uint8_t u8LcdRam01;     /*!< LCD RAM01 */
    volatile  uint8_t u8LcdRam02;     /*!< LCD RAM02 */
    volatile  uint8_t u8LcdRam03;     /*!< LCD RAM03 */
    volatile  uint8_t u8LcdRam04;     /*!< LCD RAM04 */
    volatile  uint8_t u8LcdRam05;     /*!< LCD RAM05 */
    volatile  uint8_t u8LcdRam06;     /*!< LCD RAM06 */
    volatile  uint8_t u8LcdRam07;     /*!< LCD RAM07 */
    volatile  uint8_t u8LcdRam08;     /*!< LCD RAM08 */
    volatile  uint8_t u8LcdRam09;     /*!< LCD RAM09 */
    volatile  uint8_t u8LcdRam10;     /*!< LCD RAM10 */
    volatile  uint8_t u8LcdRam11;     /*!< LCD RAM11 */
    volatile  uint8_t u8LcdRam12;     /*!< LCD RAM12 */
    volatile  uint8_t u8LcdRam13;     /*!< LCD RAM13 */
    volatile  uint8_t u8LcdRam14;     /*!< LCD RAM14 */
    volatile  uint8_t u8LcdRam15;     /*!< LCD RAM15 */
    volatile  uint8_t u8LcdRam16;     /*!< LCD RAM16 */
    volatile  uint8_t u8LcdRam17;     /*!< LCD RAM17 */
    volatile  uint8_t u8LcdRam18;     /*!< LCD RAM18 */
    volatile  uint8_t u8LcdRam19;     /*!< LCD RAM19 */
    volatile  uint8_t u8LcdRam20;     /*!< LCD RAM20 */
    volatile  uint8_t u8LcdRam21;     /*!< LCD RAM21 */
    volatile  uint8_t u8LcdRam22;     /*!< LCD RAM22 */
    volatile  uint8_t u8LcdRam23;     /*!< LCD RAM23 */
    volatile  uint8_t u8LcdRam24;     /*!< LCD RAM24 */
    volatile  uint8_t u8LcdRam25;     /*!< LCD RAM25 */
    volatile  uint8_t u8LcdRam26;     /*!< LCD RAM26 */
    volatile  uint8_t u8LcdRam27;     /*!< LCD RAM27 */
    volatile  uint8_t u8LcdRam28;     /*!< LCD RAM28 */
    volatile  uint8_t u8LcdRam29;     /*!< LCD RAM29 */
    volatile  uint8_t u8LcdRam30;     /*!< LCD RAM30 */
    volatile  uint8_t u8LcdRam31;     /*!< LCD RAM31 */
    volatile  uint8_t u8LcdRam32;     /*!< LCD RAM32 */
    volatile  uint8_t u8LcdRam33;     /*!< LCD RAM33 */
    volatile  uint8_t u8LcdRam34;     /*!< LCD RAM34 */
    volatile  uint8_t u8LcdRam35;     /*!< LCD RAM35 */
    volatile  uint8_t u8LcdRam36;     /*!< LCD RAM36 */
    volatile  uint8_t u8LcdRam37;     /*!< LCD RAM37 */
    volatile  uint8_t u8LcdRam38;     /*!< LCD RAM38 */
    volatile  uint8_t u8LcdRam39;     /*!< LCD RAM39 */

}stc_lcd_ramxxtypedef_t;

/**
 ******************************************************************************
 ** \brief LCD configuration struct
 *****************************************************************************/
typedef struct
{
    /*!< LCD clock selection*/
    en_lcd_display_clk_sel_t  enLcdDisplayClkSel;
    /*!< LCD frame refresh rate set*/
    en_lcd_framereratesel_t   enLcdFrameRerateSel;
    /*!< LCD working mode set,include com、bias、duty、waveform、set*/
    en_lcd_workmodesel_t      enLcdWorkModeSel;
    /*!< LCD drive circuit selection,include in R、 Ex R 、 Ex C、 Register (R03、R13、R23、R33、R43)driving voltagesetting*/
    stc_lcd_drivecirconfigtypedef_t  stcLcdDriveCircuitSel;        
    /*!< LCD COM、Seg i/o drive ability set*/
    en_lcd_drivepowsel_t      enLcdDrivePowerSel;
    
    /*u8LcdSe0~u8LcdSe4 Regist configuration */
    /*!< 8 COM mode, pin SEG0 ~ SEG35 as segment signal output pin*/
    /*!< 6 COM mode, pin SEG0 ~ SEG35, SEG38 and SEG39 as segment signal output pin.*/
    /*!< 4 COM mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    /*!< Static mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    /*!< SEG0~SEG7 SET*/
    union {
     volatile  uint8_t       u8Seg0_Seg7Config;
     stc_lcd_se0typedef_t    stcSeg0_Seg7Config;
    };
    /*!< SEG8~SEG15 SET*/
    union {
     volatile  uint8_t       u8Seg8_Seg15Config;
     stc_lcd_se1typedef_t    stcSeg8_Seg15Config;
    };
    /*!< SEG16~SEG23 SET*/
    union {
     volatile  uint8_t       u8Seg16_Seg23Config;
     stc_lcd_se2typedef_t    stcSeg16_Seg23Config;
    };
    /*!< SEG24~SEG31 SET*/
    union {
     volatile  uint8_t       u8Seg24_Seg31Config;
     stc_lcd_se3typedef_t    stcSeg24_Seg31Config;
    };
    /*!< SEG32~SEG39 SET*/
    union {
     volatile  uint8_t       u8Seg32_Seg39Config;
     stc_lcd_se4typedef_t    stcSeg32_Seg39Config;
    };
       
}stc_lcd_configtypedef_t;


/******************************************************************************
 * Local type definitions ('typedef')
 ******************************************************************************/
#ifndef ENABLE
        #define ENABLE TRUE             /*!< ENABLE DEFINE */
#endif

#ifndef DISABLE
        #define DISABLE FALSE           /*!< DISABLE DEFINE */
#endif

#ifndef LCDRAMSIZE
        #define LCDRAMSIZE  39          /*!< LCD RAM MAX SIZE */
#endif

#ifndef LCDRAMu8ListSIZE
        #define LCDRAMu8ListSIZE 7        /*!< LCD RAM u8List MAX SIZE */
#endif

#ifndef LCDFULLWRITE
        #define LCDFULLWRITE  0XFF      /*!< LCD RAM FULL WRITE 0XFF */
#endif

#ifndef LCDFULLCLEAR
        #define LCDFULLCLEAR  0X00      /*!< LCD RAM FULL WRITE 0X00 */
#endif

/******************************************************************************
 * Global variable definitions ('extern')                                     
 ******************************************************************************/

/******************************************************************************
 * Global function prototypes (definition in C source)                        
 ******************************************************************************/
/*LCD INTI--------------------------------------------------------------------*/
en_result_t Lcd_InitConfig(stc_lcd_configtypedef_t* pstcLcdInitconfig);
/*LCD ENABLE OR DISABLE-------------------------------------------------------*/
void Lcd_Cmd(boolean_t bNewState);
/*LCD FULL Write--------------------------------------------------------------*/
void Lcd_FullWrite(void);
/*LCD FULL Clear--------------------------------------------------------------*/
void Lcd_FullClear(void);
/*LCD Write RAM Index bit-----------------------------------------------------*/
en_result_t Lcd_WriteDdramIndexBit(uint8_t u8Row, uint8_t u8List, boolean_t bDate);
/*LCD Read RAM Index bit------------------------------------------------------*/
boolean_t Lcd_ReadDdramIndexBit(uint8_t u8Row, uint8_t u8List);
/*LCD Write RAM Index byte----------------------------------------------------*/
en_result_t LCD_WriteDdramIndexByte(uint8_t u8Row, uint8_t bData);
/*LCD Read RAM Index byte----------------------------------------------------*/
uint8_t LCD_ReadDdramIndexByte(uint8_t u8Row );


//@}
#ifdef __cplusplus
}
#endif

#endif /* __LCD_H__ */
/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/









