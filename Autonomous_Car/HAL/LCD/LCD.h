/*
 * LCD.h
 *
 *  Created on: Sep 29, 2023
 *      Author: Mohamed
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../MCAL/DIO/DIO.h"

#define Function_Set        0b00101000
#define Display_Mode        0b00001111
#define Display_Clear       0b00000001
#define Entry_Mode          0b00000110
#define Reset          0x02
#define beginning_1stLine   0x80
#define beginning_2stLine   0xc0
#define Right_Shift_Command 0x1c
#define Left_Shift_Command  0x18

#define LCD_OUTPUT 1
#define LCD_INPUT 0

#define RW_High 1
#define RW_Low 0
#define RW_Port PortB
#define RW_Pin 2

#define RS_High 1
#define RS_Low 0
#define RS_Port PortB
#define RS_Pin 1

#define Enable_High 1
#define Enable_Low 0

#define Enable_PORT PortB
#define Enable_PIN 3

#define LCD_D_PORT PortA
#define LCD_D4_PIN 4
#define LCD_D5_PIN 5
#define LCD_D6_PIN 6
#define LCD_D7_PIN 7

enum {
	Left_Shift, Right_Shift, First_Line, Second_Line
};

void HAL_LCD_u8LCDInit();
void HAL_LCD_u8SendCommands(u8);
void HAL_LCD_u8SendChar(u8);
void HAL_LCD_u8SendString(u8*);
void HAL_LCD_u8Clear();
void HAL_LCD_u8GoTo(u8, u8);
void HAL_LCD_u8CustomChar(u8, u8*);

#endif /* HAL_LCD_LCD_H_ */
