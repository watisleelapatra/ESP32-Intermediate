#define RED 19
#define GREEN 18
#define BLUE 17
int light;
void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    analogWrite(RED, dutyCycle);
    analogWrite(GREEN, dutyCycle);
    analogWrite(BLUE, dutyCycle);
    delay(20);
  }
  delay(500);
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    analogWrite(RED, dutyCycle);
    analogWrite(GREEN, dutyCycle);
    analogWrite(BLUE, dutyCycle);
    delay(20);
  }
  delay(500);
}
