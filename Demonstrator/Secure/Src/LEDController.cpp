#include "LEDController.hpp"
#include "CtoCpp_callable.h"


void SecureLEDController::writeColor(){

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

SecureLEDController::SecureLEDController(P9813DATA p9813data){
	configureP9813AsSecure(p9813data);
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
    type=p9813;
}
SecureLEDController::SecureLEDController(LEDPINDATA led_pins){
	//TODO
		BSP_LED_Init(LED3);
		BSP_LED_Init(LED2);
		BSP_LED_Init(LED1);
    type=onBoard;
}
SecureLEDController::SecureLEDController(P9813DATA p9813data,LEDPINDATA led_pins){
	configureP9813AsSecure(p9813data);
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
	//TODO
		BSP_LED_Init(LED3);
		BSP_LED_Init(LED2);
		BSP_LED_Init(LED1);
    type=both;
}

bool SecureLEDController::setRGB(
	uint8_t r,
	uint8_t g,
	uint8_t b
){
	this->r=r;this->g=g;this->b=b;
	writeColor();
	return SUCCESS;
}

void SecureLEDController::configureP9813AsSecure(P9813DATA p9813data){
  	HAL_GPIO_ConfigPinAttributes(p9813data.GPIOx, (GPIO_PIN_All & ~(p9813data.GPIO_Pin_data) & ~(p9813data.GPIO_Pin_clock)), GPIO_PIN_NSEC);
}




SecureLEDController ledc;

//To be callable from standard C

extern "C" {

void initLEDController(
    GPIO_TypeDef*   GPIOx, 
    uint16_t        GPIO_Pin_data,
    uint16_t        GPIO_Pin_clock
){
	P9813DATA p9813data = {GPIOx, GPIO_Pin_data, GPIO_Pin_clock};
	ledc = SecureLEDController(p9813data);
}
void initLEDController_default(){
	P9813DATA p9813data = {GPIOD, GPIO_PIN_6, GPIO_PIN_7};
	ledc = SecureLEDController(p9813data,LEDPINDATA{});
}

void LEDController_setColor(
    uint8_t r,
    uint8_t g,
    uint8_t b
){
	ledc.setRGB(r,g,b);
}

}
