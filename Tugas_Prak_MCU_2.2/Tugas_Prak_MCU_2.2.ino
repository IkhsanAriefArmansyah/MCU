const int button1Pin = 2; 
const int button2Pin = 3; 
const int button3Pin = 4; 
const int LED_mrh = 9; 
const int LED_kuning = 10; 
const int LED_hijau = 11; 

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(LED_mrh, OUTPUT);
  pinMode(LED_kuning, OUTPUT);
  pinMode(LED_hijau, OUTPUT);
}

void loop() {
  int button1State = digitalRead(button1Pin);
  int button2State = digitalRead(button2Pin);
  int button3State = digitalRead(button3Pin);

  if (button1State == HIGH && button2State == HIGH) {
    digitalWrite(LED_mrh, HIGH);
  } else if (button1State == HIGH || button3State == HIGH) {
    digitalWrite(LED_kuning, HIGH);
  } else if (button1State == HIGH && button2State == HIGH && button3State == HIGH) {
    digitalWrite(LED_mrh, HIGH);
    digitalWrite(LED_kuning, HIGH);
    digitalWrite(LED_hijau, HIGH);
  } else {
    digitalWrite(LED_mrh, LOW);
    digitalWrite(LED_kuning, LOW);
    digitalWrite(LED_hijau, LOW);
  }
}