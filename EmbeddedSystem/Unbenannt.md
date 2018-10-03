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

![dawandler](Bilder\dawandler.PNG)



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

WCET - längst mögliche Ausführungszeit
BCET - beste

#### weicheDeadlines

Verfehlen der Deadline kein Fehler - wichtiger ist dabei die Statistik

#### harteDeadlines

Verfehlen der Deadline ist ein Fehler und die Folgen sind dramatisch

- periodisch
  - wenn der Task alle p Zeiteinheiten ausgeführt wird
  - jede Ausführung eines Tasks heißt Job
  - Die Ausführungszeit der Jobs ist immer gleich

![bubblepop](Bilder\bubblepop.PNG)


- aperiodisch
  - Maximale Verspätung
    - Maximale Differenz zwischen Ausführungsende und Deadline über alle Tasks; negativ, wenn vor Ende der Deadline fertig
  - Deadline-Intervall
    - Zeit zwischen Verfügbarkeit und Deadline

![letspowerup](Bilder\letspowerup.PNG)

- präemptiv
  - wenn der Scheduler unterbrechbar ist
  - sonst nicht präemptiv
- statisch
  - wenn ein Scheduler Entscheidungen vor der Laufzeit trifft
  - Startzeiten der Tasks in Tabelle abgelegt
  - ein Dispatcher startet die Tasks zur richtigen Zeit
- dynamisch
  - wenn ein Scheduler Entscheidungen auch während der Laufzeit trifft



![dummefrage](Bilder\dummefrage.PNG)


#### Scheduling Verfahren

- Round Robin mit Zeitschlitzen
- Earliest Due Date
  - alle Tasks gleichzeitig verfügbar 
  - Reihenfolge: früheste Deadline zuerst durch sortierung
  - Optimal für Minimierung der maximalen Verspätung 
- Earliest Deadline First EDF
  - unterschiedliche Ankunftszeit von Tasks 
  - Zu jedem Zeitpunkt wird Task mit der frühesten absoluten Deadline ausgeführt, ggf. Unterbrechen des aktuellen Task. 
  - Warteschlange von ausführbereiten Tasks nach Deadlines 
  - Dynamisches Scheduling
- Least Laxity (Geringster Schlupf) ??? 
- Rate Monotonic Scheduling
  - periodisch
  - Annahmen:
    - unabhängige Tasks
    - di = pi ( siehe periodisches Scheduling)
    - ci konstant und bekannt
    - bei n Tasks Einhaltung vond Deadlines für Auslastung
      - μ = ∑^n i=1ci / pi ≤ n(2^1/n-1) 
    - Priorität ist monoton fallende Funktion ihrer Periode, also haben Tasks mit kurzer Periode hohe Priorität 
- Rate Monotonic Analysis
  - Analyse des Rate Monotonic Schedulings 
  - Betrachtung des Falls mit der schlechtesten Antwortzeit 
    - Alle Jobs gleichzeitig bereit 
    - Kritische Antwortzeit beim niedrig periodisierten Task 

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

- Schleifen:
  - Einfache Transformationen
  - Kachelweise Verarbeitung
  - Aufteilung
  - Falten
    - Falten hat etwas mit Seen und Teichen zutun
- Mathematik 
  - Festkomma-Darstellung 
    - Berechnungen in Festkomma sind schneller
    - Reihenfolge der Berechnungen beeinflussen die Genauigkeit
  - Mathematische Näherungen
    - durch Taylor Reihen werden mathematische Funktionen angenähert
- Look-up Tabellen 
  - vorberechenen von Aufgaben
  - wenn man sie braucht kann man dann abschreiben
- Compiler Optimierungen
  - Laufzeit / Geschwindigkeit
  - Codegröße
  - Energieverbrauch

Norman 

- Dokumentation, Prozesse, Quantifizieren/Messen 
- als Empfehlungen der besten Herangehensweisen 
- zur Handhabung der Komplexität 
- zur Festlegung von Qualität und 
- zur Prüfbarkeit deren Umsetzung 

