/*
 * work.c
 *
 *  Created on: 28.12.2020
 *      Author: F. Pilz
 */

#include "stm32l5xx_nucleo.h"
#include "secure_nsc.h"

#define HERZSCHLAG_INTERVALL 750			//the heartbeat is normal
#define HERZSCHLAG_BRADYKARDIE 500			//the heartbeat is too slow

void sinuatrial_node(int mode);				//the green LED lights up, simulates normal heartbeat
void pacemaker(void);						//the red LED lights up, simulates pacemaker triggered heartbeat

int work(void){
	//pacemaker();
	/*Test der verschiedenen Modi*/
	sinuatrial_node(2);
	for(int i = 0; i < 20; ++i){
		osDelay(100);
		sinuatrial_node(1);
	}
	sinuatrial_node(0);
	while(1){
		;
	}
}

/* Idea: There are two modes:
 * 0: Heart beats without pacemaker, might be used for debugging purpose or for check by the pacemaker, works indefinitely
 * 1: Heart beats with pacemaker, beats only once to stabilize heartbeat
 * 2: Venticular Fibrillation*/

void sinuatrial_node(int mode){
	if(mode == 0){
		while(1){
			SECURE_LEDToggle();
			osDelay(750);
		}
	}
	if(mode == 1){
		SECURE_LEDToggle();
	}
	if(mode == 2){
		for(int i = 0; i < 100; ++i){
			SECURE_LEDToggle();
			osDelay(120);
		}
	}
}

void pacemaker(void){

}
