/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/* global URL, fetch */

window.onload = function() {    
        console.log("Bild vom Server");
	fetch('http://localhost:8080/studfileserver/img/StudBoardLogo150x100.png').then(
		function(response) {
			return response.blob();
		}
	).then(
		function(blob) {
			let src = document.getElementById("klein");
                        let url = URL.createObjectURL(blob);
                        src.attributes.srcset.nodeValue = url;
		}
	).catch(function(err) {
		console.log("Oops, Something went wrong!", err);
	});
        fetch('http://localhost:8080/studfileserver/img/StudBoardLogo300x200.png').then(
		function(response) {
			return response.blob();
		}
	).then(
		function(blob) {
			let src = document.getElementById("groß");
                        let url = URL.createObjectURL(blob);
                        src.attributes.srcset.nodeValue = url;
		}
	).catch(function(err) {
		console.log("Oops, Something went wrong!", err);
	});
}
