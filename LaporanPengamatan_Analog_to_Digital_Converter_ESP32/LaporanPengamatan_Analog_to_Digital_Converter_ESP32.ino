const int potensiometer = 13; // Pin analog potensiometer

void setup() {
  Serial.begin(115200);
}

void loop() {
  int nilaiDigital = analogRead(potensiometer); // Membaca nilai analog dari potensiometer
  float tegangan = analogReadMilliVolts(potensiometer) / 1000.0; // Menghitung tegangan dalam mV

  Serial.print("Nilai Analog: ");
  Serial.println(nilaiDigital);
  
  Serial.print("Tegangan: ");
  Serial.print(tegangan);
  Serial.println(" mV");

  delay(1000); // Delay 1 detik
}
