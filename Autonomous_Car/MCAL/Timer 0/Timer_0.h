/*
 * Timer_0.h
 *
 *  Created on: Oct 18, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_0_TIMER_0_H_
#define MCAL_TIMER_0_TIMER_0_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

#define ISR( vectNum ) void vectNum (void)__attribute__((signal));\
										void vectNum (void)
#define TIMER0_OVF_vect __vector_11
#define TIMER0_COMP_vect __vector_10

#define CPU_Frequancy 16000000
enum {
	Normal_Mode, CTC_Mode, PWM_Mode, FastPWM_Mode
};
#define Prescaller1_Value 1
#define Prescaller8_Value 8
#define Prescaller64_Value 64
#define Prescaller256_Value 256
#define Prescaller1024_Value 1024

#define CompareStartValue 199

enum {
	NoPrescaller,
	Prescaller_1,
	Prescaller_8,
	Prescaller_64,
	Prescaller_256,
	Prescaller_1024,
	Clock_on_falling_edge,
	Clock_on_rising_edge
};
enum{Disconnected,Reserved,Non_Inverted,Inverted};

void MCAL_Timer0_Init(u8, u8,u8);
void MCAL_Timer0_SetPreloadValue(u8);
void MCAL_Timer0_SetCompareValue(u8);
void MCAL_Timer0_EnableNormalMode();
void MCAL_Timer0_DisableNormalMode();
void MCAL_Timer0_EnableCTCMode();
void MCAL_Timer0_DisableCTCMode();
void MCAL_Timer0_Delayms_NormalMode(u32);
void MCAL_Timer0_Delayms_CTCMode(u32);

void MCAL_Timer0_CallBack(void (*ptr)(void));

#endif /* MCAL_TIMER_0_TIMER_0_H_ */
