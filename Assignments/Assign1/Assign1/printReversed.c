#include <stdio.h>
#include <stdlib.h>

/*
    This function takes in an integer
    and prints out the reversed char representation
    of that integer using putchar

    Recursion is used to retrieve the last digit
    until last one is reached
*/

void printReversed(unsigned int n)
{
    if (n < 10)
    {
        // converts int into char
        putchar(n + '0');
        putchar('\n');
        return;
    }

    putchar((n % 10) + '0');
    printReversed(n/10);
}