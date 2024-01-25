#include <stdio.h>

/*
    ***NOTE***
    The use of the function is not in my program currently,
    it was apart of it earlier, but since I added & linked
    all my code together to a driver; I found no use for it anymore.

    I kept it here for future reference

    This function takes an integer as input and 
    prints that integer as a char using putchar

    Recursion is again used here to first get to the 
    first integer, and then recurse back to the last integer
    while printing using putchar
*/

void printNum(int n)
{
    if (n/10)
        printNum(n/10);

    putchar(n%10 + '0');
}