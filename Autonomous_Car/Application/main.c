/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "Autonomous_Car/Autonomous_Car.h"
int main(void) {
	APP_Autonomous_Car_voidInit();
	APP_Autonomous_Car_voidApp();
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
//	HAL_SM_voidSMInit();
//			HAL_SM_voidSMSetAngle(i);
//	u16 period_Ticks = 0;
//	  u16 on_Ticks = 0;
//	  	SET_BIT(DDRD, Pin3);
//	  	MCAL_DIO_u8SetPinDirection(PortB, Pin3, Pin_High); //PWM
//	  	//T0
//	  	MCAL_Timer0_Init(FastPWM_Mode,Prescaller_8,Non_Inverted);
//	  	MCAL_Timer0_SetCompareValue(64);
//
//	  	while (1) {
//	  	ICU_SW_init(&period_Ticks,&on_Ticks);
//	  		if (on_Ticks == 64) {
//	  			SET_BIT(PORTD, Pin3);
//	  		}
//	  	}

//	while (1) {
//
//	}
}
