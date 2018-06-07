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
/** \file lcd.c
 **
 ** A detailed description is available at 
 ** @link LCDGroup LCD description @endlink
 **
 ** History:
 **   - 2016-10-31
 **
 ******************************************************************************/

/******************************************************************************/
/* Include files                                                              */
/******************************************************************************/
#include "lcd.h"

/*! LCD frame refresh rate select*/
#define   IS_VALID_FRAMERERATESEL(x)         ( LcdFrameReRateSel128Hz  == (x) ||\
                                               LcdFrameReRateSel256Hz  == (x) ||\
                                               LcdFrameReRateSel512Hz  == (x) ||\
                                               LcdFrameReRateSel1kHz   == (x) )

/*! LCD bias Settings*/
#define   IS_VALID_BIASSET(x)                ( LcdBiasSet1Div2   == (x) ||\
                                               LcdBiasSet1Div3   == (x) ||\
                                               Lcd_BiasSet1Div4  == (x) )

/*! LCD display mode select*/
#define   IS_VALID_DISMODESEL(x)             ( Lcd_DisModeSelStatic  == (x) ||\
                                               LcdDisModeSel2Per     == (x) ||\
                                               LcdDisModeSel3Per     == (x) ||\
                                               LcdDisModeSel4Per     == (x) ||\
                                               LcdDisModeSel6Per     == (x) ||\
                                               LcdDisModeSel8Per     == (x) )

/*! LCD contrast select*/
#define   IS_VALID_CONTRASTSEL(x)            ( LcdContrastSel60per  == (x) ||\
                                               LcdContrastSel65per  == (x) ||\
                                               LcdContrastSel70per  == (x) ||\
                                               LcdContrastSel75per  == (x) ||\
                                               LcdContrastSel80per  == (x) ||\
                                               LcdContrastSel85per  == (x) ||\
                                               LcdContrastSel90per  == (x) ||\
                                               LcdContrastSel100per == (x) )

/*! LCD Charge time select*/
#define   IS_VALID_RCHARGTIMSEL(x)           ( LcdRChargTimSel1Clk == (x) ||\
                                               LcdRChargTimSel2Clk == (x) ||\
                                               LcdRChargTimSel3Clk == (x) ||\
                                               LcdRChargTimSel4Clk == (x) ||\
                                               LcdRChargTimSel5Clk == (x) ||\
                                               LcdRChargTimSel6Clk == (x) ||\
                                               LcdRChargTimSel7Clk == (x) ||\
                                               LcdRChargTimSel8Clk == (x) )

/*! LCD Charge mode select*/
#define   IS_VALID_RCHARGMODESEL(x)          ( LcdRChargModeSelFast      == (x) ||\
                                               LcdRChargModeSelLargeCur  == (x) ||\
                                               LcdRChargModeSelSmallCur  == (x) )

/*! LCD capacitance charge pump Charging frequency select*/
#define   IS_VALID_CAPCHARGPUMPCHFRESEL(x)   ( ChargPumpChFreSel2kHz  == (x) ||\
                                               ChargPumpChFreSel4kHz  == (x) ||\
                                               ChargPumpChFreSel8kHz  == (x) ||\
                                               ChargPumpChFreSel16kHz == (x) )

/*! LCD bias circuit selection*/
#define   IS_VALID_BIASCIRCUITSEL(x)         ( LcdBiasCircuitSelInRes  == (x) ||\
                                               LcdBiasCircuitSelExCap  == (x) ||\
                                               LcdBiasCircuitSelExRes  == (x) )

/*! LCD drive power select*/
#define   IS_VALID_DRIVEPOWSEL(x)            ( LcdDrivePowSelNormal    == (x) ||\
                                               LcdDrivePowSel2Times    == (x) ||\
                                               LcdDrivePowSel3Times    == (x) ||\
                                               LcdDrivePowSel4Times    == (x) )
