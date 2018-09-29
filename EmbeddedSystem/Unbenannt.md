# Embedded

![Codedesign](Bilder\Codedesign.PNG)

## Vorlsung 1 - Einleitung 

### Anforderungen

Verlässlich hinsichtlich 

- Zuverlässigkeit (nicht ausfallen)
- Wartbarkeit (schnell repariert bei Ausfall)
- Verfügbarkeit (hohe Zuverlässigkeit, hohe Wartbarkeit)
- Sicherheit (keinen Schaden bei Ausfall)
- Integrität (Gewährleistung von Daten- und Kommunikationssicherheit) 

Effizient hinsichtlich

- Energieverbrauch (Energie kostet...)
- Codegröße (z.B. Festplatte oft ungewünscht wg. Verschleiß) 
- Laufzeit (Einhalten von Zeitbedingungen)
- Gewicht (z.B. leicht trag- oder verbaubar)
- Preis (nur Teil eines System) 

Einzwecksystem: Eingebettetes System übernimmt oft genau eine bestimmte Aufgabe

 - vermindert Ressourcenanforderungen
 - verbessert Effizienz 

“Nicht mehr als nötig” für die dedizierte Aufgabe

oft keine Änderungen nach Fertigstellung möglich

oft Echtzeitbedingungen 

Transformative und reaktive Systeme

 - transformative: Eingabe, Berechnung, Ausgabe
 - reaktive: dauerhafte Interaktion mit seiner Umwelt 

Systeme mit Echtzeit-Anforderungen

 - harte Zeitbedingungen (Nichteinhalten ist Fehler)
 - weiche Zeitbedinungen (z.B. statistisch im Rahmen) 

## Vorlsung 2 - Elektrotechnick

R = U/I

Q = C * U 

• Knotenregel: In einem Knotenpunkt ist die Summe der hineinfließenden Ströme gleich der Summe der abfließenden Ströme. 

• Maschenregel: Die Summe der Teilspannungen einer Masche (Umlauf) ist null. 

#### Pull-Up Pull-Down

![pullupdown](Bilder\pullupdown.PNG)

Will man dafür sorgen, dass der Eingangspin logisch LOW erhält, wenn die Taste gedrückt wird, so gilt Teilbild 1.1. 

​	pullup  ist low active

Will man dafür sorgen, dass der Eingang logisch HIGH erhält, wenn die Taste gedrückt wird, gilt Teilbild 1.2. 

​	pulldown ist high active



## Vorlsung 3 - Toolchain

Elemente der Toolchain

- Cross-Compiler und 
- Linker
- Debugger
- Flash-Werkzeug
- Board circuit debug interface, z.B JTAG (IEEE 1149)
- Build-Management-Tools (z.B. make) 

Kompilierung

1. Lexikalische (Scanner), syntaktische (Parser) und semantische Analyse des Quellendes mit Ergebnis Syntaxbaum 
2. Ggf. Übersetzung des Syntaxbaums in Zwischencode und Optimierung des Zwischencodes 
3. Übersetzung des Zwischencodes/Syntaxbaums in Maschinencode. 
4. Ggf. Linken des Maschinencodes mit Bibliotheken 
5. Ergebnis: Lauffähiger Binärcode 

Cross Compiler (gcc)

1. Präprozessing Eingabe main.c, Ausgabe: main.i (Quellcode mit Includes) 
2. Kompilierung Eingabe: main.i, Ausgabe: main.s (Assemblersprache)
3. Assemblierung Eingabe: main.s, Ausgabe: main.o (Maschinensprache)
4. Linken Eingabe: main.o, Ausgabe: main.elf (Exe-/Linkable Format)
5. Konvertierung Eingabe: main.elf, Ausgabe: main.bin (Binärdatei zum Flashen) 

Flash-Werkzeug
Übertragen des Kompilats von dem Host-System auf das Target-System 

- mittels vordefinierter Schnittstelle (Soft- und Hardware) 
- abhängig von der Entwicklungshardware 
- auch möglich mittels Board circuit debug interface 

