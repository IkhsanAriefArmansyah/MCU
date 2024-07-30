const int red = 3;
const int yllw = 6;
const int grn = 9;

bool runningLED = true;

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yllw, OUTPUT);
  pinMode(grn, OUTPUT);
  Serial.begin(9600);
  Serial.println("traffic lights akan terus menyala sampai karakter 'p' dikirimkan");
}

void loop() {
  if (runningLED) {
    digitalWrite(red, HIGH);
    delay(2000);
    digitalWrite(red, LOW);

    digitalWrite(yllw, HIGH);
    delay(2000);
    digitalWrite(yllw, LOW);

    digitalWrite(grn, HIGH);
    delay(2000);
    digitalWrite(grn, LOW);

    if (Serial.available() > 0) {
      char stopped = Serial.read();
      if (stopped == 'p') { 
        runningLED = false;
      }
    }
  }
}

//TUGAS PRAK 5.2