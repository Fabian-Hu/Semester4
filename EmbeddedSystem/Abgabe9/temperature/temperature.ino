#include <Wire.h>

const int shortDelay = 500;
const int address = 0x48;
const int READTEMP = 0xAA;
const int TLCOMMAND = 0xA2;
const int THCOMMAND = 0xA1;
const int AccessConfig = 0xAC;
const int COMMAND = 0x1800;
const int POLARITY = 0x02;
const int START = 0xEE;
const int TEMP = 29;
const int NIX = 0x00;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.setModule(0);
  Serial.begin(9600);
  
  //TH setzen ; Im Moment 24°C
  Wire.beginTransmission(address);
  Wire.write(AccessConfig);
  Wire.write(POLARITY);
  Wire.endTransmission();
  Wire.beginTransmission(address);
  Wire.write(START);
  Wire.endTransmission();
  
  Wire.beginTransmission(address);
  Wire.write(THCOMMAND); 
  Wire.write(TEMP);
  Wire.write(NIX);  
  Wire.endTransmission();
  Wire.beginTransmission(address);
  Wire.write(TLCOMMAND); 
  Wire.write(TEMP);
  Wire.write(NIX);
  Wire.endTransmission();

  Wire.beginTransmission(address);
  Wire.write(START);
  Wire.endTransmission();
  
}

void loop() {
  // put your main code here, to run repeatedly: 

  Wire.beginTransmission(address);
  Wire.write(READTEMP);
  Wire.endTransmission();
  
  Wire.requestFrom(address, 2);
  //Ausgabe   WAHRSCHEINLICH FALSCH
  while(Wire.available()) {
    int c = Wire.read();
    int d = Wire.read();
    Serial.print(c);
    Serial.print(".");
    if(d != 0)
      Serial.println("5");
    else
      Serial.println("0");
  }


  delay(shortDelay);
}
