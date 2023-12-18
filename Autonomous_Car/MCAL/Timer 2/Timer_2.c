/*
 * Timer_2.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Mohamed
 */

#include "Timer_2.h"

f32 Glob_TickTimeT2;

void MCAL_Timer2_Init(u8 Loc_u8Mode, u8 Loc_u8Prescaller, u8 Loc_u8OC0Mode) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	SET_BIT(SREG, 7);
	if (Loc_u8Mode == Normal_Mode_T2) {
		CLR_BIT(TCCR2, 3);
		CLR_BIT(TCCR2, 6);
		SET_BIT(TIMSK, 0);
	} else if (Loc_u8Mode == CTC_Mode_T2) {
		SET_BIT(TCCR2, 3);
		CLR_BIT(TCCR2, 6);
		SET_BIT(TIMSK, 1);
	} else if (Loc_u8Mode == PWM_Mode_T2) {
		CLR_BIT(TCCR2, 3);
		SET_BIT(TCCR2, 6);
	} else if (Loc_u8Mode == FastPWM_Mode_T2) {
		SET_BIT(TCCR2, 3);
		SET_BIT(TCCR2, 6);
		SET_BIT(TIMSK, 1);
	}
	if (Loc_u8Prescaller == NoPrescallerT2) {
		CLR_BIT(TCCR2, 0);
		CLR_BIT(TCCR2, 1);
		CLR_BIT(TCCR2, 2);
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_1T2) {
		SET_BIT(TCCR2, 0);
		CLR_BIT(TCCR2, 1);
		CLR_BIT(TCCR2, 2);
		Glob_TickTimeT2 = Prescaller1_ValueT2 / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_8T2) {
		CLR_BIT(TCCR2, 0);
		SET_BIT(TCCR2, 1);
		CLR_BIT(TCCR2, 2);
		Glob_TickTimeT2 = Prescaller8_ValueT2 / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_32T2) {
		SET_BIT(TCCR2, 0);
		SET_BIT(TCCR2, 1);
		CLR_BIT(TCCR2, 2);
		Glob_TickTimeT2 = Prescaller32_ValueT2 / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_64T2) {
		CLR_BIT(TCCR2, 0);
		CLR_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		Glob_TickTimeT2 = Prescaller64_ValueT2 / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_128T2) {
		SET_BIT(TCCR2, 0);
		CLR_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		Glob_TickTimeT2 = Prescaller128_ValueT2 / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_256T2) {
		CLR_BIT(TCCR2, 0);
		SET_BIT(TCCR2, 1);
		SET_BIT(TCCR2, 2);
		LOC_u8ReturnValue = E_OK;
	} else {
		//NOTHING
	}
	if (Loc_u8OC0Mode == DisconnectedT2) {
		CLR_BIT(TCCR2, 4);
		CLR_BIT(TCCR2, 5);
	} else if (Loc_u8OC0Mode == ReservedT2) {
		SET_BIT(TCCR2, 4);
		CLR_BIT(TCCR2, 5);
		//PWM, Fast PWM
	} else if (Loc_u8OC0Mode == Non_InvertedT2) {
		SET_BIT(TCCR2, 5);
		CLR_BIT(TCCR2, 4);
		// OC2
		SET_BIT(DDRD, 7);
		//PWM, Fast PWM
	} else if (Loc_u8OC0Mode == InvertedT2) {
		SET_BIT(TCCR0, 4);
		SET_BIT(TCCR0, 5);
		// OC2
		SET_BIT(DDRD, 7);
	}
}
void MCAL_Timer2_SetPreloadValue(u8 Loc_u8Value) {
	TCNT2 = Loc_u8Value;
}
void MCAL_Timer2_SetCompareValue(u8 Loc_u8Value) {
	OCR2 = Loc_u8Value;
}
void MCAL_Timer2_EnableNormalMode() {
	SET_BIT(TIMSK, 0);
}
void MCAL_Timer2_DisableNormalMode() {
	CLR_BIT(TIMSK, 0);
}
void MCAL_Timer2_EnableCTCMode() {
	SET_BIT(TIMSK, 1);
}
void MCAL_Timer2_DisableCTCMode() {
	CLR_BIT(TIMSK, 1);
}

//void MCAL_Timer0_CallBack(void (*ptr)(void)) {
//	if (ptr != '\0')
//		Gptr3 = ptr;
//}

//ISR( TIMER0__OVF_vect) {
//	if (Gptr3 != '\0')
//		Gptr3();
//}
//ISR( TIMER0_COMP_vect) {
//	if (Gptr3 != '\0')
//		Gptr3();
//}

