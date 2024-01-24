#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 10

void printArr(char a[], int n);
void readVals(char input[]);
int convertInt(char a[], int n);
int addReversedInt(char a[], int n, char b[], int m);
void printReversed(unsigned int n);

int main(void)
{
    char message[] = "Enter two unsigned integer numbers in reverse order to be calculated: ";
    // size of array
    int len = sizeof(message)/sizeof(char);

    printArr(message, len);

    // user input arrays
    char a[MAXLEN];
    readVals(a);
    char b[MAXLEN];
    readVals(b);

    // size of array 'a'
    int lenA = strlen(a);

    // size of array 'b'
    int lenB = strlen(b);

    int result = addReversedInt(a, lenA, b, lenB);

    char resultMessage[] = "Result of the two numbers provided: ";
    int resultLen = sizeof(resultMessage)/sizeof(char);
    printArr(resultMessage, resultLen);

    printReversed(result);

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
        toReturn = 10 * toReturn + (a[i] - '0');
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
    Input the arrays as a parameter since values
    are passed by reference.
    Modifying the existing array
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

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}

void printReversed(unsigned int n)
{
    if (n < 10)
    {
        // Converts int into char
        putchar(n + '0');
        putchar('\n');
        return;
    }

    putchar((n % 10) + '0');
    printReversed(n/10);
}
