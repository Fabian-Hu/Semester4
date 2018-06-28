/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.io.Serializable;
import java.util.List;
import javax.ws.rs.*;
import javax.ws.rs.core.*;

/**
 *
 * @author Fabian
 */
@Path("artikel")
public class ArtikelResource implements Serializable{
    
    studboardAPI api = new studboardAPI();
    
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response getArtikel(@QueryParam("id") int id){ 
        Artikel tim = api.getArticle(id);
        if (tim != null)
            return Response.ok(tim).build();
        
        return Response.status(Response.Status.NOT_FOUND).build();
    }
     
    @Path("liste")
    @GET
    @Produces(MediaType.APPLICATION_JSON)
    public Response getArtikelListe(@QueryParam("num") int num, @QueryParam("type") String type){
        List tim = api.getAllArticle();
        if (tim != null)
            return Response.ok(tim).build();
        
        return Response.status(Response.Status.NOT_FOUND).build();
    }
}