/*! LCD working mode select*/
#define   IS_VALID_WORKMODESEL(x)            ( Lcd_8Com_1Div8Duty_1Div3bias_TypeA_Max36Seg  == (x) ||\
                                               Lcd_8Com_1Div8Duty_1Div3bias_TypeB_Max36Seg  == (x) ||\
                                               Lcd_8Com_1Div8Duty_1Div4bias_TypeA_Max36Seg  == (x) ||\
                                               Lcd_8Com_1Div8Duty_1Div4bias_TypeB_Max36Seg  == (x) ||\
                                               Lcd_6Com_1Div6Duty_1Div3bias_TypeA_Max38Seg  == (x) ||\
                                               Lcd_6Com_1Div6Duty_1Div3bias_TypeB_Max38Seg  == (x) ||\
                                               Lcd_6Com_1Div6Duty_1Div4bias_TypeA_Max38Seg  == (x) ||\
                                               Lcd_6Com_1Div6Duty_1Div4bias_TypeB_Max38Seg  == (x) ||\
                                               Lcd_4Com_1Div2Duty_1Div2bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div2Duty_1Div2bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div2Duty_1Div3bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div2Duty_1Div3bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div3Duty_1Div2bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div3Duty_1Div2bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div3Duty_1Div3bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div3Duty_1Div3bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div4Duty_1Div3bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div4Duty_1Div3bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div4Duty_1Div4bias_TypeA_Max40Seg  == (x) ||\
                                               Lcd_4Com_1Div4Duty_1Div4bias_TypeB_Max40Seg  == (x) ||\
                                               Lcd_Com0_StaticMode_Max40Seg  == (x) )



/**
 ******************************************************************************
 ** \brief Lcd_InitConfig 
 **        According to the structure to initialize the LCD peripheral
 **        registers.
 ** 
 ** \param [IN] pstcLcdInitconfig   : LCD initialization structure entry
 ** address.
 ** 
 ** \retval en_result_t Ok: init done.
 **                     others: init failed.
 ******************************************************************************/
