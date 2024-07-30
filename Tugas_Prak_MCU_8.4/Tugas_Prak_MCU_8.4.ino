const int dC = 3;
const int bttn1 = 6;
const int bttn2 = 9;

int bttnState1 = 0;
int bttnState2 = 0;

void setup() {
  pinMode(dC, OUTPUT);
  pinMode(bttn1, INPUT);
  pinMode(bttn2, INPUT);
}

void loop() {
  bttnState1 = digitalRead(bttn1);
  bttnState2 = digitalRead(bttn2);

  if (bttnState1 == HIGH) {
    digitalWrite(dC, HIGH);
  } else if (bttnState2 == HIGH) {
    digitalWrite(dC, LOW);
  }
}

//TUGAS 4