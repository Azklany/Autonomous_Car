/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "main.h"
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Timer 0/Timer_0.h"
#include "../SERVICE/ICU_Interface.h"

int main(void) {
//	HAL_SM_voidSMInit();
//			HAL_SM_voidSMSetAngle(i);
	u16 period_Ticks = 0;
	  u16 on_Ticks = 0;
	  	SET_BIT(DDRD, Pin3);
	  	MCAL_DIO_u8SetPinDirection(PortB, Pin3, Pin_High); //PWM
	  	//T0
	  	MCAL_Timer0_Init(FastPWM_Mode,Prescaller_8,Non_Inverted);
	  	MCAL_Timer0_SetCompareValue(64);

	  	while (1) {
	  	ICU_SW_init(&period_Ticks,&on_Ticks);
	  		if (on_Ticks == 64) {
	  			SET_BIT(PORTD, Pin3);
	  		}
	  	}

//	while (1) {
//		for (int i = 0; i <= 180; i += 5) {
//			HAL_SM_voidSMSetAngle(i);
//			_delay_ms(40);
//			if (i == 180) {
//				for (int i = 180; i >= 0; i -= 5) {
//					HAL_SM_voidSMSetAngle(i);
//					_delay_ms(40);
//				}
//			}
//
//		}
//	}
}