en_result_t Lcd_InitConfig(stc_lcd_configtypedef_t *pstcLcdInitconfig)
{
    /*!< The function returns the state*/
    en_result_t  enresult =  Error;
    /*!< Pointer to the LCD of the register variables*/
    volatile stc_lcdc_regtyptedef_t *pLCDReg = NULL;

    /*! Parameter detection*/
    ASSERT(NULL != pstcLcdInitconfig);
    ASSERT(IS_VALID_FRAMERERATESEL(pstcLcdInitconfig->enLcdFrameRerateSel));
    ASSERT(IS_VALID_BIASCIRCUITSEL(pstcLcdInitconfig->stcLcdDriveCircuitSel.enLcdDriveCirSel));
    ASSERT(IS_VALID_DRIVEPOWSEL(pstcLcdInitconfig->enLcdDrivePowerSel));
    ASSERT(IS_VALID_WORKMODESEL(pstcLcdInitconfig->enLcdWorkModeSel));

    /*For LCD base address register*/
    pLCDReg = M0P_LCDC;

    /*To determine whether a LCD register address*/
    if (pLCDReg == NULL)
    {
        enresult = ErrorInvalidParameter;
        /*Provided parameter is not valid*/
        return enresult;
    }

    /*!< Setting function state return variables*/
    enresult =  Ok;

    /*!< LCD Display CLOCK Select*/
    pLCDReg->LCDCR0_f.CLKSEL = pstcLcdInitconfig->enLcdDisplayClkSel;
    /*!< LCD frame refresh rate*/
    pLCDReg->LCDCR0_f.LCD_FRAME  = pstcLcdInitconfig->enLcdFrameRerateSel;

    /*!< LCD working mode set,include com、bias、duty、waveform、set*/
    switch (pstcLcdInitconfig->enLcdWorkModeSel)
    {
        /*!< 8 COM mode, pin SEG0 ~ SEG35 as segment signal output pin*/
        case Lcd_8Com_1Div8Duty_1Div3bias_TypeA_Max36Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = TRUE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = TRUE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel8Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_8Com_1Div8Duty_1Div3bias_TypeB_Max36Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = TRUE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = TRUE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel8Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;
            /*!< */
        case Lcd_8Com_1Div8Duty_1Div4bias_TypeA_Max36Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = TRUE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = TRUE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel8Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_8Com_1Div8Duty_1Div4bias_TypeB_Max36Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = TRUE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = TRUE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel8Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

            /*!< 6 COM mode, pin SEG0 ~ SEG35, SEG38 and SEG39 as segment signal output pin.*/
        case Lcd_6Com_1Div6Duty_1Div3bias_TypeA_Max38Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel6Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_6Com_1Div6Duty_1Div3bias_TypeB_Max38Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel6Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;
            /*!< */
        case Lcd_6Com_1Div6Duty_1Div4bias_TypeA_Max38Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel6Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_6Com_1Div6Duty_1Div4bias_TypeB_Max38Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = TRUE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = TRUE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel6Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

            /*!< 4 COM mode, pin SEG0 ~ SEG39 as segment signal output pin*/
        case Lcd_4Com_1Div2Duty_1Div2bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div2;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel2Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_4Com_1Div2Duty_1Div2bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div2;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel2Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;
            /*!< */
        case Lcd_4Com_1Div2Duty_1Div3bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel2Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_4Com_1Div2Duty_1Div3bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel2Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;
            /*!< */
        case Lcd_4Com_1Div3Duty_1Div2bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div2;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel3Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_4Com_1Div3Duty_1Div2bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div2;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel3Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;
            /*!< */
        case Lcd_4Com_1Div3Duty_1Div3bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel3Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_4Com_1Div3Duty_1Div3bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel3Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

            /*!< */
        case Lcd_4Com_1Div4Duty_1Div3bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/4 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel4Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;

            /*!< */
        case Lcd_4Com_1Div4Duty_1Div3bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div3;
            /*!< LCD display mode choice 1/4 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel4Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

            /*!< */
        case Lcd_4Com_1Div4Duty_1Div4bias_TypeA_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel4Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeA;

            break;
            /*!< */
        case Lcd_4Com_1Div4Duty_1Div4bias_TypeB_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = TRUE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = TRUE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = TRUE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = Lcd_BiasSet1Div4;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = LcdDisModeSel4Per;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

            /*!< Static mode, pin SEG0 ~ SEG39 as segment signal output pin*/
        case Lcd_Com0_StaticMode_Max40Seg:

            /*!< COME0 function select*/
            pLCDReg->LCDCE0_f.COME0 = TRUE;
            /*!< COME1 function select*/
            pLCDReg->LCDCE0_f.COME1 = FALSE;
            /*!< COME2 function select*/
            pLCDReg->LCDCE0_f.COME2 = FALSE;
            /*!< COME3 function select*/
            pLCDReg->LCDCE0_f.COME3 = FALSE;
            /*!< COME4 function select*/
            pLCDReg->LCDCE0_f.COME4 = FALSE;
            /*!< COME5 function select*/
            pLCDReg->LCDCE0_f.COME5 = FALSE;
            /*!< COME6 function select*/
            pLCDReg->LCDCE0_f.COME6 = FALSE;
            /*!< COME7 function select*/
            pLCDReg->LCDCE0_f.COME7 = FALSE;

            /*!< LCD bias Settings*/
            pLCDReg->LCDCR0_f.BIAS  = LcdBiasSet1Div2;
            /*!< LCD display mode choice 1/8 duty*/
            pLCDReg->LCDCR0_f.LCD_MODE  = Lcd_DisModeSelStatic;
            /*!< LCD driver waveform selection*/
            pLCDReg->LCDCR2_f.WSEL = LcdDrivWaveSelTypeB;

            break;

        default:
            enresult = ErrorInvalidParameter;
            /*Provided parameter is not valid*/
            return enresult;
    }

    /*!< LCD The LCD display circuit selection bias*/
    pLCDReg->LCDCR2_f.VSEL = pstcLcdInitconfig->stcLcdDriveCircuitSel.enLcdDriveCirSel;
    /*!< LCD drive circuit selection,include in R、 Ex R 、 Ex C、 Register (R03、R13、R23、R33、R43)driving voltagesetting*/
    switch (pstcLcdInitconfig->stcLcdDriveCircuitSel.enLcdDriveCirSel)
    {
        /*!< LCD bias circuit selection Internal resistance */
        case LcdBiasCircuitSelInRes:

            /*!< LCD contrast to choose*/
            pLCDReg->LCDCR1_f.VLCD = pstcLcdInitconfig->stcLcdDriveCircuitSel.stcLcdInRCirConfig.enLcdInRCirContrastSel;
            /*!< LCD Quick charge mode, small internal resistance charging time choice*/
            pLCDReg->LCDCR1_f.CT  = pstcLcdInitconfig->stcLcdDriveCircuitSel.stcLcdInRCirConfig.enLcdInRCirChargTimeSel;
            /*!< LCD When using internal resistance, charging mode selection*/
            pLCDReg->LCDCR1_f.CMOD = pstcLcdInitconfig->stcLcdDriveCircuitSel.stcLcdInRCirConfig.enLcdInRCirChargModeSel;

            /*!< Choose a R03 port function AS GPIO */
            pLCDReg->LCDDVC_f.VE0 =  FALSE;
            /*!< Choose a R13 port function AS GPIO*/
            pLCDReg->LCDDVC_f.VE1 =  FALSE;
            /*!< Choose a R23 port function AS GPIO*/
            pLCDReg->LCDDVC_f.VE2 =  FALSE;
            /*!< Choose a R33 port function AS GPIO*/
            pLCDReg->LCDDVC_f.VE3 =  FALSE;
            /*!< Choose a R43 port function AS GPIO*/
            pLCDReg->LCDDVC_f.VE4 =  FALSE;

            break;
            /*!< LCD bias circuit selection  external capacitance*/
        case LcdBiasCircuitSelExCap:

            /*!< LCD When using external capacitance, charge pump working frequency selection*/
            pLCDReg->LCDCR2_f.CP_FREQ = pstcLcdInitconfig->stcLcdDriveCircuitSel.enLcdExCapChargPumpChFreqSel;

            /*!< Choose a R03 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE0 =  TRUE;
            /*!< Choose a R13 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE1 =  TRUE;
            /*!< Choose a R23 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE2 =  TRUE;
            /*!< Choose a R33 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE3 =  TRUE;
            /*!< Choose a R43 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE4 =  TRUE;

            break;
            /*!< LCD bias circuit selection  external resistance*/
        case LcdBiasCircuitSelExRes:

            /*!< Choose a R03 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE0 =  TRUE;
            /*!< Choose a R13 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE1 =  TRUE;
            /*!< Choose a R23 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE2 =  TRUE;
            /*!< Choose a R33 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE3 =  TRUE;
            /*!< Choose a R43 port function AS LCD drive voltage input*/
            pLCDReg->LCDDVC_f.VE4 =  TRUE;

            break;

        default:
            enresult = ErrorInvalidParameter;
            /*Provided parameter is not valid*/
            return enresult;
    }

    /*!< LCD COM、Seg i/o drive ability set*/
    pLCDReg->LCDCR3_f.LCD_BUF = pstcLcdInitconfig->enLcdDrivePowerSel;

    /*u8LcdSe0~u8LcdSe4 Regist configuration */
    /*!< 8 COM mode, pin SEG0 ~ SEG35 as segment signal output pin*/
    /*!< 6 COM mode, pin SEG0 ~ SEG35, SEG38 and SEG39 as segment signal output pin.*/
    /*!< 4 COM mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    /*!< Static mode, pin SEG0 ~ SEG39 as segment signal output pin*/
    /*!< SEG0~SEG7 SET*/
    pLCDReg->LCDSE0 = pstcLcdInitconfig->u8Seg0_Seg7Config;
    pLCDReg->LCDSE0_f.SEGE0 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE0;
    pLCDReg->LCDSE0_f.SEGE1 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE1;
    pLCDReg->LCDSE0_f.SEGE2 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE2;
    pLCDReg->LCDSE0_f.SEGE3 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE3;
    pLCDReg->LCDSE0_f.SEGE4 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE4;
    pLCDReg->LCDSE0_f.SEGE5 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE5;
    pLCDReg->LCDSE0_f.SEGE6 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE6;
    pLCDReg->LCDSE0_f.SEGE7 = pstcLcdInitconfig->stcSeg0_Seg7Config.SEGE7;

    /*!< SEG8~SEG15 SET*/
    pLCDReg->LCDSE1 = pstcLcdInitconfig->u8Seg8_Seg15Config;
    pLCDReg->LCDSE1_f.SEGE8  = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE8;
    pLCDReg->LCDSE1_f.SEGE9  = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE9;
    pLCDReg->LCDSE1_f.SEGE10 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE10;
    pLCDReg->LCDSE1_f.SEGE11 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE11;
    pLCDReg->LCDSE1_f.SEGE12 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE12;
    pLCDReg->LCDSE1_f.SEGE13 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE13;
    pLCDReg->LCDSE1_f.SEGE14 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE14;
    pLCDReg->LCDSE1_f.SEGE15 = pstcLcdInitconfig->stcSeg8_Seg15Config.SEGE15;

    /*!< SEG16~SEG23 SET*/
    pLCDReg->LCDSE2 = pstcLcdInitconfig->u8Seg16_Seg23Config;
    pLCDReg->LCDSE2_f.SEGE16 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE16;
    pLCDReg->LCDSE2_f.SEGE17 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE17;
    pLCDReg->LCDSE2_f.SEGE18 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE18;
    pLCDReg->LCDSE2_f.SEGE19 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE19;
    pLCDReg->LCDSE2_f.SEGE20 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE20;
    pLCDReg->LCDSE2_f.SEGE21 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE21;
    pLCDReg->LCDSE2_f.SEGE22 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE22;
    pLCDReg->LCDSE2_f.SEGE23 = pstcLcdInitconfig->stcSeg16_Seg23Config.SEGE23;

    /*!< SEG24~SEG31 SET*/
    pLCDReg->LCDSE3 = pstcLcdInitconfig->u8Seg24_Seg31Config;
    pLCDReg->LCDSE3_f.SEGE24 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE24;
    pLCDReg->LCDSE3_f.SEGE25 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE25;
    pLCDReg->LCDSE3_f.SEGE26 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE26;
    pLCDReg->LCDSE3_f.SEGE27 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE27;
    pLCDReg->LCDSE3_f.SEGE28 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE28;
    pLCDReg->LCDSE3_f.SEGE29 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE29;
    pLCDReg->LCDSE3_f.SEGE30 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE30;
    pLCDReg->LCDSE3_f.SEGE31 = pstcLcdInitconfig->stcSeg24_Seg31Config.SEGE31;

    /*!< SEG32~SEG39 SET*/
    pLCDReg->LCDSE4 = pstcLcdInitconfig->u8Seg32_Seg39Config;
    pLCDReg->LCDSE4_f.SEGE32 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE32;
    pLCDReg->LCDSE4_f.SEGE33 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE33;
    pLCDReg->LCDSE4_f.SEGE34 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE34;
    pLCDReg->LCDSE4_f.SEGE35 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE35;
    pLCDReg->LCDSE4_f.SEGE36 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE36;
    pLCDReg->LCDSE4_f.SEGE37 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE37;
    pLCDReg->LCDSE4_f.SEGE38 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE38;
    pLCDReg->LCDSE4_f.SEGE39 = pstcLcdInitconfig->stcSeg32_Seg39Config.SEGE39;

    return  enresult;
}


