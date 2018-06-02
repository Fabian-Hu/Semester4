
let de_DE = {
    site_title : "SAILI - Die Website für Studierende und Lehrende",
    nav : "Navigation",
    home : "Startseite",
    news_title: "Neuigkeiten",
    projects : "Projekte",
    tasks : "Aufgaben",
    article : "Neuen Artikel anlegen",
    last_articles : "Die letzten Artikel",
    show_more : "Mehr anzeigen...",
    input_form : "Eingabeformular",
    title : "Titel",
    text : "Text",
    article_type : "Artikeltyp",
    start_date : "Startdatum",
    end_date : "Enddatum",
    title_color : "Titelfarbe"
};

let en_GB = {
    site_title : "SAILI - The website for students and teachers",
    nav : "Navigation",
    home : "Home",
    news_title : "News",
    projects : "Projects",
    tasks : "Tasks",
    article : "Create new article",
    last_articles : "The last articles",
    show_more : "Show more...",
    input_form : "Input form",
    title : "Title",
    text : "Text",
    article_type : "Article type",
    start_date : "Start date",
    end_date : "End date",
    title_color : "Title color"
};

function setLanguage() {
    let lang;
    if (navigator.language === 'de' || navigator.language === 'de-DE') {
        lang = de_DE;
    }else if (navigator.language === 'en' || navigator.language === 'en-US' || navigator.language === 'en-GB') {
        lang = en_GB;
    }
    for (let args in lang) {
        let elems = document.getElementsByClassName(args);
        for (let part of elems) {
            part.firstChild.nodeValue = lang[args];
        }
    }
};

let myWindow = window.open("", "MsgWindow", "menubar=0,titlebar=0,toolbar=0,top=15%,resizable=0,width=600px,height=200px");

if (navigator.language === 'de' || navigator.language === 'de-DE') {
    myWindow.document.write("<p style=\"text-align: center; position: absolute; left: 37%; top: 40%\">Wilkommen auf SAILI!</p>");
}else if (navigator.language === 'en' || navigator.language === 'en-US' || navigator.language === 'en-GB') {
    myWindow.document.write("<p style=\"text-align: center; position: absolute; left: 37%; top: 40%\">Welcome to SAILI!</p>");
}
myWindow.setTimeout("close()", 5000);