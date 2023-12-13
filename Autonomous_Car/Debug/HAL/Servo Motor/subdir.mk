################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Servo\ Motor/Servo_Motor.c 

OBJS += \
./HAL/Servo\ Motor/Servo_Motor.o 

C_DEPS += \
./HAL/Servo\ Motor/Servo_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Servo\ Motor/Servo_Motor.o: ../HAL/Servo\ Motor/Servo_Motor.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"HAL/Servo Motor/Servo_Motor.d" -MT"HAL/Servo\ Motor/Servo_Motor.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


