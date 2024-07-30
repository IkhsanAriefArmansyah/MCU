#include <Servo.h>
Servo servoo;
const int potentioVal;
int potentio = A0;
int bttn = 2;
bool pintuTerbuka = false;
unsigned long time = 0;

void setup() {
  servoo.attach(9);
  pinMode(potentio, INPUT);
  pinMode(bttn, INPUT_PULLUP);
}

void loop() {
  int potentioVal = analogRead(potentioVal);
  int angle = map(potentioVal, 0, 1023, 0, 180);

  if (digitalRead(bttn) == LOW) {
    if (!pintuTerbuka) {
      pintuTerbuka = true;
      time = millis();
    }
    servoo.write(angle);
  } else {
    if (pintuTerbuka && millis() - time >= 5000) {
      pintuTerbuka = false;
      servoo.write(0);
    }
  }
}
