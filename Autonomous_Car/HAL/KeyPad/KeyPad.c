/*
 * KeyPad.c
 *
 *  Created on: Sep 30, 2023
 *      Author: Mohamed
 */

#include "KeyPad.h"

u8 array[4][4] = { { '1', '2', '3', 'A' }, { '4', '5', '6', 'B' }, { '7', '8',
		'9', 'C' }, { '*', '0', '#', 'D' } };
u8 KetPadValue = 0;

void HAL_KeyPad_u8KeyPadInit() {
	MCAL_DIO_u8SetPortDirection(2, 0x0F);
	MCAL_DIO_u8SetPortValue(2, PORT_OUTPUT);
}

//STD_Type HAL_KeyPad_u8GetKeyPressed(u8 *Button) {
//	u8 c = 3;
//	for (u32 col = 0; col < 4; col++) {
//		u8 r = 3;
//		MCAL_DIO_u8SetPinValue(2, col, 0);
//		for (u32 row = 4; row < 8; row++) {
//			MCAL_DIO_u8GetPinValue(2, row, &KetPadValue);
//			if (KetPadValue == 0) {
//				_delay_ms(5);
//				MCAL_DIO_u8GetPinValue(2, row, &KetPadValue);
//				if (KetPadValue == 1) {
//					*Button = array[r][c];
//				}
//			}
//			r--;
//		}
//		c--;
//		MCAL_DIO_u8SetPinValue(2, col, 1);
//	}
//}

void HAL_KeyPad_u8GetKeyPressed(u8 *Button) {

	u8 LOC_u8Col, LOC_u8Row, LOC_u8Status = 7, LOC_u8PinValue;
	*Button = 0;
	for (LOC_u8Row = 0; LOC_u8Row < 4; LOC_u8Row++) {
		//  LOC_u8Return_Value = MCAL_DIO_u8SetPinValue(KeyPad_Port,R0,Pin_HIGH);
		//  LOC_u8Return_Value = MCAL_DIO_u8SetPinValue(KeyPad_Port,R1,Pin_HIGH);
		//  LOC_u8Return_Value = MCAL_DIO_u8SetPinValue(KeyPad_Port,R2,Pin_HIGH);
		//  LOC_u8Return_Value = MCAL_DIO_u8SetPinValue(KeyPad_Port,R3,Pin_HIGH);
		MCAL_DIO_u8SetPinValue(2, LOC_u8Row, 0);
		for (LOC_u8Col = 0; LOC_u8Col < 4; LOC_u8Col++) {
			MCAL_DIO_u8GetPinValue(2, (LOC_u8Col + 4), &LOC_u8PinValue);
			LOC_u8Status = LOC_u8PinValue; //new
			if (LOC_u8PinValue == 0) {
				_delay_ms(5); //new
				MCAL_DIO_u8GetPinValue(2, (LOC_u8Col + 4), &LOC_u8PinValue); //new
				if (LOC_u8PinValue == 1) //new
						{
					_delay_ms(5);
					*Button = array[LOC_u8Row][LOC_u8Col];
				}
				break;
			}
		}
		MCAL_DIO_u8SetPinValue(2, LOC_u8Row, 1);

		/* if(LOC_u8Status==0)
		 {
		 break;
		 }
		 */
	}
}
