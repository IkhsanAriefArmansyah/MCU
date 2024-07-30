const int buttonPin = 2;  
const int ledPin1 = 3;   
const int ledPin2 = 4;  
const int ledPin3 = 5;   
const int ledPin4 = 6;  

bool lampu1Aktif = false; 
bool tombolDitekan = false; 

void setup() {
pinMode(buttonPin, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, LOW);
}

void loop() {
int tombolState = digitalRead(buttonPin);

  if (tombolState == LOW && !tombolDitekan) {
    tombolDitekan = true;

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);

    if (lampu1Aktif) {
      digitalWrite(ledPin1, HIGH);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    } 
    else if (lampu1Aktif){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
    }
    else if (lampu1Aktif){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);
      digitalWrite(ledPin4, LOW);
    }
    else{
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, HIGH);
    }
  lampu1Aktif = !lampu1Aktif;
  }
  else (tombolState == HIGH); {
  tombolDitekan = false;
  }
}
