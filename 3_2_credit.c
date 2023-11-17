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
    printf("\ncard number m10 %li", cardNumber % 10);
    printf("\n card number m100 %li", (cardNumber % 100 - cardNumber %10) / 10);
    printf("\n card number /10 /m10 %li", (cardNumber / 10 % 10 - cardNumber %10) / 10);

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
    // create a variable to help exracting intended digits
    long digitPowerOfTen = 100;
    int sum = 0;
    while (digitPowerOfTen < cardNumber)
    {    
        // create variables to help exracting intended digits
        long previousDigitsPower = digitPowerOfTen / 10;
        int intendedDigit = (cardNumber % digitPowerOfTen - cardNumber % previousDigitsPower) / previousDigitsPower;
        printf("\ndigitPowerOfTen: %li", digitPowerOfTen);
        printf("\npreviousDigitPower: %li", previousDigitsPower);
        printf("\nintended digit is %i", intendedDigit);
        int multypliedByTwoDigits = intendedDigit * 2;
        sum = sum + multypliedByTwoDigits;
        printf("\nSum = %i", sum);
        printf("\n");

        // Delete last digit from card number temperoaroly
        // cardNumber = cardNumber / powerOfTen;
        digitPowerOfTen *= 100;
    }
    printf("sum before return: %i", sum);
    return sum;
}