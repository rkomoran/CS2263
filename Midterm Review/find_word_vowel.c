#include <stdio.h>
#include <ctype.h>
#define MAX 100

int main()
{
    char* input = "here Are a series of words, some of them start with vowels; and others do not";
    char* ptr = input;

    char vowelWords[MAX];

    int vowelIndex = 0;
    while (*ptr != '\0')
    {
        switch (tolower(*ptr))
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            // found vowel -- keep finding characters until a \n or ' ' is encountered.
            vowelWords[vowelIndex++] = *ptr;
            ptr++;
            while(*ptr != '\0' && *ptr != ' ' && *ptr != '\n')
            {   
                vowelWords[vowelIndex++] = *ptr;
                ptr++;
            }
            vowelWords[vowelIndex++] = ' ';
            break;
            // keep looping until next word is met
        default:
            while(*ptr != '\0' && *ptr != ' ' && *ptr != '\n')
            {
                ptr++;
            }
            if (*ptr == ' ' || *ptr == '\n')
            {
                ptr++;
            }
            break;
        }
    }
    vowelWords[vowelIndex] = '\0';

    printf("The words starting with vowels are: ");
    
    for (int i = 0; i < vowelIndex; i++)
    {
        printf("%c", vowelWords[i]);
    }
    printf("\n");

    return 0;
}
