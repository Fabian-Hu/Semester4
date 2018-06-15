/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

let myWindow = window.open("", "MsgWindow", "menubar=0,titlebar=0,toolbar=0,top=15%,resizable=0,width=600px,height=200px");

if (navigator.language === 'de' || navigator.language === 'de-DE') {
    myWindow.document.write("<p style=\"text-align: center; position: absolute; left: 37%; top: 40%\">Wilkommen auf SAILI!</p>");
}else if (navigator.language === 'en' || navigator.language === 'en-US' || navigator.language === 'en-GB') {
    myWindow.document.write("<p style=\"text-align: center; position: absolute; left: 37%; top: 40%\">Welcome to SAILI!</p>");
}
myWindow.setTimeout("close()", 5000);

