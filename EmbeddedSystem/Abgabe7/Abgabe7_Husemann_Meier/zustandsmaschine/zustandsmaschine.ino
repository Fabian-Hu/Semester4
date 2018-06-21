
#include "pitches.h" 
const uint8_t schalterB = PC_4;
const uint8_t schalterD = PC_5;
const uint8_t Buzzer = PC_6;

// baudrate for serial communication
const int baudRate = 9600;

int noteDuration = 2;
int zustand=1;

void setup() {
  Serial.begin(baudRate);
  pinMode(schalterB,INPUT);
  pinMode(schalterD,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  switch(zustand){
    case 1:         //00
      if (digitalRead(schalterB) == HIGH) {
        zustand = 3;
      } else if (digitalRead(schalterD) == HIGH) {
        zustand = 2;
      } 
      Serial.println(zustand);
      break;
    case 2:         //01
      if (digitalRead(schalterB) == HIGH) {
        zustand = 4;
      } else if (digitalRead(schalterD) == LOW) {
        zustand = 1;
      } 
      Serial.println(zustand);
      break;
    case 3:         //10
      if (digitalRead(schalterD) == HIGH) {
        zustand = 4;
      } else if (digitalRead(schalterB) == LOW) {
        zustand = 1;
      } 
      Serial.println(zustand);
      break;
    case 4:         //beep

      tone(Buzzer,NOTE_D8,noteDuration);
      noTone(Buzzer); 
      if (digitalRead(schalterD) == LOW) {
        zustand = 1;
      } else if (digitalRead(schalterB) == LOW) {
        zustand = 1;
      } 
      Serial.println(zustand);
      
      break;  
    default:
      Serial.println("Error");
  }
}
