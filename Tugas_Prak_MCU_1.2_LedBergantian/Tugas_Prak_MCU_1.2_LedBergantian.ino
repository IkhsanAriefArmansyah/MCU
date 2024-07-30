const int tombolPin = 2;  
const int ledPin1 = 3;    
const int ledPin2 = 4;    
const int ledPin3 = 5;   
const int ledPin4 = 6;   
int lampuAktif;  
bool tombolDitekan = false; 

void setup() {
  Serial.begin(9600);

  pinMode(tombolPin, INPUT);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
}

void loop() {
int tombolState = digitalRead(tombolPin);

  if (tombolState == HIGH && !tombolDitekan) {
    tombolDitekan = true;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);

    switch (lampuAktif) {
      case 0:
        digitalWrite(ledPin1, HIGH);
        Serial.println("Lampu 1 aktif");
        break;
      case 1:
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, HIGH);
        Serial.println("Lampu 2 aktif");
        break;
      case 2:
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, HIGH);
        Serial.println("Lampu 3 aktif");
        break;
      case 3:
        digitalWrite(ledPin1, LOW);
        digitalWrite(ledPin2, LOW);
        digitalWrite(ledPin3, LOW);
        digitalWrite(ledPin4, HIGH);
        Serial.println("Lampu 4 aktif");
        break;
    }

    lampuAktif = (lampuAktif + 1) % 4;
  } else if (tombolState == LOW) {
    tombolDitekan = false;
  }

  delay(100); 
}
