#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int give_value_of_n_in_first_status(char x,char y);
int give_value_of_n_in_second_status(char x,char z);
int give_value_of_n_in_third_status(char x,char z);
void apply_the_equation(double n,char x,char y,char z);

int main(void)
{

const string notes_hash[] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#"
                       };

const string notes_flug[] = {"A", "Bb", "B", "C", "Db", "D", "Eb", "E", "F",
                        "Gb", "G", "Ab"
                       };

// "A3", "A4", "A5", "A6", "A7"
const string notes_A[] = {220=>3, 440=>4, 880=>5, 1760=>6, 3520=>7};

//string note = "D4 D4 E4 D4 G4 F#4 D4 D4 E4 D4 A4 G#4";
string note = get_string("Enter the note: ");
//int length_note=strlen(note) ;
//string temporary_note = NULL;
int counter = 0;
char x ;
char y ;
char z ='\0';
double n = 0;
//int result=0;

x=note[counter];
y=note[counter+1];
z=note[counter+2];

/*
printf("X is %c\n",x);
printf("Y is %c\n",y);
printf("Z is %c\n",z);
*/
        if (z =='\0')
        {
           // A5
           n = give_value_of_n_in_first_status(x,y);
           //printf("N is %i\n",n);
           //printf("Result is %i\n",apply_the_equation(n,x,y,z));
           apply_the_equation(n,x,y,z);
        }
        else
        {
            // A#4 or Ab4
            if (y == '#')
            {
               n = give_value_of_n_in_second_status(x,z);
               //printf("N is %i\n",n);
               //printf("Result is %i\n",apply_the_equation(n,x,y,z));
               apply_the_equation(n,x,y,z);
            }
            else if (y == 'b')
            {
               n = give_value_of_n_in_third_status(x,z);
               //printf("N is %i\n",n);
               //printf("Result is %i\n",apply_the_equation(n,x,y,z));
               apply_the_equation(n,x,y,z);
            }
        }
}

int give_value_of_n_in_first_status(char x,char y)
{
    int n=0;

       if (y=='5')
        {
            switch (x)
            {
                case 'A':
                    n=12;
                break;

                case 'C':
                    n=3;
                break;

                case 'D':
                    n=5;
                break;

                case 'E':
                    n=7;
                break;

                case 'F':
                    n=8;
                break;

                case 'G':
                    n=10 ;
                break;
            }
        }
        else if (y=='4')
        {
            switch (x)
            {
                case 'A':
                    n=2;
                break;

                case 'B':
                    n=2;
                break;

                case 'G':
                    n=3;
                break;

                case 'F':
                    n=5;
                break;

                case 'E':
                    n=7;
                break;

                case 'D':
                    n=8;
                break;

                case 'C':
                    n=10 ;
                break;
            }

        }
        return n;
}

int give_value_of_n_in_second_status(char x,char z)
{
    int n=0;

       if (z=='5')
        {
            switch (x)
            {
                case 'C':
                    n=4;
                break;

                case 'D':
                    n=6;
                break;

                case 'F':
                    n=9;
                break;

                case 'G':
                    n=11 ;
                break;
            }
        }
        else if (z=='4')
        {
            switch (x)
            {
                case 'G':
                    n=3;
                break;

                case 'F':
                    n=5;
                break;

                case 'D':
                    n=8;
                break;

                case 'C':
                    n=10 ;
                break;
            }

        }
        return n;

}

int give_value_of_n_in_third_status(char x,char y)
{
    int n=0;

       if (y=='5')
        {
            switch (x)
            {
                case 'D':
                    n=4;
                break;

                case 'E':
                    n=6;
                break;

                case 'G':
                    n=9;
                break;

                case 'A':
                    n=11 ;
                break;
            }
        }
        else if (y=='4')
        {
            switch (x)
            {
                 case 'A':
                    n=4 ;
                break;

                case 'G':
                    n=5;
                break;

                case 'E':
                    n=8;
                break;

                case 'D':
                    n=10;
                break;

            }

        }
        return n;
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


