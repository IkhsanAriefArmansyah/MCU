void setup() {
  Serial.begin(9600);
  int numb = 10;
  while (numb >= 1) {
    Serial.println(numb);
    numb--;
    delay(500);
  }
  Serial.println("Waktu habis!");
  while (true) {
  }
}
void loop() {
}

//TUGAS PRAK 5.3