#include <stdio.h>
#include <string.h>

void printArr(char a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        putchar(a[i]);
    }
    putchar('\n');
}
// one way to do this is to keep assigning a 1d array and holding the current string and check it with the 2d unique_tags array
// if it exists
int main()
{
    char unique_tags[1000][1000];
    int c;
    int length = 0;
    int tag_count = 0;
    int unique_tag_count = 0;
    char current_tag[1000];

    while ((c = getchar()) != EOF)
    {
        if (c == '<')
        {
            //total_tags[tag_count][index++] = c;
            c = getchar();
            while (c != EOF && c != '>')
            {
                //printf("%c", c);
                //printf("Index before: %d\n", index);
                current_tag[length] = c;
                //printf("Index after %d\n", index);
                printf("%c:[%d],", c, length);
                length++;
                c = getchar();
            }
            //total_tags[tag_count][index++] = '>';
            current_tag[length] = '\0';
            //printf("Index after final: %d\n", index);
            //printf("%s\n", total_tags[tag_count]);
            //printArr(total_tags[tag_count], index);
            //printf("Value of total_tags in interation:\n %s\n", total_tags[tag_count]);

            // this works
            //printArr(total_tags[tag_count], tag_count);
            printf("\t: STRING %s\n", current_tag);

            tag_count++;
            length = 0;
        }
    }
    // for (int i = 0; i < tag_count; i++)
    // {
    //     if (strcmp("/body", total_tags[i]))
    //     {
    //         printf("hi");
    //     }
    //    //printf("%s ", total_tags[i]);
    // }
    // Check for unique tags
    // for (int i = 0; i < tag_count; i++)
    // {  
    //    // printf("Total tag string %s\n", total_tags[i]);
    //     int is_unique = 1;
    //     for (int j = 0; j < unique_tag_count; j++)
    //     {
    //         if (strcmp(unique_tags[j], total_tags[i]) == 0)
    //         {
    //             is_unique = 0;
    //             break;
    //         }
    //     }
    //     if (is_unique)
    //     {
    //         strcpy(unique_tags[unique_tag_count], total_tags[i]);
    //         unique_tag_count++;
    //     }
    // }
    
    // Print unique tags
    printf("\nUnique tags:\n");
    for (int i = 0; i < unique_tag_count; i++) {
        printf("%s\n", unique_tags[i]);
    }
}
// int main()
// {
//     // char dogshit[][10] = {"Hello", "yep", "fuck", "you"};

//     // printf("%s\n", dogshit[2]);
//     // int c, index = 0;
//     // char array[10];
//     // while ((c = getchar()) != EOF)
//     // {
//     //     array[index++] = c;
//     // }
//     // array[index] = '\0';

//     // printf("String %s\n", array);
// }