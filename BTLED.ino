#include "BluetoothSerial.h"
#define LED_BUILTIN 2

String device_name = "Watis_BT";  //<--- Replace with your name
BluetoothSerial SerialBT;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  SerialBT.begin(device_name);  //Bluetooth device name
  Serial.printf("The device with name \"%s\" is started.\nNow you can pair it with Bluetooth!\n", device_name.c_str());
}

void loop() {
  char cmd;
  if (SerialBT.available()) {
    cmd = SerialBT.read(); 
    if(cmd == '1')
      digitalWrite(LED_BUILTIN, HIGH);
    if(cmd == '0')
      digitalWrite(LED_BUILTIN, LOW);;
  }
}
