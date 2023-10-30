#include <stdio.h>
#include <cs50.h>

/* Recreate Mario pyramid, albeit in text, using hashes (#) for bricks */

int main(void)
{
    // Prompt height input 1-8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Loop from 0 to height (col)
    for (int row = 1; row <= height; row++)
    {
        // Right-align pyramid by printing empty space
        int requiredEmptySpaces = height - row;
        while (requiredEmptySpaces > 0)
        {
            printf(" ");
            requiredEmptySpaces--;   
        }

        // Loop from 0 to current counter (row)
        for (int col = 1; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");
    }
}