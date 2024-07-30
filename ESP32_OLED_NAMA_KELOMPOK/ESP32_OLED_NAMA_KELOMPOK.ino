#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  display.clearDisplay();

  //atur ukuran tulisan
  display.setTextSize(1);       // ukuran normal 1:1
  display.setTextColor(WHITE);  // tulisan warna putih

  //buat tulisan welcome to hollanda academy


  display.setCursor(0, 0);
  display.setTextSize(2, 5);  // kursor diletakkan pada baris 0 kolom 0
  display.print("BRNACLEBOT");
  display.setCursor(0, 40);  // kursor diletakkan pada baris 15 kolom 0
  display.setTextSize(3);    // ukuran perbesar 1:2
  display.print("TANK");
  display.display();
  delay(1000);
  display.setCursor(0, 35);  // kursor diletakkan pada baris 50 kolom 0
  display.print(" ");
  display.display();
  delay(1000);
  display.clearDisplay();  // hapus tulisan di layar

  display.setCursor(0, 0);
  display.setTextSize(2);  // kursor diletakkan pada baris 0 kolom 0
  display.print("Arief");
  delay(1000);
  display.setCursor(0, 15);  // kursor diletakkan pada baris 15 kolom 0
  display.setTextSize(2);    // ukuran perbesar 1:2
  display.print("Nizam");
  delay(1000);
  display.setCursor(0, 35);
  display.setTextSize(2);  // kursor diletakkan pada baris 50 kolom 0
  display.print("Nike");
  display.display();
  delay(1000);
  display.clearDisplay();  // hapus tulisan di layar
  display.display();
}
