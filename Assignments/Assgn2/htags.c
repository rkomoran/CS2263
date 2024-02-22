#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 100000

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}

void readTag(char * tag)
{
    int c, i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '<')
        {
            tag[i++] = c;
            while ((c = getchar()) != EOF && c != '>' && c != '!')
            {
                tag[i++] = c;
            }
            tag[i++] = '>';
            tag[i++] = '\n';   
        }
        tag[i++] = '\0';
    }
    printArr(tag, i);
}

int main(void)
{
    char tag[MAXSIZE];
    readTag(tag);
}