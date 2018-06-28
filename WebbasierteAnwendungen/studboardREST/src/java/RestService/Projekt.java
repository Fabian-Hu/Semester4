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
@Table(name = "project")
public class Projekt extends Artikel{
    
    @Column(name = "professor")
    String professor;
    @Column(name = "plaetze")
    int plaetze;

    public Projekt() {
    }
    
    
    public Projekt(long id, String content, String titel, String titelfarbe, String startdatum, String enddatum, String professor, int plaetze) {
        super(id, content, titel, titelfarbe, startdatum, enddatum);
        this.professor = professor;
        this.plaetze = plaetze;
        this.type = "Projects";
    }
    
    public String getProfessor(){
        return this.professor;
    }
    
    public int getPlaetze(){
        return this.plaetze;
    }
}
