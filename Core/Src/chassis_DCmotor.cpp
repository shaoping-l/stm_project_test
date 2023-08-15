/*
 * chassis_DCmotor.cpp
 *
 *  Created on: Jul 27, 2023
 *      Author: kch93
 */
#include "chassis_DCmotor.h"
#include "stm32h7xx_hal.h"/*h7*/
#define pi 3.1415926535897932384

/*encoder*/
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;
/*VNH5019_PWM*/
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim12;

DC_motor FL(15.96559764,31.71747647,0,216,512,1000);//motor_1
DC_motor BL(24.18280423,91.68881006,0,216,512,1000);//motor_2
DC_motor BR(21.19552541,50.08697147,0,216,512,1000);//motor_3
DC_motor FR(32.6189283,77.45068509,0,216,512,1000);//motor_4

void DC_motor_init(){
	//enc_1
	HAL_TIM_Encoder_Start_IT(&htim2,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start_IT(&htim2,TIM_CHANNEL_2);
 	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_2);//VNH5019_1_PWM
 	//enc_2
 	HAL_TIM_Encoder_Start_IT(&htim5,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start_IT(&htim5,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim12,TIM_CHANNEL_1);//VNH5019_2_PWM
	//enc_3
	HAL_TIM_Encoder_Start_IT(&htim3,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start_IT(&htim3,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_1);//VNH5019_3_PWM
	//enc_4
	HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_1);
	HAL_TIM_Encoder_Start_IT(&htim4,TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&htim15,TIM_CHANNEL_2);//VNH5019_4_PWM
}

//motor Instance
DC_motor::DC_motor(double p, double i, double d, double ratio, double res, double PWM_span){
	this->kp = p;
	this->ki = i;
	this->kd = d;
	this->reduction_ratio = ratio;
	this->resolution = res;
	this->ARR = PWM_span;
}
//using angular velocity
double DC_motor::encoder(TIM_HandleTypeDef *htim){
	enc = __HAL_TIM_GetCounter(htim);
	__HAL_TIM_SetCounter(htim,0);
	return (double) enc/(4*resolution*reduction_ratio*TIM_IT_span*2*pi);
}
int DC_motor::PID_PWM_Convertor(double set_point,double present_var){
	//Proportion
	error = set_point - present_var;
	//integal
	integral += error * TIM_IT_span;
	if (ki * integral > 1) integral = 1/ki;
	else if (ki * integral < -1) integral = -1/ki;
	//differential
	differential = (u - prev_u) / TIM_IT_span;
	prev_u = u;
	//PWM_Ratio
	u = kp * error + ki * integral + kd * differential;
	if (u > 1) u = 1;
	else if (u < -1) u = -1;

	return (int) u*ARR;
}



