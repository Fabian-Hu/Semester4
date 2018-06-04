var readyStateCallbackFunction = function() {
    if (this.readyState == 4 && this.status == 200) {
		console.log("Folgene Antwort erhalten: ");
		console.log(this.responseText);
    } else {
		console.log("readyState: " + this.readyState + " Status: " + this.status);
	}
  };

window.onload = function() {
	let requestor = new XMLHttpRequest();
	requestor.open("GET","xmlhttprequest.json");
	requestor.onreadystatechange = readyStateCallbackFunction;
	requestor.send();
}