#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;    //prompt for user input. If bad input, prompt again. There will be at least one prompt.
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);
    //Start of printing. Algorithm: print ".", then #, then ".", then "#".
    for (int row = 0; row < height; row = row + 1)  //Starting from row 0, maximum number of rows = input. For every row:
    {
        for (int column = 0; column < (height * 2 + 2); column = column + 1)    //maximum number of col = 2 times input + 2 "."
        {
            if (column < (-row + height -1))   //the number of . decreases with row. So, the maths formula of col must be (neg)row.
            {                               //plus a constant to make sure total number of columns is constant in each row.
                printf(" ");                // -1 because first row has at least one hash, so one fewer "."
            }
            else if (column > (-row + height - 2) && column < height)
            {
                printf("#");
            }
            else if (column > (height - 1) && column < (height + 2))
            {
                printf(" ");
            }
            else if (column > (height + 1) && column < (row + height + 3))
            {
               printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

}