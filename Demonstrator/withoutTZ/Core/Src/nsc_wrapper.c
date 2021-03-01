/*
 * nsc_wrapper.c
 *
 *  Created on: Feb 28, 2021
 *      Author: F. Pilz
 */

#include "nsc_wrapper.h"
#include "CtoCpp_callable.h"

void SECURE_LEDS_setGreen(uint8_t brightness){
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(r, brightness, b);
}

void SECURE_LEDS_setRed(uint8_t brightness){
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(brightness, g, b);
}

void SECURE_LEDS_setBlue(uint8_t brightness){
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(r, g, brightness);
}
