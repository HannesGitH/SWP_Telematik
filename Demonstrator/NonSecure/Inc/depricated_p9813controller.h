#ifndef P9813CONTROLLER_H
#define P9813CONTROLLER_H

#include "stm32l5xx_nucleo.h"

    /**
      * @brief  create LED Strip Controller
      * @note   ----
      * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L5 family
      * @param  GPIO_Pin_data specifies the pin to the p9813 data line
      * @param  GPIO_Pin_clock specifies the pin to the p9813 clock line
      * @retval P9813Controller
      */
    void P9813Controller__initialize(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock);

    /**
      * @brief  Set an RGB color value to the RGB-Strip
      * @note   ----
      * @param  r color RED (values betwwen 0 no red and 255 fully red)
      * @param  g colorvalue GREEN
      * @param  b colorvalue BLUE
      * @retval success or not
      */
    int P9813Controller__setRGB(
      uint8_t r,
      uint8_t g,
      uint8_t b
    );

#endif
