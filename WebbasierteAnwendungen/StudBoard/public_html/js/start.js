window.onload = function() {
    let url = document.URL;
    let parts = url.split("?")[0].split("#")[0].split("/");
    let side = parts[parts.length - 1].split(".")[0];
    
    switch(side) {
        case "index":
            loadArticles(5);
            break;
        
        case "Artikel":
            let urlParams = new URLSearchParams(window.location.search);
            zeigeArtikel(urlParams.get("id"));
            // generateTableOfContents();
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
            if (side === "Aufgaben"){
                loadArticlesByMenu("task");
            }else if (side === "Projekte"){
                loadArticlesByMenu("project");
            }else if (side === "News"){
                loadArticlesByMenu("news");
            }
            
            
            break;
    }
    
};

