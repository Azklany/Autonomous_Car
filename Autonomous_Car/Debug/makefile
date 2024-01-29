################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer\ 1/subdir.mk
-include MCAL/Timer\ 0/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/Ultrasonic\ Sensor/subdir.mk
-include HAL/Servo\ Motor/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/H_Bridge/subdir.mk
-include HAL/Buzzer/subdir.mk
-include Application/Autonomous_Car/subdir.mk
-include Application/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Autonomous_Car.lss \

FLASH_IMAGE += \
Autonomous_Car.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Autonomous_Car.elf secondary-outputs

# Tool invocations
Autonomous_Car.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Autonomous_Car.map -mmcu=atmega32 -o "Autonomous_Car.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Autonomous_Car.lss: Autonomous_Car.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Autonomous_Car.elf  >"Autonomous_Car.lss"
	@echo 'Finished building: $@'
	@echo ' '

Autonomous_Car.hex: Autonomous_Car.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Autonomous_Car.elf  "Autonomous_Car.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Autonomous_Car.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Autonomous_Car.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Autonomous_Car.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
