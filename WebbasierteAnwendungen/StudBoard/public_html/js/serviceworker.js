/* global caches */

this.addEventListener('install', function(event) {   
    event.waitUntil( 
        caches.open('StudBoardOffline').then(function(cache) {
            return cache.addAll([ 
                '/StudBoard/',
                '/StudBoard/Aufgaben.html',
                '/StudBoard/JSONUmwandler.js',
                '/StudBoard/NeuerArtikel.html',
                '/StudBoard/News.html',
                '/StudBoard/Projekte.html',
                '/StudBoard/StudBoardLogo150x100.png',
                '/StudBoard/StudBoardLogo300x200.png',
                '/StudBoard/article.js',
                '/StudBoard/blanko.html',
                '/StudBoard/cascade.css',
                '/StudBoard/geolocation.js',
                '/StudBoard/index.html',
                '/StudBoard/localStorage.js',
                '/StudBoard/popup.html',
                '/StudBoard/popup.js',
                '/StudBoard/serviceworker.js',
                '/StudBoard/sprache2.js',
                '/StudBoard/sprache_nav.js' 
            ]); 
        }) 
    ); 
});

this.addEventListener('fetch', function(evt) {
    evt.respondWith(
        caches.match(evt.request).then( 
            function(res) {   
                return res;
            }).catch(function() {
                console.log("Resource >" + evt.request.url + "< nicht im Cache gefunden");
            })        
     ); 
});
