/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices;

import java.util.List;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import restWebServices.exampleData.ExampleData;
import restWebServices.models.Comment;

/**
 *
 * @author Andre
 */
@Path("comments")
public class ArticleCommentsResource {
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getComments(@QueryParam("articleId") int id) {
        
        List<Comment> comments = ExampleData.getInstance().getComments();
        
        JSONArray jsonComments = new JSONArray();
        
        for (int i = 0; i < comments.size(); i++) {
            Comment comment = comments.get(i);
            if (comment.getArticleId() == id) {
                JSONObject jsonComment = new JSONObject();
                jsonComment.put("id", comment.getId());
                jsonComment.put("text", comment.getText());
                jsonComment.put("rating", comment.getRating());
                jsonComment.put("file", comment.getFile());
                jsonComments.add(jsonComment);
            }
        }
        
        return jsonComments.toJSONString();
    }
}
