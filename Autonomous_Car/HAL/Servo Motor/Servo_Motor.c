/*
 * Servo_Motor.c
 *
 *  Created on: Oct 29, 2023
 *      Author: TOP_WORLD
 */
#include "Servo_Motor.h"
void HAL_SM_voidSMInit(void) {
	SET_BIT(DDRD,Pin7);
}
void HAL_SM_voidSMSetAngle(u8 LOC_u8Angle) {
	u16 LOC_u16Time=(32.0/3)*(LOC_u8Angle-90)+1100;
	u16 LOC_u16OffTime=(20000-LOC_u16Time);
	if (LOC_u8Angle <= MAX_ANGLE && LOC_u8Angle >= MIN_ANGLE) {
		SET_BIT(PORTD,Pin7);
		_delay_us(LOC_u16Time);
		CLR_BIT(PORTD,Pin7);
		_delay_us(LOC_u16OffTime);
	} else {
		//NOTHING
	}
}
