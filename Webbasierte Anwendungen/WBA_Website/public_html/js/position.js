if (navigator.geolocation) {
    navigator.geolocation.watchPosition(function(position) {
        /*console.log("Position");
        for (let i in position.coords) {
            console.log(i + " = " + position.coords[i]);
        }*/
    }, function(error) {
        console.log("Keine geolocation Daten vorhanden");
    });
}