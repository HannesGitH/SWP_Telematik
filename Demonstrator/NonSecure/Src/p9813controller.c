#include "p9813controller.h"
#include "constant.h"
#include "stm32l5xx_nucleo.h"
#include "cmsis_os.h"

uint8_t _r;
uint8_t _g;
uint8_t _b;

GPIO_TypeDef *_GPIOx;
uint16_t _dataPIN;
uint16_t _clockPIN;

uint32_t _bgr;
uint32_t _sequence;

void _LEDController__send32bitSequence(uint32_t sequence){
    for(int8_t i=31;i>=0;i--){

		HAL_GPIO_WritePin(_GPIOx, _dataPIN, ((sequence>>i)&1)?GPIO_PIN_SET:GPIO_PIN_RESET);//fetch and write next bit from sequence

		//Toggle clock (rising edge)
		HAL_GPIO_WritePin(_GPIOx, _clockPIN, GPIO_PIN_RESET);
		osDelay(1);						//give p9813 some time (datasheet says he needs up to 500nanoseconds)
		HAL_GPIO_WritePin(_GPIOx, _clockPIN, GPIO_PIN_SET);
		osDelay(1);						//give p9813 some time
	}
}

void _LEDController__writeColor(){

	//this is what the protocol of the p9813 requires:
	_bgr=(_b<<16)|(_g<<8)|_r;
	_sequence  =  0xc0000000           	//first to bits are set
			| (~(0xFFFFFF3F|_r))<<18   	//flip 2 most significant bits of r and move to protocol specified location
			| (~(0xFFFFFF3F|_g))<<20   	//flip 2 most significant bits of g and move to protocol specified location
			| (~(0xFFFFFF3F|_b))<<22   	//flip 2 most significant bits of b and move to protocol specified location
			| _bgr;                    	//add actual color info



	_LEDController__send32bitSequence(0);               //start Data
	_LEDController__send32bitSequence(_sequence);
	_LEDController__send32bitSequence(0);               //end Data
	}

void LEDController__initialize(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock){
	_dataPIN=GPIO_Pin_data;_clockPIN=GPIO_Pin_clock;_GPIOx=GPIOx;

  	GPIO_InitTypeDef GPIO_Init;
  	GPIO_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull  = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  	//init data pin
  	  	GPIO_Init.Pin   = _dataPIN;
  		HAL_GPIO_Init(_GPIOx, &GPIO_Init);
	//init clock pin
		GPIO_Init.Pin   = _clockPIN;
		HAL_GPIO_Init(_GPIOx, &GPIO_Init);

}

int LEDController__setRGB(
	uint8_t r,
	uint8_t g,
	uint8_t b
){
	_r=r;_g=g;_b=b;
	_LEDController__writeColor();
	return SUCCESS;
}
