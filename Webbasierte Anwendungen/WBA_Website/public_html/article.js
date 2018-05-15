
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

news1 = new News("Weil es unter Obama weiß war: Trump lässt Weißes Haus schwarz streichen", "Washington (dpo) - Der Mann meint es ernst. Donald Trump hat das Weiße Haus heute komplett schwarz streichen lassen. Offenbar will sich der US-Präsident mit Farbänderung" + 
        "von seinem Vorgänger Barack Obama distanzieren, in dessen Amtszeit das Gebäude weiß war. \"Es ist das gute Recht des Präsidenten, seiner Residenz jede Farbe zu verpassen, die er möchte\", rechtfertigt Sarah Huckabee-Sanders, die Sprecherin des Schwarzen Hauses, die überraschende Aktion. \"Wenn Barack Obama ein Weißes Haus bevorzugt, ist das seine Sache. Präsident Trump lässt sich davon sicher nicht beeinflussen." + 
        "Trump selbst äußerte sich noch nicht zu der Farbänderung, sondern zog sich ins neugestaltete Rectangular Office zurück, wo er derzeit Papiere unterzeichnet, um alle von Barack Obama begnadigten Thanksgiving-Truthähne nachträglich töten zu lassen." , 
        "green", "11.05.2018", "12.05.2018", "Politik", "Postillon");

project1 = new Project("Melonen-Tragegriff", "Jeder kennt das: Da steht man am Obstregal, nimmt die Melone und bekommt sie nicht in den Einkaufswagen. Frustrierend und zeitaufwendig. Aber was wäre, wenn Melonen Griffe hätten? Alle hundert Jahre kommt ein Mensch auf so eine Idee.", 
        "red", "08.05.18", "12.05.18", "Prof. Dr. Mike", "10000");

project2 = new Project("Regenbogen-Scheibenwischer", "Für alle, die mehr Farbe in ihrem Leben wollen: https://www.sinn-frei.com/media/2012/17509_006.jpg", "orange", "01.04.2018", "02.04.2018", "Prof.Dr. Karl", "42");

task1 = new Task("Unsichtbarkeit", "Erzähle jedem glaubhaft, dass du unsichtbar bist", "saddlebrown", "12.05.2018", "20.06.2018", "Physik");

