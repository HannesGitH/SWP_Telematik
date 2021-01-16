extern "C" {
#include "cmsis_os.h"
#include "thread1.h"
#include "secure_nsc.h"
}
#include "ledcontroller.hpp"

extern "C" int runThread1() {

	P9813DATA p9813data = {GPIOD, GPIO_PIN_6, GPIO_PIN_7};
	LEDController ledC(p9813data,LEDPINDATA{});
	for (;;) {
		osDelay(100);
		//SECURE_LEDsetGreen(55);
		//ledC.setRGB(0, 0, 0);
		osDelay(100);
		SECURE_LEDToggle2();
		//ledC.setRGB(255, 255, 255);
	}

return 0;
}
