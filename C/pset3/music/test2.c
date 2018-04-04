#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Functions declaration Section
bool compare(string x, char y);
bool compare_string(string x, string y);
int apply_the_equation(double n,char last_charachter,string note,float notes_A[8]);

string str_combine(char x, char y);
double get_n_of_two_charaters_input(char first_character, char * notes_hash[12], const int length_array  );
double get_n_of_three_charaters_with_hash_input(char first_character, char second_character, char * notes_hash[12], const int length_array);
double get_n_of_three_charaters_with_flug_input(char first_character, char second_character, char * notes_flug[12], const int length_array);

int main(void)
{
const int length_array = 12;
char * notes_hash[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F","F#", "G", "G#"};
char * notes_flug[12] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F","Gb", "G", "Ab"};

//                  A0 A1  A2  A3   A4  A5    A6    A7
float notes_A[8] = {27.5,55,110,220, 440, 880, 1760, 3520};

//string note = "D4 D4 E4 D4 G4 F#4 D4 D4 E4 D4 A4 G#4";
// a first character of the string sequence
char first_character;
// a second character of the string sequence
char second_character;
// a third character of the string sequence
char third_character;

// The Input value
string note;

// enter the input only if the first letter is in upper case and the string sequence isn't empty
do
{
note = get_string("Enter the note: ");
first_character = note[0];
second_character = note[1];
third_character = note[2];
}
while(!isupper(first_character) || note == NULL );

int note_length = strlen(note);

// n is a important value in The equation, we need it later
double n = 0.0;
int result =0;

    if (note_length==2)
    {
        n=get_n_of_two_charaters_input(first_character,notes_hash ,length_array );
        //printf("N is %f\n",n);
        //printf("***************************************\n");

        result = apply_the_equation(n,second_character,note,notes_A);
        printf("Result: %i\n",result);
    }
    else
    {
        // A#4 or Ab4
        if (second_character=='#')
        {
            n=get_n_of_three_charaters_with_hash_input(first_character,second_character,notes_hash ,length_array);
            //printf("N is %f\n",n);
            //printf("***************************************\n");

            result = apply_the_equation(n,third_character,note,notes_A);
            printf("Result: %i\n",result);
        }// end first if
        else if (second_character=='b')
        {
            n=get_n_of_three_charaters_with_flug_input(first_character,second_character,notes_flug ,length_array);
            //printf("N is %f\n",n);
            //printf("***************************************\n");

            result = apply_the_equation(n,third_character,note,notes_A);
            printf("Result: %i\n",result);
        }// end second if
    }// end first if
}// end main

// Functions Section
int apply_the_equation(double n,char last_charachter,string note,float notes_A[8])
{
    int note_length=strlen(note);
    //char first_charachter = note[0];
    int result = 0;
    char last_character_string [] ={last_charachter,'\0'};
    int last_charachter_integer = atoi(last_character_string);

    double power  = n/12 ;
    //printf("Power is %f\n",n);

    double p = pow(2.00, power);
    //printf("P is %f\n",n);

//                          A0  A1  A2  A3   A4  A5    A6    A7
//      int notes_A[8] = {27.50,55,110,220, 440, 880, 1760, 3520};

    switch(last_charachter_integer)
    {

        case 0:
            if(note_length==2)
            {
                 result = round(notes_A[0] * p );
            }
            else
            {
                result = round(notes_A[0] * p );
            }
        break;


        // * A0
        case 1:
            if(note_length==2)
            {
                if (compare_string(note,"B1"))
                {
                    result = round(notes_A[1] * p );
                }
                else if (compare_string(note,"A1"))
                {
                    result = round(notes_A[1] * p );
                }
                else
                {
                     result = round(notes_A[0] * p );
                }
            }
            else
            {
                if (compare_string(note,"A#1"))
                {
                     result = round(notes_A[1] * p );
                }
                else if (compare_string(note,"Bb1"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B2"))
                {
                    result = round(notes_A[2] * p );
                }
                else if (compare_string(note,"A2"))
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
                if (compare_string(note,"A#2"))
                {
                     result = round(notes_A[2] * p );
                }
                else if (compare_string(note,"Bb2"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B3"))
                {
                    result = round(notes_A[3] * p );
                }
                else if (compare_string(note,"A3"))
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
                if (compare_string(note,"A#3"))
                {
                     result = round(notes_A[3] * p );
                }
                else if (compare_string(note,"Bb3"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B4"))
                {
                    result = round(notes_A[4] * p );
                }
                else if (compare_string(note,"A4"))
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
                if (compare_string(note,"A#4"))
                {
                     result = round(notes_A[4] * p );
                }
                else if (compare_string(note,"Bb4"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B5"))
                {
                    result = round(notes_A[5] * p );
                }
                else if (compare_string(note,"A5"))
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
                if (compare_string(note,"A#5"))
                {
                     result = round(notes_A[5] * p );
                }
                else if (compare_string(note,"Bb5"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B6"))
                {
                    result = round(notes_A[6] * p );
                }
                else if (compare_string(note,"A6"))
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
                if (compare_string(note,"A#6"))
                {
                     result = round(notes_A[6] * p );
                }
                else if (compare_string(note,"Bb6"))
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
            if(note_length==2)
            {
                if (compare_string(note,"B7"))
                {
                    result = round(notes_A[7] * p );
                }
                else if (compare_string(note,"A7"))
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
                if (compare_string(note,"A#7"))
                {
                     result = round(notes_A[7] * p );
                }
                else if (compare_string(note,"Bb7"))
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

double get_n_of_two_charaters_input(char first_character , char * notes_hash[12], const int length_array)
{
    int counter = 0;
    double n=0.0;
        while (counter<length_array)
        {
            bool first_compare_operation = compare(notes_hash[counter], first_character);
            //printf("compare is %i\n",first_compare_operation);
            //printf("***************************************\n");

                if(first_compare_operation)
                {
                    n=counter;
                    //printf("N is %f\n",n);
                    return n;
                }
                else
                {
                   counter++;
                }
        }
    return 0;

}

double get_n_of_three_charaters_with_hash_input(char first_character , char second_character, char * notes_hash[12], const int length_array)
{
    int counter = 0;
    double n=0.0;
    //char * notes_hash[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F","F#", "G", "G#"};

    while (counter<length_array)
    {
        char first_attempt [] ={first_character,second_character,'\0'};
        //printf("first_attempt is %s\n",first_attempt);
        //printf("notes_hash[%i] is %s\n",counter,notes_hash[counter]);
        bool first_compare_operation = compare_string(notes_hash[counter],first_attempt);

        // second case when the ltter will be identical with the second Prospect Xb
        if(first_compare_operation)
        {
            n=counter;
            //printf("N is %f\n",n);
            //printf("***************************************\n");
            return n;
        }
        else
        {
            n=counter;
            //printf("N is %f\n",n);
            //printf("***************************************\n");
            counter++;
        }// end if
    }// end loop


    return 0;

}

double get_n_of_three_charaters_with_flug_input(char first_character , char second_character , char * notes_flug[12], const int length_array)
{
    int counter = 0;
    double n=0.0;
    //char * notes_flug[12] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F","Gb", "G", "Ab"};
    while (counter<length_array)
    {
        char first_attempt [] ={first_character,second_character,'\0'};
        //printf("first_attempt is %s\n",first_attempt);
        //printf("notes_flug[%i] is %s\n",counter,notes_flug[counter]);

        bool first_compare_operation = compare_string(notes_flug[counter],first_attempt);

        // second case when the ltter will be identical with the second Prospect Xb
        if(first_compare_operation)
        {
            n=counter;
            //printf("N is %f\n",n);
            //printf("***************************************\n");
            return n;
        }
        else
        {
            n=counter;
            //printf("N is %f\n",n);
            //printf("***************************************\n");
            counter++;
        }// end if
    }// end loop

    return 0;

}

// Extra functions

bool compare(string x, char y)
{
    int length = strlen(x);
    //int counter = 0;

    if (length != 1)
    {
        return false;
    }
    else if (x[0]!=y)
    {
      return false;
    }
    else
    {
      return true ;
    }

}

bool compare_string (string x,string y)
{
    if ((x[0]==y[0]) && (x[1]==y[1]))
    {
      return true ;
    }
    else
    {
     return false ;
    }
}

/* Garbige

*/


