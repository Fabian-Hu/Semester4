/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* global fetch */

function zeigeArtikel(id) {    
    fetch('http://localhost:8080/studboardREST/artikel?id='+id)
        .then(function(response) {
            return response.json();
        })
        .then(function(myJson) {
            document.getElementById("articleBody").classList.add(myJson["type"]);
            document.getElementById("articleTitle").innerHTML = myJson["titel"];
            document.getElementById("articleTitle").style = "color: " + myJson["titelfarbe"] + ";";
            document.getElementById("articleContent").innerHTML = myJson["content"];
            document.getElementById("articleFooter").innerHTML = "Start: " + myJson["startdatum"] + "<br>Ende: " + myJson["enddatum"];
    });
}

