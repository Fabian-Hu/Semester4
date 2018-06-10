
/* global fetch */

function createArticle(article, key){
    let newArticle = document.getElementById("example_article").cloneNode(true);
    console.log(newArticle);
    newArticle.childNodes[1].childNodes[1].firstChild.nodeValue = article.titel;
    newArticle.childNodes[3].innerHTML = article.content.substring(0, 400) + "...";
    newArticle.attributes["class"].nodeValue = article.type;
    newArticle.id = key;
    
    if (article.type === "News") {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\Artikel.html?id=" + key;
    } else {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\Artikel.html?id=" + key;
    }
    
    let br = document.createElement("br");
    document.getElementById("example_article").parentNode.appendChild(br);
    document.getElementById("example_article").parentNode.appendChild(newArticle);
}

function loadArticlesByMenu(menu) {
    jsonUmwandler = new jsonUmwandler();
    let articles = localStorage.getItem(menu);
    if (articles) {
        for (let i = 1; i <= articles; i++) {
            let article_JSON = localStorage.getItem(menu + "/" + (articles - i));
            if (article_JSON) {
                let article = jsonUmwandler.jsonToArcticle(article_JSON);
                createArticle(article, menu + "/" + (articles - i));
                //addToNavgation(article.title, menu + "/" + (articles - i));
            } 
        }
        document.getElementById("articles").removeChild(document.getElementById("example_article"));
    }
}

function loadArticles(num) {   
    jsonUmwandler = new jsonUmwandler();
    let history = localStorage.getItem("history");
    if (history) {
        for (i = 1; i <= num; i++) {
            let article_Key = localStorage.getItem("history/" + (history - i));
            let article_JSON = localStorage.getItem(article_Key);
            if (article_JSON) {
                let article = jsonUmwandler.jsonToArcticle(article_JSON);
                createArticle(article, article_Key);
            } 
        }
        document.getElementById("articles").removeChild(document.getElementById("example_article"));
    }
}

function loadArticlesFromServer(num) {
    fetch('http://localhost:8080/studfileserver/Artikel/history.json').then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for (let i = 1; i <= num; i++) {
                if (jsonData.length - i >= 0) {
                    getArticle(jsonData[jsonData.length - i]);
                }
            }
            document.getElementById("example_article").style.display = "none";
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

function loadSpecialArticlesFromServer(article) {
    fetch('http://localhost:8080/studfileserver/Artikel/' + article + '/history.json').then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for (let i = 0; i < jsonData.length; i++) {
                getArticle(jsonData[i]);
            }
            document.getElementById("example_article").style.display = "none";
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

var getArticle = function(file) {
    jsonUmwandler = new jsonUmwandler();
    let filename = file.split('/');
    console.log(filename);
    let articleNum = localStorage.getItem(filename[0]);
    if (!articleNum || articleNum < parseInt(filename[1]) + 1) {
        localStorage.setItem(filename[0], parseInt(filename[1]) + 1);
    }
    let articleJson = localStorage.getItem(file);
    if (articleJson === null) {
        let path = 'http://localhost:8080/studfileserver/Artikel/' + file + '.json';
        fetch(path).then(
            function(response) {
                let res = response.json();
                return res;
            }
        ).then(
            function(jsonData) {
                createArticle(jsonData, file);
                localStorage.setItem(file, jsonUmwandler.articleToJson(jsonData));
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        createArticle(jsonUmwandler.jsonToArticle(articleJson), file);
    }
};