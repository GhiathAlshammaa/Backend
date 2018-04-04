from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
from collections import defaultdict
from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)
# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")
@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    # say hello to user
    username = hello()

    if not session['user_id']:
        return apology("Session in invalid")

    else:

        # bring all the records which has same user_id, that means same user has owned them
        #sql_records = db.execute("SELECT id,stock_number,symbol FROM protfolio WHERE user_id=:u_id;",u_id=session['user_id'])

        # bring all the records which has same user_id, that means same user has owned them
        try:
            sql_records = db.execute("SELECT * FROM protfolio WHERE user_id=:u_id;",u_id=session['user_id'])
        except :
            return apology("This area is Invalid")


        # create a new dictionary , for save all the values in one place
        new_record = {}

        # bring the user_id of the session and save it with new varible
        u_id = session['user_id']
        StocksTotal = 0.0

        # check if the main query work or not. this query brings the records of shares based on user_id
        if not sql_records:
            # The user has no shares
            #bring the cash , that is why I made this query
            cash_query = db.execute("SELECT cash FROM users WHERE id = :u_id", u_id=session['user_id'])
            cash = str(cash_query[0]["cash"])
            cash = cash.replace("$", "")
            cash = cash.replace(",", "")
            cash = float(cash)

            # fake dictionary , I used to appear empty table to the user
            records = {}
            # If the user still new and he has no shares yet , he will see empty table
            return render_template("index.html", records=records, total=0, CashCurrent=usd(cash),Username=username)
        else:
            # If the user has some shares under his id , depend on loop we will transform them to dictionary
            #try:
                for sql in sql_records:
                    new_record["id"] = sql["id"]
                    new_record["shares"] = sql["stock_number"]
                    symbol = sql["symbol"]

                    symbol = lookup(symbol)  # name
                    StocksTotal = StocksTotal + (float(new_record["shares"]) * symbol["price"])

                    new_record["symbol"] = symbol["symbol"]
                    new_record["name"]   = symbol["name"]
                    new_record["cost"] = float(new_record["shares"]) * symbol["price"] # total
                    new_record["price"] = symbol["price"]
                # bring cash value from users table
                cash_query = db.execute("SELECT cash FROM users WHERE id = :u_id", u_id=session['user_id'])
                cash = cash_query[0]["cash"]
                cash = str(cash_query[0]["cash"])
                cash = cash.replace("$", "")
                cash = cash.replace(",", "")
                cash = float(cash)

                # sum the curremt cash with the total price of the shares
                StocksTotal = float(StocksTotal) + float(cash)
                check_in_result = db.execute("SELECT * FROM result WHERE symbol=:symbol;",symbol=new_record["symbol"])
                if not check_in_result:
                    # a function would save the new record in the result table
                    insert_record_to_result(new_record)
                else:
                    # Remove the old record and enter a new one
                    db.execute ("DELETE FROM result where symbol=:symbol",symbol=new_record["symbol"])
                    # a function would save the new record in the result table
                    insert_record_to_result(new_record)

                # fetch the data of the result table
                records = db.execute("SELECT * FROM result WHERE u_id = :u_id", u_id=u_id)
                return render_template("index.html", records=records, total=usd(StocksTotal), CashCurrent=usd(cash),Username=username)
            #except:
                #return apology("This area is Invalid")

@app.route("/buy", methods=["GET", "POST"])
@login_required

def buy():
    """Buy shares of stock"""

        # this code to say hello to user

