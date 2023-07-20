#include <Adafruit_SH110X.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_SHT4x.h"
#include <Fonts/FreeSans9pt7b.h>


Adafruit_SH1107 display = Adafruit_SH1107(64, 128, &Wire);
//Adafruit_SSD1306 display(128, 64, &Wire1);

Adafruit_SHT4x sht4 = Adafruit_SHT4x();

void setup() {
  Serial.begin(115200);
  //while (!Serial);

  
  Serial.println("128x64 OLED FeatherWing test");
  display.begin(0x3C, true); // Address 0x3C default
  //if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3D)) {
  //  Serial.println(F("SSD1306 allocation failed"));
  //  for(;;); // Don't proceed, loop forever
  //}
  
  Serial.println("OLED begun");

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();
  
  Serial.println("Adafruit SHT4x test");
  if (! sht4.begin(&Wire)) {
    Serial.println("Couldn't find SHT4x");
    while (1) delay(1);
  }
  Serial.println("Found SHT4x sensor");
  Serial.print("Serial number 0x");
  Serial.println(sht4.readSerial(), HEX);

  sht4.setPrecision(SHT4X_HIGH_PRECISION);
  sht4.setHeater(SHT4X_NO_HEATER);
  
  display.setRotation(1);
  display.setFont(&FreeSans9pt7b);
  display.setTextColor(SH110X_WHITE);  
}

void loop() {
  sensors_event_t humidity, temp;
  
  uint32_t timestamp = millis();
  sht4.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  timestamp = millis() - timestamp;

  Serial.print("Temperature: "); Serial.print(temp.temperature); Serial.println(" degrees C");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");

  display.clearDisplay();
  display.setCursor(0, 20);
  display.println("SHT41 Sensor");
    display.setCursor(0, 40);

display.print("Temp: "); 
  display.print(temp.temperature,1); 

  display.println(" C");
  display.print("Hum: "); 
  display.print(humidity.relative_humidity,1); 
  display.println(" %");
  display.display();
  yield();
  delay(100);
}
