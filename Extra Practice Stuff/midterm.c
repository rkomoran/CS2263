// take in a string and remove vowels
// using heap memory
#include <stdio.h>
#include <stdlib.h>
int isVowel(char word)
{
    switch (word)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
        return 0;
        break;
    }
    return 1;
}
int lengthOfWord(char * array)
{
    char * ptr = array;
    int count = 0;
    for (; *ptr != '\0'; ptr++)
    {
        count++;
    }
    return count;
}
void printArr(char * array, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}
int main(int argc, char ** argv)
{
    char * word = "abra cadabra";

    char * new_word;
    new_word = malloc(sizeof(word));

    int length = lengthOfWord(word);
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isVowel(word[i]))
        {
            new_word[count] = word[i];
            count++;
        }
    }
    new_word[count] = '\0';
    //printArr(new_word, count);
    printf("New word: %s\n", new_word);
    free(new_word);
}