/*
 * script.cpp
 *
 *  Created on: 2023年8月16日
 *      Author: paul3
 */
#include "script.h"
#include "pusher.h"

SCRIPT script_a;
//extern PUSHER pusher_A;
//extern PUSHER pusher_B;
//extern PUSHER pusher_C;
//extern PUSHER pusher_D;
void script(){
	if(script_a.scriptrun == 1){
		if(delay_start == 0){
			script_wheel(5,0,0);
			script_pusher(5,5);
			delay_start = 1;
		}
		if(delay == 250 && delay_start == 1){
//			script_wheel(0,0,0);
			script_pusher(11,5);
			delay_start = 2;
		}
		if(delay == 550 && delay_start == 2){
			script_wheel(20,0,0);
			delay_start = 3;
		}
		if(delay == 700 && delay_start == 3){
			script_wheel(10,0,0);
			script_pusher(-2,5);
			delay_start = 4;
		}
		if(delay == 900 && delay_start == 4){
			script_wheel(0,0,0);
			script_pusher(-2,10);
			delay_start = 5;
		}
		if(delay == 1050 && delay_start == 5){/*-50*/
//			script_pusher(-2,10);
			script_wheel(10,0,0);
			delay_start = 6;
		}
		if(delay == 1250 && delay_start == 6){/*-50*/
			script_pusher(10,0);
			delay_start = 7;
		}
//		if(delay == 1700 && delay_start == 6){
//			script_wheel(0,0,0);
//			script_pusher(10,0);
//			delay_start = 7;
//		}
		if(delay == 1800 && delay_start == 7){
			script_wheel(10,0,0);
			script_pusher(-2,10);
			delay_start = 8;
		}
//		if(delay == 2000 && delay_start == 8){
//			script_wheel(0,0,0);
//			script_pusher(-2,10);
//			delay_start = 9;
//		}
//		if(delay == 2900 && delay_start == 9){
//			script_wheel(10,0,0);
//			delay_start = 10;
//		}
		if(delay == 2500 && delay_start == 8){
			script_wheel(0,0,0);
			script_pusher(-2,0);
			delay_start = 0;
			script_a.scriptrun = 0;
			delay = 0;
		}
	}

}
void script_wheel(double s_Vx,double s_Vy,double s_w){
	Vx = s_Vx;
	Vy = s_Vy;
	W = s_w;
}
//void script_pusher(double hight_a,double hight_b,double hight_c,double hight_d){
//	pusher_A.state = hight_a;
//	pusher_B.state = hight_b;
//	pusher_C.state = hight_c;
//	pusher_D.state = hight_d;
//}

