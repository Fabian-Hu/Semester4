
class Article {
    constructor(title, content, color, start, end) {
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.end = end;
        this.type = "article";
    } 
}

class News extends Article {
    constructor(title, content, color, start, end, category, source) {
        super(title, content, color, start, end);
        this.category = category;
        this.source = source;
        this.type = "news";
    }
}

class Project extends Article {
    constructor(title, content, color, start, end, prof, freeJobs) {
        super(title, content, color, start, end);
        this.prof = prof;
        this.freeJobs = freeJobs;
        this.type = "project";
    }
}

class Task extends Article {
    constructor(title, content, color, start, end, subject) {
        super(title, content, color, start, end);
        this.subject = subject;
        this.type = "task";
    }
}

let articleConverter = new ArticleConverter();

function showArticle(id) {
    article = articleConverter.jsonToArticle(localStorage.getItem(id));
    document.getElementById("articleBody").class += article.type;
    document.getElementById("articleTitel").innerHTML = article.title;
    document.getElementById("articleTitel").style = "color: " + article.color + ";";
    document.getElementById("articleContent").innerHTML = article.text;
    document.getElementById("articleStart").innerHTML = "Start: " + article.start;
    document.getElementById("articleEnd").innerHTML = "Ende: " + article.end;    
}

window.onload = function() {
    let urlParams = new URLSearchParams(window.location.search);
    showArticle(urlParams.get("id"));
};