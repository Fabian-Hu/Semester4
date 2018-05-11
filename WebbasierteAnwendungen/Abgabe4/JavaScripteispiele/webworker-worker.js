var messageCounter=0;

onmessage = function(e) {
	messageCounter++;
	if(messageCounter<=3) {
		console.log(e.data);
		postMessage("reply " + messageCounter); 	// Reply to caller
	} else {
		postMessage("no more replies");
		close();									//Close the worker
	}
}