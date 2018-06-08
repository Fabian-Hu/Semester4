# Blatt 7

Den gegeben Header bekommt man als Response vom Server, wenn man versucht auf Daten zuzugreifen, für die man sich authorisieren muss. 

Nachdem der Browser nun diese Antwort erhalten hat muss er den Benutzer nach Benutzernamen und Passwort fragen und anschließend den Request erneut senden mit einem zusätlichen Authorization-Header wie z.B:

````
Authorization: Basic aGBpa286d291aHI
````

