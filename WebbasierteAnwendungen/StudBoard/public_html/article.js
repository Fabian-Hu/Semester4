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
    }
}

class news extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, kategorie, quellenangabe) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.kategorie = kategorie;
        this.quellenangabe = quellenangabe;
    }
        
    jsonSchreiben(){
        let obj = {
            attr1 : this.content,
            attr2 : this.titel,
            attr3 : this.titelfarbe,
            attr4 : this.startdatum,
            attr5 : this.enddatum,
            attr6 : this.kategorie,
            attr7 : this.quellenangabe
        };
        
        let newJsonStr = JSON.stringify(obj); 
        document.open();
        document.write(newJsonStr);
        document.close();
    }
    
}

class projects extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, professor, plaetze) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.professor = professor;
        this.plaetze = plaetze;
    }
    
    jsonSchreiben(){
        let obj = {
            attr1 : this.content,
            attr2 : this.titel,
            attr3 : this.titelfarbe,
            attr4 : this.startdatum,
            attr5 : this.enddatum,
            attr6 : this.professor,
            attr7 : this.plaetze
        };
        
        let newJsonStr = JSON.stringify(obj); 
        document.open();
        document.write('<a href="projects.json">' + newJsonStr + '</a>');
        document.close();
    }
}

class tasks extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, fach) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.fach = fach;
    }
    
    jsonSchreiben(){
        let obj = {
            attr1 : this.content,
            attr2 : this.titel,
            attr3 : this.titelfarbe,
            attr4 : this.startdatum,
            attr5 : this.enddatum,
            attr6 : this.fach
        };
        
        let newJsonStr = JSON.stringify(obj); 
        document.open();
        document.write('<a href="tasks.json">' + newJsonStr + '</a>');
        document.close();
    }
}

//news(content, titel, titelfarbe, startdatum, enddatum, kategorie, quellenangabe)
//projects(content, titel, titelfarbe, startdatum, enddatum, professor, plaetze)
//tasks(content, titel, titelfarbe, startdatum, enddatum, fach)

var news1 = new news("Hallo hier wohnt ein Igel","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
var news2 = new news("Ich habe keine Lust mehr", "Leben", "#000000", "1997-6-2", "2018-6-1", "unwichtig", "aus meinem Leben");
var porjekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");
var task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");

news1.jsonSchreiben();
news2.jsonSchreiben();
projekt1.jsonSchreiben();
task1.jsonSchreiben();
