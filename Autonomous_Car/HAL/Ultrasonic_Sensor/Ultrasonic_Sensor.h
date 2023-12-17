/*
 * Ultrasonic_Sensor.h
 *
 *  Created on: Dec 16, 2023
 *      Author: TOP_WORLD
 */

#ifndef HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_
#define F_CPU 16000000UL
#define  NUM0 0
#define  NUM1 1
#define TRIG_PORT PortD
#define TRIG_PIN 6
#define ECHO_PORT PortD
#define ECHO_PIN 2
void ultrasonic_init(void);
void EXTI_action(void);
void ultrasonic_sendTrigger(void);
void ultrasonic_get_Distance(f32* returned_distance);
#endif /* HAL_ULTRASONIC_SENSOR_ULTRASONIC_SENSOR_H_ */
