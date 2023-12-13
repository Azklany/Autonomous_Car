/*
 * DIO.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

//////////
//#include <avr\io.h>
#include <util\delay.h>
////////
#define PORT_INPUT 0x00
#define PORT_OUTPUT 0xff

//#define PIN_INPUT 0x00
//#define PIN_OUTPUT 0xff

#define Num_Of_Pins 7

#define Pin0 0
#define Pin1 1
#define Pin2 2
#define Pin3 3
#define Pin4 4
#define Pin5 5
#define Pin6 6
#define Pin7 7

enum {
	PortA, PortB, PortC, PortD
};

//enum {
//	E_OK, E_NOT_OK
//};

//enum {
//	Port_Low, Port_High
//};

#define Pin_High 1
#define Pin_Low 0

STD_Type MCAL_DIO_u8SetPortDirection(u8, u8);
STD_Type MCAL_DIO_u8SetPinDirection(u8, u8, u8);
STD_Type MCAL_DIO_u8SetPortValue(u8, u8);
STD_Type MCAL_DIO_u8SetPinValue(u8, u8, u8);
STD_Type MCAL_DIO_u8SGetPortValue(u8, u8*);
STD_Type MCAL_DIO_u8GetPinValue(u8, u8, u8*);
STD_Type MCAL_DIO_u8TogglePortValue(u8);
STD_Type MCAL_DIO_u8TogglePinValue(u8, u8);

#endif /* MCAL_DIO_DIO_H_ */
