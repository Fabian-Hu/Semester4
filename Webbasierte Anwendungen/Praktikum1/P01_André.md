## Webbasierte Anwendungen Blatt 1

André Kirsch



### Theorie

Wie erfolgt die Übergabe der Daten vom Client zum Server mit dem HTTP-GET-Befehl?

- Die Datenübergabe des HTTP-GET Befehls verläuft analog zu allen anderen HTTP Befehlen über eine TCP Verbindung.
- Der HTTP-GET Befehl selber sendet keine umfangreichen Daten zum Server, sondern fragt nur Daten an.
- Ein Query-String kann in dem URL Feld eines HTTP-GET Befehls mitgesendet werden.
- Die HTTP-Kommunikation verläuft standardmäßig über Port 80
- GET [URL] HTTP/1.1
  Accept: [MIME-TYPEN] ; [Qualität]
  User-Agent: [Angaben zum Browser]
  Accept-Language: [Sprache]
  [...]

Nennen Sie die wichtigste Quelle für Web-Standards

​	w3c - w3c.org



### Praxis

#### Entwicklungsumgebung installieren



#### Entwickler-Tools: HTTP-Analyse

1. Es wurde die Website www.fh-bielefeld.de in Firefox geöffnet
2. Es wurde die Entwicklerkonsole mit F12 geöffnet
3. Es wurde der Tab "Netzwerkanalys" geöffnet
4. Es wurde die angeforderte HTML-Seite in der Entwicklerkonsole geöffnet
5. Es wurde die HTTP-Version HTTP/1.1 verwendet
6. Es wurde die Anfragemethode GET verwendet
7. Die Anfragekopfzeilen sind die vom Client an den Server gesendeten Kopfzeilen und die Antwortkopfzeilen sind die vom Server an den Client gesendeten Kopfzeilen