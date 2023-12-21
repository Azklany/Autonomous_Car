/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "Autonomous_Car/Autonomous_Car.h"
#include "../HAL/Servo Motor/Servo_Motor.h"
int main(void) {
//	APP_Autonomous_Car_voidInit();
//	APP_Autonomous_Car_voidApp();
//	f32 x=0;
//	    SET_BIT(DDRD,Pin3);
//	  	 SET_BIT(SREG,Pin7);
//	    HAL_Ultrasonic_Sensor_voidInit();
//	    MCAL_Timer0_Init(Normal_Mode,Prescaller_64,Non_Inverted);
//	    MCAL_Timer0_SetPreloadValue(113);
//	    while(1){
//	    	HAL_Ultrasonic_Sensor_voidCalcDistancse(&x);
//	    	if(x>100){
//	    		SET_BIT(PORTD,Pin3);
//	    	}else {
//	    		CLR_BIT(PORTD,Pin3);
//
//			}
//	    }

	SET_BIT(DDRD, Pin7);
	HAL_SM_voidSMSetAngle(90);
	_delay_ms(2000);
	while (1) {
		for (int i = 90; i >= 0; i -= 2) {
			HAL_SM_voidSMSetAngle(i);
			_delay_ms(1);
			if (i == 0) {
				_delay_ms(200);
				for (int i = 0; i <= 180; i += 2) {
					HAL_SM_voidSMSetAngle(i);
					_delay_ms(1);
					if (i == 180) {
						_delay_ms(200);
						for (int i = 180; i >= 90; i -= 2) {
							HAL_SM_voidSMSetAngle(i);
							_delay_ms(1);
						}
					}
				}

			}
		}
	}
}
