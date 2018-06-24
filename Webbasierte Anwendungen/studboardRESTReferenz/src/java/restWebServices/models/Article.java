/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
/*@Entity
@Table(name = "article")
@NamedQueries({
    @NamedQuery(name = "article.findAll", query = "SELECT a FROM Article a"),
    @NamedQuery(name = "article.findById", query = "SELECT a FROM Article a WHERE a.id = :id"),
    @NamedQuery(name = "article.findByType", query = "SELECT a FROM Article a WHERE a.type = :type")
})*/
@XmlRootElement
public class Article implements Serializable {
    
    //@Id
    //@GeneratedValue
    protected int id;
    //@Column(name = "title")
    protected String title;
    //@Column(name = "content")
    protected String content;
    //@Column(name = "color")
    protected String color;
    //@Column(name = "start")
    protected String start;
    //@Column(name = "ende")
    protected String end;
    //@Column(name = "type")
    protected String type = "article";
    
    //protected List<Comment> comments;

    public Article() {
    }

    public Article(int id, String title, String content, String color, String start, String end) {
        this.id = id;
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.end = end;
        //comments = new ArrayList();
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

    /*public void addComment(Comment comment) {
        comments.add(comment);
    }
    
    public int[] getComments() {
        int[] ids = new int[comments.size()];
        for (int i = 0; i < comments.size(); i++)
            ids[i] = comments.get(i).getId();
        return ids;
    }*/
}
