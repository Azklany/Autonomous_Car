/*
 * Autonomous_Car.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */
#include "../../HAL/H_Bridge/H_Bridge.h"
#include "../../HAL/Servo Motor/Servo_Motor.h"
#include "../../HAL/Ultrasonic Sensor/Ultrasonic_Sensor.h"
#include "../../HAL/LCD/LCD.h"
#include "../../HAL/Buzzer/Buzzer.h"
#include "Autonomous_Car.h"
volatile f32 Glob_f32AnglesDistance[2];
void APP_Autonomous_Car_voidInit(void) {
	//Init Buzzer
	HAL_Buzzer_u8BuzzerInit(PortA, Pin3);
	//Init LCD
	HAL_LCD_u8LCDInit();
	//Init Servo Motor
	HAL_SM_voidSMInit();
	//Init UltraSonic Sensor
	HAL_Ultrasonic_Sensor_voidInit();
	//Init H_Bridge
	HAL_void_H_BridgeInit();

}
void APP_Autonomous_Car_voidApp(void) {
	//Start
	f32 Loc_f32Distance = 0;
	HAL_SM_voidSMSetAngle(90);
	while (1) {
		HAL_Ultrasonic_Sensor_voidCalcDistancse(&Loc_f32Distance);
		if (Loc_f32Distance <= 30.0) {
		HAL_void_H_BridgeStop(0);
			for (int i = 90; i >= 0; i -= 5) {
				 if (i == 90)
					Glob_f32AnglesDistance[0] = Loc_f32Distance;
				HAL_SM_voidSMSetAngle(i);
				_delay_ms(40);
				if (i == 0) {
					for (int i = 0; i <= 180; i += 5) {
						if (i == 180)
							Glob_f32AnglesDistance[1] = Loc_f32Distance;
						HAL_SM_voidSMSetAngle(i);
						_delay_ms(40);
						if (i == 180) {
							for (int i = 180; i >= 90; i -= 5) {
								HAL_SM_voidSMSetAngle(i);
								_delay_ms(40);
							}
						}
					}
				}

			}
		}
//		HAL_void_H_BridgeFront(90);
	}
}

