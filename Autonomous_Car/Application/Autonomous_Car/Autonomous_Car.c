/*
 * Autonomous_Car.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "Autonomous_Car.h"
volatile u16 Glob_u16DirLeft = NUM0;
volatile u16 Glob_u16DirRight = NUM0;
volatile u16 Glob_u16DirFront = NUM0;
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
	//Leds
	HAL_LED_u8LedInit(PortA, Pin0);
	HAL_LED_u8LedInit(PortA, Pin1);
}
void APP_Autonomous_Car_voidApp(void) {
	f32 LOC_f32Distance = NUM0;
	//	Initially Set Servo Angle 90
	HAL_SM_voidSMSetAngle(START_ANGLE);
	//Light Front LEDS
	HAL_LED_u8LedMode(PortA, Pin0, LED_ON);
	while (NUM1) {
		_delay_ms(50);
		HAL_Ultrasonic_Sensor_voidCalcDistancse(&LOC_f32Distance);
//		Glob_u16DirFront = LOC_f32Distance;
		if (LOC_f32Distance > DISTANCE_30) {
			HAL_LCD_u8Clear();
			HAL_LCD_u8SendString("Moving Front...");
			HAL_LCD_u8GoTo(Second_Line, NUM0);
			HAL_LCD_u8SendString("Distance: ");
			_delay_ms(50);
			HAL_Ultrasonic_Sensor_voidCalcDistancse(&LOC_f32Distance);
			_delay_ms(50);
			Glob_u16DirFront = LOC_f32Distance;
			HAL_LCD_u8SendNumber(Glob_u16DirFront);
			_delay_ms(20);
			HAL_LCD_u8SendString("cm");
			HAL_void_H_BridgeFront(MAX_SPEED);
			HAL_LED_u8LedMode(PortA, Pin1, LED_OFF);
		} else if (LOC_f32Distance <= DISTANCE_30) {
			if (LOC_f32Distance <= DISTANCE_10) {
				HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Pin_High);
				HAL_LCD_u8Clear();
				HAL_LCD_u8SendString("Moving Back...");
				HAL_void_H_BridgeBack(MAX_SPEED);
				_delay_ms(1000);
				HAL_Buzzer_u8BuzzerMode(PortA, Pin3, Pin_Low);
			}
			HAL_void_H_BridgeStop(NUM0);
			HAL_LED_u8LedMode(PortA, Pin1, LED_ON);
			for (int i = START_ANGLE; i >= MAX_CCW_ANGLE; i -= NUM_2) {
				HAL_SM_voidSMSetAngle(i);
				if (i == MAX_CCW_ANGLE) {
					_delay_ms(50);
					HAL_Ultrasonic_Sensor_voidCalcDistancse(&LOC_f32Distance);
					_delay_ms(50);
					Glob_u16DirRight = LOC_f32Distance;
					HAL_LCD_u8Clear();
					HAL_LCD_u8SendString("Dir Right: ");
					HAL_LCD_u8SendNumber(Glob_u16DirRight);
					HAL_LCD_u8SendString("cm");
					_delay_ms(200);
					for (int j = MAX_CCW_ANGLE; j <= MAX_CW_ANGLE; j += NUM_2) {
						HAL_SM_voidSMSetAngle(j);
						if (j == MAX_CW_ANGLE) {
							_delay_ms(50);
							HAL_Ultrasonic_Sensor_voidCalcDistancse(
									&LOC_f32Distance);
							_delay_ms(50);
							Glob_u16DirLeft = LOC_f32Distance;
							HAL_LCD_u8Clear();
							HAL_LCD_u8SendString("Dir Left: ");
							HAL_LCD_u8SendNumber(Glob_u16DirLeft);
							HAL_LCD_u8SendString("cm");
							_delay_ms(200);
							for (int k = MAX_CW_ANGLE; k >= START_ANGLE; k -=
							NUM_2) {
								HAL_SM_voidSMSetAngle(k);
							}
						}
					}
				}
			}
			if (Glob_u16DirLeft > Glob_u16DirRight) {
				HAL_LCD_u8Clear();
				HAL_LCD_u8SendString("Moving Left...");
				HAL_LCD_u8GoTo(Second_Line, NUM0);
				HAL_LCD_u8SendString("Distance: ");
				HAL_LCD_u8SendNumber((u16) Glob_u16DirLeft);
				HAL_LCD_u8SendString("cm");
				HAL_void_H_BridgeCCW(MAX_SPEED);
				_delay_ms(900);
			} else if (Glob_u16DirRight >= Glob_u16DirLeft) {
				HAL_LCD_u8Clear();
				HAL_LCD_u8SendString("Moving Right...");
				HAL_LCD_u8GoTo(Second_Line, NUM0);
				HAL_LCD_u8SendString("Distance: ");
				HAL_LCD_u8SendNumber((u16) Glob_u16DirRight);
				HAL_LCD_u8SendString("cm");
				HAL_void_H_BridgeCW(MAX_SPEED);
				_delay_ms(900);
			} else {
				//NOTHING
			}
		} else {
			//NOTHING
		}
	}

}
