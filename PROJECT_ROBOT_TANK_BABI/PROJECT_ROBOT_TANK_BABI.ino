int TRG1 = 12;
int ECHO1 = 13;
int TRG2 = 32;
int ECHO2 = 33;
int TRG3 = 18;
int ECHO3 = 19;

int IN1 = 16;
int IN2 = 17;
int IN3 = 25;
int IN4 = 26;

const int frequency = 0;
const int pwm_channel = 0;
const int resolution = 0;

void setup() {
pinMode(TRG1, INPUT);
pinMode(ECHO1, OUTPUT);
pinMode(TRG1, INPUT);
pinMode(ECHO2, OUTPUT);
pinMode(TRG1, INPUT);
pinMode(ECHO3, OUTPUT);


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  ledcSetup(pwm_channel, frequency, resolution);

}

void loop() {
  setDirection();
  delay(1000);
}

void setDirection() {

  ledcWrite(pwm_channel, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(1000);

}
