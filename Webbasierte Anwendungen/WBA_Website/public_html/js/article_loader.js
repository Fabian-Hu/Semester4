
let articleConverter = new ArticleConverter();

function addToNavgation(title, key) {
    let navPoint = document.getElementById("parentNavigation");
    console.log(navPoint);
    let li = document.createElement("li");
    let a = document.createElement("a");
    
    let link = document.createAttribute("href");
    link.value = "#" + key;
    a.attributes.setNamedItem(link);
    a.text = title.substring(0, 20) + "...";
    
    li.appendChild(a);
    navPoint.appendChild(li);
}

function createArticle(article, key){
    let newArticle = document.getElementById("example_article").cloneNode(true);
    console.log(newArticle);
    newArticle.childNodes[1].childNodes[1].firstChild.nodeValue = article.title;
    newArticle.childNodes[3].innerHTML = article.content.substring(0, 400) + "...";
    newArticle.attributes["class"].nodeValue = article.type + " articledesc";
    newArticle.id = key;
    
    if (article.type === "news") {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\article.html?id=" + key;
    } else {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\article.html?id=" + key;
    }
    
    let br = document.createElement("br");
    document.getElementById("example_article").parentNode.appendChild(br);
    document.getElementById("example_article").parentNode.appendChild(newArticle);
}

function loadArticlesByMenu(menu) {
    let articles = localStorage.getItem(menu);
    if (articles) {
        for (let i = 1; i <= articles; i++) {
            let article_JSON = localStorage.getItem(menu + "/" + (articles - i));
            if (article_JSON) {
                let article = articleConverter.jsonToArticle(article_JSON);
                createArticle(article, menu + "/" + (articles - i));
                addToNavgation(article.title, menu + "/" + (articles - i));
            } 
        }
        document.getElementById("articles").removeChild(document.getElementById("example_article"));
    }
}

function loadSpecialArticlesFromServer(article) {
    fetch('http://localhost:8080/studfileserver/articles/' + article + '/history.json').then(
        function(response) {
            let res = response.json();
            console.log("history");
            return res;
        }
    ).then(
        function(jsonData) {
            console.log(jsonData);
            for (let i = 0; i < jsonData.length; i++) {
                getArticle(jsonData[i]);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

function loadArticlesFromServer(num) {
    fetch('http://localhost:8080/studfileserver/articles/history.json').then(
        function(response) {
            let res = response.json();
            console.log("history");
            return res;
        }
    ).then(
        function(jsonData) {
            console.log(jsonData);
            for (let i = 1; i <= num; i++) {
                if (jsonData.length - i > 0)
                    getArticle(jsonData[jsonData.length - i]);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

var getArticle = function(file) {
    let path = 'http://localhost:8080/studfileserver/articles/' + file + '.json';
    fetch(path).then(
        function(response) {
            let res = response.json();
            console.log(res);
            return res;
        }
    ).then(
        function(jsonData) {
            console.log(jsonData);
            createArticle(jsonData, jsonData.type + '/' + file);
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

let taskNum = localStorage.getItem("task");
if (!taskNum) {
    localStorage.setItem("task", "0");
}

let projectsNum = localStorage.getItem("project");
if (!projectsNum) {
    localStorage.setItem("project", "0");
}

let newsNum = localStorage.getItem("news");
if (!newsNum) {
    localStorage.setItem("news", "0");
}

let historyNum = localStorage.getItem("history");
if (!historyNum) {
    localStorage.setItem("history", "0");
}
