/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class Comment {
    constructor(text, rating, file, articleId) {
        this.text = text;
        this.rating = rating;
        this.file = file;
        this.articleId = articleId;
    }
}

var saveComment = function() {
    urlParams = new URLSearchParams(window.location.search);
    text = document.getElementById("text").value;
    attachment = document.getElementById("attachment").value;
    radioButtons = document.getElementsByName("rate");
    rating = 0;
    for(var i = 0; i < radioButtons.length; i++) {
        if (radioButtons[i].checked) {
            rating = radioButtons[i].value;
        }
    }
    comment = new Comment(text, rating, attachment, urlParams.get("id"));
    urlParams = new URLSearchParams(window.location.search);
    count = localStorage.getItem("comment/" + urlParams.get("id"));
    if (count === null)
        count = 0;
    
    //localStorage.setItem("comment/" + urlParams.get("id") + "/" + count, JSON.stringify(comment));
    
    //localStorage.setItem("comment/" + urlParams.get("id"), parseInt(count) + 1);
    showComment(comment);
    
    fetch('http://localhost:8080/studboardDB/resources/comment/create', {
        body: JSON.stringify(comment),
        cache: 'no-cache',
        credentials: 'same-origin',
        headers: {
            'content-type': 'application/json'
        },
        method: 'POST',
        mode: 'cors',
        redirect: 'follow',
        referrer: 'no-referrer'
    }).then (function(response) {
       console.log(response.text());
    });
};

function showComment(comment) {
    article = document.createElement("article");
    p1 = document.createElement("p");

    p1.innerHTML = comment.text + "<br><br>Anhang: " + comment.file + "<br><br>Bewertung: " + comment.rating + "/5";

    article.appendChild(document.createElement("hr"));
    article.appendChild(p1);
    document.getElementById("comments").appendChild(article);
}

function loadComment(id, articleId) {
    comment_JSON = localStorage.getItem(articleId + "/" + id);;
    if (comment_JSON === null) {
        let path = 'http://localhost:8080/studboardDB/resources/comment?id=' + id;
        fetch(path).then(
            function(response) {
                let res = response.json();
                return res;
            }
        ).then(
            function(jsonData) {
                showComment(jsonData);
                localStorage.setItem(articleId + "/" + id, JSON.stringify(jsonData));
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        showComment(JSON.parse(comment_JSON));
    }
}

function loadComments() {
    urlParams = new URLSearchParams(window.location.search);
    fetch('http://localhost:8080/studboardDB/resources/comments?articleId=' + urlParams.get("id")).then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for (let i = 0; i < jsonData.length; i++) {
                showComment(jsonData[i]);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}