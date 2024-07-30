byte trigPin1 = 12;
byte echoPin1 = 34;
byte trigPin2 = 13;
byte echoPin2 = 36;

byte IN1 = 26;  //motor1 INA
byte IN2 = 27;  //motor1 INAB
byte IN3 = 17;  //motor2 INA
byte IN4 = 16;  //motor2 INAB

#define kecepatanSuara 0.034

float jarakcm1, jarakcm2;

void setup() {
  Serial.begin(115200);
  //inisialisasi sensor jarak
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);


  //inisialisasi motor
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.println("ROBOT MOVEMENT");
  Serial.println("Sensor 1(cm), Sensor 2 (cm)");
}

void loop() {
  jarakcm1 = ambilJarak(trigPin1, echoPin1);
  jarakcm2 = ambilJarak(trigPin2, echoPin2);


  Serial.print(jarakcm1, 2);
  Serial.print(" , ");
  Serial.print(jarakcm2, 2);
  Serial.print(" , ");


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
  digitalWrite(IN1, 0);  //motor1 A
  digitalWrite(IN2, 0);  //motor1 B
  digitalWrite(IN3, 1);  //motor2 A
  digitalWrite(IN4, 0);  //motor2 B
}

void belokKiri() {
  Serial.println("Belok Kiri");
  digitalWrite(IN1, 1);  //motor1 A
  digitalWrite(IN2, 0);  //motor1 B
  digitalWrite(IN3, 0);  //motor2 A
  digitalWrite(IN4, 0);  //motor2 B
}

void lurus() {
  Serial.println("Lurus");
  digitalWrite(IN1, 1);  //motor1 A
  digitalWrite(IN2, 0);  //motor1 B
  digitalWrite(IN3, 1);  //motor2 A
  digitalWrite(IN4, 0);  //motor2 B
}

void berhenti() {
  Serial.println("Berhenti");
  digitalWrite(IN1, 0);  //motor1 A
  digitalWrite(IN2, 0);  //motor1 B
  digitalWrite(IN3, 0);  //motor2 A
  digitalWrite(IN4, 0);  //motor2 B
}
