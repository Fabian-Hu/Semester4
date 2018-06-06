/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class jsonUmwandler {
    constructor(){
        
    }
    
    articleToJson(article) {
        return JSON.stringify(article);
    }
    
    jsonToArcticle(json){
        let jsonObj = JSON.parse(json);   
        if(jsonObj["type"] === "News"){
            return new news(jsonObj["content"],jsonObj["titel"],jsonObj["titelfarbe"],jsonObj["startdatum"],jsonObj["enddatum"],jsonObj["kategorie"],jsonObj["quellenangabe"]);
        } else if(jsonObj["type"] === "Projects"){
            return new projects(jsonObj["content"],jsonObj["titel"],jsonObj["titelfarbe"],jsonObj["startdatum"],jsonObj["enddatum"],jsonObj["professor"],jsonObj["plaetze"]);
        } else if(jsonObj["type"] === "Tasks"){
            return new tasks(jsonObj["content"],jsonObj["titel"],jsonObj["titelfarbe"],jsonObj["startdatum"],jsonObj["enddatum"],jsonObj["fach"]);
        } else {
            // ERROR
        }
    }
}

/*
var news1 = new news("Hallo hier wohnt ein Igel","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
var news2 = new news("Ich habe keine Lust mehr", "Leben", "#000000", "1997-6-2", "2018-6-1", "unwichtig", "aus meinem Leben");
var projekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");
var task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");


let string = jsonUmwandler.articleToJson(news1);
console.log(string);

let article1 = jsonUmwandler.jsonToArcticle(string);
console.log(article1);*/