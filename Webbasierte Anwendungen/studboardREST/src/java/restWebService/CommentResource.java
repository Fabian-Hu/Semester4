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
import javax.ws.rs.core.Response;
import restWebService.models.Comment;

/**
 *
 * @author Andre
 */
@Path("comment")
public class CommentResource {
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response getComment(@QueryParam("id") int id) {
        
        Comment comment = new Comment(0, 0, "Ich glaube, der ist mal wieder am Rasen mähen", "4", "");
        
        return Response.ok(comment).build();
    }
}
