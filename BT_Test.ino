#include "BluetoothSerial.h"
String device_name = "Watis_BT";  //<--- Replace with your name
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin(device_name); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}