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
public class Comment {
    
    private int id;
    private int articleId;
    private String text;
    private String rating;
    private String file;

    public Comment(int id, int articleId, String text, String rating, String file) {
        this.id = id;
        this.articleId = articleId;
        this.text = text;
        this.rating = rating;
        this.file = file;
    }

    public int getId() {
        return id;
    }

    public int getArticleId() {
        return articleId;
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
