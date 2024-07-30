const int pm = A0;
const int red = 2;
const int yllw = 4;
const int grn = 6;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yllw, OUTPUT);
  pinMode(grn, OUTPUT);
}

void loop() {
  int nilai = analogRead(pm);
  Serial.print("Nilai Potensiometer: ");
  Serial.println(nilai);

  if (nilai > 800) {
    digitalWrite(red, HIGH);
    digitalWrite(yllw, LOW);
    digitalWrite(grn, LOW);
    Serial.println("Air dalam tangki tinggi");
  } else if (nilai >= 400 && nilai <= 800) {
    digitalWrite(red, LOW);
    digitalWrite(yllw, HIGH);
    digitalWrite(grn, LOW);
    Serial.println("Air dalam tangki sedang");
  } else {
    digitalWrite(red, LOW);
    digitalWrite(yllw, LOW);
    digitalWrite(grn, HIGH);
    Serial.println("Air dalam tangki rendah");
  }
  delay(500);
}
