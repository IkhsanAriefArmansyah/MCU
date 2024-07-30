const int BTN1 = 2;
const int BTN2 = 3;
const int BTN3 = 4;
const int LED1 = 5;
const int LED2 = 6;
const int LED3 = 7;

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  int BTNstate1 = digitalRead(BTN1);
  int BTNstate2 = digitalRead(BTN2);
  int BTNstate3 = digitalRead(BTN3);
  if (BTNstate1 == LOW) {
    digitalWrite(LED1, HIGH);
  } else {
    digitalWrite(LED1, LOW);
  }

  if (BTNstate2 == LOW) {
    digitalWrite(LED2, HIGH);
  } else {
    digitalWrite(LED2, LOW);
  }

  if (BTNstate3 == LOW) {
    digitalWrite(LED3, HIGH);
  } else {
    digitalWrite(LED3, LOW);
  }

  if (BTNstate1 == HIGH && BTNstate2 == HIGH && BTNstate3 == HIGH) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  }
}
