/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebService;

import java.util.ArrayList;
import java.util.List;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import restWebService.models.ArticleShort;

/**
 *
 * @author Andre
 */
@Path("history")
public class ArticleHistoryResource {
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getHistory() {
        
        /*List<ArticleShort> articles = new ArrayList();
        articles.add(new ArticleShort(0, "Was macht der Hausmeister?", "Siehe Frage im Titel", "Task"));
        articles.add(new ArticleShort(1, "Tragbarer Sonnenschirm", "Weitere Informationen im Artikel", "Project"));
        articles.add(new ArticleShort(2, "Bauer Müller klaut eigene Äpfel", "Wieso macht der das?", "News"));
        articles.add(new ArticleShort(3, "Selbstscheerende Schafe", "Wir entwickeln selbstscheerende Schafe", "Project"));
        articles.add(new ArticleShort(4, "Wasser aus der Steckdose", "Baue deine Wohnung so um, dass das Wasser aus der Steckdose "
                + "und der Strom aus dem Wasserhahn kommt", "Task"));*/
        
        JSONArray history = new JSONArray();
        JSONObject article1 = new JSONObject();
        article1.put("id", 0);
        article1.put("title", "Was macht der Hausmeister?");
        article1.put("content", "Siehe Frage im Titel");
        article1.put("type", "Task");
        history.add(article1);
        
        JSONObject article2 = new JSONObject();
        article2.put("id", 1);
        article2.put("title", "Tragbarer Sonnenschirm");
        article2.put("content", "Weitere Informationen im Artikel");
        article2.put("type", "Project");
        history.add(article2);
        
        JSONObject article3 = new JSONObject();
        article3.put("id", 2);
        article3.put("title", "Bauer Müller klaut eigene Äpfel");
        article3.put("content", "Wieso macht der das?");
        article3.put("type", "News");
        history.add(article3);
        
        JSONObject article4 = new JSONObject();
        article4.put("id", 3);
        article4.put("title", "Selbstscheerende Schafe");
        article4.put("content", "Wir entwickeln selbstscheerende Schafe");
        article4.put("type", "Project");
        history.add(article4);
        
        JSONObject article5 = new JSONObject();
        article5.put("id", 4);
        article5.put("title", "Wasser aus der Steckdose");
        article5.put("content", "Baue deine Wohnung so um, dass das Wasser aus der Steckdose "
                + "und der Strom aus dem Wasserhahn kommt");
        article5.put("type", "Task");
        history.add(article5);
        
        return history.toJSONString();
    }
}
