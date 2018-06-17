/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import java.util.ArrayList;
import java.util.List;
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
    
    protected List<Comment> comments;

    public Article(int id, String title, String content, String color, String start, String end) {
        this.id = id;
        this.title = title;
        this.content = content;
        this.color = color;
        this.start = start;
        this.end = end;
        comments = new ArrayList();
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

    public void addComment(Comment comment) {
        comments.add(comment);
    }
    
    public int[] getComments() {
        int[] ids = new int[comments.size()];
        for (int i = 0; i < comments.size(); i++)
            ids[i] = comments.get(i).getId();
        return ids;
    }
}
