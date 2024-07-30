int button= 6;
int nilaitombol;
int count;
int led= 7;

void setup() {
Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop() {
  nilaitombol= digitalRead(button);

  if (nilaitombol == 1){
      digitalWrite(led, HIGH);   
      Serial.println("lampu LED menyala");

    }
   else {
      digitalWrite(led, LOW);
      Serial.println("lampu LED tidak menyala");

    }
  }
