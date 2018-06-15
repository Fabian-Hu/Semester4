# Webbasierte Anwendungen Blatt 8

### Welche Technologie macht es ihnen bei Java-WebServices einfach, ihre Datenobjekte als JSON oder XML über einen REST-WebService auszuliefern?

Die Content Negotiation ist eine Technik des HTTP. Sie ermöglicht dem Client dem Server zu sagen, in welchem Typ die angeforderten Daten geliefert werden sollen.

Im REST Umfeld wird dies hauptsächlich mit XML und JSON verwendet.

In der JAX-RS Spezifikation nutzt es JAXB und ermöglicht so automatisches Generieren von JSON/XML aus JavaObjekten.