# say hello to user
    username = hello()


    if request.method == "POST":
        # save the form input varibles into new varibles
        symbol = request.form.get("symbol")
        symbol = symbol.upper()
        number_shares = request.form.get("shares")
        # bring 3 cells of dictionary in a helpers.py based on symbol
        # symbol , name , current price
        record = lookup(symbol)

        # Validation operations on the input of the html page
        try:
            # we don't get any Symbol of the html page
            if not symbol:
                return apology("Sympol is empty")
            # check if this kind of Symbol is available or not
            if not record:
                return apology("This symbol isn't available")
            # check the Number of shares field , if it is empty
            if not number_shares:
                return apology("Number of shares is empty")
            # check the Number of shares field , it is a negative number
            if int(number_shares) <= 0:
                return apology("The Number of shares is not a positive integer")
        except:
            return apology("Valid purchase")

        # bring the value of the current cash from
        cash_value = db.execute("SELECT cash FROM users WHERE id=:id;", id=session["user_id"])
        #cash_value = select_rows_of_db("users","id",session["user_id"])
        if not cash_value:
                return apology("cash_value query is wrong ")

        #cash_value = float(cash_value[0]["cash"])
        cash_value = str(cash_value[0]["cash"])
        cash_value = cash_value.replace("$", "")
        cash_value = cash_value.replace(",", "")
        cash_value = float(cash_value)

        # how much is the cost currently of the shares depend on the current price
        cost = float(number_shares) * record['price']

        try:
            # check if the budget of the User enough to buy new shares
            if cost > cash_value:
                return apology("you have no money enough to buy it ")
        except:
            return apology('Invalid purchase')

        # check if this kind of shares is right now inside the Database
        sql = db.execute("SELECT * FROM protfolio where user_id=:u_id and symbol=:symbol",symbol=symbol,u_id=session["user_id"])
        # new dictionay , I need it to make a insertion to database
        NewRecord = record
        NewRecord["shares"] = number_shares

        NewRecord["cost"] = cost

        # if the kind of shares (Symbol) isn't there , we should to make a insertion operations on Database
        if len(sql)==0:
            #symbol_id = sql[0]["id"]
            #NewRecord["id"] = symbol_id
            # once the user have money enough, we allow to him buy the new shares
            if cost < cash_value:
                # an insertion operations to Database
                # Insert a new record to the portfolio table
                insert_record_to_protfolio(NewRecord)
                fetch_new_id = db.execute("SELECT id FROM protfolio WHERE user_id=:u_id and symbol=:symbol;",u_id=session["user_id"],symbol=symbol)
                NewRecord["id"] = fetch_new_id[0]["id"]

                # Insert a new record to the result table
                insert_record_to_result(NewRecord)

                # Insert a new record to the history table
                insert_record_to_history(NewRecord,"b")

                # update the value of cash, after we subtract the value of the new shares which have bought
                sum = cash_value - (float(number_shares) * record['price'])
                update_record(sum)

            # the bough operation is done, so go to index to appear the new table
            flash ("Bought")
        # if the kind of shares (Symbol) is already there , we should to make a updating operations on Database
        # and we don't need to touch history
        else:
            symbol_id = sql[0]["id"]
            NewRecord["id"] = symbol_id

            user_id = sql[0]["user_id"]
            old_number_shares = sql[0]["stock_number"]
            new_number_shares = number_shares
             # change the the record in the protfolio table
            db.execute("UPDATE protfolio SET stock_number=:ons + :nns WHERE user_id=:user_id;", ons=old_number_shares,nns=new_number_shares, user_id=user_id )

            # change the the record in the result table
            db.execute("UPDATE result SET shares=:ons + :nns WHERE id=:id_s;", nns=new_number_shares, ons=old_number_shares ,id_s=symbol_id)
            sum = cash_value-(float(number_shares) * record['price'])
            # change the value of cash
            update_record(sum)

            # Insert a new record to the history table
            insert_record_to_history(NewRecord,"b")



        return redirect("/")
    else:
        # if the code couldn't find the post came from the Form , that means appear the html page
        return render_template("buy.html",Username=username)

@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    # say hello to user
    username = hello()

    # bring entire of the records which the User did
    interaction = db.execute("SELECT * FROM history WHERE user_id=:id ORDER BY id DESC ", id=session['user_id'])

    # check if the main query doesn't work
    if not interaction:
            return apology("Interaction query is wrong", 403)
    # if everything work well , appear the history html page
    return render_template("history.html", interactions=interaction,Username=username)

@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # say hello to user
    # username = hello()


    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username",
                          username=request.form.get("username"))


        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
           return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")
        #return redirect(url_for("index"))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")

