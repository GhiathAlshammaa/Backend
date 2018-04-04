#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Functions declaration section
string cipher_operation(int key, string plaintext);
void print_final_result(string ciphertext);

// the beginning of my program
int main(int argc, string argv[])
{
// Input section, check the key which enter by user in Arguments sentence
// Check the number of the arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        return 1;
    }
// by this varible , I will convert the second part of the Arguments from string to int value
    int key = atoi(argv[1]);


// Input section , where I will take string sequence by user, save it in a string varible
// a varible contents the text which the user will enter
    string plaintext = get_string("plaintext: ");

// Algorithem section
// apply the Algorithem on the input text then after cipher operation return it back
    string ciphertext = cipher_operation(key, plaintext);

// Onput section , print cipher text operation.
    print_final_result(ciphertext);

}// end main

// Functions section
// a Function for cipher the input text and return it back as cipher text
string cipher_operation(int key, string plaintext)
{
// a varibles will content the elments of the input array after cipher operation
    string ciphertext = plaintext;
    // I will cipher the letters based on Caesar’s algorithm , one by one
    for (int i = 0, length = strlen(plaintext); i <= length; i++)
    {
        // a varible , I will use to check the elements of array , one by one
        char character = plaintext[i];

        // The character will change according to the condition of the character
        // check if the character is letter
        if (isalpha(character))
        {
            // check if the letter is in upper case
            if (isupper(character))
            {
                ciphertext[i] = 65 + (character - 65 + key) % 26;
            }
            // check if the letter is in lower case
            else if (islower(character))
            {
                ciphertext[i] = 97 + (character - 97 + key) % 26;
            }
        }
        // else the character is not letter , print it simply
        else
        {
            ciphertext[i] = character;
        }

    } // end for
    return ciphertext;
}

// a Function for printing the final output
void print_final_result(string ciphertext)
{
    printf("ciphertext: %s\n", ciphertext);
}





