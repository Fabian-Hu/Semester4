# Vorlesung 1 - Einleitung  & Shell

Aufgaben des Betriebssystems:

- Boot
- login
- Benutzeroberfläche
- Daten verwalten
- Programme ausführen
- Ressourcen verwalten(CPU, Speicher, Programms, processes)
- Abstraktion von der Hardware



shell war zu langweilig

# Vorlesung 2 - Prozesse

Zusammenarbeit zwischen Anwenderprogramm und BS: Welches sind die Ziele des Kernel-Call-Mechanismus?

 - Erhöhung der Geschwindigkeit 
 - Vereinfachung der Programmierung 
 - Schutz von Speicherbereichen 
 - Einsparung von Energie
 - Senkung der Taktfrequenz 
 - Entkopplung von User und System 

Nennen Sie die Basis- oder Kernelfunktionalitäten eines BS!

- Prozessmanagement 
- Dateimanagement 
- Behandlung von Echtzeitereignissen 
- Bestimmung der Prozessreihenfolge 
- Userverwaltung 
- Verwaltung des virtuellen Speichers 
- Login 
- Nachrichtentransport 



# Vorlesung 3 - noch mehr Prozesse

Zustände:

- Aktiv (running): Der Prozess belegt gerade das Betriebsmittel CPU und wird ausgeführt.
- Bereit (ready): Der Prozess wartet darauf, die CPU zu erhalten.
- Blockiert (waiting): Der Prozess wartet
  - auf ein E/A Gerät,
  - eine Nachricht von einem anderen Prozess,
  - ein Zeitgebersignal oder ähnliches.
  - Selbst wenn die CPU zur Verfügung steht, kann der Prozess in diesem Zustand nicht aktiv werden.
- Neu (new): Ein neuer Prozess wird erzeugt.
- Beendet (terminated): Der Prozess ist beendet.  

![threads](D:\Studium\Semester4\Semester4\Betriebssysteme\Bilder\threads.PNG)

# Vorlesung 4 - Scheduling

![schedulingbegriffe](D:\Studium\Semester4\Semester4\Betriebssysteme\Bilder\schedulingbegriffe.PNG)

Parallele Prozesse:

+ Rechner mit mehreren CPUs oder Netzwerke aus unabhängigen Rechnern (Multiprozessorsystemen) können mehrere Prozesse zeitgleich ausführen
+ Prozesse laufen unabhängig von einander (parallel)

Nebenläufige Prozesse: 

+ Rechner mit einer CPU können immer nur einen Prozess bearbeiten

+ Prozesse laufen hintereinander in beliebiger Reihenfolge (nebenläufig) 

+ Parallelität (Pseudoparallelität) wird durch Multitasking realisiert  

  

Nebenläufige Prozesse 

Kommunikation zwischen Prozessen:

+ Prozesse arbeiten oft zusammen, um ihre Aufgabe zu erfüllen.
+ Dabei stellen sich folgende Fragen:
  + Wie findet der Austausch der Daten zwischen den Prozessen statt?
    + Über gemeinsame Variablen (gemeinsame Speicherbereiche)?
    + Über Nachrichtenaustausch (Message Passing)?
  + Wie wird die Konsistenz gemeinsam genutzter Daten sichergestellt?
  + Wie wird die richtige Reihenfolge beim Zugriff auf gemeinsame Daten sichergestellt?
+ Die beiden letzten Fragen führen zum Problem der Prozesssynchronisation
  + Scheduling beeinflusst Abarbeitungsreihenfolge von Maschinenbefehlen
  + Außerhalb der Kontrolle des Anwendungsentwicklers 

# Vorlesung  5 - Interprozesskommunikation















# Vorlesung 6 -Deadlocks



Vier Bedingungen, die zum Auftreten einer Verklemmung notwendig sind (Coffman / Elphick / Shoshani, 1971): 

1. Wechselseitiger Ausschluss:
   + Jede Ressource ist entweder verfügbar oder genau einem Prozess zugeordnet.
2.  Hold-and-wait-Bedingung: 
   + Prozesse, die schon Ressourcen reserviert haben, können noch weitere Ressourcen anfordern. 
3. Nichtunterbrechbarkeit: 
   + Ressourcen, die einem Prozess bewilligt wurden, können diesem nicht wieder entzogen werden (no preemption). 
4. Zyklische Wartebedingung:
   + Es muss eine zyklische Kette von Prozessen geben, von denen jeder auf eine Ressource wartet, die dem nächsten Prozess in der Kette gehört.  

