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

function showComment(id) {
    comment_JSON = localStorage.getItem(id);
    if(comment_JSON) {
        comment = JSON.parse(comment_JSON);
        article = document.createElement("article");
        p1 = document.createElement("p");
        
        p1.innerHTML = comment.text + "<br><br>Anhang: " + comment.file + "<br><br>Bewertung: " + comment.rating + "/5";
        
        article.appendChild(document.createElement("hr"));
        article.appendChild(p1);
        document.getElementById("comments").appendChild(article);
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
}