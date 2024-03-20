#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void readArray(char * array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}

void readFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    bool inTag = false, inComment = false;
    int newAllocation = 0, c, totalAllocation = 0, index = 0, opener = '<', closer = '>', unique_words_count = 0;
    char * word;
    char ** uniqueWord = NULL;

    while ((c = fgetc(file)) != EOF)
    {

        // inside opening tag
        if (c == '<')
        {
            c = fgetc(file);

            // check if next character is in comment or not
            if (c == '!')
            {
                inComment = true;
                continue;
            }
            else
            {
                newAllocation = 0;

                newAllocation += 2;
                totalAllocation += 2;

                inTag = true;
                word = malloc(totalAllocation * sizeof(char));
                word[index++] = opener;
                word[index++] = c;
                continue;
            }
        }

        else if (c == '>')
        {
            if (inComment)
            {
                inComment = false;
                continue;
            }
            else 
            {
                newAllocation += 2;
                totalAllocation += 2;

                word = realloc(word, totalAllocation);

                inTag = false;
                word[index++] = closer;
                word[index] = '\0';

                printf("Current Allocation of tag %d\n", newAllocation);

                //readArray(word, totalAllocation);
                // next step would be making a new 2D array
                // and making it the size of totalAllocation here
                // (should be the bytes from 1 tag)

                // then figuring out if this word already exists in the 
                // 2D array

                // check if the word is unique
                bool found = false;
                for (int i = 0; i < unique_words_count; i++)
                {
                    // found word
                    if (strcmp(word, uniqueWord[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                // store unqiue word in array of strings (2D)
                // using malloc (size of the current tag)
                if (!found) {
                    uniqueWord = realloc(uniqueWord, (unique_words_count + 1) * sizeof(char *));
                    uniqueWord[unique_words_count] = malloc(totalAllocation * sizeof(char));
                    strcpy(uniqueWord[unique_words_count++], word);
                }

                // reset counters & free temp word array
                index = 0;
                free(word);
            }
        }

        // still in word -- continue storing characters
        if (inTag && !inComment)
        {
            newAllocation += 1;
            totalAllocation++;

            word = realloc(word, totalAllocation);

            word[index++] = c;
        }

        //printf("%c", c);
    }

    // print unique words & free uniqueWords allocation
    printf("\n");
    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < unique_words_count; i++)
    {
        printf("%s\n", uniqueWord[i]);
        free(uniqueWord[i]);
    }

    printf("Total allocated memory: %d\n", totalAllocation);
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }

    readFile(argv[1]);

    return EXIT_SUCCESS;
}