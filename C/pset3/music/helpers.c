// Helper functions for music

#include <cs50.h>
#include "helpers.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// My functions declaration for a frequency function
// compare between string and a charechter
bool compare(string x, char y);
// compare between two string sequances
bool compare_string(string x, string y);
// apply our equation to give the laste result
int apply_the_equation(double n, char last_charachter, string note, float notes_A[8]);
// combine  between two string sequances
string str_combine(char x, char y);
// as the name of these functions , you can understand the target of it
double get_n_of_two_charaters_input(char first_character, char *notes_hash[12], int length_array);
double get_n_of_three_charaters_with_hash_input(string note, char *notes_hash[12], int length_array);
double get_n_of_three_charaters_with_flug_input(string note, char *notes_flug[12], int length_array);


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //  by these two varible , I convert the numerator from string to integer
    char numerator_string[] = {fraction[0], '\0'};
    int numerator    = atoi(numerator_string);

    //  by these two varible , I convert the denominator_string from string to integer
    char denominator_string[] = {fraction[2], '\0'};
    int denominator    = atoi(denominator_string);

    //  make the compare and return the last value after apply a mathematic operation
    switch (denominator)
    {
        // 1/2
        case 2:
            return 4 * numerator;
            break;
        // 1/4
        case 4:
            return 2 * numerator;
            break;

        // 1/8 , 3/8
        default :
            return numerator;
            break;
    }
    return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // ensure string was read
    if (strlen(s) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //  as the name , that constant to the length of all array
    const int length_array = 12;
    //  this array only to the letter with # , for I compar it later with the input
    char *notes_hash[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};
    //  this array only to the letter with b , for I compare it later with the input
    char *notes_flug[12] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab"};

// The note came from paramter

//  this array only to the A values , from A0 to A7. because I need it in my equation later
//                  A0 A1  A2  A3   A4  A5    A6    A7
    float notes_A[8] = {27.5, 55, 110, 220, 440, 880, 1760, 3520};

// here I divided my input string to three variables
// a first character of the input
    char first_character;
// a second character of the input
    char second_character;
// a third character of the input
    char third_character;

// here I refell my avarible beased on the input
    first_character = note[0];
    second_character = note[1];
    third_character = note[2];

// a varible contents the length of the input string sequences
    int note_length = strlen(note);

// n is a important value in The equation, we need it later in the mathmatic operation
    double n = 0.0;
// a variable contents The last result of frequance function
    int result = 0;
// if statment to check, if the value of input ist two characters or three charachters
    if (note_length == 2)
    {
        n = get_n_of_two_charaters_input(first_character, notes_hash, length_array );
        result = apply_the_equation(n, second_character, note, notes_A);

    }
// else , three characters call another fanctions to bring the N value and The last Result
    else
    {
        // A#4 or Ab4
        if (second_character == '#')
        {
            n = get_n_of_three_charaters_with_hash_input(note, notes_hash, length_array);
            result = apply_the_equation(n, third_character, note, notes_A);
        }// end first if
        else if (second_character == 'b')
        {
            n = get_n_of_three_charaters_with_flug_input(note, notes_flug, length_array);
            result = apply_the_equation(n, third_character, note, notes_A);
        }// end second if
    }// end first if
    return result;
}

