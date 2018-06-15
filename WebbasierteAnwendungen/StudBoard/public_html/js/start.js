window.onload = function() {
    let url = document.URL;
    let parts = url.split("?")[0].split("#")[0].split("/");
    let side = parts[parts.length - 1].split(".")[0];
    
    switch(side) {
        case "index":
            loadArticlesFromServer(5);
            break;
        
        case "Artikel":
            let urlParams = new URLSearchParams(window.location.search);
            zeigeArtikel(urlParams.get("id"));
            document.getElementById("commentForm").addEventListener("submit", function(event) {
                event.preventDefault();
                saveComment();
            });
            console.log("Lade Comments...");
            loadComments(urlParams.get("id"));
            console.log("fertig");
            break;
        
        default:
            if (side === "Aufgaben"){
                loadSpecialArticlesFromServer(5,"Task");
            }else if (side === "Projekte"){
                loadSpecialArticlesFromServer(5,"Projects");
            }else if (side === "News"){
                loadSpecialArticlesFromServer(5,"News");
            } 
            break;
    }
    
};
