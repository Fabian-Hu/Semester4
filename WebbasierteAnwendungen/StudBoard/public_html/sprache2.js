/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

var de = ["Titel:", "Text:", "Artikeltyp:", "Projekte", "Aufgaben", "Neuigkeiten","Startdatum:","Enddatum:","TitelFarbe:","Senden","Neuen Artikel erstellen","Eingabeformular"];
var en = ["Title:", "Text:", "Articletype:", "Project", "Tasks", "News","Startdate:","Enddate:","Titlecolor:","Send", "Create a new article","Entry form"];

if (navigator.language.indexOf("en") > -1) {
    setLanguage(en);
} else if (navigator.language.indexOf("de") > -1) {
    setLanguage(de);
}

function setLanguage(language) {
    document.getElementById("title").innerHTML = language[0];
    document.getElementById("text").innerHTML = language[1];
    document.getElementById("artikeltyp").innerHTML = language[2];
    document.getElementById("projekt").innerHTML = language[3];
    document.getElementById("aufgabe").innerHTML = language[4];
    document.getElementById("news").innerHTML = language[5];
    document.getElementById("startdatum").innerHTML = language[6];
    document.getElementById("enddatum").innerHTML = language[7];
    document.getElementById("titelfarbe").innerHTML = language[8];
    document.getElementById("senden").innerHTML = language[9];
    document.getElementById("titel").innerHTML = language[10];
    document.getElementById("eingabe").innerHTML = language[11];
    console.log(language.toString());
}
