#include "p9813controller.hpp"

extern "C"{
#include "stm32l5xx_nucleo.h"
}

void P9813Controller::send32bitSequence(uint32_t sequence){
    for(int8_t i=31;i>=0;i--){

		HAL_GPIO_WritePin(GPIOx, dataPIN, ((sequence>>i)&1)?GPIO_PIN_SET:GPIO_PIN_RESET);//fetch and write next bit from sequence

		//Toggle clock (rising edge)
		HAL_GPIO_WritePin(GPIOx, clockPIN, GPIO_PIN_RESET);
		HAL_Delay(1);						//give p9813 some time (datasheet says he needs up to 500nanoseconds)
		HAL_GPIO_WritePin(GPIOx, clockPIN, GPIO_PIN_SET);
		HAL_Delay(1);						//give p9813 some time
	}
}

void P9813Controller::writeColor(){

	//this is what the protocol of the p9813 requires:
	bgr=(b<<16)|(g<<8)|r;
	sequence  =  0xc0000000           	//first to bits are set
			| (~(0xFFFFFF3F|r))<<18   	//flip 2 most significant bits of r and move to protocol specified location
			| (~(0xFFFFFF3F|g))<<20   	//flip 2 most significant bits of g and move to protocol specified location
			| (~(0xFFFFFF3F|b))<<22   	//flip 2 most significant bits of b and move to protocol specified location
			| bgr;                    	//add actual color info



	send32bitSequence(0);               //start Data
	send32bitSequence(sequence);
	send32bitSequence(0);               //end Data

	}

P9813Controller::P9813Controller(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin_data, uint16_t GPIO_Pin_clock){
	dataPIN=GPIO_Pin_data;clockPIN=GPIO_Pin_clock;
	this->GPIOx=GPIOx;

  	GPIO_InitTypeDef GPIO_Init;
  	GPIO_Init.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull  = GPIO_PULLUP;
	GPIO_Init.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  	//init data pin
  	  	GPIO_Init.Pin   = dataPIN;
  		HAL_GPIO_Init(GPIOx, &GPIO_Init);
	//init clock pin
		GPIO_Init.Pin   = clockPIN;
		HAL_GPIO_Init(GPIOx, &GPIO_Init);

}

bool P9813Controller::setRGB(
	uint8_t r,
	uint8_t g,
	uint8_t b
){
	this->r=r;this->g=g;this->b=b;
	writeColor();
	return SUCCESS;
}
