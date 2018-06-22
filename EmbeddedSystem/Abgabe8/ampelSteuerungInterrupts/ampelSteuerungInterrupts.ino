
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/hibernate.h"

#define ersteZeitspanne 1500      //TW
#define zweiteZeitspanne 500      //TU
#define dritteZeitspanne 1000     //TG
#define vierteZeitspanne 2000     //TE
#define gruenFuss PC_4
#define rotFuss PC_5
#define gruenAmpel PC_6
#define gelbAmpel PC_7
#define rotAmpel PD_6
#define knopf PUSH2

void setup() {
  Serial.begin(9600);
  pinMode(gruenFuss, OUTPUT);
  pinMode(rotFuss, OUTPUT);
  pinMode(gruenAmpel, OUTPUT);
  pinMode(gelbAmpel, OUTPUT);
  pinMode(rotAmpel, OUTPUT);
  pinMode(knopf, INPUT);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
  HibernateEnableExpClk(SysCtlClockGet());
  HibernateGPIORetentionEnable();
  HibernateWakeSet(HIBERNATE_WAKE_PIN);
}

class Timer {
  public:
    static Timer getInstance() {    
      static Timer instance;     
      return instance;
    }
    
    void setTimer(int zeit) {
      TimerLoadSet(TIMER0_BASE, TIMER_A, zeit);
      TimerEnable(TIMER0_BASE, TIMER_A);
      IntEnable(INT_TIMER0A);
      TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    }
  
    void resetTimer() {
      TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    }
  private:
    Timer() {  
       SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
       TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);
    }
    
};

void ownDelay()
{
  Timer::getInstance().setISRFunction(energieSparer);
  Timer::getInstance().setTimer(vierteZeitspanne);
}

void energieSparer(){
  digitalWrite(rotAmpel,LOW);
  digitalWrite(gelbAmpel,LOW);
  digitalWrite(gruenFuss,LOW);
  
  digitalWrite(gruenAmpel,LOW);
  digitalWrite(rotFuss,LOW);

  HibernateRequest();
  while (true)
  {
  }
}

int zustand = 0;
void states(){
  Serial.println(zustand);
  switch(zustand){
    case 0:
      // Ampel grün fußampel rot
      digitalWrite(rotAmpel,LOW);
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(gruenFuss,LOW);
      
      digitalWrite(gruenAmpel,HIGH);
      digitalWrite(rotFuss,HIGH);
      ownDelay();
      // Knopfdruck
      if (digitalRead(knopf) == LOW) {
        // ersteZeitspanne
        Timer::getInstance().setTimer(ersteZeitspanne);
        zustand = 1;
      }
      
      break;
    case 1:
      // ampel gelb
      digitalWrite(gruenAmpel,LOW);
      digitalWrite(gelbAmpel,HIGH);
       
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 2;
      break;
    case 2:
      // ampel rot
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(rotAmpel,HIGH);
      
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 3;
      break;
    case 3:
      // fußampel grün
      digitalWrite(rotFuss,LOW);
      digitalWrite(gruenFuss,HIGH);
       
      // dritteZeitspanne
      Timer::getInstance().setTimer(dritteZeitspanne);
      zustand = 4;
      break;
    case 4:
      //fußampel rot
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotFuss,HIGH);
       
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 5;
      break;
    case 5:
      //ampel rot-gelb
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotAmpel,HIGH);
      digitalWrite(gelbAmpel,HIGH);
      
      //zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);  
      zustand = 0;  
      break;     
  }
}


void loop() { 
    Timer::getInstance().resetTimer();
    Timer::getInstance().setISRFunction(states);
  }
