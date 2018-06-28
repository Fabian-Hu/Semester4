
#define ersteZeitspanne 500
#define zweiteZeitspanne 2000
#define dritteZeitspanne 1000
#define gruenFuss PC_4
#define rotFuss PC_5
#define gruenAmpel PC_6
#define gelbAmpel PC_7
#define rotAmpel PD_6
#define knopf PUSH2

void setup() {
  Serial.begin(9600);
  pinMode(gruenFuss, OUTPUT);
  pinMode(rotFuss, OUTPUT);
  pinMode(gruenAmpel, OUTPUT);
  pinMode(gelbAmpel, OUTPUT);
  pinMode(rotAmpel, OUTPUT);
  pinMode(knopf, INPUT);
}

int zustand = 0;
void loop() { 
  Serial.println(zustand);
  switch(zustand){
    case 0:
      // Ampel grün fußampel rot
      digitalWrite(rotAmpel,LOW);
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(gruenFuss,LOW);
      
      digitalWrite(gruenAmpel,HIGH);
      digitalWrite(rotFuss,HIGH);
      
      // Knopfdruck
      //Serial.println(digitalRead(knopf));
      if (digitalRead(knopf) == LOW) {
        // ersteZeitspanne
        delay(ersteZeitspanne);
        zustand = 1;
      }
      
      break;
    case 1:
      // ampel gelb
      digitalWrite(gruenAmpel,LOW);
      digitalWrite(gelbAmpel,HIGH);
       
      // zweiteZeitspanne
      delay(zweiteZeitspanne);
      zustand = 2;
      break;
    case 2:
      // ampel rot
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(rotAmpel,HIGH);
      
      // zweiteZeitspanne
      delay(zweiteZeitspanne);
      zustand = 3;
      break;
    case 3:
      // fußampel grün
      digitalWrite(rotFuss,LOW);
      digitalWrite(gruenFuss,HIGH);
       
      // dritteZeitspanne
      delay(dritteZeitspanne);
      zustand = 4;
      break;
    case 4:
      //fußampel rot
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotFuss,HIGH);
       
      // zweiteZeitspanne
      delay(zweiteZeitspanne);
      zustand = 5;
      break;
    case 5:
      //ampel rot-gelb
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotAmpel,HIGH);
      digitalWrite(gelbAmpel,HIGH);
      
      //zweiteZeitspanne
      delay(zweiteZeitspanne);  
      zustand = 0;  
      break;     
  }
  
}
