# Embedded Systems - Praktikum 1

Beispiel eines eingebetteten Systems:

- TiWi - uB2 Bluetooth Module (LSR)

## Aufgabe 1

### Aufgabe 1.1

Das TiWi - uB2 Bluetooth Module dient zum Senden und Empfangen von Daten über Bluetooth. Über eine UART Schnittstelle kann es gesteuert werden. Auf dem Bluetooth Module wurde ein Mikrocontroller als Hardware verbaut, auf welchem eine Software zur Verarbeitung der Bluetooth Signale läuft. Zusätzlich gibt es noch eine RF Antenne als Sensor und Aktor, welche Signale Senden und Empfangen kann.

### Aufgabe 1.2

Das TiWi-uB2 Bluetooth Module besteht aus einem Mikrocontroller, einem Quarz, einem Bandpass Filter und einer RF Antenne. Der verwendete Mikrocontroller ist ein CC2564 Dual-mode Bluetooth Controller der Marke Texas Instruments. An diesen ist ein Quarz von 38.4Mhz angeschlossen. Desweiteren ist noch eine RF Antenne für den Bluetooth Empfang angeschlossen. Dazwischen liegt noch ein Band-Pass Filter, sodass nur noch Signale der korrekten Frequenz(ISM Band) zum Mikrocontroller gelangen.

Mikrocontroller: CC2564 mit vorinstallierter Bluetooth Software

Beispiel für 38.4Mhz Quarz: MQF 38.4-0600/03

Beispiel für Band-Pass Filter: ACPF-7224 (ISM Bandpass Filter)

Beispiel für RF Antenne: 2450AT43B100

### Aufgabe 1.3

Es gibt verschiedene Gründe, warum das System so entworfen wurde. Zum einen besitzt das System einen besonders einfachen und verständlichen Aufbau, sodass auch Hobbyentwickler die Funktionsweise möglichst schnell verstehen können. Zum Anderen enthält der verwendete Mikrocontroller schon eine für Bluetooth vorgesehene Software, sodass keine weitere Software installiert werden muss. Dies spart einen Arbeitsschritt bei der Herstellung des Bluetooth Moduls. Der verbaute Quarz dient zu einer genaueren Frequenzerzeugung, sodass der Mikrocontroller genauer arbeiten kann. Zuletzt soll der Band-Pass Filter ungewollte Daten abfangen, sodass der Mikrcontroller nur noch die tatsächlich benötigten Frequenzen empfängt.


## Aufgabe 2

### Aufgabe 2.1

Das Bluetooth Modul muss viele verschiedene Anforderungen erfüllen. Bezüglich der Verlässlichkeit soll es zuverlässig arbeiten, es soll also die Daten zuverlässig und fehlerfrei empfangen und senden. Desweiteren sollte es möglichst gut wartbar sein bzw. es sollte sich bei einem Defekt möglichst leicht austauschen lassen. Zusätzlich ist es wichtig, dass das Modul zu allen Zeitpunkten verfügbar ist und über das Modul kommuniziert werden kann. Sollte es zu einem Defekt an dem Gerät kommen, so soll es sicher sein und durch den Defekt keine weiteren Bauteile beschädigen. Zuletzt sollte es die Daten in Bezug auf die Integrität sicher übertragen können.

Auch im Bereich Effizienz sollten die Anforderungen erfüllt sein. Dazu sollte es einen möglichst geringen Energieverbrauch haben. Auch sollte das Bluetooth Modul die Daten möglichst schnell verarbeiten, sodass die Laufzeit möglichst gering ist. Desweiteren sollte das Gewicht genauso wie der Preis möglichst gering sein.

Als Einzwecksystem sollte sich das Bluetooth Modul auch nur um das Senden und Empfangen von Bluetooth Daten kümmern. Außerdem muss es ein reaktives System sein, um zu jeder Zeit neue Verbindungen anzunehmen bzw zu jeder Zeit Daten empfangen zu können. Zuletzt sollten weiche Zeitbedingungen eingehalten werden. Es sind also kurze Verzögerungen vor dem Senden und Empfangen von Daten erlaubt, solange diese vollständig und fehlerfrei übertragen werden.

### Aufgabe 2.2

Das Nichteinhalten der Anforderungen könnte eine Reihe von Problemen verursachen. Zuerst könnte es nicht möglich sein, dass das Bluetooth Modul von anderen Geräten nicht erkannt wird und man sich somit nicht verbinden kann. Auch könnte es andere Geräte stören, die auf der selben Frequenz senden wollen wie andere Bluetooth- oder WLAN-Geräte. Zusätzlich kann es noch zu einem Verbindungsabbruch beim Übertragen von Daten können.

Zuletzt könnte es sein, dass das Bluetooth Modul einen zu hohen Stromverbrauch oder ein zu hohes Gewicht hat, sodass es sich nicht lohnen würde, das Bluetooth Modul in tragbare Geräte mit Akku einzubauen.