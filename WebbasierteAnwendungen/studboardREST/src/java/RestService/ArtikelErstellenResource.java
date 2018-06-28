/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import javax.ws.rs.Consumes;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

/**
 *
 * @author Fabian
 */
@Path("artikel/erstellen")
public class ArtikelErstellenResource {
    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    public Response artikelErstellen(String json){
        System.out.println(json);
        return Response.status(Response.Status.OK).build();
    }
    
    
    
}
