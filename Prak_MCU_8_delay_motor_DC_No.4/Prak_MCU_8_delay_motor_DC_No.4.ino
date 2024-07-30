//inisialisasi pin
const int ledPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  Serial.println("Mengukur waktu yang dibutuhkan untuk menjalankan suatu tugas");
}

void loop() {
  long startTime = millis();//inisialisasi variabel
  digitalWrite(ledPin, HIGH); //Nyalakan LED
  delay(1000);//mematikan LED
  digitalWrite(ledPin,  LOW);//MEMATIKAN LED

  long endTime = millis();//hitung waktu yang dibutuhkan
  Serial.println(endTime - startTime);//tampilkan waktu yang dibutuhkan
}
