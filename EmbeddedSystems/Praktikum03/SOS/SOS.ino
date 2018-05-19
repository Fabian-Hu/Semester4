#define LED PB_3

const int longDelay = 1000;
const int shortDelay = 500;
const int delayBetweenSignal = 500;
const int delayBetweenChars = 1000;
const int delayBetweenWords = 2000;

void sendLong() {
  digitalWrite(LED, HIGH);
  delay(longDelay);
  digitalWrite(LED, LOW);
  delay(delayBetweenSignal);
}

void sendShort() {
  digitalWrite(LED, HIGH);
  delay(shortDelay);
  digitalWrite(LED, LOW);
  delay(delayBetweenSignal);
}

void sendO() {
  for (int i = 0; i < 3; i++) {
    sendLong();
  }
  delay(delayBetweenChars);
}

void sendS() {
  for (int i = 0; i < 3; i++) {
    sendShort();
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
