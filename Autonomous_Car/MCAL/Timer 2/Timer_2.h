/*
 * Timer_2.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_TIMER_2_TIMER_2_H_
#define MCAL_TIMER_2_TIMER_2_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"


#define CPU_Frequancy 16000000

enum {
	Normal_Mode_T2, CTC_Mode_T2, PWM_Mode_T2, FastPWM_Mode_T2
};
#define Prescaller1_ValueT2 1
#define Prescaller8_ValueT2 8
#define Prescaller32_ValueT2 32
#define Prescaller64_ValueT2 64
#define Prescaller128_ValueT2 128
#define Prescaller256_ValueT2 256

enum {
	NoPrescallerT2,
	Prescaller_1T2,
	Prescaller_8T2,
	Prescaller_32T2,
	Prescaller_64T2,
	Prescaller_128T2,
	Prescaller_256T2,

};
enum{DisconnectedT2,ReservedT2,Non_InvertedT2,InvertedT2};
void MCAL_Timer2_Init(u8 , u8 , u8 );
void MCAL_Timer2_SetPreloadValue(u8);
void MCAL_Timer2_SetCompareValue(u8);
void MCAL_Timer2_EnableNormalMode();
void MCAL_Timer2_DisableNormalMode();
void MCAL_Timer2_EnableCTCMode();
void MCAL_Timer2_DisableCTCMode();

#endif /* MCAL_TIMER_2_TIMER_2_H_ */
