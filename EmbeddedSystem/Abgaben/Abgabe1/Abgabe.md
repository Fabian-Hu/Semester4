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
    * Zwei Radioknöpfe für die Hitze und den Timer
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

  Der Microcontroller hat ein ob-chip-analog-to-digital coverter für die zwei Radioknöpfe für die Hitze und den Timer

- Software:

  ![ToasterSoftware](C:\Users\Fabian\Desktop\Semester4\EmbeddedSystem\Abgabe1\ToasterSoftware.png)

  Der Microcontroller wird gestartet

  Wartet auf die betätigung des Startknopf

  Die Hizespule wird eingeschaltet und auf die, am Radioknopf eingestellte, Temeratur gebracht

  Die Hitzespule wir beim Stopknopf oder beim ablauf des Timers ausgestellet und der Lautsprecher gibt ein beep von sich

  ​

  Die Temperatur wird geregelt durch an und ausschalten der Hitzespule![img](file:///C:/Users/Fabian/Desktop/Semester4/EmbeddedSystem/Abgabe1/Hitzeregelung.PNG?lastModify=1525007858)

  ​

- Überlegen Sie, warum die Entwickler/innen die Systeme so konstruiert und nicht anders
  entworfen haben.



### Aufgabe 2

- Beschreiben Sie die Anforderungen im Detail, die an die Beispiele der eingebetteten
  Systeme gestellt werden.
- Stellen Sie weiterhin dar, welche Auswirkungen das Nichteinhalten der Anforderungen
  haben kann.


##### Wasserhahn

 -  Zuverlässigkeit

     - Das System darf nicht ausfallen, damit man sich jederzeit die Hände waschen kann
     - sonst hat man schmutzige Hände und das ist unhygienisch

- Wartbarkeit

  - Baustellen auf der Toilette sind immer unerwünscht, also sollten sie möglichst schnell vollzogen werden
  - sonst fühlen sich Nutzer im Bad gestört

- Verfügbarkeit

  - ergibt sich aus den oberen beiden Anforderungen
  - sonst bekommt man von eventuellen Kunden Beschwerden und sie kaufen nicht mehr bei einem ein (Anwendungsfall Kaufhaus)

- Sicherheit

  - bei einem Ausfall darf der Wasserhahn nicht für immer weiterlaufen
  - sonst enstehen einerseites Wasserkosten, andererseits wird das Badezimmer womöglich überflutet.

- Integrität

  - Da es nur ein Wasserhahn ist und keine Daten gesammelt werden ist die Integrität kein Problem
  - (Es wäre wohl nicht sehr ruhmreich sich in ein Wasserhahn zu hacken um ihn an und auszumachen, zumal hatder Wasserhahn keine Schnittstelle nach draußen)

  ​