@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")

@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    # say hello to user
    username = hello()

    # check if the Form of html page send something
    if request.method == "POST":
        # put the Form input variables in new variables , that is easier to use
        symbol = request.form.get("symbol")
        record = lookup(symbol)

        # if the record is empty appear a error message
        if not symbol or not record:
            return apology("Invalid symbol",400)
        else:
            # if the record is not String appear also a error message
            #if type(record)!= str :
               # return apology("Invalid symbol",400)
            # if everything works well, appear the values of the quote

            #for r in record
            record["price"]=usd(record["price"])

            return render_template("quoted.html", Info=record)
    # if the code doesn't get any post of the Form , appear the html page
    else:
        return render_template("quote.html",Username=username)

@app.route("/cash", methods=["GET", "POST"])
def cash():

    """incress your cash"""

    # say hello to user
    username = hello()

    # manipulate the information the user has submitted
    if request.method == "POST":
        # save the form values into new varibles
        cash = request.form.get("cash")

        # validation operations
        if not cash:
            return apology("Cash field is empty!")

        old_cash = db.execute("select cash FROM users WHERE id=:u_id;", u_id=session['user_id'])
        old_cash = old_cash[0]["cash"]

        # sum the old and the new of cash
        cash = float(old_cash) + float(cash)


        # update the table
        result = db.execute("UPDATE users SET cash=:value WHERE id=:u_id;", value=cash ,u_id=session['user_id'])


        # after success the regesteration , the code will save the session by the id of user
        # as if he makes a successful login

        flash ("You have a new value of cash")
        # then he will go to the index to check the table
        return redirect("/")
    else:
        return render_template("cash.html",Username=username)



@app.route("/changepassword", methods=["GET", "POST"])
def changepassword():

    # say hello to user
    username = hello()

    """Change Password."""
    # manipulate the information the user has submitted

    if request.method == "POST":
        # save the form values into new varibles
        password = request.form.get("password2")
        confirmation =  request.form.get("confirmation2")

        # validation operations
        if not password:
            return apology("Password is empty!")

        # check password confirmation field
        if not confirmation:
            return apology("confirmation is empty!")

        # check if there are matching between a password and password confirmation
        if password != confirmation:
            return apology("passwords doesn't match confirmation field")

        # save the password after encrypt inside the hash varible
        hash_password = generate_password_hash(password)

        # validation operation, if the Username is repeated
        # if the username is repeated, the code will send error message and stop the query
        result = db.execute("UPDATE users SET hash=:value WHERE id=:u_id;", value=hash_password ,u_id=session['user_id'])


        # after success the regesteration , the code will save the session by the id of user
        # as if he makes a successful login

        flash ("Your password has changed")
        # then he will go to the index to check the table
        return redirect("/")
    else:
        return render_template("changepassword.html",Username=username)


