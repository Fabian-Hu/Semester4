#include <Energia.h>

#ifndef TIMER
#define TIMER
class Timer {
public:
  static Timer &getTimer();
  void setCallback(void (*onTimeUp)(void));
  void setTimer(int timeSpan);
  void resetTimer();

private:
  Timer();
  Timer(Timer const&);
  void operator=(Timer const&);
  void (*onTimeUp)(void);
  int timeSpan;
  int startMillis;
  uint32_t period;
};
#endif
