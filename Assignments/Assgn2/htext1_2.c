#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}

int main()
{
    int c;
    bool inTag = false;
    bool outTag = false;

    char title[] = "Output of htext:\n";
    printArr(title, strlen(title));
    
    while ((c = getchar()) != EOF)
    {
        // outside of the tag, also the start position
        if (c == '>')
        {
            outTag = true;
            continue;
        }
        // inside of a tag, also the stop position
        else if (c == '<')
        {
            inTag = true;
            outTag = false;
        }
        // keep printing until we reach another opening tag
        if (outTag)
        {
            putchar(c);
        }
    }
    putchar('\n');
}