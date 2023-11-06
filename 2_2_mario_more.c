#include <cs50.h>
#include <stdio.h>

/* Recreate Mario double pyramid, albeit in text, using hashes (#) for bricks */

int main(void)
{
    // Prompt height input 1-8
    int height;        
    do
    {
        height = get_int("Height: ");
    } 
    while (height < 1 || height > 8);
    
    // Loop from 0 to height (row)
    for (int row = 0; row < height; row++)
    {
        // Right-align pyramid by printing required empty space 
        int requiredEmptySpace = height - row - 1;
        while (requiredEmptySpace > 0)
        {
            printf(" ");
            requiredEmptySpace--;
        }
        
        // print (i hashes + double space + i hashes)
        for (int i = 0; i <= row; i++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j <= row; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}