#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int convertInt(char a[], int n);
int addReversedInt(char a[], int n, char b[], int m);
void printNum(int n);
int main(void)
{
    char a[] = {'3', '2', '1'};
    char b[] = {'6','5','4'};

    // size of array 'a'
    int lenA = sizeof(a) / sizeof(char);

    // size of array 'b'
    int lenB = sizeof(b) / sizeof(char);

    int result = addReversedInt(a, lenA, b, lenB);
    // printf("Sum of two arrays: %d\n", addReversedInt(a, lenA, b, lenB));
    printNum(result);
    putchar('\n');
    return EXIT_SUCCESS;
}

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

int addReversedInt(char a[], int n, char b[], int m)
{
    int resultA = convertInt(a, n);
    int resultB = convertInt(b, m);

    return resultA + resultB;
}

/*
    To print the result of convertInt only using
    putchar
*/
void printNum(int n)
{
    if (n/10)
        printNum(n/10);

    putchar(n%10 + '0');
}
