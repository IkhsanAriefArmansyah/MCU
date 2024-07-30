const int dC = 2;
void setup() {
  pinMode(dC, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    char input = Serial.read();
    switch (input) {
      case '1':
        hidup();
        break;
      case '0':
        mati();
        break;
      default:
        Serial.println("Perintah tidak valid!");
    }
  }
}
void hidup() {
  digitalWrite(dC, HIGH);
  Serial.println("Motor DC hidup");
}
void mati() {
  digitalWrite(dC, LOW);
  Serial.println("Motor DC mati");
}

//TUGAS 5