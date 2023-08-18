/*
 * mainpp.cpp
 *
 *  Created on: Jul 23, 2023
 *      Author: paul3
 */
#include "mainpp.h"
#include "pusher.h"
#include "chassis_DCmotor.h"
#include "stm32h7xx_hal.h"
#include "script.h"
int b=0;
int scriptrun =0;

extern TIM_HandleTypeDef htim1;
void main_function(){
	PUSHER pusher_A;
	PUSHER pusher_B;
	PUSHER pusher_C;
	PUSHER pusher_D;
	stm_setup();
	while(1){
		script();
		pusher_A.distence();
		pusher_A.pusher_move();
		pusher_B.distence();
		pusher_B.pusher_move();
		pusher_C.distence();
		pusher_C.pusher_move();
		pusher_D.distence();
		pusher_D.pusher_move();
	}
}
void stm_setup(void){
	HAL_TIM_Base_Start_IT(&htim1);//main Timer
	DC_motor_init();
}

