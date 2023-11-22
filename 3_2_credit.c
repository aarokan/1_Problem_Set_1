#include <cs50.h>
#include <stdio.h>

bool checkIfValid(long cardNumber);
int addMultipliedByTwo(long cardNumber);
int addRemainingDigits(long cardNumber);

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
    
    // check for card validity, length & starting digit (VISA or MASTERCARD ..etc
    // then print AMEX, MASTERCARD, VISA or INVALID
    if (!cardIsValid)
    {
        printf("\nCard is not Valid");
    } else
    {
        printf("\nCard is Valid");
    }
}

bool checkIfValid(long cardNumber)
{
    // Multiply every other digit by 2, starting with the number’s second-to-last
    // then add those products’ digits together (13 would be 1+3) into sumOfMultiply
    int sumOfMultiply = addMultipliedByTwo(cardNumber);

    // add digits that weren’t multiplied by 2 (starting from the end) into sumOfRemainingDigits
    int sumOfRemainingDigits = addRemainingDigits(cardNumber);

    // if the total’s last digit is 0 (the total modulo 10 is congruent to 0) the num is valid
    if ((sumOfMultiply + sumOfRemainingDigits) % 10 == 0)
    {
        return true;
    } else
    {
        return false;
    } 
}

int addMultipliedByTwo(long cardNumber)
{
    // create a variable to help exracting intended digits
    // note: if we take a big number % 10 it will give us last digit
    long digitPowerOfTen = 100;
    int sum = 0;
    while (digitPowerOfTen < cardNumber * 10)
    {    
        // create variables to help exracting intended digits
        long previousDigitsPower = digitPowerOfTen / 10;
        int intendedDigit = (cardNumber % digitPowerOfTen - cardNumber % previousDigitsPower) / previousDigitsPower;
        int multypliedByTwoDigits = intendedDigit * 2;

        // add those products’ digits together (13 would be 1+3)
        int lastDigit = multypliedByTwoDigits % 10;
        int firstDigit = (multypliedByTwoDigits - multypliedByTwoDigits % 10) / 10;
        int addedProductsDigits = lastDigit + firstDigit;

        sum = sum + addedProductsDigits;

        // move back two digits by increasing digitPowerOfTen
        digitPowerOfTen *= 100;
    }
    return sum;
}

int addRemainingDigits(long cardNumber)
{
    // create a variable to help exracting intended digits
    // note: if we take a big number % 10 it will give us last digit
    long remDigitPowerOfTen = 10;
    int remSum = 0;
    while (remDigitPowerOfTen < cardNumber * 10)
    {
        // create variables to help exracting intended digits
        long remPreviousDigitsPower = remDigitPowerOfTen / 10;
        int remIntendedDigit = (cardNumber % remDigitPowerOfTen - cardNumber % remPreviousDigitsPower) / remPreviousDigitsPower;

        // add those digits together
        remSum += remIntendedDigit;

        // move back two digits by increasing digitPowerOfTen
        remDigitPowerOfTen*= 100;
    }
    return remSum; 
}