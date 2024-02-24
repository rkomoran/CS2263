#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* atoi:  convert s to integer */
int my_atoi(char s[])
{
    int sign = 1;
    int result = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        /* check if number provided is negative */
        if (s[i] == '-')
        {
            sign = -1;
        }
        /* convert the string to an integer */
        if (isdigit(s[i]))
        {
            result = result * 10 + (s[i] - '0');
        }
    }
    return sign * result;
}

int main()
{
    char num1[] = "123";
    char num2[] = "-567";

    int result1 = my_atoi(num1);
    int result2 = my_atoi(num2);

    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);

    return 0;
}
