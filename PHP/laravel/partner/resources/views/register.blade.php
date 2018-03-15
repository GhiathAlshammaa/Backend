<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS 
    <link href="css/style.css" rel="stylesheet" type="text/css" >
    -->
    
    <link href="Css/style.css" rel="stylesheet" type="text/css" >
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <link href='https://fonts.googleapis.com/css?family=Damion' rel='stylesheet'>
    <link href='https://fonts.googleapis.com/css?family=Berkshire Swash'>
    <link href='https://fonts.googleapis.com/css?family=Trade Winds' rel='stylesheet'>
    <link href='https://fonts.googleapis.com/css?family=Arapey' rel='stylesheet'>
    <script src="https://code.jquery.com/jquery-latest.min.js"></script>
    
    <script src="//code.jquery.com/jquery.js"></script>
    <script src="//maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>

    
    <style>
    #msg{
      /*border: 0px solid #0000ff;*/
      width : 400px;
      font-size:12px;
    }
    </style>
    
    
    <title>:: Register ::</title>
    <script> 
    /*
      if( <? //=$errors->has('inputEmail')?>){
        $('#inputEmail').css('border-color', 'red');
      }
     */
    </script>
    
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
         Register
         </span>
         
        <div id="msg"> @include('flash::message')</div>
        
        <!-- Text before form
        @if(count($errors))
    	<div class="alert alert-danger" style="width:600px;">
    		<strong>Whoops!</strong> There were some problems with your input.<br/>
    		<ul>
    			@foreach($errors->all() as $error)
    			<li>{{ $error }}</li>
    			@endforeach
    		</ul>
    	</div>
        @endif 
        -->
         
        <!-- 
        @if(!isset($data))   
            <div id='validation'>  
            </div>
        @else
            <div id='validation'>  
                {{{ $data['username']  }}}   <br>
                {{{ $data['email'] }}}  <br>
                {{{ $data['password'] }}}  <br>
                {{{ $data['note'] }}}  <br>                
            </div>        
        @endif
        -->
         
        </div> 
     </div>
     

    
     <div class="row" id="row3"> 
       <div class="col-sm-12" >
          <div id="register" class="register">
              
                <!-- Register form -->
                <div id="register" class="register">
                <?php
                 echo Form::open(array('url' => '/validateRegister', 'method' => 'POST'));

                    //echo "<div class='form-group'>";
                    //echo " <div class='form-group {{ $errors->has('inputUsername') ? 'has-error' : '' }}'>";
                ?>
                    <div class="form-group {{ $errors->has('inputUsername') ? 'has-error has-feedback' : '' }}">
                <?php
                    
                    echo Form::label('inputUsername', 'Username :');
                    echo '<br/>';
                    echo Form::text('inputUsername', old('inputUsername') , ['placeholder' => 'Username', 'id' => 'inputUsername', 'class' => 'form-control {{ $errors->has("inputUsername") ? "has-error" : "" }}']);
                    echo '<span class="text-danger">'.$errors->first('inputUsername').'</span>';
                    echo '</div>';
                    
                    echo "<div class='form-group'>";
                    echo Form::label('inputEmail', 'E-Mail Address :');
                    echo '<br/>';
                    echo Form::text('inputEmail',  old('inputEmail') , ['placeholder' => 'Email', 'id' => 'inputEmail', 'class' => 'form-control']);
                    echo '<span class="text-danger">'.$errors->first('inputEmail').'</span>';                    
                    echo '</div>';
             
                    echo "<div class='form-group'>";
                    echo Form::label('inputPassword', 'Enter a password :');
                    echo '<br/>';
                    echo Form::password('inputPassword', ['placeholder' => 'Password', 'id' => 'inputPassword', 'class' => 'form-control']);
                    echo '<span class="text-danger">'.$errors->first('inputPassword').'</span>';                    
                    echo '</div>';  
                    
                    echo "<div class='form-group'>";    
                    echo Form::label('inputConfirmation', 'Enter same password again :');
                    echo '<br/>';
                    echo Form::password('inputConfirmation', ['placeholder' => 'Repeat the password', 'id' => 'inputConfirmation', 'class' => 'form-control']);
                    echo '<span class="text-danger">'.$errors->first('inputConfirmation').'</span>';                    
                    echo '</div>';   
                    
                    echo csrf_field();
                    
                    echo '<center>';
                    echo Form::submit('Sign up', ['class' => 'btn btn-primary']);
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