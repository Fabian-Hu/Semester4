/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebService;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.QueryParam;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import restWebService.models.Article;
import restWebService.models.Project;

/**
 *
 * @author Andre
 */
@Path("article")
public class ArticleResource {
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response getArticle(@QueryParam("id") int id) {
        Article article = new Project("Prof. Dr. Dreifuss", "2", 0, "Programmieren eines Kartoffelschälers", "In diesem Projekt werde ich einen Kartoffelschäler, "
                + "Baujahr 1962, so umprogrammieren, dass er von alleine Kartoffeln schälen kann. Dazu verwende ich die Skriptsprache JavaScript. Desweiteren erhält "
                + "der Kartoffelschäler noch eine Internetanbindung, sodass man gleichzeitg Internetradio während des Kartoffelschälens hören kann.", "blue", "08.06.1962", "23.08.2021");
        
        return Response.ok(article).build();
    }
}
