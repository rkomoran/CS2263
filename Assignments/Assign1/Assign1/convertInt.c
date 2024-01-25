#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    The following function takes in a char and 
    pre-determined length of said array.

    It then converts each char read into a ongoing
    integer sum which is stored in toReturn

    toReturn returns the original char input of numbers
    to integer numbers that are reversed
*/

int convertInt(char a[], int n)
{
    int i, toReturn;
    toReturn = 0;
    
     /*
        this example is directly from section 2.7 Type Conversions
        from K & R - C Textbook
    */
    for (i = n - 1; i >= 0 && isdigit(a[i]); i--)
    {   
        /* 
           adds a 0 to the end of the current num 
           so it can directly concat the next number. 
        */ 
        toReturn = (a[i] - '0') + 10 * toReturn;
    }
    return toReturn;
}