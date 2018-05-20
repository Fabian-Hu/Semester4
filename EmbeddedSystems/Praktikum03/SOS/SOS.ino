#define LED PB_3

const int longDelay = 1000;
const int shortDelay = 500;
const int delayBetweenSignal = 500;
const int delayBetweenChars = 1000;
const int delayBetweenWords = 2000;

void sendSignal(const int delay) {
  digitalWrite(LED, HIGH);
  delay(delay);
  digitalWrite(LED, LOW);
  delay(delayBetweenSignal);
}

void sendO() {
  for (int i = 0; i < 3; i++) {
    sendSignal(longDelay);
  }
  delay(delayBetweenChars);
}

void sendS() {
  for (int i = 0; i < 3; i++) {
    sendSignal(shortDelay);
  }
  delay(delayBetweenChars);
}

void sendSOS() {
  sendS();
  sendO();
  sendS();
  delay(delayBetweenWords);
}

void setup() {                
  pinMode(LED, OUTPUT);     
}

void loop() {
  sendSOS();
}
