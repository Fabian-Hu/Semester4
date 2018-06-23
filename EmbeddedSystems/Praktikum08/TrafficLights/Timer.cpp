#include "Timer.h"
#include "tm4c123gh6pm.h"
#include "hw_memmap.h"
#include "hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"

Timer::Timer() {
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
  TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);
  IntMasterEnable();

  period = SysCtlClockGet() / 2;
}

Timer &Timer::getTimer() {
  static Timer timer;
  return timer;
}

void Timer::setCallback(void (*onTimeUp)(void)) {
  this->onTimeUp = onTimeUp;
  TimerDisable(TIMER0_BASE, TIMER_BOTH);
  TimerIntDisable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  TimerIntRegister(TIMER0_BASE, TIMER_BOTH, onTimeUp);
  IntEnable(INT_TIMER0A);
  TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  TimerEnable(TIMER0_BASE, TIMER_BOTH);
}

void Timer::setTimer(int timeSpan) {
  this->timeSpan = timeSpan;
  resetTimer();
}

void Timer::resetTimer() {
  TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
  TimerDisable(TIMER0_BASE, TIMER_BOTH);
  TimerLoadSet(TIMER0_BASE, TIMER_BOTH, period * timeSpan);
  TimerEnable(TIMER0_BASE, TIMER_BOTH);
}