/**
 ******************************************************************************
 ** \brief Lcd_Cmd 
 **        LCD Enable or Disamble.
 ** 
 ** \param [IN] bNewState   : ENABLE OR DISABLE.
 ** 
 ** \retval void 
 ******************************************************************************/
void Lcd_Cmd(boolean_t bNewState)
{
    /*!< LCD Enable*/
    M0P_LCDC->LCDCR3_f.LCD_EN = bNewState;
}


/**
 ******************************************************************************
 ** \brief Lcd_FullWrite 
 **        LCD FULL display.
 ** \param [IN]     : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Lcd_FullWrite(void)
{
    volatile uint8_t *ptemp = NULL;
    int i = 0;

    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< All members of the assignment*/
    for (i = 0; i <= LCDRAMSIZE; i++)
    {
        *ptemp = LCDFULLWRITE;
        ptemp++;
    }

}


/**
 ******************************************************************************
 ** \brief Lcd_FullClear 
 **        LCD FULL Clear.
 ** \param [IN]     : 
 ** 
 ** \retval void 
 ******************************************************************************/
void Lcd_FullClear(void)
{
    int i = 0;
    volatile uint8_t *ptemp = NULL;
    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< All members of the assignment*/
    for (i = 0; i <= LCDRAMSIZE; i++)
    {
        *ptemp = LCDFULLCLEAR;
        ptemp++;
    }
}


