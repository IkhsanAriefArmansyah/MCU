const int ledPin = 3;
unsigned long previousMillis = 0;
const long interval = 1000; //interval waktu dalam milidetik (1 detik)

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    digitalWrite(ledPin, !digitalRead(ledPin)); // ubah status LED
  }
}
