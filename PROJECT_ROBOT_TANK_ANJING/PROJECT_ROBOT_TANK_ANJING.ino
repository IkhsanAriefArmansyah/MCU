
byte trigPin1 = 2;
byte echoPin1 = 4;
byte trigPin2 = 34;
byte echoPin2 = 35;
byte trigPin3 = 18;
byte echoPin3 = 19;
byte IN1 = 25;  //motor1 INA
byte IN2 = 26;  //motor1 INAB
byte IN3 = 27;  //motor2 INA
byte IN4 = 14;  //motor2 INAB

#define kecepatanSuara 0.034

float jarakcm1, jarakcm2, jarakcm3;

void setup() {
  Serial.begin(115200);
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

  Serial.println("ROBOT MOVEMENT");
  Serial.println("Sensor 1(cm), Sensor 2 (cm), Sensor 3 (cm)");
}

void loop() {
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


  //jika sensor 1 dan sensor 3 lebih dari 100 maka lurus
  //artinya kedua motor aktif
  if (jarakcm1 >= 100 && jarakcm3 >= 100) lurus();

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

void lurus() {
  Serial.println("Lurus");
  digitalWrite(IN1, 0);  //motor1 A
  digitalWrite(IN2, 1);  //motor1 B
  digitalWrite(IN3, 0);  //motor2 A
  digitalWrite(IN4, 1);  //motor2 B
}

void berhenti() {
  Serial.println("Berhenti");
  digitalWrite(IN1, 0);  //motor1 A
  digitalWrite(IN2, 0);  //motor1 B
  digitalWrite(IN3, 0);  //motor2 A
  digitalWrite(IN4, 0);  //motor2 B
}