unsigned long startTime;

void setup() {
  Serial.begin(9600);
  startTime = micros();
}

void loop() {
  unsigned long currentTime = micros();
  unsigned long elapsedTime = currentTime - startTime;

  Serial.print("Waktu berlalu (microdetik) : ");
  Serial.print(elapsedTime);
  delay(1000);//Tunggu 1 detik
}
