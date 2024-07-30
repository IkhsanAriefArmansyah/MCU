const int red = 3;
const int grn = 6;
const int blu = 9;
void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(grn, OUTPUT);
  pinMode(blu, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    char instruction = Serial.read();

    switch (instruction) {
      case 'R':
        digitalWrite(red, HIGH);
        digitalWrite(grn, LOW);
        digitalWrite(blu, LOW);
        break;
      case 'G':
        digitalWrite(red, LOW);
        digitalWrite(grn, HIGH);
        digitalWrite(blu, LOW);
        break;
      case 'B':
        digitalWrite(red, LOW);
        digitalWrite(grn, LOW);
        digitalWrite(blu, HIGH);
        break;
      default:
        digitalWrite(red, LOW);
        digitalWrite(grn, LOW);
        digitalWrite(blu, LOW);
        break;
    }
  }
}
