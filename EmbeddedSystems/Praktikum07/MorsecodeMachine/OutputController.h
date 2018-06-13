#include "Morse.h"

const char longSignal = '-';
const char shortSignal = '.';

const uint16_t shortDelay = 200;
const uint16_t longDelay = 3 * shortDelay;
const uint16_t pauseBetweenChars = shortDelay;
const uint16_t pauseBetweenWords = 7 * shortDelay;

class Actor {
public:
  Actor(uint8_t pin) : pin(pin) {
    pinMode(pin, OUTPUT);
  }

  void setActive(uint8_t state = HIGH) {
    digitalWrite(pin, state);
  }

private:
  uint8_t pin;
};

class AbstractController {
public:
  virtual void morseString(String &output) {
    for (int i = 0; i < output.length(); i++) {
      if (output[i] == ' ') {
        delay(pauseBetweenWords);
      } else {
        char c = output[i];
        if (islower(c)) {
          c += ('A' - 'a');
        }
        const char *morse = CHAR_TO_MORSE[c];
        Serial.println(morse);
        for (int j = 0; j < strlen(morse); j++) {
          if (morse[j] == longSignal) {
            morseLong();
          } else if (morse[j] == shortSignal) {
            morseShort();
          }
          delay(pauseBetweenChars);
        }
      }
    }
  }
  
  virtual void morseShort() = 0;
  virtual void morseLong() = 0;
};

class PinController : public AbstractController {
public:
  PinController(Actor &actor) : actor(actor) { }
  void setActor(Actor &actor) {
    this->actor = actor;
  }
  void morseShort() {
    actor.setActive(HIGH);
    delay(shortDelay);
    actor.setActive(LOW);
  }
  void morseLong() {
    actor.setActive(HIGH);
    delay(longDelay);
    actor.setActive(LOW);
  }

private:
  Actor &actor;
};

