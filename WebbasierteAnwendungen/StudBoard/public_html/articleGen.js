


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
    jsonUmwandler = new jsonUmwandler();
    let articles = localStorage.getItem(menu);
    if (articles) {
        for (let i = 1; i <= articles; i++) {
            let article_JSON = localStorage.getItem(menu + "/" + (articles - i));
            if (article_JSON) {
                let article = jsonUmwandler.jsonToArcticle(article_JSON);
                createArticle(article, menu + "/" + (articles - i));
                addToNavgation(article.title, menu + "/" + (articles - i));
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
