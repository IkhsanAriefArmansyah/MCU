byte ldr = A0;
byte led = 13;

void setup() {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
}

void loop() {
  int nilai = analogRead(ldr);
  Serial.print("Nilai digital ldr= ");
  Serial.println(nilai);
  Serial.print(",");
  float voltase = float (nilai / 1023.0 * 5.0);
  Serial.print("Nilai voltase = ");
  Serial.println(voltase);
  if (nilai >= 0 && nilai < 300) digitalWrite(led, HIGH);
  if (nilai >= 300 && nilai < 600) {
    digitalWrite(led, LOW);
  }
  if (nilai >= 600) {
    for (byte indeks = 0; indeks < 5; indeks++) {
      digitalWrite(led, 1);
      delay(500);
      digitalWrite(led, 0);
      delay(500);
    }
  }
  delay(500);
}
