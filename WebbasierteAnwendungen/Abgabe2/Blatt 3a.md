#Blatt 3a

##Schreiben sie die Grundstruktur einer Tabelle in HTML auf

```html
<table>
    <thead>
        <tr>
          <th></th>
          <th>Haus A</th>
          <th>Haus B</th>
        </tr>
    </thead>
    <tbody>
        <tr>
          <th>Wohnfläche</th>
          <td>100</td>
          <td>150</td>
        </tr>
        <tr>
          <th>Gartenfläche</th>
          <td>50</td>
          <td>100</td>
        </tr>
    </tbody>
    <tfoot>
        <tr>
          <th>Gesamtfläche</th>
          <td>150</td>
          <td>250</td>
        </tr>
        <tr>
          <td colspan="3">Alle Angaben in Quadratmetern.</td>
        </tr>
    </tfoot>
</table>
```



##Nennen sie die drei wichtigsten Attribute für HTML-Formate

**action** 		URL an welche die Daten aus dem Formular gesendet werden

**method** 	bestimmt die HTTP-Methode die zum Versand genutzt wird 

**enctype** 	bestimmt den Mime-Type in dem Versendet wird 

Beispiel:

​	<form action=“URL“ method=“POST|GET“ enctype=“TRANSFERFORMAT“> 

​	</form>