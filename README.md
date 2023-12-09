# Autonomous_Car
For `ATmega32 Datasheet` click [here](https://pdf1.alldatasheet.com/datasheet-pdf/view/77378/ATMEL/ATMEGA32.html)
<hr>

### Component
- AMIT AVR-KIT (AVR-ATmega32)
- Ultrasonic HC- SR04.
- Servo motor.
- H-Bridge (L293D).
- Motors.
- Caster wheel.
- Chassis

### Specifications => Ultrasonic Sensor, H-Bridge (L293D) , LCD , Servo Motor 
- Ultrasonic is used to detect any obstacles towards to the car, and
the car must fast react to avoid this obstacle like stopping and
turning to any empty direction.

- L293D is used to control the speed and the direction of motors.

- LCD displays the current direction that car immediately move.

- Servo is used to make ultrasonic scanning around 180°.


 <hr>

## Drivers
- Application
  - Autonomous_Car
  - main
- FreeRTOS 
- HAL
  - LED
  - LCD
  - Buzzer
  - H-Bridge
- MCAL
  - DIO
  - WDT
  - Timer0
  - Timer1
  - Interrupt

## Common Files
- `MCU.h` File
- `Macros.h` File
- `STD_Types.h` File

<hr>

## Use This Link To Clone My Repo :
   ```
  https://github.com/Azklany/Autonomous_Car.git
  ```
<hr>

All rights reserved © 2023 to [Azklany](https://github.com/Azklany) & [Abdo](https://github.com/AbdulrahmanElanani).
