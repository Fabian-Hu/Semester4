#Embedded Systems: Aufgabenblatt 1

## Praktikum 1 (10 Punkte) - Fragen zu eingebetteten Systemen

### Beispiel Casio fx-82ES

### Aufgabe 1

- Beschreiben Sie, wie sich die angesprochenen Merkmale auf Ihre Beispiele übertragen
  lassen?

  - Software 
    - Berechnen der eingegeben Daten
  - Hardware 
    - Microcontroller zum ausführen der Software
    - Batterie für Strom
    - Solarzelle für Strom
  - Sensor
    - Tastatur für Zahlen, Rechenoperationen und Zusatzoperationen
  - Aktor
    - Display zum ausgeben der Informationen

- Gehen Sie den gewählten Beispielen auf den Grund. Beschreiben Sie, auf welcher
  Hardware (Mikrocontroller, Speicher, Sensoren, Aktoren, Kommunikationselemente etc.)
  und Software (Betriebssystem) die Systeme basieren. Wenn es nicht möglich ist herauszufinden, welches Bauteil genau verwendet wurde, machen Sie einen Vorschlag für ein konkretes Bauteil. Für den Vorschlag soll ein Datenblatt vorliegen.

  Der Mikrocontroller besitzt einen Datenbus über dem er Daten bekommt, sie zur CPU weiterleitet und wieder 							ausgibt.

  Strom erhält der Taschenrechner über die Solarzelle, bis das Lichtlevel zu niedrig ist. Dann unterstützt die Batterie.

  Angezeigt werden die Ein und Ausgaben auf dem Display.

  Mit den vielen Tasten kann man den Taschenrechner bedienen.

   -  Mikrocontoller: ML610901 ist ein 8bit-Mikrocontroller mit integriertem LCD-Treiber für 96 x 32

      Segmente mit 8bitCPU Kern, 3584 Bytes RAM und 96k ROM.

   -  Batterie: Panasonic Knopfzelle Silberoxid SR44

   -  Solarzelle: sanyo sa3515s4

   -  Display: 96 x 32 Segment LCD Display

  ​

- Überlegen Sie, warum die Entwickler/innen die Systeme so konstruiert und nicht anders
  entworfen haben.

  - Einfacher Aufbau für ein einfaches System
  - der integrierte LCD Treiber des Mikrocontrollers hält es noch kleiner
  - Der Display ist groß genug für komplexe Ein und Ausgaben, aber nicht so groß, dass das Modell vergrößert wird
  - Durch die Solarzelle hat man bei Licht unbegrenzte Laufzeit, bei Dunkelheit hilft die Batterie aus, auch wenn man bei Dunkelheit den Display nicht lesen kann.



### Aufgabe 2

- Beschreiben Sie die Anforderungen im Detail, die an die Beispiele der eingebetteten
  Systeme gestellt werden.
- Stellen Sie weiterhin dar, welche Auswirkungen das Nichteinhalten der Anforderungen
  haben kann.


-  Verlässlichkeit
  - Zuverlässigkeit: Der Taschenrechner soll zuverlässig Rechnungen berechnen
  - Wartbarkeit: Die Batterie sollte einfach auszuwechseln sein
  - Verfügbarkeit: Dank der Batterie kann der Taschenrechner auch im Dunkeln rechnen
  - Sicherheit: wenn das Gerät ausfällt muss man sich zwangsläufig Ersatz kaufen
  - Integrität: Datenklau ist bei einem Taschenrechner kein Problem
-  Effizienz
     - Energieverbrauch: Dank Solarzelle hält der Taschenrechner ewig
     - Codegröße: klein
     - Laufzeit: sehr variable Laufzeitlänge, von sehr kurzer Laufzeit bei einfachen Operationen, bis hin zu mehreren Sekunden Laufzeit bei sehr komplizierten Formeln
     - Gewicht: Dank kleiner Größe einfach zu tragen
     - Preis: <20
-  Einzwecksystem: Der Mikrokontoller kümmert sich um das Berechnen der Daten
-  transformatives System: Es kommt Eingabe, der Rechner berechnet sie und gibt sie danach aus
-  harte Zeitbedingungen: Ungewöhnliche Verzögerungen sind fast immer ein Fehler