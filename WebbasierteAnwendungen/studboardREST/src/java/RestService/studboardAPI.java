/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.util.List;
import javax.annotation.Resource;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;
import javax.transaction.UserTransaction;

/**
 *
 * @author Fabian
 */
public class studboardAPI {
    
    /**
    * Entity Manager em, basierend auf der in presistence.xml ge-
    * speicherten Datenbankverbindung
    */
    @PersistenceContext(unitName = "studboardRESTPU")
    private EntityManager em;
    /**
    * User Transaction utx zur Kommunikation mit Datenbank
    */
    @Resource
    private UserTransaction utx;

    public Artikel getArticle(int id) {
        Query query = this.em.createNamedQuery("Artikel.findById", Artikel.class);
        query.setParameter("id", id);
        Artikel article = (Artikel) query.getSingleResult();
        return article;
    }
    
    public List getAllArticle() {
        Query query = this.em.createNamedQuery("Artikel.findAll", Artikel.class);
        List article = query.getResultList();
        return article;
    }
    
    public Comment getComment(int id) {
        Query query = this.em.createNamedQuery("Comment.findById", Artikel.class);
        query.setParameter("id", id);
        Comment comment = (Comment) query.getSingleResult();
        return comment;
    }
    
    public List getAllComment() {
        Query query = this.em.createNamedQuery("Comment.findAll", Artikel.class);
        List comment = query.getResultList();
        return comment;
    }
}
