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
        if(g>127){
			BSP_LED_On(LED1);
		}else{
			BSP_LED_Off(LED1);
		}
        if(b>127){
			BSP_LED_On(LED2);
		}else{
			BSP_LED_Off(LED2);
		}
        
    }
}

SecureLEDController::SecureLEDController(P9813DATA p9813data){
	#ifndef NONSECURE
	configureP9813AsSecure(p9813data);
	#endif
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
    type=p9813;
}
SecureLEDController::SecureLEDController(LEDPINDATA led_pins){
	#ifndef NONSECURE
	configureNormalLEDsAsSecure(led_pins);
	#endif
    type=onBoard;
}
SecureLEDController::SecureLEDController(P9813DATA p9813data,LEDPINDATA led_pins){
	#ifndef NONSECURE
	configureP9813AsSecure(p9813data);
	#endif
	p9813controller=P9813Controller(p9813data.GPIOx,p9813data.GPIO_Pin_data,p9813data.GPIO_Pin_clock);
	#ifndef NONSECURE
	configureNormalLEDsAsSecure(led_pins);
	#endif
	type=both;
}
bool SecureLEDController::setRGB(RGB rgb){
	return setRGB(rgb.r,rgb.g,rgb.b);
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
#ifndef NONSECURE
/* We don't need to use these functions, if we don't use TrustZone */
void SecureLEDController::configureP9813AsSecure(P9813DATA p9813data){
  	HAL_GPIO_ConfigPinAttributes(p9813data.GPIOx, ((p9813data.GPIO_Pin_data) & (p9813data.GPIO_Pin_clock)), GPIO_PIN_SEC);
	return;
}
void SecureLEDController::configureNormalLEDsAsSecure(LEDPINDATA pindata){
	//config pins as secure
  	HAL_GPIO_ConfigPinAttributes(pindata.GPIOx_R,  pindata.GPIO_Pin_Red, GPIO_PIN_SEC);
	HAL_GPIO_ConfigPinAttributes(pindata.GPIOx_G,  pindata.GPIO_Pin_Green, GPIO_PIN_SEC);
	HAL_GPIO_ConfigPinAttributes(pindata.GPIOx_B,  pindata.GPIO_Pin_Blue, GPIO_PIN_SEC);
	//init pins
	GPIO_InitTypeDef GPIO_Init;
  	GPIO_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull  = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  	//init red pin
  	  	GPIO_Init.Pin   = pindata.GPIO_Pin_Red;
  		HAL_GPIO_Init(pindata.GPIOx_R, &GPIO_Init);
  	//init red pin
  	  	GPIO_Init.Pin   = pindata.GPIO_Pin_Green;
  		HAL_GPIO_Init(pindata.GPIOx_G, &GPIO_Init);
  	//init red pin
  	  	GPIO_Init.Pin   = pindata.GPIO_Pin_Blue;
  		HAL_GPIO_Init(pindata.GPIOx_B, &GPIO_Init);
	
	return;
}
#endif



SecureLEDController ledc;

//To be callable from standard C

extern "C" {

//TODO with onboard
void initLEDController(
    GPIO_TypeDef*   GPIOx, 
    uint16_t        GPIO_Pin_data,
    uint16_t        GPIO_Pin_clock
){
	P9813DATA p9813data = {GPIOx, GPIO_Pin_data, GPIO_Pin_clock};
	ledc = SecureLEDController(p9813data);
	return;
}
void initLEDController_default(){
	P9813DATA p9813data = {GPIOD, GPIO_PIN_6, GPIO_PIN_7}; //my current setup
	LEDPINDATA led_pins = {GPIOC,GPIO_PIN_7, GPIOB,GPIO_PIN_7, GPIOA,GPIO_PIN_9 }; //onboard leds
	ledc = SecureLEDController(p9813data,led_pins);
}

void LEDController_setColor(
    uint8_t r,
    uint8_t g,
    uint8_t b
){
	ledc.setRGB(r,g,b);
	return;
}
RGB LEDController_getColor(){
	return ledc.getRGB();
}

}
