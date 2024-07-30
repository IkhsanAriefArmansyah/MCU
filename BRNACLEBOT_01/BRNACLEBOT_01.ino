#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <RTClib.h>

#define SCREEN_WIDTH 128 // OLED display lebar dalam piksel
#define SCREEN_HEIGHT 64 // OLED display tinggi dalam piksel

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//global variabel untuk membuat tulisan rata tengah
byte panjang, lebar;
int16_t  x, y;
uint16_t w, h;

//inisialisasi RTC
RTC_DS1307 rtc;
int tahun;
byte bulan, hari, jam, menit, detik;
char tanggal[20] = "yyyy/mm/dd hh:mm:ss";


//global variabel
boolean tekan;


//ultrasonik
byte trigPin1 = 12;
byte echoPin1 = 34;
byte trigPin2 = 13;
byte echoPin2 = 36;
byte trigPin3 = 14;
byte echoPin3 = 39;


byte IN1 = 26; //motor1 INA
byte IN2 = 27; //motor1 INAB
byte IN3 = 17; //motor2 INA
byte IN4 = 16; //motor2 INAB

byte Misil = 32;
#define kecepatanSuara 0.034

float jarakcm1, jarakcm2, jarakcm3;

void setup() {
  Serial.begin(115200);
  //pengaturan RTC 
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(1);

  if (!rtc.begin() || !rtc.isrunning()) {
    Serial.println("RTC tidak ditemukan");
    Serial.flush();
    display.setCursor(0, 0);
    display.print("RTC Error!!!");
    display.display();
    while (1) delay(10);
  } else {
    display.setCursor(0, 0);
    display.print("RTC OK!!!");
    display.display();
  }
  delay(2000);
  display.clearDisplay();
  display.display();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.print("DISPLAY");
  display.setCursor(0, 15);
  display.print("TANGGAL");
  display.setCursor(0, 30);
  display.print("DAN");
  display.setCursor(0, 45);
  display.print("WAKTU");
  display.display();
  delay(2000);

  //oled
  pinMode(4, INPUT_PULLUP);
  //inisialisasi sensor jarak
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);

  //inisialisasi motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  display.clearDisplay();

  //atur ukuran tulisan
  display.setTextSize(1.5);      // ukuran normal 1:1
  display.setTextColor(WHITE); // tulisan warna putih

  //buat tulisan welcome to hollanda academy
  display.getTextBounds("BRNACLEBOT TANK", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
  panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
  display.setCursor(panjang, 0);     // kursor diletakkan pada rata tengah kolom 0
  display.print("BRNACLEBOT TANK");
  display.display();
  delay(1000);

  //sekarang kita buat tulisan di bagian tengah layar
  display.setTextSize(1);      // ukuran normal 1:1
  display.setTextColor(WHITE); // tulisan warna putih

  display.getTextBounds("NIZAM", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
  panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
  lebar = (SCREEN_HEIGHT - h) / 2;
  display.setCursor(panjang, 20);     // kursor diletakkan pada rata tengah kolom 0
  display.print("NIZAM");
  display.display();

  //sekarang kita buat tulisan di bagian bawah layar
  display.getTextBounds("NIKE", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
  panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
  lebar = SCREEN_HEIGHT - h;
  display.setCursor(panjang, 35);     // kursor diletakkan pada rata tengah kolom 0
  display.print("NIKE");
  display.display();

  //sekarang kita buat tulisan di bagian bawah layar
  display.getTextBounds("ARIEF", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
  panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
  lebar = SCREEN_HEIGHT - h;
  display.setCursor(panjang, 50);     // kursor diletakkan pada rata tengah kolom 0
  display.print("ARIEF");
  display.display();

  Serial.println("ROBOT MOVEMENT");
  Serial.println("Sensor 1(cm), Sensor 2 (cm), Sensor 3 (cm) ");
}

void loop() {
  //perulangan RTC data
  DateTime nows = rtc.now();
  tahun = nows.year();
  bulan = nows.month();
  hari = nows.day();
  jam = nows.hour();
  menit = nows.minute();
  detik = nows.second();

  sprintf(tanggal, "%4d/%02d/%02d %02d:%02d:%02d", tahun, bulan, hari, jam, menit, detik);
  Serial.println(tanggal);

  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(tanggal);
  display.display();
  delay(1000);


  tekan = digitalRead(4);
  Serial.print(tekan);
  Serial.print(" ");

  display.clearDisplay();
  if (tekan == 0) {
    Serial.println("limit switch ditekan");
    display.setTextSize(2);
    display.getTextBounds("LMT SWITCH ON", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
    panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
    lebar = (SCREEN_HEIGHT - h) / 2;
    display.setCursor(panjang, lebar);     // kursor diletakkan pada rata tengah kolom 0
    display.print("LMT SWITCH ON");
    display.display();
    //while(1){
    //delay(1000);

  }
  else {
    Serial.println("limit switch tidak ditekan");
    display.setTextSize(2);
    display.getTextBounds("LMT SWITCH OFF", 0, 0, &x, &y, &w, &h); //untuk mendapatkan jumlah piksel dalam lebar dan tinggi untuk tulisan WELCOME
    panjang = (SCREEN_WIDTH - w) / 2; // Untuk menentukan penempatan piksel pertama
    lebar = (SCREEN_HEIGHT - h) / 2;
    display.setCursor(panjang, lebar);     // kursor diletakkan pada rata tengah kolom 0
    display.print("LMT SWITCH OFF");
    display.display();
  }

  jarakcm1 = ambilJarak(trigPin1, echoPin1);
  jarakcm2 = ambilJarak(trigPin2, echoPin2);
  jarakcm3 = ambilJarak(trigPin3, echoPin3);


  Serial.print(jarakcm1, 2);
  Serial.print(" , ");
  Serial.print(jarakcm2, 2);
  Serial.print(" , ");
  Serial.println(jarakcm3);


  //sensor 1 dan sensor 3 menjadi dasar untuk pergerakan motor
  //jika sensor 1 kurang dari 100 dan sensor 3 lebih dari 100 maka belok kiri
  //artinya motor kanan aktif dan motor kiri berhenti
  if (jarakcm1 < 30 && jarakcm2 >= 30) belokKanan();

  //jika sensor 1 lebih dari 100 dan sensor 3 kurang dari 100 maka belok kanan
  //artinya motor kiri aktif dan motor kanan berhenti;
  else if (jarakcm1 >= 30 && jarakcm2 < 30) belokKiri();

  //jika sensor 1 dan sensor 3 lebih dari 100 maka lurus
  //artinya kedua motor aktif
  else if (jarakcm1 >= 30 && jarakcm2 >= 30) lurus();

 
  //selain itu motor berhenti
  else berhenti();
  delay(500);
   if (jarakcm3 < 15) {
    Serial.println("fire fire");
    digitalWrite(Misil, 1);
  }
  //Jika jarak lebih dari 50 cm maka lampu mati.
  else {
    Serial.println("hayoloo");
    digitalWrite(Misil, 0);
  }
  delay(500);
}

float ambilJarak(byte trigPin, byte echoPin) {
  float jarak = 0;
  unsigned long durasi = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durasi = pulseIn(echoPin, HIGH);

  // Calculate the distance
  jarak = durasi * kecepatanSuara / 2;
  return jarak;
}

void belokKanan() {
  Serial.println("Belok Kanan");
  digitalWrite(IN1, 0); //motor1 A
  digitalWrite(IN2, 0); //motor1 B
  digitalWrite(IN3, 1); //motor2 A
  digitalWrite(IN4, 0); //motor2 B
}

void belokKiri() {
  Serial.println("Belok Kiri");
  digitalWrite(IN1, 1); //motor1 A
  digitalWrite(IN2, 0); //motor1 B
  digitalWrite(IN3, 0); //motor2 A
  digitalWrite(IN4, 0); //motor2 B
}

void lurus() {
  Serial.println("Lurus");
  digitalWrite(IN1, 1); //motor1 A
  digitalWrite(IN2, 0); //motor1 B
  digitalWrite(IN3, 1); //motor2 A
  digitalWrite(IN4, 0); //motor2 B
}

void berhenti() {
  Serial.println("Berhenti");
  digitalWrite(IN1, 0); //motor1 A
  digitalWrite(IN2, 0); //motor1 B
  digitalWrite(IN3, 0); //motor2 A
  digitalWrite(IN4, 0); //motor2 B
}