@app.route("/register", methods=["GET", "POST"])
def register():

    # say hello to user
    #username = hello()

    """Register user."""
    # manipulate the information the user has submitted

    if request.method == "POST":
        # save the form values into new varibles
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation =  request.form.get("confirmation")
        cash = 10000

        # validation operations
        # check username field
        if not username:
            return apology("Username is empty!")

        # check password field
        if not password:
            return apology("Password is empty!")

        # check password confirmation field
        if not confirmation:
            return apology("confirmation is empty!")

        # check if there are matching between a password and password confirmation
        if password != confirmation:
            return apology("passwords doesn't match confirmation field")

        # save the password after encrypt inside the hash varible
        hash_password = generate_password_hash(password)

        # validation operation, if the Username is repeated
        # if the username is repeated, the code will send error message and stop the query
        result = db.execute("INSERT INTO users (username, hash,cash) \
        VALUES (:username,:hash_password,:cash)",\
        username=username,hash_password=hash_password,cash=cash)

        # if the Username repeated , appear error message
        if not result:
            return apology("Username repeated , try again and choose another username")

        # after success the regesteration , the code will save the session by the id of user
        # as if he makes a successful login
        try:
            user_id = db.execute("SELECT id FROM users WHERE username IS :username",\
            username=request.form.get("username"))
            session['user_id'] = user_id[0]['id']
        except:
            return apology("Error with Session regestration")

        # then he will go to the index to check the table
        return redirect("/")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():

    # say hello to user
    username = hello()

    # Sell shares of stock
    if request.method == "POST":
        # save the Form input values into a new varibles

        symbol = request.form.get("symbol")
        if symbol == None:
            return apology("symbol is Null ", 400)

        stocks_number_query = db.execute("SELECT stock_number FROM protfolio WHERE symbol=:symbol and user_id=:u_id;", symbol=symbol,u_id=session['user_id'])

        #symbol, fetch the id depend on symbol , because we need it later
        id_query = db.execute("SELECT id FROM protfolio WHERE symbol=:symbol and user_id=:u_id;", symbol=symbol,u_id=session['user_id'])

        # check if the query is work well
        if not stocks_number_query:
            return apology("Sql stocks_number's query is Wrong ", 403)
        else:
            # if everything work well , create new varibles to change the stocks number
            # depend on the new operation
            # stocks varibles
            old_stocks_number = stocks_number_query[0]["stock_number"]
            id_symbol = id_query[0]['id']

            try :
                # bring the number of shares of the html page
                sn = int(request.form.get("shares"))

            except ValueError:
                return apology("ValueError handling , could not convert string to float ")


            # check what the user input and ensure of the value
            try:
                if sn < 1:
                    return apology("negative number of shares")
                if sn > old_stocks_number:
                    return apology("invalid number of shares")
            except:
                return apology("happened problem , during the comparison between the old value of shares with the new value ")

            new_stocks_number = float(old_stocks_number) - float(sn)

            # depend on lookup , I will know the cureent price to my shares
            # Symbol varibles
            symbol = lookup(symbol)
            sell_price = float(symbol["price"]) * float(sn)

            #old_total_query = db.execute("SELECT total FROM result WHERE symbol=:symbol;", symbol=symbol["symbol"])
            #old_total = old_total_query[0]["total"]

            old_price_query = db.execute("SELECT price,shares FROM result WHERE symbol=:symbol;", symbol=symbol["symbol"])
            old_shares = old_price_query[0]["shares"]
            old_price  = str(old_price_query[0]["price"])
            old_price = old_price.replace("$", "")
            old_price = old_price.replace(",", "")

            old_total  = float(old_shares) * float(old_price)

            # change the Cash , because it is reduced after this operation
            change_cash_query = db.execute("select cash FROM users WHERE id=:u_id;", u_id=session['user_id'])
            old_cash = str(change_cash_query[0]["cash"])
            old_cash = old_cash.replace("$", "")
            old_cash = old_cash.replace(",", "")

            new_cash = float(old_cash) + float(sell_price)

            #total = float(old_total + sell_price)
            total = float(old_total) + float(sell_price)

            db.execute("UPDATE users SET cash=:value WHERE id=:user_id;", value=usd(new_cash) ,user_id=session['user_id'])
            db.execute("UPDATE protfolio SET stock_number=:value WHERE id=:id_s;", value=new_stocks_number ,id_s=id_symbol)
            db.execute("UPDATE result SET shares=:value , total=:total WHERE id=:id_s;", value=new_stocks_number,total=usd(total) ,id_s=id_symbol)


            # insert a new record to histroy table
            NewRecord={}
            NewRecord["symbol"]= symbol["symbol"]
            NewRecord["shares"]= int(sn)
            NewRecord["price"] = float(symbol["price"])
            NewRecord["cost"]  = float(sell_price)

            insert_record_to_history(NewRecord,"s")


            # cehck if the stocks of the symbol becames 0 , then remove symbol's record
            check_stocks_number_query = db.execute("SELECT stock_number FROM protfolio WHERE id=:id_symbol;", id_symbol=id_symbol)
            check_stocks_number = check_stocks_number_query[0]['stock_number']

            if (check_stocks_number == 0):
                db.execute("DELETE FROM protfolio WHERE id=:id_symbol", id_symbol=id_symbol)
                db.execute("DELETE FROM result WHERE id=:id_symbol", id_symbol=id_symbol)

            flash ("Sold")
            return redirect("/")

    else:
        # if the code doesn't get post of the Form , appear the html page
        # sql query to fetch the old symbol value
        symbols = db.execute("SELECT symbol FROM protfolio WHERE user_id=:u_id;", u_id=session['user_id'])
        return render_template("sell.html", symbols=symbols, Username=username)

