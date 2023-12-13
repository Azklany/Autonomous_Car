################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Push\ Button/PushButton.c 

OBJS += \
./HAL/Push\ Button/PushButton.o 

C_DEPS += \
./HAL/Push\ Button/PushButton.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Push\ Button/PushButton.o: ../HAL/Push\ Button/PushButton.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/Push Button/PushButton.d" -MT"HAL/Push\ Button/PushButton.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


