This project aims to build a simple car dashboard using the STM32F446RE microcontroller. The final goal is to receive vehicle data via the CAN bus and display it on an LCD screen (ILI9341 driver).

At this stage of development, the system communicates with a PC that simulates the car's ECU. The PC sends RPM data over UART interface, which the STM32 receives and processes for display.

ILI9341 driver: https://github.com/afiskon/stm32-ili9341
