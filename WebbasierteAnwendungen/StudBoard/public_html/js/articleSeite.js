/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function zeigeArtikel(id) {   
    jsonUmwandler = new jsonUmwandler();
    article = jsonUmwandler.jsonToArcticle(localStorage.getItem(id));
    if(article !== null) {
        document.getElementById("articleBody").classList.add(article.type);
        document.getElementById("articleTitle").innerHTML = article.titel;
        document.getElementById("articleTitle").style = "color: " + article.titelfarbe + ";";
        document.getElementById("articleContent").innerHTML = article.content;
        document.getElementById("articleFooter").innerHTML = "Start: " + article.startdatum + "<br>Ende: " + article.enddatum;
    }
}

