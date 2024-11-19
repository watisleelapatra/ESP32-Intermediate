#include <LiquidCrystal_I2C.h>
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void setup(){
  float x = PI;
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
  lcd.setCursor(0, 0);  //at the first line, first column
  lcd.print((char) 247);
  lcd.print(" = ");
  lcd.setCursor(4, 0);
  lcd.print(x, 5);  //display 5 digits fraction
  lcd.setCursor(0, 1);  //at the second line, first column
  lcd.print((char) 247);
  lcd.print(" = ");
  lcd.setCursor(4, 1);
  lcd.print(x, 2);  //display 2 digits fraction
}

void loop(){
}
