/*
 * Ultrasonic_Sensor.c
 *
 *  Created on: Dec 16, 2023
 *      Author: TOP_WORLD
 */

#include "Ultrasonic_Sensor.h"

volatile u8 Glob_u8Counter = NUM1;
volatile f32 Glob_f32Distance = NUM0;
volatile u16 Glob_u16StartTime = NUM0, Glob_u16EndTime = NUM0, Glob_u16TimeDiff = NUM0;
volatile u16 Glob_u16OvfCounterStart, Glob_16OvfCounterEnd;
extern volatile u16 Glob_u16OvfCounter;

void HAL_Ultrasonic_Sensor_voidInit(void) {
	MCAL_DIO_u8SetPinDirection(ECHO_PORT, ECHO_PIN, Pin_Low);      //
	MCAL_DIO_u8SetPinDirection(TRIG_PORT, TRIG_PIN, Pin_High);  //  trigger
	MCAL_Interrupt_EXIT_CallBack_0(HAL_Ultrasonic_Sensor_voidInterrupt); // external interrupt call back
	SET_BIT(SREG,Pin7);
	MCAL_Timer0_Init(Normal_Mode,Prescaller_64,Non_Inverted);
	MCAL_Timer0_SetPreloadValue(113);
}

void HAL_Ultrasonic_Sensor_voidTrigger(void) {
	MCAL_DIO_u8SetPinValue(TRIG_PORT, TRIG_PIN, Pin_High);    // high
	_delay_us(10);                                            // 10 micro seconds delay
	MCAL_DIO_u8SetPinValue(TRIG_PORT, TRIG_PIN, Pin_Low);     // low
}

void HAL_Ultrasonic_Sensor_voidCalcDistancse(f32* returned_distance) {
	HAL_Ultrasonic_Sensor_voidTrigger();                                  // send trigger
	MCAL_Interrupt_InterruptRisingInit();
	_delay_ms(50);                                            // stability delay
	*returned_distance = Glob_f32Distance;                           // get the distance
}
void HAL_Ultrasonic_Sensor_voidInterrupt(void)                                     // call back function
{

	if (Glob_u8Counter <= 2)          // check for counter status
			{
		if (Glob_u8Counter == NUM1)      // check if it is the first entry
		{
			// store the start time value
			Glob_u16StartTime = TCNT0;

			// store number of OVFs at the start of the signal
			Glob_u16OvfCounterStart = Glob_u16OvfCounter;

			// at the first entry  we change the capture edge to falling edge to capture echo signal
			MCAL_Interrupt_InterruptFallingInit();
		}

		else if (Glob_u8Counter == 2) // check if it's the second entry
				{
			//store end time value
			Glob_u16EndTime = TCNT0;

			//store number of OVFs at the end of signal
			Glob_16OvfCounterEnd = Glob_u16OvfCounter;

			//calculate the time difference between start and end
			Glob_u16TimeDiff = (Glob_u16EndTime + (256 * Glob_16OvfCounterEnd))
					- (Glob_u16StartTime + (256 * Glob_u16OvfCounterStart));

			//calculate the distance
			Glob_f32Distance = Glob_u16TimeDiff * 0.068; //     f32 ton=(h(64/16000000))/2 >>     distance=ton34000;

			//reset the counter to calculate new signal
			Glob_u8Counter = NUM0;

		}

		//increase the counter to sync with the entry state
		Glob_u8Counter++;
	}

}
