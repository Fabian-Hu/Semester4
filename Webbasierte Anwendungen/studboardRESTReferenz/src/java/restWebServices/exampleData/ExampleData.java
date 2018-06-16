/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.exampleData;

import java.util.ArrayList;
import java.util.List;
import restWebServices.models.Article;
import restWebServices.models.Comment;
import restWebServices.models.News;
import restWebServices.models.Project;
import restWebServices.models.Task;

/**
 *
 * @author Andre
 */
public class ExampleData {
    
    private static ExampleData data;
    
    private List<Article> articles = new ArrayList<>();
    private List<Comment> comments = new ArrayList<>();
    
    private ExampleData() {
        articles.add(new Project("Prof. Dr. Dreifuss", "2", 0, "Programmieren eines Kartoffelschälers", "In diesem Projekt werde ich einen Kartoffelschäler, "
                + "Baujahr 1962, so umprogrammieren, dass er von alleine Kartoffeln schälen kann. Dazu verwende ich die Skriptsprache JavaScript. Desweiteren erhält "
                + "der Kartoffelschäler noch eine Internetanbindung, sodass man gleichzeitg Internetradio während des Kartoffelschälens hören kann.", "blue", "08.06.1962", "23.08.2021"));
        articles.add(new Task("Physik", 1, "Schwebebahn", "Hallo, ich muss eine Schwebebahn in Physik entwickeln und brauche dabei dringend Hilfe. Wer mir helfen möcht, "
                + "kann sich gerne hier in den Kommentaren melden oder mich per Handy erreichen: 0123 4567890", "red", "04.02.2014", "23.06.2015"));
        articles.add(new News("Postillon", 2, "Weil es unter Obama weiß war: Trump lässt Weißes Haus schwarz streichen", "Washington (dpo) - Der Mann meint es ernst. "
                + "Donald Trump hat das Weiße Haus heute komplett schwarz streichen lassen. Offenbar will sich der US-Präsident mit Farbänderungvon seinem Vorgänger Barack Obama distanzieren, "
                + "in dessen Amtszeit das Gebäude weiß war. \"Es ist das gute Recht des Präsidenten, seiner Residenz jede Farbe zu verpassen, die er möchte\", rechtfertigt Sarah Huckabee-Sanders, "
                + "die Sprecherin des Schwarzen Hauses, die überraschende Aktion. \"Wenn Barack Obama ein Weißes Haus bevorzugt, ist das seine Sache. Präsident Trump lässt sich davon sicher nicht beeinflussen. "
                + "Trump selbst äußerte sich noch nicht zu der Farbänderung, sondern zog sich ins neugestaltete Rectangular Office zurück, wo er derzeit Papiere unterzeichnet, "
                + "um alle von Barack Obama begnadigten Thanksgiving-Truthähne nachträglich töten zu lassen.", "black", "04.05.2018", "14.06.2018"));
        articles.add(new News("", 3, "Fünf verschiedene Papierkörbe: Microsoft führt Mülltrennung bei Dateien ein", "<h2>Skandal!</h2><br>Redmond (Archiv) - Windows wird endlich grün: "
                + "Ein ab heute verfügbares Update für Windows 10 bringt nach Angaben von Microsoft erstmals Mülltrennung auf heimische PCs. Umweltschützer kritisieren schon seit Jahren, "
                + "dass auf Computern alle Dateien bislang ungeachtet ihres Formats im selben Mülleimer landen. <br>Statt des altbekannten Papierkorbs sind nach dem Update nun fünf verschiedenfarbige "
                + "Behälter auf dem Desktop zu sehen – jeweils einer für Fotos, Videos, Musikdateien, Textdokumente und Restmüll. Nutzer werden dazu angehalten, ihre Daten entsprechend nachhaltig zu entsorgen."
                + "<br>Dateien mit folgenden Endungen gehören beispielsweise in die Fototonne: .jpg, .png, .psd, .tiff, .gif, .bmp, .svg<br>In den Papierkorb kommen: .doc, .docx, .pdf, .txt, .xls, .xlsx"
                + "<br>Dateien mit folgenden Endungen gehören in den Altvideomüll: .wmv, .mp4, .avi, .mkv, .flv<br>In der Musiktonne landen: .wma, .mp3, .wav, .flac, .alac, .m4a, .<br><br><h3>Restmüll für alles!</h3>"
                + "<br>Die meisten anderen Dateien landen im Restmüll. <br>Beim Leeren des Mülleimers werden die entsorgten Dateien dann nicht einfach gelöscht, sondern nach Möglichkeit recycelt. "
                + "Die Farbe aus alten Fotos wird so zum Beispiel genutzt, um den Farbeimer in Microsoft Paint ressourcenschonend zu befüllen. Alte Worddokumente wiederum werden zu neuen, etwas graueren Worddokumenten verarbeitet."
                + "<br>Einige besonders toxische und nicht recyclebare Dateien wie Computer-Viren, GILF-Pornovideos oder Helene-Fischer-Songs können allerdings nicht mehr direkt auf dem Desktop entsorgt werden, "
                + "sondern müssen auf einen USB-Stick transferiert und anschließend auf dem Postweg zur Sondermüllentsorgung an Microsoft geschickt werden.", "green", "09.06.2018", "21.06.2018"));
        articles.add(new Project("Prof. Dr. Karl", "1997", 4, "Regenbogen-Scheibenwischer", "Für alle, die mehr Farbe in ihrem Leben wollen: https://www.sinn-frei.com/media/2012/17509_006.jpg", "orange", "01.04.2018", "02.04.2018"));
        
        comments.add(new Comment(0, articles.get(0), "Endlich kann ich beim Kartoffelschälen Radio hören", "5", ""));
        comments.add(new Comment(1, articles.get(0), "Hoffentlich gibt es das auch bald für nen Spargelschäler", "4", ""));
        comments.add(new Comment(2, articles.get(1), "Ich kann deine Nummer nicht auf ICQ finden, ist die falsch geschrieben?", "2", ""));
        comments.add(new Comment(3, articles.get(2), "Ich finde, pink ist eine viel schönere Farbe als weiß!!!", "3", ""));
        comments.add(new Comment(4, articles.get(3), "Wo bleibt der Mülleimer für Browser Toolbars?", "3", ""));
        comments.add(new Comment(5, articles.get(3), "Natürlich vergessen die den Mülleimer für OpenOffice Dokumente, nur damit man Microsoft Office benutzt", "4", ""));
        comments.add(new Comment(6, articles.get(4), "Boah, das wird mir zu bunt!", "1", ""));
        
        articles.get(0).addComment(comments.get(0));
        articles.get(0).addComment(comments.get(1));
        articles.get(1).addComment(comments.get(2));
        articles.get(2).addComment(comments.get(3));
        articles.get(3).addComment(comments.get(4));
        articles.get(3).addComment(comments.get(5));
        articles.get(4).addComment(comments.get(6));
    }
    
    public static ExampleData getInstance() {
        if (data == null)
            data = new ExampleData();
        return data;
    }
    
    public List<Article> getArticles() {
        return articles;
    }
    
    public List<Comment> getComments() {
        return comments;
    }
}
