/*
 * SPI.h
 *
 *  Created on: Oct 27, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../DIO/DIO.h"

#define SPI_Master 1
#define SPI_Slave 0

#define SPI_Mode SPI_Master

//SPCR
#define SPIE_PIN 7
#define SPE_PIN 6
#define DORD_PIN 5
#define MSTR_PIN 4
#define CPOL_PIN 3
#define CPHA_PIN 2
#define SPR1_PIN 1
#define SPR0_PIN 0

//SPSR
#define SPIF_PIN 7
#define WCOL_PIN 6
#define SPI2X_PIN 0

void MCAL_SPI_SPIInit(void);
u8 MCAL_SPI_SPITranceive(u8);
void MCAL_SPI_SendString(u8*);
void MCAL_SPI_RecieveString(u8*);

#endif /* MCAL_SPI_SPI_H_ */
