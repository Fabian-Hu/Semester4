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
#define vierteZeitspanne 4000     //TE
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
  HibernateWakeSet(knopf);
  ownDelay();
 }

class Timer {
  public:
    static Timer& getInstance() {    
      static Timer instance;     
      return instance;
    }
    
    void newISRFunction(void (*ISRFunction)(void)){
      TimerIntRegister(TIMER0_BASE, TIMER_A, ISRFunction);
    }
    
    void setTimer(int zeit) {
      int eintausend = 1000;
      int period = SysCtlClockGet() / eintausend;
      TimerLoadSet(TIMER0_BASE, TIMER_A, zeit * period);
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
    Timer(const Timer& );
    Timer & operator = (const Timer &);
    
};

void ownDelay()
{ 
  Timer::getInstance().newISRFunction(energieSparer);
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
  Timer::getInstance().resetTimer();
  Serial.println(zustand);
  switch(zustand){
    case 6:
    case 0:
      // Ampel grün fußampel rot
      digitalWrite(rotAmpel,LOW);
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(gruenFuss,LOW);
      
      digitalWrite(gruenAmpel,HIGH);
      digitalWrite(rotFuss,HIGH);
      
      // Knopfdruck
      if (zustand == 6) {
        ownDelay();
      }
      
      // ersteZeitspanne
      if(zustand == 0){
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
      zustand = 6;  
      break;     
  }
}

void loop() { 
  if (digitalRead(knopf) == LOW && zustand == 0) {
        zustand = 0;
        Timer::getInstance().resetTimer();
        Timer::getInstance().newISRFunction(states);
        Timer::getInstance().setTimer(vierteZeitspanne);
      }
  }
