const int bttn = 2;
const int led = 4;
unsigned long waktuTekan = 0; 
boolean diTekan = false;

void setup() {
  pinMode(bttn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  if (digitalRead(bttn) == LOW) {
    if (!diTekan) {
      waktuTekan = millis();
      diTekan = true;
      digitalWrite(led, HIGH);
    }
  } else {
    if (diTekan) {
      unsigned long waktuRilis = millis();
      unsigned long tahan = waktuRilis - waktuTekan;
      Serial.print("Tombol saat ditekan: ");
      Serial.print(tahan);
      Serial.println(" ms");
      digitalWrite(led, LOW);
      diTekan = false;
    }
  }
}

//TUGAS 1