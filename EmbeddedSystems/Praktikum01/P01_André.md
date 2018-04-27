# Embedded Systems - Praktikum 1

Beispiel eines eingebetteten Systems:

- TiWi - uB2 Bluetooth Module (LSR)

## Aufgabe 1

### Aufgabe 1.1

Software:

- Software zur Verarbeitung eines Bluetooth Signals

Hardware:

- Mikrocontroller zum Ausführen der Software

Sensor/Aktor:

- RF Antenne zum Senden/Empfangen von Signalen

Anforderungen:

- Verlässlichkeit
  - Zuverlässigkeit: Bluetooth Modul sollte Daten zuverlässig und fehlerfrei empfangen und senden
  - Wartbarkeit: Bluetooth Modul sollte bei Defekt leicht zu ersetzen sein
  - Verfügbarkeit: Bluetooth Modul sollte von anderen Geräten erkannt werden
  - Sicherheit: Bluetooth Modul sollte keine Explosionen verursachen (kA, bessere Idee?)
  - Integrität: Bluetooth Modul sollte die Daten sicher übertragen
- Effizienz
  - Energieverbrauch: Bluetooth Modul sollte einen geringen Energieverbrauch haben
  - Codegröße: Bluetooth Code sollte klein genug für den Mikrocontroller sein
  - Laufzeit: Bluetooth Modul sollte die Daten möglichst schnell verarbeiten
  - Gewicht: Bluetooth Modul sollte besonders leicht sein
  - Preis: Bluetooth Modul sollte kostengünstig zu erhalten sein
- Einzwecksystem: Das Bluetooth Modul sollte sich nur um den Empfang und das Sende von Daten kümmern
- reaktive System: Das Bluetooth Modul sollte dauerhaft mit der Umwelt interagieren, um neue Verbindungen anzunehmen
- weiche Zeitbedingungen: Kurze Verzögerungen bis zum Beginn des Senden oder Empfangen von Daten sind erlaubt, solange diese vollständig und fehlerfrei übertragen werden

### Aufgabe 1.2

Das TiWi-uB2 Bluetooth Module besteht aus einem Mikrocontroller, einem Quarz, einem Bandpass Filter und einer RF Antenne. Der verwendete Mikrocontroller ist ein CC2564 Dual-mode Bluetooth Controller der Marke Texas Instruments. An diesen ist ein Quarz von 38.4Mhz angeschlossen. Desweiteren ist noch eine RF Antenne für den Bluetooth Empfang angeschlossen. Dazwischen liegt noch ein Band-Pass Filter, sodass nur noch Signale der korrekten Frequenz(ISM Band) zum Mikrocontroller gelangen.

Mikrocontroller: CC2564 mit vorinstallierter Bluetooth Software

Beispiel für 38.4Mhz Quarz: MQF 38.4-0600/03

Beispiel für Band-Pass Filter: ACPF-7224 (ISM Bandpass Filter)

Beispiel für RF Antenne: 2450AT43B100

### Aufgabe 1.3

Gründe, warum das System so entworfen wurde:

- Einfacher Aufbau des Systems
- Der Mikrocontroller enthält direkt das richtige Programm für eine Bluetooth Kommunikation
- Der Quarz dient zur genaueren Frequenzerzeugung
- Der Band-Pass Filter soll nicht benötigte Frequenzen abfangen



## Aufgabe 2

