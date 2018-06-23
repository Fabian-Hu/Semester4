#include "Timer.h"
#include "driverlib/hibernate.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"

const uint8_t pinTrafficLights = PUSH2;

const uint8_t pinLights[] = { PC_6, PC_7, PD_6, PC_5, PC_4 };

const int tw_time = 8;
const int tu_time = 2;
const int tg_time = 4;
const int te_time = 16;

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
Timer &timer = Timer::getTimer();

void updateLights() {
  uint8_t lightStates = pedTrafficLightStates << 3;
  lightStates |= vehTrafficLightStates;

  for (int i = 0; i < sizeof(pinLights); i++) {
    digitalWrite(pinLights[i], lightStates & 1);
    lightStates >>= 1;
  }
}

void onNextVehLightState() {
  switch(vehTrafficLightStates) {
    case 0b001:
      vehTrafficLightStates <<= 1;
      timer.setTimer(tu_time);
      break;
    case 0b010:
      vehTrafficLightStates <<= 1;
      ped = 1;
      timer.setCallback(onNextPedLightState);
      timer.resetTimer();
      break;
    case 0b100:
      if(ped == 0) {
        vehTrafficLightStates |= 0b010;
        timer.resetTimer();
      }
      break;
    case 0b110:
      vehTrafficLightStates >>= 2;
      timer.setCallback(onSleep);
      timer.setTimer(te_time);
      break;
  }
}

void onNextPedLightState() {
  switch(pedTrafficLightStates) {
    case 0b01:
      if(ped) {
        pedTrafficLightStates <<= 1;
        timer.setTimer(tg_time);
      }
      break;
    case 0b10:
      pedTrafficLightStates >>= 1;
      ped = 0;
      timer.setCallback(onNextVehLightState);
      timer.setTimer(tu_time);
      break;
  }
}

void onSleep() {
  for (int i = 0; i < sizeof(pinLights); i++) {
    digitalWrite(pinLights[i], LOW);
  }
  
  HibernateRequest();
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < sizeof(pinLights); i++) {
    pinMode(pinLights[i], OUTPUT);
  }
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
  HibernateEnableExpClk(SysCtlClockGet());
  HibernateGPIORetentionEnable();
  HibernateWakeSet(pinTrafficLights);

  vehTrafficLightStates = 1;
  pedTrafficLightStates = 1;
  ped = 0;
  updateLights();
  
  timer.setCallback(onSleep);
  timer.setTimer(te_time);
}

void loop() {
  if (btnTrafficLights.state() && vehTrafficLightStates == 1) {
    timer.setCallback(onNextVehLightState);
    timer.setTimer(tw_time);
  }
  
  updateLights();
}
