# Blatt 1 - Internet

## Theorie

Wie erfolgt die Übergabe der Daten vom Client zum Server mit dem HTTP-GET Befehl?

* Die Daten werden über TCP verschickt

* Verbindet sich auf Port 80

* ```
  GET //URL HTTP/1.1
  Accept: MIME-Typen(text/html, ...); QUALITÄTSANSPRUCH (q=0.9)
  USER-Agent: ANGABEN BROWSER (Mozilla/4.0)
  Accept-Language: Sprache (en; q=0.5, ...)
  ```

Nennen Sie die wichtigste Quelle für Web-Standards

* W3C

## Praxis

### Entwicklungsumgebung

### HTTP-Analyse

1. www.vfl-frotheim.de in Firefox
5. HTTP/1.1
6. GET
7. In der Anfragekopfzeile stehen die Anforderung bzw. Voraussetzungen die erfüllt sein müssen wie Accept (\*/\*), Accept-Encoding (gzip, deflate) und Accept-Language (de,en-US;q=0.7,en;q=0.3) und in der Antwortkopfzeile steht, was es tatsächlich ist, wie Content-Encoding (gzip), Content-Type (text/html; charset=UTF-8) Content-Encoding und X-Language (german)