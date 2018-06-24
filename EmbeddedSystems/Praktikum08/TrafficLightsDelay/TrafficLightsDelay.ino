const uint8_t pinTrafficLights = PUSH2;

const uint8_t pinLights[] = { PC_6, PC_7, PD_6, PC_5, PC_4 };

const int tw_time = 4000;
const int tu_time = 1000;
const int tg_time = 2000;

uint8_t vehTrafficLightStates;
uint8_t pedTrafficLightStates;

uint8_t ped;

template <const uint8_t PORT_BTN>
class Button {
public:
  Button() {
    pinMode(PORT_BTN, INPUT);
  }

  unsigned int state() {
    if (digitalRead(PORT_BTN) == LOW) {
      delay(100);
      if (digitalRead(PORT_BTN) == LOW) {
        return HIGH; 
      }
    }
    return LOW;
  }

};

Button<pinTrafficLights> btnTrafficLights;

void updateLights() {
  uint8_t lightStates = pedTrafficLightStates << 3;
  lightStates |= vehTrafficLightStates;

  for (int i = 0; i < sizeof(pinLights); i++) {
    digitalWrite(pinLights[i], lightStates & 1);
    lightStates >>= 1;
  }
}

void setup() {
  for (int i = 0; i < sizeof(pinLights); i++) {
    pinMode(pinLights[i], OUTPUT);
  }

  vehTrafficLightStates = 1;
  pedTrafficLightStates = 1;
  ped = 0;
}

void loop() {
  switch(vehTrafficLightStates) {
    case 0b001:
      if (btnTrafficLights.state()) {
        delay(tw_time);
        vehTrafficLightStates <<= 1;
      }
      break;
    case 0b010:
      delay(tu_time);
        vehTrafficLightStates <<= 1;
      ped = 1;
      break;
    case 0b100:
      if(ped == 0) {
        delay(tu_time);
        vehTrafficLightStates |= 0b010;
      }
      break;
    case 0b110:
      delay(tu_time);
      vehTrafficLightStates >>= 2;
      break;
  }

  updateLights();

  switch(pedTrafficLightStates) {
    case 0b01:
      if(ped) {
        delay(tu_time);
        pedTrafficLightStates <<= 1;
      }
      break;
    case 0b10:
      delay(tg_time);
      pedTrafficLightStates >>= 1;
      ped = 0;
      break;
  }

  updateLights();
}
