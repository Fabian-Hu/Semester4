/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function generieren(article){
   // let newArticle = document.creatElement("article");
    localStorage2 = new localStorage2();
    let artList = [];
    artList = localStorage2.articleLesen();
    for(let art of artList){
        //let artObj = jsonUmwandler.jsonToArcticle(art);
        console.log(art); // Hier Funktion zum erstellen eines Articel
    }
}

generieren(5);