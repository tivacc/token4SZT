#ifndef _PAPER_DRV_
#define _PAPER_DRV_

#include "gpio.h"
#include "typedef.h"



#define SPI_SPEED 		0x02

#define PAPER_MOSI_PORT	0
#define PAPER_MOSI_PIN 	1

#define PAPER_CLK_PORT	0
#define PAPER_CLK_PIN	2

#define PAPER_CS_PORT	0
#define PAPER_CS_PIN	0

#define PAPER_DC_PORT	0
#define PAPER_DC_PIN	6

#define PAPER_RST_PORT	0
#define PAPER_RST_PIN	5

#define PAPER_BUSY_PORT	0
#define PAPER_BUSY_PIN	4


#define EPD_W21_MOSI_0	  Gpio_SetIO(PAPER_MOSI_PORT, PAPER_MOSI_PIN, 0)
#define EPD_W21_MOSI_1	  Gpio_SetIO(PAPER_MOSI_PORT, PAPER_MOSI_PIN, 1)

#define EPD_W21_CLK_0	  Gpio_SetIO(PAPER_CLK_PORT, PAPER_CLK_PIN, 0)
#define EPD_W21_CLK_1	  Gpio_SetIO(PAPER_CLK_PORT, PAPER_CLK_PIN, 1)

#define EPD_W21_CS_0	  Gpio_SetIO(PAPER_CS_PORT, PAPER_CS_PORT, 0)
#define EPD_W21_CS_1	  Gpio_SetIO(PAPER_CS_PORT, PAPER_CS_PORT, 1)

#define EPD_W21_DC_0	  Gpio_SetIO(PAPER_DC_PORT, PAPER_DC_PIN, 0)
#define EPD_W21_DC_1	  Gpio_SetIO(PAPER_DC_PORT, PAPER_DC_PIN, 1)

#define EPD_W21_RST_0	  Gpio_SetIO(PAPER_RST_PORT, PAPER_RST_PIN, 0)
#define EPD_W21_RST_1	  Gpio_SetIO(PAPER_RST_PORT, PAPER_RST_PIN, 1)

#define isEPD_W21_BUSY    Gpio_GetIO(PAPER_BUSY_PORT, PAPER_BUSY_PIN)


void paperIOInit(void);
void EPD_W21_Init(void);


void EPD_display_init(void);
void full_display(void pic_display(void));
void partial_display(u16 x_start,u16 x_end,u16 y_start,u16 y_end ,void partial_old(void),void partial_new(void));
void partial_display_dynam(u16 x_start,u16 x_end,u16 y_start,u16 y_end ,void partial_old(void),unsigned char dataLen,unsigned char *playData,void partial_new(unsigned char ,unsigned char *));

void deep_sleep(void); 

void lut(void);
void lut1(void);
void lcd_chkstatus(void);

//
void lcd_full00(void);
void lcd_white(void);
void lcdDisInfo(void);


#endif
