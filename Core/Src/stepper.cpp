/*
 * stepper.cpp
 *
 *  Created on: 2023年8月3日
 *      Author: paul3
 */
#include "stepper.h"

STEPPER st1;

void STEPPER::stepper_cal(){
	st1.step = (st1.goal_angle -st1.now_angle)*8/1.8;
	if(st1.step > 0){
		HAL_GPIO_WritePin(DIR_PORT_1,DIR_PIN_1,GPIO_PIN_RESET);
	}
	if(st1.step < 0){
		HAL_GPIO_WritePin(DIR_PORT_1,DIR_PIN_1,GPIO_PIN_SET);
	}
}
