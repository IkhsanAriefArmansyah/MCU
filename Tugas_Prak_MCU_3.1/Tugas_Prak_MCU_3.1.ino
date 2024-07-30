const int BTN1 = 2;
const int BTN2 = 4;
const int LED1 = 6;
const int LED2 = 8;

void setup() {
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  int BTNstate1 = digitalRead(BTN1);
  int BTNstate2 = digitalRead(BTN2);

  switch (BTNstate1) {
    case LOW:
      digitalWrite(LED1, HIGH);
      break;

    default:
      digitalWrite(LED1, LOW);
      break;
  }

  switch (BTNstate2) {
    case LOW:
      digitalWrite(LED2, HIGH);
      break;

    default:
      digitalWrite(LED2, LOW);
      break;
  }
}