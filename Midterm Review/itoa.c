#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[])
{
    // int c, i, j;
    // for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    //     c = s[i];
    //     s[i] = s[j];
    //     s[j] = c;
    // }
    char temp;
    int length = strlen(s);
    for (int i = 0; i < length / 2; i++)
    {
        temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

/* itoa:  convert n to characters in s */
void itoa(int n, char s[])
{
    // int i, sign;
    // if ((sign = n) < 0) /* record sign */
    //     n = -n;          /* make n positive */
    // i = 0;
    // do
    // { /* generate digits in reverse order */
    //     s[i++] = n % 10 + '0';
    // } while ((n /= 10) > 0);
    // if (sign < 0)
    //     s[i++] = '-';
    // s[i] = '\0';
    // reverse(s);

    // checks if sign is negative
    // make n positive for iteration
    char sign;
    if (n < 0)
    {
        sign = (n < 0) ? '-': ' ';
        n = n * -1;
    }

    int i = 0;
    for (i = 0; n > 0; i++)
    {
        // note that this chops off the LAST number -- will be backwards once done
        s[i] = (n % 10 + '0');
        n = n/10;
    }

    if (sign == '-')
    {
        s[i] = sign;
        i++;
    }
    s[i] = '\0';

    // need to reverse array now
    reverse(s);
}

int main()
{
    char buffer[20]; // A buffer to store the converted string

    // Test cases
    int test_cases[] = {123, -456, 7890, 1};
    int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    for (int i = 0; i < num_test_cases; i++)
    {
        itoa(test_cases[i], buffer);
        printf("Integer: %d, String: %s\n", test_cases[i], buffer);
    }

    return 0;
}
