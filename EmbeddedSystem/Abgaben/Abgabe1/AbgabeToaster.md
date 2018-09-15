#Embedded Systems: Aufgabenblatt 1

## Praktikum 1 (10 Punkte) - Fragen zu eingebetteten Systemen

###Beispiel Toaster Oven Control System

### Aufgabe 1

- Beschreiben Sie, wie sich die angesprochenen Merkmale auf Ihre Beispiele übertragen
  lassen?

  * Software
    * Kontrolliert die Temperatur und den Timer im Toaster
  * Hardware
    * Microcontroller zum steuern dern Komponenten
    * Temperatur Sensor zum messen der Temperatur
  * Sensor
    * Ein Knopf für Start und Stop
    * Zwei Drehknöpfe für die Hitze und den Timer
  * Aktor
    * Statusindikator(LED, Lautsprecher) zum ausgeben der Informationen
    * Hitzespule

- Gehen Sie den gewählten Beispielen auf den Grund. Beschreiben Sie, auf welcher
  Hardware (Mikrocontroller, Speicher, Sensoren, Aktoren, Kommunikationselemente etc.)
  und Software (Betriebssystem) die Systeme basieren. Wenn es nicht möglich ist herauszufinden, welches Bauteil genau verwendet wurde, machen Sie einen Vorschlag für ein konkretes Bauteil. Für den Vorschlag soll ein Datenblatt vorliegen.

- Hardware:

  - Microcontroller: MC9S08QD2 8bit
  - Temperatur Sensor: LM35 low-cost linear
    temperature sensor
    - Genauigkeit von +- 3/4 Grad Celsius
    - Kann messen von -55 bis 150 Grad Celsius

  Der Microcontroller hat ein ob-chip-analog-to-digital coverter für die zwei Drehknöpfe für die Hitze und den Timer

  Ausgaben:

  - LED an = Toaster an
  - LED aus = Toaster aus
  - Lautsprecher gibt ein Ton aus = fertig 

- Software:

  ![ToasterSoftware](C:\Users\Fabian\Desktop\Semester4\EmbeddedSystem\Abgabe1\ToasterSoftware.png)

  Der Microcontroller wird gestartet

  Wartet auf die betätigung des Startknopf

  Die Hizespule wird eingeschaltet und auf die, am Drehknopf eingestellte, Temeratur gebracht

  Die Hitzespule wir beim Stopknopf oder beim ablauf des Timers ausgestellet und der Lautsprecher gibt ein beep von sich

  ​

  Die Temperatur wird geregelt durch an und ausschalten der Hitzespule![img](file:///C:/Users/Fabian/Desktop/Semester4/EmbeddedSystem/Abgabe1/Hitzeregelung.PNG?lastModify=1525007858)

  ​

- Überlegen Sie, warum die Entwickler/innen die Systeme so konstruiert und nicht anders
  entworfen haben.

  - Kleiner Microcontroller reicht aus
  - Der Tempersatur Sensor ist vergleichsweise billig 
  - Mit Drehknopfen kann man gut die Zeit und die Temperatur einstellen
  - LED und Lautsprecher reichen aus um die simplen ausgaben zu machen



### Aufgabe 2

- Beschreiben Sie die Anforderungen im Detail, die an die Beispiele der eingebetteten
  Systeme gestellt werden.


 - Verlässlichkeit

     - Zuverlässigkeit: Der Toaster Oven soll dein Essen mit deiner eingestellten Zeit und Hitze toasten
     - Wartbarkeit: Es kann nichts ausgetauscht werden
     - Verfügbarkeit: Kann überall benutzt werden wo es eine Steckdose gibt
     - Sicherheit: wenn das Gerät ausfällt muss man sich zwangsläufig Ersatz kaufen
     - Integrität: Datenklau ist bei einem Toaster kein Problem

-  Effizienz

     - Energieverbrauch: Maximal 230V, da es an einer normale Steckdose angeschlossen ist

     - Codegröße: klein

     - Laufzeit: Je nach Timer unterschiedlich lang kann auch öfters hintereinander verwendet werden

     - Gewicht: Relativ schwer da es eine mittlere Größe hat

     - Preis: <120

       ​

-  Stellen Sie weiterhin dar, welche Auswirkungen das Nichteinhalten der Anforderungen
     haben kann.

-  Wenn es zu ausfällen kommt kann es passieren das dein Essen kalt ist, dass kann auch zu einer Lebensmittelvergiftung führen

-  Es könnte auch dein Essen verbrennen 
     ​