//Requires DHT sensors library by Adafruit
#include "DHT.h"
#include <LiquidCrystal_I2C.h>

#define DHTPIN 13     // GPIO13 connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();

}

void loop() {
  delay(2000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  lcd.backlight();
  lcd.setCursor(0, 0);  //at the first line, first column
  lcd.print("Temp  = ");
  lcd.setCursor(8, 0);
  lcd.print(t, 1);  //display 5 digits fraction
  lcd.setCursor(0, 1);  //at the second line, first column
  lcd.print("Humid = ");
  lcd.setCursor(8, 1);
  lcd.print(h, 1);  //display 2 digits fraction
  //Serial.print(F("Humidity: "));
  //Serial.print(h);
  //Serial.print(F("%  Temperature: "));
  //Serial.print(t);
  //Serial.print(F("°C "));
  //Serial.print(f);
  //Serial.println(F("°F"));
  //---For Serial Ploter---//
  //Serial.print(h);
  //Serial.print(" ");
  //Serial.println(t);
  
  }
