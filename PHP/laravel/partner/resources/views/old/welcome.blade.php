<!DOCTYPE html>
<html>
    <head>
        <title>Laravel</title>

        <link href="https://fonts.googleapis.com/css?family=Lato:100" rel="stylesheet" type="text/css">

        <style>
            html, body {
                height: 100%;
            }

            body {
                margin: 0;
                padding: 0;
                width: 100%;
                display: table;
                font-weight: 100;
                font-family: 'Lato';
            }

            .container {
                text-align: center;
                display: table-cell;
                vertical-align: middle;
            }

            .content {
                text-align: center;
                display: inline-block;
            }

            .title {
                font-size: 96px;
            }
        </style>
    </head>
    <body>
        <!--
        <div class="container">
            <div class="content">
                <div class="title">Laravel 5</div>
            </div>
        </div>
        -->
        <div class="container">
            <label> Enter a Category </label></br></br>
            <form action="/store" method="POST">
              <b>Title:</b><br>
              <input type="text" name="title" value=""><br>
              <b>Note:</b><br>
              <!--
              <input type="text" name="note" value="">
              -->
              
              <textarea rows="4" cols="30" name="note"></textarea><br><br>
              <input type="hidden" name="_token" value={{ csrf_token() }}>
              
              <input type="submit" value="Add">
            </form>
        </div>    
    </body>
</html>
