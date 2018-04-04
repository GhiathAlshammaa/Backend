#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Functions Declaration section */
// function converts the key to the values
string convert_key_to_value(string key_str, int limit_key_array);
// function cipher the characters one by one
char cipher_plaintext(char plaintext, char key_str);
// a function for print the last result
void print_final_result(char *ciphertext);

int main(int argc, string argv[])
{
    // a varible to save the key values
    string key_str = argv[1];

    // Check the number of the arguments & if the second arguments is number
    /* Section 1 of my problem - I should to take the Key as String sequences and converte it to values */
    // check if the count of the arguments is not more than 2
    if (argc != 2)
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    // check if the value of the second argument is a number
    int counter_argument = 0;
    while (counter_argument < strlen(key_str))
    {
        if (isdigit(key_str[counter_argument]))
        {
            printf("Usage: ./vigenere k\n");
            return 1;
        }
        else
        {
            counter_argument++;
        }
    }
// a varible contents the length of the key array
    int limit_key_array = strlen(key_str) ;
// excute the Environmental responsibility function about convert from string to specific values
    key_str = convert_key_to_value(key_str, limit_key_array);
// I should to decress 1 because the Arrays always begin from 0
    limit_key_array -= 1;

    /* Section 2 of my problem - I should to take the input of user and cipher it */
// Input, take the Input from the user
    string plaintext = get_string("plaintext: ");
//char cipher='\0';
    char *cipher = plaintext;
// a varible contents the length of the key array & I should to decress 1 because the Array always begin from 0
    int limit_plaintext_array = strlen(plaintext) - 1;
// a varible as counter I need it , because of I want to let my keys array repeat itself
    int counter = 0;
// a loop, it will check the letters one by one and apply the equation to cipher the letters based on the key array
    for (int i = 0; i <= limit_plaintext_array; i++)
    {
        // if The String sequence not equal space
        if (isalpha(plaintext[i]))
        {
            if (i > limit_key_array)
            {
                // check if the counter over the limit of keys array repeat the values
                if (counter > limit_key_array)
                {
                    // repeat the key array from the begin because the limit is over
                    counter = 0;
                    // check & cipher the charachter
                    cipher[i] = cipher_plaintext(plaintext[i], key_str[counter]);
                    counter++;
                }
                else
                {
                    // check & cipher the charachter
                    cipher[i] = cipher_plaintext(plaintext[i], key_str[counter]);
                    counter++;
                }// End if 2
            }
            else
            {
                // check & cipher the charachter
                // and I should here send the key array based on i counter because the condition is not yet executed
                if (i == counter)
                {
                    cipher[i] = cipher_plaintext(plaintext[i], key_str[i]);
                    counter++;
                }
                else
                {
                    cipher[i] = cipher_plaintext(plaintext[i], key_str[counter]);
                    counter++;

                }
            }
        }
        else
        {
            cipher[i] = plaintext[i];
        }// End if 1

    }// end for

// Output
    print_final_result(cipher);

}// End main

// The Functions Section
// Function converts the key to the values
string convert_key_to_value(string key_str, int limit_key_array)
{
    int key ;
    for (int i = 0; i < limit_key_array; i++)
    {
        // limit_key_array = n;
        if (isalpha(key_str[i]))
        {
            if (isupper(key_str[i]))
            {
                key =  (key_str[i] - 'A');
                key_str[i] = key;
            }
            else if (islower(key_str[i]))
            {
                key =  (key_str[i] - 'a');
                key_str[i] = key;
            }
        }
        else
        {
            printf("Usage: ./vigenere k\n");
        }
    }
    return key_str;
}

// check & cipher the characters
char cipher_plaintext(char plaintext, char key_str)
{
    char character = plaintext;
    char cipher = '\0';
    // The character will change according to the condition of the character
    // check if the character is letter
    // check if the letter is in upper case
    if (isupper(character))
    {
        cipher = 65 + (character - 65 + key_str) % 26;
        return cipher;
    }
    // check if the letter is in lower case
    else if (islower(character))
    {
        cipher = 97 + (character - 97 + key_str) % 26;
        return cipher;
    }

    return cipher;
}
// End cipher_plaintext Function

// printing output
void print_final_result(char *ciphertext)
{
    printf("ciphertext: %s\n", ciphertext);
}





