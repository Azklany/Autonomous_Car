/*
 * Push_Button.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

/*
 * Buzzer.c
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

#include "PushButton.h"

u8 Glob_PB0_u8PinValue=0;
u8 Glob_PB1_u8PinValue=0;
u8 Glob_PB2_u8PinValue=0;

STD_Type HAL_PushButton_u8PushButtonInit(u8 Loc_u8PushButtonPortID,
		u8 Loc_u8PushButtonPinID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PushButtonPortID <= PortD && Loc_u8PushButtonPinID <= Num_Of_Pins) {
		Loc_u8Return_Value = MCAL_DIO_u8SetPinDirection(Loc_u8PushButtonPortID,
				Loc_u8PushButtonPinID, Pin_High);
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

STD_Type HAL_PushButton_u8PushButtonCheck(u8 Loc_u8PushButtonPortID,
		u8 Loc_u8PushButtonPinID) {
	u8 Loc_u8Return_Value = E_NOT_OK;
	if (Loc_u8PushButtonPortID <= PortD && Loc_u8PushButtonPinID <= Num_Of_Pins) {
		if(Loc_u8PushButtonPinID==PushButton0_PIN){
			Loc_u8Return_Value = MCAL_DIO_u8GetPinValue(Loc_u8PushButtonPortID,
					Loc_u8PushButtonPinID, &Glob_PB0_u8PinValue);
		}
		else if(Loc_u8PushButtonPinID==PushButton1_PIN){
			Loc_u8Return_Value = MCAL_DIO_u8GetPinValue(Loc_u8PushButtonPortID,
					Loc_u8PushButtonPinID, &Glob_PB1_u8PinValue);
		}
		else if(Loc_u8PushButtonPinID==PushButton2_PIN){
			Loc_u8Return_Value = MCAL_DIO_u8GetPinValue(Loc_u8PushButtonPortID,
					Loc_u8PushButtonPinID, &Glob_PB2_u8PinValue);
		}
		else{
			//Do Nothing
		}
	} else {
		//Do Nothing
	}
	return Loc_u8Return_Value;
}

