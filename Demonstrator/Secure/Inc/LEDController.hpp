#ifndef SecureLEDController_HPP
#define SecureLEDController_HPP

extern "C"{
#include "stm32l5xx_nucleo.h"
}
#include "p9813controller.hpp"

struct P9813DATA {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin_data; 
    uint16_t GPIO_Pin_clock;
};
struct LEDPINDATA {
    //TODO
};

enum LEDTYPE { p9813, onBoard, both };

class SecureLEDController{
  private:
      LEDTYPE type;
      uint8_t r;
      uint8_t g;
      uint8_t b;

      P9813Controller p9813controller;

      void writeColor();

  public:
    /**
      * @brief  create LED Strip and onBoard Controller
      * @note   ----
      * @retval SecureLEDController
      */
    SecureLEDController(P9813DATA p9813data);
    SecureLEDController(LEDPINDATA led_pins);
    SecureLEDController(P9813DATA p9813data,LEDPINDATA led_pins);
    ~SecureLEDController(){}

    /**
      * @brief  Set an RGB color value to the RGB-Strip
      * @note   ----
      * @param  r color RED (values betwwen 0 no red and 255 fully red)
      * @param  g colorvalue GREEN
      * @param  b colorvalue BLUE
      * @retval success or not
      */
    bool setRGB(
      uint8_t r,
      uint8_t g,
      uint8_t b
    );
};

#endif
