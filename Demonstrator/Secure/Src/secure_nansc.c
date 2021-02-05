
#include "secure_nansc.h"
#include "CtoCpp_callable.h"

//Not working if TZEN=1 cause it doesnt get the secure Context via 
CMSE_NS_ENTRY void SECURE_LEDS_setRed(uint8_t brightness){
	HAL_ResumeTick();
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(brightness, g, b);
    HAL_SuspendTick();
}
void SECURE_LEDS_setBlue(uint8_t brightness){
	HAL_ResumeTick();
    struct RGB currentColor = LEDController_getColor();
    uint8_t r = currentColor.r;
    uint8_t g = currentColor.g;
    uint8_t b = currentColor.b;
    LEDController_setColor(r, g, brightness);
    HAL_SuspendTick();
}
