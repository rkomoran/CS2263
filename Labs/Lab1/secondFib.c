#include <stdio.h>
int main(void)
{
    int a = 0, c = 0, i = 0;
    int b = 1;

    while (i < 20)
    {
        if ((i % 2) == 0)
        {
            printf("%d ", a);
        }
        c = a + b;
        a = b;
        b = c;
        i++;
    }
}
