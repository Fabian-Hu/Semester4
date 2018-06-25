window.onload = function() {
    setLanguage();
    let url = document.URL;
    let parts = url.split("?")[0].split("#")[0].split("/");
    let side = parts[parts.length - 1].split(".")[0];
    getLogo();
    
    switch(side) {
        case "":
            loadArticlesFromServer(5);
            break;
            
        case "index":
            loadArticlesFromServer(5);
            break;
        
        case "article":
            let urlParams = new URLSearchParams(window.location.search);
            loadArticle(urlParams.get("id"));
            generateTableOfContents();
            document.getElementById("commentForm").addEventListener("submit", function(event) {
                event.preventDefault();
                saveComment();
            });
            loadComments();
            break;
        
        case "createNewArticle":
            document.getElementById("articleForm").addEventListener("submit", function(event) {
                event.preventDefault();
                saveNewArticleToLocalStorage();
            });
            break;
        
        default:
            if (side === "tasks" || side === "projects")
                side = side.substring(0, side.length - 1);
            console.log(side);
            loadSpecialArticlesFromServer(side);
            break;
    }
    
};

