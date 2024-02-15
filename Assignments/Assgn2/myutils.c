#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}

void concat_string(char word[], char complete_string[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (word[i] == '\n')
        {
            word[i] = ' ';
        }
    }

    strcat(strcat(complete_string, " "), word); 
}

int isValidWord(char word[], char complete_string[], int index)
{
    if (strlen(word) > 0)
        {
            int validWord = true;
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == ' ' && word[i + 1] == ' ') {
                    validWord = false;
                    break;
                }
            }
            if (validWord) {
                concat_string(word, complete_string, index); 
            }
        }
}

void readVal(char word[], char complete_string[])
{
    int c, index = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '>')
        {
            index = 0;
            while ((c = getchar()) != EOF && c != '<')
            {
                word[index] = c;
                index++;
            }
            word[index] = '\0';
            isValidWord(word, complete_string, index);
        }
    }
    printf("%s\n", complete_string);
}