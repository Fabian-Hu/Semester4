
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
    newArticle.childNodes[1].childNodes[1].firstChild.nodeValue = article.title;
    newArticle.childNodes[3].innerHTML = article.content.substring(0, 400) + "...";
    newArticle.attributes["class"].nodeValue = article.type + " articledesc";
    newArticle.style.display = "block";
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

function loadSpecialArticlesFromServer(article) {
    fetch('http://localhost:8080/studfileserver/articles/' + article + '/history.json').then(
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

function loadArticlesFromServer(num) {
    fetch('http://localhost:8080/studfileserver/articles/history.json').then(
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

var getArticle = function(file) {
    let filename = file.split('/');
    console.log(filename);
    let articleNum = localStorage.getItem(filename[0]);
    if (!articleNum || articleNum < parseInt(filename[1]) + 1) {
        localStorage.setItem(filename[0], parseInt(filename[1]) + 1);
    }
    let articleJson = localStorage.getItem(file);
    if (articleJson === null) {
        let path = 'http://localhost:8080/studfileserver/articles/' + file + '.json';
        fetch(path).then(
            function(response) {
                let res = response.json();
                return res;
            }
        ).then(
            function(jsonData) {
                createArticle(jsonData, file);
                localStorage.setItem(file, articleConverter.articleToJson(jsonData));
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        createArticle(articleConverter.jsonToArticle(articleJson), file);
    }
};
