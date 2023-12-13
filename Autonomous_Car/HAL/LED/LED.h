/*
 * LED.h
 *
 *  Created on: Sep 25, 2023
 *      Author: Mohamed
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include "../../MCAL/DIO/DIO.h"

#define LED0_PORT PortC
#define LED0_PIN 2
#define LED1_PORT PortC
#define LED1_PIN 7
#define LED2_PORT PortD
#define LED2_PIN 3

enum {
	LED_OFF, LED_ON, LED_TOG
};

STD_Type HAL_LED_u8LedInit(u8,u8);
STD_Type HAL_LED_u8LedMode(u8,u8,u8);

#endif /* HAL_LED_LED_H_ */
