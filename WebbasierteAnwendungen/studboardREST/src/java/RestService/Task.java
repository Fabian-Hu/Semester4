/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package RestService;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Fabian
 */
@XmlRootElement
@Entity
@Table(name = "task")
public class Task extends Artikel {
    
    @Column(name = "fach")
    String fach;

    public Task() {
    }
    
    public Task(long id, String content, String titel, String titelfarbe, String startdatum, String enddatum, String fach) {
        super(id, content, titel, titelfarbe, startdatum, enddatum);
        this.fach = fach;
        this.type = "Task";
    }
    
    public String getFach(){
        return this.fach;
    }
    
}
