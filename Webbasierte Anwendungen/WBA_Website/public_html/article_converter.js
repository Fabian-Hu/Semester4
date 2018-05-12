
class ArticleConverter {
    
    articleToJson(article) {
        return JSON.stringify(article);
    }
    
    jsonToArticle(json) {
        let article = JSON.parse(json);
        switch(article.type) {
            case "news":
                return new News(article);
                break;
            
            case "task":
                return new Task(article);
                break;
            
            case "project":
                return new Project(article);
                break;
                
            default:
                return new Article(article);
                break;
        }
    }
}

articleConverter = new ArticleConverter();
let articleStr = articleConverter.articleToJson(task1);
console.log(articleStr);
let article1 = articleConverter.jsonToArticle(articleStr);
console.log(article1.constructor.name);
