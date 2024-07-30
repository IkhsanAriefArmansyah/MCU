int LED[]={3,5,2,6};
int tombol = 10;
int nilaiTombol;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, INPUT_PULLUP);
}
void loop() {
  nilaiTombol = digitalRead(tombol);
  if (nilaiTombol==0){
    digitalWrite(3, HIGH);
    Serial.println("1");
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);
    digitalWrite(5, HIGH);
    Serial.println("2");
    delay(1000);
    digitalWrite(5, LOW);
    delay(1000);
    digitalWrite(2, HIGH);
    Serial.println("3");
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
    digitalWrite(6, HIGH);
    Serial.println("4");
    delay(1000);
    digitalWrite(6, LOW);
    delay(1000);
  }else{
    digitalWrite(LED, LOW);
    Serial.println("Tombol Dilepas");
    delay(1000); 
  }
} 
