const int led = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    if (i <= 1) continue;
    if (i == 8) {
      digitalWrite(led, 0);
      delay(1000);
      break;
    }
    Serial.println(i);
    digitalWrite(led, 1);
    delay(500);
  }
}
