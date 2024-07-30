#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C
#define OLED LED_BUILTIN
Adafruit_SSD1306 display(OLED);

void setup() {
  pinMode(OLED, OUTPUT);
  digitalWrite(OLED, LOW);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  for (byte arr = 1; arr <= 60; arr++) {
    display.clearDisplay();
    display.setTextSize(4);
    display.setTextColor(WHITE);
    display.setCursor(45, 0);
    display.println(arr);
    display.display();
    delay(1000);
  }
}
