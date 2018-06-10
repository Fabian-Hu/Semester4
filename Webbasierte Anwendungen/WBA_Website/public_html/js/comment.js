/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

class Comment {
    constructor(text, rating, file) {
        this.text = text;
        this.rating = rating;
        this.file = file;
    }
}

var saveComment = function() {
    text = document.getElementById("text").value;
    attachment = document.getElementById("attachment").value;
    radioButtons = document.getElementsByName("rate");
    rating = 0;
    for(var i = 0; i < radioButtons.length; i++) {
        if (radioButtons[i].checked) {
            rating = radioButtons[i].value;
        }
    }
    comment = new Comment(text, rating, attachment);
    urlParams = new URLSearchParams(window.location.search);
    count = localStorage.getItem("comment/" + urlParams.get("id"));
    if (count === null)
        count = 0;
    
    localStorage.setItem("comment/" + urlParams.get("id") + "/" + count, JSON.stringify(comment));
    
    localStorage.setItem("comment/" + urlParams.get("id"), parseInt(count) + 1);
    showComment("comment/" + urlParams.get("id") + "/" + count);
};

function showComment(comment) {
    article = document.createElement("article");
    p1 = document.createElement("p");

    p1.innerHTML = comment.text + "<br><br>Anhang: " + comment.file + "<br><br>Bewertung: " + comment.rating + "/5";

    article.appendChild(document.createElement("hr"));
    article.appendChild(p1);
    document.getElementById("comments").appendChild(article);
}

function loadComment(file) {
    comment_JSON = localStorage.getItem(file);;
    if (comment_JSON === null) {
        let path = 'http://localhost:8080/studfileserver/' + file + '.json';
        fetch(path).then(
            function(response) {
                let res = response.json();
                return res;
            }
        ).then(
            function(jsonData) {
                showComment(jsonData, file);
                localStorage.setItem(file, JSON.stringify(jsonData));
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        showComment(JSON.parse(comment_JSON), file);
    }
}

function loadComments() {
    urlParams = new URLSearchParams(window.location.search);
    num = parseInt(localStorage.getItem("comment/" + urlParams.get("id")));
    if(num) {
        for(i = 0; i < num; i++) {
            showComment("comment/" + urlParams.get("id") + "/" + i);
        }
    }
    fetch('http://localhost:8080/studfileserver/comment/' + urlParams.get("id") + '.json').then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for (let i = 0; i < jsonData; i++) {
                loadComment('comment/' + urlParams.get("id") + "/" + i);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}