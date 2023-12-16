################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRtos/heap_2.c \
../FreeRtos/list.c \
../FreeRtos/port.c \
../FreeRtos/queue.c \
../FreeRtos/tasks.c 

OBJS += \
./FreeRtos/heap_2.o \
./FreeRtos/list.o \
./FreeRtos/port.o \
./FreeRtos/queue.o \
./FreeRtos/tasks.o 

C_DEPS += \
./FreeRtos/heap_2.d \
./FreeRtos/list.d \
./FreeRtos/port.d \
./FreeRtos/queue.d \
./FreeRtos/tasks.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRtos/%.o: ../FreeRtos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


