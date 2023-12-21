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

		SET_BIT(DDRD,Pin7);
	while (1) {
		SET_BIT(PORTD,Pin7);
		_delay_us(140);
		CLR_BIT(PORTD,Pin7);
		_delay_us(19860);
	}
}
