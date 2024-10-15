/***************************************************
  This is an example for the SHT4x Humidity & Temp Sensor
  using the non-blocking methods

  Designed specifically to work with the SHT4x sensor from Adafruit
  ----> https://www.adafruit.com/products/4885

  These sensors use I2C to communicate, 2 pins are required to
  interface
****************************************************/

#include "Adafruit_SHT4x.h"

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);

  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit SHT4x non-blocking test");
  if (!sht4.begin()) {
    Serial.println("Couldn't find SHT4x");
    while (1)
      delay(1);
  }

  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);
  sht4.startEvent(); // start reading sensor data
}

void loop() {
  if (sht4.hasEvent()) { // check if the sensor has new data ready
    sensors_event_t humidity, temp;
    sht4.fillEvent(&humidity, &temp); // populate temp and humidity objects with fresh data
    Serial.print("Temperature: ");
    Serial.print(temp.temperature);
    Serial.println(" degrees C");
    Serial.print("Humidity: ");
    Serial.print(humidity.relative_humidity);
    Serial.println("% rH");
    sht4.startEvent(); // start reading sensor data again
  }

  // do other stuff here ...
}