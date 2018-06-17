/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices;

import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 *
 * @author Andre
 */
@Path("article/create")
public class ArticleCreateResource {
    
    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    public Response createArticle(String json) {
        System.out.println(json);
        return Response.status(Response.Status.OK).build();
    }
}
