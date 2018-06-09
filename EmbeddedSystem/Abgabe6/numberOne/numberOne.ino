// our working number
volatile uint8_t number0 = 1;
const int waitTime = 1000;

// baudrate for serial communication
const int baudRate = 9600;

// initialize Serial
void setup() {
  Serial.begin(baudRate);
}

// main loop
void loop() {
  // print number
  Serial.println(number0);

  /*if (number == 128) {
    number = 1;
  } else {
    number = number * 2;
  }*/
  
  asm volatile(
    "MOV r3,%0\n\t"
    "CMP r3, #128\n\t"
    "ITE eq\n\t"
    "MOVEQ r3, #1 \n\t"
    "ADDNE r3, r3\n\t"  

      : [value] "r+" (number0)
  );

  delay(waitTime);
   
}
