/*
 * DIO.c
 *
 *  Created on: Sep 24, 2023
 *      Author: Mohamed
 */

#include "DIO.h"

STD_Type MCAL_DIO_u8SetPortDirection(u8 Loc_u8PortID, u8 Loc_u8PortDirection) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PortDirection <= PORT_OUTPUT) {
		if (Loc_u8PortDirection == PORT_OUTPUT) {
			if (Loc_u8PortID == PortA) {
				DDRA = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				DDRB = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				DDRC = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				DDRD = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else if (Loc_u8PortDirection == PORT_INPUT) {
			if (Loc_u8PortID == PortA) {
				DDRA = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				DDRB = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				DDRC = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				DDRD = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else {
			if (Loc_u8PortID == PortA) {
				DDRA = Loc_u8PortDirection;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				DDRB = Loc_u8PortDirection;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				DDRC = Loc_u8PortDirection;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				DDRD = Loc_u8PortDirection;
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type MCAL_DIO_u8SetPinDirection(u8 Loc_u8PortID, u8 Loc_u8PinID,
		u8 Loc_u8PinDirection) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PinID <= Num_Of_Pins
			&& Loc_u8PinDirection <= Pin_High) {
		if (Loc_u8PinDirection == Pin_High) {
			if (Loc_u8PortID == PortA) {
				SET_BIT(DDRA, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				SET_BIT(DDRB, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				SET_BIT(DDRC, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				SET_BIT(DDRD, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else if (Loc_u8PinDirection == Pin_Low) {
			if (Loc_u8PortID == PortA) {
				CLR_BIT(DDRA, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				CLR_BIT(DDRB, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				CLR_BIT(DDRC, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				CLR_BIT(DDRD, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;

}

STD_Type MCAL_DIO_u8SetPortValue(u8 Loc_u8PortID, u8 Loc_u8PortValue) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PortValue <= PORT_OUTPUT) {
		if (Loc_u8PortValue == PORT_OUTPUT) {
			if (Loc_u8PortID == PortA) {
				PORTA = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				PORTB = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				PORTC = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				PORTD = PORT_OUTPUT;
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else if (Loc_u8PortValue == PORT_INPUT) {
			if (Loc_u8PortID == PortA) {
				PORTA = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				PORTB = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				PORTC = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				PORTD = PORT_INPUT;
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else {
			if (Loc_u8PortID == PortA) {
				PORTA = Loc_u8PortValue;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				PORTB = Loc_u8PortValue;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				PORTC = Loc_u8PortValue;
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				PORTD = Loc_u8PortValue;
				Loc_u8Return_Value = E_OK;
			}
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type MCAL_DIO_u8SetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID,
		u8 Loc_u8PinValue) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PinID <= Num_Of_Pins
			&& Loc_u8PinValue <= Pin_High) {
		if (Loc_u8PinValue == Pin_High) {
			if (Loc_u8PortID == PortA) {
				SET_BIT(PORTA, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				SET_BIT(PORTB, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				SET_BIT(PORTC, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				SET_BIT(PORTD, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else if (Loc_u8PinValue == Pin_Low) {
			if (Loc_u8PortID == PortA) {
				CLR_BIT(PORTA, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortB) {
				CLR_BIT(PORTB, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortC) {
				CLR_BIT(PORTC, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else if (Loc_u8PortID == PortD) {
				CLR_BIT(PORTD, Loc_u8PinID);
				Loc_u8Return_Value = E_OK;
			} else {
				//Do Nothing
			}
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;

}

STD_Type MCAL_DIO_u8SGetPortValue(u8 Loc_u8PortID, u8* Loc_u8PortValue) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD) {
		if (Loc_u8PortID == PortA) {
			*Loc_u8PortValue = PORTA;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortB) {
			*Loc_u8PortValue = PORTB;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortC) {
			*Loc_u8PortValue = PORTC;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortD) {
			*Loc_u8PortValue = PORTD;
			Loc_u8Return_Value = E_OK;
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type MCAL_DIO_u8GetPinValue(u8 Loc_u8PortID, u8 Loc_u8PinID,
		u8* Loc_u8PinValue) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PinID <= Num_Of_Pins) {
		if (Loc_u8PortID == PortA) {
			*Loc_u8PinValue = GET_BIT(PINA, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortB) {
			*Loc_u8PinValue = GET_BIT(PINB, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortC) {
			*Loc_u8PinValue = GET_BIT(PINC, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortD) {
			*Loc_u8PinValue = GET_BIT(PIND, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type MCAL_DIO_u8TogglePortValue(u8 Loc_u8PortID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD) {
		if (Loc_u8PortID == PortA) {
			PORTA = ~PORTA;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortB) {
			PORTB = ~PORTB;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortC) {
			PORTC = ~PORTC;
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortD) {
			PORTD = ~PORTD;
			Loc_u8Return_Value = E_OK;
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type MCAL_DIO_u8TogglePinValue(u8 Loc_u8PortID, u8 Loc_u8PinID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PortID <= PortD && Loc_u8PinID <= Num_Of_Pins) {
		if (Loc_u8PortID == PortA) {
			TOGGLE_BIT(PORTA, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortB) {
			TOGGLE_BIT(PORTB, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortC) {
			TOGGLE_BIT(PORTC, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else if (Loc_u8PortID == PortD) {
			TOGGLE_BIT(PORTD, Loc_u8PinID);
			Loc_u8Return_Value = E_OK;
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

