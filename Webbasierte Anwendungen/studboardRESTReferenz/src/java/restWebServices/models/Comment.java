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
/*@Entity
@Table(name = "comment")
@NamedQueries({
    @NamedQuery(name = "comment.findAll", query = "SELECT c FROM Comment c"),
    @NamedQuery(name = "comment.findById", query = "SELECT c FROM Comment c WHERE c.id = :id"),
    @NamedQuery(name = "comment.findByArticle", query = "SELECT c FROM Comment c WHERE c.article = :article")
})*/
@XmlRootElement
public class Comment implements Serializable {
    
    //@Id
    //@GeneratedValue
    private int id;
    //@ManyToOne
    private Article article;
    //@Column(name = "text")
    private String text;
    //@Column(name = "rating")
    private String rating;
    //@Column(name = "file")
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

    public int getId() {
        return id;
    }

    public int getArticleId() {
        return article.getId();
    }

    public String getText() {
        return text;
    }

    public String getRating() {
        return rating;
    }

    public String getFile() {
        return file;
    }
}
