## Blatt 1

#### Wie erfolgt die Übergabe der Daten vom Client zum Server mit dem HTTP-GET Befehl?

Es wird eine TCP Verbindung hergestellt über den Port 80 und der Client schickt eine HTTP Anfrage mit GET, darauf hin antwortet der Server mit einer entsprechenden Antwort

Anfrage:
GET //URL HTTP/1.1
Accept: MIME-Typen(text/html, ...); QUALITÄTSANSPRUCH (q=0.9)
USER-Agent: ANGABEN BROWSER (Mozilla/4.0)
Accept-Language: Sprache (en; q=0.5, ...)

Antwort:
PROTOKOLL-VERSION(HTTP/1.1) STATUS-CODE(200)
ANTWORT-DATUM(Date: Mo, 18 Oct 2017 23:20:55 GMT)
Content-Type: MIME-TYPEN(text/html)
Content(json/html)

#### Nennen Sie die wichtigste Quelle für Web-Standards

w3c.org

#### Was ist der Unterschied zwischen Anfragekopfzeilen und Antwortkopfzeilen?

Antwortkopfzeile 

* Respons Header
* 

Anfragekopfzeile

* Request Header
* 

#### Http Status Codes

* 100er Information, während die Anfrage bearbeitet wird
* 200er Erfolgreiche Anfrage
* 300er Umleitung
* 400er Anfragefehler
* 500er Serverfehler

## Blatt 2

#### Webapplikation

**Definition**: Eine Web-Applikation ist ein Softwaresystem, das auf Spezifikationen des World Wide Web Consortium (W3C) beruht und Webspezifische Ressourcen wie Inhalte und Dienste bereitstellt, die über eine Benutzerschnittstelle, den Web-Browser, verwendet werden. 

**Anwenderbezug(1):** Eine Web-Applikation wird von verschiedensten Anwendern mit verschiedensten Kontexten, Fähigkeiten und Vorwissen genutzt. 

**Nutzung(2): **Web-Applikationen werden unter verschiedensten Gegebenheiten genutzt. 

**Inhalte(3): **Die Inhalte (Content) einer Web-Applikation sind die Basis für ihre Nutzung und kritischer Faktor für die Akzeptanz. 

**Verlinkung(4): **Web-Applikationen haben Verbindungen zu anderen WebApplikationen. (Hypertext) 

**Darstellung(5):** Die Darstellung (Presentation) einer Web-Applikation ist mit ein wichtiger Faktor bei der Benutzerakzeptanz. 

**Software Struktur(6): **Eine Web-Applikation ist eine jederzeit verfügbare, verteilte Anwendung. 

**Hardware Nutzung(7):** Eine Web-Applikation hat einen beschränkten Zugriff auf die Hardware des Anzeigegerätes 

**Maschinenlesbarkeit(8): **Web-Applikationen sind zunächst einmal für die Verwendung durch Menschen konzipiert, können aber auch Konzepte zur Verwendung durch Algorithmen implementieren. 

### Kategorien

**Dokumentenzentriert:** Eine dokumentenzentrierte Web-Seite besteht aus statischen HTML-Seiten. 

**Interaktiv:** Eine interaktive Web-Anwendung bietet die Möglichkeit einfache Interaktionen über Eingabebereiche auszuführen 

**Transaktionale:** Eine transaktionale Web-Anwendung bietet die Möglichkeit schreibende Interaktionen auszuführen 

**Workflowbasiert: **Bei Workflowbasierte Web-Anwendungen steht die Abwicklung von Geschäftsprozessen (Workflow) im Vordergrund. 

**Kollaborative:** Kollaborative Web-Anwendungen rücken die Teilnahme der Anwender in den Mittelpunkt. 

**Portalorientiert:** Portalorientierte Web-Anwendungen verstehen sich als Zugriffspunkt auf verteilte, potentiell heterogene Informationsquellen und Dienste im Sinne eines Single Point of Access 

**Ubiquitäre:** Ubiquitäre Web-Anwendungen bieten uneingeschränkte Verfügbarkeit und personalisierte Dienste. 

**Semantisch:** Semantische Web-Anwendungen bereiten ihre Inhalte so auf, dass sie auch durch Algorithmen in ihrer Bedeutung ausgewertet werden können. 

**Progressiv:** Progressive Web-Anwendungen erfüllen Charakteristika, von Web-Anwendungen und nutzen Charakteristika von nativen Anwendungen. 

#### Checkliste

