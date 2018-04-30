# Embedded Systems - Praktikum 1

Beispiel eines eingebetteten Systems:

- TiWi - uB2 Bluetooth Module (LSR)
- Bluetooth

## Aufgabe 1

### Teil 1

Das TiWi - uB2 Bluetooth Module dient zum Senden und Empfangen von Daten über Bluetooth. Über eine UART Schnittstelle kann es gesteuert werden. Auf dem Bluetooth Module wurde ein Mikrocontroller als Hardware verbaut, auf welchem eine Software zur Verarbeitung der Bluetooth Signale läuft. Zusätzlich gibt es noch eine RF Antenne als Sensor und Aktor, welche Signale Senden und Empfangen kann.



Das ABS hat die Aufgabe das Blockieren der Reifen bei einer Vollbremsung zu verhindern, um beim Bremsen navigierbar zu bleiben. Das ABS ist ein reaktives System mit Echtzeit-Anforderung. Es besitzt eine harte Zeitbedingung, wenn diese nicht erfüllt wird kann es zu fatalen Folgen kommen. Das ABS besteht aus Drehzahlsensor, der seine Daten an die Steuereinheit weiterleitet, welche den Schlupf berechnet und gegebenenfalls die Aktoren, die steuerbaren Magnetventilen an der ABS-Hydraulik anspricht.

### Teil 2

Das TiWi-uB2 Bluetooth Module besteht aus einem Mikrocontroller, einem Quarz, einem Bandpass Filter und einer RF Antenne. Der verwendete Mikrocontroller ist ein CC2564 Dual-mode Bluetooth Controller der Marke Texas Instruments. An diesen ist ein Quarz von 38.4Mhz angeschlossen. Des Weiteren ist noch eine RF Antenne für den Bluetooth Empfang angeschlossen. Dazwischen liegt noch ein Band-Pass Filter, sodass nur noch Signale der korrekten Frequenz(ISM Band) zum Mikrocontroller gelangen.

Mikrocontroller: CC2564 mit vorinstallierter Bluetooth Software

Beispiel für 38.4Mhz Quarz: MQF 38.4-0600/03

Beispiel für Band-Pass Filter: ACPF-7224 (ISM Bandpass Filter)

Beispiel für RF Antenne: 2450AT43B100



Das ABS besitzt als Sensor vier Raddrehzahlsensoren (z.B. Induktivgeber), die pemanent die Drehgeschwindigkeit des Reifen misst. 

Die hieraus resultierenden Daten werden an die Steuereinheit (ECU) geliefert. Diese besteht aus ein bis zwei Mikroprozessoren (abhängig von dem alter des Systems), die mit einander vernetzt sind und einem nichtflüchtigen Programmspeicher. In der Steuereinheit werden die Werte für die Drehzahlgeschwindigkeit und den Schlupf (Abweichung zurück gelegte Strecke pro Radumfang und tatsächlicher Reifenumfang) durchgehend berechnet. Bei Blockiertendenz eines Rades gibt die Steuereinheit die Stellbefehle an die Aktoren weiter.

Die Aktoren sind die Magnetventile der ABS-Hydraulik, die genutzt werden um den Bremsdruck zu regulieren. Die Anzahl der Aktoren sind abhängig von dem System. In den älteren Systemen gab es nur zwei für die beiden hinteren Räder, in neueren inzwischen für alle vier Räder.

Das System besitzt kein Betriebssystem und wurde mit Assembler programmiert. 

Drehzahlsensor (Induktivgeber): Bendix® WS-24™, AD22157

Steuereinheit:  EC-60™, TPIC7218-Q1

ABS-Hydraulik: Bendix® M-32™

### Teil 3

Es gibt verschiedene Gründe, warum das System so entworfen wurde. Zum einen besitzt das System einen besonders einfachen und verständlichen Aufbau, sodass auch Hobbyentwickler die Funktionsweise möglichst schnell verstehen können. Zum Anderen enthält der verwendete Mikrocontroller schon eine für Bluetooth vorgesehene Software, sodass keine weitere Software installiert werden muss. Dies spart einen Arbeitsschritt bei der Herstellung des Bluetooth Moduls. Der verbaute Quarz dient zu einer genaueren Frequenzerzeugung, sodass der Mikrocontroller genauer arbeiten kann. Zuletzt soll der Band-Pass Filter ungewollte Daten abfangen, sodass der Mikrocontroller nur noch die tatsächlich benötigten Frequenzen empfängt.



Das System wurde so konstruiert, um es möglichst einfach und effizient zu halten. Es besitzt alles, was es für seine eine Aufgabe braucht und wurde auf die nötigsten Bestandteile reduziert. Das in neueren Systemen zwei Prozessoren eingesetzt werden hängt mit der Anzeige von Ausfällen oder Fehlern im ABS zusammen. Im Fehlerfall wird das ABS ausgeschaltet, die Kontrollleuchte schaltet sich ein und ein statischer Test läuft automatisch durch. Dieser kann zum Teil das Problem schon lösen.

