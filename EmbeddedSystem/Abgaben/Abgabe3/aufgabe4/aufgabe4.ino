#define PIN PB_3

//Variablen
int kurz = 200;
int lang = 400;
int sehrlang = 2000;

//Prototypes
void morseS();
void morseO();

void setup() {
    pinMode(PIN,OUTPUT);
}

void loop() {
  morseS();
  morseO();
  morseS();

  digitalWrite(PIN, HIGH);
  delay(sehrlang); 
}

void morseS(){
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(kurz); 
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(kurz); 
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(kurz);
}

void morseO(){
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(lang); 
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(lang); 
  digitalWrite(PIN, HIGH);   // turn the PIN on (HIGH is the voltage level)
  delay(kurz);               // wait for a second
  digitalWrite(PIN, LOW);    // turn the PIN off by making the voltage LOW
  delay(lang); 
}

