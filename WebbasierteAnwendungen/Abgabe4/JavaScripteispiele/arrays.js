let myArray = ['w0','w1'];			// Neues Array mit 2 Elementen
myArray[3] = 'w3';					// Hinzufügen eines Elements
console.log(myArray.length);		// Auslesen des Attributs „length“
let myArray2 = [];					// Neues Array ohne Elemente
let myArray3 = new Array(2);		// Neues Array mit 2 „undefined“ Elementen

console.log(myArray);

myArray['3'] = 'w3a';				// Automatische Konvertierung zu integer
console.log(myArray);

myArray['01'] = 'w1a';				// Konvertierung zu integer klappt nicht -> als Attribut gesetzt
console.log(myArray);

myArray['test'] = 'TestWert';		// Schreiben des Attributs
console.log(myArray['test']);		// Zugriff auf Attribut nicht Element

console.log('===start for in===');
for(var i in myArray) {
	console.log(i + ' = ' + myArray[i]);
}

console.log('=== start for of===');
for(var elem of myArray) {
	console.log(elem);
}
