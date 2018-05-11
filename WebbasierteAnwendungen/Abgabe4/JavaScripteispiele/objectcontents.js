// Objekt deklarieren
let obj = {
	// Objekt mit einer Eigenschaft ausstatten
	eigenschaft : 'grün',
	// Objekt mit einer Methode ausstatten
	methode : function() {
		console.log(this.eigenschaft);		// Ausgabe: grün
		console.log(obj.eigenschaft);		// Ausgabe: grün
	}
}

for(var i in obj) {
	console.log(i + ' = ' + obj[i]);
}