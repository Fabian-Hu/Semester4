// our working number
volatile uint8_t number = 1;

// baudrate for serial communication
const int baudRate = 9600;

// initialize Serial
void setup() {
  Serial.begin(baudRate);
}

// main loop
void loop() {
  
  // print number
  Serial.println(number);
  
  asm volatile(
    "ldr r0, =number\n\t"
    "ldr r1, [r0, #0]\n\t"
    "lsl r1, r1, #1\n\t"
    "cmp r1, #256\n\t"
    "it eq\n\t"
    "moveq r1, #1\n\t"
    "str r1, [r0, #0]\n\t"
  
  );
}
