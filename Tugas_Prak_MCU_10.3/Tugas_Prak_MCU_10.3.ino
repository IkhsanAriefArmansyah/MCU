#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Servo srvo;

void setup() {
  Serial.begin(9600);
  srvo.attach(9); 
  pinMode(A0, INPUT);
}

void loop() {
  int potentio = analogRead(A0);
  int sudutServo = map(potentio, 0, 1023, 0, 180);

  srvo.write(sudutServo);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(30, 0);
  display.println("Servo");
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(50, 20);
  display.println(sudutServo);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(25, 45);
  display.println("Derajat");
  display.display();
  delay(1000); 
}
