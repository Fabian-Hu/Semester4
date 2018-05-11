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

class MeineKlasse2 extends MeineKlasse {
	
	constructor(param1) {
		super(param1);								//Zwingend
		this.attribut1 = 55;
	}
	
	get attribut1() {
		return this.a1;
	}
	
	set attribut1(param1) {
		this.a1 = param1 * 2;
	}
}



meineVar = new MeineKlasse2(20);

console.log(meineVar.attribut1);
console.log(meineVar.attribut2);

