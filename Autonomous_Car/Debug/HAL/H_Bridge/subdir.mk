################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/H_Bridge/H_Bridge.c 

OBJS += \
./HAL/H_Bridge/H_Bridge.o 

C_DEPS += \
./HAL/H_Bridge/H_Bridge.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/H_Bridge/%.o: ../HAL/H_Bridge/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


