/**************************************************
* mario.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Ghiath Alshammaa
* graded by: TUTOR INSERTS NAME HERE ONCE GRADED
* pset design by Harvard CS50
*
* This program prints a pyramid consisting of hashtags.
* It ask for input for thei height and prints a dynamic output.
***************************************************/
#include <cs50.h>
#include <stdio.h>

int main(void)
{

// a variable should to content the height (new line) of the half-pyramid
int height;

    // The input Checker
    do
    {

        printf("please enter value between 0 and 23: \n");
        height = get_int();

    }
    while(height<0 || height>23);

// a variable for the Space
int space=height-1 ;

// a variable for the #
int hash=height-space;

// a counter , I used with the (do .... while loop) because I don't want to change the original values
int count =0;

    // The loop determines how many line should  we use
    for (int i=0;i<height;i++)
    {
            // at the last line when the Spaces becames  0 , that means the complete line contents only hasches
            if(space==0)
            {
                    /* print the hasches for the left pyramid */
                    count=hash;
                    do
                    {
                    printf("#");
                    count--;
                    }
                    while(count>0);

                    /* print a gap */
                    count=2;
                    do
                    {
                        printf(" ");
                        count--;
                    }
                    while(count>0);

                    /* print the hasches for the right pyramid */
                    count=hash;
                    do
                    {
                    printf("#");
                    count--;
                    }
                    while(count>0);


                    /* print new line after finishing */
                     printf("\n");
                    break;

            }  // Else, the line is normal, it contents ( Spaces and # ) together
            else
            {

                /* print Spaces for the lift pyramid */
                count=space;
                do
                {
                    printf(" ");
                    count--;
                }
                while(count>0);


                /* print hasches for the lift pyramid */
                count=hash;
                do
                {
                    printf("#");
                    count--;
                }
                while(count>0);

                /* print a gap of two Spaces */
                count=2;
                do
                {
                    printf(" ");
                    count--;
                }
                while(count>0);

                /* print hasches for the right pyramid */
                count=hash;
                do
                {
                    printf("#");
                    count--;
                }
                while(count>0);


            }

        /* print a newline after finishing */
        printf("\n");

        // we should make these operations for the next round of the (for loop)
        // the new count of the Sapces
        space--;

        // the new count of the #
        hash=height-space;

    }// end for loop



}