/*
 * Timer1.c
 *
 *  Created on: Oct 22, 2023
 *      Author: TOP_WORLD
 */
#include "Timer1.h"
void (*Gptr_3)(void)='\0';

u8 MCAL_T1_u8T1Init(u8 LOC_u8Timer1Mode) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8Timer1Mode <= FAST_PWM_OCR1A) {
		if (LOC_u8Timer1Mode == NORMAL_MODE) {
			CLR_BIT(TCCR1A, Pin0);
			CLR_BIT(TCCR1A, Pin1);
			CLR_BIT(TCCR1B, Pin3);
			CLR_BIT(TCCR1B, Pin4);
			LOC_u8ReturnValue = E_OK;
		}    else if (LOC_u8Timer1Mode == FAST_PWM_10bit) {
			SET_BIT(TCCR1A, Pin0);
			SET_BIT(TCCR1A, Pin1);
			SET_BIT(TCCR1B, Pin3);
			CLR_BIT(TCCR1B, Pin4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_ICR1) {
			CLR_BIT(TCCR1A, Pin0);
			SET_BIT(TCCR1A, Pin1);
			SET_BIT(TCCR1B, Pin3);
			SET_BIT(TCCR1B, Pin4);
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Timer1Mode == FAST_PWM_OCR1A) {
			SET_BIT(TCCR1A, Pin0);
			SET_BIT(TCCR1A, Pin1);
			SET_BIT(TCCR1B, Pin3);
			SET_BIT(TCCR1B, Pin4);
			LOC_u8ReturnValue = E_OK;
		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}
u8 MCAL_T1_u8T1Prescaler(u8 LOC_u8Clock_Selection, f32 *LOC_pf32TickTime) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8Clock_Selection <= EXTERNAL_RISING_EDGE) {
		 if (LOC_u8Clock_Selection == PRESCALLING_8) {
			CLR_BIT(TCCR1B, Pin0);
			SET_BIT(TCCR1B, Pin1);
			CLR_BIT(TCCR1B, Pin2);
			*LOC_pf32TickTime = PRESCALLING8 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		} else if (LOC_u8Clock_Selection == PRESCALLING_64) {
			SET_BIT(TCCR1B, Pin0);
			SET_BIT(TCCR1B, Pin1);
			CLR_BIT(TCCR1B, Pin2);
			*LOC_pf32TickTime = PRESCALLING64 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		}  else if (LOC_u8Clock_Selection == PRESCALLING_1024) {
			SET_BIT(TCCR1B, Pin0);
			CLR_BIT(TCCR1B, Pin1);
			SET_BIT(TCCR1B, Pin2);
			*LOC_pf32TickTime = PRESCALLING1024 / (f32) CPU_FREQUNCY;
			LOC_u8ReturnValue = E_OK;
		}  else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}
//Fast MODE PWM & PHASE CORRECT
u8 MCAL_T1_u8T1CompareOutputMode(u8 LOC_u8OutputMode, u8 LOC_u8Channel) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (LOC_u8OutputMode <= INVERTING_MODE && LOC_u8Channel <= CHENNEL_B) {
		if (LOC_u8Channel == CHENNEL_A) {
			if (LOC_u8OutputMode == NON_INVERTING_MODE) {
				CLR_BIT(TCCR1A, Pin6);
				SET_BIT(TCCR1A, Pin7);
				SET_BIT(DDRD, Pin5);
				LOC_u8ReturnValue = E_OK;
			} else if (LOC_u8OutputMode == INVERTING_MODE) {
				SET_BIT(TCCR1A, Pin6);
				SET_BIT(TCCR1A, Pin7);
				SET_BIT(DDRD, Pin5);
				LOC_u8ReturnValue = E_OK;
			} else {
				//NOTHING
			}
		} else if (LOC_u8Channel == CHENNEL_B) {
			if (LOC_u8OutputMode == NON_INVERTING_MODE) {
				CLR_BIT(TCCR1A, Pin4);
				SET_BIT(TCCR1A, Pin5);
				SET_BIT(DDRD, Pin4);
				LOC_u8ReturnValue = E_OK;
			} else if (LOC_u8OutputMode == INVERTING_MODE) {
				SET_BIT(TCCR1A, Pin4);
				SET_BIT(TCCR1A, Pin5);
				SET_BIT(DDRD, Pin4);
				LOC_u8ReturnValue = E_OK;
			} else {
				//NOTHING
			}

		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
	return LOC_u8ReturnValue;
}

//Set TCNT1 Value
void MCAL_T1_voidSetTCNT1Value(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		TCNT1 = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//GIT TCNT1
void MCAL_T1_voidGetTCNT1Value(u16 *LOC_pu16Value) {
	if (LOC_pu16Value) {
		*LOC_pu16Value = TCNT1;
	}
}
//Set OCR1A
void MCAL_T1_voidSetOCR1AValue(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		OCR1A = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//SET OCR1B
void MCAL_T1_voidSetOCR1BValue(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		OCR1B = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//SET ICR1
void MCAL_T1_voidSetICR1Value(u16 LOC_u16Value) {
	if (LOC_u16Value <= SIXTEEN_BIT_MAX_VALUE) {
		ICR1 = LOC_u16Value;
	} else {
		//NOTHING
	}
}
//Get ICR1
void MCAL_T1_voidGetICR1Value(u16 *LOC_pu16Value) {
	if (LOC_pu16Value) {
		*LOC_pu16Value = ICR1;
	}
}
//TCNT1 PIE
void MCAL_T1_voidTCNT1_GIEEnable(void) {
	SET_BIT(SREG, Pin7);
	SET_BIT(TIMSK, Pin2);
}
void MCAL_T1_voidTCNT1_GIEDisable(void) {
	CLR_BIT(TIMSK, Pin2);
}
//OCR1B PIE
void MCAL_T1_voidOCR1B_GIEEnable(void) {
	SET_BIT(SREG, Pin7);
	SET_BIT(TIMSK, Pin3);
}
void MCAL_T1_voidOCR1B_GIEDisable(void) {
	CLR_BIT(TIMSK, Pin3);
}
//OCR1A PIE
void MCAL_T1_voidOCR1A_GIEEnable(void) {
	SET_BIT(SREG, Pin7);
	SET_BIT(TIMSK, Pin4);
}
void MCAL_T1_voidOCR1A_GIEDisable(void) {
	CLR_BIT(TIMSK, Pin4);
}
//ICR1 PIE
void MCAL_T1_voidICR1_GIEEnable(void) {
	SET_BIT(SREG, Pin7);
	SET_BIT(TIMSK, Pin5);
}
void MCAL_T1_voidICR1_GIEDisable(void) {
	CLR_BIT(TIMSK, Pin5);
}



//ICU EDGE
void MCAL_T1_voidSetTriggerEdge(u8 LOC_u8TriggerEdge) {
	if (LOC_u8TriggerEdge <= RISING_EDGE) {
		if (LOC_u8TriggerEdge == RISING_EDGE) {
			SET_BIT(TCCR1B, Pin6);
		} else if (LOC_u8TriggerEdge == FALLING_EDGE) {
			CLR_BIT(TCCR1B, Pin6);
		} else {
			//NOTHING
		}
	} else {
		//NOTHING
	}
}
u8 MCAL_T1_u8T1_Callback(void (*ptr)(void)) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	if (ptr != '\0') {
		Gptr_3 = ptr;
		LOC_u8ReturnValue = E_OK;
	}
	return LOC_u8ReturnValue;
}

ISR(TIMER1_OVF_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}
//ISR(TIMER1_COMPA_vect) {
//	if (Gptr_3 != '\0') {
//		Gptr_3();
//	}
//}
ISR(TIMER1_COMPB_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}
ISR(TIMER1_CAPT_vect) {
	if (Gptr_3 != '\0') {
		Gptr_3();
	}
}

void MCAL_T1_FPWM_10bitRES(u8 copy_u8Channel, u8 copy_u8Duty) {
	f32 LOC_f32tickTime = 0;
	//Set Mode
	MCAL_T1_u8T1Init(PWM_PHASE_CORRECT_10bit);
	//Select Prescaler
	MCAL_T1_u8T1Prescaler(PRESCALLING_64, &LOC_f32tickTime);
	MCAL_T1_u8T1CompareOutputMode(NON_INVERTING_MODE, copy_u8Channel);
	if (copy_u8Channel == CHENNEL_A) {
		OCR1A = copy_u8Duty * 10.23;
	} else if (copy_u8Channel == CHENNEL_B) {
		OCR1B = copy_u8Duty * 10.23;

	} else {
		//NOTHING
	}
}
