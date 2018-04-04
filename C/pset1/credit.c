/**************************************************
* credit.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Ghiath Alshammaa
* graded by: TUTOR INSERTS NAME HERE ONCE GRADED
* pset design by Harvard CS50
*
* Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
* It receives input on the change that is owed.
***************************************************/
#include <stdio.h>
#include <cs50.h>

// Functions declaration
int sum_first_part(int length, int digits[16]);
int sum_second_part(int length, int digits[16]);
void checker_kind_creditcard(int length,int first_digit,int second_digit,int elements_number, int alternative_digits[16]);


// The Begining of the program
int main(void)
{

// The Varibles section
// count the cycles of the loop,and the final result is the number of digits
int counter=0;
// it contains same the value of the input to save my original value after finish the operation
long alternativ_input ;
// it contents the orginal value of the Input
long input;
// The array , which will save the input value as Elements
int digits[16];
// The alternative array , which will save the input value as Elements
int alternative_digits[16];
// the length of the array
int elements_number=0;
// the length of the array - 1 , because the Array always start of the 0
int neu_elements_number;

// Input Section , the user muss to enter number less that 16 digits
do
{
    input = get_long_long(" Number: ");
}
while (input > 9999999999999999);



// The processing section
// first step , account the number of the digits
alternativ_input=input;

for (int i = 0 ;i <= 15; i++)
{
    // every time , this Equation execute , we decrease one of the digits
    alternativ_input = alternativ_input / 10;



    // if the alternative input becomes 0 , that means , the digits is finish
    if (alternativ_input==0)
    {

        elements_number++;
        break;
    }
    else
    {
        // every cycle of the loop add 1 to the elements_number until the digits is finsh, that will give us the length
        elements_number++;
    }
}

// because the Array considers the 0 one of the elements, I should to -1 of the limit variable
neu_elements_number = elements_number - 1 ;

// insert the value of digits to the Array Elements, In descending order
for (int i=neu_elements_number ;i>=0;i--)
{
    // if the loop make the correct cycle based on the digits number, it must stop. and continue the program without waste time
    if ( (counter==17 && elements_number==16) || (counter==16 && elements_number==15) || (counter==14 && elements_number==13) )
    {
        break;
    }
    else
    {// every time , this Equation execute , we will know one of the array elements
        digits[i] = input % 10;
        alternative_digits[i] = input % 10;
        input = input / 10;
        counter++;
    }
}




// Output
// check the kind of the Creditcard and print it
checker_kind_creditcard(elements_number,digits[0],digits[1],elements_number,alternative_digits);

}

// functions Section
// this function to sum the first part of the Creditcard
int sum_first_part(int length, int digits[16])
{
    // a varible to make limit to the array and I decress 1 because the Array begin always of 0
    int new_length =length-1;
    // a varible to save the total of the digits
    int sum =0 ;
    for (int i=0 ;i<=new_length;i+=2)
    {
                sum += digits[i];
    }

    return sum;
}// end function sum_first_part

// this function to sum the second part of the Creditcard & multiply every number of the digits in number 2
int sum_second_part(int length, int digits[16])
{
    // after multiply digit in number 2 , if the number contents of tow digits . we need this varible
    int exception=0;
    // a varible to make limit to the array and I decress 1 because the Array begin always of 0
    int new_length =length-1;
    // a varible to save the total of the digits after apply the equation
    int sum =0 ;
    for (int i=1 ;i<=new_length;i+=2)
    {
                digits[i] = digits[i]*2;

                // after multiply digit in number 2 , if the number contents of tow digits . we divide them to two digits
                if(digits[i]>10)
                {
                    exception = digits[i] / 10;
                    sum += exception;
                    exception = digits[i] % 10;
                    sum += exception;
                    continue;
                }
                else
                {
                sum += digits[i];
                }
    }

    return sum;
}// end function sum_second_part


// this function for check the kind of the credit card
void checker_kind_creditcard(int length,int first_digit,int second_digit,int elements_number, int alternative_digits[16])
{

// here make equation , to check if the Creditcard Invalid
// sum the first part of the Creditcard
int first = sum_first_part(elements_number,alternative_digits);
// sum the second part of the Creditcard after we multiply every one of them in number 2
int second = sum_second_part(elements_number,alternative_digits);
// calculate the final result of the operation to know if the Creditcard valid or invalid
int result = first + second ;
// if the second digts is not 0 , that means the Creditcard is INVALID
result = result % 10 ;

// first step we should to check the length of the input digits
    switch (length)
    {
    case 16:
        if (first_digit == 4)
        {
             printf("VISA\n");
        }
        // second step we should to check the value of the first digit
        else if (first_digit == 5)
        {// third step we should to check the value of the second digit
            if(second_digit == 1 || second_digit == 2 || second_digit == 3 || second_digit == 4 || second_digit == 5  )
            {
                printf("MASTERCARD\n");
            }
            else
            {
                //printf("unknown Credit Card\n");
            }
        }
    break;

    case 15:
        if (first_digit == 3)
        {
            if(second_digit == 4 || second_digit == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                //printf("unknown Credit Card\n");
            }
        }
    break;

    case 13:
        if (first_digit == 4)
            printf("VISA\n");
    break;

    // if all our steps is failing. that means , we have unknown Creditcard
    default:
        //  else the Creditcard is INVALID
        if (result!=0)
        {
          printf("INVALID\n");
        }
    break;
    }

}// end the function checker_kind_creditcard

