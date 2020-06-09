#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;  //prompt user for non-negative amount owed

    do
    {
        dollars = get_float("Change owed:");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);

    //Use the largest coins possible.
    //Keep track of coins used.
    int n = 0;
    //Keep track of remaining change owed.
    int change = cents;

    //While we can use quarters, add a quarter.
    while (change >= 25)
    {
        change = change - 25;
        n = n + 1;
    }

    //While we can use dimes, add a dime.
    while (change >= 10)
    {
        change = change - 10;
        n = n + 1;
    }

    while (change >= 5)
    {
        change = change - 5;
        n = n + 1;
    }

    while (change > 0)
    {
        change = change - 1;
        n = n + 1;
    }

    //Print the number of coins.
    printf("%i\n", n);
}