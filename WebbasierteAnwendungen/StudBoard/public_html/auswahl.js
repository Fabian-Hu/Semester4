/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function choooose() {
    let type,x,article1;
    x = document.getElementById("form1");
    type = x.elements["artikelTyp"].value;
    
    jsonUmwandler = new jsonUmwandler();
    alert("hallo");
    //alert(x.elements["artikelText"].value);
    //alert(x.elements["artikelTitel"].value);
    //alert(x.elements["titelFarbe"].value);
    //alert(x.elements["startdatum"].value);
    //alert(x.elements["enddatum"].value);
    
    if (type === "News"||type === "Neuigkeiten") { 
        news1 = new news(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "kategorie", "quellenangabe");
        
        news1.ausgabe();
        let string = jsonUmwandler.articleToJson(news1);
        
        articleSchreiben(news1);
    } else if (type === "Project"||type === "Projekte") {      
        pro1 = new projects(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "professor", "plaetze");
        console.log("Project");
        articleSchreiben(pro1);
    } else if (type === "Tasks"|| type === "Aufgabe") {   
        task1 = new tasks(x.elements["artikelText"].value, 
        x.elements["artikelTitel"].value, x.elements["titelFarbe"].value,
        x.elements["startdatum"].value, x.elements["enddatum"].value,
        "fach");
        articleSchreiben(task1);
    } else {
        article1 = null;
        alert("Oops, something went wrong");
    } 
   
}