
let articleConverter = new ArticleConverter();

/*let news1_DOM = localStorage.getItem("news/0");
if (news1_DOM) {
    news1 = articleConverter.jsonToArticle(news1_DOM);
} else {
    news1 = new News("Weil es unter Obama weiß war: Trump lässt Weißes Haus schwarz streichen", "Washington (dpo) - Der Mann meint es ernst. Donald Trump hat das Weiße Haus heute komplett schwarz streichen lassen. Offenbar will sich der US-Präsident mit Farbänderung" + 
        "von seinem Vorgänger Barack Obama distanzieren, in dessen Amtszeit das Gebäude weiß war. \"Es ist das gute Recht des Präsidenten, seiner Residenz jede Farbe zu verpassen, die er möchte\", rechtfertigt Sarah Huckabee-Sanders, die Sprecherin des Schwarzen Hauses, die überraschende Aktion. \"Wenn Barack Obama ein Weißes Haus bevorzugt, ist das seine Sache. Präsident Trump lässt sich davon sicher nicht beeinflussen." + 
        "Trump selbst äußerte sich noch nicht zu der Farbänderung, sondern zog sich ins neugestaltete Rectangular Office zurück, wo er derzeit Papiere unterzeichnet, um alle von Barack Obama begnadigten Thanksgiving-Truthähne nachträglich töten zu lassen." , 
        "green", "11.05.2018", "12.05.2018", "Politik", "Postillon");

    localStorage.setItem("news/0", articleConverter.articleToJson(news1));
    console.log("news saved");
}

let project1_DOM = localStorage.getItem("project/0");
if (project1_DOM) {
    project1 = articleConverter.jsonToArticle(project1_DOM);
} else {
    project1 = new Project("Melonen-Tragegriff", "Jeder kennt das: Da steht man am Obstregal, nimmt die Melone und bekommt sie nicht in den Einkaufswagen. Frustrierend und zeitaufwendig. Aber was wäre, wenn Melonen Griffe hätten? Alle hundert Jahre kommt ein Mensch auf so eine Idee.", 
        "red", "08.05.18", "12.05.18", "Prof. Dr. Mike", "10000");
    localStorage.setItem("project/0", articleConverter.articleToJson(project1));
    console.log("project saved");
}

let project2_DOM = localStorage.getItem("project/1");
if (project2_DOM) {
    project2 = articleConverter.jsonToArticle(project2_DOM);
} else {
    project2 = new Project("Regenbogen-Scheibenwischer", "Für alle, die mehr Farbe in ihrem Leben wollen: https://www.sinn-frei.com/media/2012/17509_006.jpg", "orange", "01.04.2018", "02.04.2018", "Prof.Dr. Karl", "42");
    localStorage.setItem("project/1", articleConverter.articleToJson(project2));
    console.log("project saved");
}

let task1_DOM = localStorage.getItem("task/0");
if (task1_DOM) {
    task1 = articleConverter.jsonToArticle(task1_DOM);
} else {
    task1 = new Task("Unsichtbarkeit", "Erzähle jedem glaubhaft, dass du unsichtbar bist", "saddlebrown", "12.05.2018", "20.06.2018", "Physik");
    localStorage.setItem("task/0", articleConverter.articleToJson(task1));
    console.log("task saved");
}
localStorage.setItem("task", "1");
localStorage.setItem("project", "2");
localStorage.setItem("news", "1");
localStorage.setItem("history", "4");
localStorage.setItem("history/0", "task/0");
localStorage.setItem("history/1", "project/1");
localStorage.setItem("history/2", "news/0");
localStorage.setItem("history/3", "project/0");
 */

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
    let articles = localStorage.getItem(menu);
    if (articles) {
        for (let i = 1; i <= articles; i++) {
            let article_JSON = localStorage.getItem(menu + "/" + (articles - i));
            if (article_JSON) {
                let article = articleConverter.jsonToArticle(article_JSON);
                createArticle(article, menu + "/" + (articles - i));
                addToNavgation(article.title, menu + "/" + (articles - i));
            } 
        }
        document.getElementById("articles").removeChild(document.getElementById("example_article"));
    }
}

function loadArticles(num) {
    let history = localStorage.getItem("history");
    if (history) {
        for (i = 1; i <= num; i++) {
            let article_Key = localStorage.getItem("history/" + (history - i));
            let article_JSON = localStorage.getItem(article_Key);
            if (article_JSON) {
                let article = articleConverter.jsonToArticle(article_JSON);
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
