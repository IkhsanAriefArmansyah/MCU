const int potentiometerPin = A3;  //Pin analog untuk potensiometer
const int ledPin = 13;           //Pin untuk LED
const int numReadings = 10;      //Jumlah pengukuran untuk diambil rata-ratanya

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int total = 0;
  int readingsTaken = 0;  //Jumlah pengukuran yang telah diambil

  while (readingsTaken < numReadings) {
    int sensorValue = analogRead(potentiometerPin);  //Membaca nilai dari potensiometer
    total += sensorValue;
    readingsTaken++;
    delay(100); //Jeda 100ms antara pengukuran
  }
  int rerata = total / numReadings;
  Serial.print("Rata-rata Sensor : ");
  Serial.println(rerata);

  //Mengendalikan LED untuk berkeip sesuai dengan nilai rata-rata
  if (rerata < 512) {
    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPin, HIGH);
      delay(rerata);  //Waktu LED menyala
      digitalWrite(ledPin, LOW);
      delay(rerata);  //Waktu LED mati
    }
  } else {

    for (int i = 0; i < 10; i++) {
      digitalWrite(ledPin, HIGH);
      delay(rerata);  //Waktu LED menyala
      digitalWrite(ledPin, LOW);
      delay(rerata);  //Waktu LED mati
    }
  }
}
