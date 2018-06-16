
class Article {
    constructor(title, content, color, start, end, comments) {
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.end = end;
        this.type = "article";
        this.comments = comments;
    } 
}

class News extends Article {
    constructor(title, content, color, start, end, category, source, comments) {
        super(title, content, color, start, end);
        this.category = category;
        this.source = source;
        this.type = "news";
    }
}

class Project extends Article {
    constructor(title, content, color, start, end, prof, freeJobs, comments) {
        super(title, content, color, start, end);
        this.prof = prof;
        this.freeJobs = freeJobs;
        this.type = "project";
    }
}

class Task extends Article {
    constructor(title, content, color, start, end, subject, comments) {
        super(title, content, color, start, end);
        this.subject = subject;
        this.type = "task";
    }
}