## Aufgabe 2

### Teil 1

Das Bluetooth Modul muss viele verschiedene Anforderungen erfüllen. Bezüglich der Verlässlichkeit soll es zuverlässig arbeiten, es soll also die Daten zuverlässig und fehlerfrei empfangen und senden. Des Weiteren sollte es möglichst gut wartbar sein bzw. es sollte sich bei einem Defekt möglichst leicht austauschen lassen. Zusätzlich ist es wichtig, dass das Modul zu allen Zeitpunkten verfügbar ist und über das Modul kommuniziert werden kann. Sollte es zu einem Defekt an dem Gerät kommen, so soll es sicher sein und durch den Defekt keine weiteren Bauteile beschädigen. Zuletzt sollte es die Daten in Bezug auf die Integrität sicher übertragen können.

Auch im Bereich Effizienz sollten die Anforderungen erfüllt sein. Dazu sollte es einen möglichst geringen Energieverbrauch haben. Auch sollte das Bluetooth Modul die Daten möglichst schnell verarbeiten, sodass die Laufzeit möglichst gering ist. Des Weiteren sollte das Gewicht genauso wie der Preis möglichst gering sein.

Als Einzwecksystem sollte sich das Bluetooth Modul auch nur um das Senden und Empfangen von Bluetooth Daten kümmern. Außerdem muss es ein reaktives System sein, um zu jeder Zeit neue Verbindungen anzunehmen bzw. zu jeder Zeit Daten empfangen zu können. Zuletzt sollten weiche Zeitbedingungen eingehalten werden. Es sind also kurze Verzögerungen vor dem Senden und Empfangen von Daten erlaubt, solange diese vollständig und fehlerfrei übertragen werden.



Es werden einige Anforderungen an das ABS bezüglich der Verlässlichkeit gestellt. Die Verlässlichkeit bezieht sich zum einen auf eine hohe Zuverlässlichkeit, also dass das System nicht ausfällt, welches bei dem ABS verheerende Folgen haben kann. Durch Ausfall des ABS zum falschen Zeit kann es zu schweren Unfällen kommen. 

Außerdem bezieht es sich auf hohe Wartbarkeit. Das bedeutet, dass das System bei Ausfall schnell repariert werden kann, damit, die Autofahrer nicht zu lange auf die Reparatur warten müssen und deswegen das Risiko eingehen ohne ABS zu fahren. 

Darüber hinaus kommt es auf eine hohe Sicherheit an. Es soll kein weiterer Schaden bei einem Unfall entstehen und nicht andere elektronischen Systeme des Autos beschädigt werden, wodurch die weitere wichtige Funktionen des Autos ausfallen könnten

Des Weiteren ist eine hohe Integrität wichtig, damit keine wichtige Daten verloren gehen, so dass zum Beispiel der Schlupf falsch berechnet wird, oder der Befehl zur Bremsdruck Reduzierung nicht richtig übertragen wird. 

Außerdem werden noch einiger Anforderungen hinsichtlich der Effizienz gestellt. Das System soll dem Auto nicht zu viel Energie kosten und so andere Systeme beeinträchtigen. Des Weiteren soll es klein und leicht sein, um über all eingebaut werden kann und genug Platz für die restliche Technik lässt. Darüber hinaus sollte es nicht zu teuer sein, um nicht den gesamt Preis zu hoch werden lassen.

Das ABS ist ein reaktives System mit Echtzeit-Anforderung. Es besitzt eine harte Zeitbedingung, wenn diese nicht erfüllt wird kann es zu fatalen Folgen kommen. 

### Teil 3

Das Nichteinhalten der Anforderungen könnte eine Reihe von Problemen verursachen. Zuerst könnte es nicht möglich sein, dass das Bluetooth Modul von anderen Geräten nicht erkannt wird und man sich somit nicht verbinden kann. Auch könnte es andere Geräte stören, die auf der selben Frequenz senden wollen wie andere Bluetooth- oder WLAN-Geräte. Zusätzlich kann es noch zu einem Verbindungsabbruch beim Übertragen von Daten können.

Zuletzt könnte es sein, dass das Bluetooth Modul einen zu hohen Stromverbrauch oder ein zu hohes Gewicht hat, sodass es sich nicht lohnen würde, das Bluetooth Modul in tragbare Geräte mit Akku einzubauen.



Ein nicht einhalten der Anforderungen kann immer direkt fatale Folgen haben. Wenn das ABS nicht einwandfrei funktioniert kann es zu schlimmen Unfällen kommen.

