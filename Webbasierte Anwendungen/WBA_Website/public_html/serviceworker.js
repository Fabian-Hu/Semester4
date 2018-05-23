/* global caches */

let cacheName = 'saili';

this.addEventListener('install', function(event) {
	event.waitUntil(
		caches.open(cacheName).then(function(cache) {
			return cache.addAll([
				'/WBA_Website/',
				'/WBA_Website/index.html',
				'/WBA_Website/article.js',
				'/WBA_Website/article_converter.js',
				'/WBA_Website/createNewArticle.html',
				'/WBA_Website/dataTarget.html',
				'/WBA_Website/news.html',
				'/WBA_Website/projects.html',
				'/WBA_Website/serviceworker.js',
				'/WBA_Website/stylesheet.css',
				'/WBA_Website/tasks.html',
				'/WBA_Website/translation.js',
				'/WBA_Website/img/StudBoardLogo150x100.png',
				'/WBA_Website/img/StudBoardLogo300x200.png',
				'/WBA_Website/img/StudBoardLogo301x200.png'
			]);
		})
	);
});

this.addEventListener('fetch', function(event) {
	event.respondWith(
		caches.match(event.request).then(
			function(res) {
				return res;
			}).catch(function() {
				console.log('Error: Angeforderte Datei nicht im Cache: ' + event.request.url);
			}
		)
	);
});