################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer\ 0/Timer_0.c 

OBJS += \
./MCAL/Timer\ 0/Timer_0.o 

C_DEPS += \
./MCAL/Timer\ 0/Timer_0.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer\ 0/Timer_0.o: ../MCAL/Timer\ 0/Timer_0.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"MCAL/Timer 0/Timer_0.d" -MT"MCAL/Timer\ 0/Timer_0.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


