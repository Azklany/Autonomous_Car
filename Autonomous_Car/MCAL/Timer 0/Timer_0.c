/*
 * Timer_0.c
 *
 *  Created on: Oct 18, 2023
 *      Author: Mohamed
 */

#include "../Timer 0/Timer_0.h"

void (*Gptr3)(void)= '\0' ;
f32 Glob_TickTime;
u16 Start = 0;
u16 Counter = 0;

void MCAL_Timer0_Init(u8 Loc_u8Mode, u8 Loc_u8Prescaller,u8 Loc_u8OC0Mode) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	SET_BIT(SREG, 7);
	if (Loc_u8Mode == Normal_Mode) {
		CLR_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		SET_BIT(TIMSK, 0);
	} else if (Loc_u8Mode == CTC_Mode) {
		SET_BIT(TCCR0, 3);
		CLR_BIT(TCCR0, 6);
		SET_BIT(TIMSK, 1);
	} else if (Loc_u8Mode == PWM_Mode) {
		CLR_BIT(TCCR0, 3);
		SET_BIT(TCCR0, 6);
	} else if (Loc_u8Mode == FastPWM_Mode) {
//		SET_BIT(TCCR0, 3);
//		SET_BIT(TCCR0, 6);
		SET_BIT(TIMSK, 1);
	}
	if (Loc_u8Prescaller == NoPrescaller) {
		CLR_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_1) {
		SET_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
		Glob_TickTime = Prescaller1_Value / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_8) {
		CLR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
		Glob_TickTime = Prescaller8_Value / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_64) {
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		CLR_BIT(TCCR0, 2);
		Glob_TickTime = Prescaller64_Value / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_256) {
		CLR_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		Glob_TickTime = Prescaller256_Value / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Prescaller_1024) {
		SET_BIT(TCCR0, 0);
		CLR_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		Glob_TickTime = Prescaller1024_Value / (f32) CPU_Frequancy;
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Clock_on_falling_edge) {
		CLR_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		LOC_u8ReturnValue = E_OK;
	} else if (Loc_u8Prescaller == Clock_on_rising_edge) {
		SET_BIT(TCCR0, 0);
		SET_BIT(TCCR0, 1);
		SET_BIT(TCCR0, 2);
		LOC_u8ReturnValue = E_OK;
	} else {
		//NOTHING
	}
	if (Loc_u8OC0Mode == Disconnected) {
			CLR_BIT(TCCR0, 4);
			CLR_BIT(TCCR0, 5);
		} else if (Loc_u8OC0Mode == Reserved) {
			SET_BIT(TCCR0, 4);
			CLR_BIT(TCCR0, 5);
			//PWM, Fast PWM
		} else if (Loc_u8OC0Mode == Non_Inverted) {
			SET_BIT(TCCR0, 5);
			CLR_BIT(TCCR0, 4);
			// OC0
			SET_BIT(DDRB, 3);
			//PWM, Fast PWM
		} else if (Loc_u8OC0Mode == Inverted) {
			SET_BIT(TCCR0, 4);
			SET_BIT(TCCR0, 5);
			// OC0
			SET_BIT(DDRB, 3);
		}
}
void MCAL_Timer0_SetPreloadValue(u8 Loc_u8Value) {
	TCNT0 = Loc_u8Value;
}
void MCAL_Timer0_SetCompareValue(u8 Loc_u8Value) {
	OCR0 = Loc_u8Value;
}
void MCAL_Timer0_EnableNormalMode() {
	SET_BIT(TIMSK, 0);
}
void MCAL_Timer0_DisableNormalMode() {
	CLR_BIT(TIMSK, 0);
}
void MCAL_Timer0_EnableCTCMode() {
	SET_BIT(TIMSK, 1);
}
void MCAL_Timer0_DisableCTCMode() {
	CLR_BIT(TIMSK, 1);
}

void MCAL_Timer0_Delayms_NormalMode(u32 Loc_u32MilliSeconds) {
	u32 N = 0;
	N = (Loc_u32MilliSeconds / 1000.0) / (f32) Glob_TickTime;
	Start = N % 256;
	if (Start == 0) {
		MCAL_Timer0_SetPreloadValue(Start);
		Counter = N / 256;
	} else if (Start != 0) {
		MCAL_Timer0_SetPreloadValue(Start);
		Counter = ((N / 256) + 1);
	} else {
		//NOTHING
	}
}
void MCAL_Timer0_Delayms_CTCMode(u32 Loc_u32MilliSeconds) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	f32 N = 0;
	MCAL_Timer0_SetCompareValue(CompareStartValue);
	N = ((CompareStartValue + 1) * Glob_TickTime);
	Counter = ((Loc_u32MilliSeconds/1000.0) / N);

	LOC_u8ReturnValue = E_OK;
}

void MCAL_Timer0_CallBack(void (*ptr)(void)) {
	if (ptr != '\0')
		Gptr3 = ptr;
}

ISR(TIMER0_OVF_vect) {
	if (Gptr3 != '\0')
		Gptr3();
}
ISR(TIMER0_COMP_vect) {
	if (Gptr3 != '\0')
		Gptr3();
}

