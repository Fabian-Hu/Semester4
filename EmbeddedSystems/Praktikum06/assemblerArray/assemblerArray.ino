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
    "movs r0, %[fibo]\n\t"
    "movs r3, %[index]\n"
    "subs r3, #1\n\t"
    "subs r3, #1\n\t"
    "fibonacci:\n\t"
    "ldr r1, [r0, #0]\n\t"
    "ldr r2, [r0, #1]\n\t"
    "add r1, r2\n\t"
    "str r1, [r0, #2]\n\t"
    "add r0, #1\n\t"
    "subs r3, #1\n\t"
    "bpl fibonacci"
    : 
    : [index] "r" (lastFiboIndex), [fibo] "r" (fibData)
    : "r0", "r1", "r2", "r3", "cc", "memory"
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
