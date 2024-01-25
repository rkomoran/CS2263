#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include "convertInt.h"

/*
    This function takes in two character arrays
    that contain numbers and their respective lengths

    It then calls convertInt function to reverse & convert these
    chars into integers

    addReversedInt sums the result of these arrays respectively &
    returns it as an int.
*/

int addReversedInt(char a[], int n, char b[], int m)
{
    int resultA = convertInt(a, n);
    int resultB = convertInt(b, m);

    return resultA + resultB;
}