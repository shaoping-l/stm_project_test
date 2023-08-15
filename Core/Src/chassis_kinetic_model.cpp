/*
 * chassis_kinetics.cpp
 *
 *  Created on: Jul 27, 2023
 *      Author: kch93
 */
#include <chassis_kinetic_model.h>

Chassis_data cmd_vel;
Chassis_data realspeed;


//Mecanum_O
void Mecanum_O::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
	*m1_SP= (cmd_vel.Vx-cmd_vel.Vy-cmd_vel.w*(Mecanum_O::lx+Mecanum_O::ly))/Mecanum_O::radius;
	*m2_SP= (cmd_vel.Vx+cmd_vel.Vy-cmd_vel.w*(Mecanum_O::lx+Mecanum_O::ly))/Mecanum_O::radius;
	*m3_SP= (cmd_vel.Vx-cmd_vel.Vy+cmd_vel.w*(Mecanum_O::lx+Mecanum_O::ly))/Mecanum_O::radius;
	*m4_SP= (cmd_vel.Vx+cmd_vel.Vy+cmd_vel.w*(Mecanum_O::lx+Mecanum_O::ly))/Mecanum_O::radius;
}
void Mecanum_O::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV){
	realspeed.Vx= (*m1_PV+*m2_PV+*m3_PV+*m4_PV)/4*Mecanum_O::radius;
	realspeed.Vy= (-*m1_PV+*m2_PV-*m3_PV+*m4_PV)/4*Mecanum_O::radius;
	realspeed.w= (-*m1_PV-*m2_PV+*m3_PV+*m4_PV)/(4*(Mecanum_O::lx+Mecanum_O::ly))*Mecanum_O::radius;
}

//Mecanum_X
void Mecanum_X::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
	*m1_SP= (cmd_vel.Vx+cmd_vel.Vy-cmd_vel.w*(Mecanum_X::lx-Mecanum_X::ly))/Mecanum_X::radius;
	*m2_SP= (cmd_vel.Vx-cmd_vel.Vy+cmd_vel.w*(Mecanum_X::lx-Mecanum_X::ly))/Mecanum_X::radius;
	*m3_SP= (cmd_vel.Vx+cmd_vel.Vy+cmd_vel.w*(Mecanum_X::lx-Mecanum_X::ly))/Mecanum_X::radius;
	*m4_SP= (cmd_vel.Vx-cmd_vel.Vy-cmd_vel.w*(Mecanum_X::lx-Mecanum_X::ly))/Mecanum_X::radius;
}
void Mecanum_X::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV){
	realspeed.Vx= (*m1_PV+*m2_PV+*m3_PV+*m4_PV)/4*Mecanum_X::radius;
	realspeed.Vy= (*m1_PV-*m2_PV+*m3_PV-*m4_PV)/4*Mecanum_X::radius;
	realspeed.w= (-*m1_PV+*m2_PV+*m3_PV-*m4_PV)/(4*(Mecanum_X::lx-Mecanum_X::ly))*Mecanum_X::radius;
}

