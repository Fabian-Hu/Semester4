// Klasse anlegen
class MeineKlasse {
	
	constructor(param1) {
		// Hier kommen Attributdeklarationen
		this.attribut1 = param1;					// Ruft den Setter auf
		this.attribut2 = 10;						// Legt das Attribut an
	}
	
	get attribut1() {
		console.log('get attribut1');
		return this.a1;
	}
	
	set attribut1(param1) {
		console.log('set attribut1');
		this.a1 = param1;
	}
}
meineVar = new MeineKlasse(20);

console.log(meineVar.attribut1);
//console.log(meineVar.attribut1());			// Fehler: not a function
console.log(meineVar.a1);
console.log(meineVar.attribut2);

