///*
// * ICU_Interface.c
// *
// *  Created on: Dec 15, 2023
// *      Author: TOP_WORLD
// */
//#include "../MCAL/Interrupt/Interrupt.h"
//#include "../MCAL/Timer 1/Timer1.h"
//#include "../MCAL/DIO/DIO.h"
//#include "ICU_Interface.h"
//static volatile u8 LOC_u8counter = NUMBER_0;
//static volatile u16 period_Ticks = NUMBER_0;
//static volatile u16 on_Ticks = NUMBER_0;
//void ICU_SW_init(u16 * copy_pu16period_Ticks, u16 * copy_pu16on_Ticks) {
//	f32 y = NUMBER_0;
//	MCAL_DIO_u8SetPinDirection(PortD, Pin2, Pin_Low);
//	//Timer 1
//	MCAL_T1_u8T1Init(NORMAL_MODE);
//	MCAL_T1_u8T1Prescaler(PRESCALLING_8, &y);
//	//Int0
//	MCAL_Interrupt_InterruptInit();
//	SET_BIT(MCUCR, Pin1);
//	SET_BIT(MCUCR, Pin0);
//	MCAL_Interrupt_EXIT_CallBack_0(ICU_SW);
//	//Bsy wait the ICU measure value
//	while ((period_Ticks == 0) && (on_Ticks == 0))
//		;
//	if ((copy_pu16on_Ticks != '\0') && (copy_pu16period_Ticks != '\0')) {
//		*copy_pu16period_Ticks = period_Ticks;
//		*copy_pu16on_Ticks = on_Ticks;
//	} else {
//		//NOTHING
//	}
//}
//void ICU_SW(void) {
//	LOC_u8counter++;
//	//Frist Rising Edge
//	if (LOC_u8counter == 1) {
//		//Timer Starts counter
//		MCAL_T1_voidSetTCNT1Value(NUMBER_0);
//		SET_BIT(MCUCR, Pin1);
//		CLR_BIT(MCUCR, Pin0);
//	} else if (LOC_u8counter == 2) {
//		//second rising edge
//		MCAL_T1_voidGetTCNT1Value(&on_Ticks);
//		on_Ticks--;
//		//Change Int0 to Trigger to falling edge
//		SET_BIT(MCUCR, Pin1);
//		SET_BIT(MCUCR, Pin0);
//	} else if (LOC_u8counter == 3) {
//		//Falling edge to get on time
//		MCAL_T1_voidGetTCNT1Value(&period_Ticks);
//		period_Ticks--;
//		MCAL_Interrupt_EnableGIE(Disable);
//	}
//}
//
