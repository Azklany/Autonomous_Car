/*
 * Push_Button.h
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

#ifndef HAL_PUSH_BUTTON_PUSHBUTTON_H_
#define HAL_PUSH_BUTTON_PUSHBUTTON_H_

#include "../../MCAL/DIO/DIO.h"

#define PushButton0_PORT PortB
#define PushButton0_PIN 0
#define PushButton1_PORT PortD
#define PushButton1_PIN 6
#define PushButton2_PORT PortD
#define PushButton2_PIN 2

extern u8 Glob_PB0_u8PinValue;
extern u8 Glob_PB1_u8PinValue;
extern u8 Glob_PB2_u8PinValue;

STD_Type HAL_PushButton_u8PushButtonInit(u8, u8);
STD_Type HAL_PushButton_u8PushButtonCheck(u8, u8);

#endif /* HAL_PUSH_BUTTON_PUSHBUTTON_H_ */