Behandlung von Dreadlocks

1. Ignorieren: Erscheint unangemessen, aber:
   - Die meisten Betriebssysteme inklusive Windows und Unix verfahren so.
   - Kein zusätzlicher Overhead für selten auftretende Ereignisse. 
2. Erkennen und Beheben: Lasse Deadlocks passieren und behebe sie dann. 
3. Dynamische Verhinderung: durch vorsichtiges Ressourcenmanagement. 
4. Vermeidung von Deadlocks: Eine der vier notwendigen Bedingungen muss prinzipiell unerfüllbar werden.  

Deadlocks: Erkennen und Beheben 

Zwei Phasen des Algorithmus: 

- Erkennungsphase (detection algorithm): Das Betriebssystem überprüft periodisch, ob ein Deadlock vorliegt.
- Behebungsphase (recovery algorithm): Im Fall eine Deadlocks ergreift das Betriebssystem Maßnahmen, um den Deadlock aufzulösen.
- Notwendige Randbedingungen zur Erkennung:
- Die notwendigen Informationen über belegte und angeforderte Ressourcen müssen einfach zugänglich sein.
- Der Aufwand zur Entdeckung von Deadlocks muss vertretbar sein. (z.B. während der Ausführung des Erkennungsverfahrens dürfen keine Betriebsmittel angefordert oder freigegeben werden.) 

###Deadlocks: Beheben

+ Behebung durch Unterbrechung: Einem Prozess wird eine Ressource zeitweise entzogen, Zuteilung an blockierten Prozess. 
  + Auswahl des Prozesses schwierig. 
  + Nicht jede Ressource kann zeitweise entzogen werden. 
+ Behebung durch teilweise Wiederholung (Rollback): 
  + Prozess schreibt seinen Zustand (belegte Ressourcen) regelmäßig (Checkpoints) in Log-Dateien. 
  + Prozess, der einen Deadlock durch die Anforderung einer Ressource verursacht, wird auf einen Checkpoint zurückgesetzt, in dem er die Ressource noch nicht benötigt hat. 
  + Arbeit hinter dem Checkpoint ist verloren. 
+  Behebung durch Prozessabbruch (und Neustart): 
  +  Am einfachsten und wirkungsvollsten (aber: am brutalsten). 
  +  Auswahl des zu beendenden Prozesses schwierig. 
  +  Kann zu Inkonsistenzen bei globalen Daten führen. 

# was zur hölle sind sichere Zustände??!?!?!!??!??!?!?!??!!??

 







# Vorlesung 7 - Speicherverwaldung I

![xfvyxfgvxfgfgd](D:\Studium\Semester4\Semester4\Betriebssysteme\Bilder\xfvyxfgvxfgfgd.PNG)



Zwei Arten der Speicherverwaltung können unterschieden werden: 

1. Speicherbelegung ist fest (einfache Variante)
   - Monoprogrammierung:
     - Nur ein Prozess und das Betriebssystem teilen sich den Speicher
     - frühe Batchsysteme, Embedded Systems (BS im ROM) 
     - Problem: Speicherschutz zwischen BS und Applikation
   - Multiprogrammierung:
     - Mehrere Prozesse gleichzeitig im Speicher,
     - jeder Prozess bekommt einen festen Speicherbereich. 
2. Speicherbelegung ist flexibel: 
   - Prozesse werden zwischen Hauptspeicher und Platte verschoben
   - Verfahren: Swapping, virtueller Speicher 

##### Speicherverwaltung: Relokation

Möglichkeiten der Relokation von Prozessen: 

+ Es wird nur relative Adressierung eingesetzt. 
  + Geht nicht für jeden Prozessortyp 
+ Es wird eine Relokationstabelle benutzt: 
  + Programm wird für Adresse 0 gelinkt. 
  + Relokationstabelle enthält jede absolute Adresse in der Binärdatei. 
  + Beim Laden des Programms wird der Startoffset zu den Adressen addiert. 
+ Hardwareunterstützung → Memory Management Unit (MMU): 
  + Basisregister wird automatisch zu jeder Adressinformation addiert

Die Hardware zur Unterstützung der Relokation ist die Memory Management Unit (MMU) 

 + Jeder Prozess hat seinen eigenen logischen Adressbereich.
 + Bei jedem Kontextwechsel wird die MMU umprogrammiert, um den neuen logischen Adressbereich einzustellen. 
 + Keine Relokation des Programmcodes notwendig, da jeder Prozess ab der logischen Adresse 0 beginnt. 
 + Speicherschutz gegeben, da jeder Prozess nur seinen Speicher sieht (sonst: Segmentation Fault). 

