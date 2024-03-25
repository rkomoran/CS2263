#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// reads and frees elements of 2D array
void readArray(char ** array, int length)
{
    printf("\n");
    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < length; i++)
    {
        printf("%s\n", array[i]);
        free(array[i]);
    }
    free(array);
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
    int newAllocation = 0, c, totalAllocation = 0, totalToPrint = 0, index = 0, opener = '<', closer = '>', unique_words_count = 0;
    char * word = NULL, ** uniqueWord = NULL;

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
                // reset new word memory allocation
                newAllocation = 0;

                newAllocation += 2;
                totalAllocation += 2;

                inTag = true;

                // allocate new memory on heap of first 2 valid read-in chars
                // for the temp array
                word = malloc(newAllocation * sizeof(char));

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

                // printf("Current Allocation of tag %d bytes\n", newAllocation);

                // check if the word is unique
                bool found = false;
                for (int i = 0; i < unique_words_count; i++)
                {
                    // found word in 2D array
                    if (strcmp(word, uniqueWord[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                // store unique word in array of strings (2D)
                // using malloc (size of the current tag)
                if (!found) {
                    totalToPrint += newAllocation;
                    printf("Current allocated tag memory: %d\n", newAllocation);

                    // row implementation
                    uniqueWord = realloc(uniqueWord, (unique_words_count + 1) * sizeof(char *));

                    // col implementation
                    uniqueWord[unique_words_count] = malloc(newAllocation * sizeof(char)); 

                    // adding word to 2D array
                    strcpy(uniqueWord[unique_words_count], word);
                    unique_words_count++;
                }

                // reset counters & free temp word array
                index = 0;
                free(word);
            }
        }

        // still in word -- continue storing characters
        if (inTag && !inComment)
        {
            newAllocation++;
            totalAllocation++;

            word = realloc(word, totalAllocation);

            word[index++] = c;
        }
    }

    // print unique words & free uniqueWords allocation
    readArray(uniqueWord, unique_words_count);
    fclose(file);
    
    printf("Total allocated memory: %d bytes\n", totalToPrint);
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