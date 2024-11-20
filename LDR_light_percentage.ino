#define LDR 36  //LDR is connected to ADC1 (GPIO36, VP pin)
int Light, Percent;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Light = analogRead(LDR);
  Percent = map(Light, 400, 4095, 100, 0);
  Serial.print(Light);
  Serial.print(" ");
  Serial.println(Percent);
  delay(1000);

}
