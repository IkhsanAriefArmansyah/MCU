const int pm = A0;
const int red = 2;
const int yllw = 4;
const int grn = 6;
int ketinggianAir;

void setup() {
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yllw, OUTPUT);
  pinMode(grn, OUTPUT);
}

void loop() {
  int nilai = analogRead(pm);
  Serial.print("Nilai Potensiometer: ");
  Serial.println(nilai);

  if (nilai > 800) {
    ketinggianAir = 1;
  } else if (nilai >= 400 && nilai <= 800) {
    ketinggianAir = 2;
  } else {
    ketinggianAir = 3;
  }

  switch (ketinggianAir) {
    case 1:
      digitalWrite(red, HIGH);
      digitalWrite(yllw, LOW);
      digitalWrite(grn, LOW);
      Serial.println("Air dalam tangki tinggi");
      break;
    case 2:
      digitalWrite(red, LOW);
      digitalWrite(yllw, HIGH);
      digitalWrite(grn, LOW);
      Serial.println("Air dalam tangki sedang");
      break;
    case 3:
      digitalWrite(red, LOW);
      digitalWrite(yllw, LOW);
      digitalWrite(grn, HIGH);
      Serial.println("Air dalam tangki rendah");
      break;
    default:
      break;
  }
  Serial.println(" ");
  delay(500);
}
