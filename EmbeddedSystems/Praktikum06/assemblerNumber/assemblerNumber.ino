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
    "movs r1, %[num]\n\t"
    "lsl r1, r1, #1\n\t"
    "cmp r1, #256\n\t"
    "it eq\n\t"
    "moveq r1, #1\n\t"
    "movs %[num], r1 \n\t"
  : [num] "+r" (number)
  : 
  : "r1", "cc" 
  );

  delay(500);
}
