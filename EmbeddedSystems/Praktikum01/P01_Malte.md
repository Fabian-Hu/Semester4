# Praktikum 1 - Fragen zu eingebetteten Systemen

Beispiel 1: Anitblockiersystem (ABS6)

Beispiel 2: Bluetooth

## Aufgabe 1

### Teil 1

Das ABS hat die Aufgabe das Blockieren der Reifen bei einer Vollbremsung zu verhindern, um beim Bremsen navigierbar zu bleiben. Das ABS ist ein reaktives System mit Echtzeit-Anforderung. Es besitzt eine harte Zeitbedingung, wenn diese nicht erfüllt wird kann es zu fatalen Folgen kommen. Das ABS besteht aus Drehgeschwindigkeitssensoren, einer Steuereinheit und steuerbaren Magnetventilen an der ABS-Hydraulik.

### Teil 2

Das ABS besitzt als Sensor vier Raddrehzahlsensoren (z.B. Induktionsgeber), die pemanent die Drehgeschwindigkeit des Reifen misst. 

Die hieraus resultierenden Daten werden über ein Bussystem (**genauer**) an die Steuereinheit (ECU) geliefert. Diese besteht aus ein bis zwei Mikroprozessoren (abhängig von dem alter des Systems), die mit einander vernetzt sind und einem nichtflüchtigen Programmspeicher. In der Steuereinheit werden die Werte für die Drehzahlgeschwindigkeit und den Schlupf (Abweichung zurück gelegte Strecke pro Radumfang und tatsächlicher Reifenumfang) durchgehend berechnet. Bei Blockiertendenz eines Rades gibt die Steuereinheit die Stellbefehle an die Aktoren weiter.

Die Aktoren sind die Magnetventile der ABS-Hydraulik, die genutzt werden um den Bremsdruck zu regulieren. Die Anzahl der Aktoren sind abhängig von dem System. In den älteren System gab es nur zwei für die beiden hinteren Räder, in neueren inzwischen für alle vier Räder.

Das System besitzt kein Betriebssystem und wurde mit Assembler programmiert. 

### Teil 3

Das System wurde so konstruiert, um es möglichst einfach und effiezient zu halten. Es besitzt alles, was es für seine eine Aufgabe braucht und wurde auf die nötigsten Bestandteile reduziert. Das in neueren Systemen zwei Prozessoren eingesetzt werden hängt mit der Anzeige von Ausfällen oder Fehlern im ABS zusammen. Im Fehlerfall wird das ABS ausgeschaltet, die Kontrollleucht schaltet sich ein und ein statischer Test läuft automatisch durch. Dieser kann zum Teil das Problem schon lösen.

## Aufgabe 2

Es werden einige Anforderungen an das ABS bezüglich der Verlässlichkeit gestellt. Die Verlässlichkeit bezieht sich zum einen auf eine hohe Zuverlässlichkeit, also dass das System nicht ausfällt, welches bei dem ABS verherrende Folgen haben kann. Durch Ausfall des ABS zum falschen Zeit kann es zu schweren Unfällen kommen. 

Außerdem bezieht es sich auf hohe Wartbarkeit. Das bedeutet, dass das System bei Ausfall schnell repariert werden kann, damit, die Autofahrer nicht zu lange auf die Reperatur warten müssen und deswegen das Risiko eingehen ohne ABS zu fahren. 

Außerdem kommt es auf eine hohe Sicherheit an. Es soll kein weiterer Schaden bei einem Aufall entstehen und nicht andere elektronischen Systeme des Autos beschädigt werden, wodurch die weitere wichtige Funktionen des Autos ausfallen könnten

Außerderm werden noch einiger Anforderungen hinsichtlich der Effizienz gestellt. Das System soll dem Auto nicht zu viel Energie kosten und so andere Systeme beeinträchtigen. Des weiteren soll es kleine und leicht sein, um über all eingebaut werden kann und genug Platz für die restliche Technik lässt. Des weiteren sollte es nicht zu teuer sein, um nicht den gesamt Preis zu hoch werden lassen.

