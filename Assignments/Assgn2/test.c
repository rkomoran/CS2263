#include <stdio.h>
#include <string.h>
// this reads in the entire contents of the html file
// using ./test < A2W2024.html

void readFile()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}
// for htags1 -- we need to transverse the html file. 
// this means we need to store it in a char array (string)
// and use pointers (or str library) to determine if we have hit 
// a < followed by another > and get the difference of that.


int main()
{
    /** junk **/
    // char * test = "<body lang=EN-CA link=blue vlink=\"#954F72\">";
    // printf("%s\n", test);
    // // just have a size for 10 now I guess
    // char tags[10];
    // for (int i = 0; i < strlen(test); i++)
    // {
    //     // returns pointer to the first occurrence of
    //     // '<' in the string
    //     if (strchr(test, '<') != NULL)
    //     {

    //     }
    // }
    /** junk **/
    //readFile();
}