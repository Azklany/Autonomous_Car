/*
 * LED.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */
#include "LED.h"

STD_Type HAL_LED_u8LedInit(u8 Loc_u8LEDPortID, u8 Loc_u8LEDPinID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8LEDPortID <= PortD && Loc_u8LEDPinID <= Num_Of_Pins) {
		Loc_u8Return_Value = MCAL_DIO_u8SetPinDirection(Loc_u8LEDPortID,
				Loc_u8LEDPinID, Pin_High);
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type HAL_LED_u8LedMode(u8 Loc_u8LEDPortID, u8 Loc_u8LEDPinID,
		u8 Loc_u8LEDMode) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8LEDPortID <= PortD && Loc_u8LEDPinID <= Num_Of_Pins
			&& Loc_u8LEDMode <= LED_TOG) {
		if (Loc_u8LEDMode == LED_ON) {
			Loc_u8Return_Value = MCAL_DIO_u8SetPinValue(Loc_u8LEDPortID,
					Loc_u8LEDPinID, Pin_High);
		} else if (Loc_u8LEDMode == LED_OFF) {
			Loc_u8Return_Value = MCAL_DIO_u8SetPinValue(Loc_u8LEDPortID,
					Loc_u8LEDPinID, Pin_Low);
		} else if (Loc_u8LEDMode == LED_TOG) {
			Loc_u8Return_Value = MCAL_DIO_u8TogglePinValue(Loc_u8LEDPortID,
					Loc_u8LEDPinID);
		} else {
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}
