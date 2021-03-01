extern "C" {
#include "thread1.h"
}
//#include "LEDController.hpp"

extern "C" int runThread1() {

	void (*SECURE_LEDS_setRed)(uint8_t) = get__SECURE_LEDS_setRed__func();

	for (;;) {
		osDelay(100);
		BSP_LED_Toggle(LED3);//This doesnt work with TZEN=1
		SECURE_LEDS_setGreen(255);
		SECURE_LEDS_setRed(255);//attack on the ledcontroller?
		osDelay(100);
		SECURE_LEDS_setGreen(55);
		SECURE_LEDS_setRed(55);
	}

return 0;
}
