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
    
    // Loop from 0 to height (col)
    for (int col = 0; col < height; col++)
    {
        // Right-align pyramid by printing required empty space 
        int requiredEmptySpace = height - col + 1;
        while (requiredEmptySpace > 0)
        {
            /* code */
        }
        

        // print (i hashes + double space + i hashes)
    }
}