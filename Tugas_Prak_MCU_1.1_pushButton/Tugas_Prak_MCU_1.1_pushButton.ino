const int tombol = 2; 
const int lampu = 3; 

void setup() {
  Serial.begin(9600);
  pinMode(tombol, INPUT);
  pinMode(lampu, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(tombol);

  if (buttonState == LOW) {
    digitalWrite(lampu, LOW);
    Serial.println("push button bernilai 1, lampu hidup");
  } else {
    digitalWrite(lampu, HIGH);
    Serial.println("push button bernilai 0, lampu mati");
  }
  delay(100); 
} 
