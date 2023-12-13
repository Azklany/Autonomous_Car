/*
 * Potentiometer.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Mohamed
 */

#include "Potentiometer.h"

void HAL_Potentiometer_PotentiometerInit(u8 Loc_u8PotPort,u8 Loc_u8PotPin) {
//	MCAL_DIO_u8SetPinDirection(Loc_u8PotPort,Loc_u8PotPin,Pin_Low);
	MCAL_ADC_AdcInit(Adc_1);
}

void HAL_Potentiometer_PotentiometerValue(u16 *Loc_u16Value) {
	MCAL_ADC_AdcStartConversion(Enable);
	MCAL_ADC_u8AdcSetValue(Loc_u16Value);
}
