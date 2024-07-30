int biggest(int a, int b, int c) {
  if (a >= b && a >= c) {
    return a;
  } else if (b >= a && b >= c) {
    return b;
  } else {
    return c;
  }
}

void setup() {
  Serial.begin(9600);
  int angkaTerbesar = biggest(1, 3, 13);

  Serial.print("Angka terbesar adalah: ");
  Serial.println(angkaTerbesar);
}

void loop() {
}

//TUGAS PRAK 6.3