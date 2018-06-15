/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* global fetch */

class Comment {
    constructor(text, rating, file) {
        this.text = text;
        this.rating = rating;
        this.file = file;
    }
}

function showComment(json) {   
    console.log(json);
    article = document.createElement("article");
    p1 = document.createElement("p");
    p1.innerHTML = json["text"] + "<br><br>Anhang: " + json["file"] + "<br><br>Bewertung: " + json["rating"];
    article.appendChild(document.createElement("hr"));
    article.appendChild(p1);
    document.getElementById("comments").appendChild(article);
    
}

var saveComment = function () {
    text = document.getElementById("text").value;
    attachment = document.getElementById("attachment").value;
    radioButtons = document.getElementsByName("rate");
    rating = 0;
    for (var i = 0; i < radioButtons.length; i++) {
        if (radioButtons[i].checked) {
            rating = radioButtons[i].value;
        }
    }
    comment = new Comment(text, rating+"/5", attachment);
    urlParams = new URLSearchParams(window.location.search);
    count = localStorage.getItem("comment/" + urlParams.get("id"));
    if (count === null)
        count = 0;

    localStorage.setItem("comment/" + urlParams.get("id") + "/" + count, JSON.stringify(comment));

    localStorage.setItem("comment/" + urlParams.get("id"), parseInt(count) + 1);
    alert(JSON.parse(JSON.stringify(comment)));
    showComment(JSON.parse(JSON.stringify(comment)));
    
    fetch("http://localhost:8080/studboardREST/comment/erstellen", {
        method: 'POST', // *GET, PUT, DELETE, etc. 
        body: JSON.stringify(comment), // must match 'Content-Type' header 
        headers: {
            'content-type': 'application/json'
        }  
    }).then(function (res){ // parses response to JSON 
        console.log(res.text());
    });

};

function loadComments(id) {
    fetch('http://localhost:8080/studboardREST/comment/liste?id='+id).then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            for(i=0;i<jsonData.length;i++){
                showComment(jsonData[i]);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}





/*
function showComment(id) {
    console.log("Kommentar ID: "+id);
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
    if(!num)
        num = 0;
    let com = urlParams.get("id");
    console.log(com);
    fetch('http://localhost:8080/studfileserver/comment/' + com + '.json').then(
        function(response) {
            let res = response.json();
            return res;
        }
    ).then(
        function(jsonData) {
            console.log(jsonData);
            if (num < jsonData) {
                num = jsonData;
                localStorage.setItem("comment/" + urlParams.get("id"), num);
            }
            for (let i = 0; i < num; i++) {
                loadComment('comment/' + urlParams.get("id") + "/" + i);
            }
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}

function loadComment(file) {
    comment_JSON = localStorage.getItem(file);
    if (comment_JSON === null) {
        let path = 'http://localhost:8080/studfileserver/' + file + '.json';
        fetch(path).then(
            function(response) {
                let res = response.json();
                
                return res;
            }
        ).then(
            function(jsonData) {
                showComment(file);
                localStorage.setItem(file, JSON.stringify(jsonData));
            }
        ).catch(
            function(err) {
                console.log("error: " + err);
            }
        );
    } else {
        
        showComment(file);
    }
}*/