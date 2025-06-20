This project aims to build a simple car dashboard using the STM32F446RE microcontroller. The final goal is to receive vehicle data via the CAN bus and display it on an LCD screen (ILI9341 driver).

At this stage of development, the system communicates with a PC that simulates the car's ECU. The PC sends RPM data over UART interface, which the STM32 receives and processes for display.

In python_script/ you can find script that send data via UART and simulates car rpm. To run this script you need to install 'pyserial' and 'keyboard' library.

ILI9341 driver: https://github.com/afiskon/stm32-ili9341
