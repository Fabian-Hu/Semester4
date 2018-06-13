const uint8_t btnPinB = PC_4;
const uint8_t btnPinD = PC_5;
const uint8_t buzzerPin = PC_6;

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

class State {
public:
  State(void (*stateChange)()) : stateChange(stateChange){}
  State(State **states, int stateNum, int *events) : nextStates(states), stateNum(stateNum), events(events) {}

  void setStates(State *states[], int stateNum, int events[]) {
    this->nextStates = states;
    this->stateNum = stateNum;
    this->events = events;
  }

  State *nextState(int event) {
    for (int i = 0; i < stateNum; i++) {
      if (events[i] == event) {
        nextStates[i]->stateChange();
        return nextStates[i];
      }
    }
    return this;
  }

private:
  State **nextStates;
  int stateNum;
  int *events;
  void (*stateChange)();
};

template <const uint8_t PORT_BUZZ>
class Buzzer {
public:
  Buzzer() {
    pinMode(PORT_BUZZ, OUTPUT);
  }

  void setActive(uint8_t state = HIGH) {
    digitalWrite(PORT_BUZZ, state);
  }
};

Buzzer<buzzerPin> buzzer;

void activateBuzzer() {
  buzzer.setActive(HIGH);
}

void deactivateBuzzer() {
  buzzer.setActive(LOW);
}

const int eventd = 0;
const int event_d = 1;
const int eventb = 2;
const int event_b = 3;

Button<btnPinB> buttonB;
Button<btnPinD> buttonD;

State state00(deactivateBuzzer);
State state01(deactivateBuzzer);
State state10(deactivateBuzzer);
State stateBeep(activateBuzzer);

State *states[] = {&state01, &state10};
int events[] = {eventd, eventb};
State *states1[] = {&state00, &stateBeep};
int events1[] = {event_d, eventb};
State *states2[] = {&state00, &stateBeep};
int events2[] = {event_b, eventd};
State *states3[] = {&state01, &state10};
int events3[] = {event_b, event_d};

void setup() {
  Serial.begin(9600);
  state00.setStates(states, 2, events);
  state01.setStates(states1, 2, events1);
  state10.setStates(states2, 2, events2);
  stateBeep.setStates(states3, 2, events3);
}

void loop() {
  static State *current = &state00;
  current = (buttonB.state()) ? current->nextState(eventb) : current->nextState(event_b);
  current = (buttonD.state()) ? current->nextState(eventd) : current->nextState(event_d);
}
