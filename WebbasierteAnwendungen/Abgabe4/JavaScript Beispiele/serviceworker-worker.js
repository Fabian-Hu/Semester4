// Called on install stage
this.addEventListener('install', function(event) {
  // Sicherstellen, das zuerst alle Datein im cache landen
  event.waitUntil(
    caches.open('v1').then(function(cache) {
      return cache.addAll([
        '/pwa/',
		'/pwa/serviceworker.html',
		'/pwa/serviceworker.js',
        '/pwa/serviceworker-tc.jpg'
      ]);
    })
  );
});

// Wird aufgerufen wenn Dateien angefragt werden
this.addEventListener('fetch', function(evt) {
	console.log("Hole " + evt.request.url);
	evt.respondWith(																	// Responde with erwartet eine asynchrone Funktion
		caches.match(evt.request).then(
		function(res) {																	// res ist Ergebnis von caches.match()
			console.log("Resource >" + res.url + "< aus dem Cache geholt");
			return res;
		}).catch(function(err) {															
			console.log("Resource >" + evt.request.url + "< nicht im Cache gefunden");			
			//return fetch(evt.request);
		})
	);
});