/**
 ******************************************************************************
 ** \brief Lcd_WriteDdramIndexBit 
 **        LCD Write the specified bit in the DDRAM.
 ** 
 ** \param [IN] u8Row   : 0~39, RAM00~RAM39
 ** \param [IN] u8List  : 0~7, bit0~bit7
 ** \param [IN] bDate   : 1 or 0,
 ** 
 ** \retval en_result_t Ok: write done.
 **                     others: write failed.
 ******************************************************************************/
en_result_t Lcd_WriteDdramIndexBit(uint8_t u8Row, uint8_t u8List, boolean_t bDate)
{
    /*!< Define function returns the state variables*/
    en_result_t  enresult = Error;
    /*!< Define a pointer variable*/
    volatile uint8_t *ptemp = NULL;

    /*!< Determine whether the input parameters conform to the limit*/
    if ((u8Row > LCDRAMSIZE) || (u8List > LCDRAMu8ListSIZE))
    {
        enresult = ErrorInvalidParameter;
        return enresult;
    }
    /*!< set function returns state */
    enresult = Ok;
    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< Point to modify LCDRAM u8Row*/
    ptemp += u8Row;

    if (bDate == TRUE)
    {
        /*!< SET bit*/
        *ptemp |= (uint8_t)(bDate << u8List);
    } else
    {
        /*!< clear bit*/
        *ptemp &= (uint8_t)(bDate << u8List);
    }

    return  enresult;

}


