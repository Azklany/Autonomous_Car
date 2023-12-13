/*
 * Potentiometer.h
 *
 *  Created on: Oct 14, 2023
 *      Author: Mohamed
 */

#ifndef HAL_POTENTIOMETER_POTENTIOMETER_H_
#define HAL_POTENTIOMETER_POTENTIOMETER_H_

#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO.h"

void HAL_Potentiometer_PotentiometerInit(u8,u8);
void HAL_Potentiometer_PotentiometerValue(u16*);

#endif /* HAL_POTENTIOMETER_POTENTIOMETER_H_ */
