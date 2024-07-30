void setup() {
  Serial.begin(9600);
  for (int arr = 1; arr <= 20; arr += 2) {
    Serial.println(arr);
  }
}

void loop() {
}
