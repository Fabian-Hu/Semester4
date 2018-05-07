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

obj.methode();

// Objekt deklarieren
let obj2 = new Object();
// Objekt mit einer Eigenschaft ausstatten
obj2.eigenschaft = 'rot';
// Objekt mit einer Methode ausstatten
obj2.methode = function() {
   console.log(this.eigenschaft);		// Ausgabe: rot
   console.log(obj.eigenschaft);		// Ausgabe: grün
}

obj2.methode();
