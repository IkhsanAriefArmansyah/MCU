const int ledPin = 13;
const int switchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  int switchState = digitalRead(switchPin);
  while (switchState == LOW) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    switchState = digitalRead(switchPin);
  }
}
