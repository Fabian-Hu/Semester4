// Check if geolocation-api is available
if (navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(positionRecivedHandler, errorHandler);
} else {
	console.log("Geolocation not supported");
}

function positionRecivedHandler(position) {
	console.log("Ihre Positionsinformationen:");
	for(let i in position.coords) {
		console.log(i + " = " + position.coords[i]);
	}
}

function errorHandler(error) {
	console.log("Keine geolocation Daten vorhanden.");
}