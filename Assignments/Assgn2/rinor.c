#include <stdio.h>
#include <string.h>
#include <ctype.h>

char complete_string[100000] = "test";

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}

void concat_string(char word[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Word = %c\n", word[i]);
        if (word[i] == '\n')
        {
            word[i] = ' ';
        }
    }
    if (strcmp(complete_string, " ") == "\0")
    {
        strcat(complete_string, word);
    }
    else {
        strcat(strcat(complete_string, " "), word); 
    }
}

void validWord (char word[], int index)
{
    if (strlen(word) > 0)
        {
            int validWord = 1;
            for (int i = 0; i < strlen(word) - 1; i++) {
                if (word[i] == ' ' && word[i + 1] == ' ')  {
                    validWord = 0;
                    break;
                }
            }
            if (validWord) {
                concat_string(word, index); 
            }
        }
}

int main(void)
{
    int c, index = 0, total_chars = 0;
    char word[1000000] = "";
    while ((c = getchar()) != EOF)
    {
        if (c == '>')
        {
            index = 0;
            while ((c = getchar()) != EOF && c != '<')
            {
                word[index] = c;
                index++;
                total_chars++;
            }
            word[index] = '\0';
            validWord(word, index);
        }
    }
    printArr(complete_string, total_chars);
    return 0;
}