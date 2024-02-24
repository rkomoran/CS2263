#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
/* this is an implementation to find only the vowels in a string & store them in a seperate array */

int main()
{
    char* array = "Ryuf";
    // points to first character of the array
    char* ptr = array;
    char new_array[100];
    int length = sizeof(new_array)/sizeof(new_array[0]);

    // keep looping until end of string is specified
    int count = 0;
    int vowelFound = 0;
    while (*ptr != '\0')
    {
        switch (tolower(*ptr))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            new_array[count] = *ptr;
            count++;
            vowelFound = 1;
        break;
        default:
        break;
        }
        ptr++;
    }
    new_array[count]  = '\0';

    if (vowelFound)
    {
        printf("The vowels in %s are: ", array);
        char* iterative_ptr = new_array;
        for (; *iterative_ptr != '\0'; iterative_ptr++)
        {
            printf("%c", *iterative_ptr);
        }
    }
    else
    {
        printf("No vowel found");
    }

    return EXIT_SUCCESS;
}