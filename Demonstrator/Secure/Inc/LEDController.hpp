#ifndef SecureLEDController_HPP
#define SecureLEDController_HPP

extern "C"{
  #include "stm32l5xx_nucleo.h"
  #include "CtoCpp_callable.h"
}
#include "p9813controller.hpp"

struct P9813DATA {
    GPIO_TypeDef *GPIOx;
    uint16_t GPIO_Pin_data; 
    uint16_t GPIO_Pin_clock;
};
struct LEDPINDATA {
    GPIO_TypeDef *GPIOx_R;
    uint16_t GPIO_Pin_Red;

    GPIO_TypeDef *GPIOx_G;
    uint16_t GPIO_Pin_Green;

    GPIO_TypeDef *GPIOx_B;
    uint16_t GPIO_Pin_Blue; 
};

enum LEDTYPE { p9813, onBoard, both };

class SecureLEDController{
  private:
      LEDTYPE type;
      uint8_t r = 0;
      uint8_t g = 0;
      uint8_t b = 0;

      P9813Controller p9813controller;

      void writeColor();
    /* We don't need to use these functions, if we don't use TrustZone */
    void configureP9813AsSecure(P9813DATA p9813data);
    void configureNormalLEDsAsSecure(LEDPINDATA pindata);

  public:
    /**
      * @brief  create LED Strip and onBoard Controller
      * @note   ----
      * @retval SecureLEDController
      */
    SecureLEDController(P9813DATA p9813data);
    SecureLEDController(LEDPINDATA led_pins);
    SecureLEDController(P9813DATA p9813data,LEDPINDATA led_pins);
    SecureLEDController(){}
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
    bool setRGB(RGB);
    RGB getRGB(){return {r,g,b};}
};

#endif
