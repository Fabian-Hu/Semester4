window.onload = function() {
    setLanguage();
    let url = document.URL;
    let parts = url.split("/");
    let side = "index";
    
    switch(side) {
        case "index":
            loadArticles(5);
            break;
        
        case "createNewArticle":
            document.getElementById("articleForm").addEventListener("submit", saveNewArticleToLocalStorage);
            break;
        
        default:
            loadArticlesByMenu(side);
            break;
    }
    
};

