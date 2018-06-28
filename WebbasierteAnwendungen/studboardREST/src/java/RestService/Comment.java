/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.io.Serializable;
import javax.persistence.*;
import javax.xml.bind.annotation.XmlRootElement;

/**
 *
 * @author Fabian
 */
@XmlRootElement
@Entity
@Table(name = "comment")
@NamedQueries({
    @NamedQuery(name="Comment.findAll",
        query="SELECT c FROM Comment c"),
    @NamedQuery(name="Comment.findById",
        query="SELECT c FROM Comment c WHERE c.id = :id")
})
public class Comment implements Serializable {
    @Id
    @GeneratedValue
    long id;
    @Column(name = "article_id")
    long article_id;
    @Column(name = "text")
    String text;
    @Column(name = "rating")
    String rating;
    @Column(name = "file")
    String file;

    public Comment() {
    }
    
    public Comment(long id, long article_id, String text, String rating, String file) {
        this.id = id;
        this.article_id = article_id;
        this.text = text;
        this.rating = rating;
        this.file = file;
    }
    
    public long getId(){
        return this.id;
    }
    
    public long getArticle_id(){
        return this.article_id;
    }
    
    public String getText(){
        return this.text;
    }
    
    public String getRating(){
        return this.rating;
    }
    
    public String getFile(){
        return this.file;
    }
}
