# Praktikum 05 - Assembler

Malte Riechmann, André Kirsch

### Aufgabe 1

| Option | Erklärung                                                    |
| ------ | ------------------------------------------------------------ |
| -o0    | Standard Option. Reduziert Kompilierungszeit und ermöglicht Debugging (liefert dabei das erwartete Ergebnis). |
| -o2    | Führt fast alle möglichen Optimierungen durch. Verlängert dabei aber die Kompilationszeit, aber erhöht die Performance des generierten Codes. |
| -os    | Führt die gleichen Optimierungen wie -o2 durch, bis auf solche, die normalerweise die Code Größe erhöhen. Außerdem werden weitere Optimierungen durchgeführt, um die Code Größe zu reduzieren. |



Um auf die TivaC-Toolchain über die Kommandozeile zugreifen zu können, haben wir dessen Installationspfad in die Windows Umgebungsvariable PATH eingetragen. Die ermittelte Version ist 6.3.1  20170620.

Nachdem wir die Schritte ausgeführt haben, haben wir heraus gefunden, dass die Größe des Programmcodes 888 Bytes groß ist, die uninitialisierten Variablen belegen 260 Byte. Das ergibt eine Gesamtgröße von 1148 Byte.

```
   text    data     bss     dec     hex filename
    888       0     260    1148     47c blink.elf
```

Die Spalten des Disassembly haben folgende Bedeutung

| Speicheradresse in Hexadezimalem Format | Der Befehl in Maschinensprache in Hexadezimalem Format | Der Befehl in Assemblersprache (Lesbare Repräsentation der Maschinensprache) |
| --------------------------------------- | ------------------------------------------------------ | ------------------------------------------------------------ |
| 2ae:                                    | 4b0d                                                   | ldr r3 [pc, #52]                                             |



Im Folgenden werden die Anweisungen von 2ae bis 2da erläutert

| ldr	r3, [pc, #52] | Erläuterung                                                  |
| -------------------- | ------------------------------------------------------------ |
| ldr r3, [pc, #52]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 52 (Adresse des GPIO_PORTF_DIR_R) in das Register r3 |
| movs r2, #8          | Lädt die Zahl 8 in das Register r2                           |
| str r2, [r3, #0]     | Speichert den Inhalt vom Register r2 in das Register r3      |
| ldr r3, [pc, #48]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 48(Adresse des GPIO_PORTF_DEN_R) in das Register r3 |
| movs r2, #8          | Lädt die Zahl 8 in das Register r2                           |
| str r2, [r3, #0]     | Speichert den Inhalt vom Register r2 in das Register r3      |
| ldr r2, [pc, #48]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 48 von  in das Register r2 |
| ldr r3, [pc, #44]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 44 in das Register r3 |
| ldr r3, [r3, #0]     | Lädt die in das Register r3                                  |
| orr.w r3, r3, #8     | Verknüpft mit einem logischen Oder den Wert von Register r3 mit mit 8 und schreibt das Ergebnis in das Regiter r3. Das .w ist eine Kennzeichnung, das der Assembler ein 32 Bit Encoding für die Anweisung verwenden muss. |
| str r3, [r2, #0]     | Speichert den Inhalt vom Register r3 in das Register r2      |
| bl 26c \<delay\>     | Der Programm Counter Springt zu der angegebenen Programmadresse 26c. |
| ldr r2, [pc, #32]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 32 von  in das Register r2 |
| ldr r3, [pc, #48]    | Lädt den Wert der Adresse des Programmcounter mit einem Offset von 48 von  in das Register r3 |
|                      |                                                              |
|                      |                                                              |
|                      |                                                              |



### Aufgabe 2

```
   text    data     bss     dec     hex filename
    844       0     260    1104     450 blink.elf
```

Bei den Größen lässt sich erkennen, dass der Teil des Programmcodes um 44 Byte geschrumpft ist. Hier konnte der Compiler also durch die Optimierung den Programmcode ein wenig komprimieren.

Sofort erkennbare Änderungen im Assembler Code sind zum einen die komplett fehlenden Delay Funktion. Diese ist mit in die Main Funktion gerutscht. Als Folge davon gibt es aber in der Main Funktion wesentlich mehr Sprünge durch den Programmcode. Desweiteren werden alle Speicherstellen, die abhängig vom Programmcounter sind, zu Beginn der Main Funktion in die Register geladen. Dadurch wurde die Anzahl der gesamten ldr Aufrufe verringert und es wird eine größere Anzahl an Registern verwendet.

| Codestelle | Beschreibung                                        |
| ---------- | --------------------------------------------------- |
| ab 26c     | Vorladen aller wichtigen Adressen                   |
| ab 278     | Anweisungen vor der while-Schleife                  |
| ab 288     | Beginn der while-Schleife und bitweise OR-Anweisung |
| ab 292     | Erste Delay-Funktion                                |
| ab 2a4     | Bitweises Clearen                                   |
| ab 2ae     | Zweite Delay-Funktion                               |
| ab 2c0     | Sprung zurück zu Beginn der while-Schleife          |



### Aufgabe 3

Das Wort volatile bedeutet so viel wie: "Der Compiler darf an dieser Stelle nicht optimieren". Das bedeutet, dass jeder Programmcode, in den diese Variable genutzt wird, vom Compiler nicht optimiert wird.

Durch das fehlende volatile konnte der Compiler nun also auch die Stellen optimieren, die in Aufgabe 2 nicht optimiert werden durften. Dadurch hat er in diesem Fall den zweiten Aufruf der Funktion delay komplett aus dem Programmcode geschmissen. Die erste Delay Funktion wurde verkürzt auf die zwei Befehle an Stelle 290 und 292. Der restliche Programmcode wurde ähnlich compiliert, es unterscheidet sich lediglich in der Nutzung der verwendeten Register. Wodurch teilweise aus anderen Registern geladen und in andere Register geschrieben wird.