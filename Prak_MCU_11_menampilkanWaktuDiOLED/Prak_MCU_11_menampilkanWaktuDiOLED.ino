#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
RTC_DS3231 rtc;

void setup() {
Serial.begin(9600);
if (! rtc.begin()) {
  Serial.println("RTC tidak ditemukan");
  Serial.flush();
  while (1) delay (10);
}

display.begin(SSD1306_SWITCHCAPVCC, 0X3C);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(SSD1306_WHITE);
}

void loop() {
  DateTime now = rtc.now();

  char formattedDateTime[20];

  snprintf (formattedDateTime, sizeof(formattedDateTime),
            "%02d/%02d/%04d:%02d:%02d",
            now.day(), now.month(), now.year(),
            now.hour(), now.minute(), now.second());

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println(formattedDateTime);
  display.display();

  delay(1000);
}