Debugger (Frontend) 

- läuft auf dem Host-System und 
- kommuniziert mit dem Target-System 
- über vordefinierte Schnittstelle. 

Board circuit debug interface (Backend) 

- wird angesprochen von Applikation auf dem Host-System, 
- welche mit dem Debugger kommuniziert.

Ein Linker Script beschreibt die Abbildung der Segmente (Memory Map) des Kompilats in den Speicher des TargetSystems 

Memory Map

- für Programmcode in ROM und RAM, 
- für Variablen im RAM, 
- für die Vektor-Interrupt-Tabelle. 

Interrupt-Vektor-Tabelle

- Teil der Memory Map 
- Beinhaltet die Interrupt-Handler: 
  - Einsprungadressen für ausgelöste Interrupts (später mehr). 
- Oft detailliert zu initialisieren. 

Bootloader 

- Auf Target-System installierter Programmcode
- Zur Unterstützung des Überspielen (Flashen) zum TargetSystem 
- Änderung des Bootloaders mittels speziellen Schritten (meist mit Setzen von sogenannten Fuse-Bits bei dem Flashen) 

## Vorlsung 4 - Hardware



![hardware](Bilder\hardware.PNG)



Harvard-Architektur 

- Programm- und Datenspeicher sind getrennt. 
- Programmcode kann nicht überschrieben werden.

von-Neumann-Architektur 

- gemeinsamer Speicher für Daten und Programmcode. 

Complex Instruction Set Computer CISC 

- mächtiger Befehlsumfang, wenig Register, unterschiedliche Befehlslängen

Reduced Instruction Set Computer RISC 

- nur notwendige Befehle gleicher Befehlslängen, mehr Register

Mikrocontroller 

- Mikroprozessor plus Speicher und I/O 

![mikroprozessor](Bilder\mikroprozessor.PNG)

![interrupts](Bilder\interrupts.PNG)

Watchdog / Wachhund 

- Verhindern eines Absturz / Aufhängen des Mikrocontrollers 
- Startet einen Timer, der bei Ablauf Reset ausführt. 
- Laufendes (nicht abgestürztes) Programm muss den Watchdog regelmäßig zurücksetzen. 

Pulsweitenmodulation (PWM) 

- Umwandlung einer technischen Größe in eine Signalfolge von Pulsen unterschiedlicher Breite.
- Frequenz des modulierten Signals dabei konstant
- Duty Cycle: Anteil von Anzustände an Gesamtintervall 
- Vergleich: Ofen auf Temperatur heizen mit An-/ Ausschalten 

Kommunikation/Bus

Anforderungen an Kommunikationskanäle entsprechen denen an das eingebettete System: 

- Robustheit (z.B. ausgesetztenTemperaturen) 
- Echtzeit 
- Fehlertoleranz (z.B. wenn eine Nachricht nicht ankommt) 
- Effizienz (Verbauung, Kosten) 
- Bandbreite 

Echtzeit / Kollisionen

Carrier-sense multiple access
Bei gleichzeitigem Senden auf Kanal gibt es Kollisionen 

- collision detect (CSMA/CD)
  - Bei Kollision: neuer Versuch nach zufälliger Wartezeit
- collision resolution (CSMA/CR)
  - In Arbitrierung werden Teilnehmern Prioritäten zugewiesen. Bei Kollision hat höhere Priorität Vorrang. 



## Vorlsung 5 - Microcontroller

#### Stack Pointer

In Thread mode, the function of this register changes depending on the ASP bit in the Control Register (CONTROL) register. When the ASP bit is clear, this register is the Main Stack Pointer (MSP). When the ASP bit is set, this register is the Process Stack Pointer (PSP) 

#### Link Register

The Link Register (LR) is register R14, and it stores the return information for subroutines, function calls, and exceptions 

#### Program Counter

The Program Counter (PC) is register R15, and it contains the current program address 

#### Power Managment

