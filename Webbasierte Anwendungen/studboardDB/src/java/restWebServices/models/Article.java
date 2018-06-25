/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
@Entity
@Table(name = "article")
@NamedQueries({
    @NamedQuery(name = "article.findAll", query = "SELECT a FROM Article a"),
    @NamedQuery(name = "article.findById", query = "SELECT a FROM Article a WHERE a.id = :id"),
    @NamedQuery(name = "article.findByType", query = "SELECT a FROM Article a WHERE a.type = :type")
})
@XmlRootElement
public class Article implements Serializable {
    
    protected int id;
    protected String title;
    protected String content;
    protected String color;
    protected String start;
    protected String ende;
    protected String type = "article";

    public Article() {
    }

    public Article(int id, String title, String content, String color, String start, String end) {
        this.id = id;
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.ende = end;
    }
    
    @Id
    public int getId() {
        return id;
    }
    
    public void setId(int id) {
        this.id = id;
    }

    @Column(name = "title")
    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }
    
    @Column(name = "content")
    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }
    
    @Column(name = "color")
    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }
    
    @Column(name = "start")
    public String getStart() {
        return start;
    }

    public void setStart(String start) {
        this.start = start;
    }
    
    @Column(name = "ende")
    public String getEnde() {
        return ende;
    }

    public void setEnde(String ende) {
        this.ende = ende;
    }
    
    @Column(name = "type")
    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }
}
