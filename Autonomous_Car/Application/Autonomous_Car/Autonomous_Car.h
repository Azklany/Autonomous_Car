/*
 * Autonomous_Car.h
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#ifndef APPLICATION_AUTONOMOUS_CAR_AUTONOMOUS_CAR_H_
#define APPLICATION_AUTONOMOUS_CAR_AUTONOMOUS_CAR_H_
#include "../../HAL/H_Bridge/H_Bridge.h"
#include "../../HAL/Servo Motor/Servo_Motor.h"
#include "../../HAL/Ultrasonic Sensor/Ultrasonic_Sensor.h"
#include "../../HAL/LED/LED.h"
#include "../../HAL/LCD/LCD.h"
#include "../../HAL/Buzzer/Buzzer.h"
#define START_ANGLE 90
#define MAX_CW_ANGLE 180
#define MAX_CCW_ANGLE 0
#define DISTANCE_30 30.0
#define DISTANCE_10 10.0
#define MAX_SPEED 99
#define NUM_2 2
void APP_Autonomous_Car_voidInit(void) ;
void APP_Autonomous_Car_voidApp(void) ;
#endif /* APPLICATION_AUTONOMOUS_CAR_AUTONOMOUS_CAR_H_ */
