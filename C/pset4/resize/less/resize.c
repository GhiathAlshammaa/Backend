/**************************************************
* resize.c
*
* refugees{code} Intake #3
*
* code written by: Mohammad Ghiath Alshammaa
* graded by: TUTOR INSERTS NAME HERE ONCE GRADED
* pset design by Harvard CS50
*
* change the scale of image from small dimension to big dimension
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
// ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

// remember filenames
    char *infile  = argv[2];
    char *outfile = argv[3];

// convert the factor from string to integer
    int n = atoi(argv[1]);

// checking  the factor, it must be positive number & less than 100
    if (n < 1 || n > 100)
    {
        fprintf(stderr, "The factor must be positive number and less than 100 \n");
        return 1;
    }

// open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

// open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

// read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

// read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

// new varibles & updating the dimention
// Dimensions (old & new)
    int oldWidth = abs(bi.biWidth);
    int oldHeight = abs(bi.biHeight);
    bi.biWidth = bi.biWidth * n;
    bi.biHeight = bi.biHeight * n;

// padding (new & old)
    int padding    =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int oldPadding =  (4 - (oldWidth * sizeof(RGBTRIPLE)) % 4) % 4;

// change dimensions in BITMAPINFOHEADER
    bi.biSizeImage = (abs(bi.biWidth) * 3 + padding) * abs(bi.biHeight);

// change dimensions in BITMAPFILEHEADER
    bf.bfSize = bi.biSizeImage + 54 ;

// ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

// write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

// write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

// This varible contents the number of bytes to move Cursor
    int offset ;

// This varible contents the counter_heigh for the loop which responsibility about the high of the new file
    int counter_heigh = 0;

// iterate over infile's scanlines
    while  ( counter_heigh < oldHeight )
    {
        for (int counter = 0; counter < n; counter++)
        {
            // inside the fseek I change the offset to contents the number of bytes to move Cursor
            // and by SEEK_SET I began from the first point of the file by use SEEK_SET
            offset = 54 + counter_heigh * ( (oldWidth * 3) + oldPadding );

            // fseek responsibles about the file position indicator
            fseek(inptr, offset, SEEK_SET);

            // iterate over pixels in scanline
            for (int counter_width = 0; counter_width < oldWidth; counter_width++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // write RGB triple to outfile
                for (int k = 0; k < n; k++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            // then add it back (to demonstrate how)
            for (int k = 0; k < padding; k++)
            {
                fputc(0x00, outptr);
            }
        }

        counter_heigh++;
    }

// close infile
    fclose(inptr);

// close outfile
    fclose(outptr);

// success
    return 0;
}