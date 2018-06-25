
class Article {
    constructor(title, content, color, start, end) {
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.ende = end;
        this.type = "article";
        this.id = 42;
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