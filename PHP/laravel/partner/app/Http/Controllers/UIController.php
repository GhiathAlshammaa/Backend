<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

use App\laravel;

use Illuminate\Support\Facades\Input;

// use Illuminate\Support\Facades\Hash;

use Hash;

use DB;

//use App\Http\Requests\LoginPost;


class UIController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
     
     
    public function welcome()
    {
        //

        return view('welcome');

    }
   
    public function index()
    {
        //
        return view('login');

    }
   
    public function login(Request $request)
    {
        //
        //$user = new laravel;
        // Validation 
        
        $method = $request->method();
        
        if ($request->isMethod('POST')) 
        {
            $email = $request->input("inputEmail");
            $password = $request->input("inputPassword");
                
            $data = array("email"=>$email,"password"=>$password);
            
            // Validation operation 
            if ($validator->fails()) {
                return redirect('login')
                            ->withErrors($validator)
                            ->withInput();
            }
            else
            {
                return view('login')->with('data', $data);
            }
            // End validation 
            
        }
        else
        {
            return view('login');
        }
        
    }
       
    public function validateLoginform(Request $request)
    {
      // put the value which came from the form into varibles 
      print_r($request->all());
      $this->validate($request,[
         'inputEmail'=>'required|email',
         'inputPassword'=>'required|min:3|max:20'
      ]);
   }
    
    
    public function register(Request $request)
    {
        // Check the kind of the Form (post or Get)
        $method = $request->method();
        if ($request->isMethod('POST')) 
        {
            $username = $request->input("inputUsername");
            $email    = $request->input("inputEmail");
            $password = $request->input("inputPassword");
            $note     = $request->input("inputNote");
                
            $data = array("username"=>$username,"email"=>$email,
                          "password"=>$password,"note"=>$note );
            return view('register')->with('data', $data);
        }
        else
        {

            return view('register');
        }
    }
    
    public function validateRegisterform(Request $request)
    {
      // The validation of the fields  
      $this->validate($request,[
         'inputUsername'=>'required',
         'inputEmail'=>'required|email',
         'inputPassword'=>'required|min:3|max:20',
         'inputConfirmation'=>'required|min:3|max:20|required_with:inputPassword|same:inputPassword'
      ],[
    	  'inputUsername.required' => ' The username field is required.',
    	  'inputPassword.min' => ' The password must be at least 8 characters.',
    	  'inputPassword.max' => ' The password may not be greater than 20 characters.',
    	  'inputEmail.required' => ' The Email field is required.',
    	]);

        // echo("Username:" . $username ."<br>");
        // echo("Email:"    . $email ."<br>");
        // echo("Password:" . $password ."<br>");
        // 	dd('You are successfully added all fields.');
        
            
        $user = new laravel;
        $method = $request->method();
        
        if ($request->isMethod('POST')) 
        {
            
            // The values of columns
            $username = $request->input('inputUsername');
            $email    = $request->input('inputEmail');
            $password = $request->input('inputPassword');
            $hashedPassword = Hash::make($password);
                    
            // The Record is already in the database. user must to enter another values
            $results = DB::table('users')
                         ->where('username', $username)
                         ->orWhere('email', $email)->get();      
                          
            if($results) 
            {

                flash('This Username or email is already inside the database.<br>
                       So you must to inputting another values')->error();
                return view("register");
            }
            else
            {
                flash('This information was not  in the database before.')->success();
                // return view("register");
                
                // incress the user if a one before insert a new record 
                $last_id = DB::table('users')->max('id');
                $last_id +=1;
                    
                // insertion record to the category table
                $data = array("id"=>$last_id,"username"=>$username,"email"=>$email,"password"=>$hashedPassword );
                $insert=DB::table('users')->insert($data);
                
                if($insert) 
                {
                        
                    flash('Success saved a new record into Database')->success();
                    return view("register");
                    
                // // send value to show the view 
                // $data = DB::table('users')->get();
                // if ($data)
                // {
                //   return view('register')->with('data', $data);  
                //     }
                //     else
                //     {
                //       $data = array("id"=>0,"username"=>'',"email"=>'',"password"=>'' );
                //       return view('register')->with('data', $data); 
                //     }
                    
                }
                else
                {
                    flash('The insertation is not success')->error();
                    return view("register");
                }
             }
                        
        }
    }// end the function 
    

    

    /**
     * Show the form for creating a new resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function create()
    {
        //
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function store(Request $request)
    {
        //
    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        //
    }

    /**
     * Show the form for editing the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function edit($id)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \Illuminate\Http\Request  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(Request $request, $id)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy($id)
    {
        //
    }
}