Unterscheidet sich in Sleep- und Deep-Sleep-Mode
Sleep-Mode hält den Prozessortakt an
Deep-Sleep-Mode stoppt System-Clock und schaltet die PLL und den Speicher aus 

## Vorlsung 6 - StateCharts

Vorteile:

+ Hierarchische Beschreibung endlicher Automaten
+ Nebenläufigkeit 
+ Werkzeugunterstützung 

Nachteile:

+ Unübersichtlich für komplexe Modelle
+ Grenzen bei der Wiederverwendung 
+ Nicht ausgelegt für verteilte Systeme 



siehe Vorlesung 6 für Bilder von State Charts

## Vorlsung 7 - ModSprach

![Itgoeson](Bilder\Itgoeson.PNG)

#### Use case diagrmamemmqe3rf

![letme](Bilder\letme.PNG)

#### Aktivitationitätigkeitigkeitsdiagramm

![youremyheartshaker](Bilder\youremyheartshaker.PNG)

##### , Zeitverlaufsdiagramma

![issanagay](Bilder\issanagay.PNG)

#### Sequenzdiagramm

![Baepsae](Bilder\Baepsae.PNG)

#### kontextdiagramm

![silverspoon](Bilder\silverspoon.PNG)

#### Anforderungsdiagramm

![keepitreallyman](Bilder\keepitreallyman.PNG)

##### Requirementsdiagrammition

![yougottaknowthatyourforreal](Bilder\yougottaknowthatyourforreal.PNG)

#### Blockdefinitionsdiagramm

![Blockdia](Bilder\Blockdia.PNG)

###### Internes Blockdiagramm![internesBlock](Bilder\internesBlock.PNG)

###  Parameterdiagramm 

![ParamDia](Bilder\ParamDia.PNG)

## Vorlsung 8 - Scheduling









## Vorlsung 9 - RTOS

###Standard-Software 

+ Wiederverwendbare Standardkomponenten 
  + Hardware-Abstraction-Layer 
  + Middleware 
  +  (Real Time) Operating Systems 
+  Oft auch als Intellectual Property IP bezeichnet (Geistiges Eigentum) 

###Hardware-Abstraction-Layer HAL 

Schicht zwischen (Anwendungs-)Software und Hardware 

“Standardisierte” Programmierschnittstelle unabhängig von unterliegender Hardware 

Kapselung von Hardware-spezifischen Programmcode

Erlaubt einfache Portierung auf andere Hardware 

###Middleware 

+ Nutzbare Zusatzsoftware für Anwendungsprogrammierung 
+ Zwischenschicht/Vermittlungssoftware zwischen Betriebssystem und Anwendung 
+ Oft gemeint: Kommunikationsbibliotheken  
+ z.b CORBA

### Eingebettete Betriebssysteme 

+ Allgemeine Anforderungen 
  + Konfigurierbarkeit (zur Compile-Zeit) 
  + Abarbeitung von Peripherie in Tasks und nicht im Kernel
  + Schutzmechanismen für Sicherheit, aber normalerweise nicht für direkte Speicherzugriffe 
  + Direktes Nutzen von Interrupts 

### Echtzeitbetriebssysteme RTOS 

+ Anforderungen an Echtzeitbetriebssystem (real-time operating system): 
  + Vorhersagbares Zeitverhalten 
    + Garantierte obere Schranke für Laufzeit 
    + Deterministisches Scheduling 
  + Zeitverwaltung/Scheduler bei Betriebssystem 
    + Priorisierung und hohe Präzision für Zeitdiensten 
    + Schnelles/vorhersagbares Umschalten (~Sekundenbruchteile) 
+ Gerätetreiber außerhalbs des Echtzeitbetriebssystem-Kerns 
  + Aufgaben des Kerns: 
    + Task-, Speicher- und Zeitverwaltung
    + Intertask-Synchronisation und -Kommunikation 

![Betreibsssysssteme](Bilder\Betreibsssysssteme.PNG)



