byte potensio = A2;
byte led = 13;
int nilai;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  nilai = analogRead(potensio);
  Serial.print("Nilai digital potensiometer= ");
  Serial.println(nilai);

  if (nilai < 250) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
