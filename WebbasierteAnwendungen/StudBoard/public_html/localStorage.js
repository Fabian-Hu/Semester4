/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
 
class localStorage2 {
    
    newsLesen(){ 
        jsonUmwandler = new jsonUmwandler();
        if (typeof(Storage) !== "undefined") {  
            let news = [];
            let i=1;
            while(true){
                string1 = "news"+i; 
                news[i] = localStorage.getItem(string1);         
                if(news[i]){
                    let newsObj = jsonUmwandler.jsonToArcticle(news[i]);
                    console.log(newsObj); // Hier Funktion zum erstellen eines Articel
                    i++;
                }else {
                    break;
                }
            }
        } else { 
            console.log("Sorry! No Web Storage support.."); 
        }
    }

    articleLesen(){ 
        jsonUmwandler = new jsonUmwandler();
        let string1;
        let art = [];
        let i=1;
        if (typeof(Storage) !== "undefined") {  
            while(true){
                string1 = "art"+i; 
                art[i] = localStorage.getItem(string1);         
                if(art[i]){            
                    i++;
                }else {
                    break;
                }
            }
            return art;
        } else { 
            console.log("Sorry! No Web Storage support.."); 
        }
    }
    
    taskLesen(){ 
        jsonUmwandler = new jsonUmwandler();
        if (typeof(Storage) !== "undefined") {  
            let task = [];
            let i=1;
            while(true){
                string1 = "task"+i; 
                task[i] = localStorage.getItem(string1);         
                if(task[i]){
                    let proObj = jsonUmwandler.jsonToArcticle(task[i]);
                    console.log(proObj); // Hier Funktion zum erstellen eines Articel
                    i++;
                }else {
                    break;
                }
            }
        } else { 
            console.log("Sorry! No Web Storage support.."); 
        }
    }

    articleSchreiben(obj){   
        let i=1; 
        jsonUmwandler = new jsonUmwandler(); 
        let string1,string;
        while(true){                
            string1 = "art"+i; 
            let art1 = localStorage.getItem(string1);              
            if(art1){               
                i++;
            }else {               
                break;
            }        
        }                   
        string1 = "art"+i; 
        string = jsonUmwandler.articleToJson(obj);
        localStorage.setItem(string1,string);
    }
    /*
    articleSchreiben(obj){   
        let i=1; 
        jsonUmwandler = new jsonUmwandler(); 
        let string1,string;
        if(obj.type === "News"){         
            while(true){                
                string1 = "news"+i; 
                let news1 = localStorage.getItem(string1);              
                if(news1){               
                    i++;
                }else {               
                    break;
                }        
            }
            string1 = "news2"; 
            string = jsonUmwandler.articleToJson(obj);
            localStorage.setItem(string1,string);
        } else if(obj.type === "Projects"){
            while(true){
                string1 = "pro"+i; 
                let pro = localStorage.getItem(string1);         
                if(pro){
                    i++;
                }else {
                    break;
                }        
            }
            string1 = "pro"+i; 
            string = jsonUmwandler.articleToJson(obj);
            localStorage.setItem(string1,string);
        } else if(obj.type === "Tasks"){
            while(true){
                string1 = "task"+i; 
                let task = localStorage.getItem(string1);         
                if(task){
                    i++;
                }else {
                    break;
                }        
            }
            string1 = "task"+i; 
            string = jsonUmwandler.articleToJson(obj);
            localStorage.setItem(string1,string);
        } else {
            console.log("Falsches Objekt übergeben");
        }
    }*/
}

//let news12 = new news("Hallo","Igelhaus","#000000","2018-2-1", "2018-12-3", "wichtig", "aus unserem Gehirn");
//let task1 = new tasks("Webanwendung machen", "Aufgabe", "#f0f0f0", "2018-2-1", "2018-2-1", "das beste Fach des Universums");
//let projekt1 = new projects("Project X unterliegt der Geheimhaltung", "Project X", "#ff00ff", "2018-2-1", "2018-2-1", "Florian Fehring", "23");

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