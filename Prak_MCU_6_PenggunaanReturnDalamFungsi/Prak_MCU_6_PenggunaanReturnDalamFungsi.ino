int tambah(int a, int b) {
  int hasil = a + b;
  return hasil;
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  int x = 5;
  int y = 3;
  int hasilPenambahan = tambah(x, y);
  Serial.print("Hasil penambahan: ");
  Serial.println(hasilPenambahan);
  delay(1000);
}

//PRAK6.3
