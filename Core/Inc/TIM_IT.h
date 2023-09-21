/*
 * TIM_IT.h
 *
 *  Created on: Jul 30, 2023
 *      Author: kch93
 */

#ifndef INC_TIM_IT_H_
#define INC_TIM_IT_H_

#include "stm32h7xx_hal.h"
//main Timer
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim12;
extern TIM_HandleTypeDef htim15;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim23;
//Kpid[0]
//VNH5019_1
extern TIM_HandleTypeDef htim2;
#define FR_ENC &htim2
#define FR_PWM_TIMMER &htim12
#define FR_PWM_CHANNEL TIM_CHANNEL_2
#define FR_INA_PORT GPIOD
#define FR_INA_PIN GPIO_PIN_14
#define FR_INB_PORT GPIOD
#define FR_INB_PIN GPIO_PIN_8
#define FR_Kp 24.1824
#define FR_Ki 91.6881
#define FR_Kd 0
//Kpid[1]
//VNH5019_2
extern TIM_HandleTypeDef htim5;
#define FL_ENC &htim5
#define FL_PWM_TIMMER &htim12
#define FL_PWM_CHANNEL TIM_CHANNEL_1
#define FL_INA_PORT GPIOB
#define FL_INA_PIN GPIO_PIN_12
#define FL_INB_PORT GPIOB
#define FL_INB_PIN GPIO_PIN_13
#define FL_Kp 24.1824
#define FL_Ki 91.6881
#define FL_Kd 0
//Kpid[2]
//VNH5019_3
extern TIM_HandleTypeDef htim3;
#define BL_ENC &htim3
#define BL_PWM_TIMMER &htim15
#define BL_PWM_CHANNEL TIM_CHANNEL_1
#define BL_INA_PORT GPIOE
#define BL_INA_PIN GPIO_PIN_2
#define BL_INB_PORT GPIOE
#define BL_INB_PIN GPIO_PIN_3
#define BL_Kp 24.1824
#define BL_Ki 91.6881
#define BL_Kd 0
//Kpid[3]
//VNH5019_4
extern TIM_HandleTypeDef htim4;
#define BR_ENC &htim4
#define BR_PWM_TIMMER &htim15
#define BR_PWM_CHANNEL TIM_CHANNEL_2
#define BR_INA_PORT GPIOC
#define BR_INA_PIN GPIO_PIN_13
#define BR_INB_PORT GPIOE
#define BR_INB_PIN GPIO_PIN_4
#define BR_Kp 24.1824
#define BR_Ki 91.6881
#define BR_Kd 0

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

double Vx = 0, Vy = 0, W, rVx, rVy, rW;
int delay_start = 0,delay = 0;
int delay_start_2= 0,delay_2 = 0;
#endif /* INC_TIM_IT_H_ */
