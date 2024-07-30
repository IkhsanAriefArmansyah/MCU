const int ledPin = 13;
const int switchBlinkPin = 2;
const int switchOnOffPin = 3;
bool isBlinking = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchBlinkPin, INPUT_PULLUP);
  pinMode(switchOnOffPin, INPUT_PULLUP);
}

void loop() {
  int switchBlinkState = digitalRead(switchBlinkPin);
  int switchOnOffState = digitalRead(switchOnOffPin);

  if (switchBlinkState == LOW) {
    isBlinking = !isBlinking;
    delay(200);
  }
  while (isBlinking) {
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);
    delay(500);
    switchBlinkState = digitalRead(switchBlinkPin);

    if (switchBlinkState == LOW) {
      isBlinking = false;
      delay(200);
    }
  }
  if (switchOnOffState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