+ Vorteile: 
  + Vorhandene Funktionalität, z.B. 
    + Scheduler 
    + Timer- und Interrupt-Handling 
  + Gegebene Modularität 
  + Portierbar- und Wartbarkeit 

### POSIX 

POSIX (Portable Operating System Interface) mit Echtzeit-Erweiterung 

+ Vorgabe einer API für Unix-ähnliche Betriebssysteme 

  include <pthread.h>

### RTOS-Standard: OSEK/VDX 

+ Gremium: Offene Systeme und deren Schnittstellen für die Elektronik im Kraftfahrzeug (OSEK) / Vehicle Distributed eXecutive (VDX) 
+ OSEK-OS, u.a. statischer Kernel: keine dynamische Speicherallokation und keine dynamische Generierung von Tasks 

###RTOS-Standard: AUTOSAR 

+ Gremium für AUTomotive Open System ARchitecture 
+ Fortsetzung von OSEK/VDX 
+ Beschreibung u.a. 
  + Trennung von Basis-Software (für Infrastruktur des Steuergeräts) und Anwendungssoftware 
  + Kommunikation der Basis- und Anwendungssoftware über virtuellen funktionalen Bus (Schnittstellen-API) 
  + Runtime Environment (Middleware) 

### Echtzeiterweiterungen von Betriebssystemen 

Hybride Betriebssysteme für Echtzeit- und andere Tasks 

+ 1.Komponenten-Austausch beim Standard-Betriebssystem, z.B. des Schedulers 
  + Problem: Abhängigkeiten von Tasks nicht berücksichtigt 
+ 2.Standard-Betriebssystem läuft als Task eines Echtzeitkerns 
  + Probleme beim Standard-Betriebssystem beeinflussen den Echtzeitkern nicht. 
  + Aufteilung von Geräten zwischen beiden Systemen ist möglicherweise notwendig. 

![echt](Bilder\echt.PNG)



### Linux für Eingebettete Systeme 

+ Beide Ansätze hybrider Echtzeiterweiterungen vorhanden: 
  + PREEMPT_RT (Scheduler ausgetauscht) 
    +  Präemptiver Kernel (aus User-Mode kann Kernel-Mode unterbrochen werden) 
  + RTLinux 
    + Linux als Task eines Real-Time Kernels 

### FreeRTOS 

- Unterstützung verschiedener Hardware-Plattformen 
- Single-Core, (Multi-Core ist selbst zu implementieren.) 
- Kleiner Kernel (ab 5 KB) 
- Open Source unter GPL, aber nutzbar für kommerzielle Projekte 

##### Features 

Präemptives und kooperatives Scheduling 

Flexibles Management von Taskprioritäten 

Queues 

Semaphoren und Mutexes 

Tick und Idle Hook Funktionen 

Stack Overflow checking 

### FreeRTOS: Task-Zustände 

+ Not-Running: 
  + Blocked: Warten auf Zeit- oder Synchronisation-Ereignis 
  + Suspended: ausgesetzt vom Scheduling mittels API Funktion 
  + Ready: Bereit zur Ausführung 
+ Running: In Ausführung 

Rate Monotonic Scheduling mit FreeRTOS 

- Verhindern von eigenen Prioritätsänderung der Tasks 
- Zuordnen der Prioritäten entsprechend RMS, d.h. je kleiner die Periode je höher die Priorität eines Tasks 
- Keine gleichen sondern nur eindeutige Prioritäten 

Queues 

- zur Kommunikation zwischen Tasks 
- üblicherweise in FIFO modus 
- eigenständig (gehören keinem Task) 
- Zugriff auf Queue eines Tasks optional mit Wartezeit 
  - Task in Blocked-Zustand bis Lese/Schreib-Zugriff möglich oder bis Wartezeit abgelaufen
  - Höchste Priorität gewinnt, sonst längste Wartezeit bei mehreren Tasks in Blocked-Zustand 





## Vorlsung 10 - ImplementierungsStandards















