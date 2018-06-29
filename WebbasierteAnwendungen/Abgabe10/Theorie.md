##Was ist der Unterschied zwischen einer JSP und einem Servlet? 

| JSP                                                          |                           Servlet                            |
| ------------------------------------------------------------ | :----------------------------------------------------------: |
| dynamische Erzeugung von Textinhalten                        |          dynamische Erzeugung von binären Inhalten           |
| Generierung einer Darstellung in HTML, WML, …                | Generierung von textuellen Inhalten mit Templates für Webdarstellungen |
| Präsentation der Benutzerschnittstelle                       |        Schaffung eines zentralen webbezogenen Zugangs        |
| Vorverarbeitung eingehender Daten                            |                Umsetzen der Geschäftsprozesse                |
|                                                              |                 Anwenden der Geschäftslogik                  |
|                                                              |                                                              |
| höhere Abstraktionsebene als Servlets                        |                 näher am Server (Container)                  |
| Einbindung von Tag-Bibliotheken                              |            Darstellung eigener binärer MIMETypen             |
| Deklarativer Stil                                            |           Prozeduraler od. objektorientierter Stil           |
|                                                              |                                                              |
| starke Mischung von Logik und Darstellung bei größeren Seiten |         Unübersichtlichkeit bei zu vielen Templates          |
| Mangelnde Skalierbarkeit                                     |                 Reagiert träge zur Laufzeit                  |
|                                                              | ggf. Rollenverteilung von Designer und Entwickler problematisch |


##Was ist der Nachteil dieser Implementierung? Recherchieren sie nach Alternativen

###Nachteile: 
* Unübersichtlichkeit bei zu vielen Templates 
* Reagiert träge zur Laufzeit 
* ggf. Rollenverteilung von Designer und Entwickler problematisch

###Alternatvien
* Node.js
* CGI-Entwicklung












