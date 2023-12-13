/*
 * ADC.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

#define ISR( vectNum ) void vectNum (void)__attribute__((signal));\
										void vectNum (void)
#define ADC (*(volatile u16*)((0x04) + 0x20))

#define ADC_vect __vector_16

#define PORT_OUTPUT 0xff
#define PORT_INPUT 0x00

#define Enable 1
#define Disable 0

#define Pin_High 1
#define Pin_Low 0

#define Adc_0 0
#define Adc_1 1
#define Adc_2 2
#define Adc_3 3
#define Adc_4 4
#define Adc_5 5
#define Adc_6 6
#define Adc_7 7

enum {
	Admux, Adcsra, Sfior
};

#define ADUMX_Value_Adc0 0b01000000
#define ADUMX_Value_Adc1 0b01000001
#define ADUMX_Value_Adc2 0b01000010
#define ADUMX_Value_Adc3 0b01000011
#define ADUMX_Value_Adc4 0b01000100
#define ADUMX_Value_Adc5 0b01000101
#define ADUMX_Value_Adc6 0b01000110
#define ADUMX_Value_Adc7 0b01000111
#define ADCSRA_VALUE 0b10101111

void MCAL_ADC_u8SetRegister(u8, u8);
void MCAL_ADC_u8SetRegisterPin(u8, u8, u8);
void MCAL_ADC_AdcInit(u8);
void MCAL_ADC_AdcStartConversion(u8);
void MCAL_ADC_EXIT_CallBack(void (*ptr)(void));
u8 MCAL_ADC_u8AdcSetValue(u16 *);

#endif /* MCAL_ADC_ADC_H_ */
