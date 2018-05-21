/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package techsoft;

import java.util.Arrays;
import java.util.List;

/**
 *
 * @author Ghiath
 */
public class Techsoft {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Searcher searcher = new Searcher();
              
        /* The solutions of the stages */
        System.out.println("######### Stufe 1 #########");
        //Exactly like the demand : 
        searcher.Stufe1();
        
        System.out.println("######### Stufe 2 #########");
        //Exactly like the demand : 
        searcher.Stufe2();
        
        System.out.println("######### Stufe 3 ######### ");
        // I was wanting to use the Sql statment in this way : 
        // " select *  from tbl_phonebook where soundex("last_name") = soundex('RUESSWURM');"
        // but unfortunatly the soundex function is not available with Derby Database ,  
        // So I have selected the values of output depend on the first letter and the last letter of the input value 
        searcher.Stufe3();
        
    }

    
    
}
