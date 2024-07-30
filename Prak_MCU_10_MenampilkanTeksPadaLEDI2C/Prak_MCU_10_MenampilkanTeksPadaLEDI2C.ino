#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
int16_t x1, y1;
uint16_t w, h;

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();                                          // Hapus tampilan
  display.setTextSize(1);                                          // Ukuran teks
  display.setTextColor(SSD1306_WHITE);                             // Warna teks
  display.setTextSize(1);                                          // Ukuran teks
  display.getTextBounds("Selamat datang", 0, 0, &x1, y1, &w, &h);  //mencari Jumlah piksel pada kalimat
  byte tengah = (128 - w) / 2;
  display.setCursor(tengah, 10);  // Posisi teks
  display.println(F("Selamat datang"));
  display.display();
  delay(2000);  // Tampilkan selama 2 detik
  display.setTextSize(2);
  display.setCursor(0, 20);
  display.println(F("Arduino I2C OLED"));
  display.display();
  delay(2000);
}

void loop() {
}
