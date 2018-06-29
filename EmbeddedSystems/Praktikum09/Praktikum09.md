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

#### 1.2:

