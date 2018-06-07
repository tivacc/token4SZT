#ifndef _TOKEN_BSP_H_
#define _TOKEN_BSP_H_

#include "gpio.h"
#include "typedef.h"

#define SPI_SPEED 		0x02

#define KEY_UP_PORT	2
#define KEY_UP_PIN 	3

#define KEY_DOWN_PORT	2
#define KEY_DOWN_PIN 	4

void bspConfig(void) ;

#endif

