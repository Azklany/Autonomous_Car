/*
 * KeyPad.h
 *
 *  Created on: Sep 30, 2023
 *      Author: Mohamed
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../MCAL/DIO/DIO.h"

#define PullUp 1
#define High 1
#define Low 1

#define Pressed 1

#define Rows_Input PullUp
#define Colums_Output High

void HAL_KeyPad_u8KeyPadInit();
void HAL_KeyPad_u8GetKeyPressed();

#endif /* HAL_KEYPAD_KEYPAD_H_ */
