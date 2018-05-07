// Test if Storage is supported
if (typeof(Storage) !== "undefined") {
	let visits = localStorage.getItem("visits");
	if(visits) {  										// Test if visits is not undefined
		visitsNo = parseInt(visits);					// Has to parse because storage is string only
		visitsNo++;
		localStorage.setItem("visits",visitsNo);
		
		if(visitsNo>5) {
			localStorage.removeItem("visits");
		}
	} else {
		localStorage.setItem("visits",1);
	}
	console.log("This is your " + localStorage.getItem("visits") + " visit");
} else {
    console.log("Sorry! No Web Storage support..");
}

for(var i in localStorage) {
	console.log(i + " => " + localStorage[i]);
}