import serial
import keyboard
import time

rpm = 0

def accelerate():
    global rpm
    rpm += 300
    if(rpm > 9999):
        rpm = 9999

def stop_rpm():
    global rpm
    rpm -= 220
    if(rpm <= 0):
        rpm = 0

def make_string_4_long(str):
    if len(str) < 4:
        str = str.zfill(4)
    return str

ser = serial.Serial('COM7', 115200, timeout=1)

while True:
    if keyboard.is_pressed('w'):
        accelerate()
        ser.write(make_string_4_long(str(rpm)).encode('utf-8'))
    else:
        stop_rpm()
        ser.write(make_string_4_long(str(rpm)).encode('utf-8'))
    print(f"Current RPM: {rpm}")
    time.sleep(0.1)


