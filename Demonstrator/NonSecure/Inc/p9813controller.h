#ifndef P9813CONTROLLER_H
#define P9813CONTROLLER_H


class LEDController{
  private:
    uint8_t r;
    uint8_t g;
    uint8_t b;

    GPIO_TypeDef *GPIOx;
    GPIO_Pin_data dataPIN;
    GPIO_Pin_data clockPIN;

    uint32_t bgr;
    uint32_t sequence;

    void send32bitSequence(uint32_t sequence);
    void writeColor();

  public:
    /**
      * @brief  create LED Strip Controller
      * @note   ----
      * @param  GPIOx where x can be (A..H) to select the GPIO peripheral for STM32L5 family
      * @param  GPIO_Pin_data specifies the pin to the p9813 data line
      * @param  GPIO_Pin_clock specifies the pin to the p9813 clock line
      * @retval LEDController
      */
    LEDController(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock);
    ~LEDController(){}

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
