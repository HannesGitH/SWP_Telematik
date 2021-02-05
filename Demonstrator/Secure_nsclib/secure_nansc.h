#ifndef NANSC
#define NANSC

#include "stm32l5xx_nucleo.h"
#include <stdio.h>

//callable but not runnable
void SECURE_LEDS_setRed(uint8_t brightness);
void SECURE_LEDS_setBlue(uint8_t brightness);

#endif
