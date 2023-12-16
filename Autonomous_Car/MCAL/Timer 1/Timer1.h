/*
 * Timer1.h
 *
 *  Created on: Oct 22, 2023
 *      Author: TOP_WORLD
 */

#ifndef MCAL_TIMER_1_TIMER1_H_
#define MCAL_TIMER_1_TIMER1_H_
#include "../../Commons/STD_Types.h"
#include "../../Commons/Macros.h"
#include "../../Commons/MCU.h"
#include "../DIO/DIO.h"
#define ISR(vectNum) void vectNum (void) __attribute__((signal));\
	void vectNum (void)

#define TIMER1_OVF_vect __vector_9
//#define TIMER1_COMPA_vect __vector_7
#define TIMER1_CAPT_vect __vector_6
#define TIMER1_COMPB_vect __vector_8
//Edge
#define FALLING_EDGE 0
#define RISING_EDGE 1
#define NORMAL_MODE                                 0
#define PWM_PHASE_CORRECT_8bit                      1
#define PWM_PHASE_CORRECT_9bit                      2
#define PWM_PHASE_CORRECT_10bit                     3
#define CTC_OCR1A                                   4
#define FAST_PWM_8bit                               5
#define FAST_PWM_9bit                               6
#define FAST_PWM_10bit                              7
#define PWM_PHASE_AND_FREQUANCY_CORRECT_ICR1        8
#define PWM_PHASE_AND_FREQUANCY_CORRECT_OCR1A       9
#define PWM_PHASE_CORRECT_ICR1                      10
#define PWM_PHASE_CORRECT_OCR1A                     11
#define CTC_ICR1                                    12
#define REVERSED_MODE                               13
#define FAST_PWM_ICR1                               14
#define FAST_PWM_OCR1A                              15
//PRESCALER
#define COUNTER_STOP 0
#define PRESCALLING_0 1
#define PRESCALLING_8 2
#define PRESCALLING_64 3
#define PRESCALLING_256 4
#define PRESCALLING_1024 5
#define EXTERNAL_FALLING_EDGE 6
#define EXTERNAL_RISING_EDGE 7
#define PRESCALLING0 1
#define PRESCALLING8 8
#define PRESCALLING64 64
#define PRESCALLING256 256
#define PRESCALLING1024 1024
#define CPU_FREQUNCY 16000000
//Compare Output
#define NON_INVERTING_MODE 0
#define INVERTING_MODE 1
//Channel
#define CHENNEL_A 0
#define CHENNEL_B 1
//Over FLOW
#define OVER_FLOW_COUNT 65535
#define NUMBER_1 1
#define NUMBER_0 0
//DELAY CTC CONSTANT
#define CTC_DELAY_CONST 199
//16Bit
#define SIXTEEN_BIT_MAX_VALUE 65635
u8 MCAL_T1_u8T1Init(u8 LOC_u8Timer1Mode);
u8 MCAL_T1_u8T1Prescaler(u8 LOC_u8Clock_Selection, f32 *LOC_pfl32TickTime);
u8 MCAL_T1_u8T1CompareOutputMode(u8 LOC_u8OutputMode, u8 LOC_u8Channel);
u8 MCAL_T1_u8T1_Callback(void (*ptr)(void));
void MCAL_T1_voidNoiseCancller(void);
void MCAL_T1_voidSetTCNT1Value(u16 LOC_u16Value);
void MCAL_T1_voidSetOCR1AValue(u16 LOC_u16Value);
void MCAL_T1_voidSetOCR1BValue(u16 LOC_u16Value);
void MCAL_T1_voidSetICR1Value(u16 LOC_u16Value);
void MCAL_T1_voidGetTCNT1Value(u16 *LOC_pu16Value);
void MCAL_T1_voidGetICR1Value(u16 *LOC_pu16Value);
void MCAL_T1_voidTCNT1_GIEDisable(void);
void MCAL_T1_voidOCR1A_GIEDisable(void);
void MCAL_T1_voidOCR1B_GIEDisable(void);
void MCAL_T1_voidICR1_GIEDisable(void);
void MCAL_T1_voidTCNT1_GIEEnable(void);
void MCAL_T1_voidOCR1A_GIEEnable(void);
void MCAL_T1_voidOCR1B_GIEEnable(void);
void MCAL_T1_voidICR1_GIEEnable(void);
u8 MCAL_T1_u8T1DelayNormalMode(u8 LOC_u8Clock_Selection,
		f32 LOC_fl32NumOFSecond, u16 *LOC_pu8StartValue, u16 *LOC_pu16Counter);
void MCAL_T1_voidDelayCTCMode(u8 LOC_u8Clock_Selection, f32 LOC_fl32NumOFSecond,
		u16 *LOC_pu16Counter);
void MCAL_T1_voidSetTriggerEdge(u8 LOC_u8TriggerEdge);
void MCAL_T1_FPWM_10bitRES(u8 copy_u8Channel, u8 copy_u8Duty);
#endif /* MCAL_TIMER_1_TIMER1_H_ */
