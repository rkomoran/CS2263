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
    int c, d;
    int opener = '<';
    bool inTag = false;
    bool in_comment = false;

    char title[] = "Output of htags:\n";
    printArr(title, strlen(title));

    while ((c = getchar()) != EOF)
    {
        // inside tag
        if (c == '<')
        {
            d = getchar();
            // we know it is a comment
            if (d == '!')
            {
                in_comment = true;
            }
            else
            {
                // not in comment, add in the extra characters back
                inTag = true;
                putchar(opener);
                putchar(d);
                continue;
            }
        }
        // outside tag
        else if (c == '>')
        {
            // check if we are still in the comment
            if (in_comment)
            {
                in_comment = false;
                continue;
            }
            else
            {
                putchar(c);
                putchar('\n');
                inTag = false;
            }
        }
        if (inTag && !in_comment)
        {
            putchar(c);
        }
    }
}
