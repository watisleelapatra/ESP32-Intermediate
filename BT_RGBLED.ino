#include "BluetoothSerial.h"
//#define LED_BUILTIN 2
#define RED 17
#define BLUE 18
#define GREEN 19

String device_name = "Watis_BT";  //<--- Replace with your name
BluetoothSerial SerialBT;

void setup() {
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  //digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);
  SerialBT.begin(device_name);  //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  char cmd;
  if (SerialBT.available()) {
    cmd = SerialBT.read(); 
    if(cmd == '0')
      digitalWrite(RED, LOW);
    if(cmd == '1')
      digitalWrite(RED, HIGH);
    if(cmd == '2')
      digitalWrite(GREEN, LOW);
    if(cmd == '3')
      digitalWrite(GREEN, HIGH);
    if(cmd == '4')
      digitalWrite(BLUE, LOW);
    if(cmd == '5')
      digitalWrite(BLUE, HIGH);
  }
}
