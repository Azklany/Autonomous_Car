/*
 * Servo_Motor.h
 *
 *  Created on: Oct 29, 2023
 *      Author: TOP_WORLD
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_H_

#include "../../MCAL/DIO/DIO.h"

#define MAX_ANGLE 180.0
#define MIN_ANGLE 0
void HAL_SM_voidSMInit(void);
void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle);
#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_H_ */
