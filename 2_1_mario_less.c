#include <stdio.h>
#include <cs50.h>

/* Recreate Mario pyramid, albeit in text, using hashes (#) for bricks */
// Declare functions
int get_height(void);
void print_pyramid(int);

int main(void)
{
    /*  
    Prompt user for height
    If height is less than 1 or greater than 8 
    (or not an integer at all), go back one step 
    */
    int height = get_height();

    /*  
    Iterate from 1 through height:
    On iteration i, print i hashes and then a newline 
    */
   print_pyramid(height);
}

int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;    
}

void print_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int requiredEmptySpace = height - i + 1;
        while (requiredEmptySpace > 0)
        {
            printf(" ");
            requiredEmptySpace--;
        }
        
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}