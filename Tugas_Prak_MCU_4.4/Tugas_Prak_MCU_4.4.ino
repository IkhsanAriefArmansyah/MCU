int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int dTime = Serial.parseInt();

    if (dTime > 0) {
      for (;;) {
        digitalWrite(LED, HIGH);
        delay(dTime);
        digitalWrite(LED, LOW);
        delay(dTime);
      }
    }
  }
}
