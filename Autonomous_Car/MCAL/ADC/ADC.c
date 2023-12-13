/*
 * ADC.c
 *
 *  Created on: Oct 10, 2023
 *      Author: Mohamed
 */

#include "ADC.h"

void (*Gptr_ADC)(void)= '\0' ;

void MCAL_ADC_u8SetRegister(u8 Loc_u8PortID, u8 Loc_u8PortValue) {
	if (Loc_u8PortValue == PORT_OUTPUT) {
		if (Loc_u8PortID == Admux) {
			ADMUX = PORT_OUTPUT;
		} else if (Loc_u8PortID == Adcsra) {
			ADCSRA = PORT_OUTPUT;
		} else if (Loc_u8PortID == Sfior) {
			SFIOR = PORT_OUTPUT;
		} else {
			//Do Nothing
		}
	} else if (Loc_u8PortValue == PORT_INPUT) {
		if (Loc_u8PortID == Admux) {
			ADMUX = PORT_INPUT;
		} else if (Loc_u8PortID == Adcsra) {
			ADCSRA = PORT_INPUT;
		} else if (Loc_u8PortID == Sfior) {
			SFIOR = PORT_INPUT;
		} else {
			//Do Nothing
		}
	} else {
		if (Loc_u8PortID == Admux) {
			ADMUX = Loc_u8PortValue;
		} else if (Loc_u8PortID == Adcsra) {
			ADCSRA = Loc_u8PortValue;
		} else if (Loc_u8PortID == Sfior) {
			SFIOR = Loc_u8PortValue;
		}
	}
}

void MCAL_ADC_u8SetRegisterPin(u8 Loc_u8PortID, u8 Loc_u8PinID,
		u8 Loc_u8PinValue) {
	if (Loc_u8PinValue == Pin_High) {
		if (Loc_u8PortID == Admux) {
			SET_BIT(ADMUX, Loc_u8PinID);
		} else if (Loc_u8PortID == Adcsra) {
			SET_BIT(ADCSRA, Loc_u8PinID);
		} else if (Loc_u8PortID == Sfior) {
			SET_BIT(SFIOR, Loc_u8PinID);
		} else {
			//Do Nothing
		}
	} else if (Loc_u8PinValue == Pin_Low) {
		if (Loc_u8PortID == Admux) {
			CLR_BIT(ADMUX, Loc_u8PinID);
		} else if (Loc_u8PortID == Adcsra) {
			CLR_BIT(ADCSRA, Loc_u8PinID);
		} else if (Loc_u8PortID == Sfior) {
			CLR_BIT(SFIOR, Loc_u8PinID);
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
}

void MCAL_ADC_AdcInit(u8 Loc_u8Position) {
	MCAL_ADC_u8SetRegister(Adcsra, ADCSRA_VALUE);
	MCAL_ADC_u8SetRegisterPin(Sfior, 7, Pin_Low);
	MCAL_ADC_u8SetRegisterPin(Sfior, 6, Pin_Low);
	MCAL_ADC_u8SetRegisterPin(Sfior, 5, Pin_Low);
	MCAL_Interrupt_u8SetRegisterPin(SREG, 7, Pin_High);
	if (Loc_u8Position == Adc_0) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc0);
	} else if (Loc_u8Position == Adc_1) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc1);
	} else if (Loc_u8Position == Adc_2) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc2);
	} else if (Loc_u8Position == Adc_3) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc3);
	} else if (Loc_u8Position == Adc_4) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc4);
	} else if (Loc_u8Position == Adc_5) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc5);
	} else if (Loc_u8Position == Adc_6) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc6);
	} else if (Loc_u8Position == Adc_7) {
		MCAL_ADC_u8SetRegister(Admux, ADUMX_Value_Adc7);
	} else {
		//Do Nothing
	}
}

void MCAL_ADC_AdcStartConversion(u8 Loc_u8Value) {
	if (Loc_u8Value == Enable) {
		MCAL_ADC_u8SetRegisterPin(Adcsra, 6, Enable);
	} else if (Loc_u8Value == Disable) {
		MCAL_ADC_u8SetRegisterPin(Adcsra, 6, Disable);
	} else {
		//NOTHING
	}
}

u8 MCAL_ADC_u8AdcSetValue(u16 *Loc_u16Value) {
	u8 LOC_u8ReturnValue = E_NOT_OK;
	*Loc_u16Value = (((u32) ADC * 5000) / 1024);
	return LOC_u8ReturnValue;
}

void MCAL_ADC_EXIT_CallBack(void (*ptr)(void)) {
	if (ptr != '\0')
		Gptr_ADC = ptr;
}

ISR(ADC_vect) {
	if (Gptr_ADC != '\0')
		Gptr_ADC();
}
