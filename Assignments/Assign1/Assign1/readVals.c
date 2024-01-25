#include <stdio.h>

/*
    This function takes an empty string, or char array,
    as input; and fills that array using
    getchar until it reaches "ENTER" by user
    or end-of-file

    The array is then terminated with a null operator 
*/

void readVals(char input[])
{   
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        input[i] = c;
    }
    // add null terminating char
    input[i] = '\0';
}