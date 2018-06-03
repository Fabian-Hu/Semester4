window.onload = function() {
    let url = document.URL;
    let parts = url.split("?")[0].split("#")[0].split("/");
    let side = parts[parts.length - 1].split(".")[0];
    
    switch(side) {
        case "index":
            loadArticles(5);
            break;
        
        case "article":
            let urlParams = new URLSearchParams(window.location.search);
            showArticle(urlParams.get("id"));
            generateTableOfContents();
            document.getElementById("commentForm").addEventListener("submit", function(event) {
                event.preventDefault();
                saveComment();
            });
            loadComments();
            break;
        
        /*case "NeuerArtikel":
            document.getElementById("articleForm").addEventListener("submit", saveNewArticleToLocalStorage);
            break;*/
        
        default:
            if (side === "Aufgaben" || side === "Projekte" || side === "News")
                side = side.substring(0, side.length - 1);
            console.log(side);
            loadArticlesByMenu(side);
            break;
    }
    
};

