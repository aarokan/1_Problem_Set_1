#include <cs50.h>
#include <stdio.h>

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
    /* note: if we take a big number % 10 it will give us last digit*/
    printf("%li", cardNumber % 10);
    printf("\n%li", (cardNumber % 100 - cardNumber %10) / 10);
    printf("\n%li", (cardNumber % 1000 - cardNumber % 100) / 100);
        // Multiply every other digit by 2, starting with the number’s second-to-last
        // then add those products’ digits together (13 would be 1+3) sumOfMultiply
        // add digits that weren’t multiplied by 2 (starting from the end) sumOfRemainingDigits
        // if the total’s last digit is 0 (the total modulo 10 is congruent to 0) the num is valid

    // check for card length & starting digit (VISA or MASTERCARD ..etc
    
    // print AMEX, MASTERCARD, VISA or INVALID

}