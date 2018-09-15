
#include "pitches.h" 
#define LED RED_LED

const uint8_t schalterB = PC_4;
const uint8_t schalterD = PC_5;
const uint8_t BuzzerPin = PC_6;
String inputString = ""; // a string to hold incoming data
boolean stringComplete = false; // whether the string is complete
boolean buzzersTurn = true;

// baudrate for serial communication
const int baudRate = 9600;
const int maxLength = 128;

const int kurz = 200;
const int lang = kurz * 3;
const int pauseZwischenSymbol = kurz;
const int pauseZwischenBuchstabe = lang;
const int pauseZwischenWort = kurz * 7;

// define delay for blinking in ms
const uint32_t Delay = 500;

const int morse_size = 39;
const String morse[morse_size] =
{
    ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---",
    "-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-",
    "..-","...-",".--","-..-","-.--","--..","-----",".----",
    "..---","...--","....-",".....","-....","--...","---..","----."
};

String toMorse(char c) {
  return morse[tolower(c) - 'a'];
}

class Wandler {
public:
    Wandler() {
    }
    void textToMorseCode(String input){
      for (int i = 0; i < input.length()-2; i++) {
          if (input[i] == ' ') {
            delay(pauseZwischenWort);
          } else {
            String code = toMorse(input[i]);
            output(code);
            delay(pauseZwischenBuchstabe);
          }
      }
    }
    void output(String code) {
      for (char c : code) {
        if (c == '.') {
          kurzesSymbol();
        } else if (c == '-') {
          langesSymbol();
        }
      }
    }
    virtual void kurzesSymbol() {
      
    }
    virtual void langesSymbol() {
      
    }
};

class Led : public Wandler {
public:
    Led() {
    }
    void kurzesSymbol() {
      digitalWrite(LED, HIGH);
      delay(kurz);
      digitalWrite(LED, LOW);
      delay(pauseZwischenSymbol);
    }
    void langesSymbol() {
      digitalWrite(LED, HIGH);
      delay(lang);
      digitalWrite(LED, LOW);
      delay(pauseZwischenSymbol);
    }
};

class Buzzer : public Wandler {
public:
    Buzzer() {
    }
    void kurzesSymbol() {
      tone(BuzzerPin,NOTE_D4,kurz);
      delay(kurz);
      noTone(BuzzerPin);
      delay(pauseZwischenSymbol);
    }
    void langesSymbol() {
      tone(BuzzerPin,NOTE_D4,lang);
      delay(lang);
      noTone(BuzzerPin);
      delay(pauseZwischenSymbol);
    }
};

  Led led;
  Buzzer buzzer;
  
void setup() {
  Serial.begin(baudRate);
  pinMode(schalterB,INPUT);
  pinMode(schalterD,INPUT);
  pinMode(LED, OUTPUT);   
  
  // reserve 128 bytes for the inputString:
  inputString.reserve(maxLength);

}

void loop() {
  if (digitalRead(schalterB) == HIGH) {
    if (buzzersTurn == true) {
      buzzersTurn = false;
      Serial.println("LED:");
    } else {
      buzzersTurn = true;
      Serial.println("Buzzer:");
    }
    delay(Delay);
  }
  
  if (stringComplete && (digitalRead(schalterD) == HIGH)) {
    String inputCopy = inputString;
    if (buzzersTurn == true) {
      buzzer.textToMorseCode(inputCopy);
    } else {
      led.textToMorseCode(inputCopy);
    }
   
    inputString = "";
    stringComplete = false;
    delay(Delay * 4);
  }
}

void serialEvent() {
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read(); 
    // add it to the inputString:
    
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    } 
  }
}
