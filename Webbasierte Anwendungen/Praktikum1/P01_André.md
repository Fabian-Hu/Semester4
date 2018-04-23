## Webbasierte Anwendungen Blatt 1

André Kirsch



### Theorie

Wie erfolgt die Übergabe der Daten vom Client zum Server mit dem HTTP-GET-Befehl?

- Die Datenübergabe des HTTP-GET Befehls verläuft analog zu allen anderen HTTP Befehlen über eine TCP Verbindung.
- Der HTTP-GET Befehl selber sendet keine umfangreichen Daten zum Server, sondern fragt nur Daten an.
- Ein Query-String kann in dem URL Feld eines HTTP-GET Befehls mitgesendet werden.
- Die HTTP-Kommunikation verläuft standardmäßig über Port 80
- ```http
  GET //URL HTTP/1.1
  Accept: MIME-Typen(text/html, ...); QUALITÄTSANSPRUCH (q=0.9)
  USER-Agent: ANGABEN BROWSER (Mozilla/4.0)
  Accept-Language: Sprache (en; q=0.5, ...)
  ```

Nennen Sie die wichtigste Quelle für Web-Standards

​	w3c - w3c.org



### Praxis

#### Entwicklungsumgebung installieren

Die NetBeans IDE ließ sich ohne Probleme installieren und der Glassfish Server war über Port 8080 erreichbar.

#### Entwickler-Tools: HTTP-Analyse

1. Es wurde die Website www.fh-bielefeld.de in Firefox geöffnet
2. Es wurde die Entwicklerkonsole mit F12 geöffnet
3. Es wurde der Tab "Netzwerkanalyse" geöffnet
4. Es wurde die angeforderte HTML-Seite in der Entwicklerkonsole geöffnet
5. Es wurde die HTTP-Version HTTP/1.1 verwendet
6. Es wurde die Anfragemethode GET verwendet
7. Die Anfragekopfzeilen sind die vom Client an den Server gesendeten Kopfzeilen und die Antwortkopfzeilen sind die vom Server an den Client gesendeten Kopfzeilen. In den Anfragekopfzeilen stehen die Anforderung bzw. Voraussetzungen, die erfüllt sein müssen wie Accept (\*/\*), Accept-Encoding (gzip, deflate) und Accept-Language (de,en-US;q=0.7,en;q=0.3) und in den Antwortkopfzeilen steht, was es tatsächlich ist, wie Content-Encoding (gzip), Content-Type (text/html; charset=UTF-8) Content-Encoding und X-Language (german)