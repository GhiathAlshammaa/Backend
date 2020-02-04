using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Configuration;
using System.Data;
using System.IO;
using System.Windows.Forms;


public partial class _Default : System.Web.UI.Page
{
    // varibles containts the query, which we will use them 
    string select;
    string update;
    string delete;

    // counters, to counts the times 
    static int counter;
    static int oldcounter;

    // Database Connection Varibles
    DataTable dt = new DataTable("cars");
    SqlConnection con = new SqlConnection(ConfigurationManager.ConnectionStrings["dbconnect"].ConnectionString);
    // Select query varibles
    SqlCommand cmd_select;
    SqlDataReader reader;
    // Update query varibles
    SqlCommand cmd_update;
    
    // Loading page 
    protected void Page_Load(object sender, EventArgs e)
    {
        // At first time the page loading, the code should to intialize this varibles
        if (IsPostBack == false)
        {
            DropDownList1.SelectedIndex = 0;
            counter = 0;
            oldcounter = 0;
            DropDownList1.Enabled = false;

            Label1.ForeColor = System.Drawing.Color.Blue;
            Label1.Text = "Status: Start";
        }
    }

    // Next Button
    protected void Button1_Click(object sender, EventArgs e)
    {
        // this lable resbonsible about give the result of the updateing or deleting operations
        Label2.Text = " ";

        // I puted my code inside Exception to avoid the run time Error 
        try
        {
            // I did this if statment, because I have no 0 Id in my table, that will handle with first time of run time 
            if (counter > 0)
            {
                 select = "select * from car where id =" + counter;
            }
            else
            {
                 select = "select * from car";
            }

            // open a connection with Database
            con.Open();
            // here I Executed my select query 
            cmd_select = new SqlCommand(select, con);
            reader = cmd_select.ExecuteReader();
            
            // while I have a rows come from database, fill the Elments on the User Interface
            if (reader.Read())
            {
                counter = Convert.ToInt32(reader["id"]);
                DropDownList1.Enabled = true;
                DropDownList1.SelectedValue=reader["category"].ToString();
                Image1.ImageUrl = "~/img/" + reader["img"].ToString() ;
                Label1.ForeColor = System.Drawing.Color.Green;
                Label1.Text = "Status: Ongoing";

                // here I tried to execute the updating action automaticaly inside the Next button, but that didn't success 
                oldcounter = counter;
                /*
                reader.Close();
                update = "Update car set category='" + DropDownList1.SelectedValue + "' Where Id='" + oldcounter + "'";
                cmd_update = new SqlCommand(update, con);
                cmd_update.ExecuteNonQuery();
                */

                // After finish the Display of the informations, incress the counter 
                counter++;
            }
            else
            {
             // after the rows is finished, appear to my particular photo, and change the label1 ("Finished")
             counter = 0;
             Image1.ImageUrl = "~/img/" + "finish.jpg";
             DropDownList1.SelectedIndex = 0;
             DropDownList1.Enabled = false;

             Label1.ForeColor = System.Drawing.Color.Red;
             Label1.Text = "Status: finished";
             
            }
        }
        // If the code occures Error during the run time, The code will handle with it and appear a Message explains the Reson of this Error 
        catch (Exception ex)
        {
            MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }
        // at all the cases, close the connection with Database and the SqlDataReader
        finally
        { 
            reader.Close();
            con.Close();
        }
    }

    // Update Button 
    protected void Button2_Click(object sender, EventArgs e)
    {
        // by this sql query the code will update a particular row's category on Database, depend on the ID
        update = "Update car set category='"+ DropDownList1.SelectedValue +"' Where Id= "+ oldcounter;
        cmd_update = new SqlCommand(update, con);

        // open a connection with Database, and execute the update query 
        con.Open();
        cmd_update.ExecuteNonQuery();

        // after the Update opeartion successfuly, it will appear message and change the containt of label
        Label2.Text = "Update Successfuly";
        MessageBox.Show("Update Successfuly", "Update", MessageBoxButtons.OK, MessageBoxIcon.Information);
        Label1.ForeColor = System.Drawing.Color.Green;
        Label1.Text = "Status: Ongoing";

        // close connection with Database
        con.Close();
        
    }

    // Delete Button
    protected void Button3_Click(object sender, EventArgs e)
    {
        // by this sql query the code will Delete a particular row's on Database, depend on the ID
        delete = "Delete From car Where Id= " + oldcounter;
        cmd_update = new SqlCommand(delete, con);

        // open a connection with Database, and execute the update query 
        con.Open();
        cmd_update.ExecuteNonQuery();

        // after the Delete opeartion successfuly, it will appear message and change the containt of label
        Label2.Text = "Delete Successfuly";
        MessageBox.Show("Delete Successfuly", "Delete", MessageBoxButtons.OK, MessageBoxIcon.Information);
        Label1.ForeColor = System.Drawing.Color.Green;
        Label1.Text = "Status: Ongoing";
    
        con.Close();
    }
}