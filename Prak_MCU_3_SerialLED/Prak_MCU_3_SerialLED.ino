const int led1Pin = 5;
const int led2Pin = 6;

void setup() {
Serial.begin(9600);
pinMode(led1Pin, OUTPUT);
pinMode(led2Pin, OUTPUT);
}

void loop() {
if (Serial.available()) {
  char perintah = Serial.read();

  switch (perintah) {
    case '1':
      digitalWrite(led1Pin, HIGH);
      break;
    case '2':
      digitalWrite(led1Pin, LOW);
      break;
    case '3':
      digitalWrite(led2Pin, HIGH);
      break;
    case '4':
      digitalWrite(led2Pin, LOW);
      break;
    default:
      break;
    }
  }
}