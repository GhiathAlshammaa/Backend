/**************************************************
* recover.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Ghiath Alshammaa
* graded by: TUTOR INSERTS NAME HERE ONCE GRADED
* pset design by Harvard CS50
*
* Recover the content of specific file
***************************************************/
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define Block 512

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // open input file & check
    char *filename = argv[1];
    FILE *inptr = fopen(filename, "r");

    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open the file %s.\n", filename);
        return 2;
    }

    // create new file to save a jpg picture one by one
    FILE *img = NULL;
    char new_file_name[10];
    // a avarible contents 512 bytes will help me to check the card 512 bytes by 512 bytes
    uint8_t buffer[Block] = {0};
    // a avarible works as counter in do .. while
    int loop_counter = 0;

    // read first 512 in the card file
    fread(buffer, Block, 1, inptr) ;

    // loop to check the memory 512 by 512 bytes and when find new photo create it and completet it then close it
    do
    {
        // if the code finds first part of jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0 )
        {
            // it will check if this photo was not the first jpg in the card , it must close last one
            if (loop_counter > 0 )
            {
                fclose(img);
            }
            // Then the code going on to create new photo with new filename based on the counter
            sprintf(new_file_name, "%03i.jpg", loop_counter);
            loop_counter ++ ;
            img = fopen(new_file_name, "w");
            // the code writes the contents in the new jpg file
            fwrite(buffer, Block, 1, img);
        }
        else
        {
            // if the code doesn't find new photo , it should complete the old one until it is finish
            if (loop_counter > 0 )
            {
                fwrite(buffer, Block, 1, img);
            }
        }

    }
    // the code going to still check all the end of the Card file
    while (fread(buffer, Block, 1, inptr) != 0);

    // close all the open files
    fclose(img);
    fclose(inptr);

}