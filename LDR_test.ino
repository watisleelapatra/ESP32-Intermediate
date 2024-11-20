#define LDR 36  //LDR is connected to ADC1 (GPIO36, VP pin)
int Light;
void setup() {
  Serial.begin(9600);

}

void loop() {
  Light = analogRead(LDR);
  Serial.println(Light);
  delay(1000);

}
