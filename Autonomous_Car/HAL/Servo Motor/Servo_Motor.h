/*
 * Servo_Motor.h
 *
 *  Created on: Oct 29, 2023
 *      Author: TOP_WORLD
 */

#ifndef HAL_SERVO_MOTOR_SERVO_MOTOR_H_
#define HAL_SERVO_MOTOR_SERVO_MOTOR_H_

#include "../../MCAL/Timer 2/Timer_2.h"
#include "../../MCAL/DIO/DIO.h"
#define INIT_VALUE 4999
#define START_ZERO 660
#define BETWEEN_0_180 280
#define MAX_ANGLE 180.0
#define MIN_ANGLE 0
#define MIN_PWM_VALUE 100
#define MAX_PWM_VALUE 200
void HAL_SM_voidSMInit(void);
void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle);
u8 map(u8 LOC_u8Angle, u8 Angle_0, u8 Angle_180, u8 Min_PWM_Value, u8 Max_PWM_Value) ;
#endif /* HAL_SERVO_MOTOR_SERVO_MOTOR_H_ */
