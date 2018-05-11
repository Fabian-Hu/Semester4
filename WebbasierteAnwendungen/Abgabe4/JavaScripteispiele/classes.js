// Klasse anlegen
class MeineKlasse {
	//Hier gibt es keine Attribut-Deklarationen
	
	constructor(param1) {
		// Hier kommen Attributdeklarationen
		this.attribut1 = param1;
		this.attribut2 = undefined;
	}
	
	methode1() {
		return this.attribut1;
	}
}
meineVar = new MeineKlasse(20);

console.log(meineVar.attribut1);
console.log(meineVar.methode1());
console.log(meineVar.attribut2);

meineVar.attribut3 = 42;
console.log(meineVar.attribut3);
