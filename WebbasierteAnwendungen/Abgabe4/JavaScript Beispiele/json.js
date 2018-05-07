let jsonStr = "{\"attribut1\" : 42, \"array1\" : [\"w1\",\"w2\",\"w3\",\"w4\"]}";

jsonObj = JSON.parse(jsonStr);

for(var attr in jsonObj) {
	console.log(attr);
	if(typeof jsonObj[attr] == "object") {
		for(var i in jsonObj[attr]) {
			console.log("> " + jsonObj[attr][i]);
		}
	}
}

let obj = {
	attr1 : 42,
	array1 : [1,2,3,4],
	object1 : {sub1 : "sub1", sub2 : "sub2"}
}

let newJsonStr = JSON.stringify(obj);
console.log(newJsonStr);