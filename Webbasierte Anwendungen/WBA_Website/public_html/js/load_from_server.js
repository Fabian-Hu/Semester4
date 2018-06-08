/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
function getLogo() {
    fetch('http://localhost:8080/studfileserver/img/example.json').then(
        function(response) {
            console.log(response.ok);
            console.log(response.status);
            console.log(response.statusText);
            let res = response.json();
            console.log(res);
            return res;
        }
    ).then(
        function(jsonData) {
            console.log(jsonData);
        }
    ).catch(
        function(err) {
            console.log("error: " + err);
        }
    );
}


