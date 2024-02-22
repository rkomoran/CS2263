#include <stdio.h>
#include <ctype.h>

// from Assgn 1
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
    int index = 0;
    char tag[100000];
    // this reads in data from stdin
    while ((c = getchar()) != EOF)
    {
        // check if in opening tag
        // ignore if it is a comment
        if (c == '<' && (c = getchar() != '!'))
        {
            while ((c = getchar()) != EOF && c != '>')
            {
                tag[index] = c;
                index++;
            }
        }
    }
    tag[index] = '\0';
    printArr(tag, index);
}

