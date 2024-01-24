#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int convertInt(char a[], int n);
void printNum(int n);
int main(void)
{
    char a[] = {'3', '2', '1'};

    // size of array
    int len = sizeof(a) / sizeof(char);

    int result = convertInt(a, len);
    // testing purposes
    // printf("Result: %d\n", convertInt(a, len));
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