Sicherheitsintegritätslevel 

+ Level A: geringe Verletzung 
+ Level B: schwere Verletzung(en); Tod einer Person
+ Level C: Tod mehrerer Personen 
+ Level D: Tod vieler Personen 

Genereller Aufbau eines Paragraphen: 

+ Ziele 
+ Allgemeines 
+ Eingaben (Vorbedingungen) 
+ Anforderungen und Empfehlungen 
+ Arbeitsergebnisse

Coding Rules

- Kommentare 
- Klammern und Layout von mathematischen Ausdrücken 
- Keine impliziten Typkonvertierungen 
- Keine magischen Zahlen (magic numbers) 
- Einheitliche Namensgebung bei Variablen 









# Sonstiges

## optimierungsgedöns

Optimierungsflags

| Option | Erklärung                                                    |
| ------ | ------------------------------------------------------------ |
| -o0    | Standard Option. Reduziert Kompilierungszeit und ermöglicht Debugging (liefert dabei das erwartete Ergebnis). |
| -o2    | Führt fast alle möglichen Optimierungen durch. Verlängert dabei aber die Kompilationszeit, aber erhöht die Performance des generierten Codes. |
| -os    | Führt die gleichen Optimierungen wie -o2 durch, bis auf solche, die normalerweise die Code Größe erhöhen. Außerdem werden weitere Optimierungen durchgeführt, um die Code Größe zu reduzieren. |

Das Wort volatile bedeutet so viel wie: "Der Compiler darf an dieser Stelle nicht optimieren". 

## assembller

```c
 asm volatile(
    "movs r4, %[fibo]\n\t"  
    "movs r7, %[index]\n"
    "subs r7, #2\n\t"
    "fibonacci:\n\t"
    "ldr r5, [r4, #0]\n\t"
    "ldr r6, [r4, #1]\n\t"
    "add r5, r6\n\t"
    "str r5, [r4, #2]\n\t"
    "add r4, #1\n\t"
    "subs r7, #1\n\t"
    "bne fibonacci"
    : 
    : [index] "r" (lastFiboIndex), [fibo] "r" (fibData)
    : "r4", "r5", "r6", "r7", "cc", "memory"
  );

asm volatile(
    "movs r4, %[num]\n\t"
    "lsl r4, r4, #1\n\t"
    "cmp r4, #256\n\t"
    "it eq\n\t"
    "moveq r4, #1\n\t"
    "movs %[num], r4 \n\t"
  : [num] "+r" (number)
  : 
  : "r4", "cc", "memory"
  );
```



## timer

