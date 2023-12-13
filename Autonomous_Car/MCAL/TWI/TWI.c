/*
 * TWI.c
 *
 *  Created on: Dec 1, 2023
 *      Author: Mohamed
 */

#include "TWI.h"

// Master
void MCAL_TWI_Master_Init(void) {
	//Enable TWI
	SET_BIT(TWCR, Pin2);
	//Enable ACK
	SET_BIT(TWCR, Pin6);
	//Bit Rate
	TWBR = Bit_Rate;
}

void MCAL_TWI_Master_SendStartCondition(void) {
	// Enable Start
	SET_BIT(TWCR, Pin5);
	//CLR Flag
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
}
void MCAL_TWI_Master_SendReStartCondition(void) {
	// Enable Start
	SET_BIT(TWCR, Pin5);
	//CLR Flag
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
}

void MCAL_TWI_Master_SendStopCondition(void) {
	// Enable Stop
	SET_BIT(TWCR, Pin4);
	//CLR Flag
	SET_BIT(TWCR, Pin7);
}

void MCAL_TWI_Master_SendSlaveAddWithWrite(u8 Address) {
	TWDR = Address << 1;
	//Write
	CLR_BIT(TWDR, Pin0);
	//clr start cond
	CLR_BIT(TWCR, Pin5);
	//clr flage
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
}
void MCAL_TWI_Master_SendSlaveAddWithRead(u8 Address) {
	TWDR = Address << 1;
	//Read
	SET_BIT(TWDR, Pin0);
	//clr start cond
	CLR_BIT(TWCR, Pin5);
	//clr flage
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
}

// Slave
void MCAL_TWI_Slave_Init(u8 Slave_Address) {
	//Enable TWI
	SET_BIT(TWCR, Pin2);
	//Enable ACK
	SET_BIT(TWCR, Pin6);
	//Set Slave Address
	TWAR = Slave_Address << 1;
	//config general call
	CLR_BIT(TWAR, Pin0);
	//CLr flag
	SET_BIT(TWCR, Pin7);
}

void MCAL_TWI_Slave_Listen(void) {
	//clr flage
	SET_BIT(TWCR, Pin7);

}

// Common

void MCAL_TWI_SendData(u8 Data) {
	TWDR = Data;
	//clr flage
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
}
void MCAL_TWI_RecieveData(u8* Data) {
	//clr flage
	SET_BIT(TWCR, Pin7);
	//Wait
	while (GET_BIT(TWCR,Pin7) == 0)
		;
	*Data = TWDR;
}
