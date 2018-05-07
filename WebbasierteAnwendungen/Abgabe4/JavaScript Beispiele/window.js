let fenster1 = window.open("", "popup1", "width=200,height=100");
let fenster2 = window.open("","popup", "width=200,height=200");
fenster2.setTimeout("close()", 2000); // Zeitverzögerung 2000 ms
fenster1.setTimeout("close()", 5000); // Zeitverzögerung 5000 ms
