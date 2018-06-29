/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.io.Serializable;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

/**
 *
 * @author Fabian
 */
@Path("comment/liste")
public class CommentListeResource implements Serializable{
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getKommentarListe(@QueryParam("id") int id){
        JSONArray liste = new JSONArray();      
        JSONObject comment = new JSONObject();
        Comment[] CommentList = new Comment[5];
        CommentList[0] = new Comment(0,0, "Hallo","4/5","file");
        CommentList[1] = new Comment(1,0,"Tiefgründiger Text","5/5 Text","file");
        CommentList[2] = new Comment(2,0,"Energia stinkt","0/5","file");
        CommentList[3] = new Comment(3,1,"Java ist okey","3/5","file");
        CommentList[4] = new Comment(4,1,"Fische sind meistens Nass","2/5","file");
        
        comment.clear();
        for (Comment kommentar : CommentList) {
            if(kommentar.getArticle_id()==id){
                comment = new JSONObject();
                comment.put("id", kommentar.getId());
                comment.put("article_id",kommentar.getArticle_id());
                comment.put("text",kommentar.getText());
                comment.put("rating",kommentar.getRating());
                comment.put("file",kommentar.getFile());
                liste.add(comment);
            }
        }
        return liste.toJSONString();
    }
}

