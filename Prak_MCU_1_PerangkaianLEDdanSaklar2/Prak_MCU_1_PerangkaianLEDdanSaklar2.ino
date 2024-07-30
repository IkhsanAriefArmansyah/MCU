//simulasi led dan saklar
int button = 2;
int nilaitombol;
int count;
int led = 13;

void setup() {
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  nilaitombol = digitalRead(button);

  if (nilaitombol == 0){
  digitalWrite (led, LOW);
  }
  else {
   digitalWrite (led, HIGH);
  }
}
