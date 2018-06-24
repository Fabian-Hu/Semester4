/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices;

import java.util.List;
import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import restWebServices.models.Article;
        

/**
 *
 * @author Andre
 */
@Path("")
public class ArticleResource {
    
    private static final int CONTENT_SIZE = 128;
    
    private DatabaseApi api = new DatabaseApi();
    
    @GET
    @Path("article")
    @Produces(MediaType.APPLICATION_JSON)
    public Response getArticle(@QueryParam("id") int id) {
        
        Article article = api.getArticlebyId(id);
        if (article != null)
            return Response.ok(article).build();
        
        return Response.status(Response.Status.NOT_FOUND).build();
    }
    
    @GET
    @Path("history")
    @Produces(MediaType.APPLICATION_JSON)
    public String getHistory(@QueryParam("count") int count, @QueryParam("type") String type) {
        
        List<Article> articles = null;
        
        //if (type.equals("all"))
            //articles = api.getArticles();
        //else
        //    articles = api.getArticlesByType(type);
        
        JSONArray history = new JSONArray();
        
        if (count == 0)
            count = articles.size();
        
        count = 0;
        
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
    
    @POST
    @Path("article/create")
    @Consumes(MediaType.APPLICATION_JSON)
    public Response createArticle(String json) {
        System.out.println(json);
        return Response.status(Response.Status.OK).build();
    }
}
