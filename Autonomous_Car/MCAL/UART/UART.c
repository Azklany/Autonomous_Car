/*
 * UART.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Mohamed
 */

#include "UART.h"
//#include "avr/interrupt.h"

void MCAL_UART_UARTInit(void) {
	/* Set baud rate */
	UBRRH = (u8) (Baud_Rate >> Shift_8_bit);
	UBRRL = (u8) Baud_Rate;

	/* Enable RX and TX */
//	UCSRB = (1 << RXEN) | (1 << TXEN);
	SET_BIT(UCSRB,RXEN_PIN);
	SET_BIT(UCSRB,TXEN_PIN);

	/* Set frame format: 8data, 2stop bit */
//	UCSRC = (1 << URSEL) | (1 << USBS) | (3 << UCSZ0);
	UCSRC = UCSRC_Size;
	//Logical Error
//	SET_BIT(UCSRC,URSEL_PIN);
//	SET_BIT(UCSRC,USBS_PIN);
//	SET_BIT(UCSRC,UCSZ0_PIN);
//	SET_BIT(UCSRC,UCSZ1_PIN);
}

void MCAL_UART_UARTTransmit(u8 Loc_u8data) {
	/* Wait for empty transmit buffer */
//	while (!( UCSRA & (1 << UDRE_PIN)));
	while (GET_BIT(UCSRA,UDRE_PIN)==0);

	/* Put data into buffer, sends the data */
	UDR = Loc_u8data;

	/* Wait for data to be transmitted */
	while (GET_BIT(UCSRA,TXC_PIN)==0);
	SET_BIT(UCSRA,TXC_PIN);

}
//void MCAL_UART_UARTTransmitString(u8* Loc_u8data) {
//
//	for(u32 i=0;i<;i++){
//		MCAL_UART_UARTTransmit(Loc_u8data[i]);
//	}
//
//}

void MCAL_UART_UARTReceive(u8* Loc_u8data) {
	/* Wait for data to be received */
//	while (!(UCSRA & (1 << RXC_PIN)));
	while (GET_BIT(UCSRA,RXC_PIN)==0);

	/* 	Save Received Data in Var-Loc_u8data */
	*Loc_u8data=UDR;
}
