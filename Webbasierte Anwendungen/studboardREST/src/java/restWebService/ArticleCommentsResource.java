/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebService;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

/**
 *
 * @author Andre
 */
@Path("comments")
public class ArticleCommentsResource {
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getComments(@QueryParam("articleId") int id) {
        
        JSONArray comments = new JSONArray();
        
        JSONObject comment0 = new JSONObject();
        comment0.put("id", 0);
        comment0.put("articleId", id);
        comment0.put("text", "Achtung Werbung: Kennen sie schon den neuen Bananenshakemixer. Banane rein, einschalten und fertig!");
        comment0.put("rating", "5");
        comment0.put("file", "");
        comments.add(comment0);
        
        JSONObject comment1 = new JSONObject();
        comment1.put("id", 1);
        comment1.put("articleId", id);
        comment1.put("text", "Gibt es den Artikel auch in anderen Sprachen?");
        comment1.put("rating", "2");
        comment1.put("file", "");
        comments.add(comment1);
        
        return comments.toJSONString();
    }
}
