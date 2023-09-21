/*
 * servo.h
 *
 *  Created on: Sep 15, 2023
 *      Author: paul3
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#include "main.h"


void UART_Send(uint8_t u8_data);
void UART_Send_SetMotorPosition(uint16_t motorId,uint16_t position,uint16_t Time);




#endif /* INC_SERVO_H_ */
