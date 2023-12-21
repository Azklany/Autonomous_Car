/*
 * Servo_Motor.c
 *
 *  Created on: Oct 29, 2023
 *      Author: TOP_WORLD
 */
#include "Servo_Motor.h"
void HAL_SM_voidSMInit(void) {
	MCAL_Timer2_Init(FastPWM_Mode_T2, Prescaller_64T2, Non_InvertedT2);
	SET_BIT(DDRD,Pin7);
//	MCAL_T1_u8T1Init(FAST_PWM_ICR1);
//	MCAL_T1_u8T1Prescaler(PRESCALLING_64,&Tick_Time);
//	MCAL_T1_u8T1CompareOutputMode(NON_INVERTING_MODE,CHENNEL_A);
//	MCAL_T1_voidSetICR1Value(INIT_VALUE);
//	MCAL_T1_voidSetOCR1AValue(START_ZERO);
//	MCAL_Timer2_SetCompareValue(START_ZERO);
}
void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle) {
	if (LOC_u8Angle <= MAX_ANGLE && LOC_u8Angle >= MIN_ANGLE) {
		u8 SetAngle = 240 ;//+ ((LOC_u8Angle / MAX_ANGLE) * 390);
//	MCAL_T1_voidSetOCR1AValue(SetAngle);
		MCAL_Timer2_SetCompareValue(SetAngle);
	} else {
		//NOTHING
	}
}
