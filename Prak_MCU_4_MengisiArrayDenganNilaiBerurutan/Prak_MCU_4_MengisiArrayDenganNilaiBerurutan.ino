const int arraySize = 5;
int data[arraySize];

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < arraySize; i++) {
    data[i] = i * 10;
  }

  Serial.println("Data dalam array:");
  for (int i = 0; i < arraySize; i++) {
    Serial.println(data[i]);
  }
}

void loop() {
}
