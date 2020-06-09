#include <cs50.h>
#include <stdio.h>


int main(void)
{
    //Prompt for user input
    long userinput;
    do
    {
        userinput = get_long("Number:");
    }
    while (userinput < 0);

    //Extract individual digits in userinput, save in array
    long quotient = userinput;
    int digit, i = 0;
    int array[16] = {}; // maximum number of digits in cc is 16

    do
    {
        digit = quotient % 10;
        array[i] = digit;
        i = i + 1;
        quotient = quotient / 10;
    }
    while (quotient > 0);

    //Calculate checksum. First muliply every other digit, starting with the tens
    int j = 0, doublearray[16] = {};
    for (i = 1; i < 16; i = i + 2)
    {
        doublearray[j] = 2 * array [i];
        j = j + 1;
    }

    //Second step: add the products' digits together:
    int sum = 0;
    for (j = 0; j < 8; j = j + 1)
    {
        sum = sum + doublearray[j] % 10 + doublearray[j] / 10;
    }

    //Third step: add the sum to the sum of digits that weren't multiplied by 2
    int second_sum = 0;
    for (i = 0; i < 16; i = i + 2)
    {
        second_sum = second_sum + array[i];
    }

    int grand_total = sum + second_sum;

    //Fourth step: Check last digit of grand total
    int last_digit;
    last_digit = grand_total % 10;

    // Count number of digits in number
    int count = 0;
    long number = userinput;

    do
    {
        count = count + 1;
        number = number / 10;
    }
    while (number > 0);

    i = 0;
    if (last_digit == 0 && count == 15 && array[14] == 3 && (array[13] == 4 || array[13] == 7))
    {
        printf("AMEX\n");
    }
    else if (last_digit == 0 && count == 16 && array[15] == 5 && array[14] > 0 && array[14] < 6)
    {
        printf("MASTERCARD\n");
    }
    else if (last_digit == 0 && ((count == 13 && array[12] == 4) || (count == 16 && array[15] == 4)))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}



