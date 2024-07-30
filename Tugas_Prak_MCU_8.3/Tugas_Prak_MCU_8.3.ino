const int dC = 2;

void setup() {
  pinMode(dC, OUTPUT);
}

void loop() {
  digitalWrite(dC, HIGH);
  unsigned long waktuMulai = millis();

  while (millis() - waktuMulai < 5000) {
  }

  digitalWrite(dC, LOW);
  waktuMulai = millis();

  while (millis() - waktuMulai < 3000) {
  }
}

//TUGAS 3