/*
 * nsc_wrapper.h
 *
 *  Created on: Feb 28, 2021
 *      Author: F. Pilz
 */

#ifndef INC_NSC_WRAPPER_H_
#define INC_NSC_WRAPPER_H_

#include <stdint.h>

void SECURE_LEDS_setGreen(uint8_t brightness);
void SECURE_LEDS_setRed(uint8_t brightness);
void SECURE_LEDS_setBlue(uint8_t brightness);

#endif /* INC_NSC_WRAPPER_H_ */
