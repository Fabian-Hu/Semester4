# Blatt 11

## Theorie

Das MV* Muster trennt die drei Bereich Model, View und einem Bindeglied zwischen den beiden. Das Model beinhaltet die Informationen bzw. die Inhaltsojekte und teilt den Views mit, wenn eine Änderung eigetreten ist. Der Controller zwischen den beiden steuert dei Änderungen des Models.

## Implementierung

#### Aufgabe 5

Unsere Softwarearchitektur entspricht am ehest dem Model View ViewModel Modell. Es gibt eine strikte Trennung von Model und View, beide Kommunizieren ausschließlich mit dem ViewModel. Die View nutzt die Elemente des ViewModels (JavaScript-Dateien) ein und ist austauschbar. Das ViewModel kennt die View nicht und ruft Methoden vom Model aus.

Was fehlt, ist die Validierung im Model, welche nur indirekt über das Schreiben in die Datenbank gegeben ist. Außerdem muss das Model noch die View bei Änderungen benachrichtigen.