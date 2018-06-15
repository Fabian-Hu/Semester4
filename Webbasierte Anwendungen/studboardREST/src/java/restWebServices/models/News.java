/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
@XmlRootElement
public class News extends Article{
    
    private String source;

    public News(String source, int id, String title, String content, String color, String start, String end) {
        super(id, title, content, color, start, end);
        type = "news";
        this.source = source;
    }

    public String getSource() {
        return source;
    }
}
