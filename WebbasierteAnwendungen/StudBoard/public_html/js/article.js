/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
class article {
    constructor(content, titel, titelfarbe, startdatum, enddatum) {
        this.content = content;
        this.titel = titel;
        this.titelfarbe = titelfarbe;
        this.startdatum = startdatum;
        this.enddatum = enddatum;
        this.type = "Article";
    }
    
    ausgabe(){
        alert(this.content);
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
