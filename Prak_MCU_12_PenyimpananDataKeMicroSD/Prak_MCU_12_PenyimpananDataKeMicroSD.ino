#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
while (!Serial)

Serial.print("\nInitializing Sd car...");
if (!SD.begin(chipSelect)){
  Serial.println("Card failed, or not present");
  while(1);
  }
Serial.println("card initialized.");
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor = analogRead(A0);
File dataFile = SD.open("datalog.txt", FILE_WRITE);

if(dataFile){
  dataFile.println(sensor);
  dataFile.close();
  Serial.println(sensor);
}
else Serial.println("error opening datalog.txt");
}
