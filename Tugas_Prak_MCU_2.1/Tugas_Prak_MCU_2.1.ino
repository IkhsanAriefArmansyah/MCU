const int button1Pin = 2; // Pin untuk tombol pertama
const int button2Pin = 3; // Pin untuk tombol kedua
const int button3Pin = 4; // Pin untuk tombol ketiga
const int led1Pin = 9; // Pin untuk LED pertama
const int led2Pin = 10; // Pin untuk LED kedua
const int led3Pin = 11; // Pin untuk LED ketiga

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);

  if (button1State == HIGH) {
    digitalWrite(led1Pin, HIGH);
  } else {
    digitalWrite(led1Pin, LOW);
  }

  if (button2State == HIGH) {
    digitalWrite(led2Pin, HIGH);
  } else {
    digitalWrite(led2Pin, LOW);
  }

  if (button3State == HIGH) {
    digitalWrite(led3Pin, HIGH);
  } else {
    digitalWrite(led3Pin, LOW);
  }
}