# Embedded Systems - Praktikum 9

Malte Riechmann, André Kirsch

### Aufgabe 1:

#### 1.1:

Die Adresse des DS1621 lautet 10010000 bzw. 10010001. Die Adresse setzt sich aus den folgenden Bestandteilen zusammen:

| Name               | Bits | Beschreibung                                                 |
| ------------------ | ---- | ------------------------------------------------------------ |
| 4-bit Control code | 1001 | Festgelegte Bitabfolge zum Ansprechen des DS1621             |
| Device select bits | 000  | Geben an, welches von acht Geräten vom Master genutzt werden. Da in unserem Fall die Pins A0, A1 und A2 nicht angeschlossen sind, sind sie alle 0 **(nochmal prüfen!!!)** |
| Read/Write Bit     | 1/0  | Gibt an, ob geschrieben oder gelesen werden soll.            |

Für die Wire Bibliothek werden die Bits durch einen *bit shift* um eins nach rechts verschoben. Die Wire Bibliothek setzt das Read/Write Bit automatisch anhand der aufgerufenen Methode *read* oder *write*.

Der *beginTransmission* Funktion der Wire Bibliothek beginnt eine Übertragung. Dieser wird die Adresse des Thermometers übergeben. Eine Übertragung kann mit *endTransmission* wieder beendet werden.

Zum Empfangen von Daten kann auch der *requestFrom* Funktion die Adresse des Thermometers übergeben werden.

#### 1.2:

Für die Temperaturwerte werden 2 Byte verwendet. Das erste Byte gibt die Temperatur als Ganzzahl an. Erlaubte Werte gehen von -55°C bis +125°C. Vom zweiten Byte wird nur das erste Bit verwendet, welches einen halben Grad Schritt angibt. Die restlichen 7 Bits werden nicht verwendet und sind daher immer 0.

Beispiele:

| Temperatur | Binär Wert        |
| ---------- | ----------------- |
| +125°C     | 01111101 00000000 |
| +0°C       | 00000000 00000000 |
| -1/2°C     | 11111111 10000000 |
| -55°C      | 11001001 00000000 |



Um den Tout Pin ab 25°C anschalten zu lassen, muss das *Access TH* Kommando an den DS1621 gesendet werden. Anschließend wird der Wert (25,0), ab dem der Pin angeschaltet werden soll, gesendet. Dieser Wert wird im vorher erklärten Format dargestellt.

So würde das Kommando aussehen:

| Hexadezimal | Binär                      |
| ----------- | -------------------------- |
| A1 19 00    | 10100001 00011001 00000000 |

Mit der Wire Bibliothek wurde es dann folgendermaßen aussehen:

```c++
Wire.begin();
Wire.beginTransmission(0x48);
Wire.send(0xA11900);
Wire.endTransmission();
```

Zuerst initialisieren wir die Wire Bibliothek. Danach starten wir eine Übertragung. Dabei geben die Adresse des Thermometers im 7 Bit Format mit an. Als nächstes Senden wir die Daten, die wir senden möchten und beenden unsere Übertragung.

#### 1.3:

Zum Abfragen der aktuellen Temperatur wird mit dem *Read Temperature* Kommando abgefragt. Dazu wird dieses Kommando gesendet und direkt danach kann das 2 Byte lange Ergebnis gelesen werden.

```c++
int8_t preComma;
int8_t postComma;

Wire.begin();
Wire.beginTransmission(0x48);
Wire.send(0xAA); 
Wire.endTransmission();

Wire.requestFrom(0x48, 2);
if (Wire.available()) {
    preComma = Wire.read();
    postComma = Wire.read();
}
```

Dazu initialisieren wir zuerst wieder die Wire Bibliothek und senden danach in einer Übertragung das Kommando *0xAA* für das Lesen der Temperatur. Danach fordern wir eine 2 Byte lange Antwort vom DS1621 an und lesen diese dann ein.