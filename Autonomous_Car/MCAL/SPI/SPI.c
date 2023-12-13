/*
 * SPI.c
 *
 *  Created on: Oct 27, 2023
 *      Author: Mohamed
 */

//Slave
#include "SPI.h"

void MCAL_SPI_SPIInit(void) {
#if SPI_Mode == SPI_Master
	//Master Enable   *
	SET_BIT(SPCR, MSTR_PIN);

	//MOSI   *
	MCAL_DIO_u8SetPinDirection(PortB, Pin5, Pin_High);
	//Disable SS  *
	MCAL_DIO_u8SetPinDirection(PortB, Pin4, Pin_High);
	//SDK  *
	MCAL_DIO_u8SetPinDirection(PortB, Pin7, Pin_High);

	//SS Disable *
	MCAL_DIO_u8SetPinValue(PortB, Pin4, Pin_High);

	//Prescaler 64 *
	SET_BIT(SPCR, SPR0_PIN);
	SET_BIT(SPCR, SPR1_PIN);
#elif SPI_Mode == SPI_Salve
	//Slave Enable   *
	CLR_BIT(SPCR, MSTR_PIN);

	//MISO *
	MCAL_DIO_u8SetPinDirection(PortB, Pin6, Pin_High);
#endif

//the LSB of the data word is transmitted first.
	SET_BIT(SPCR, DORD_PIN);

	//Clock
//	SET_BIT(SPCR, CPOL_PIN);
	SET_BIT(SPCR, CPHA_PIN);

//Enable Interrupt
//	SET_BIT(SPCR, SPIE_PIN);

//SPI Enable
	SET_BIT(SPCR, SPE_PIN);
}

void MCAL_SPI_SendString(u8* Loc_Data) {
	for (u32 i = 0; Loc_Data[i] != '\0'; i++) {
		MCAL_SPI_SPITranceive(Loc_Data[i]);
	}
}

void MCAL_SPI_RecieveString(u8* Loc_Data) {
	for (u32 i = 0; Loc_Data[i] != '\0'; i++) {
		Loc_Data[i] = MCAL_SPI_SPITranceive(0xff);
	}
}

u8 MCAL_SPI_SPITranceive(u8 Loc_u8Data) {
	SPDR = Loc_u8Data;
	while (GET_BIT(SPSR,SPIF_PIN) == 0)
		;
	return SPDR;
}

