/*
 * WDT.c
 *
 *  Created on: Oct 21, 2023
 *      Author: Mohamed
 */

#include "WDT.h"

void MCAL_WDT_u8Enable(void) {
	SET_BIT(WDTCR, WDTCR_Pin3);
	SET_BIT(WDTCR, WDTCR_Pin4);
}
void MCAL_WDT_u8SetTime(u8 Loc_u8Time) {
	if (Loc_u8Time == Time_16_3_ms) {
		CLR_BIT(WDTCR, WDTCR_Pin0);
		CLR_BIT(WDTCR, WDTCR_Pin1);
		CLR_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_32_5_ms) {
		SET_BIT(WDTCR, WDTCR_Pin0);
		CLR_BIT(WDTCR, WDTCR_Pin1);
		CLR_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_65_0_ms) {
		CLR_BIT(WDTCR, WDTCR_Pin0);
		SET_BIT(WDTCR, WDTCR_Pin1);
		CLR_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_0_13_s) {
		SET_BIT(WDTCR, WDTCR_Pin0);
		SET_BIT(WDTCR, WDTCR_Pin1);
		CLR_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_0_26_s) {
		CLR_BIT(WDTCR, WDTCR_Pin0);
		CLR_BIT(WDTCR, WDTCR_Pin1);
		SET_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_0_52_s) {
		SET_BIT(WDTCR, WDTCR_Pin0);
		CLR_BIT(WDTCR, WDTCR_Pin1);
		SET_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_1_0_s) {
		CLR_BIT(WDTCR, WDTCR_Pin0);
		SET_BIT(WDTCR, WDTCR_Pin1);
		SET_BIT(WDTCR, WDTCR_Pin2);
	} else if (Loc_u8Time == Time_2_1_s) {
		SET_BIT(WDTCR, WDTCR_Pin0);
		SET_BIT(WDTCR, WDTCR_Pin1);
		SET_BIT(WDTCR, WDTCR_Pin2);
	}
}
void MCAL_WDT_u8Disable(void) {
	WDTCR = WDTCR_Disable;
	WDTCR = WDTCR_Zero;
}
