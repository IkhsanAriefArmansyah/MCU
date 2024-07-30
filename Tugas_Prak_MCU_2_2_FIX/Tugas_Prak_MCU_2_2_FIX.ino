int lamp[] = { 2, 4, 6 };
int pshBtn[] = { 8, 10, 12 };
int btn1; int btn2; int btn3;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
}
void loop() {
  btn1 = digitalRead(8);
  btn2 = digitalRead(10);
  btn3 = digitalRead(12);

  if (btn1 == 0 && btn2 == 0 && btn3 == 0) {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(6, HIGH);
    delay(2000);
  } else if (btn1 == 0 && btn2 == 0) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
    delay(2000);
  } else if (btn1 == 0 || btn3 == 0) {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(6, LOW);
    delay(2000);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(6, LOW);
  }
}
