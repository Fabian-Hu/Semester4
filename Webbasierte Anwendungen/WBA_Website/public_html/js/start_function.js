window.onload = function() {
    setLanguage();
    let url = document.URL;
    let parts = url.split("?")[0].split("#")[0].split("/");
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
            if (side === "tasks" || side === "projects")
                side = side.substring(0, side.length - 1);
            console.log(side);
            loadArticlesByMenu(side);
            break;
    }
    
};

