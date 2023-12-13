################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer\ 1/Timer1.c 

OBJS += \
./MCAL/Timer\ 1/Timer1.o 

C_DEPS += \
./MCAL/Timer\ 1/Timer1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer\ 1/Timer1.o: ../MCAL/Timer\ 1/Timer1.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"MCAL/Timer 1/Timer1.d" -MT"MCAL/Timer\ 1/Timer1.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


