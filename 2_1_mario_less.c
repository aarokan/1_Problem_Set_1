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
    while (height < 1 || height > 9);
    
    // Loop from 0 to height (col)
    for (int row = 0; row < height; row++)
    {
        // Loop from 0 to current counter (row)
        for (int col = 0; col <= row; col++)
        {
            printf("#");
        }
        printf("\n");
    }
}