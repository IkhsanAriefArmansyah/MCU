void setup() {
  Serial.begin(9600);
  int numb = 1;

  while (numb <= 20) {
    if (numb % 2 != 0) {
      Serial.println(numb);
    }
    numb++;
  }
}

void loop() {
}

//TUGAS PRAK 5.1