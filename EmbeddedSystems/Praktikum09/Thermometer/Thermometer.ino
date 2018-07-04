#include <Wire.h>

const uint8_t thermoAddress = 0x48;

const uint8_t cmdReadTemp = 0xAA;
const uint8_t cmdAccessTH = 0xA1;
const uint8_t cmdAccessTL = 0xA2;
const uint8_t cmdConfig = 0xAC;
const uint8_t cmdStartConversion = 0xEE;

const uint8_t polarity = 0x02;
const int8_t highTemp = 27;
const uint8_t notZero = 0b10000000;
const uint8_t zero = 0;
const uint8_t lowTemp = highTemp - 1;

const uint8_t requestByteCount = 2;

int8_t preComma;
int8_t postComma;

void setupThermometer() {
  Wire.setModule(0);

  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdConfig);
  Wire.write(polarity);
  Wire.endTransmission();
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdStartConversion);
  Wire.endTransmission();
  Serial.println("Thermometer initialized");
}

void setupHighTemperature() {
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdAccessTH);
  Wire.write(highTemp);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdAccessTL);
  Wire.write(lowTemp);
  Wire.write(notZero);
  Wire.endTransmission();
  Serial.println("High Temperature set");
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

  Serial.println("Initializing thermometer");
  setupThermometer();
  setupHighTemperature();
}

void loop() {
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdReadTemp);
  Wire.endTransmission();

  Wire.requestFrom(thermoAddress, requestByteCount);
  if (Wire.available()) {
    Serial.println("Reading temperature");
    preComma = Wire.read();
    postComma = Wire.read();
  }

  printTemperature();
}
