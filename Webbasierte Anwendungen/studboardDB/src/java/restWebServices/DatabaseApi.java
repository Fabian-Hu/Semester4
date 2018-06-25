/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package restWebServices;

import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import restWebServices.models.Article;
import restWebServices.models.Comment;
import javax.annotation.Resource;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.persistence.*;
import javax.transaction.HeuristicMixedException;
import javax.transaction.HeuristicRollbackException;
import javax.transaction.NotSupportedException;
import javax.transaction.SystemException;
import javax.transaction.UserTransaction;

/**
 *
 * @author Andre
 */
public class DatabaseApi {
    
    @PersistenceContext(unitName = "studboardDBPU")
    private EntityManager em = Persistence.createEntityManagerFactory("studboardDBPU").createEntityManager();
    //@Resource
    private UserTransaction utx = null;

    public DatabaseApi() {
        try {
            this.utx = (UserTransaction) new InitialContext().lookup("UserTransaction");
        } catch (NamingException ex) {
            Logger.getLogger(DatabaseApi.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public List<Article> getArticles() {
        TypedQuery<Article> query = this.em.createNamedQuery("article.findAll", Article.class);
        List<Article> articles = query.getResultList();
        return articles;
    }
    
    public Article getArticlebyId(int id) {
        Query query = this.em.createNamedQuery("article.findById", Article.class);
        query.setParameter("id", id);
        Article article = (Article) query.getSingleResult();
        return article;
    }
    
    public List<Article> getArticlesByType(String type) {
        Query query = this.em.createNamedQuery("article.findByType", Article.class);
        query.setParameter("type", type);
        List<Article> articles = query.getResultList();
        return articles;
    }
    
    public List<Comment> getComments() {
        Query query = this.em.createNamedQuery("comment.findAll", Comment.class);
        List<Comment> comments = query.getResultList();
        return comments;
    }
    
    public Comment getCommentById(int id) {
        Query query = this.em.createNamedQuery("comment.findById", Comment.class);
        query.setParameter("id", id);
        Comment comment = (Comment) query.getSingleResult();
        return comment;
    }
    
    public List<Comment> getCommentsByArticle(int articleId) {
        Query query = this.em.createNamedQuery("comment.findByArticle", Comment.class);
        Article article = this.getArticlebyId(articleId);
        query.setParameter("article", article);
        List<Comment> comments = query.getResultList();
        return comments;
    }
    
    public void insertArticle(Article article) {
        try {
            this.utx.begin();
            this.em.persist(article);
            this.utx.commit();
        } catch (javax.transaction.RollbackException | HeuristicMixedException | HeuristicRollbackException | NotSupportedException | SystemException | SecurityException | IllegalStateException ex) {
            Logger.getLogger(DatabaseApi.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public void insertComment(Comment comment) {
        try {
            this.utx.begin();
            this.em.persist(comment);
            this.utx.commit();
        } catch (javax.transaction.RollbackException | HeuristicMixedException | HeuristicRollbackException | NotSupportedException | SystemException | SecurityException | IllegalStateException ex) {
            Logger.getLogger(DatabaseApi.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
