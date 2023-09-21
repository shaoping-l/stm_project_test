# include "PID.h"
#define PI 3.14159265751

double Kp[] = {0.1, 0.1, 0.1, 0.1};
double Ki[] = {0.5, 0.5, 0.5, 0.5};
double Kd[] = {0, 0, 0, 0};
KPID Kpid[4] = {
    {Kp[0], Ki[0], Kd[0], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0},
    {Kp[1], Ki[1], Kd[1], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0},
    {Kp[2], Ki[2], Kd[2], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0},
    {Kp[3], Ki[3], Kd[3], 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0}
};

void pidCtrl(int i){
	Kpid[i].insVel = (double) Kpid[i].enc * PI * Dwheel
			/ (4 * resolution * reduction_ratio * belt_ratio) * frequency;
	Kpid[i].error = Kpid[i].goalVel - Kpid[i].insVel;
	Kpid[i].up = Kpid[i].Kp * Kpid[i].error;
	Kpid[i].ui += Kpid[i].Ki * Kpid[i].last_error / frequency;
//	Kpid[i].ui = 0;
	Kpid[i].ud = Kpid[i].Kd * (Kpid[i].error - Kpid[i].last_error) * frequency;
	if( fabs(Kpid[i].ui) > max_ui )
		Kpid[i].ui = (Kpid[i].ui >= 0)? max_ui: -1*max_ui;
	Kpid[i].u = Kpid[i].up + Kpid[i].ui + Kpid[i].ud;

	Kpid[i].last_error = Kpid[i].error;

	Kpid[i].pulse = fabs(Kpid[i].u) * PWM_ARR;
	if(Kpid[i].pulse > PWM_ARR)	Kpid[i].pulse = PWM_ARR;
}