```c
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/timer.h"
#include "driverlib/hibernate.h"

#define ersteZeitspanne 1500      //TW
#define zweiteZeitspanne 500      //TU
#define dritteZeitspanne 1000     //TG
#define vierteZeitspanne 4000     //TE
#define gruenFuss PC_4
#define rotFuss PC_5
#define gruenAmpel PC_6
#define gelbAmpel PC_7
#define rotAmpel PD_6
#define knopf PUSH2

void setup() {
  Serial.begin(9600);
  pinMode(gruenFuss, OUTPUT);
  pinMode(rotFuss, OUTPUT);
  pinMode(gruenAmpel, OUTPUT);
  pinMode(gelbAmpel, OUTPUT);
  pinMode(rotAmpel, OUTPUT);
  pinMode(knopf, INPUT);

  SysCtlPeripheralEnable(SYSCTL_PERIPH_HIBERNATE);
  HibernateEnableExpClk(SysCtlClockGet());
  HibernateGPIORetentionEnable();
  HibernateWakeSet(knopf);
  ownDelay();
 }

class Timer {
  public:
    static Timer& getInstance() {    
      static Timer instance;     
      return instance;
    }
    
    void newISRFunction(void (*ISRFunction)(void)){
      TimerIntRegister(TIMER0_BASE, TIMER_A, ISRFunction);
    }
    
    void setTimer(int zeit) {
      int eintausend = 1000;
      int period = SysCtlClockGet() / eintausend;
      TimerLoadSet(TIMER0_BASE, TIMER_A, zeit * period);
      TimerEnable(TIMER0_BASE, TIMER_A);
      IntEnable(INT_TIMER0A);
      TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    }
  
    void resetTimer() {
      TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    }
  private:
    Timer() {  
       SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
       TimerConfigure(TIMER0_BASE, TIMER_CFG_ONE_SHOT);
    }
    Timer(const Timer& );
    Timer & operator = (const Timer &);
    
};

void ownDelay()
{ 
  Timer::getInstance().newISRFunction(energieSparer);
  Timer::getInstance().setTimer(vierteZeitspanne);
}

void energieSparer(){
  digitalWrite(rotAmpel,LOW);
  digitalWrite(gelbAmpel,LOW);
  digitalWrite(gruenFuss,LOW);
  
  digitalWrite(gruenAmpel,LOW);
  digitalWrite(rotFuss,LOW);

  HibernateRequest();
  while (true)
  {
  }
}

int zustand = 0;

void states(){
  Timer::getInstance().resetTimer();
  Serial.println(zustand);
  switch(zustand){
    case 6:
    case 0:
      // Ampel grün fußampel rot
      digitalWrite(rotAmpel,LOW);
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(gruenFuss,LOW);
      
      digitalWrite(gruenAmpel,HIGH);
      digitalWrite(rotFuss,HIGH);
      
      // Knopfdruck
      if (zustand == 6) {
        ownDelay();
      }
      
      // ersteZeitspanne
      if(zustand == 0){
        Timer::getInstance().setTimer(ersteZeitspanne);
        zustand = 1;
      }
      break;
      
    case 1:
      // ampel gelb
      digitalWrite(gruenAmpel,LOW);
      digitalWrite(gelbAmpel,HIGH);
       
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 2;
      break;
      
    case 2:
      // ampel rot
      digitalWrite(gelbAmpel,LOW);
      digitalWrite(rotAmpel,HIGH);
      
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 3;
      break;
      
    case 3:
      // fußampel grün
      digitalWrite(rotFuss,LOW);
      digitalWrite(gruenFuss,HIGH);
       
      // dritteZeitspanne
      Timer::getInstance().setTimer(dritteZeitspanne);
      zustand = 4;
      break;
      
    case 4:
      //fußampel rot
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotFuss,HIGH);
       
      // zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);
      zustand = 5;
      break;
      
    case 5:
      //ampel rot-gelb
      digitalWrite(gruenFuss,LOW);
      digitalWrite(rotAmpel,HIGH);
      digitalWrite(gelbAmpel,HIGH);
      
      //zweiteZeitspanne
      Timer::getInstance().setTimer(zweiteZeitspanne);  
      zustand = 6;  
      break;     
  }
}

void loop() { 
  if (digitalRead(knopf) == LOW && zustand == 0) {
        zustand = 0;
        Timer::getInstance().resetTimer();
        Timer::getInstance().newISRFunction(states);
        Timer::getInstance().setTimer(vierteZeitspanne);
      }
  }

```



## wire bilbilbiothek

````c
#include <Wire.h>

const uint8_t thermoAddress = 0x48;

const uint8_t cmdReadTemp = 0xAA;
const uint8_t cmdAccessTH = 0xA1;
const uint8_t cmdAccessTL = 0xA2;
const uint8_t cmdConfig = 0xAC;
const uint8_t cmdStartConversion = 0xEE;

const uint8_t polarity = 0x02;
const int8_t highTemp = 27;
const uint8_t notZero = 0b10000000;
const uint8_t zero = 0;
const uint8_t lowTemp = highTemp - 1;

const uint8_t requestByteCount = 2;

int8_t preComma;
int8_t postComma;

void setupThermometer() {
  Wire.setModule(0);

  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdConfig);
  Wire.write(polarity);
  Wire.endTransmission();
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdStartConversion);
  Wire.endTransmission();
  Serial.println("Thermometer initialized");
}

