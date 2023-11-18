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
    bool cardIsValid = checkIfValid(cardNumber);

    // check for card length & starting digit (VISA or MASTERCARD ..etc
    
    // print AMEX, MASTERCARD, VISA or INVALID
    
}

bool checkIfValid(long cardNumber)
{
    // Multiply every other digit by 2, starting with the number’s second-to-last
    // then add those products’ digits together (13 would be 1+3) into sumOfMultiply
    int sumOfMultiply = addMultipliedByTwo(cardNumber);

    // add digits that weren’t multiplied by 2 (starting from the end) into sumOfRemainingDigits
    // if the total’s last digit is 0 (the total modulo 10 is congruent to 0) the num is valid
    return 0;
}

int addMultipliedByTwo(long cardNumber)
{
    // create a variable to help exracting intended digits
    // note: if we take a big number % 10 it will give us last digit
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
        // add those products’ digits together (13 would be 1+3)
        int lastDigit = multypliedByTwoDigits % 10;
        int firstDigit = (multypliedByTwoDigits - multypliedByTwoDigits % 10) / 10;
        int addedProductsDigits = lastDigit + firstDigit;

        sum = sum + addedProductsDigits;
        printf("\nSum = %i", sum);
        printf("\n");

        // move back two digits by increasing digitPowerOfTen
        digitPowerOfTen *= 100;
    }
    printf("sum before return: %i", sum);
    return sum;
}