byte tombol = 2;
byte led = 13;
int nilai;

void setup() {
pinMode(tombol, INPUT_PULLUP);
pinMode(led, OUTPUT);

Serial.begin(9600);
}

void loop() {
nilai = digitalRead(tombol);
Serial.print("Nilai tombol = ");
Serial.println(nilai);

if (nilai == 1) {
  digitalWrite(led, HIGH);
}
else {
  digitalWrite(led, LOW);
}
}
