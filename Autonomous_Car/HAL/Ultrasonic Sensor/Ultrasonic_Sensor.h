/*
 * Ultrasonic_Sensor.h
 *
 *  Created on: Dec 16, 2023
 *      Author: TOP_WORLD
 */

#ifndef HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Timer 0/Timer_0.h"
#include "../../MCAL/Interrupt/Interrupt.h"

#define  NUM0 0
#define  NUM1 1
#define TRIG_PORT PortD
#define TRIG_PIN 6
#define ECHO_PORT PortD
#define ECHO_PIN 2
void HAL_Ultrasonic_Sensor_voidInit(void) ;
void HAL_Ultrasonic_Sensor_voidTrigger(void);
void HAL_Ultrasonic_Sensor_voidCalcDistancse(f32*) ;
void HAL_Ultrasonic_Sensor_voidInterrupt(void);
#endif /* HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_ */
