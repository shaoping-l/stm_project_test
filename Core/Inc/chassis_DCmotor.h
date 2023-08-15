/*
 * chassis_DCmotor.h
 *
 *  Created on: Jul 27, 2023
 *      Author: kch93
 */

#ifndef INC_CHASSIS_DCMOTOR_H_
#define INC_CHASSIS_DCMOTOR_H_
#include "stm32h7xx_hal.h"

void DC_motor_init();
//TIM_IT span
#define TIM_IT_span 0.001

class DC_motor{
public:
	DC_motor(double p, double i, double d, double ratio, double res, double PWM_span);
	//encoder
	int resolution;
	double reduction_ratio;
	int enc;
	double encoder(TIM_HandleTypeDef *htim);
	//PID
	double SP=0, PV=0, kp, ki, kd;
	double ARR;
	int pulse;
	int PID_PWM_Convertor(double set_point,double present_var);
private:
	//PID
	double error, integral, differential;
	double u = 0, prev_u = 0;
};

//virtual Instances
extern DC_motor FL;
extern DC_motor BL;
extern DC_motor BR;
extern DC_motor FR;

#endif /* INC_CHASSIS_DCMOTOR_H_ */
