# Arduino - Temperature and Humidity check

This is a simple project to create a device to measure temperature and humidity.

PIECES:

- Arduino Uno (other microcontroller are good as well)
- LCD display
- active buzzer
- ultrasonic sensor
- DHT 11 (or others) temperature and humidity sensor
- potentiometer (to adjust LCD brightness)

The wiring image shows how to wire the pieces together. 

![alt text](https://github.com/pitbull36/ard_temp_humidity/blob/master/wiring_temp_hum.png?raw=true)

Basically the device wait for input, as something is approaching the ultrasonic sensor at a distance <= 35 cm,
you will hear a double beep and on the LCD screen it will appear temperature and humidity until the ultrasonic
sensor is free.

![alt text](https://github.com/pitbull36/ard_temp_humidity/blob/master/preview.jpg?raw=true)

The code is in the .ino file.
