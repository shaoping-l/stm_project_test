/*
 * stepper.h
 *
 *  Created on: 2023年8月3日
 *      Author: paul3
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_
#include "stm32h7xx_hal.h"

#define DIR_PORT_1 GPIOB
#define DIR_PIN_1 GPIO_PIN_6
#define STEP_PORT_1 GPIOB
#define STEP_PIN_1 GPIO_PIN_7

class STEPPER{
public:
	double now_angle =0;
	double goal_angle =0;
	double step =0;
	void stepper_cal();
private:
};




#endif /* INC_STEPPER_H_ */
