volatile int number = 1;
const int waitTime = 1000;
  
void doubler(){
if (number == 128) {
    number = 1;
  } else {
    number = number * 2;
  }
  delay(waitTime);
}
