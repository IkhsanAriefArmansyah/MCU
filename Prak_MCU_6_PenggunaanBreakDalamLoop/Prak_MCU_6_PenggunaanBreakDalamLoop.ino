const int ledpin = 13;

void setup() {
  pinMode(ledpin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledpin, HIGH);
    delay(500);
    digitalWrite(ledpin, LOW);
    delay(500);
    if (i == 5) {
      break;
    }
  }
}

//PRAK6.1
