/*
 * chassis_kinetics.h
 *
 *  Created on: Jul 27, 2023
 *      Author: kch93
 */

#ifndef INC_CHASSIS_KINETIC_MODEL_H_
#define INC_CHASSIS_KINETIC_MODEL_H_

//ROS_PORT data for Chassis
typedef struct{
	double Vx, Vy, w;
}Chassis_data;




//kinetic models
namespace Mecanum_O{
	//wheel_data
	const double lx=193.39, ly=236.555;
	const double radius=129;
	//translation
	void inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP);
	void forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV);
}

namespace Mecanum_X{
	//wheel_data
	const double lx=10, ly=10;
	const double radius=129;
	//translation
	void inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP);
	void forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV);
}


#endif /* INC_CHASSIS_KINETIC_MODEL_H_ */
