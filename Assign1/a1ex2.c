#include <stdio.h>
#include <stdlib.h>

void printReversed(unsigned int n);
int main(void)
{
    unsigned int n = 2263;
    printReversed(n);

    return EXIT_SUCCESS;
}

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
