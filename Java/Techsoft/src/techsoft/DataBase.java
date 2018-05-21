/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package techsoft;

import java.sql.Array.*;
import java.sql.*;
import javax.swing.*;

/**
 *
 * @author Ghiath
 */
public class DataBase {
    
    String input;

    public DataBase(String i) {
        
        input = i;
        try
        {
            String url="jdbc:derby://localhost:1527/DataBase;create=true";
            String username="root";
            String password="123456";

            Connection con = DriverManager.getConnection(url,username,password);
            Statement statement = con.createStatement();
            char first_letter = input.charAt(0);
            char last_letter  = input.charAt(input.length()-1);
            String query = "SELECT * FROM ROOT.TBL_PHONEBOOK WHERE LAST_NAME LIKE '"+first_letter+"%%"+last_letter+"'";
            ResultSet rs = statement.executeQuery(query);
            
            //System.out.println(rs.next());
            
            while(rs.next()) 
            {
                 String last_name = rs.getString("last_name");
                 System.out.println(last_name);
            }
        }
        catch (SQLException ex)
        {
            JOptionPane.showMessageDialog(null, ex);
        }
    }
    
}
