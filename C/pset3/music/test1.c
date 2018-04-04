#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
int give_value_of_n_in_first_status(char x,char y);
int give_value_of_n_in_second_status(char x,char z);
int give_value_of_n_in_third_status(char x,char z);
*/
void apply_the_equation(double n,char x,char y,char z);
char* concat(char *s1, char *s2);

int main(void)
{
const int length_array = 12;
char * notes_hash[12] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F","F#", "G", "G#" };
//const string notes_flug[] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F","Gb", "G", "Ab"};

// "A0","A1","A2","A3", "A4", "A5", "A6", "A7"
//const int notes_A[] = {0,55,110,220, 440, 880, 1760, 3520};

//string note = "D4 D4 E4 D4 G4 F#4 D4 D4 E4 D4 A4 G#4";
string note = get_string("Enter the note: ");
//int length_note=strlen(note) ;
//string temporary_note = NULL;
int counter = 0;
char z ='\0';
//string xy=note;

double n = 0;
int i=0;
//int result=0;

char x[1] = {note[0]};
char y   =  note[counter+1];
z =  note[counter+2];


//printf("X is %s\n",x);
//printf("Y is %s\n",y);
//printf("XY is %s\n",note);
//printf("Z is %c\n",z);

        if (z =='\0')
        {
            //printf("XY is %s\n",note);
            while (i<length_array)
            {
                printf("notes_hash[%i] is %s\n",i,notes_hash[i]);
                printf("x is %s\n",x);
                printf("***************************************\n");

                int ret = strcmp(notes_hash[i], x);
                printf("compare is %i\n",ret);

                if(ret==0)
                {
                    n=i;
                    break;
                }
                else
                {
                   //printf("%i\n",i);
                   i++;
                }
            }
            //printf("N is %f\n",n);
        }
        else
        {
            // A#4 or Ab4
            if (y=='#')
            {

            }
            else if (y=='b')
            {

            }
        }
}


void apply_the_equation(double n,char x,char y,char z)
{
    int result = 0;
    //double p =0;
    double power  = n/12 ;

    if (y == '#' || y == 'b')
    {
        if( ((x=='B')&&(z=='4')) || (z=='5') )
        {
            //p = pow(2.00, power);
            result = round(440 * pow(2.00, power) );
        }
        else if (z=='4')
        {
            //p = pow(2.00, power);
            result = round(440 * pow(2.00, power) );
        }
    }
    else if (z == '\0')
    {
        if( ((x=='B')&&(y=='4')) || (y=='5') )
        {
            //p = pow(2.00, power);
            result = round(440 * pow(2.00, power) );
        }
        else if (y=='4')
        {
            //p = pow(2.00, power);
            result = round(440 * pow(2.00, power) );
        }
    }
    //return result;
    //printf("N : %f\n",n);
    //printf("power : %f\n",power);
    //printf("p : %f\n",p);
    printf("Result: %i\n",result);
}



