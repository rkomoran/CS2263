#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

int main(int argc, char ** argv)
{
    if (argc < 2)
    {
        printf("ERROR: Provide a file to read.\n");
        return EXIT_FAILURE;
    }
    
    /* check if memory option has been specified */
    bool option = false;
    if (argc == 3 && strcmp(argv[2], "-m") == 0)
    {
        printf("HI");
        option = true;
    }

    /* read in file */
    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("ERROR: Could not open file\n");
        return EXIT_FAILURE;
    }

    bool inTag = false, inComment = false;
    int newAllocation = 0, c, totalAllocation = 0, currentAllocation = 0, totalToPrint = 0, index = 0, opener = '<', closer = '>', unique_words_count = 0;
    char * word = NULL, ** uniqueWord = NULL;

    Node * head = NULL;

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
                //totalAllocation += 2;

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
                totalAllocation += newAllocation;

                word = realloc(word, totalAllocation);             

                inTag = false;
                word[index++] = closer;
                word[index] = '\0';

                // constructing a new node with added tag
                Node * n = Node_construct(word);

                if (head == NULL)
                {
                    totalToPrint += newAllocation;

                    if (option)
                    {
                        printf("Current allocated tag memory: %d\n", newAllocation);
                    }

                    head = List_add(head, n);
                }
                // check if word exists already in list
                else if (List_search(head, n))
                {
                    currentAllocation = newAllocation + (sizeof(n) + (sizeof(n->tag)));
                    totalToPrint += currentAllocation;
                    head = List_add(head, n);
                    if (option)
                    {
                        printf("Current allocated tag memory: %d\n", currentAllocation);
                    }
                }
                else
                {
                    free(n->tag);
                    free(n);
                }

                // reset counters & free temp word array
                totalAllocation = 0;
                index = 0;
                free(word);
            }
        }
        // still in word -- continue storing characters
        if (inTag && !inComment)
        {
            newAllocation++;
            totalAllocation += newAllocation;

            word = realloc(word, totalAllocation);

            word[index++] = c;
        }
    }

    List_print(head);
    fclose(file);

    List_deconstruct(head);

    if (option)
    {
        printf("Total allocated memory: %d bytes\n", totalToPrint);
    }

    return EXIT_SUCCESS;
}