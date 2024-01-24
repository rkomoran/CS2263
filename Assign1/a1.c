#include <stdio.h>
#include <stdlib.h>

void printArr(char a[], int n);
int main(void)
{
    char message[] = "Hello World";

    // size of array
    int len = sizeof(message)/sizeof(char);

    printArr(message, len);

    return EXIT_SUCCESS;
}

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