#Speicherverwaltung: Probleme mit fester Speicherbelegung  

Moderne Computersystem haben andere Anforderungen:

+ Es laufen meist viele Prozesse, die schnell reagieren müssen (Interaktive Systeme) 
+ Prozesse haben mehr Speicherbedarf, als physikalischer Speicher vorhanden ist 

Mögliche Lösungen: 

+ Swapping: Verschieben von kompletten Prozessen zwischen Platte und Hauptspeicher 
+ Virtueller Speicher: Daten der Prozesse sind nur zum Teil im Hauptspeicher  

Speicherbelegungsstrategien

Wie finde ich ein passendes Segment, wenn ein Prozess neuen Speicher benötigt?

- First fit: Das erste passende Loch in der Liste wird genommen. Vorteil: sehr effizient!
- Next fit: Wie first fit, allerdings wird die Suche an der Stelle, wo zuletzt Speicher gefunden wurde, fortgesetzt (→ Ringstruktur).
- Best fit: Sucht das kleinste passende Loch in der gesamten Liste. Große Löcher bleiben lange bestehen, es werden aber viele kleine, nutzlose Löcher erzeugt.
- Worst fit: Sucht das größte freie Loch. Alle Löcher verfügen mit der Zeit über ungefähr die gleiche Größe. Große Speicherbereiche können aber evtl. später nicht mehr bereit gestellt werden.
- Quick fit: Für die Löcher werden getrennte Listen für Löcher gebräuchlicher Größe erzeugt. Findet sehr schnell passende Löcher, die Speicherfreigabe ist allerdings aufwändig (Abgleich Listen bei verschmelzen Löcher).  

Virtueller Speicher: Überblick

+ Idee des virtuellen Speichers (virtual memory, Fotheringham, 1961):
  + Ist ein Programm größer als der zur Verfügung stehende Speicher, dann wird nur der gerade benötigte Teil im Speicher gehalten.
+ Wichtige Fragen:
  + Welche Teile werden gerade benötigt?
  + Welche Teile können ausgelagert werden? -> Auslagerungs- und Einlagerungsstrategien.
+ Zweistufiges Adressierungsschema:
  + Die von den Programmen benutzten virtuellen Adressen werden von der Memory Management Unit (MMU) in physikalische Adressen umgewandelt und
  + dann erst an den Speicher gegeben.
+ Wichtigstes Verfahren: Paging

Prinzip des Paging:

- Der virtuelle Adressraum ist in Seiten (pages) aufgeteilt.
- Der physikalische Speicher ist in Seitenrahmen / Seitenkacheln (page frames) aufgeteilt.
- Seiten und Seitenrahmen sind immer gleich groß!
- Die virtuelle Adresse wird in
  - eine Seitennummer (page number) und
  - eine Adresse innerhalb der Seite (page offset) aufgeteilt.
- Die Seitennummer adressiert einen Seitenrahmen über eine Seitentabelle (page table).
- Seiten, die nicht im Speicher gehalten werden können, werden auf Platte (Hintergrundspeicher) auslagert.  



###Virtueller Speicher: Seitenfehler

Was passiert bei einem Zugriff auf eine nicht geladene Seite?  

+ Beispiel: Befehl MOV REG, 22870 

+ Die MMU stellt fest, dass die virtuelle Seite (5 = 0101) nicht geladen ist und löst eine Unterbrechung aus →Seitenfehler (page fault). Der aufrufende Prozess wird blockiert.
+ Das Betriebssystem sucht einen freien Seitenrahmen aus. 
  + Ist kein Seitenrahmen frei, wird ein benutzter Seitenrahmen gewählt. 
+ Wurde dieser modifiziert, wird er auf die Platte zurückgespeichert. 
+ Seite wird von der Platte geladen und in den Seitenrahmen geschrieben. 
+ Seitentabelle wird aktualisiert. 
+ Der Befehlszähler des aufrufenden Prozesses wird zurückgesetzt (der letzte Befehl muss wiederholt werden) und der Prozess wird wieder in den ‚bereit‘ Zustand versetzt.  

### Struktur eines Page Table Eintrags

![Candypop](D:\Studium\Semester4\Semester4\Betriebssysteme\Bilder\Candypop.PNG)

- Page frame number:
  - Verweis auf Seitenrahmen
