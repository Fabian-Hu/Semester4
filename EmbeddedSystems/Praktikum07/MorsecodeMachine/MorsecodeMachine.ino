#include "OutputController.h"

const uint8_t btnPinB = PC_4;
const uint8_t btnPinD = PC_5;
const uint8_t buzzerPin = PC_6;
const uint8_t ledPin = RED_LED;

const uint8_t strLength = 128;

template <const uint8_t PORT_BTN>
class Button {
public:
  Button() {
    pinMode(PORT_BTN, INPUT);
  }

  unsigned int state() {
    if (digitalRead(PORT_BTN)) {
      delay(100);
      if (digitalRead(PORT_BTN)) {
        return HIGH; 
      }
    }
    return LOW;
  }

};

Button<btnPinB> buttonB;
Button<btnPinD> buttonD;
Actor buzzer(buzzerPin);
Actor led(ledPin);

uint8_t currentActor = 0;

PinController output(buzzer);

String input = "";
long lastCharTime = 0.0f;
const int maxCharWaitTime = 10;
String parsedInput = input;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  input.reserve(strLength);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonB.state() == HIGH) {
    if (currentActor == 0) {
      output.setActor(led);
      currentActor++;
    } else {
      output.setActor(buzzer);
      currentActor = 0;
    }
  }

  if (buttonD.state() == HIGH) {
    output.morseString(parsedInput);
  }
  
  if (input.length() > 0 && millis() - lastCharTime > maxCharWaitTime) {
    parsedInput = input;
    input = "";
  }
}

void serialEvent() {
  if (Serial.available()) {
    char inChar = (char)Serial.read();
    if (input.length() < strLength) {
      input += inChar;
    }
    lastCharTime = millis();
  }
}

