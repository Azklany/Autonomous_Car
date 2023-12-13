/*
 * UART.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

void MCAL_UART_UARTInit(void);
void MCAL_UART_UARTTransmit(u8);
void MCAL_UART_UARTReceive(u8*);

//UCSRB PINS
#define RXEN_PIN 4
#define TXEN_PIN 3
#define UCSZ2_PIN 2
//UCSRC PINS
#define URSEL_PIN 7
#define USBS_PIN 3
#define UCSZ0_PIN 1
#define UCSZ1_PIN 2
#define UCSRC_Size 0b10001110
//UCSRA PINS
#define UDRE_PIN 5
#define RXC_PIN 7
#define TXC_PIN 6

#define Baud_Rate 103
#define Shift_8_bit 8

#endif /* MCAL_UART_UART_H_ */
