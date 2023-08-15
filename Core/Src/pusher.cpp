/*
 * pusher.cpp
 *
 *  Created on: 2023年7月25日
 *      Author: paul3
 */
#include "pusher.h"

PUSHER pusher_A;
PUSHER pusher_B;
PUSHER pusher_C;
PUSHER pusher_D;

void PUSHER::distence(){
	pusher_A.d = (pusher_A.state - pusher_A.p_state)*10;
	pusher_B.d = (pusher_B.state - pusher_B.p_state)*10;
	pusher_C.d = (pusher_C.state - pusher_C.p_state)*10;
	pusher_D.d = (pusher_D.state - pusher_D.p_state)*10;
}
void PUSHER::pusher_move(){
	/*pusher down*/
	if(pusher_A.d >0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);
		HAL_Delay(pusher_A.d*1000/PUSHER_SPEED);
		pusher_A.p_state = pusher_A.state;
	}

	if(pusher_B.d >0){
		HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_RESET);
		HAL_Delay(pusher_B.d*1000/PUSHER_SPEED);
		pusher_B.p_state = pusher_B.state;
	}

	if(pusher_C.d >0){
		HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_RESET);
		HAL_Delay(pusher_C.d*1000/PUSHER_SPEED);
		pusher_C.p_state = pusher_C.state;
	}

	if(pusher_D.d >0){
		HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_RESET);
		HAL_Delay(pusher_D.d*1000/PUSHER_SPEED);
		pusher_D.p_state = pusher_D.state;
	}

	/*pusher up*/
	if(pusher_A.d <0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(-pusher_A.d*1000/PUSHER_SPEED);
		pusher_A.p_state = pusher_A.state;
	}

	if(pusher_B.d <0){
		HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(-pusher_B.d*1000/PUSHER_SPEED);
		pusher_B.p_state = pusher_B.state;
	}

	if(pusher_C.d <0){
		HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(-pusher_C.d*1000/PUSHER_SPEED);
		pusher_C.p_state = pusher_C.state;
	}

	if(pusher_D.d <0){
		HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(-pusher_D.d*1000/PUSHER_SPEED);
		pusher_D.p_state = pusher_D.state;
	}
	/*pusher stop*/
	if(pusher_A.d ==0){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);

	}

	if(pusher_B.d ==0){
		HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_RESET);

	}

	if(pusher_C.d ==0){
		HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_RESET);

	}

	if(pusher_D.d ==0){
		HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_RESET);

	}
}
void pusher_reset(){
	if(pusher_A.a == 1){
		HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_SET);
		HAL_Delay(5000);
		pusher_A.p_state = 0;
		pusher_A.state = 0;
	}
}

