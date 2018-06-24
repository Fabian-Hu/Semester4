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
public class Task extends Article{
    
    private String subject;

    public Task() {
    }

    public Task(String subject, int id, String title, String content, String color, String start, String end) {
        super(id, title, content, color, start, end);
        type = "task";
        this.subject = subject;
    }

    @Column(name = "subject")
    public String getSubject() {
        return subject;
    }

    public void setSubject(String subject) {
        this.subject = subject;
    }
    
    
}
