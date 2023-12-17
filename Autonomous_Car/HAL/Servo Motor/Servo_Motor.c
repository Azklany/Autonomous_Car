///*
// * Servo_Motor.c
// *
// *  Created on: Oct 29, 2023
// *      Author: TOP_WORLD
// */
//#include "Servo_Motor.h"
//void HAL_SM_voidSMInit(void){
//	f32 Tick_Time=0;
//	MCAL_T1_u8T1Init(FAST_PWM_ICR1);
//	MCAL_T1_u8T1Prescaler(PRESCALLING_64,&Tick_Time);
//	MCAL_T1_u8T1CompareOutputMode(NON_INVERTING_MODE,CHENNEL_A);
//	MCAL_T1_voidSetICR1Value(INIT_VALUE);
//	MCAL_T1_voidSetOCR1AValue(START_ZERO);
//
//}
//void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle){
//	if(LOC_u8Angle<=MAX_ANGLE&&LOC_u8Angle>=MIN_ANGLE){
//	u16 SetAngle=START_ZERO+((LOC_u8Angle/MAX_ANGLE)*BETWEEN_0_180);
//	MCAL_T1_voidSetOCR1AValue(SetAngle);
//	}else {
//		//NOTHING
//	}
//}
