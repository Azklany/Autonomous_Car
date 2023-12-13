/*
 * Buzzer.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

#include "Buzzer.h"

STD_Type HAL_Buzzer_u8BuzzerInit(u8 Loc_u8BuzzerPortID, u8 Loc_u8BuzzerPinID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8BuzzerPortID <= PortD && Loc_u8BuzzerPinID <= Num_Of_Pins) {
		Loc_u8Return_Value=Loc_u8Return_Value = MCAL_DIO_u8SetPinDirection(Loc_u8BuzzerPortID,
				Loc_u8BuzzerPinID, Pin_High);
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type HAL_Buzzer_u8BuzzerMode(u8 Loc_u8BuzzerPortID, u8 Loc_u8BuzzerPinID,
		u8 Loc_u8BuzzerMode) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8BuzzerPortID <= PortD && Loc_u8BuzzerPinID <= Num_Of_Pins
			&& Loc_u8BuzzerMode <= Buzzer_TOG) {
		if (Loc_u8BuzzerMode == Buzzer_ON) {
			Loc_u8Return_Value=MCAL_DIO_u8SetPinValue(Loc_u8BuzzerPortID, Loc_u8BuzzerPinID, Pin_High);
		} else if (Loc_u8BuzzerMode == Buzzer_OFF) {
			Loc_u8Return_Value=MCAL_DIO_u8SetPinValue(Loc_u8BuzzerPortID, Loc_u8BuzzerPinID, Pin_Low);
		} else if (Loc_u8BuzzerMode == Buzzer_TOG) {
			Loc_u8Return_Value=MCAL_DIO_u8TogglePinValue(Loc_u8BuzzerPortID,Loc_u8BuzzerPinID);
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

