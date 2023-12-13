/*
 * Buzzer.h
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "../../MCAL/DIO/DIO.h"

#define Buzzer_PORT PortA
#define Buzzer_PIN 3

enum {
	Buzzer_OFF, Buzzer_ON, Buzzer_TOG
};

STD_Type HAL_Buzzer_u8BuzzerInit(u8,u8);
STD_Type HAL_Buzzer_u8BuzzerMode(u8,u8,u8);


#endif /* HAL_BUZZER_BUZZER_H_ */
