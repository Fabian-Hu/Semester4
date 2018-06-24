/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function getLogo() {
    fetch('http://localhost:8080/studfileserver/img/StudBoardLogo150x100.png').then(
        function(response) {
            /*for (var pair of response.headers.entries()) {
               console.log(pair[0] + ": " + pair[1]);
            }*/
            return response.blob();
        }
    ).then(
        function(blob) {
            let src = document.getElementById("smallImg");
            let image = document.getElementById("defaultImg");
            let objectURL = URL.createObjectURL(blob);
            image.src = objectURL;
            src.attributes.srcset.nodeValue = objectURL;
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
    fetch('http://localhost:8080/studfileserver/img/StudBoardLogo300x200.png').then(
        function(response) {
            return response.blob();
        }
    ).then(
        function(blob) {
            let src = document.getElementById("largeImg");
            let objectURL = URL.createObjectURL(blob);
            src.attributes.srcset.nodeValue = objectURL;
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}


