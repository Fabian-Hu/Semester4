/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.io.Serializable;
import javax.persistence.Entity;
import javax.persistence.*;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Fabian
 */
@XmlRootElement
@Entity
@Table(name = "artikel")
@NamedQueries({
    @NamedQuery(name="Artikel.findAll",
        query="SELECT a FROM Artikel a"),
    @NamedQuery(name="Artikel.findById",
        query="SELECT a FROM Artikel a WHERE a.id = :id")
})
public class Artikel implements Serializable {
    
    @Id
    @GeneratedValue
    long id;
    
    @Column(name = "titel")
    String titel;
    @Column(name = "content")
    String content;
    @Column(name = "titelfarbe")
    String titelfarbe;
    @Column(name = "startdatum")
    String startdatum;
    @Column(name = "enddatum")
    String enddatum;
    @Column(name = "type")
    String type;

    public Artikel() {
    }
    
    public Artikel(long id, String content,String titel,String titelfarbe,String startdatum,String enddatum){
        this.id = id;
        this.content = content;
        this.titel = titel;
        this.titelfarbe = titelfarbe;
        this.startdatum = startdatum;
        this.enddatum = enddatum;
        this.type = "Article";
    }
    
    public String getContent(){
        return this.content;
    }
    
    public String getTitel(){
        return this.titel;
    }
    
    public String getTitelfarbe(){
        return this.titelfarbe;
    }
    
    public String getStartdatum(){
        return this.startdatum;
    }
    
    public String getEnddatum(){
        return this.enddatum;
    }
    
    public String getType(){
        return this.type;
    }
    
    public Art verkleinern(){
        return new Art(this.id,this.content,this.titel,this.type);
    }
}
