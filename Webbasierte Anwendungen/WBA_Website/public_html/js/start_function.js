window.onload = function() {
    setLanguage();
    let url = document.URL;
    let parts = url.split("#")[0].split("/");
    console.log(parts[parts.length - 1].split(".")[0]);
    let side = parts[parts.length - 1].split(".")[0];
    
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

