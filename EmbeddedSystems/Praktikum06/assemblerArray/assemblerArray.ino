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
    "movs r4, %[fibo]\n\t"
    "movs r7, %[index]\n"
    "subs r7, #2\n\t"
    "fibonacci:\n\t"
    "ldr r5, [r4, #0]\n\t"
    "ldr r6, [r4, #1]\n\t"
    "add r5, r6\n\t"
    "str r5, [r4, #2]\n\t"
    "add r4, #1\n\t"
    "subs r7, #1\n\t"
    "bne fibonacci"
    : 
    : [index] "r" (lastFiboIndex), [fibo] "r" (fibData)
    : "r4", "r5", "r6", "r7", "cc", "memory"
  );
}

// main loop
void loop() {
  
  // print data
  for (int i = 0; i < lastFiboIndex; i++) {
    Serial.println(fibData[i]);
  }
  
  // delay 1s
  delay(waitTime);
}
