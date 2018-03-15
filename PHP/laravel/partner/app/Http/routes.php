<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the controller to call when that URI is requested.
|


Route::get('/', function () {
    return view('welcome');
});
*/
Route::get('/', function () {
    //return view('login');
    return view('login');
});


Route::get('/login', "UIController@login");
Route::post('/validateLogin', "UIController@validateLoginform");

Route::get('/register', "UIController@register");
Route::post('/validateRegister', "UIController@validateRegisterform");


//Route::get('accounts/create', [as => 'createAccount', 'uses' => 'AccountsController@create']);


//Route::get('/index', "UIController@index");

/*
Route::get('/login', function () {
    return view('welcome');
});
*/



Route::get('/category/remove', "category@index");
Route::get('/category', "category@index");
Route::post('/category', "category@validateform");

//Route::post('/category', "category@index");

//Route::get('/category/show', "category@show");

//Route::get('index', "category@index");
//Route::post('store', "category@store");



