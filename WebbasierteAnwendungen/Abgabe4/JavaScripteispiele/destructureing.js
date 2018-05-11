let myArray = ['w0','w1', 'w3'];

let a,b,c;
[a,b,c] = myArray;

console.log('a: ' + a + ' b: ' + b + ' c: ' + c);

function spreadingTest(a,b,c) {
	console.log('a: ' + a + ' b: ' + b + ' c: ' + c);
}

spreadingTest(...myArray);