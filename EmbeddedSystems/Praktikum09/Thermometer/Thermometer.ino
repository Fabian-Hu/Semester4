#include <Wire.h>

const uint8_t thermoAddress = 0x48;

const uint8_t cmdReadTemp = 0xAA;
const uint8_t cmdAccessTH = 0xA1;
const uint8_t cmdConfig = 0xAC;
const uint8_t cmdStartConversion = 0xEE;

const uint8_t polarity = 0x02;
const uint8_t highTemp = 0x1900;

const uint8_t requestByteCount = 2;

int8_t preComma;
int8_t postComma;

void setupThermometer() {
  Wire.setModule(0);

  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdConfig);
  Wire.write(polarity);
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdStartConversion);
  Wire.endTransmission();
}

void setupHighTemperature() {
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdAccessTH);
  Wire.write(highTemp);
  Wire.endTransmission();
}

void printTemperature() {
  Serial.print(preComma);
  if(postComma) {
    Serial.print(".5");
  }
  Serial.println("");
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  setupThermometer();
  setupHighTemperature();
}

void loop() {
  Wire.begin(thermoAddress);
  Wire.send(0xAA);

  Wire.requestFrom(thermoAddress, requestByteCount);
  if (Wire.available()) {
    preComma = Wire.read();
    postComma = Wire.read();
  }

  printTemperature();
}
