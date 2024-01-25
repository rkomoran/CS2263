#include <stdio.h>
#include <stdlib.h>

/*
    This function takes in an array with it's length
    and prints all the elements in said array
    using putchar.

    It then adds a new line after it is done reading the 
    array.
*/

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
        // printf("\n");
    }
    putchar('\n');
}