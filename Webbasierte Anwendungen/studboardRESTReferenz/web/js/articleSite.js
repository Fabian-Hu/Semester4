/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

let articleConverter2 = new ArticleConverter();

function loadArticle(id) {
    jsonArticle = localStorage.getItem(id);
    if(jsonArticle === null) {
        fetch('http://localhost:8080/studboardRESTReferenz/resources/article?id=' + id).then(
            function(response) {
                let res = response.json();
                return res;
            }
        ).then(
            function(jsonData) {
                localStorage.setItem(id, articleConverter2.articleToJson(jsonData)),
                showArticle(jsonData);
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        article = articleConverter2.jsonToArticle(jsonArticle);
        showArticle(article);
    }
}

function showArticle(article) {
    if(article !== null) {
        document.getElementById("articleBody").classList.add(article.type);
        document.getElementById("articleTitle").innerHTML = article.title;
        document.getElementById("articleTitle").style = "color: " + article.color + ";";
        document.getElementById("articleContent").innerHTML = article.content;
        document.getElementById("articleFooter").innerHTML = "Start: " + article.start + "<br>Ende: " + article.end;
        
        if (article.comments !== undefined) {
            article.comments.forEach( function(commentId) {
                loadComment(commentId, article.id);
            })
        }
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


