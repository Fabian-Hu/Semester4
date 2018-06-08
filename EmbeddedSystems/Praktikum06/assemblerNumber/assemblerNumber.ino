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
    "movs r4, %[num]\n\t"
    "lsl r4, r4, #1\n\t"
    "it eq\n\t"
    "moveq r4, #1\n\t"
    "movs %[num], r4 \n\t"
  : [num] "+r" (number)
  : 
  : "r4", "cc", "memory"
  );

  delay(500);
}
