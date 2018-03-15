<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS 
    <link href="css/style.css" rel="stylesheet" type="text/css" >
    <link href="{{ secure_asset('css/style.css') }}" rel="stylesheet"  type="text/css">

    -->
    
    <link href="Css/style.css" rel="stylesheet" type="text/css" >
    
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    
    <link href='https://fonts.googleapis.com/css?family=Damion' rel='stylesheet'>
    <link href='https://fonts.googleapis.com/css?family=Berkshire Swash'>
    
    <link href='https://fonts.googleapis.com/css?family=Trade Winds' rel='stylesheet'>
    <link href='https://fonts.googleapis.com/css?family=Arapey' rel='stylesheet'>
    
    
    
    <title>:: Login ::</title>
    
    <style>
    
    
    
    </style>
    
  </head>
  <body>
    <!--
    <h1>Login</h1>
    -->
    <center>
     <div class="row" id="row1"> 
       <div class="col-sm-12">
         <!-- Logo -->
         <img src="{{url('/img/logo.png')}}" width="180" height="228" >
         <!-- Logo -->
        </div>
      </div>
     
     
     <div class="row" id="row2"> 
        <div class="col-sm-12">
        
        <!-- Text before form -->
        <span class="text-secondary" style="font-family: 'Arapey';font-size: 22px;">
           You won't fight alone after today
         </span><br/>   
        <span class="text-secondary" style="font-family: 'Trade Winds';font-size: 30px;">
         Login
        </span>
        <!-- /resources/views/create.login.php -->
        
        @if ($errors->any())
            <div class="alert alert-danger" style="width:600px;">
                <ul>
                    @foreach ($errors->all() as $error)
                        <li>{{ $error }}</li>
                    @endforeach
                </ul>
            </div>
        @endif
        
        <!-- check login inputing  -->        
        <!--
        @if(!isset($data))   
            <div id='validation'>  
                
            </div>
        @else
            <div id='validation'>  
                {{{ $data['email']  }}}   <br>
                {{{ $data['password'] }}}  <br>
            </div>        
        @endif
        -->
        </div> 
     </div>
     

    
     <div class="row" id="row3"> 
       <div class="col-sm-12" >
          <div id="login">
                <!-- Login form -->
                <div id="login">
                <?php
                 echo Form::open(array('url' => '/validateLogin'));
                    
                    echo '<div class="form-group">';
                    echo Form::label('inputEmail', 'E-Mail Address :');
                    echo '<br/>';
                    echo Form::text('inputEmail', NULL, ['placeholder' => 'Email', 'id' => 'inputEmail', 'class' => 'form-control']);
                    echo '</div>';
             
                    echo '<div class="form-group">';
                    echo Form::label('inputPassword', 'Enter a password :');
                    echo '<br/>';
                    echo Form::password('inputPassword', ['placeholder' => 'Password', 'id' => 'inputPassword', 'class' => 'form-control']);
                    echo '</div>';  
                    /*
                    echo '<div class="form-group">';     
                    echo Form::label('inputPassword', 'Enter same password again :');
                    echo '<br/>';
                    echo Form::password('inputConfirmation', ['placeholder' => 'Repeat the password', 'id' => 'inputConfirmation', 'class' => 'form-control']);
                    echo '</div>';   
                    */
  
                    echo csrf_field();
                    echo '<div class="form-group">';
                    echo "if you havn't account <label>"; 
                    echo '<a href="/register" target="_NEW"> <b>Sign up</b></a>';
                    echo '</div>';
                    
                    echo '<center>';
                    echo Form::submit('Sign in', ['class' => 'btn btn-primary']);
                    echo '</center>';
                    
                 echo Form::close();
                ?>
                </div>          

          </div>
        </div> 
      </div>
     
     
     
     <div class="row" id="row4"> 
       <div class="col-sm-12">
           
           <!-- Footer Bar -->
           
           <!-- -->
       
       </div> 
     </div>
      
     
    </center>

    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
  
  
  </body>
</html>