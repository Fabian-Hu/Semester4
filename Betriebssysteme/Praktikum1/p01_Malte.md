# Praktikum 1

|Befehl |Parameter |Beschreibung |
|------|---------|------------|
|man|(Seite) Programm|System-Anzeigeprogramm für die Handbuchseiten. Über man n more wird die n-te Seite der More-Manuals angezeigt|
|pwd|-|Gibt aktuelles Arbeitsverzeichnis aus|
|ls|-|Gibt Ordner und Dateien des aktuellen Verzeichnisses aus|
|ls -l|-|Gibt Ordner und Dateien des aktuellen Verzeichnisses aus. Außerdem werden Dateityp zusammen mit den Zugriffsberechtigungen angezeigt|
|ls -al|-|Gibt Informationen von ls -l aller Dateien aus, es werden also auch versteckte Einträge (beginnend mit .) ausgegeben|
|cd|Zielpfad|Navigiert zu dem angegebenem relativen oder absoltem Pfad|
|mkdir|Ordnername|Erstellt ein Verzeichnis mit dem angegebenem Namen wenn es noch nicht existiert|
|rm|Dateiname|Entfernt angebene Datei. Über -r können Rekursiv alle Dateien eines Ordners gelöscht werden|
|cp|Quelle Ziel|Kopiert Quelldatei(en) in das Zielverzeichnis|
|mv|Quelle Ziel|Bewegt die Quelle zum Ziel und/oder bennent es um|
|more|Datei|Ermöglicht es Seitenweise(Fenstergröße) durch eine Datei zu navigieren|
|tar|-|Ermöglicht das Verarbeiten von tar oder zip Dateien. Es kann über xf ein tar oder zip Verzeichnis entpackt werden|
|gzip|-|Dient dem ver-/entpacken von gz Dateien (nur einzelne)|
|top|-|Zeigt dynamisch sortiert die aktuell Laufenden Prozesse des laufenden Systems|
|uname|-|Gibt Informationen zum System aus|

Was bewirkt``find . | xargs grep testString``?

Über ``find .`` wird jeder Ordner und jede Datei im Verzeichnis ausgehend im Verzeichnis aufgelistet. Hierbei werden auch die Dateien in Ordnern und Unterordner aufgelistet. Über ``|`` wird die Ausgabe von find an den zweiten Befehl weitergeleitet und über ``xargs`` als Parameter benutzt, in denen über ``grep`` nach "testString" gesucht wird. Der ``grep`` command wird somit für jede gefundene Datei ausgeführt

## Aufgabe 2

Teil 1:

1. cd /home

2. sudo mkdir Betriebssysteme

3. cd Betriebssysteme

4. sudo mkdir Vorlesung Praktikum

5. cd Praktikum

6. sudo mkdir p01

Teil 2:

1. cd ~
2. mv Downloads/file.tar.gz .
3. ls | head -n1            ->           1file1
4. ls | head -n1 | xargs rm

### Aufgabe 3

1. tar -xf dirStruct.tar.gz

2. rm -r rootTest

3. tar -xf dirStruct.tar.gz

4. cd rootTest/dir1

5. bei rm * .txt werden über * alle Dateien (keine Ordner) gelöscht und die Datei Namens .txt wird gelöscht. Bei rm können über Leer

6. Bei rm ist ein undo nicht  möglich, da die Dateien bzw. der Link auf die Dateien gelöscht wird und diese nicht verschoben werden.

   Mittels Data Recovery kann nach gelöschten Daten gesucht werden und diese können dann wieder hergestellt werden.