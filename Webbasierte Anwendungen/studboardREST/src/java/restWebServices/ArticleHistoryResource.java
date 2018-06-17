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
import restWebServices.models.Article;

/**
 *
 * @author Andre
 */
@Path("history")
public class ArticleHistoryResource {
    
    private static final int CONTENT_SIZE = 128;
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public String getHistory(@QueryParam("count") int count, @QueryParam("type") String type) {
        
        List<Article> articles = ExampleData.getInstance().getArticles();
        
        JSONArray history = new JSONArray();
        
        if (count == 0)
            count = articles.size();
        
        for (int i = 0; i < count && i < articles.size(); i++) {
            Article article = articles.get(i);
            if (article.getType().equals(type) || type.equals("all")) {
                JSONObject jsonArticle = new JSONObject();
                jsonArticle.put("id", article.getId());
                jsonArticle.put("title", article.getTitle());
                jsonArticle.put("content", article.getContent().substring(0, article.getContent().length() > CONTENT_SIZE ? CONTENT_SIZE : article.getContent().length()));
                jsonArticle.put("type", article.getType());
                history.add(jsonArticle);
            }
        }
        
        return history.toJSONString();
    }
}
