char data;
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  if (Serial.available() > 0) {
    data = Serial.read();
    if(data > 20) {
      Serial.print("You type a character ");
      Serial.println((char) data);
    }
  }
}
