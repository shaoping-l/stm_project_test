/*
 * script.h
 *
 *  Created on: 2023年8月16日
 *      Author: paul3
 */

#ifndef INC_SCRIPT_H_
#define INC_SCRIPT_H_


void script();
void script_wheel(double s_Vx,double s_Vy,double s_W);
void script_pusher(double hight_a,double hight_b);
class SCRIPT{
public:
	int scriptrun = 0;
private:
};
extern double Vx;
extern double Vy;
extern double W;
extern int delay;
extern int delay_start;
extern int delay_2;
extern int delay_start_2;


#endif /* INC_SCRIPT_H_ */
