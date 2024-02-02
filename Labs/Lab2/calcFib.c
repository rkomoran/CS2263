#include <stdio.h>

int calcTrib(int n) {
    if (n == 0) {
        return 0;
    }
    int a = 0, b = 0, c = 1, d = 0;
    for (int i = 1; i <= n; i++) {
        d = a + b + c;
        a = b;
        b = c;
        c = d;
    }
    return a;
}

int main(void)
{
    for (int i = 0; i < 20; i += 2) 
    {
        printf("%d ", calcTrib(i));
    }
    printf("\n");
}
