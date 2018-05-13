/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function choooose() {
    var type,x;
    x = document.getElementById("form1");
    type = x.elements["artikelTyp"].value;
    console.log(type);
    if (type === "News") {
        var n = new news(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "kategorie", "quellenangabe");
    } else if (type === "Projekt") {
        var p = new projects(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "professor", "plaetze");
    } else if (type === "Aufgabe") {
        var t = new tasks(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "fach");
    } else {
        alert("Oops, something went wrong");
    }
}

class article {
    constructor(content, titel, titelfarbe, startdatum, enddatum) {
        this.content = content;
        this.titel = titel;
        this.titelfarbe = titelfarbe;
        this.startdatum = startdatum;
        this.enddatum = enddatum;
        this.type = "Article";
    }
}

class news extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, kategorie, quellenangabe) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.kategorie = kategorie;
        this.quellenangabe = quellenangabe;
        this.type = "News";
    }   
}

class projects extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, professor, plaetze) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.professor = professor;
        this.plaetze = plaetze;
        this.type = "Projects";
    }
}

class tasks extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, fach) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.fach = fach;
        this.type = "Tasks";
    }
}

//news(content, titel, titelfarbe, startdatum, enddatum, kategorie, quellenangabe)
//projects(content, titel, titelfarbe, startdatum, enddatum, professor, plaetze)
//tasks(content, titel, titelfarbe, startdatum, enddatum, fach)

