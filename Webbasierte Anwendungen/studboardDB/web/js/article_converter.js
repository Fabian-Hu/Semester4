
class ArticleConverter {
    
    articleToJson(article) {
        return JSON.stringify(article);
    }
    
    jsonToArticle(json) {
        let article = JSON.parse(json);
        let obj;
        switch(article.type) {
            case "news":
                obj = new News();
                break;
            
            case "task":
                obj = new Task();
                break;
            
            case "project":
                obj = new Project();
                break;
                
            default:
                obj = new Article();
                break;
        }
        for (var key in obj) {
            obj[key] = article[key];
        }
        return obj;
    }
}
