void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 20; i += 2) {
    Serial.println(i);
    delay(500);
  }
}

void loop() {
}
