#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

void readFile(char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return;
    }

    // *** attempting to read inbetween htags ***
    bool inTag = false, inComment = false;
    int index = 0, unique_words_count = 0, opener = '<', closer = '>', c;
    char word[MAX * 10] = "", unique_words[MAX][MAX] = {" "}; 

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
                inTag = true;
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
                inTag = false;
                word[index++] = closer;
                word[index] = '\0';

                // check if the word is unique
                bool found = false;
                for (int i = 0; i < unique_words_count; i++)
                {
                    if (strcmp(word, unique_words[i]) == 0)
                    {
                        found = true;
                        break;
                    }
                }
                // store unqiue word in array of strings (2D)
                if (!found)
                {
                    strcpy(unique_words[unique_words_count++], word);
                }

                // reset word index to store next word inbetween tags
                index = 0;
            }
        }

        // still in word -- continue storing characters
        if (inTag && !inComment)
        {
            word[index++] = c;
        }
    }

    // print unique words
    printf("Unique words between HTML tags:\n");
    for (int i = 0; i < unique_words_count; i++)
    {
        printf("%s\n", unique_words[i]);
    }
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
