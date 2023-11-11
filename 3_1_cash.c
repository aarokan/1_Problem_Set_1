#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    // add a quarter until cents are less than 25
    int numOfQuarters = 0;
    while (cents >= 25)
    {
        numOfQuarters++;
        /*
        function receives a copy of the cents variable, 
        rather than a reference to it. Any changes made 
        will not be reflected in the original variable. 
        */
        cents -= 25;
    }
    return numOfQuarters;
}

int calculate_dimes(int cents)
{
    int numOfDimes = 0;
    while (cents >= 10)
    {
        numOfDimes++;
        cents -= 10;
    }
    return numOfDimes;
}

int calculate_nickels(int cents)
{
    int numOfNickels = 0;
    while (cents >= 5)
    {
        numOfNickels++;
        cents -= 5;
    }
    return numOfNickels;
}

int calculate_pennies(int cents)
{
    int numOfPennies = 0;
    while (cents >= 1)
    {
        numOfPennies++;
        cents -= 1;
    }
    return numOfPennies;
}
