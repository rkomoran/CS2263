#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* we're going to make a program that counts n amount of substrings in a string */
/* this will take standard input from the terminal */
/* second argument will be the bigger string, and the third will be the smaller one */
int main (int argc, char ** argv)
{
    /* if needle & haystack are not supplied */
    if (argc < 3)
    {
        printf("more inputs pls");
        return EXIT_FAILURE;
    }

    // points to the big string in argument
    char * ptr;

    ptr = argv[1];
    printf("Value of string: %s\n", ptr);

    int count = 0;
    do
    {
        ptr = strstr(ptr, argv[2]);
        if (ptr != NULL)
        {
            printf("%s\n", ptr);
            count++;
            ptr++;
        }
    }
    while(ptr != NULL);

    return EXIT_SUCCESS;
}
