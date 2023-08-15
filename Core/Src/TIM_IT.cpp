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



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM1){
		a++;
		Mecanum_O::inverse_kinetics(&FL.SP,&BL.SP,&BR.SP,&FR.SP);

		/*1. DC_motor FL*/
		FL.PV = FL.encoder(&htim2);
		FL.pulse = FL.PID_PWM_Convertor(FL.SP, FL.PV);

		if (FL.pulse > 0) {
			HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_RESET);
		}
		else{
			HAL_GPIO_WritePin(FL_INA_PORT, FL_INA_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(FL_INB_PORT, FL_INB_PIN, GPIO_PIN_SET);
		}
		__HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, abs(FL.pulse));

		/*2. DC_motor BL*/
		BL.PV = BL.encoder(&htim5);
		BL.pulse = BL.PID_PWM_Convertor(BL.SP, BL.PV);

		if (BL.pulse > 0) {
			HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_RESET);
		}
		else{
			HAL_GPIO_WritePin(BL_INA_PORT, BL_INA_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(BL_INB_PORT, BL_INB_PIN, GPIO_PIN_SET);
		}
		__HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1, abs(BL.pulse));

		/*3. DC_motor BR*/
		BR.PV = BR.encoder(&htim3);
		BR.pulse = BR.PID_PWM_Convertor(BR.SP, BR.PV);

		if (BR.pulse > 0) {
			HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_RESET);
		}
		else{
			HAL_GPIO_WritePin(BR_INA_PORT, BR_INA_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(BR_INB_PORT, BR_INB_PIN, GPIO_PIN_SET);
		}
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_1, abs(BR.pulse));

		/*4. DC_motor FR*/
		FR.PV = FR.encoder(&htim4);
		FR.pulse = FR.PID_PWM_Convertor(FR.SP, FR.PV);

		if (FR.pulse > 0) {
			HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_RESET);
		}
		else{
			HAL_GPIO_WritePin(FR_INA_PORT, FR_INA_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(FR_INB_PORT, FR_INB_PIN, GPIO_PIN_SET);
		}
		__HAL_TIM_SET_COMPARE(&htim15, TIM_CHANNEL_2, abs(FR.pulse));

		Mecanum_O::forward_kinetics(&FL.PV,&BL.PV,&BR.PV,&FR.PV);
	}
}
