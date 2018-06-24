/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
@Entity
@XmlRootElement
public class Project extends Article{
    
    private String prof;
    private String freeJobs;

    public Project() {
    }

    public Project(String prof, String freeJobs, int id, String title, String content, String color, String start, String end) {
        super(id, title, content, color, start, end);
        type = "project";
        this.prof = prof;
        this.freeJobs = freeJobs;
    }

    @Column(name = "prof")
    public String getProf() {
        return prof;
    }

    @Column(name = "freeJobs")
    public String getFreeJobs() {
        return freeJobs;
    }

    public void setProf(String prof) {
        this.prof = prof;
    }

    public void setFreeJobs(String freeJobs) {
        this.freeJobs = freeJobs;
    }
    
    
}
