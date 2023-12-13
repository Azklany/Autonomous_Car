/*
 * WDT.h
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed
 */

#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_

#include "../../Commons/MCU.h"
#include "../../Commons/Macros.h"
#include "../../Commons/STD_Types.h"

#define WDTCR_Enable 0b00011000
#define WDTCR_Disable 0b00011000
#define WDTCR_Zero 0b00000000

#define WDTCR_Pin0 0
#define WDTCR_Pin1 1
#define WDTCR_Pin2 2
#define WDTCR_Pin3 3
#define WDTCR_Pin4 4

void MCAL_WDT_u8Enable(void);
void MCAL_WDT_u8SetTime(u8);
void MCAL_WDT_u8Disable(void);

enum{Time_16_3_ms,Time_32_5_ms,Time_65_0_ms,Time_0_13_s,Time_0_26_s,Time_0_52_s,Time_1_0_s,Time_2_1_s};
#endif /* MCAL_WDT_WDT_H_ */
