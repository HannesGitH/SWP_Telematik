extern "C" {
#include "thread1.h"
#include "secure_nansc.h"
}
//#include "LEDController.hpp"

extern "C" int runThread1() {

	for (;;) {
		osDelay(100);
		BSP_LED_Toggle(LED3);//This doesnt work with TZEN=1
		SECURE_LEDS_setGreen(255);
		SECURE_LEDS_setBlue(255);
		osDelay(100);
		SECURE_LEDS_setGreen(55);
		SECURE_LEDS_setBlue(55);
	}

return 0;
}