1. Welche Anforderungen werden an meine Web-Anwendung gestellt?
2. Welche Charakteristika sind für meine Web-Anwendung wichtig?
3. In welcher Kategorie ist meine Web-Anwendung realisierbar? (Minimalansatz)
4. Wie groß ist der geschätzte Aufwand für die Realisierung?
5. Was währe der Mehrwert einer Realisierung in einer höheren Kategorie?
6. Gibt es technische Einschränkungen? 

#### User Stories

| Als...   | ...möchte ich...         | ..., so dass...                   | Priorität | Akzeptanz             |
| -------- | ------------------------ | --------------------------------- | --------- | --------------------- |
| Benutzer | mich registrieren können | ich ein neues Profil anlegen kann | Muss      | Registrierung möglich |



## Blatt 3

####  Was ist der Unterschied zwischen strukturellen und semantischen Auszeichnungen? 

Durch semantisch korrektes HTML bekommen Inhalte eine Bedeutung und machen das Dokument zugänglicher. Dabei legt man mit HTML den Zustand der Inhalte fest, beispielsweise ob ein Text eine Überschrift ist oder der Inhalt,  aber auch Zitate lassen sich damit hervorheben.

Die Struktur von HTML legt eher den Aufbau einer Seite fest, indem es Bereiche definiert, bzw. trennt. Außerdem kann man Elemente, in Form von Tabellen und Listen, einfügen.

## Blatt 4

### Nennen sie die Kaskadierungs-Reihenfolge von CSS?

1. Browser
2. Extern und Intern (in Deklarations-Reihenfolge)
3. Inline

## Blatt 5

### Auf welche Arten kann ein JavaScript in eine HTML-Seite eingebunden werden?

- External: Aus einer anderen Datei, im Header oder Body 
- Internal: Im Script-Tag innerhalb Header oder Body 
- InAttribute: In einem onclick Attribut (veraltet!) 

```html
<script src=“datei.js“></script>
<script>…</script>
<a href=“#“ onclick=“alert(‘Ausgabe‘)“>Link</a>
```

### Wann werden JavaScripte ausgeführt?

JavaScripte werden ausgeführt, sobald der Browser sie vollständig geladen hat.

###### Auswirkungen:

1. Skripte können ausgeführt werden, ehe das Dokument vollständig geladen ist 
2. Funktionen können „zu früh“ ausgeführt werden 
3. Eventuell sind noch nicht alle Abhängigkeiten geladen, wenn ein Skript startet

### JSON

``` javascript
let jsonStr = JSON.stringify(obj); 

jsonObj = JSON.parse(jsonStr);
for(var attr in jsonObj) { 
	console.log(attr);
	if(typeof jsonObj[attr] == "object") {
		for(var i in jsonObj[attr]) {
			console.log(jsonObj[attr][i]);
		}
	}
}
```

### localstorage
``` javascript
localStorage.setItem(KEY,VALUE);
localStorage.getItem(KEY);
localStorage.removeItem(KEY);
localStorage.clear();
```

### service worker

``` javascript
// Wird aufgerufen wenn Dateien angefragt werden
this.addEventListener('fetch', function(evt) {
	console.log("Hole " + evt.request.url);
	evt.respondWith( // Responde with erwartet eine asynchrone Funktion
		caches.match(evt.request).then(
			function(res) { // res ist Ergebnis von
				caches.match()
				console.log("Resource >" + res.url + "< aus dem Cache geholt");
				return res;
		}).catch(function(err) {
			console.log("Resource >" + evt.request.url + "< nicht im Cache gefunden"); //return fetch(evt.request);
		})
	);
});

```

## Blatt 6



## Blatt 7

### Was muss der Browser machen, nachdem er folgende Antwort auf eine GET-Anfrage vom Server bekommen hat?

/HTTP/1.1 401 Unauthorized
Date: Mon, 13 Jan 2003 08:35:41 GMT
Server: Apache/1.3.24 (Win32) PHP/4.3.0
WWW-Authenticate: basic realm=“geschuetzterBereich“

Der Browser fragt nun nach dem Benutzernamen und dem dazugehörigen Passwort. 
Danach wird der GET-Request erneut gesendet, mit einem zusätzlichen Authorization-Header.
Das sieht dann ungefähr so aus:

GET /secure_document.html HTTP/1.0 
Accept: image/gif, image/jpeg, */* 
Accept-charset: iso-8859-1, *, utf-8 
Accept-encoding: gzip 
Accept-language: en 
User-Agent: Mozilla/4.51 [en] (WINNT; I) 
Authorization: Basic aGVpa286d29laHI 

Dabei muss man allerdings beachten, dass der Username und das Passwort zwar base64 codiert ist, aber dennoch unverschlüsselt gesendet wird.

