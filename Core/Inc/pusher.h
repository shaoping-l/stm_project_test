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
#define PUSHER_A_IN1_PIN GPIO_PIN_9
#define PUSHER_A_IN2_PORT GPIOE
#define PUSHER_A_IN2_PIN GPIO_PIN_11
#define PUSHER_SPEED 33.6

class PUSHER{
public:
	//PUSHER(int x):state(x){}; //initializer list
	double state =0;
	double p_state =0;
	double d =0;
//	void pusher_down();
//	void pusher_up();
	void pusher_move();
	void distence();
	void pusher_reset();
private: //encapsulation 封裝
	int _state;
};



#endif /* INC_PUSHER_H_ */
