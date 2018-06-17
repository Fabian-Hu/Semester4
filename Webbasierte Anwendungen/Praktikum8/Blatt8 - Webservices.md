# Blatt 8 - Webservices

#### Welche Technologie macht es ihnen bei Java-WebServices einfach, ihre Datenobjekte als JSON oder XML über einen REST-WebService auszuliefern?

Die gesuchte Technologie bezeichnet man im Allgemeinen als **Content Negotiation**. Diese ermöglicht dem Client, dem Server mitzuteilen, welchen Datentyp die angeforderten Daten beim Versenden haben sollen. 

In der JAX-RS Spezifikation wird dafür JAXB genutzt, welches automatisch aus Java Objekten JSON oder XML generieren kann.