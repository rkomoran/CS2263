#include <stdio.h>

int a = 0, b = 1, c = 2, d = 0;

int main(void)
{
    for (int i = 0; i < 20; i ++) 
    {
        if (i % 2 == 0)
        {
            printf("%d ", a);
        }
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
}

