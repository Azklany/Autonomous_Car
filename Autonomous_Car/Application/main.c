/*
 * main.c
 *
 *  Created on: Dec 13, 2023
 *      Author: Mohamed
 */

#include "main.h"

void main(void) {
	HAL_SM_voidSMInit();
	while (1) {
		for (int i = 0; i <= 180; i += 5) {
			HAL_SM_voidSMSetAngle(i);
			_delay_ms(40);
			if (i == 180) {
				for (int i = 180; i > 0; i -= 5) {
					HAL_SM_voidSMSetAngle(i);
					_delay_ms(40);
				}
			}

		}
	}
}
