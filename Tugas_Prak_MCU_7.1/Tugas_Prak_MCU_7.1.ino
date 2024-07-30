byte ldr = A0;
byte led[] = { 2, 4 };

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  int nilai = analogRead(ldr);
  Serial.print("Nilai digital ldr = ");
  Serial.println(nilai);
  float volt = float(nilai / 1023.0 * 5.0);
  Serial.print("Nilai voltase = ");
  Serial.println(volt);

  if (nilai <= 400) {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
  } else if (nilai >= 400) {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
  }
  delay(2000);
}