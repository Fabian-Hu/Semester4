/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


function showArticle(id) {   
    jsonUmwandler = new jsonUmwandler();
    article = jsonUmwandler.jsonToArcticle(localStorage.getItem(id));
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
    
    size = 0;
    currentNode = document.createElement("nav");
    
    headers.forEach(function(current) {
        if (current.localName[1] > size) {
            next = document.createElement("ul");
            currentNode.appendChild(next);
            currentNode = next;
            size = parseInt(current.localName[1]);
        } else if (current.localName[1] < size) {
            currentNode = currentNode.parentNode;
            size = parseInt(current.localName[1]);
        }
        item = document.createElement("li");
        link = document.createElement("a");
        link.text = current.innerText;
        link.href = "#" + current.innerText;
        item.appendChild(link);
        currentNode.appendChild(item);
        current.id = current.innerText;
    });
    while (currentNode.parentNode !== null)
        currentNode = currentNode.parentNode;
    navigation = document.getElementById("navigationList");
    navigation.parentNode.insertBefore(currentNode, navigation.nextSibling);
}


