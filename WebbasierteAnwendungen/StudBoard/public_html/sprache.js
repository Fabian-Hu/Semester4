/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *     
    
   
 */

var de = ["Neuigkeiten", "Startseite", "Menü", "Projekte", "Aufgaben", "Neuer Artikel"];
var en = ["News", "Home", "Navigation", "Project", "Tasks", "New article"];

if (navigator.language.indexOf("en") > -1) {
    setLanguage(en);
} else if (navigator.language.indexOf("de") > -1) {
    setLanguage(de);
}

function setLanguage(language) {
    document.getElementById("navstart").innerHTML = language[1];
    document.getElementById("nav").innerHTML = language[2];
    document.getElementById("navpro").innerHTML = language[3];
    document.getElementById("navauf").innerHTML = language[4];
    document.getElementById("navnews").innerHTML = language[0];
    document.getElementById("navneu").innerHTML = language[5];
    console.log(language.toString());
}