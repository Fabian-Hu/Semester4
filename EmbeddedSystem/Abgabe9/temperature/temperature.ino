#include <Wire.h>

const int shortDelay = 500;
const int address = 0b1001000;
const int READTEMP = 0xAA;
const int TLCOMMAND = 0xA21800;
const int THCOMMAND = 0xA11800;

void setup() {
  // put your setup code here, to run once:

  Wire.begin(address);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 

  Wire.requestFrom(address, 2);
  //Ausgabe   WAHRSCHEINLICH FALSCH
  while(Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
  }

  //TH setzen ; Im Moment 24°C
  Wire.beginTransmission(address);
  Wire.write(THCOMMAND);
  Wire.endTransmission();

  //TL setzen
  Wire.beginTransmission(address);
  Wire.write(TLCOMMAND);
  Wire.endTransmission();

  delay(shortDelay);
}
