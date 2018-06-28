/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package RestService;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Fabian
 */
public class ChatServer extends HttpServlet {
    private static List<String> chatVerlauf = new ArrayList<>();
    
    // 1. Load
    static {
        chatVerlauf.add("load at: "+ new Date().getTime());
    }
    
    // 2. Instanziierung
    public ChatServer(){
        chatVerlauf.add("Willkommen im Chat");
        chatVerlauf.add("Instanziierung at: " + new Date().getTime());
    }
    
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException{
        response.setContentType("text/html;charset=UTF-8");
        try(PrintWriter out = response.getWriter()){
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<body>");
            for(String chatEintrag : chatVerlauf) {
                out.println(chatEintrag+"<br />");
            }
            out.println("</body>");
            out.println("</html>");
        }
    }
    
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response){
        String user = request.getParameter("user");
        String in = request.getParameter("inhalt");
        
        chatVerlauf.add(user+": "+in);
    }
}
