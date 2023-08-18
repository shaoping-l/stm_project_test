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

//VNH5019_1
extern TIM_HandleTypeDef htim2;
#define FL_INA_PORT GPIOD
#define FL_INA_PIN GPIO_PIN_8
#define FL_INB_PORT GPIOD
#define FL_INB_PIN GPIO_PIN_14
//VNH5019_2
extern TIM_HandleTypeDef htim5;
#define BL_INA_PORT GPIOB
#define BL_INA_PIN GPIO_PIN_12
#define BL_INB_PORT GPIOB
#define BL_INB_PIN GPIO_PIN_13
//VNH5019_3
extern TIM_HandleTypeDef htim3;
#define BR_INA_PORT GPIOE
#define BR_INA_PIN GPIO_PIN_2
#define BR_INB_PORT GPIOE
#define BR_INB_PIN GPIO_PIN_3
//VNH5019_4
extern TIM_HandleTypeDef htim4;
#define FR_INA_PORT GPIOC
#define FR_INA_PIN GPIO_PIN_13
#define FR_INB_PORT GPIOE
#define FR_INB_PIN GPIO_PIN_4

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

double Vx = 0, Vy = 0, W, rVx, rVy, rW;

#endif /* INC_TIM_IT_H_ */
