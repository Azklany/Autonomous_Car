/*
 * Autonomous_Car.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */
#include "../../HAL/H_Bridge/H_Bridge.h"
//#include "../../HAL/Servo Motor/Servo_Motor.h"
//#include "../../HAL/Ultrasonic Sensor/Ultrasonic_Sensor.h"
//#include "../../HAL/LED/LED.h"
//#include "../../HAL/LCD/LCD.h"
//#include "../../HAL/Buzzer/Buzzer.h"
//#include "Autonomous_Car.h"
//volatile f32 Glob_f32AnglesDistance[2];
void APP_Autonomous_Car_voidInit(void) {
	//Init Buzzer
//	HAL_Buzzer_u8BuzzerInit(PortA, Pin3);
	//Init LCD
//	HAL_LCD_u8LCDInit();
	//Init Servo Motor
//	HAL_SM_voidSMInit();
	//Init UltraSonic Sensor
//	HAL_Ultrasonic_Sensor_voidInit();
	//Init H_Bridge
	HAL_void_H_BridgeInit();
	//Leds
//	HAL_LED_u8LedInit(PortA, Pin0);
//	HAL_LED_u8LedInit(PortA, Pin1);
}
void APP_Autonomous_Car_voidApp(void) {
	//Start
	HAL_void_H_BridgeFront(99);
//	HAL_LED_u8LedMode(PortA, Pin0, Pin_High);
//	f32 Loc_f32Distance = 0;
//	HAL_SM_voidSMSetAngle(90);
//	_delay_ms(2000);
//	while (1) {
//		HAL_Ultrasonic_Sensor_voidCalcDistancse(&Loc_f32Distance);
//		if (Loc_f32Distance <= 30.0) {
//			HAL_void_H_BridgeStop(0);
//			HAL_LED_u8LedMode(PortA, Pin1, Pin_High);
//			for (int i = 90; i >= 0; i -= 2) {
//				if (i == 0)
//					HAL_SM_voidSMSetAngle(i);
//				_delay_ms(1);
//				if (i == 0) {
//					HAL_Ultrasonic_Sensor_voidCalcDistancse(&Loc_f32Distance);
//					Glob_f32AnglesDistance[0] = Loc_f32Distance;
//					_delay_ms(200);
//					for (int i = 0; i <= 180; i += 2) {
//						if (i == 180)
//							Glob_f32AnglesDistance[1] = Loc_f32Distance;
//						HAL_SM_voidSMSetAngle(i);
//						_delay_ms(1);
//						if (i == 180) {
//							HAL_Ultrasonic_Sensor_voidCalcDistancse(
//									&Loc_f32Distance);
//							Glob_f32AnglesDistance[1] = Loc_f32Distance;
//							_delay_ms(200);
//							for (int i = 180; i >= 90; i -= 2) {
//								HAL_SM_voidSMSetAngle(i);
//								_delay_ms(1);
//							}
//						}
//					}
//				}
//			}
//			//take
//			if (Glob_f32AnglesDistance[0] > Glob_f32AnglesDistance[1]) {
//				HAL_void_H_BridgeCW(99);
//				_delay_ms(2000);
//				HAL_void_H_BridgeFront(99);
//			} else {
//				HAL_void_H_BridgeCCW(99);
//				_delay_ms(2000);
//				HAL_void_H_BridgeFront(99);
//			}
//			HAL_LED_u8LedMode(PortA, Pin1, Pin_Low);
//
//		}
////		HAL_void_H_BridgeFront(90);
//	}
}

