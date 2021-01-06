extern "C" {
#include "cmsis_os.h"
#include "thread1.h"
}
#include "p9813controller.hpp"

extern "C" int runThread1() {

	LEDController ledC(GPIOD, GPIO_PIN_6, GPIO_PIN_7);
	for (;;) {
		osDelay(100);
		ledC.setRGB(0, 0, 0);
		osDelay(1000);
		ledC.setRGB(255, 255, 255);
	}

return SUCCESS;
}
