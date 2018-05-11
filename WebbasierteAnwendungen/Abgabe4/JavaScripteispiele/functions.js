// Deklariere Funktion
function function1(param) {
   return param * param;
}
// Benutze Funktion
console.log(function1(2));

// Deklariere Funktion und speichere Referenz auf Funktion in Variable
let functionVar1 = function(param) {
   return param * param;
}
console.log(typeof functionVar1);
// Benutze Funktion
console.log(functionVar1(2));

// Checks if an function always returns the same with the same param
function isDeterministic(func, param) {
	let res1 = func(param);
	let res2 = func(param);
	if(res1==res2) {
		return true;
	}
	return false;
}

console.log(isDeterministic(functionVar1,4));

// Function with default value
function defaultValue(param=2) {
	return param * param;
}

console.log(defaultValue());
console.log(defaultValue(4));

function addAll(value1, ...valuesN) {
	let val = value1;
	for(var i=0; i < valuesN.length;i++) {
		val += valuesN[i];
	}
	return val;
}

console.log(addAll(1,2));
console.log(addAll(1,2,3,4,5,6));