/*
 * Servo_Motor.h
 *
 *  Created on: Oct 29, 2023
 *      Author: TOP_WORLD
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_H_

#include "../../MCAL/Timer 1/Timer1.h"
#include "../../MCAL/DIO/DIO.h"
#define INIT_VALUE 4999
#define START_ZERO 138
#define BETWEEN_0_180 508
#define MAX_ANGLE 180.0
#define MIN_ANGLE 0
void HAL_SM_voidSMInit(void);
void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle);
#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_H_ */
