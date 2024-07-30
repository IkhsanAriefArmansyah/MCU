float operand1, operand2, result;
char operatorChar;

void setup() {
  Serial.begin(9600);
  Serial.println("Kalkulator sederhana");
  Serial.println("Masukkan operasi matematika (contoh: 5 + 3): ");
}

void loop() {
  if (Serial.available() > 0) {
    String inputString = Serial.readStringUntil('\n');

    int spaceIndex = inputString.indexOf(' ');
    if (spaceIndex != -1) {
      operand1 = inputString.substring(0, spaceIndex).toFloat();
      inputString = inputString.substring(spaceIndex + 1);

      spaceIndex = inputString.indexOf(' ');
      if (spaceIndex != -1) {
        operatorChar = inputString.charAt(spaceIndex + 1);
        operand2 = inputString.substring(spaceIndex + 3).toFloat();

        switch (operatorChar) {
          case '+':
            result = operand1 + operand2;
            break;
          case '-':
            result = operand1 - operand2;
            break;
          case '*':
            result = operand1 * operand2;
            break;
          case '/':
            if (operand2 != 0) {
              result = operand1 / operand2;
            } else {
              Serial.println("Error: Pembagian oleh nol");
              result = 0;
              break;
            }
        Serial.print("Hasil: ");
        Serial.println(result);
        }
      }else {
        Serial.println("Error: Format input tidak valid");
      }
    } else {
      Serial.println("Error: Format input tidak valid");
    }
  }
}