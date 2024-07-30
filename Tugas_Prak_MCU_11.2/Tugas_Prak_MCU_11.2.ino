#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <time.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define POT_PIN A0

#define OLED_SDA 4
#define OLED_SCL 5
#define OLED_RESET 23

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int dn;

String waktu, tanggal;

int bacaDN() {
  return analogRead(POT_PIN);
}

void dapatkanWaktuTanggal() {
  // Dapatkan waktu dan tanggal dari library time
  struct tm tm;
  time_t now = time(NULL);
  localtime_r(&now, &tm);
pinMode(POT_PIN, INPUT);
  // Format waktu dan tanggal
  waktu = String(tm.tm_mday) + "/" + String(tm.tm_mon + 1) + "/" + String(tm.tm_year + 1900) + " " + String(tm.tm_hour) + ":" + String(tm.tm_min) + ":" + String(tm.tm_sec);
  tanggal = String(tm.tm_year + 1900) + "-" + String(tm.tm_mon + 1) + "-" + String(tm.tm_mday);
}

void setup() {
  // Inisialisasi Serial
  Serial.begin(9600);

  // Inisialisasi OLED
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Set font size
  display.setTextSize(2);
}

void loop() {
  // Baca nilai DN dari potensiometer
  dn = bacaDN();

  // Dapatkan waktu dan tanggal saat ini
  dapatkanWaktuTanggal();

  // Tampilkan waktu dan tanggal di OLED
  display.setCursor(0, 0);
  display.println(waktu);

  // Tampilkan nilai DN di OLED
  display.setCursor(0, 32);
  display.println(dn);

  // Tampilkan nilai DN di Serial Monitor
  Serial.println(tanggal + "-" + String(dn));

  // Tunda selama 1 detik
  delay(1000);
}
