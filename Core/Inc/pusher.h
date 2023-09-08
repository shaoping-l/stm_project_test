/*
 * pusher.h
 *
 *  Created on: 2023年7月25日
 *      Author: paul3
 */

#ifndef INC_PUSHER_H_
#define INC_PUSHER_H_
#include "stm32h7xx_hal.h"

/*pusher test*/
#define PUSHER_A_IN1_PORT GPIOE
#define PUSHER_A_IN1_PIN GPIO_PIN_15
#define PUSHER_A_IN2_PORT GPIOE
#define PUSHER_A_IN2_PIN GPIO_PIN_10

#define PUSHER_B_IN1_PORT GPIOE
#define PUSHER_B_IN1_PIN GPIO_PIN_9
#define PUSHER_B_IN2_PORT GPIOE
#define PUSHER_B_IN2_PIN GPIO_PIN_8

#define PUSHER_C_IN1_PORT GPIOF
#define PUSHER_C_IN1_PIN GPIO_PIN_14
#define PUSHER_C_IN2_PORT GPIOF
#define PUSHER_C_IN2_PIN GPIO_PIN_13

#define PUSHER_D_IN1_PORT GPIOG
#define PUSHER_D_IN1_PIN GPIO_PIN_0
#define PUSHER_D_IN2_PORT GPIOF
#define PUSHER_D_IN2_PIN GPIO_PIN_15

#define PUSHER_SPEED 33.6


class PUSHER{
public:
	//PUSHER(int x):state(x){}; //initializer list
	double state =0;
	double p_state =0;
	double d =0;
	int count =0;
//	void pusher_down();
//	void pusher_up();
	void pusher_move();
	void distence();
	void script_pusher(double hight_a,double hight_b);
private: //encapsulation 封裝
	int _state;
};



#endif /* INC_PUSHER_H_ */
