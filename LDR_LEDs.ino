#define LDR 36  //LDR is connected to ADC1 (GPIO36, VP pin)
#define RED 19
#define GREEN 18
#define BLUE 17
int Light, Percent;
void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 0);
  digitalWrite(BLUE, 0);
}

void loop() {
  Light = analogRead(LDR);
  Percent = map(Light, 400, 4095, 100, 0);
  Serial.print(Light);
  Serial.print(" ");
  Serial.println(Percent);
  if(Percent > 90) {
    digitalWrite(RED, 0);
    digitalWrite(GREEN, 0);
    digitalWrite(BLUE, 0);
  }
  else if(Percent < 90 && Percent > 60) {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 0);
    digitalWrite(BLUE, 0);
  }
  else if(Percent < 60 && Percent > 30) {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 0);
  }
  else if(Percent < 30) {
    digitalWrite(RED, 1);
    digitalWrite(GREEN, 1);
    digitalWrite(BLUE, 1);
  }
  delay(1000);

}
