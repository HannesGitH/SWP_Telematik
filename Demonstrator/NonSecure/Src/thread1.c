//extern "C" {
#include "p9813controller.h"
#include "cmsis_os.h"
//}
#include "thread1.h"

/*extern "C" */int runThread1() {

	LEDController__initialize(GPIOD, GPIO_PIN_6, GPIO_PIN_7);
	for (;;) {
		osDelay(100);
		LEDController__setRGB(0, 0, 0);
		osDelay(1000);
		LEDController__setRGB(255, 255, 255);
	}

return SUCCESS;
}
