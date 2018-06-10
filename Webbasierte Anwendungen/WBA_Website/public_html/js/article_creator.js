/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
let articleConverter = new ArticleConverter();

var saveNewArticleToLocalStorage = function(event) {
    event.prevent.preventDefault();
    let typeSelector = document.getElementById("artikelTyp").value;
    let titel = document.getElementById("artikelTitel").value;
    let text = document.getElementById("artikelText").value;
    let start = document.getElementById("artikelStartdatum").value;
    let ende = document.getElementById("artikelEnddatum").value;
    let farbe = document.getElementById("artikelTitelfarbe").value;
    let article;
    let key;
    let id = 0;
    switch(typeSelector) {
        case "News":
            id = localStorage.getItem("news");
            if (id === null) {
                id = 0;
            }
            key = "news/" + id;
            localStorage.setItem("news", parseInt(id) + 1);
            article = new News(titel, text, farbe, start, ende, "", "");
            break;
        case "Projekt":
            id = localStorage.getItem("project");
            if (id === null) {
                id = 0;
            }
            key = "project/" + id;
            localStorage.setItem("project", parseInt(id) + 1);
            article = new Project(titel, text, farbe, start, ende, "", "");
            break;
        case "Aufgabe":
            id = localStorage.getItem("task");
            if (id === null) {
                id = 0;
            }
            key = "task/" + id;
            localStorage.setItem("task", parseInt(id) + 1);
            article = new Task(titel, text, farbe, start, ende, "", "");
            break;
    }
    localStorage.setItem(key, articleConverter.articleToJson(article));
    sendArticleToServer(key, articleConverter.articleToJson(article)).then(
            function(data) {
                console.log(data);
            }
        ).catch(error => console.error(error));
    
};

function sendArticleToServer(key, article) {
    console.log('hallo');
    return fetch('http://localhost:8080/studfileserver/' + key + '.json', {
        body: article,
        cache: 'no-cache',
        credentials: 'same-origin',
        headers: {
            'content-type': 'application/json'
        },
        method: 'POST',
        mode: 'cors',
        redirect: 'follow',
        referrer: 'no-referrer'
    }).then(response => response.json());
}
