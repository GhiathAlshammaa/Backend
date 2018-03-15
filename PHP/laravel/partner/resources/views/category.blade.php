<!DOCTYPE html>
<html>
    <head>
    <title>:: Category ::</title>
      <meta charset="utf-8">
      <meta name="viewport" content="width=device-width, initial-scale=1">
      <link rel="stylesheet" href="//maxcdn.bootstrapcdn.com/bootstrap/3.3.5/css/bootstrap.min.css">
      
      <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css">
      <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
      <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js"></script>
      <script src="https://code.jquery.com/jquery-latest.min.js"></script>
      <script type="text/javascript" src="./js/jquery-latest.min.js"></script>
    <script>
      /* global $ */
      /* global location */
        
        $(document).ready(function() {
           var hash = window.location.hash;
        
           if (hash != "")
               $('#tabs a[href="' + hash + '"]').tab('view');
           else
               $('#tabs a:first').tab('view');
        });
    </script>
    
    
    <style>
    .body1 {
        margin-top:-90px;
        /*overflow: hidden;*/
    }
    
    .jumbotron{
        margin-bottom:0px;
    }
    
    .card-body{
        margin-bottom:0px;   
    }
    
    .nav {
       margin-top:-15px;  
    }
    
    #row1{
        border: 0px solid #0000ff;
        margin-bottom: 10px;
    }
    
    #side-menu-box{
        border: 0px solid #0000ff;
        padding: 80px 0px 0px 10px ;
    }
    
    .btn-group-vertical
    {
        width:180px;
    }
    
    #content-box{
      border: 0px solid #0000ff;  
    }
    
    #msg{
      border: 0px solid #0000ff;  
    }    
    
    .jumbotron
    {
        background-color: #ffff00 !important;
        
    }
    
    .table
    {
      font-size: 16px;
    }
    
    
    </style>
    </head>
    
    <body class="body1">
    
    <br/><br/><br/><br/>
     
    <div class="container" id="container">
        
        <!--Begin Row1-->
        <div class="row" id="row1">
            <div class="col-sm-12">
                <div class="jumbotron">
                  <h1><img src="{{ url('/img/cms.png') }}" width="56" height="65" ></img>CMS</h1>
                </div>
                

            </div> <!--End col-sm-12-->
        </div><!--End Row1--> 
        
        <!--Begin Row2-->
        
        <div class="row">
            <div class="col-sm-2" id="side-menu-box">
                
                <div class="btn-group-vertical">
                    <button type="button" class="btn btn-primary active">Category</button>
                    <button type="button" class="btn btn-primary">Targets</button>
                    <button type="button" class="btn btn-primary">Targets Type</button>
                    <button type="button" class="btn btn-primary">Sub-Targets</button>
                    <button type="button" class="btn btn-primary">Progression Stages</button>
                </div>
                
            </div>
        
            <div class="col-sm-10" id="content-box"> 
    
               <div class="bg-primary text-white">
                <div class="card-body">
                    <h3>Category Managment</h3>
                </div>
              </div>
            
            <div id="msg"> @include('flash::message')</div>
            
            @if (count($errors) > 0)
            <div class = "alert alert-danger">
                <ul>
                    @foreach ($errors->all() as $error)
                          <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
            @endif
                
              <br>
              <!-- Nav tabs -->
              <ul class="nav nav-tabs"  role="tablist" id="tabs">
                <li class="nav-item"  class="active">
                  <a class="nav-link active" data-toggle="tab" href="#add">Add</a>
                </li>
                <li class="nav-item" id="nav-item-view">
                  <a class="nav-link " data-toggle="tab" href="#view" >
                      View
                  </a>
                </li>
                
                <li class="nav-item">
                  <a class="nav-link" data-toggle="tab" href="#edit">Edit</a>
                </li>  
                
                <!--
                <li class="nav-item">
                  <a class="nav-link" data-toggle="tab" href="#remove">Remove</a>
                </li>
                -->
              </ul>
            
              <!-- Tab panes -->
              <div class="tab-content" id="myTabContent" >
                <div id="add" class="container tab-pane active"><br>
                <h3>Add a new category :</h3> <br>
                
                {{ Form::open(array('url' => './category', 'method' => 'POST')) }}
                <h4>Category title</h4>
      				  {{ Form::text('title')}}<br><br>
      			 <h4>Category note</h4>
      				  {{ Form::textarea('note', null, ['size' => '60x10']) }}<br><br>
      				  {!! csrf_field() !!}
      				  {{ Form::submit('Add') }}
                {{ Form::close() }}
                </div>
                
                <div id="view" class="container tab-pane fade"><br>
                <h3>Display a Category table records :</h3><br>
                
                <a href="" id="view"></a>
                <table class="table">
                <thead class="thead-light">
        				  <tr>
          					<th>Id</th>
          					<th>Title</th>
          					<th>Note</th>
          					<th></th>
          					<th></th>
        				  </tr>
        				  
        				  @foreach($data as $data)
          				  <tr>
          				      <td>{{$data->id}}</td>  
            				  <td>{{$data->title}}</td>
            				   <td>{{$data->note}}</td>
            				   <td>
                				  <a href='category?id={{$data->id}}&&ope=del'>
                				  <img src="{{url('/img/x.png')}}" ></img>
                				  </a>
            				    </td>
            					<!--
            					<a href="#?id=>
              			        -->
            				</tr>	
            				
            		      @endforeach
            		
        				</thead>
        				<tbody>
                   
                    <tr>
          				    <td></td>  
            					<td></td>
            					<td></td>
            				</tr>	
               


          			 </tbody>
        			  </table>

                 
                 
                </div>
                <div id="edit" class="container tab-pane fade"><br>

                    <h3>Update the category  :</h3> <br>
                    
                    {{ Form::open(array('url' => './category', 'method' => 'POST')) }}
                    <h4>Category title</h4>
                      
                    <select name="title">
                        <option value="1"> Mental aims </option>
                        <option value="2"> Physical aims </option>
                        <option value="3"> Finincial aims </option>
                    </select><br><br>
                           
          			    <h4>Category note</h4>
          				  {{ Form::textarea('note', null, ['size' => '60x10']) }}<br><br>
          				  {!! csrf_field() !!}
          				  {{ Form::submit('update') }}
                    {{ Form::close() }}
                    
                </div>
                
                <!--
                <div id="remove" class="container tab-pane fade"><br>
                  <h3>Remove</h3>
                  <p> Remove code ... </p>
                </div>
                -->
                
              </div>
            </div>
        
        
        </div><!--End Row2--> 
    
 </div><!--End Contener--> 

     
    </body>
</html>
