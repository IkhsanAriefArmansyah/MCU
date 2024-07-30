const int S1 = 2;
const int S2 = 4;
const int LED1 = 6;
const int LED2 = 8;

char mode = 'A';

void setup() {
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    mode = Serial.read();
    Serial.print("Mode ");
    Serial.println(mode);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }

  if (mode == 'A') {
    if (digitalRead(S1) == HIGH) {
      digitalWrite(LED1, HIGH);
      delay(250);
      digitalWrite(LED1, LOW);
    }
    if (digitalRead(S2) == HIGH) {
      digitalWrite(LED2, HIGH);
      delay(250);
      digitalWrite(LED2, LOW);
    }
  } else if (mode == 'B') {
    digitalWrite(LED1, HIGH);
    delay(250);
    digitalWrite(LED1, LOW);
    delay(250);
    digitalWrite(LED2, HIGH);
    delay(250);
    digitalWrite(LED2, LOW);
  } else if (mode == 'C') {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }
}

//TUGAS PRAK 5.4