/*
 * TIM_IT.cpp
 *
 *  Created on: Jul 30, 2023
 *      Author: kch93
 */
#include "TIM_IT.h"
#include "math.h"
#include "chassis_DCmotor.h"
#include "chassis_kinetic_model.h"
#include "PID.h"
#include "pusher.h"
#include "script.h"

double coeffab = 0.5 * (width + length);
//extern int flag;
//extern int flaged;
//extern int scriptrun;
//extern int cmd;
//extern int delay;
//extern int delay_start;
extern PUSHER pusher_A;
extern PUSHER pusher_B;
extern PUSHER pusher_C;
extern PUSHER pusher_D;
double corr_vy = (double)100/94;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM1){

		Kpid[0].goalVel = Vx + Vy * corr_vy + (W * coeffab);
		Kpid[1].goalVel = Vx - Vy * corr_vy - (W * coeffab);
		Kpid[2].goalVel = Vx + Vy * corr_vy - (W * coeffab);
		Kpid[3].goalVel = Vx - Vy * corr_vy + (W * coeffab);

		Kpid[0].enc = __HAL_TIM_GetCounter(FR_ENC);
		Kpid[1].enc = __HAL_TIM_GetCounter(FL_ENC);
		Kpid[2].enc = __HAL_TIM_GetCounter(BL_ENC) * -1;
		Kpid[3].enc = __HAL_TIM_GetCounter(BR_ENC) * -1;
		__HAL_TIM_SetCounter(FR_ENC, 0);
		__HAL_TIM_SetCounter(FL_ENC, 0);
		__HAL_TIM_SetCounter(BL_ENC, 0);
		__HAL_TIM_SetCounter(BR_ENC, 0);



		for( int i = 0; i < 4; i ++){
			pidCtrl(i);
		}

		__HAL_TIM_SET_COMPARE(FR_PWM_TIMMER, FR_PWM_CHANNEL, Kpid[0].pulse);
		__HAL_TIM_SET_COMPARE(FL_PWM_TIMMER, FL_PWM_CHANNEL, Kpid[1].pulse);
		__HAL_TIM_SET_COMPARE(BL_PWM_TIMMER, BL_PWM_CHANNEL, Kpid[2].pulse);
		__HAL_TIM_SET_COMPARE(BR_PWM_TIMMER, BR_PWM_CHANNEL, Kpid[3].pulse);
		HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_RESET);
		if (Kpid[0].u > 0)HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[0].u < 0)HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_SET);
		if (Kpid[1].u > 0)HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[1].u < 0)HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_SET);
		if (Kpid[2].u > 0)HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[2].u < 0)HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_SET);
		if (Kpid[3].u > 0)HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[3].u < 0)HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_SET);
	}

	if(htim->Instance == TIM8){
		/*pusher down*/
		if(pusher_A.d > 0){
			pusher_A.count++;
			HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);
			if(pusher_A.count > pusher_A.d*1000/PUSHER_SPEED){
				pusher_A.p_state = pusher_A.state;
				pusher_A.count = 0;
			}
		}
		if(pusher_B.d > 0){
			pusher_B.count++;
			HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_RESET);
			if(pusher_B.count > pusher_B.d*1000/PUSHER_SPEED){
				pusher_B.p_state = pusher_B.state;
				pusher_B.count = 0;
			}
		}
//		if(pusher_C.d > 0){
//			pusher_C.count++;
//			HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_RESET);
//			if(pusher_C.count > pusher_C.d*1000/PUSHER_SPEED){
//				pusher_C.p_state = pusher_C.state;
//				pusher_C.count = 0;
//			}
//		}
//		if(pusher_D.d > 0){
//			pusher_D.count++;
//			HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_SET);
//			HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_RESET);
//			if(pusher_D.count > pusher_D.d*1000/PUSHER_SPEED){
//				pusher_D.p_state = pusher_D.state;
//				pusher_D.count = 0;
//			}
//		}
		/*pusher up*/
		if(pusher_A.d < 0){
			pusher_A.count++;
			HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_SET);
			if(pusher_A.count > -pusher_A.d*1000/PUSHER_SPEED){
				pusher_A.p_state = pusher_A.state;
				pusher_A.count = 0;
			}
		}
		if(pusher_B.d < 0){
			pusher_B.count++;
			HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_SET);
			if(pusher_B.count > -pusher_B.d*1000/PUSHER_SPEED){
				pusher_B.p_state = pusher_B.state;
				pusher_B.count = 0;
			}
		}
//		if(pusher_C.d < 0){
//			pusher_C.count++;
//			HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_SET);
//			if(pusher_C.count > -pusher_C.d*1000/PUSHER_SPEED){
//				pusher_C.p_state = pusher_C.state;
//				pusher_C.count = 0;
//			}
//		}
//		if(pusher_D.d < 0){
//			pusher_D.count++;
//			HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_SET);
//			if(pusher_D.count > -pusher_D.d*1000/PUSHER_SPEED){
//				pusher_D.p_state = pusher_D.state;
//				pusher_D.count = 0;
//			}
//		}
		/*pusher stop*/
		if(pusher_A.d == 0){
			HAL_GPIO_WritePin(PUSHER_A_IN1_PORT, PUSHER_A_IN1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PUSHER_A_IN2_PORT, PUSHER_A_IN2_PIN, GPIO_PIN_RESET);
		}
		if(pusher_B.d == 0){
			HAL_GPIO_WritePin(PUSHER_B_IN1_PORT, PUSHER_B_IN1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(PUSHER_B_IN2_PORT, PUSHER_B_IN2_PIN, GPIO_PIN_RESET);
		}
//		if(pusher_C.d == 0){
//					HAL_GPIO_WritePin(PUSHER_C_IN1_PORT, PUSHER_C_IN1_PIN, GPIO_PIN_RESET);
//					HAL_GPIO_WritePin(PUSHER_C_IN2_PORT, PUSHER_C_IN2_PIN, GPIO_PIN_RESET);
//		}
//		if(pusher_D.d == 0){
//			HAL_GPIO_WritePin(PUSHER_D_IN1_PORT, PUSHER_D_IN1_PIN, GPIO_PIN_RESET);
//			HAL_GPIO_WritePin(PUSHER_D_IN2_PORT, PUSHER_D_IN2_PIN, GPIO_PIN_RESET);
//		}
//
	}
	if(htim->Instance == TIM23){/*for script*/
		if(delay_start!=0){
			delay++;
		}
		if(delay_start_2!=0){
			delay_2++;
		}


//		if(cmd == 0){
//			script_wheel(0,0,0);
//			script_pusher(0,0,0,0);
//		}
//		else if(cmd == 1){
//			script_wheel(0,0,0);
//			script_pusher(10,0,0,0);
//		}
//		else if(cmd == 2){
//			script_wheel(0,0,0);
//			script_pusher(0,8.5,0,0);
//		}
//		else if(cmd == 3){
//			script_wheel(0,0,0);
//			script_pusher(10,0,0,0);
//		}
//		else if(cmd == 4){
//			script_wheel(0,0,0);
//			script_pusher(0,10,0,0);;
//		}
//		else if(cmd == 5){
//			script_wheel(0,0,0);
//			script_pusher(0,10,0,0);
//		}

	}
}
