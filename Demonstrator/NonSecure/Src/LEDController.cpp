#include "ledcontroller.hpp"

extern "C"{
#include "constant.h"
#include "cmsis_os.h"
#include "stm32l5xx_nucleo.h"
}

void LEDController::writeColor(){

    if(type!=onBoard){
        p9813controller.setRGB(r,g,b);
    }
    if(type!=p9813){
        //TODO: Write to onBoard LEDS
    }
}

LEDController::LEDController(P9813DATA p9813data){
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
    type=p9813;
}
LEDController::LEDController(LEDPINDATA led_pins){
	//TODO
    type=onBoard;
}
LEDController::LEDController(P9813DATA p9813DATA,LEDPINDATA led_pins){
	p9813controller=P9813Controller(p9813DATA.GPIOx,p9813DATA.GPIO_Pin_data,p9813DATA.GPIO_Pin_clock);
    //TODO
    type=both;
}

bool LEDController::setRGB(
	uint8_t r,
	uint8_t g,
	uint8_t b
){
	this->r=r;this->g=g;this->b=b;
	writeColor();
	return SUCCESS;
}
