#define LDR 36
#define RED 19
#define GREEN 18
#define BLUE 17
int light, dutyCycle;
void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  light = analogRead(LDR);
  dutyCycle = map(light, 400, 4095, 0, 255);
  analogWrite(RED, dutyCycle);
  analogWrite(GREEN, dutyCycle);
  analogWrite(BLUE, dutyCycle);
  delay(50);
}
