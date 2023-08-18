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
# include "PID.h"

double coeffab = 0.5 * (width + length);


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM1){

		Kpid[0].goalVel = Vx + Vy - (W * coeffab);
		Kpid[1].goalVel = Vx + Vy + (W * coeffab);
		Kpid[2].goalVel = Vx - Vy - (W * coeffab);
		Kpid[3].goalVel = Vx - Vy + (W * coeffab);

		Kpid[0].enc = __HAL_TIM_GetCounter(&htim2);
		Kpid[1].enc = __HAL_TIM_GetCounter(&htim3);
		Kpid[2].enc = __HAL_TIM_GetCounter(&htim4);
		Kpid[3].enc = __HAL_TIM_GetCounter(&htim5) * -1;
		__HAL_TIM_SetCounter(&htim2, 0);
		__HAL_TIM_SetCounter(&htim3, 0);
		__HAL_TIM_SetCounter(&htim4, 0);
		__HAL_TIM_SetCounter(&htim5, 0);



		for( int i = 0; i < 4; i ++){
			pidCtrl(i);
		}

		__HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, Kpid[0].pulse);
		__HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, Kpid[1].pulse);
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, Kpid[2].pulse);
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_2, Kpid[3].pulse);
		HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_RESET);
		if (Kpid[0].u > 0)HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[0].u < 0)HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_SET);
		if (Kpid[1].u > 0)HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[1].u < 0)HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_SET);
		if (Kpid[2].u > 0)HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[2].u < 0)HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_SET);
		if (Kpid[3].u < 0)HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_SET);
		else if (Kpid[3].u > 0)HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_SET);
	}
}
