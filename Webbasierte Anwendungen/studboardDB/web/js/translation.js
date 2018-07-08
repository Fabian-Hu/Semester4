
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
    title_color : "Titelfarbe",
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
    title_color : "Title color",
};

function setLanguage() {
    let lang;
    if (navigator.language === 'de' || navigator.language === 'de-DE') {
        lang = de_DE;
    }else if (navigator.language === 'en' || navigator.language === 'en-US' || navigator.language === 'en-GB') {
        lang = en_GB;
    }
    for (let args in lang) {
        $(document).ready(function(){
               $("." + args).text(lang[args]);
        });
    }
};
