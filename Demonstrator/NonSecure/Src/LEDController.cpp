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
        //TODO make it actually work (pwm?)
        //this is just 4 debugging
        if(r>127){
            BSP_LED_On(LED3);
        }else{
            BSP_LED_Off(LED3);
        }
        if(b>127){
			BSP_LED_On(LED2);
		}else{
			BSP_LED_Off(LED2);
		}
        if(b>127){
			BSP_LED_On(LED1);
		}else{
			BSP_LED_Off(LED1);
		}
        
    }
}

LEDController::LEDController(P9813DATA p9813data){
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
    type=p9813;
}
LEDController::LEDController(LEDPINDATA led_pins){
	//TODO
		BSP_LED_Init(LED3);
		BSP_LED_Init(LED2);
		BSP_LED_Init(LED1);
    type=onBoard;
}
LEDController::LEDController(P9813DATA p9813DATA,LEDPINDATA led_pins){
	p9813controller=P9813Controller(p9813DATA.GPIOx,p9813DATA.GPIO_Pin_data,p9813DATA.GPIO_Pin_clock);
	//TODO
		BSP_LED_Init(LED3);
		BSP_LED_Init(LED2);
		BSP_LED_Init(LED1);
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
