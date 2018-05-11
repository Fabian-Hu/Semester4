function printAtTime() {
	console.log("Time is over!");
}

setTimeout(printAtTime,1000);

for(var i=0; i < 10000; i++) {
	console.log("I'am dooing hard work");
}

var promise = new Promise(
	function(resolve,reject){
		setTimeout(function() { 
			console.log("I do something that needs time...");
			resolve("done!");
		},2000);
	}
);

promise.then(function(erg) { console.log(erg)});
console.log("This should be printed before done!");

// Promise - alternative
let executor = function(resolve,reject){
	setTimeout(function() { 
		console.log("I do something that needs time...");
		resolve("done!");
	},2000);
}

let fullFillFunc = function(erg) { console.log(erg)};

var promise = new Promise(executor);
promise.then(fullFillfunc);
console.log("This should be printed before done!");