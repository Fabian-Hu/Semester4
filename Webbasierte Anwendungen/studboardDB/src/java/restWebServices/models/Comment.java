/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices.models;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.Id;
import javax.persistence.ManyToOne;
import javax.persistence.NamedQueries;
import javax.persistence.NamedQuery;
import javax.persistence.Table;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Andre
 */
@Entity
@Table(name = "comment")
@NamedQueries({
    @NamedQuery(name = "comment.findAll", query = "SELECT c FROM Comment c"),
    @NamedQuery(name = "comment.findById", query = "SELECT c FROM Comment c WHERE c.id = :id"),
    @NamedQuery(name = "comment.findByArticle", query = "SELECT c FROM Comment c WHERE c.article = :article")
})
@XmlRootElement
public class Comment implements Serializable {
    
    private int id;
    private Article article;
    private String text;
    private String rating;
    private String file;

    public Comment() {
    }

    public Comment(int id, Article article, String text, String rating, String file) {
        this.id = id;
        this.article = article;
        this.text = text;
        this.rating = rating;
        this.file = file;
    }

    @Id
    public int getId() {
        return id;
    }

    @ManyToOne
    public Article getArticle() {
        return article;
    }

    @Column(name = "text")
    public String getText() {
        return text;
    }

    @Column(name = "rating")
    public String getRating() {
        return rating;
    }

    @Column(name = "file")
    public String getFile() {
        return file;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setArticle(Article article) {
        this.article = article;
    }

    public void setText(String text) {
        this.text = text;
    }

    public void setRating(String rating) {
        this.rating = rating;
    }

    public void setFile(String file) {
        this.file = file;
    }
    
    
}
