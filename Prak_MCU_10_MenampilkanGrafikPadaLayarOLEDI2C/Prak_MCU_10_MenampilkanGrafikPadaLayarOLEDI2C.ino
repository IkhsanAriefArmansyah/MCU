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

  display.clearDisplay();  // Hapus tampilan

  display.setTextSize(2);  // Ukuran teks

  display.setTextColor(SSD1306_WHITE);                 // warna teks
  display.getTextBounds("TE", 0, 0, &x1, y1, &w, &h);  //mencari jumlah piksel pada kalimat

  byte tengah = (128 - w) / 2;

  display.setCursor(tengah, SCREEN_HEIGHT / 2 - 7);  // Posisi teks

  display.println(F("TE"));

  display.display();

  display.drawCircle(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 20, SSD1306_WHITE);
  display.display();

  delay(1000);
}

void loop() {
}
