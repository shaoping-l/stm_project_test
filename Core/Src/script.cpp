/*
 * script.cpp
 *
 *  Created on: 2023年8月16日
 *      Author: paul3
 */
#include "script.h"
#include "pusher.h"
//#include "TIM_IT.h"

//PUSHER pusher_A;
//PUSHER pusher_B;
//PUSHER pusher_C;
//PUSHER pusher_D;
//PUSHER pusher_t;
extern int scriptrun;
void script(){
	if(scriptrun == 1){
		HAL_Delay(1000);
		script_wheel(1,0,0,3000);
		script_wheel(0,0,0,50);
		script_wheel(0,0,1,4500);
		script_wheel(0,0,0,50);
		script_wheel(0,-1,0,4000);
		script_wheel(0,0,0,50);
//		script_wheel(1,0,0,5000);
//		script_wheel(1,0,0,5000);
//		script_pusher(5,0,0,5);
//		HAL_Delay(1000);
//		pusher_t.distence(5,10,10,10);
//		HAL_Delay(1000);
//		script_wheel(1,0,0,10000);
//		pusher_t.distence(5,5,10,10);
//		HAL_Delay(1000);
//		script_wheel(1,0,0,10000);
//		pusher_t.distence(10,5,5,10);
//		HAL_Delay(1000);
//		script_wheel(1,0,0,10000);
		scriptrun = 0;
	}
}
void script_wheel(double s_Vx,double s_Vy,double s_w,double T){
	Vx = s_Vx;
	Vy = s_Vy;
	W = s_w;
	HAL_Delay(T);
}
//void script_pusher(double hight_a,double hight_b,double hight_c,double hight_d){
//	pusher_A.state = hight_a;
//	pusher_B.state = hight_b;
//	pusher_C.state = hight_c;
//	pusher_D.state = hight_d;
//}

