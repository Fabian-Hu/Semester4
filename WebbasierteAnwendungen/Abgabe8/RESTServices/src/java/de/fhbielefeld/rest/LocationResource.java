package de.fhbielefeld.rest;

import java.io.Serializable;
import javax.ws.rs.GET;
import javax.ws.rs.Path;

/**
 *
 * @author ffehring
 */
@Path("location")
public class LocationResource implements Serializable {
    
    @GET
    @Path("get")
    public String get() {
        return "test";
    }

    
}
