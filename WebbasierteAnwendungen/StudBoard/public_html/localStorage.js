/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
if (typeof(Storage) !== "undefined") {
    let visits = localStorage.getItem("visits"); 
    if(visits) {   
        visitsNo = parseInt(visits); 
        visitsNo++; 
        localStorage.setItem("visits",visitsNo);
        if(visitsNo>5) { 
            localStorage.removeItem("visits"); 
        } 
    } else {
        localStorage.setItem("visits",1); 
    } 
    console.log("This is your " + localStorage.getItem("visits") + " visit"); 
} else { 
    console.log("Sorry! No Web Storage support.."); 
}*/
 
function newsLesen(){ 
    if (typeof(Storage) !== "undefined") {  
        let news = [];
        let i=1;
        while(true){
            string1 = "news"+i; 
            news[i] = localStorage.getItem(string1);         
            if(news[i]){
                let newsObj = jsonUmwandler.jsonToArcticle(news[i]);
                console.log(newsObj); // Hier Funktion zum erstellen eines Articel
                i++;
            }else {
                break;
            }
        }
    } else { 
        console.log("Sorry! No Web Storage support.."); 
    }
}

function taskLesen(){ 
    if (typeof(Storage) !== "undefined") {  
        let task = [];
        let i=1;
        while(true){
            string1 = "task"+i; 
            task[i] = localStorage.getItem(string1);         
            if(task[i]){
                let proObj = jsonUmwandler.jsonToArcticle(task[i]);
                console.log(proObj); // Hier Funktion zum erstellen eines Articel
                i++;
            }else {
                break;
            }
        }
    } else { 
        console.log("Sorry! No Web Storage support.."); 
    }
}

function proLesen(){ 
    if (typeof(Storage) !== "undefined") {  
        let pro = [];
        let i=1;
        while(true){
            string1 = "pro"+i; 
            pro[i] = localStorage.getItem(string1);         
            if(pro[i]){
                let proObj = jsonUmwandler.jsonToArcticle(pro[i]);
                console.log(proObj); // Hier Funktion zum erstellen eines Articel
                i++;
            }else {
                break;
            }
        }
    } else { 
        console.log("Sorry! No Web Storage support.."); 
    }
}

function articleSchreiben(obj){   
    let i=1;
    if(obj.type === "News"){          
        while(true){
            string1 = "news"+i; 
            let news = localStorage.getItem(string1);         
            if(news){
                i++;
            }else {
                break;
            }        
        }
        string1 = "news"+i; 
        string = jsonUmwandler.articleToJson(obj);
        localStorage.setItem(string1,string);
        console.log(i);
    } else if(obj.type === "Projects"){
        while(true){
            string1 = "pro"+i; 
            let pro = localStorage.getItem(string1);         
            if(pro){
                i++;
            }else {
                break;
            }        
        }
        string1 = "pro"+i; 
        string = jsonUmwandler.articleToJson(obj);
        localStorage.setItem(string1,string);
        console.log(i);
    } else if(obj.type === "Tasks"){
        while(true){
            string1 = "task"+i; 
            let task = localStorage.getItem(string1);         
            if(task){
                i++;
            }else {
                break;
            }        
        }
        string1 = "task"+i; 
        string = jsonUmwandler.articleToJson(obj);
        localStorage.setItem(string1,string);
        console.log(i);
    } else {
        console.log("Falsches Objekt übergeben");
    }
}

let news12 = new news("Hallo","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
let task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");
let projekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");

jsonUmwandler = new jsonUmwandler();
//articleSchreiben(projekt1); // ACHTUNG! Doppel einträge
//localStorage.removeItem("news3"); //ACHTUNG! Wenn du mittten drin was löscht wird nur noch bis dort angezeigt 
console.log("News:");
newsLesen();
console.log("Project:");
proLesen();
console.log("Task:");
taskLesen();