int apply_the_equation(double n, char last_charachter, string note, float notes_A[8])
{
// I use this varible tto contents the length of array and for I didn't send it by parameter many time
    int note_length = strlen(note);
    int result = 0;
// by these variables , change the value of last charachter in input to integer for use with the switch statment
    char last_character_string [] = {last_charachter, '\0'};
    int last_charachter_integer = atoi(last_character_string);

// These variables , I will use in the equation, my target of them to make my mathematic operation more clear and simple
    double power = n / 12 ;
    double p = pow(2.00, power);

//                      A0  A1  A2  A3   A4  A5    A6    A7
//  int notes_A[8] = {27.50,55,110,220, 440, 880, 1760, 3520};

// depend on the last charachter of the input , I will use the suitable value of A and multiplay with it
    switch (last_charachter_integer)
    {
        case 0:
            if (note_length == 2)
            {
                result = round(notes_A[0] * p );
            }
            else
            {
                result = round(notes_A[0] * p );
            }
            break;

        // * A0
        // always if the input is only two characters , I will multiplay with the previous A
        // except in the B situation , because the gruppe of B buttons came always after the A button.
        // that why I will multiplay at the same A
        case 1:
            // that if statment because , I need to know exactly how many character the input , for checking depend on that
            if (note_length == 2)
            {
                if (compare_string(note, "B1"))
                {
                    result = round(notes_A[1] * p );
                }
                else if (compare_string(note, "A1"))
                {
                    result = round(notes_A[1] * p );
                }
                else
                {
                    result = round(notes_A[0] * p );
                }
            }
            // this else will excute when the value of input is three charachters
            else
            {
                if (compare_string(note, "A#1"))
                {
                    result = round(notes_A[1] * p );
                }
                else if (compare_string(note, "Bb1"))
                {
                    result = round(notes_A[1] * p );
                }
                else
                {
                    result = round(notes_A[0] * p );
                }
            }
            break;

        // * A1
        case 2:
            if (note_length == 2)
            {
                if (compare_string(note, "B2"))
                {
                    result = round(notes_A[2] * p );
                }
                else if (compare_string(note, "A2"))
                {
                    result = round(notes_A[2] * p );
                }
                else
                {
                    result = round(notes_A[1] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#2"))
                {
                    result = round(notes_A[2] * p );
                }
                else if (compare_string(note, "Bb2"))
                {
                    result = round(notes_A[2] * p );
                }
                else
                {
                    result = round(notes_A[1] * p );
                }
            }
            break;

        // * A2
        case 3:
            if (note_length == 2)
            {
                if (compare_string(note, "B3"))
                {
                    result = round(notes_A[3] * p );
                }
                else if (compare_string(note, "A3"))
                {
                    result = round(notes_A[3] * p );
                }
                else
                {
                    result = round(notes_A[2] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#3"))
                {
                    result = round(notes_A[3] * p );
                }
                else if (compare_string(note, "Bb3"))
                {
                    result = round(notes_A[3] * p );
                }
                else
                {
                    result = round(notes_A[2] * p );
                }
            }
            break;

        // * A3
        case 4:
            if (note_length == 2)
            {
                if (compare_string(note, "B4"))
                {
                    result = round(notes_A[4] * p );
                }
                else if (compare_string(note, "A4"))
                {
                    result = round(notes_A[4] * p );
                }
                else
                {
                    result = round(notes_A[3] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#4"))
                {
                    result = round(notes_A[4] * p );
                }
                else if (compare_string(note, "Bb4"))
                {
                    result = round(notes_A[4] * p );
                }
                else
                {
                    result = round(notes_A[3] * p );
                }
            }
            break;

        // * A4
        case 5:
            if (note_length == 2)
            {
                if (compare_string(note, "B5"))
                {
                    result = round(notes_A[5] * p );
                }
                else if (compare_string(note, "A5"))
                {
                    result = round(notes_A[5] * p );
                }
                else
                {
                    result = round(notes_A[4] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#5"))
                {
                    result = round(notes_A[5] * p );
                }
                else if (compare_string(note, "Bb5"))
                {
                    result = round(notes_A[5] * p );
                }
                else
                {
                    result = round(notes_A[4] * p );
                }
            }
            break;

        // * A5
        case 6:
            if (note_length == 2)
            {
                if (compare_string(note, "B6"))
                {
                    result = round(notes_A[6] * p );
                }
                else if (compare_string(note, "A6"))
                {
                    result = round(notes_A[6] * p );
                }
                else
                {
                    result = round(notes_A[5] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#6"))
                {
                    result = round(notes_A[6] * p );
                }
                else if (compare_string(note, "Bb6"))
                {
                    result = round(notes_A[6] * p );
                }
                else
                {
                    result = round(notes_A[5] * p );
                }
            }
            break;

        // * A6
        case 7:
            if (note_length == 2)
            {
                if (compare_string(note, "B7"))
                {
                    result = round(notes_A[7] * p );
                }
                else if (compare_string(note, "A7"))
                {
                    result = round(notes_A[7] * p );
                }
                else
                {
                    result = round(notes_A[6] * p );
                }
            }
            else
            {
                if (compare_string(note, "A#7"))
                {
                    result = round(notes_A[7] * p );
                }
                else if (compare_string(note, "Bb7"))
                {
                    result = round(notes_A[7] * p );
                }
                else
                {
                    result = round(notes_A[6] * p );
                }
            }
            break;
    }
    return result;
}
// as the name of these functions , you can understand the target of it
double get_n_of_two_charaters_input(char first_character, char *notes_hash[12], int length_array)
{
    // a variable I will use as counter in the loop statment
    int counter = 0;
    // a variable I will use as N value and I will return after the comperation operation finish
    double n = 0.0;
    // excute the loop while the condition is counter less than the length elements array
    while (counter < length_array)
    {
        bool first_compare_operation = compare(notes_hash[counter], first_character);
        if (first_compare_operation)
        {
            n = counter;
            return n;
        }
        else
        {
            counter++;
        }
    }
    return 0;

}
// as the name of these functions , you can understand the target of it
double get_n_of_three_charaters_with_hash_input(string note, char *notes_hash[12], int length_array)
{
    // as the name of these varibles , I will use them in the comparation operation
    char first_character = note[0];
    char second_character = note[1];
    // a variable I will use as counter in the loop statment
    int counter = 0;
    // a variable I will use as N value and I will return after the comperation operation finish
    double n = 0.0;
    // excute the loop while the condition is counter less than the length elements array
    while (counter < length_array)
    {
        // combine my charachter again as String sequence then make comperation operation as two string with the # array
        char first_attempt [] = {first_character, second_character, '\0'};
        bool first_compare_operation = compare_string(notes_hash[counter], first_attempt);

        // the case when the letter will be identical with such as the Prospect X#
        if (first_compare_operation)
        {
            n = counter;
            return n;
        }
        // else continue the loop statment
        else
        {
            n = counter;
            counter++;
        }// end if
    }// end loop


    return 0;

}
// as the name of these functions , you can understand the target of it
double get_n_of_three_charaters_with_flug_input(string note, char *notes_flug[12], int length_array)
{
    char first_character = note[0];
    char second_character = note[1];
    int counter = 0;
    double n = 0.0;
    while (counter < length_array)
    {
        // combine my charachter again as String sequence then make comperation operation as two string with the flug (b) array
        char first_attempt [] = {first_character, second_character, '\0'};
        bool first_compare_operation = compare_string(notes_flug[counter], first_attempt);
        // the case when the letter will be identical with such as the Prospect Xb
        if (first_compare_operation)
        {
            n = counter;
            return n;
        }
        else
        {
            n = counter;
            counter++;
        }// end if
    }// end loop

    return 0;

}
// Extra functions
// compare between a string and a charechter
bool compare(string x, char y)
{
    int length = strlen(x);
    //int counter = 0;

    if (length != 1)
    {
        return false;
    }
    else if (x[0] != y)
    {
        return false;
    }
    else
    {
        return true ;
    }

}
// compare between two string sequances
bool compare_string (string x, string y)
{
    if ((x[0] == y[0]) && (x[1] == y[1]))
    {
        return true ;
    }
    else
    {
        return false ;
    }
}


