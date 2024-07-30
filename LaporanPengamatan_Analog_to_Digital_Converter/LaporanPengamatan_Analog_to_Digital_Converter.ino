const int potPin = 34; // Pin analog potensiometer
const float vcc = 3.3; // Reference voltage in volts

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(potPin); // Membaca nilai analog dari potensiometer
  float volt = sensorValue * (vcc / 4095.0); // Menghitung tegangan

  Serial.print("Nilai Digital Potensiometer: ");
  Serial.println(sensorValue);
  
  Serial.print("Tegangan: ");
  Serial.print(volt * 1000); // Convert voltage to mV
  Serial.println(" mV");

  delay(1000); // Delay 1 detik
}
