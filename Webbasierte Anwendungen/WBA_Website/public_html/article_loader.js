
articleConverter = new ArticleConverter();

let news1_DOM = localStorage.getItem("news/1");
if (news1_DOM) {
    news1 = articleConverter.jsonToArticle(news1_DOM);
} else {
    news1 = new News("Weil es unter Obama weiß war: Trump lässt Weißes Haus schwarz streichen", "Washington (dpo) - Der Mann meint es ernst. Donald Trump hat das Weiße Haus heute komplett schwarz streichen lassen. Offenbar will sich der US-Präsident mit Farbänderung" + 
        "von seinem Vorgänger Barack Obama distanzieren, in dessen Amtszeit das Gebäude weiß war. \"Es ist das gute Recht des Präsidenten, seiner Residenz jede Farbe zu verpassen, die er möchte\", rechtfertigt Sarah Huckabee-Sanders, die Sprecherin des Schwarzen Hauses, die überraschende Aktion. \"Wenn Barack Obama ein Weißes Haus bevorzugt, ist das seine Sache. Präsident Trump lässt sich davon sicher nicht beeinflussen." + 
        "Trump selbst äußerte sich noch nicht zu der Farbänderung, sondern zog sich ins neugestaltete Rectangular Office zurück, wo er derzeit Papiere unterzeichnet, um alle von Barack Obama begnadigten Thanksgiving-Truthähne nachträglich töten zu lassen." , 
        "green", "11.05.2018", "12.05.2018", "Politik", "Postillon");

    localStorage.setItem("news/1", articleConverter.articleToJson(news1));
    console.log("news saved");
}

let project1_DOM = localStorage.getItem("project/1");
if (project1_DOM) {
    project1 = articleConverter.jsonToArticle(project1_DOM);
} else {
    project1 = new Project("Melonen-Tragegriff", "Jeder kennt das: Da steht man am Obstregal, nimmt die Melone und bekommt sie nicht in den Einkaufswagen. Frustrierend und zeitaufwendig. Aber was wäre, wenn Melonen Griffe hätten? Alle hundert Jahre kommt ein Mensch auf so eine Idee.", 
        "red", "08.05.18", "12.05.18", "Prof. Dr. Mike", "10000");
    localStorage.setItem("project/1", articleConverter.articleToJson(project1));
    console.log("project saved");
}

let project2_DOM = localStorage.getItem("project/2");
if (project2_DOM) {
    project2 = articleConverter.jsonToArticle(project2_DOM);
} else {
    project2 = new Project("Regenbogen-Scheibenwischer", "Für alle, die mehr Farbe in ihrem Leben wollen: https://www.sinn-frei.com/media/2012/17509_006.jpg", "orange", "01.04.2018", "02.04.2018", "Prof.Dr. Karl", "42");
    localStorage.setItem("project/2", articleConverter.articleToJson(project2));
    console.log("project saved");
}

let task1_DOM = localStorage.getItem("task/1");
if (task1_DOM) {
    task1 = articleConverter.jsonToArticle(task1_DOM);
} else {
    task1 = new Task("Unsichtbarkeit", "Erzähle jedem glaubhaft, dass du unsichtbar bist", "saddlebrown", "12.05.2018", "20.06.2018", "Physik");
    localStorage.setItem("task/1", articleConverter.articleToJson(task1));
    console.log("task saved");
}

console.log(news1);
console.log(project1);
console.log(project2);
console.log(task1);


