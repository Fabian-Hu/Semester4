// our working data
const uint8_t lastFiboIndex = 13;
uint8_t fibData[lastFiboIndex];
const int waitTime = 1000;

// baudrate for serial communication
const int baudRate = 9600;

void setup() {
  // initialize Serial
  Serial.begin(baudRate);

  // init first two Fibonacci numbers
  fibData[0] = 1;
  fibData[1] = 1;

  asm volatile(

  // TODO: insert program here
  
  );

}

// main loop
void loop() {
  // print data
  for (int i = 0; i < lastFiboIndex; i++)
  {
    Serial.println(fibData[i]);
  }
  // delay 1s
  delay(waitTime);
}
