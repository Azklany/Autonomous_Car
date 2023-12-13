/*
 * MCU.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Mohamed
 */

#ifndef COMMONS_MCU_H_
#define COMMONS_MCU_H_

#include "STD_Types.h"

//DIO
#define DDRA (*(volatile u8*)0x3A)
#define DDRB (*(volatile u8*)0x37)
#define DDRC (*(volatile u8*)0x34)
#define DDRD (*(volatile u8*)0x31)

#define PORTA (*(volatile u8*)0x3B)
#define PORTB (*(volatile u8*)0x38)
#define PORTC (*(volatile u8*)0x35)
#define PORTD (*(volatile u8*)0x32)

#define PINA (*(volatile u8*)0x39)
#define PINB (*(volatile u8*)0x36)
#define PINC (*(volatile u8*)0x33)
#define PIND (*(volatile u8*)0x30)

//interrupt
#define SREG (*(volatile u8*)0x5F)
#define GICR (*(volatile u8*)0x5B)
#define GIFR (*(volatile u8*)0x5A)
#define MCUCR (*(volatile u8*)0x55)
#define MCUCSR (*(volatile u8*)0x54)

//ADC
#define ADMUX (*(volatile u8*)0x27)
#define ADCSRA (*(volatile u8*)0x26)
#define ACDH (*(volatile u8*)0x25)
#define ACDL (*(volatile u8*)0x24)
#define SFIOR (*(volatile u8*)0x50)

//Timer0
#define TIMSK (*(volatile u8*)0x59)
#define OCR0 (*(volatile u8*)0x5c)
#define TCCR0 (*(volatile u8*)0x53)
#define TCNT0 (*(volatile u8*)0x52)

//Timer1
#define TCCR1A *((volatile u8*)0x4F)
#define TCCR1B *((volatile u8*)0x4E)
#define TCNT1H *((volatile u8*)0x4D)
#define TCNT1L *((volatile u8*)0x4C)
#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)
#define ICR1H *((volatile u8*)0x47)
#define ICR1L *((volatile u8*)0x46)
#define ICR1 (*(volatile uint16_t *)((0x26) + 0x20))
#define OCR1A (*(volatile uint16_t *)((0x2A) + 0x20))
#define OCR1B (*(volatile uint16_t *)((0x28) + 0x20))

//WDT
#define WDTCR (*(volatile u8*)0x41)

//UART
#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRH (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)
#define UDR (*(volatile u8*)0x2C)

//SPI
#define SPCR (*(volatile u8*)0x2D)
#define SPSR (*(volatile u8*)0x2E)
#define SPDR (*(volatile u8*)0x2F)

//TWI
#define TWCR (*(volatile u8*)0x56)
#define TWDR (*(volatile u8*)0x23)
#define TWAR (*(volatile u8*)0x22)
#define TWBR (*(volatile u8*)0x20)

//#define GIE (*(volatile u8*)0x5f)

#endif /* COMMONS_MCU_H_ */
