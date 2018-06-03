/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

if (navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(positionRecivedHandler, errorHandler);
} else {
    console.log("Geolocation ist blöd");
}

function positionRecivedHandler(position) {
    console.log("Schau mal wo du gerade stehst: ");
    for (let i in position.coords) {
        console.log(i + " = " + position.coords[i]);
    }
}

function errorHandler(error) {
    console.log("Du bist wohl ein Phantom, nirgendswo zu finden");
}