/**
 ******************************************************************************
 ** \brief Lcd_ReadDdramIndexBit 
 **        LCD Read the specified bit in the DDRAM.
 ** 
 ** \param [IN] u8Row   : 0~39, RAM00~RAM39
 ** \param [IN] u8List  : 0~7, bit0~bit7
 ** 
 ** \retval boolean_t   the read data.
 ******************************************************************************/
boolean_t Lcd_ReadDdramIndexBit(uint8_t u8Row, uint8_t u8List)
{
    /*!< Define a pointer variable*/
    volatile uint8_t *ptemp = NULL;
    uint8_t temp = 0;

    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< Point to modify LCDRAM u8Row*/
    ptemp += u8Row;
    /*!< Get the specified bit data*/
    temp = (0x0u | (1u << u8List));
    temp &= (*ptemp);
    temp = temp >> u8List;

    /*!< retern data*/
    return  (boolean_t)temp;

}


/**
 ******************************************************************************
 ** \brief LCD_WriteDdramIndexByte 
 **        LCD Write the specified bit in the DDRAM.
 ** 
 ** \param [IN] u8Row   : 0~39
 ** \param [IN] bData   : Write data
 ** 
 ** \retval en_result_t Ok: write done.
 **                     others: write failed.
 ******************************************************************************/
en_result_t LCD_WriteDdramIndexByte(uint8_t u8Row, uint8_t bData)
{
    /*!< Define function returns the state variables*/
    en_result_t  enresult = Error;
    /*!< Define a pointer variable*/
    volatile uint8_t *ptemp = NULL;

    /*!< Determine whether the input parameters conform to the limit*/
    if (u8Row > LCDRAMSIZE)
    {
        enresult = ErrorInvalidParameter;
        return enresult;
    }
    /*!< set function returns state */
    enresult = Ok;
    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< Point to modify LCDRAM u8Row*/
    ptemp += u8Row;
    /*!< Write a specified byte*/
    *ptemp = bData;

    return  enresult;
}


/**
 ******************************************************************************
 ** \brief LCD_ReadDdramIndexByte 
 **        LCD Write the specified bit in the DDRAM.
 ** 
 ** \param [IN] u8Row   : 0~39
 ** 
 ** \retval uint8_t  read data.
 ******************************************************************************/
uint8_t LCD_ReadDdramIndexByte(uint8_t u8Row)
{
    /*!< Define a pointer variable*/
    volatile uint8_t *ptemp = NULL;

    /*!< get LCD_RAMXX u8LcdRam00 Address*/
    ptemp = &M0P_LCDC->LCDRAM00;
    /*!< Point to modify LCDRAM u8Row*/
    ptemp += u8Row;

    return  (*ptemp);
}

//@} // LCD Functions

/******************************************************************************/
/* EOF (not truncated)                                                        */
/******************************************************************************/

