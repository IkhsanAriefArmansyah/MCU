void setup() {
  Serial.begin(9600);
  for (int arr = 1; arr <= 10; arr++) {
    if (arr % 2 == 0) {
      continue;
    }
    Serial.println(arr);
  }
}

void loop() {
}

//TUGAS PRAK 6.1