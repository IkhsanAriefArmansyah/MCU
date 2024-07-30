#include <Servo.h>
const byte PIN_SERVO = 3;
Servo myservo;
int posisi = 0;
int SERVO_MAX = 180;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(PIN_SERVO);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= SERVO_MAX; i++){
    myservo.write(i);
    delay(10);
  }
delay(2000);
for (int i = SERVO_MAX; i >= 0; i--){
  myservo.write(i);
  delay(10);
}
delay(2000);
}
