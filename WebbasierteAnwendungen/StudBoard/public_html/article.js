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