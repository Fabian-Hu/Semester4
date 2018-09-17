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



# Vorlesung  5 - Interprozesskommunikation



# Vorlesung 6 -Deadlocks



# Vorlesung 7 - Speicherverwaldung I



# Vorlesung 8 - Speicherverwaldung II



# Vorlesung 9 - Dateisysteme



