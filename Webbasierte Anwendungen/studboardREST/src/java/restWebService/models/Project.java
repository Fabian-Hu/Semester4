/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebService.models;

import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
@XmlRootElement
public class Project extends Article{
    
    private String prof;
    private String freeJobs;

    public Project(String prof, String freeJobs, int id, String title, String content, String color, String start, String end) {
        super(id, title, content, color, start, end);
        type = "Project";
        this.prof = prof;
        this.freeJobs = freeJobs;
    }

    public String getProf() {
        return prof;
    }

    public String getFreeJobs() {
        return freeJobs;
    }
}
