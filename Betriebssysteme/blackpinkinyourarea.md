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



# Vorlesung 8 - Speicherverwaldung II



# Vorlesung 9 - Dateisysteme



