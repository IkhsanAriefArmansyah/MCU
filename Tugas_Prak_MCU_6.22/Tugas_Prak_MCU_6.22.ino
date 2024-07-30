const int maxGuess = 100;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {
  int rndm = random(1, maxGuess + 1);
  int plyrGuess;
  bool guess = true;

  while (guess) {
    Serial.println ("Tebak angka dari 1 hingga 100");
    Serial.println ("Masukkan tebakan Anda: ");
    while (!Serial.available()) {}
    plyrGuess = Serial.parseInt();

    if (plyrGuess == rndm) {
      Serial.println("Tebakan anda benar");
      guess = false;
    } else if (plyrGuess > rndm) {
      Serial.println("Angka yang ditebak terlalu besar");
    } else {
      Serial.println("Angka yang ditebak terlalu kecil");
    }
  }
  delay(5000);
}

//TUGAS PRAK 6.2