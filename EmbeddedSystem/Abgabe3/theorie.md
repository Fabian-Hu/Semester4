# Praktikum 3 (10 Punkte) - Energia: Installation, Toolchain

## Aufgabe 1

Erledigt

## Aufgabe 2

### a

1. Bibliotheken suchen
2. Prototypen generieren
3. Sketch kompilieren
4. Zusammenlinken der Dateien und Bibliotheken
5. Mit Board verbinden
   1. Programm hochladen
   2. Flash löschen
   3. Starten

### b

assembler, um den Code in Binärcode zu ändern

linker, linkt alle Objekte in eine ausführbare Datei

Compiler: gcc, zum kompilieren

DSLite, zum hochladen

## Aufgabe 3

### a

 ~/.energia15/packages/energia/hardware/tivac/1.0.3/cores/tivac

 ~/.energia15/packages/energia/hardware/tivac/1.0.3/variants/EK-TM4C123GXL

### b

Ein Linker Skript ist eine Datei, in der die Optionen für einen Linker stehen, zum Beispiel wo die Positionen der einzelnen Segmente im Speicher festgelegt werden. 

### c

``` c
Memory {
	flash	(rx)  : ORIGIN = 0x00000000, LENGTH = 0x00040000
	ram		(rwx) : ORIGIN = 0x20000000, LENGTH = 0x00008000     
}
```

Der Flash (mit den Berechtigungen im Memory zu lesen und auszuführen) beginnt vom Anfang des Speichers an der Stelle 0x00000000 und ist 0x00040000 lang.
Der RAM (mit den Berechtigungen im Memory zu lesen, zu schreiben und auszuführen) beginnt vom Anfang des Speichers an der Stelle 0x20000000 und ist 0x00008000 lang.

## Aufgabe 5
energia-1.6.10E18/hardware/energia/msp430/cores/msp430/Energia.h
energia-1.6.10E18/hardware/energia/msp430/cores/msp430/main.cpp

erst wird init() aufgerufen.
Danach wird unsere setup() Methode aufgerufen
und zum Schluss in einer Endlosschleife die loop() Methode, welche ggf. durch einen Runtime Fehler abgebrochen wird.
Weitere Funktionen werden in der Main nicht aufgerufen. Somit sind setup und loop die einzigen Funktionen, die wir zwingend implementieren müssen.