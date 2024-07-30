const int pinPot = A3;
const int pinLED = 9;
void setup() {
  Serial.begin(9600);
  pinMode(pinPot, INPUT);
  pinMode(pinLED, OUTPUT);
}
int sensor = 0;
int brightness = 0;
void loop() {
  sensor = analogRead(pinPot);
  Serial.print("DN sensor");
  Serial.println(sensor);

  brightness = map(sensor, 0, 1023, 0, 255);
  analogWrite(pinLED, brightness);
  Serial.print("Kecerahan LED = ");
  Serial.println(brightness);
}
