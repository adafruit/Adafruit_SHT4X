# Non-Blocking

This fork adds the possibility to read the sensor in a non-blocking way using an approach similar to the [Arduino Blink Without Delay](https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay) example, while keeping the original functions.

To use the non-blocking mode, simply call `sht4x.startEvent()` to start the measurement and then continuously check if the measurement is ready using `sht4x.hasEvent()`. If the measurement is ready, you can get the temperature and humidity using `sht4x.fillEvent()`.

# Adafruit SHT4X Temperature and Humidity Sensor Breakout [![Build Status](https://github.com/adafruit/Adafruit_SHT4X/workflows/Arduino%20Library%20CI/badge.svg)](https://github.com/adafruit/Adafruit_SHT4X/actions)[![Documentation](https://github.com/adafruit/ci-arduino/blob/master/assets/doxygen_badge.svg)](http://adafruit.github.io/Adafruit_SHT4X/html/index.html)

<a href="https://www.adafruit.com/product/4636"><img src="assets/board.jpg?raw=true" width="500px"></a>

This is a library for the SHT4X Digital Humidity + Temp sensor.

It is designed specifically to work with the SHT4X Digital in the Adafruit shop:

* https://www.adafruit.com/products/4885

These sensors use **I2C** to communicate, 2 pins are required to interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.  
BSD license, all text above must be included in any redistribution

Check out the links above for our tutorials and wiring diagrams

## Installation

Use the Arduino Library Manager to install this library. If you're unfamiliar
with how this works, we have a great tutorial on Arduino library installation
at: https://learn.adafruit.com/adafruit-all-about-arduino-libraries-install-use
