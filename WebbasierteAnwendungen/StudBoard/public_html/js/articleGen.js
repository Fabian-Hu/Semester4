
/* global fetch */

function createArticle(jsonObj){
      
    let newArticle = document.getElementById("example_article").cloneNode(true);
    
    newArticle.childNodes[1].childNodes[1].firstChild.nodeValue = jsonObj["titel"];
    newArticle.childNodes[3].innerHTML = jsonObj["content"].substring(0, 400) + "...";
    newArticle.attributes["class"].nodeValue = jsonObj["type"];
    newArticle.id = jsonObj["id"];
    
    if (jsonObj["type"] === "News") {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\Artikel.html?id=" + jsonObj["id"];
    } else {
        newArticle.childNodes[7].attributes["href"].nodeValue = "\Artikel.html?id=" + jsonObj["id"];
    }
    
    let br = document.createElement("br");
    document.getElementById("example_article").parentNode.appendChild(br);
    document.getElementById("example_article").parentNode.appendChild(newArticle);
}

function loadArticlesFromServer(num) {   
    fetch('http://localhost:8080/studboardREST/artikel/liste?num='+num+"&type=article")
        .then(function(response) {
            return response.json();
        })
        .then(function(myJson) {
            for(i=0;i<myJson.length;i++){
                createArticle(myJson[i]);
            }
            document.getElementById("example_article").style.display = "none";
        });
    
}

function loadSpecialArticlesFromServer(num, type) {
    fetch('http://localhost:8080/studboardREST/artikel/liste?num='+num+"&type="+type)
        .then(function(response) {
            return response.json();
        })
        .then(function(myJson) {
            for(i=0;i<myJson.length;i++){
                createArticle(myJson[i]);
            }
            document.getElementById("example_article").style.display = "none";
        });
}

var getArticle = function(file) {
    json2 = new jsonUmwandler();
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
                localStorage.setItem(file, json2.articleToJson(jsonData));
                createArticle(jsonData, file);
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        console.log(articleJson+", "+file);
        console.log("test");
        let arti = json2.jsonToArcticle(articleJson);
        console.log("tes2t");
        console.log(arti);
        createArticle(arti, file);
    }
};