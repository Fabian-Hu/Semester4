/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

let articleConverter = new ArticleConverter();

function showArticle(id) {
    article = articleConverter.jsonToArticle(localStorage.getItem(id));
    document.getElementById("articleBody").class += article.type;
    document.getElementById("articleTitel").innerHTML = article.title;
    document.getElementById("articleTitel").style = "color: " + article.color + ";";
    document.getElementById("articleContent").innerHTML = article.text;
    document.getElementById("articleStart").innerHTML = "Start: " + article.start;
    document.getElementById("articleEnd").innerHTML = "Ende: " + article.end;    
}

window.onload = function() {
    let urlParams = new URLSearchParams(window.location.search);
    showArticle(urlParams.get("id"));
};


