const int ledpin1 = 3;
const int ledpin2 = 2;

void setup() {
  pinMode(ledpin1, OUTPUT);
  pinMode(ledpin2, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) {
      continue;
    }
    digitalWrite(ledpin1, HIGH);
    delay(500);
    digitalWrite(ledpin1, LOW);
    delay(500);
  }
  digitalWrite(ledpin2, HIGH);
  delay(1000);
  digitalWrite(ledpin2, LOW);
  delay(1000);
}

//PRAK6.2
