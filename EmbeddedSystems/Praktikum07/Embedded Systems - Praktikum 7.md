# Embedded Systems - Praktikum 7

## <u>Morsecode</u>

Malte Riechmann, André Kirsch

#### Aufgabe 1

Um die Zustandsmaschine 'beep-test' umzusetzen, haben wir zuerst zwei Klassen für die Buttons und den Buzzer erstellt. Über eine Template Konstante geben wir den Pin an, an den der Aktor bzw. Sensor an das TivaC Board angeschlossen wurde. Über _state()_ können wir bei den Buttons den aktuellen Status abfragen. Der Buzzer lässt sich über _setActive(uint8_t state)_ aktivieren.

```c++
template <const uint8_t PORT_BTN>
class Button {
public:
  Button() {
    pinMode(PORT_BTN, INPUT);
  }

  unsigned int state() {
    if (digitalRead(PORT_BTN)) {
      delay(100);
      if (digitalRead(PORT_BTN)) {
        return HIGH; 
      }
    }
    return LOW;
  }
};

template <const uint8_t PORT_BUZZ>
class Buzzer {
public:
  Buzzer() {
    pinMode(PORT_BUZZ, OUTPUT);
  }

  void setActive(uint8_t state = HIGH) {
    digitalWrite(PORT_BUZZ, state);
  }
};
```

Auch für die States haben wir eine eigene Klasse erstellt. Im Konstruktor können wir eine Methode übergeben, die aufgerufen wird, wenn man den State betritt.

```c++
void activateBuzzer() {
    buzzer.setActive(HIGH);
}

void deactivateBuzzer() {
    buzzer.setActive(LOW);
}

State state00(deactivateBuzzer);
State state01(deactivateBuzzer);
State state10(deactivateBuzzer);
State stateBeep(activateBuzzer);
```

Dies nutzen wir, um Funktionen zum Aktivieren oder Deaktivieren des Buzzers zu übergeben.

Mithilfe der Methode _setStates_ können wir dem State weitere States übergeben, in die bei gewissen Events gewechselt werden soll.

```c++
void setStates(State *states[], int stateNum, int events[]) {
    this->nextStates = states;
    this->stateNum = stateNum;
    this->events = events;
}
```

Als letzte Methode besitzt die Klasse _nextState_. Damit kann dem State ein Event übergeben werden, wodurch ein Wechsel zu einem nächsten State stattfinden soll:

```c++
State *nextState(int event) {
    for (int i = 0; i < stateNum; i++) {
        if (events[i] == event) {
            nextStates[i]->stateChange();
            return nextStates[i];
        }
    }
    return this;
}
```

Dabei gehen wir durch alle Folge-States und schauen, ob diesen das gesucht Event zugeordnet wurde. Falls ja, rufen wir einen _stateChange_ beim nächsten State auf und geben diesen zurück.

In der Funktion _loop_ speichern wir einen statischen Pointer auf den aktuellen State. Desweiteren fragen wir dort ab, ob die Buttons aktiviert wurden und wechseln anhand dessen den State.