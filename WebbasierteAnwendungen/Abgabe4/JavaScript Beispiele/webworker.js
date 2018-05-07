var worker = new Worker("webworker-worker.js");	// Call worker script

// Called when reciving message from worker
worker.onmessage = function(e) {
	console.log(e.data);
};
// Called on error
worker.onerror = function(e) {
	console.log(e.message);
}

// Send messages to worker	
worker.postMessage("message 1");
worker.postMessage("message 2");
//worker.terminate();
worker.postMessage("message 3");
worker.postMessage("message 4");