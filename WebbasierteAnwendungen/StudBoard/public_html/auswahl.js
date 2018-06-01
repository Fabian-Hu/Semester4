/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function choooose() {
    let type,x;
    x = document.getElementById("form1");
    type = x.elements["artikelTyp"].value;
    localStorage2 = new localStorage2();
    
    if (type === "News"||type === "Neuigkeiten") { 
        news1 = new news(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "kategorie", "quellenangabe");      
        
        localStorage2.articleSchreiben(news1); 
    } else if (type === "Project"||type === "Projekte") {      
        pro1 = new projects(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "professor", "plaetze");
       
        localStorage2.articleSchreiben(pro1);
    } else if (type === "Tasks"|| type === "Aufgabe") {   
        task1 = new tasks(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "fach");
        
        localStorage2.articleSchreiben(task1);
    } else {        
        alert("Oops, something went wrong");
    } 
   
}