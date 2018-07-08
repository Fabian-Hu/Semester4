
let articleConverter = new ArticleConverter();

function addToNavgation(title, key) {
    $(document).ready(function(){
        $("<li></li>").append($("<a></a>").text(title.substring(0, 20) + "...").attr("href", "#" + key)).appendTo("#parentNavigation");
    });
}

function createArticle(article){
    $(document).ready(function(){
        $("<article></article>").attr({
            "id" : article.id,
            "class" : article.type + " articledesc"
        }).append($("<header></header>").append($("<h2></h2>").text(article.title)))
        .append($("<p></p>").html(article.content + "...")).append($("<br>"))
        .append($("<a></a>").text("Mehr anzeigen...").attr("href", "\article.html?id=" + article.id))
        .appendTo("#articles");
        $("<br>").appendTo(".articles");
    });
    
    addToNavgation(article.title, article.id);
}

function loadSpecialArticlesFromServer(article) {
    fetch('http://localhost:8080/studboardDB/resources/history?count=0&type=' + article).then(
        function(response) {
            return response.json();
        }
    ).then(
        function(jsonData) {
            for (let i = 0; i < jsonData.length; i++) {
                createArticle(jsonData[i]);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

function loadArticlesFromServer(num) {
    fetch('http://localhost:8080/studboardDB/resources/history?count=' + num + '&type=all').then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for (let i = 1; i <= num; i++) {
                if (jsonData.length - i >= 0) {
                    createArticle(jsonData[jsonData.length - i]);
                }
            }
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