- Present
  - 0: Seite noch nicht im Speicher (hard miss)
  - 1: Seite im Speicher enthalten
- Modified (Dirty Bit) 
  - 0: Seite unverändert, (Inhalt identisch zum Hintergrundspeicher)
  - 1: Seite verändert
- Referenced (Zugriff erfolgt ja/nein?)
- Caching disabled (I/O Mapping)
- Protection: z.B. read/write/execute 

### Problemstellungen bei Seitentabellen: 

1. Die Seitentabellen können sehr groß werden.  
2. Die Adressumrechnung muss sehr schnell erfolgen. 
   - Der Zugriff auf die Seitentabelle darf nicht zum Flaschenhals werden.
   - Pro Maschinenbefehl können mehrere Zugriffe auf Seitentabelle nötig sein (Befehlswort, Speicheroperand) 

Mehrstufige Seitentabellen:

- Auch die Seitentabellen werden nicht immer vollständig im Speicher benötigt. 

### Translation Lookaside Buffer (TLB)

- Untersuchung:
  - Prozesse greifen häufig auf einige wenige Seiten zu
- Idee:
  - Der Paging-Tabelle, die im Arbeitsspeicher liegt, wird eine kleine schnelle Hardware-Tabelle (Registerebene) vorgeschaltet - TLB
- Oftmals wird die Seite im TLB gefunden
- Ist die Seite nicht im TLB enthalten (soft miss), wird die Pagingtabelle ausgelesen
  - Die Adresse wird dann in den TLB übernommen und ersetzt dort einen alten, länger nicht verwendeten Eintrag 
- Zur Beschleunigung des Zugriffs auf die Seitentabelle wird die MMU mit einem Cache ausgestattet, dem Assoziativspeicher oder TLB (Translation Lookaside Buffer).  

## Seitenersetzung

Strategien:

man versucht bei der Seitenersetzungsstrategie möglichst wenig Transfers von Seiten zwischen dem Speicher und der Platte zu haben

- Optimale Strategie
  - auslagern der Seite, welche in der Zukunft am spätesten gebraucht wird
  - geht nicht, weil man nicht in die Zukunft sehen kann
  - bei definierten Programmabläufen kann man es zum beurteilen der Qualität als Referenz benutzen
- FIFO
  - die älteste Seite im Speicher wird verdrängt
  - die älteste Seite kann auch die am meisten genutze sein
- LRU
  - auslagern der am längsten unbenutzen Seite
  - schwierig und ineffizient
- NRU
  - Die Seiten werden in Klassen eingeteilt
  - dafür wird das R und M Bit ausgewertet
  - aus der niedrigsten nicht leeren Klasse wird eine zufällige Seite verdrängt
- Second Chance
  - FIFO mit zweiter Chance	
  - Anstatt die älteste Seite auszulagern wird das R-Bit gelöscht
  - Die älteste Seite ohne R-Bit wird ausgelagert
- Beladys Anomalie
  - Zahl der Rahmen erhöhen
  - verringert nicht zwangsläufig die Seitenfehler
  - kein eigener Algorithmus
- Working Set Strategie
  - Die meisten Prozesse starten mit einer Seite und laden dann bei Bedarf Seiten nach (Demand Paging): 
  - Menge der Seiten, die ein Prozess zu einem bestimmten Zeitpunkt benutzt heißt Working Set.  
  - das Betriebssystem merkt sich das working Set beim einlagern eines Prozesses

Entladestrategie

- Demand-Cleaning:
  - Bei Bedarf
  - Vorteil: Seite lang im Hauptspeicher
  - Nachteil: Verzögerung bei Seitenwechsel
- Precleaning:
  - Präventives Zurückschreiben, wenn Zeit ist
  - Vorteil: Frames in der Regel verfügbar
- Page-Buffering:
  - Listen verwalten
  - Modified List: Wird zwischengepuffert
  - Unmodified List: Für Entladen freigegeben 

Lokalitätsprinzip

- Prozesse weisen zeitliche und räumliche Lokalität auf: 
  - zeitlich: 
    - kürzlich angesprochene Adresse wird in naher Zukunft wieder angesprochen. 
    - Gründe: Schleifen, Unterprogramme, Stacks, Zählvariable 
  - räumlich:
    - Adressen in der Nachbarschaft kürzlich angesprochener Adressen werden mit größerer Wahrscheinlichkeit angesprochen als weiter entfernte.
    - Gründe: Durchlaufen von Feldern, sequentieller Code-Zugriff 



# Vorlesung 9 - Dateisysteme

