void setupHighTemperature() {
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdAccessTH);
  Wire.write(highTemp);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdAccessTL);
  Wire.write(lowTemp);
  Wire.write(notZero);
  Wire.endTransmission();
  Serial.println("High Temperature set");
}

void printTemperature() {
  Serial.print(preComma);
  if(postComma) {
    Serial.print(".5");
  }
  Serial.println("");
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  Serial.println("Initializing thermometer");
  setupThermometer();
  setupHighTemperature();
}

void loop() {
  Wire.beginTransmission(thermoAddress);
  Wire.write(cmdReadTemp);
  Wire.endTransmission();

  Wire.requestFrom(thermoAddress, requestByteCount);
  if (Wire.available()) {
    Serial.println("Reading temperature");
    preComma = Wire.read();
    postComma = Wire.read();
  }

  printTemperature();
}

````



## freeRTOS

```cpp

bool aktiveHeizung = false;

void firstLoop() {
	if(aktiveHeizung){
		uint16_t temp = analogRead(PD_0);
		Serial.print("Temperatur: ");
		Serial.println(temp);
		if(temp<300){
			Serial.println("Heizen");
			digitalWrite(PC_4,HIGH);
		}else{
			Serial.println("Abkühlen");
			digitalWrite(PC_4,LOW);
		}
	}
}

void secondLoop() {
  uint16_t helligkeit = analogRead(PD_1);
  Serial.print("Helligkeit: ");
  Serial.println(helligkeit);
  if(helligkeit<200){
	  aktiveHeizung = true;
  }else{
	  aktiveHeizung = false;
	  digitalWrite(PC_4,LOW);
  }
}

void setup() {
  // initialize the digital pin as an output.
  pinMode(PD_1, INPUT);
  pinMode(PD_0, INPUT);
  pinMode(PC_4, OUTPUT);
  Serial.begin(9600);
}

void taskOne(void *pvParameters) {
	for (;;) {
		vTaskDelay(1000 / portTICK_RATE_MS);
		firstLoop();
		if (serialEventRun)
			serialEventRun();
	}
}

void taskTwo(void *pvParameters) {
	for (;;) {
		vTaskDelay(2000 / portTICK_RATE_MS);
		secondLoop();
		if (serialEventRun)
			serialEventRun();
	}
}

int main(void) {
	setup();

	xTaskCreate(taskOne, "TASK 1", configMINIMAL_STACK_SIZE + 100, NULL,
				tskIDLE_PRIORITY + 1UL, NULL);
	xTaskCreate(taskTwo, "TASK 2", configMINIMAL_STACK_SIZE + 100, NULL,
				tskIDLE_PRIORITY + 2UL, NULL);
	vTaskStartScheduler();
}
```























Viedos

Least Laxity + Rate monotonic Analysis:  -playlist btw - inder btw
https://www.youtube.com/watch?v=0-0ASSc5Gvo&index=3&list=PL9S7pHvQESJFlZcjX01sfU2eZQ0hq3a-N

Interrupts und interrupt vector tabelle: - roboterstimme
https://www.youtube.com/watch?v=uFBNf7F3l60



Interrupts Code:

```c
void buttonInterruptHandler() {
	GPIOIntDisable(GPIO_PORTC_BASE, GPIO_PIN_4);
	Serial.println("Der Not-Aus-Knopf wurde gedrueckt");
	Serial.print("Laufzeit in Millisekunden: ");
	Serial.println(millis());
	Led.off();
}

void setup(){
  	Serial.begin(9600);
 	GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
  
  	GPIOIntDisable(GPIO_PORTC_BASE, GPIO_PIN_4);
  	GPIOIntClear(GPIO_PORTC_BASE, GPIO_PIN_4);
  	GPIOIntRegister(GPIO_PORTC_BASE, buttonInterruptHandler);
  	GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_RISING_EDGE); 
  	GPIOIntEnable(GPIO_PORTC_BASE, GPIO_PIN_4);
}

```







