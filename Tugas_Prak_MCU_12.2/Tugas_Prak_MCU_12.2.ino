#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

void setup() {
  Serial.begin(9600);
  int jumlahFile = 0;
  while (SD.exists("log" + String(jumlahFile) + ".txt")) {
    jumlahFile++;
  }

  String namaFile = "log" + String(jumlahFile) + ".txt";
  File dataFile = SD.open(namaFile, FILE_WRITE);

  if (dataFile) {
    dataFile.println("Ini adalah file " + namaFile);
    dataFile.close();
    Serial.println("File " + namaFile + " berhasil dibuat.");
  } else {
    Serial.println("File gagal dibuat");
  }
}

void loop() {
}
