/*
 * TWI.h
 *
 *  Created on: Dec 1, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_TWI_TWI_H_
#define MCAL_TWI_TWI_H_

#include "../DIO/DIO.h"

#define Bit_Rate 152

//master
void MCAL_TWI_Master_Init(void);
void MCAL_TWI_Master_SendStartCondition(void);
void MCAL_TWI_Master_SendReStartCondition(void);
void MCAL_TWI_Master_SendStopCondition(void);
void MCAL_TWI_Master_SendSlaveAddWithWrite(u8);
void MCAL_TWI_Master_SendSlaveAddWithRead(u8);
//slave
void MCAL_TWI_Slave_Init(u8);
void MCAL_TWI_Slave_Listen(void);
//common
void MCAL_TWI_SendData(u8);
void MCAL_TWI_RecieveData(u8*);
#endif /* MCAL_TWI_TWI_H_ */
