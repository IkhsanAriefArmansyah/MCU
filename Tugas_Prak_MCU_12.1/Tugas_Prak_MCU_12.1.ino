#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define LDR A0
#define SD_CS_PIN 4

RTC_DS1307 rtc;
Adafruit_SSD1306 display(128, 64, &Wire);

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}

void loop() {
  int nilaiLDR = analogRead(LDR);
  float kecerahan = map(nilaiLDR, 0, 1023, 0, 100);

  DateTime now = rtc.now();

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Waktu: ");
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.print(':');
  display.print(now.second(), DEC);

  display.setCursor(0, 10);
  display.print("Kecerahan: ");
  display.print(kecerahan);
  display.print("%");

  display.display();

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.print(now.year(), DEC);
    dataFile.print('/');
    dataFile.print(now.month(), DEC);
    dataFile.print('/');
    dataFile.print(now.day(), DEC);
    dataFile.print(' ');
    dataFile.print(now.hour(), DEC);
    dataFile.print(':');
    dataFile.print(now.minute(), DEC);
    dataFile.print(':');
    dataFile.print(now.second(), DEC);
    dataFile.print(", ");
    dataFile.print(kecerahan);
    dataFile.println("%");
    dataFile.close();
  } else {
    Serial.println("error opening datalog.txt");
  }
  delay(1000);
}
