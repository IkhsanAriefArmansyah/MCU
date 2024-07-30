#include <Servo.h> 
const int srvo = 7; 
Servo servoo; 

void setup() {
  Serial.begin(9800);
  servoo.attach(srvo); 
}

void loop() {
  int potentio = analogRead(A0);
  int angle = map(potentio, 0, 1023, 0, 180);
  Serial.println(angle);
  servoo.write(angle);
  delay(150);
}
