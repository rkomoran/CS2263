#include <stdio.h>
#include <string.h>

int strlen_recursive(char * string);
int main()
{
    char string[] = "Hello";
    printf("Length of %s: %d\n", string, strlen_recursive(string));
}

int strlen_recursive(char * string)
{
    if (*string == '\0')
    {
        return 0;
    }   
    return 1 + strlen_recursive(++string);
}