/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package techsoft;
import static java.lang.Math.log;
import static java.rmi.server.LogStream.log;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;
import java.lang.Exception;

/**
 *
 * @author Ghiath
 */
public class Searcher 
{
    // Attributes for the inputing operation 
    private Scanner  input ;
    private String input_user;
    
    // Attributes for a converting operation
    private List<String> umlaut_letters;
    private List<String> umlaut_words;

    public Searcher()
    {
        // initialize Attributes
        this.umlaut_letters = new ArrayList<String>();
        this.umlaut_words   = new ArrayList<String>();
        
        // Reading a input from a User, when the program starts
        // taking value from the user  
        Enter_value_from_User();
        // specify the available umlaut letters then put them in list 
        this.setUmlaut_letters(this.input_user);
        // generate the words with umlaut letters then put them in list
        this.setUmlaut_words(this.umlaut_letters);
    }
    
    // The solution of stufe 1 of the assignment
    public void Stufe1()
    {
        String input = new String (this.getInput_user()); 
        List<String> letters = this.getUmlaut_letters();
        
        for(String item:letters)
            {
                if(input.contains(item))
                {
                    String l = conver_letter_to_umlaute(item);
                    input = input.replaceAll(item,l);
                }
            }
        System.out.println(input);
    }
    
    // The solution of stufe 2 of the assignment
    public void Stufe2()
    {
        System.out.print("(");
        this.getUmlaut_words().forEach(result -> System.out.print(result + ","));
        System.out.print(")");
        System.out.println();
    }
    
     // The solution of stufe 3 of the assignment
    public void Stufe3()
    {
        DataBase database = new DataBase(this.input_user);
    }

    public String getInput_user() {
        return input_user;
    }

    public void setInput_user(String input_user) {
        this.input_user = input_user;
    }

    public List<String> getUmlaut_letters() {
        return umlaut_letters;
    }
    
    // specify the available umlaut letters then put them in list
    public void setUmlaut_letters(String input_user) {

            if (input_user.contains("AE"))
            {
                //this.umlaut_letters.add("Ä");
                this.umlaut_letters.add("AE");
            }
            
            if (input_user.contains("OE"))
            {
                //this.umlaut_letters.add("Ö"); 
                this.umlaut_letters.add("OE");
            }
            
            if (input_user.contains("UE"))
            {
                //this.umlaut_letters.add("Ü"); 
                this.umlaut_letters.add("UE");
            }
            
            if (input_user.contains("SS"))
            {
                //this.umlaut_letters.add("ß");  
                this.umlaut_letters.add("SS");
            }
    }
    
    public List<String> getUmlaut_words() {
        return this.umlaut_words;
    }
    
    // generate the words with umlaut letters then put them in list
    public void setUmlaut_words(List<String> umlaut_letters) {
        this.umlaut_words.add(this.input_user);
        String input1 = new String (this.getInput_user());
        String input = new String (this.getInput_user()); 
        List<String> letters = this.getUmlaut_letters();
                    
            String word ; 
            if (input.contains("AE"))
            {
                word="AE";
                this.umlaut_words.add(input.replaceAll(word, "Ä"));
            }
            
            if (input.contains("OE"))
            {
                word="OE";
                this.umlaut_words.add(input.replaceAll(word, "Ö"));
            }
            
            if (input.contains("UE"))
            {
                word="UE";
                this.umlaut_words.add(input.replaceAll(word, "Ü"));
            }
            
            if (input.contains("SS"))
            {
                word="SS";
                this.umlaut_words.add(input.replaceAll(word, "ß"));
            }
            
            for(String item:letters)
            {
                if(input1.contains(item))
                {
                    String l = conver_letter_to_umlaute(item);
                    input1 = input1.replaceAll(item,l); 
                }
            }
            this.umlaut_words.add(input1);      
    }

    // taking value from the user 
    private void Enter_value_from_User() {
        
        String input_str="";
        
        try
        {
            System.out.println("Enter a Name (value should to be only String): ");
            input = new Scanner(System.in);
            input_str = input.nextLine();
            
            
            if(input_str.matches(".*\\d.*"))
            {
                throw new IllegalArgumentException ();
            }
            else
            {
                setInput_user(input_str.toUpperCase());
            }

        }
        catch (IllegalArgumentException e) 
        {
		System.out.println(" Entered value is wrong, you should enter only a string ");
	} 
        finally
        {
            input.close();
        }       
    }
    
    // converfrom normal letter to umlaute letter
    public String conver_letter_to_umlaute(String item) 
    {  
        switch(item)
        {    
            case "AE":
                return "Ä";
            case "OE":
                return "Ö";
            case "UE":
                return "Ü";
            case "SS":
                return "ß";
            default:
                return item;
        }
    }
    

}
    

