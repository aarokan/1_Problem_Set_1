#include <cs50.h>
#include <stdio.h>

bool checkIfValid(long cardNumber);
int addMultipliedByTwo(long cardNumber);

int main(void) 
{
    // prompt for input (long) 
    long cardNumber;
    do
    {
        cardNumber = get_long("Credit Card Number: ");
    }
    while (cardNumber < 999999999999 || cardNumber > 9999999999999999);
    
    // check if credit card number is valid (calculate Checksum)
    bool cardValidity = checkIfValid(cardNumber);
    // test mod 10 to get last digit
    printf("%li", cardNumber % 10);
    printf("\n%li", (cardNumber % 100 - cardNumber %10) / 10);
    printf("\n%li", (cardNumber / 10 % 10 - cardNumber %10) / 10);

    // check for card length & starting digit (VISA or MASTERCARD ..etc
    
    // print AMEX, MASTERCARD, VISA or INVALID
    
}

bool checkIfValid(long cardNumber)
{
    // Multiply every other digit by 2, starting with the number’s second-to-last
    // then add those products’ digits together (13 would be 1+3) sumOfMultiply
    int sumOfMultiply = addMultipliedByTwo(cardNumber);

    // add digits that weren’t multiplied by 2 (starting from the end) sumOfRemainingDigits
    // if the total’s last digit is 0 (the total modulo 10 is congruent to 0) the num is valid
    return 0;
}

int addMultipliedByTwo(long cardNumber)
{
    /* note: if we take a big number % 10 it will give us last digit */
    // create variable to help moving to previous digit
    int digitDecreaser = 10;
    int sum;
    while (cardNumber > 0)
    {    
        // print last digit
        printf("\nlast digit is %li", (cardNumber / digitDecreaser % 100 - cardNumber %10) / 10);
        int multypliedByTwoDigits = (cardNumber / digitDecreaser % 100 - cardNumber %10) / 10;
        sum = sum + multypliedByTwoDigits;
        printf("\nSum = %i", sum);

        // Delete last digit from card number temperoaroly
        cardNumber = cardNumber / digitDecreaser;
        // digitDecreaser *= 10;
    }
    return sum;
}