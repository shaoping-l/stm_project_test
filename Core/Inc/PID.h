#ifndef INC_PID_H_
#define INC_PID_H_

#include <math.h>
#include <stdint.h>
#include "mainpp.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define frequency 250
#define resolution 512
#define reduction_ratio 216
#define belt_ratio 0.5
#define max_ui 1
#define PWM_ARR 999
#define Dwheel 12.9		//wheelDiameter_cm
#define width 48		//cm
#define length 41.5		//cm

typedef struct{
	double Kp;
	double Ki;
	double Kd;
	int16_t enc;
	double goalVel;		//m/s
	double insVel;		//m/s
	double error;
	double last_error;
	double u;
	double up;
	double ui;
	double ud;
	double pulse;
	double cD;
}KPID;

extern KPID Kpid[4];

void pidCtrl(int i);

#ifdef __cplusplus
}
#endif

#endif /* INC_PID_H_ */
