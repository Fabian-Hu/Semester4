

#Webbasierte Anwendungen Blatt 5a

###Auf welche Arten kann ein JavaScript in eine HTML-Seite eingebunden werden?

* External: Aus einer anderen Datei, im Header oder Body 

* Internal: Im Script-Tag innerhalb Header oder Body 

* InAttribute: In einem onclick Attribut (veraltet!) 

  

###Wann werden JavaScripte ausgeführt?



JavaScripte werden ausgeführt, sobald der Browser sie vollständig geladen hat.

######Auswirkungen:

1. Skripte können ausgeführt werden, ehe das Dokument vollständig geladen ist 
2. Funktionen können „zu früh“ ausgeführt werden 
3. Eventuell sind noch nicht alle Abhängigkeiten geladen, wenn ein Skript startet