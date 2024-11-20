#define RED 17
#define GREEN 18
#define BLUE 19
char data;

void setup() {
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, 0);
  digitalWrite(GREEN, 0);
  digitalWrite(BLUE, 0);
  Serial.print("Press : 'r', 'g', 'b' to turn on LEDs and 'c' to turn off");
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    if(data > 20) {
      switch((char) data) {
        case 'r' :
          digitalWrite(RED, 1);
          break;
        case 'g' :
          digitalWrite(GREEN, 1);
          break;
        case 'b' :
          digitalWrite(BLUE, 1);
          break;
        case 'c' :
          digitalWrite(RED, 0);
          digitalWrite(GREEN, 0);
          digitalWrite(BLUE, 0);
          break;
      }
    }
  }
}
