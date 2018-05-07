// Test if Storage is supported
if (window.indexedDB) {
	let DBOpenRequest = window.indexedDB.open('toDoList',3);
	DBOpenRequest.onsuccess = function(e) {
		db = DBOpenRequest.result;
		
		// for(var i in db) {
			// console.log(i + " => " + db[i]);
		// }
		
		var transaction = db.transaction("toDoList","readonly");
		// var objectStore = transaction.objectStore("toDos");
		// var request = objectStore.get(1);
		// request.onerror = function(event) {
			// Handle errors!
		// };
		// request.onsuccess = function(event) {
			// Do something with the request.result!
			// console.log("First todo: " + request.result.desc);
		// };
	}
	
	DBOpenRequest.onupgradeneeded = function(event) {
		var db = event.target.result;
		
		var objectStore = db.createObjectStore("toDos", { keyPath: "id" });
		
		objectStore.transaction.oncomplete = function(event) {
			console.log("Created objectstore");
			// Store values in the newly created objectStore.
			var toDosObjectStore = db.transaction("toDos", "readwrite").objectStore("toDos");
			toDosObjectStore.add({id:1,desc:"learn indexedDB"});
		}
	}
} else {
    console.log("Sorry! No indexedDB support..");
}