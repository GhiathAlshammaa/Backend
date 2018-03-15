<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

use App\Http\Requests;

use App\laravel;

use Illuminate\Support\Facades\Input;

use DB;

class Category extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index(Request $request)
    {
        $user = new laravel;
        $method = $request->method();
        
        if ($request->isMethod('get')) 
        {
            $id = $request->id ;
            $ope = $request->ope ;
            //$id =$request->route()->getParameter('id');
            
            $check_record = DB::table('category')->where('id', $id);
            
            if($check_record){
                if (!is_null($id) && $ope="del" )
                {
                    flash('Success remove a record which has a id number : ('. $id .')')->success();
                     DB::table('category')->where('id',$id)->delete();
                }
            }
            else
            {
                
              flash('unsuccess remove a record which has a id number : ('. $id .')')->error();  
                
            }
            
            /*
            else
            {
                flash('Unsuccess remove a record')->error();
            } 
            */
             
            
            $data = DB::table('category')->get();
            if ($data)
            {
              return view('category')->with('data', $data);  
            }
            else
            {
               $data = array("id"=>0,"title"=>'',"note"=>'' );
               return view('category')->with('data', $data); 
            }
            
            //return View('category', compact('data'));
           
        }else{
            
            print_r($request->all());
            $this->validate($request,
            [
                'title'=>'required',
                'note'=>'required'
            ]);
                    
            
            $title = $request->input('title');
            $note  = $request->input('note');
            $last_id = DB::table('category')->max('id');
            $last_id +=1;
                    
                // This data is already inside database. you must to enter another values
                $results = DB::table('category')
                            ->where('title', $title)
                            ->orWhere('note', $note)->get();      
                          
                if($results) 
                {
                    flash('This data is already inside database. you must to enter another values')->error();
                    return view("category");
                }
                else
                {
                    // insertion record to the category table
                    $data = array("id"=>$last_id,"title"=>$title,"note"=>$note );
                    $insert=DB::table('category')->insert($data);
                    if($insert) 
                    {
                        
                        flash('Success saved a new record into Database')->success();
                        //return view("category");
                        
                        // send value to show the view 
                        $data = DB::table('category')->get();
                        if ($data)
                        {
                          return view('category')->with('data', $data);  
                        }
                        else
                        {
                           $data = array("id"=>0,"title"=>'',"note"=>'' );
                           return view('category')->with('data', $data); 
                        }
                        
                    }
                    else
                    {
                        flash('The insertation is not success')->error();
                        return view("category");
                    }
                }

    }// end function
    
    }
    
    public function validateform(Request $request)
    {
        
    $method = $request->method();
    $user = new laravel;
        if ($request->isMethod('post')) 
        {

                    print_r($request->all());
                    $this->validate($request,
                      [
                         'title'=>'required',
                         'note'=>'required'
                    ]);
                    
                     
                    $title = $request->input('title');
                    $note = $request->input('note');
                    $last_id = DB::table('category')->max('id');
                    $last_id +=1;
                    
                    // This data is already inside database. you must to enter another values
        
                    $results = DB::table('category')
                            ->where('title', $title)
                            ->orWhere('note', $note)->get();      
                          
                        if($results) 
                        {
                            flash('This data is already inside database. you must to enter another values')->error();
                            return view("category");
                        }
                        else
                        {
                            // insertion record to the category table
                            $data = array("id"=>$last_id,"title"=>$title,"note"=>$note );
                            $insert=DB::table('category')->insert($data);
                            if($insert) 
                            {
                                flash('Success saved a new record into Database')->success();
                                //return view("category");
                                
                                // send value to show the view 
                                $data = DB::table('category')->get();
                                if ($data)
                                {
                                  return view('category')->with('data', $data);  
                                }
                                else
                                {
                                   $data = array("id"=>0,"title"=>'',"note"=>'' );
                                   return view('category')->with('data', $data); 
                                }
                            }
                            else
                            {
                                flash('The insertation is not success')->error();
                                return view("category");
                            }
                       }
                       
        } // end first if 
        
   }// end function

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


    }

    /**
     * Display the specified resource.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function show($id)
    {
        // view
        $users = DB::table('category')
                    ->orderBy('id', 'desc')
                    ->groupBy('id')->get();
        
        return view("category");
        
        
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

}// end class
