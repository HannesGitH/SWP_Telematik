extern "C" {
#include "thread1.h"
}
//#include "LEDController.hpp"

extern "C" int runThread1() {

	for (;;) {
		osDelay(100);
		//BSP_LED_Toggle(LED3);//This doesnt work with TZEN=1m
		SECURE_LEDS_setGreen(255);
		osDelay(100);
		SECURE_LEDS_setGreen(55);
	}

return 0;
}
