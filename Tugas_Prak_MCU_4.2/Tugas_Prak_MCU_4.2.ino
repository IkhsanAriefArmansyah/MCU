void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    String masukan = Serial.readString();
    Serial.print("Awal : ");
    Serial.println(masukan);
    Serial.print("Terbalik : ");
    for (int arr = masukan.length() - 1; arr >= 0; arr--) {
      Serial.print(masukan[arr]);
    }
    Serial.println();
  }
}
