/*
 * pusher.cpp
 *
 *  Created on: 2023年7月25日
 *      Author: paul3
 */
#include "pusher.h"

PUSHER push;

void PUSHER::distence(){
	push.d = (push.state - push.p_state)*10;
}
void PUSHER::pusher_move(){
	/*pusher down*/
	if(push.d >0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);
		HAL_Delay(push.d*1000/PUSHER_SPEED);
		push.p_state = push.state;
	}
	/*pusher up*/
	if(push.d <0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(-push.d*1000/PUSHER_SPEED);
		push.p_state = push.state;
	}
	if(push.d ==0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);

	}
}


