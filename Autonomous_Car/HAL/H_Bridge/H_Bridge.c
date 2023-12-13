/*
 * H_Bridge.c
 *
 *  Created on: Dec 9, 2023
 *      Author: Mohamed
 */

#include "H_Bridge.h"

void HAL_void_H_BridgeInit() {
	MCAL_DIO_u8SetPinDirection(PortC, 3, Pin_High);
	MCAL_DIO_u8SetPinDirection(PortC, 4, Pin_High);
	MCAL_DIO_u8SetPinDirection(PortC, 5, Pin_High);
	MCAL_DIO_u8SetPinDirection(PortC, 6, Pin_High);
}

void HAL_void_H_BridgeCW(u8 copy_u8_speed) {
	MCAL_T1_FPWM_10bitRES(CHENNEL_B, copy_u8_speed);
	MCAL_T1_FPWM_10bitRES(CHENNEL_A, copy_u8_speed);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_High);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_Low);
}
void HAL_void_H_BridgeFront(u8 copy_u8_speed) {
	MCAL_T1_FPWM_10bitRES(CHENNEL_B, copy_u8_speed);
	MCAL_T1_FPWM_10bitRES(CHENNEL_A, copy_u8_speed);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_High);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin5, Pin_High);
	MCAL_DIO_u8SetPinValue(PortC, Pin6, Pin_Low);
}
void HAL_void_H_BridgeBack(u8 copy_u8_speed) {
	MCAL_T1_FPWM_10bitRES(CHENNEL_B, copy_u8_speed);
	MCAL_T1_FPWM_10bitRES(CHENNEL_A, copy_u8_speed);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_High);
	MCAL_DIO_u8SetPinValue(PortC, Pin5, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin6, Pin_High);
}
void HAL_void_H_BridgeCCW(u8 copy_u8_speed) {
	MCAL_T1_FPWM_10bitRES(CHENNEL_B, copy_u8_speed);
	MCAL_T1_FPWM_10bitRES(CHENNEL_A, copy_u8_speed);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_High);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin5, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin6, Pin_Low);
}

void HAL_void_H_BridgeStop(u8 copy_u8_speed) {
	MCAL_T1_FPWM_10bitRES(CHENNEL_B, copy_u8_speed);
	MCAL_T1_FPWM_10bitRES(CHENNEL_A, copy_u8_speed);
	MCAL_DIO_u8SetPinValue(PortC, Pin3, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin4, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin5, Pin_Low);
	MCAL_DIO_u8SetPinValue(PortC, Pin6, Pin_Low);
}
