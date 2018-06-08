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
    "ldr r8, %[fibDataInput]\n"
    "fibonacci:\n\t"
    "ldr r9, [r8, #0]\n\t"
    "ldr r10, [r8, #1]\n\t"
    "add r9, r10\n\t"
    "str r9, [r8, #2]\n\t"
    "add r8, #1\n\t"
    "cmp r9, #233\n\t"
    "bpl fibonacci"
    : [fibDataOutput] "=r" (fibData)
    : [fibDataInput] "r" (fibData)
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
