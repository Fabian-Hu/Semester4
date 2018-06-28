/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import javax.xml.bind.annotation.XmlRootElement;
/**
 *
 * @author Fabian
 */
@XmlRootElement
public class Art {
    
    long id;
    String titel;
    String kurzbeschreibung;
    String type;
    
    public Art(long id, String kurzbeschreibung, String titel, String type){
        this.id = id;
        this.kurzbeschreibung = kurzbeschreibung;
        this.titel = titel;
        this.type = type;
    }
    
    public String getKurzbeschreibung(){
        return this.kurzbeschreibung;
    }
    
    public String getTitel(){
        return this.titel;
    }
    
    public long getId(){
        return this.id;
    }
    
    public String getType(){
        return this.type;
    }
    
}
