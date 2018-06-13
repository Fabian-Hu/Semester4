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
public class Task extends Article{
    
    private String subject;

    public Task(String subject, int id, String title, String content, String color, String start, String end) {
        super(id, title, content, color, start, end);
        type = "Task";
        this.subject = subject;
    }

    public String getSubject() {
        return subject;
    }
}
