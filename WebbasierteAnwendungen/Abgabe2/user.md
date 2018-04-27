#Webbasierte Anwendungen Blatt 2

##Was ist der Unterschied  zwischen strukturellen und semantischen Auszeichnungen?

Durch semantisch korrektes HTML bekommen Inhalte eine Bedeutung und machen das Dokument zugänglicher. Dabei legt man mit HTML den Zustand der Inhalte fest, beispielsweise ob ein Text eine Überschrift ist oder der Inhalt,  aber auch Zitate lassen sich damit hervorheben.

Die Struktur von HTML legt eher den Aufbau einer Seite fest, indem es Bereiche definiert, bzw. trennt. Außerdem kann man Elemente, in Form von Tabellen und Listen, einfügen.

##Anforderungsanalyse: Machen Sie sich anhand der gegebenen TODO-Liste Gedanken zur Ausgestaltung der Anforderungen.

###1.)Erstellen Sie User Stories für die Webanwendung

####News darstellen
- Die Studierenden möchten News angezeigt bekommen
- Und zwar: Nicht allgemein, sondern aus ihren Fächern
- Und zwar: Es gibt Nachrichten (Vorlesungsausfälle) die wichtiger sind, als andere

####Projekt vorstellen
- Die Lehrenden möchten ihre Projekte vorstellen
- Und zwar: Nicht allen, sondern nur den Studenten aus dem eigenen Bereich
- Damit die Studierenden aus den Projekten lernen können

####Aufgaben darstellen
- Die Lehrenden und Studierenden möchten/können ihre Aufgaben darstellen
- Und zwar: Nicht allen, sondern nur den Studenten aus dem eigenen Fach
- Damit die Studierenden die Aufgaben lösen können

####Formular für Kommentare
- Die Lehrenden und Studierenden
- Möchten Kommentare schreiben
- Um Feedback zurück zugeben

####Schickes Design für die Seite
- Als Lehrender oder Studierenden
- Möchte ich ein schickes Design für die Seite haben
- Damit ich gewillt bin die Seite wieder zu besuchen

####Animationen
- Als Lehrender oder Studierender
- Möchte ich gute Animationen haben
- Damit die Navigation flüssig abläuft

####Mediendatein einbinden
- Als Studierender
- Möchte ich Mediendateien einbinden
- Damit die Lehrenden und Studierenden die Mediendateien anschauen können

####Mehrsprachen-Fähigkeit
- Als Lehrender oder Studierender
- Möchte ich die Seite lesen können
- Damit ich die Inhalte in meiner bevorzugten Sprache lesen kann

####Speichern von Artikeln
- Als Lehrender oder Studierender
- Möchte ich Artikel speichern können
- Damit ich die Artikel später wieder aufrufen kann

####Standort anzeigen
- Als Lehrender oder Studierender
- Möchte ich den Standort von Vorlesungen angezeigt bekommen
- Damit ich pünktlich zur Vorlesung kommen kann

####Inhaltsverzeichnisse
- Als Lehrender oder Studierender
- Möchte ich ein Inhaltsverzeichnis haben um sich besser Orientieren zu können
- Damit ich schnell zu meinem Gewünschten Artikel/Vorlesung finde

####Medien bearbeiten
- Als Lehrender oder Studierender
- Möchte ich meine Medien bearbeiten
- Damit ich eventuelle Fehler beseitigen kann

####Formlareingaben in Seite einfügen ???

####Navigtion über Tastenkürzel
- Als Lehrender oder Studierender
- Möchte ich mich schnell durch die Webanwendung bewegen können
- Damit ich schnell von Einem Artikel zu einem anderen Artikel/Vorlesung kommen kann

####Externe Inhalte einbinden
- Als Lehrender
- Möchte ich viele verschiedene Inhalte anbieten
- Damit die Studierenden vernünftig lernen können

####Medien hochladen / runterladen
- Als Lehrender oder Studierender
- Möchte ich Medien hochladen/runterladen
- Um die Medien mit anderen zu teilen oder von anderen Medien zu bekommen

####Kommentare hochladen / runterladen
- Als Lehrender oder Studierender
- Möchte ich Kommentare auch Offline zur Verfügung haben
- Damit ich Offline die Kommentare durchgehen kann

####Kommentare speichern
- Als Lehrender oder Studierender
- Möchte ich Kommentare abspeichern
- Um sie später wieder aufrufen zu können

####Kommunikation untereinander
- Als Lehrender oder Studierender
- Möchte ich mich mit meinen Lehrenden oder Studierenden austauschen
- Damit man mit anderen über Vorlesungsstoff und anderen Themen reden kann

###2.) Wie könnte die Seite gestaltet sein?(Mockup)
Siehe Mockup

###3.) Überlegen Sie,welche anderen Seiten sinnvollerweise Verlinkt(oder durch Tools eingebunden) werden können

* google Suche
* google Maps
* youtube

###4.) Dokumentieren Sie ihre Anforderungen für später

Siehe User Stories 

##Planung und Aufwandsabschätzung

###1.) Gehen Sie die Checkliste für die Webentwicklung durch

1. Welche Anforderung werden an meine Web-Anwendung gestellt?
   * Siehe TODO-Liste oder obrige Aufgabe
2. Welche Charakteristika sind für meine Web-Anwendung wichtig?
   * Anwenderbezug: Eine Web-Applikation wird von verschiedensten Anwendern mit verschiedensten Kontexten, Fähigkeiten und Vorwissen genutzt
   * Nutzung: Web-Applikationen werden unter verschiedensten Gegebenheiten genutzt
   * Inhalte: Die Inhalte (Aufgaben, Projekte und News) einer Web-Applikation sind die Basis für ihre Nutzung und kritischer Faktor für die Akzeptanz.
   * Verlinkung: Web-Applikationen haben Verbindungen zu anderen WebApplikationen. (Hypertext)
   * Darstellung: Die Darstellung (Presentation) einer Web-Applikation ist mit ein wichtiger Faktor bei der Benutzerakzeptanz.
   * Software Struktur: Eine Web-Applikation ist eine jederzeit verfügbare, verteilte Anwendung.
3. In welcher Kategorie ist meine Web-Anwendung realisierbar? (Minimalansatz)?
   * Kollaborative Web-Anwendungen: Benutzerinteraktion auf Inhaltsebene, Keine personalisierten Dienste
4. Wie groß ist der geschätzte Aufwand für die Realisierung?
   * Drei Monate
5. Was währe der Mehrwert einer Realisierung in einer höheren Kategorie?
   * Ubiquitäre Web-Anwendungen: Der Mehrwert dieser Kategorie ist das sie eine Vielzahl von Endgeräten unterstützt
6. Gibt es technische Einschränkungen?
   * Der Anwender benötigt einen Browser(Google Chrome, Firefox)

###2.) Begründen Sie, warum die Anwendung als Webanwendung realierst werden soll

- Mehrere Personen sollen auf unsere Anwendung zugreiffen können ohne vorwissen und ohne Installation.
- Eine Webanwendung ist ideal für Informationsaustausch von verschiedenen Themen und Projekten
- Unsere Anwendung besitzt mehrere Charakteristika von einer Webanwendung