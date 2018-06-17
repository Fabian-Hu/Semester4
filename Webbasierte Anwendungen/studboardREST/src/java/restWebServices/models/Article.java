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
public class Article {
    
    protected int id;
    protected String title;
    protected String content;
    protected String color;
    protected String start;
    protected String end;
    protected String type = "article";

    public Article(int id, String title, String content, String color, String start, String end) {
        this.id = id;
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.end = end;
    }

    public int getId() {
        return id;
    }

    public String getTitle() {
        return title;
    }

    public String getContent() {
        return content;
    }

    public String getColor() {
        return color;
    }

    public String getStart() {
        return start;
    }

    public String getEnd() {
        return end;
    }

    public String getType() {
        return type;
    }

}
