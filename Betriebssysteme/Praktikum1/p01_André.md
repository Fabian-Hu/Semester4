## Einfache Befehle der Shell - Praktikum 01

### Shell Befehle

| Befehl | Erklärung                                                    |
| ------ | ------------------------------------------------------------ |
| man    | Anzeigen des Handbuches zu einem bestimmten Befehl bzw. Programm |
| pwd    | Gibt das aktuelle Arbeitsverzeichnis an                      |
| ls     | Listet alle vorhandenen Ordner und Dateien im aktuellen Arbeitsverzeichnis auf |
| ls -l  | -l erweitert die Anzeige mit Informationen zu den Dateien und Ordnern, wie z.B. Zugriffrechte, Besitzer, Größe, etc. |
| ls -al | -a zeigt zusätzlich auch die versteckten Dateien, als die Dateien, die mit einem . beginnen, an |
| cd     | Wechselt in das angegebene Verzeichnis                       |
| mkdir  | Erstellt vom aktuellen Arbeitsverzeichnis aus einen neuen Ordner |
| rm     | Löscht Dateien oder auch ganze Ordner                        |
| cp     | Kopiert eine angegebene Datei oder Ordner in ein anderes Verzeichnis |
| mv     | Verschiebt die angegebene Datei oder benennt sie um          |
| more   | Anzeige von Textdateien in der Kommandozeile                 |
| tar    | Komprimieren und Entpacken von tar-Archiven(für mehrere Dateien) |
| gzip   | Komprimieren und Entpacken von gz-Archiven(nur einzelne Dateien) |
| top    | Dynamische Übersicht aller auf dem System laufenden Prozesse |
| uname  | Anzeige von Systeminformationen zum Kernel                   |

```bash
find . | xargs grep testString
```

- find . 
  Sucht nach allen Dateien
- |
  Übergibt die Antwort an den danach stehenden Befehl (Pipe Symbol)
- xargs grep testString
  xargs erwartet ein Kommando, das mit allen vorher über "find . " gefundenen Dateien ausgeführt wird. In diesem Fall wird innerhalb der Dateien nach dem String "testString" gesucht. Würde man den Befehl ohne "xargs" ausführen, so würden lediglich die Dateinamen durchsucht werden.



### file.tar.gz

1. Entpacken des Archivs mit "tar -xf file.tar.gz"
2. Herausfinden der obersten Datei mittels "ls | head"  - Ergebnis: 1file1
3. Löschen der Datei mit "rm 1file1"

| Zeichen | Bedeutung              |
| ------- | ---------------------- |
| *       | beliebig viele Zeichen |
| ?       | genau ein Buchstabe    |



### dirStruct.tar.gz

1. Entpacken des Archivs mit "tar -xf dirStruct.tar.gz"
2. Löschen des Entpackten Archivs mit "rm -r rootTest"
3. Erneutes Entpacken des Archivs
4. In den richtigen Ordner wechseln mit "cd rootTest/dir1"
5. Bei rm können mehrere Dateien gleichzeitig gelöscht werden, indem sie hintereinander gehängt werden. Somit würden erst alle Dateien mit *, also alle gelöscht werden und danach die Datei mit dem Namen '.txt'. Da diese aber nicht mehr existieren kann, wenn sie vorher existiert hätte, erscheint die Fehlermeldung, dass die Datei nicht gefunden und gelöscht werden konnte.
6. Das Ergebnis bei rm kann nicht mehr direkt rückgängig gemacht werden. Die Dateien werden direkt gelöscht und nicht in einen Papierkorb verschoben. Mittels Data Recovery könnte die Dateien aber möglicherweise gerettet werden.