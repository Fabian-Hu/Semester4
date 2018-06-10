/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


class localStorage2 {
     
    articleSchreiben(obj){  
        
        jsonUmwandler = new jsonUmwandler();
        let key;
        let id = 0;
        let string;
        switch(obj.type) {
            case "News":
                id = localStorage.getItem("news");
                if (id === null) {
                    id = 0;
                }
                key = "news/" + id;
                localStorage.setItem("news", parseInt(id) + 1);
                break;
            case "Projects":
                id = localStorage.getItem("project");
                if (id === null) {
                    id = 0;
                }
                key = "project/" + id;
                localStorage.setItem("project", parseInt(id) + 1);
                
                break;
            case "Tasks":
                id = localStorage.getItem("task");
                if (id === null) {
                    id = 0;
                }
                key = "task/" + id;
                localStorage.setItem("task", parseInt(id) + 1);
               
                break;
        }
        string = jsonUmwandler.articleToJson(obj);
        localStorage.setItem(key, string );

        sendArticleToServer(key, string);
    }
}
function sendArticleToServer(key, article) {
    console.log('hallo');
    return fetch('http://localhost:8080/studfileserver/' + key + '.json', {
        body: article,
        cache: 'no-cache',
        credentials: 'same-origin',
        headers: {
            'content-type': 'application/json'
        },
        method: 'POST',
        mode: 'cors',
        redirect: 'follow',
        referrer: 'no-referrer'
    }).then(response => response.json());
}


let news12 = new news("Hallo","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
let task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");
let projekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");

//localStorage2 = new localStorage2();
//jsonUmwandler = new jsonUmwandler();
//localStorage2.articleSchreiben(projekt1); // ACHTUNG! Doppel einträge
//localStorage2.articleSchreiben(news12);
//localStorage2.articleSchreiben(task1);
//localStorage.removeItem("news3"); //ACHTUNG! Wenn du mittten drin was löscht wird nur noch bis dort angezeigt 

/*console.log("News:");
newsLesen();
console.log("Project:");
proLesen();
console.log("Task:");
taskLesen();*/