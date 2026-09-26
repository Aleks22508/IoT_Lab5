#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;
File dataFile;
int position = 0;
const int potPin = A0;
int sensorValue = 0;

void setup() {

  Serial.begin(9600);
  Serial.println("Program started");
  Serial.println("Initializing SD card...");

  if(SD.begin (chipSelect)) {
    Serial.println("SD card found");
  }
  else {
    Serial.println("SD card not found");
  }
  dataFile = SD.open("sensor.csv", FILE_WRITE);
  dataFile.println("Time,Value");
  dataFile.close();
}

void loop() {
  unsigned long Time = millis()/1000;
  Serial.println(position);
  delay(1000);

  sensorValue = analogRead(potPin);

  Serial.print("Value = ");
  Serial.println(sensorValue);

  delay(500);

  dataFile = SD.open("sensor.csv", FILE_WRITE);

  if(dataFile) {
    dataFile.print(" , ");
    dataFile.println(sensorValue);
    dataFile.close();
  }
  else {
    Serial.println("Error");
  }

  delay();

}