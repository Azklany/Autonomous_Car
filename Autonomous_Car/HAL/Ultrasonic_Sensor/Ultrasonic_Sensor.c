/*
 * Ultrasonic_Sensor.c
 *
 *  Created on: Dec 16, 2023
 *      Author: TOP_WORLD
 */
#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/Timer 0/Timer_0.h"
#include "../../MCAL/Timer 1/Timer1.h"
#include "../../MCAL/Interrupt/Interrupt.h"
#include "../LCD/LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include "Ultrasonic_Sensor.h"
#include <util/delay.h>
volatile  u8  exit_count=NUM1;
volatile  f32 distance=NUM0;
volatile  u16 start_time=NUM0,end_time=NUM0,timeDiff=NUM0;
volatile  u16 ovfCounter_start,ovfCounter_end;
extern volatile   u16 OvfCounter;

void ultrasonic_init(void)
{
    MCAL_DIO_u8SetPinDirection(ECHO_PORT,ECHO_PIN,Pin_Low);      //  echo
    MCAL_DIO_u8SetPinDirection(TRIG_PORT,TRIG_PIN,Pin_High);  //  trigger
    MCAL_Interrupt_EXIT_CallBack_0(&EXTI_action);                             // external interrupt call back
}

void ultrasonic_sendTrigger(void)
{
	MCAL_DIO_u8SetPinValue(TRIG_PORT,TRIG_PIN,Pin_High);    // high
    _delay_us(10);                                             // 10 micro seconds delay
    MCAL_DIO_u8SetPinValue(TRIG_PORT,TRIG_PIN,Pin_Low);     // low
}

void ultrasonic_get_Distance(f32* returned_distance)
{
    ultrasonic_sendTrigger();                                  // send trigger
	MCAL_Interrupt_u8SetRegisterPin(Gicr, GICR_Pin6, Pin_High);
    MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin0 , Pin_High);
    	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin1 , Pin_High);
    _delay_ms(50);                                             // stability delay
    *returned_distance=distance;                               // get the distance
}
void EXTI_action(void)                                       // call back function
{

    if (exit_count<=2)          // check for counter status
    {
         if (exit_count==NUM1)      // check if it is the first entry
        {
            // store the start time value
            start_time=TCNT0;

            // store number of OVFs at the start of the signal
            ovfCounter_start=OvfCounter;

            // at the first entry  we change the capture edge to falling edge to capture echo signal
        	MCAL_Interrupt_u8SetRegisterPin(Gicr, GICR_Pin6, Pin_High);
            MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin0 , Pin_Low);
        	MCAL_Interrupt_u8SetRegisterPin(Mcucr,MCUCR_Pin1 , Pin_High);
        }

        else if(exit_count==2) // check if it's the second entry
        {
            //store end time value
            end_time=TCNT0;

            //store number of OVFs at the end of signal
            ovfCounter_end=OvfCounter;

            //calculate the time difference between start and end
            timeDiff=(end_time+(256*ovfCounter_end))-(start_time+(256*ovfCounter_start));

            //calculate the distance
            distance=timeDiff*0.068;//     f32 ton=(h(64/16000000))/2 >>     distance=ton34000;

            //reset the counter to calculate new signal
            exit_count=NUM0;

        }

        //increase the counter to sync with the entry state
        exit_count++;
    }

}
