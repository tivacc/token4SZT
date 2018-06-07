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
/*****************************************************************************/
/** \file Gpio.c
 **
 ** GPIO driver API.
 ** @link Driver Group Some description @endlink
 **
 **   - 2016-02-16  1.0  QianCP First version for Device Driver Library of
 **                         Module.
 **
 *****************************************************************************/

/******************************************************************************
 * Include files
 *****************************************************************************/
#include "gpio.h"

/**
 ******************************************************************************
 ** \addtogroup GPIO Group
 *****************************************************************************/
//@{

/******************************************************************************
 * Local pre-processor symbols/macros ('#define')
 *****************************************************************************/

/******************************************************************************
 * Global variable definitions (declared in header file with 'extern')        *
 *****************************************************************************/

/******************************************************************************
 * Local type definitions ('typedef')
 *****************************************************************************/

/******************************************************************************
 * Local function prototypes ('static')
 *****************************************************************************/

/******************************************************************************
 * Local variable definitions ('static')
 *****************************************************************************/

/******************************************************************************
 * Function implementation - global ('extern') and local ('static')
 *****************************************************************************/

/**
 * \brief   Gpio_SetAnalog
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port
 * \param   [in]  bFlag              TRUE :     set to analog mode
 *                                   FALSE:     set to GPIO mode
 *
 * \retval  en_result_t               OK    - set done.
 */
en_result_t Gpio_SetAnalog(uint8_t u8Port, uint8_t u8Pin, boolean_t bFlag)
{
    en_result_t enRet = Ok;

    if ((0 == u8Port) && (0 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE00 = bFlag;
    }
    else if ((0 == u8Port) && (1 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE01 = bFlag;
    }
    else if ((0 == u8Port) && (2 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE02 = bFlag;}
    else if ((0 == u8Port) && (3 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE03 = bFlag;}
    else if ((6 == u8Port) && (0 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE04 = bFlag;}
    else if ((6 == u8Port) && (1 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE05 = bFlag;}
    else if ((6 == u8Port) && (2 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE06 = bFlag;}
    else if ((6 == u8Port) && (3 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE07 = bFlag;}
    else if ((5 == u8Port) && (0 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE08 = bFlag;}
    else if ((5 == u8Port) && (1 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE09 = bFlag;}
    else if ((5 == u8Port) && (2 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE10 = bFlag;}
    else if ((5 == u8Port) && (3 == u8Pin))
    {
        bM0P_GPIO_ANALOG_ADE11 = bFlag;}
    else
    {
        enRet = ErrorInvalidParameter;
    }
    return enRet;
}

/**
 * \brief   Gpio_InitIO
 *
 * \param   [in]  u8Port                GPIO port index
 * \param   [in]  u8Pin                 pin offset in a port
 * \param   [in]  enDir                 enGpioDirIn/enGpioDirOut
 * \param   [in]  bPullup               pull up
 * \param   [in]  bOdr                  open drain
 *
 * \retval  en_result_t                 Ok
 */
en_result_t Gpio_InitIO(uint8_t u8Port, uint8_t u8Pin,
                        en_Gpio_dir_t enDir, boolean_t bPullup,
                        boolean_t bOdr)
{
    uint32_t u32Offset = 0;

    // force set mode, ignore result.
    Gpio_SetAnalog(u8Port, u8Pin, FALSE);

    u32Offset = u8Port;
    u32Offset = u32Offset << 0x7;
    u32Offset = u32Offset + ((uint32_t)u8Pin << 0x2u);

    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_FN0_P00 + u32Offset)) = 0u;
    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_DIR0_P00 + u32Offset)) = (uint32_t)enDir;
    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_PU0_P00 + u32Offset)) = bPullup;
    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_ODR0_P00 + u32Offset)) = bOdr;
    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_FSETE0_P00 + u32Offset)) = 0u;

    return Ok;
}

/**
 * \brief   Gpio_SetIO
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port
 * \param   [in]  bVal               1  - high
 *                                   0  - low
 * \retval  void
 */
void Gpio_SetIO(uint8_t u8Port, uint8_t u8Pin, boolean_t bVal)
{
    uint32_t u32Offset = u8Port * 0x80 + u8Pin * 0x4;

    *((volatile uint32_t *)((uint32_t)&bM0P_GPIO_SET0_P00 + u32Offset)) = bVal;
}

/**
 * \brief   Gpio_GetIO
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port

 * \retval  boolean_t                1  - high
 *                                   0  - low
 */
boolean_t Gpio_GetIO(uint8_t u8Port, uint8_t u8Pin)
{
    uint32_t u32Offset = u8Port * 0x80 + u8Pin * 0x4;

    return *((uint32_t *)((uint32_t)&bM0P_GPIO_GET0_P00 + u32Offset));
}

/**
 * \brief   FGpio_InitIO
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port
 * \param   [in]  enDir              dummy code
 * \retval  void
 */
en_result_t FGpio_InitIO(uint8_t u8Port, uint8_t u8Pin, en_Gpio_dir_t enDir)
{
    en_result_t enRet = Ok;
    uint32_t u32Offset = 0;

    //ignore analog result.
    enRet = Gpio_SetAnalog(u8Port, u8Pin, FALSE);

    u32Offset = u8Port * 0x80 + u8Pin * 0x4;

    ///< \todo why dir can't set IN?

    *((uint32_t *)((uint32_t)&bM0P_GPIO_FN0_P00 + u32Offset)) = 0u;
    *((uint32_t *)((uint32_t)&bM0P_GPIO_DIR0_P00 + u32Offset)) = enDir;
    *((uint32_t *)((uint32_t)&bM0P_GPIO_FSETE0_P00 + u32Offset)) = 1u;

    return enRet;
}

/**
 * \brief   FGpio_GetIO
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port
 *
 * \retval  boolean_t
 */
boolean_t FGpio_GetIO(uint8_t u8Port, uint8_t u8Pin)
{
    uint8_t u8Val = 0;
    u8Val = *((volatile uint8_t *)(((uint32_t)&M0P_FASTIO->FGET0) + ((uint32_t)u8Port << 0x2)));

    return (u8Val >> u8Pin) & 1u;
}

/**
 * \brief   FGpio_SetIO
 *
 * \param   [in]  u8Port             GPIO port index
 * \param   [in]  u8Pin              pin offset in a port
 * \param   [in]  bVal               1  - high
 *                                   0  - low
 * \retval  void
 */
void FGpio_SetIO(uint8_t u8Port, uint8_t u8Pin, boolean_t bVal)
{
    uint8_t u8Val = 0u;
    volatile uint8_t *pu8Addr = NULL;

    pu8Addr = (volatile uint8_t *)((uint32_t)&M0P_FASTIO->FSET0 + u8Port * 0x4);
    u8Val = *pu8Addr;
    u8Val = u8Val & ~(0x1u << u8Pin);
    u8Val = u8Val | (uint8_t)(bVal<< u8Pin);

    *pu8Addr = u8Val;
}


//@} // Gpio Group


/******************************************************************************
 * EOF (not truncated)
 *****************************************************************************/

