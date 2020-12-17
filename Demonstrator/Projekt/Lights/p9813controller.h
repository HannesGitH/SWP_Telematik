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
    LEDController(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock);
    ~LEDController(){}
    bool setRGB(
      uint8_t r,
      uint8_t g,
      uint8_t b
    );
};

#endif
