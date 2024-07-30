const int dC = 2;
int dCstate;
unsigned long waktuSekarang;
unsigned long waktuSebelumnya;
unsigned long dChidup;

void setup() {
  Serial.begin(9600);
  pinMode(dC, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();

    switch (input) {
      case '1':
        dCstate = 1;
        Serial.println("Motor Hidup");
        break;
      case '0':
        dCstate = 0;
        Serial.println("Motor Mati");
        break;
      case 't':
        while (Serial.available() == 0);
        dChidup = Serial.parseInt();
        Serial.println("Lama motor hidup selama " + String(dChidup) + " ms");
        break;
      default:
        Serial.println("PERINTAH TIDAK DITEMUKAN");
        break;
    }
  }

  waktuSekarang = millis();
  if (dCstate == 1) {
    if (waktuSekarang - waktuSebelumnya >= dChidup) {
      digitalWrite(dC, LOW);
      dCstate = 0;
      waktuSebelumnya = waktuSekarang;
    }
  } else {
  }
}
