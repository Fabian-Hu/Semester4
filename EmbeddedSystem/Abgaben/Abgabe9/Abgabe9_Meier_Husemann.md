# Praktikum 9 (10 Punkte) - Tiva C: I²C

von Tim Steven Meier und Fabian Husemann

## Aufgabe 1

#### a)

| Controlbits | A0   | A1   | A2   | RW-Bit                |
| ----------- | ---- | ---- | ---- | --------------------- |
| 1001        | 0    | 0    | 0    | 1(Read) oder 0(Write) |

Das RW-Bit wird von der Wire-Bibliothek nicht benötigt, sodass wir dort nur mit den ersten 7 Bits arbeiten. Die Slave Adresse wird in vielen Funktionen als Parameter übergeben, zum Beispiel bei begin(), beginTransmission und ein paar weiteren.



#### b)

Die Temperatur besteht aus zwei Byte, von denen maximal 9 Bit benutzt werden. Dabei stehen die ersten 8 Bit für den Zahlenbereich von -127 bis +127, dieser Wert wird allerdings auf -55 bis 125 begrenzt.
Das neunte Bit sind optionale 0.5, damit man die Temperatur genauer angeben kann. Die restlichen 7 Bit werden mit nullen aufgefüllt.

Der Command A1 ermöglicht das zugreifen auf den Schwellenwert des Temperaturoberwerts.

Über den Befehl "write" aus der Wire Bibliothek können wir bei einer bereits bestehenden Verbindung diesen Wert setzen.

| Command(binät/hexadezimal) | Temperatur(binär/hexadezimal) |
| -------------------------- | ----------------------------- |
| 10100001 (A1)              | 00011001 00000000 (1900)      |

Zusammengesetzt sieht der Befehl so aus:

"Wire.write(0xA11900)" 
Vor dem write schreibt man noch "Wire.beginTransmission(address);" und danach "Wire.endTransmission();"

#### c)

Wire.begin();

Wire.requestFrom(1001000, 2);			// Erwartet 2 Byte von der Adresse 1001000
while(Wire.available()) {				// available gibt zurück wie viele Bytes noch
									    gelesen werden müssen
char c = Wire.read();					// erhählt den Byte als char
Serial.print(c);						// gibt den char aus

}