# a function to insert record to the result table
def insert_record_result(id_s,number_shares,record,id_u,total):
    # (id_s,number_shares,record, session["user_id"])
    db.execute("INSERT INTO result (id,u_id,symbol,name,shares,price,total) \
                VALUES (:id_s, :id_u, :symbol, :name , :shares , :price , :total );",\
                id_s=id_s, id_u=id_u, symbol=record['symbol'], name=record['name'] , shares=number_shares,price=usd(record['price']),total=total)

# a function to insert record of any table
def insert_record(record, number_shares):
    db.execute("INSERT INTO protfolio (symbol, stock_number, price, user_id) \
                VALUES (:symbol, :stock_number, :price, :user_id);",\
                symbol=record['symbol'], stock_number=number_shares, price=usd(record['price']), user_id=session["user_id"])

# a function to update record in the users table
def update_record(Sum):
    db.execute("UPDATE users SET cash=:Sum1 WHERE id=:user_id;", Sum1=Sum, user_id=session["user_id"])

# a function to update a record of any table
def update_record_table(table, cell, id_c, value):
    db.execute("UPDATE :table SET :cell=:value WHERE id=:id_c;", value=value, table=table,cell=cell,id_c=id_c)

def select_rows_of_db(table_name,criteria,value):
    return db.execute("SELECT * FROM :table_name WHERE :criteria=:value;",table_name=table_name,criteria=criteria,value=value)

"""
def history_input(symbol,shares,price,user_id):
    db.execute("INSERT INTO history (Symbol, Shares, Price, user_id) \
        VALUES (:symbol, :shares, :price, :user_id);",\
        symbol=symbol, shares=shares, price=usd(price), user_id=user_id)
"""

def insert_record_to_protfolio(NewRecord):
    db.execute("INSERT INTO protfolio (symbol, stock_number, price, user_id) \
                VALUES (:symbol, :stock_number, :price, :user_id);",\
                symbol=NewRecord['symbol'], stock_number=NewRecord['shares'], price=usd(NewRecord['price']), user_id=session["user_id"])

    # (id,u_id,symbol,name,shares,price,total)
def insert_record_to_result(NewRecord):
    db.execute("INSERT INTO result (id,u_id,symbol,name,shares,price,total) \
                VALUES (:id_s, :user_id, :symbol, :name , :shares , :price , :total );",\
                id_s=NewRecord['id'], user_id=session["user_id"], symbol=NewRecord['symbol'], name=NewRecord['name'], \
                shares=NewRecord['shares'], price=usd(NewRecord['price']), total=usd(NewRecord['cost']))


def insert_record_to_history(NewRecord,kind_operation):
    if (kind_operation == "s"):
        db.execute("INSERT INTO history (symbol, shares, price,total,user_id) \
            VALUES (:symbol, :shares, :price, :total, :user_id);", \
            symbol=NewRecord['symbol'], shares = -1 * (NewRecord['shares']) , price=usd(NewRecord['price']), \
            total=usd(NewRecord['cost']), user_id=session["user_id"])
    else:
        db.execute("INSERT INTO history (symbol, shares, price,total,user_id) \
            VALUES (:symbol, :shares, :price, :total, :user_id);", \
            symbol=NewRecord['symbol'], shares= NewRecord['shares'], price=usd(NewRecord['price']), \
            total=usd(NewRecord['cost']), user_id=session["user_id"])
def hello():
    sql_username = db.execute("SELECT username FROM users WHERE id=:u_id;",u_id=session['user_id'])
    username =sql_username[0]["username"]
    return username

def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)

# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
