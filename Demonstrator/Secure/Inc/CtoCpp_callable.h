#ifndef C_TO_CPP_H
#define C_TO_CPP_H

#include "stm32l5xx_nucleo.h"

void initLEDController(
    GPIO_TypeDef*   GPIOx, 
    uint16_t        GPIO_Pin_data,
    uint16_t        GPIO_Pin_clock
);
void initLEDController_default();

void LEDController_setColor(
    uint8_t r,
    uint8_t g,
    uint8_t b
);
struct RGB LEDController_getColor();

struct RGB
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};


#endif
