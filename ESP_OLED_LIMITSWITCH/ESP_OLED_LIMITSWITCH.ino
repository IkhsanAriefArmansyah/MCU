#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Lebar layar OLED dalam piksel
#define SCREEN_HEIGHT 64 // Tinggi layar OLED dalam piksel

// Deklarasi untuk tampilan SSD1306 yang terhubung melalui I2C (pin SDA, SCL)
#define OLED_RESET    -1 // Pin reset (atau -1 jika Anda tidak menggunakan pin reset)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LIMIT_SWITCH_PIN 15 // Pin yang terhubung ke Limit Switch

void setup() {
  Serial.begin(115200);
  pinMode(LIMIT_SWITCH_PIN, INPUT_PULLUP); // Mengatur pin Limit Switch sebagai input dengan resistor pull-up

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 alokasi gagal"));
    for (;;) {} // Jangan melanjutkan, lakukan loop selamanya
  }
}

void loop() {
    int limitSwitchState = digitalRead(LIMIT_SWITCH_PIN);

  if (limitSwitchState == HIGH) {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F("HIDUP"));
    display.display();
  } else {
    display.clearDisplay();
    display.setTextSize(3);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println(F(" "));
    display.display();

    
  }
}
