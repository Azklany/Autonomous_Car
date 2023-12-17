/*
 * interrupt.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Mohamed
 */

#include "Interrupt.h"

void (*Gptr0)(void)= '\0' ;
void (*Gptr1)(void)= '\0' ;
void (*Gptr2)(void)= '\0' ;

void MCAL_Interrupt_u8SetRegister(u8 Loc_u8PortID, u8 Loc_u8PortValue) {
	if (Loc_u8PortValue == PORT_OUTPUT) {
		if (Loc_u8PortID == Sreg) {
			SREG = PORT_OUTPUT;
		} else if (Loc_u8PortID == Gicr) {
			GICR = PORT_OUTPUT;
		} else if (Loc_u8PortID == Mcucr) {
			MCUCR = PORT_OUTPUT;
		} else if (Loc_u8PortID == Mcucsr) {
			MCUCSR = PORT_OUTPUT;
		} else {
			//Do Nothing
		}
	} else if (Loc_u8PortValue == PORT_INPUT) {
		if (Loc_u8PortID == Sreg) {
			SREG = PORT_INPUT;
		} else if (Loc_u8PortID == Gicr) {
			GICR = PORT_INPUT;
		} else if (Loc_u8PortID == Mcucr) {
			MCUCR = PORT_INPUT;
		} else if (Loc_u8PortID == Mcucsr) {
			MCUCSR = PORT_INPUT;
		} else {
			//Do Nothing
		}
	} else {
		if (Loc_u8PortID == Sreg) {
			SREG = Loc_u8PortValue;
		} else if (Loc_u8PortID == Gicr) {
			GICR = Loc_u8PortValue;
		} else if (Loc_u8PortID == Mcucr) {
			MCUCR = Loc_u8PortValue;
		} else if (Loc_u8PortID == Mcucsr) {
			MCUCSR = Loc_u8PortValue;
		}
	}
}

void MCAL_Interrupt_u8SetRegisterPin(u8 Loc_u8PortID, u8 Loc_u8PinID,
		u8 Loc_u8PinValue) {
	if (Loc_u8PinValue == Pin_High) {
		if (Loc_u8PortID == Sreg) {
			SET_BIT(SREG, Loc_u8PinID);
		} else if (Loc_u8PortID == Gicr) {
			SET_BIT(GICR, Loc_u8PinID);
		} else if (Loc_u8PortID == Mcucr) {
			SET_BIT(MCUCR, Loc_u8PinID);
		} else if (Loc_u8PortID == Mcucsr) {
			SET_BIT(MCUCSR, Loc_u8PinID);
		} else {
			//Do Nothing
		}
	} else if (Loc_u8PinValue == Pin_Low) {
		if (Loc_u8PortID == Sreg) {
			CLR_BIT(SREG, Loc_u8PinID);
		} else if (Loc_u8PortID == Gicr) {
			CLR_BIT(GICR, Loc_u8PinID);
		} else if (Loc_u8PortID == Mcucr) {
			CLR_BIT(MCUCR, Loc_u8PinID);
		} else if (Loc_u8PortID == Mcucsr) {
			CLR_BIT(MCUCSR, Loc_u8PinID);
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
}

void MCAL_Interrupt_EXIT_CallBack_0(void (*ptr)(void)) {
	if (ptr != '\0')
		Gptr0 = ptr;
}
void MCAL_Interrupt_EXIT_CallBack_1(void (*ptr)(void)) {
	if (ptr != '\0')
		Gptr1 = ptr;
}
void MCAL_Interrupt_EXIT_CallBack_2(void (*ptr)(void)) {
	if (ptr != '\0')
		Gptr2 = ptr;
}

void MCAL_Interrupt_EnableGIE(u8 Loc_u8value) {
	if (Loc_u8value == Enable) {
		MCAL_Interrupt_u8SetRegisterPin(Sreg, SREG_Pin, Pin_High);
	} else if (Loc_u8value == Disable) {
		MCAL_Interrupt_u8SetRegisterPin(Sreg, SREG_Pin, Pin_Low);
	}
}

void MCAL_Interrupt_InterruptRisingInit() {
	MCAL_Interrupt_u8SetRegisterPin(Gicr, GICR_Pin6, Pin_High);
	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin0 , Pin_High);
	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin1 , Pin_High);
}
void MCAL_Interrupt_InterruptFallingInit() {
	MCAL_Interrupt_u8SetRegisterPin(Gicr, GICR_Pin6, Pin_High);
	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin0 , Pin_Low);
	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin1 , Pin_High);
}

ISR(VECT_INT0) {
	if (Gptr0 != '\0')
		Gptr0();
}
ISR(VECT_INT1) {
	if (Gptr1 != '\0')
		Gptr1();
}
ISR(VECT_INT2) {
	if (Gptr2 != '\0')
		Gptr2();
}
