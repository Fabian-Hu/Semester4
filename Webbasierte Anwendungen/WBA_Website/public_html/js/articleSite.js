/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

let articleConverter2 = new ArticleConverter();

function showArticle(id) {
    article = articleConverter2.jsonToArticle(localStorage.getItem(id));
    if(article !== null) {
        document.getElementById("articleBody").classList.add(article.type);
        document.getElementById("articleTitle").innerHTML = article.title;
        document.getElementById("articleTitle").style = "color: " + article.color + ";";
        document.getElementById("articleContent").innerHTML = article.content;
        document.getElementById("articleFooter").innerHTML = "Start: " + article.start + "<br>Ende: " + article.end;
    }
}

function generateTableOfContents() {
    content = document.getElementById("articleContent");
    headers = content.querySelectorAll("h1, h2, h3, h4, h5, h6");
    
    list = "";
    size = 0;
    height = 0;
    headers.forEach(function(current) {
        if (current.localName[1] > size) {
            list += "<ul>";
            size = parseInt(current.localName[1]);
            height++;
        } else if (current.localName[1] < size) {
            list += "</ul>";
            size = parseInt(current.localName[1]);
            height--;
        }
        list += "<li><a href='#" + current.innerText + "'>" + current.innerText + "</a></li>";
        current.id = current.innerText;
    });
    while (height > 0) {
        list += "</ul>";
        height--;
    }
    document.getElementById("navigationList").innerHTML = list;
}

window.onload = function() {
    let urlParams = new URLSearchParams(window.location.search);
    showArticle(urlParams.get("id"));
    generateTableOfContents();
};


