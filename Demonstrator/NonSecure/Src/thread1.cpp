extern "C" {
#include "cmsis_os.h"
#include "thread1.h"
#include "secure_nsc.h"
}
//#include "LEDController.hpp"

extern "C" int runThread1() {

	for (;;) {
		osDelay(100);
		SECURE_LEDS_setGreen(255);
		osDelay(100);
		SECURE_LEDS_setGreen(55);
	}

return 0;
}
