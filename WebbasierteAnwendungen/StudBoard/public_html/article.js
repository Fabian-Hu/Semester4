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
    
    get content() {
        return this.content;
    }
    set content(param) {
        this.content = param;
    }
    get titel() {
        return this.titel;
    }
    set titel(param) {
        this.titel = param;   
    }
    get titelfarbe() {
        return this.titelfarbe;
    }
    set titelfarbe(param) {
        this.titelfarbe = param; 
    }
    get startdatum() {
        return this.startdatum;
    }
    set startdatum(param) {
        this.startdatum = param;
    }
    get enddatum() {
        return this.enddatum;
    }
    set enddatum(param) {
        this.enddatum = param;
    }
}

class news extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, kategorie, quellenangabe) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.kategorie = kategorie;
        this.quellenangabe = quellenangabe;
    }
    
    get content() {
        return this.content;
    }
    set content(param) {
        this.content = param;
    }
    get titel() {
        return this.titel;
    }
    set titel(param) {
        this.titel = param;   
    }
    get titelfarbe() {
        return this.titelfarbe;
    }
    set titelfarbe(param) {
        this.titelfarbe = param; 
    }
    get startdatum() {
        return this.startdatum;
    }
    set startdatum(param) {
        this.startdatum = param;
    }
    get enddatum() {
        return this.enddatum;
    }
    set enddatum(param) {
        this.enddatum = param;
    }
    get kategorie() {
        return this.kategorie;
    }
    set kategorie(param) {
        this.kategorie = param;
    }
    get quellenangabe() {
        return this.quellenangabe;
    }
    set quellenangabe(param) {
        this.quellenangabe = param;
    }
    
    jsonSchreiben(){
        let obj = {
            attr1 : content,
            attr2 : titel,
            attr3 : titelfarbe,
            attr4 : startdatum,
            attr5 : enddatum,
            attr6 : kategorie,
            attr7 : quellenangabe
        };
        
        let newJsonStr = JSON.stringify(obj); 
        document.open();
        document.write('<a href="news.json">' + newJsonStr + '</a>');
        document.close();
    }
    
}

class projects extends article {
    constructor(content, titel, titelfarbe, startdatum, enddatum, professor, plaetze) {
        super(content, titel, titelfarbe, startdatum, enddatum);
        this.professor = professor;
        this.plaetze = plaetze;
    }
    
    get content() {
        return this.content;
    }
    set content(param) {
        this.content = param;
    }
    get titel() {
        return this.titel;
    }
    set titel(param) {
        this.titel = param;   
    }
    get titelfarbe() {
        return this.titelfarbe;
    }
    set titelfarbe(param) {
        this.titelfarbe = param; 
    }
    get startdatum() {
        return this.startdatum;
    }
    set startdatum(param) {
        this.startdatum = param;
    }
    get enddatum() {
        return this.enddatum;
    }
    set enddatum(param) {
        this.enddatum = param;
    }
    get professor() {
        return this.professor;
    }
    set professor(param) {
        this.professor = param;
    }
    get plaetze() {
        return this.plaetze;
    }
    set plaetze(param) {
        this.plaetze = param;
    }
    
    jsonSchreiben(){
        let obj = {
            attr1 : content,
            attr2 : titel,
            attr3 : titelfarbe,
            attr4 : startdatum,
            attr5 : enddatum,
            attr6 : professor,
            attr7 : plaetze
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
    
    get content() {
        return this.content;
    }
    set content(param) {
        this.content = param;
    }
    get titel() {
        return this.titel;
    }
    set titel(param) {
        this.titel = param;   
    }
    get titelfarbe() {
        return this.titelfarbe;
    }
    set titelfarbe(param) {
        this.titelfarbe = param; 
    }
    get startdatum() {
        return this.startdatum;
    }
    set startdatum(param) {
        this.startdatum = param;
    }
    get enddatum() {
        return this.enddatum;
    }
    set enddatum(param) {
        this.enddatum = param;
    }
    get fach() {
        return this.fach;
    }
    set fach(param) {
        this.fach = param;
    }
    
    jsonSchreiben(){
        let obj = {
            attr1 : content,
            attr2 : titel,
            attr3 : titelfarbe,
            attr4 : startdatum,
            attr5 : enddatum,
            attr6 : fach
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
/*
var news1 = new news("Hallo hier wohnt ein Igel","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
var news2 = new news("Ich habe keine Lust mehr", "Leben", "#000000", "1997-6-2", "2018-6-1", "unwichtig", "aus meinem Leben");
var porjekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");
var task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");
*/