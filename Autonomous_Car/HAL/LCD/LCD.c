/*
 * LCD.c
 *
 *  Created on: Sep 29, 2023
 *      Author: Mohamed
 */

#include "LCD.h"

//static u32 Counter = 0;

void HAL_LCD_u8LCDInit() {
	MCAL_DIO_u8SetPinDirection(LCD_D_PORT, LCD_D7_PIN, Pin_High);
	MCAL_DIO_u8SetPinDirection(LCD_D_PORT, LCD_D6_PIN, Pin_High);
	MCAL_DIO_u8SetPinDirection(LCD_D_PORT, LCD_D5_PIN, Pin_High);
	MCAL_DIO_u8SetPinDirection(LCD_D_PORT, LCD_D4_PIN, Pin_High);
	MCAL_DIO_u8SetPinDirection(RS_Port, RS_Pin, Pin_High);
	MCAL_DIO_u8SetPinDirection(RW_Port, RW_Pin, Pin_High);
	MCAL_DIO_u8SetPinDirection(Enable_PORT, Enable_PIN, Pin_High);
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Reset);
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Function_Set);
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Display_Mode);
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Display_Clear);
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Entry_Mode);
}

void HAL_LCD_u8SendCommands(u8 Loc_u8LCD_Command) {
	MCAL_DIO_u8SetPinValue(RS_Port, RS_Pin, RS_Low);
	MCAL_DIO_u8SetPinValue(RW_Port, RW_Pin, RW_Low);
	MCAL_DIO_u8SetPortValue(LCD_D_PORT, Loc_u8LCD_Command);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_High);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_Low);
	MCAL_DIO_u8SetPortValue(LCD_D_PORT, (Loc_u8LCD_Command << 4));
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_High);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_Low);
}

void HAL_LCD_u8SendChar(u8 Loc_u8LCD_Char) {
	MCAL_DIO_u8SetPinValue(RS_Port, RS_Pin, RS_High);
	MCAL_DIO_u8SetPinValue(RW_Port, RW_Pin, RW_Low);
	MCAL_DIO_u8SetPortValue(LCD_D_PORT, Loc_u8LCD_Char);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_High);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_Low);
	MCAL_DIO_u8SetPortValue(LCD_D_PORT, (Loc_u8LCD_Char << 4));
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_High);
	_delay_ms(2);
	MCAL_DIO_u8SetPinValue(Enable_PORT, Enable_PIN, Enable_Low);
}

void HAL_LCD_u8SendString(u8* Loc_u8LCD_String) {
	for (u32 count = 0; Loc_u8LCD_String[count] != '\0'; count++) {
		HAL_LCD_u8SendChar(Loc_u8LCD_String[count]);
	}
}

void HAL_LCD_u8SendNumber(u16 Loc_u8LCD_Number) {
	u8 str[10];
	itoa(Loc_u8LCD_Number, str, 10);
	HAL_LCD_u8SendString(str);
}

void HAL_LCD_u8GoTo(u8 Loc_u8TypeOfShift, u8 Loc_u8NumOfShift) {
	if (Loc_u8TypeOfShift == Right_Shift) {
		for (u32 count = 0; count < Loc_u8NumOfShift; count++) {
			_delay_ms(2);
			HAL_LCD_u8SendCommands(Right_Shift_Command);
		}
	} else if (Loc_u8TypeOfShift == Left_Shift) {
		for (u32 count = 0; count < Loc_u8NumOfShift; count++) {
			_delay_ms(2);
			HAL_LCD_u8SendCommands(Left_Shift_Command);
		}
	} else if (Loc_u8TypeOfShift == First_Line) {
		_delay_ms(2);
		HAL_LCD_u8SendCommands(beginning_1stLine);
	} else if (Loc_u8TypeOfShift == Second_Line) {
		_delay_ms(2);
		HAL_LCD_u8SendCommands(beginning_2stLine);
	}
}

void HAL_LCD_u8Clear() {
	_delay_ms(2);
	HAL_LCD_u8SendCommands(Display_Clear);
}

void HAL_LCD_u8CustomChar(u8 Loc_u8Location, u8* Loc_u8msg) {
	if (Loc_u8Location < 8) {
		HAL_LCD_u8SendCommands(0x40 + (Loc_u8Location*8));
		for( u8 count = 0; count < 8; count++)
			HAL_LCD_u8SendChar(Loc_u8msg[count]);
	}
	HAL_LCD_u8SendCommands(0x02);
}

