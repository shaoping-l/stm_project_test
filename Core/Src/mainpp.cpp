/*
 * mainpp.cpp
 *
 *  Created on: Jul 23, 2023
 *      Author: paul3
 */
#include "mainpp.h"
#include "pusher.h"

void main_function(){
	PUSHER push;
	while(1){
//		push.pusher_up();
//		push.pusher_down();
		push.distence();
		push.pusher_move();
	}
}


