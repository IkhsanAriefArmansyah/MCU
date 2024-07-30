#include <Servo.h>
Servo servoo;
const int srvo = 9;
const int red = 3;
const int yllw = 4;
const int ldr = A0;

void setup() {
 Serial.begin(9600);
 servoo.attach(srvo);
 pinMode(red, OUTPUT);
 pinMode(yllw, OUTPUT);
 pinMode(ldr, INPUT);
}

void loop() {
 int ldrVal = analogRead(ldr);
 float voltage = ldrVal * (5.0 / 1023.0);
 int srvoVal = map(ldrVal, 0, 1023, 0, 180);
 Serial.print("Nilai digital: ");
 Serial.print(ldrVal);
 Serial.print(", Voltase: ");
 Serial.print(voltage);
 Serial.print(", Derajat: ");
 Serial.print(srvoVal);
 Serial.print(", LED ");
 servoo.write(srvoVal);

 if (srvoVal >= 0 && srvoVal <= 10) {
    digitalWrite(red, HIGH);
    digitalWrite(yllw, LOW);
    Serial.println("merah");
 } else if (srvoVal >= 85 && srvoVal <= 95) {
    digitalWrite(red, HIGH);
    digitalWrite(yllw, HIGH);
    Serial.println("merah & kuning");
 } else if (srvoVal >= 170 && srvoVal <= 180) {
    digitalWrite(yllw, HIGH);
    for (int arr = 0; arr < 2; arr++) {
      digitalWrite(yllw, LOW);
      delay(500);
      digitalWrite(yllw, HIGH);
      delay(500);
    }
    Serial.println("kuning");
 } else {
    digitalWrite(red, LOW);
    digitalWrite(yllw, LOW);
    Serial.println("mati");
 }
 delay(2000);
}
