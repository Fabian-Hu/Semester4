/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import javax.persistence.*;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Fabian
 */
@XmlRootElement
@Entity
@Table(name = "news")
public class News extends Artikel {
    
    @Column(name = "kategorie")
    String kategorie;
    @Column(name = "quellenangabe")
    String quellenangabe;

    public News() {
    }
    
    
    public News(long id, String content, String titel, String titelfarbe, String startdatum, String enddatum, String kategorie, String quellenangabe) {
        super(id, content, titel, titelfarbe, startdatum, enddatum);
        this.kategorie = kategorie;
        this.quellenangabe = quellenangabe;
        this.type = "News";
    }
    
    public String getKategorie(){
        return this.kategorie;
    }
    
    public String getQuellenangabe(){
        return this.quellenangabe;
    }
    
}
