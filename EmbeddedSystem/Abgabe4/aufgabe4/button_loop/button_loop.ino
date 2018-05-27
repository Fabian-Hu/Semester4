// Demo illustrating blinking led and reading of button.
// Led is finally turned off when button is pressed.

#include "interrupt.h"
// define port for led output
const uint8_t LedPortOut = RED_LED;
// define pin for button input
const uint8_t ButtonPinIn = PC_4;
// define delay for blinking in ms
const uint32_t Delay = 2000;

const uint32_t INT_GPIOP4 = INT_GPIOP4;
//! LED handling class. Has disable() function for emergency stop.
//! Parameter (in): PORT_NB (output port for connected led)
template <const uint8_t PORT_NB>
class TLed {
  public:
    //! Constructor takes state (HIGH, LOW) only if given.
    //! Defaults: value for state = LOW, and is not disabled.
    TLed(const uint8_t f_ledState = LOW)
      : m_ledState(f_ledState), m_disabled(false) {
      pinMode(PORT_NB, OUTPUT); // led is always output
      digitalWrite(PORT_NB, m_ledState); // set led to default state
    }
    //! If this led is disable, nothing happens, otherwise
    //! toggles state of led (from HIGH to LOW or from LOW to HIGH).
    void toggle() {
      if (m_disabled) // somehow no longer active
        return;
      if (m_ledState == LOW) { // toggle state
        m_ledState = HIGH;
      }
      else {
        m_ledState = LOW;
      }
      digitalWrite(PORT_NB, m_ledState); // set led to current state
    }
    //! Turn led finally off (emergency stop), state is set LOW, functionality off.
    void off() {
      if (m_disabled == false) {
        Serial.println("Not-Aus-Knopf gedrückt");
      }
      m_disabled = true;
      m_ledState = LOW;
      digitalWrite(PORT_NB, m_ledState); // set led to current state

    }
  private:
    uint8_t m_ledState; // current state of led
    bool m_disabled; // disable flag (on if led is finally turned off)
};

//....TODO: INSERT CODE FOR CLASS TBUTTON....
template <const uint8_t PORT_NB>
class TButton {
  public:
    TButton() {
      pinMode(PORT_NB, INPUT);
    }

    bool state() {
      m_buttonState = digitalRead(PORT_NB);
      return m_buttonState;
    }
  private:
    bool m_buttonState;
};

// global instances for led output
TLed<LedPortOut> Led;
// and for button pin
TButton<ButtonPinIn> Button;

void interruptHandler() {
  Led.off();
}

void setup() {
  Serial.begin(9600);
  GPIOIntEnable(GPIO_PORTC_BASE, GPIO_PIN_4);
  GPIOIntRegister(GPIO_PORTC_BASE, interruptHandler);
}

void loop() {
  Led.toggle();
  delay(Delay);
}

