// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"

int value_of_letter(char c);
typedef struct node
{
    bool is_word;
    struct node *next[27];
}
node;

// root node
node *root = NULL;

// a varible to tell us the word counts after finish
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // we need this node like cursor, to know where do we are
    node *current = root;
    // the index of the letters array
    int letter_number = 0;
    // the index of the node array
    int node_number;

    // while loop to check the word letter by letter until we arrive to the end of the word
    while (word[letter_number] != '\0')
    {
        // if the charachter is alphabet determine the node &  change the node_number
        node_number = value_of_letter(word[letter_number]);

        // corresponding element with the next node
        if (current->next[node_number] == NULL)
        {
            // word is misspelled
            return false;
        }
        else
        {
            // move to next letter
            current = current->next[node_number];
        }
        // after finish, incress the letter number
        letter_number++;
    }

    // once at end of input word, check is_word
    if (current->is_word == true)
    {
        return true;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false

bool load(const char *dictionary)
{

    // open the dictionary file and check if the open operation is wrong , print error message
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open the file %s.\n", dictionary);
        return false;
    }
    // we need buffer varible to help us in reading the file and the limit of the array should to be the supposed maximum letters possible in one word
    char buffer[46];

    // master is the first node of the series (link list)
    node *master = calloc(1,sizeof(node));
    master->is_word = false;
    // link the master with the root
    root = master;

    // current node , we need it as cursor
    node *current = NULL ;
    // while loop to read our file word by word until reach to the end of the file
    while (fscanf(file, "%s", buffer) != EOF)
    {
        // link the root with the current node
        current = root ;

        // incress the global varible 1 , for later we know how words count by size function
        word_count++;

        // check the word , letter by letter
        for (int i = 0,limit = strlen(buffer); i <limit ; i++)
        {
            // we have a varible to give us the number of the letter
            int index = value_of_letter(buffer[i]);

            // that means , we don't make this node before
            if (current->next[index] == NULL)
            {
                // create new node and load inside it the new word, letter by letter
                node *alpha = calloc(1,sizeof(node));
                // and dont forget initialized this new node
                alpha->is_word = false;
                alpha->next[index] = NULL;
                // and let the current node points to the new node
                current->next[index] = alpha ;
                current = alpha;
            }
            else
            {
                // else, go on to the next one
                current = current->next[index];
            }
        }
        // and after you load the new word , give true to the is_word varible. to sure the operation is successful
        current->is_word = true;
    }
    // after we finish load all the words , close the file and let the function return true
    fclose(file);
    return true;
}

// Returns the number of words in dictionary file, if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // word_count is a global variable , I add a line in load function to increase it after every word load
    return word_count;
}

bool free_node(node *temp)
{
    // Check if a valid node has been passed
    if (temp == NULL)
    {
        return true;
    }
    // We have a node, so now check each of the 27 next nodes if it leads to further nodes
    for (int i = 0; i < 27; i++)
    {
        if (temp->next[i] != NULL)
        {
            // here I use the recursive teknic, that helps us to decrease our code
            free_node(temp->next[i]);
        }
    }
    // if all nodes point to NULL, this node is empty so we can free it without losing any addresses of further nodes.
    free(temp);
    return true ;
}


bool unload(void)
{
    return free_node(root);
}


// this function return the index of every letter
int value_of_letter(char c)
{
    // if letter is uppercase
    if (isupper(c))
    {
        return c - 65;
    }
    // if letter is lowercase
    else if (islower(c))
    {
        return c - 97;
    }
    // if the character is a apostrophe, because our array begin from 0 and the letter is 26 , so I give the apostrophe number 26
    else
    {
        return 26;
    }

}


