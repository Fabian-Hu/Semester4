window.onload = function() {
	fetch('fetchapi.json').then(
		function(response) {
			console.log("Get response as json-Promise");
			return response.json();
		}
	).then(
		function(jsonData) {
			console.log("recived data: " + jsonData);
		}
	).catch(function(err) {
		console.log("Opps, Something went wrong!", err);
	})
}