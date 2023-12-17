/*
 * interrupt.h
 *
 *  Created on: Oct 9, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_INTERRUPT_INTERRUPT_H_
#define MCAL_INTERRUPT_INTERRUPT_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

#define ISR( vectNum ) void vectNum (void)__attribute__((signal));\
										void vectNum (void)
#define VECT_INT0 __vector_1
#define VECT_INT1 __vector_2
#define VECT_INT2 __vector_3

#define PORT_OUTPUT 0xff
#define PORT_INPUT 0x00

#define Pin_High 1
#define Pin_Low 0

#define Enable 1
#define Disable 0

#define SREG_Pin 7
#define GICR_Pin5 5
#define GICR_Pin6 6
#define GICR_Pin7 7
#define MCUCR_Pin1 1
#define MCUCR_Pin0 0

enum{Sreg,Gicr,Mcucr,Mcucsr};

void MCAL_Interrupt_u8SetRegister(u8, u8);
void MCAL_Interrupt_u8SetRegisterPin(u8, u8 ,u8 );
void MCAL_Interrupt_EXIT_CallBack_0(void (*ptr)(void));
void MCAL_Interrupt_EXIT_CallBack_1(void (*ptr)(void));
void MCAL_Interrupt_EXIT_CallBack_2(void (*ptr)(void));
void MCAL_Interrupt_InterruptInit();
void MCAL_Interrupt_EnableGIE(u8);


#endif /* MCAL_INTERRUPT_INTERRUPT_H_ */
