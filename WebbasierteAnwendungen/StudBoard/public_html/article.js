/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


class aritcle {
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

class news extends aricle {
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
    
}

class projects extends aricle {
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
}

class tasks extends aricle {
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
    
}