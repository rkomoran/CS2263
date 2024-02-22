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
    char total_tags[1000][1000];
    char unique_tags[1000][1000];
    int c, index = 0, tag_count = 0, unique_tag_count = 0;
    while ((c = getchar()) != EOF)
    {
        
        if (c == '<')
        {
            //total_tags[tag_count][index++] = c;
            while ((c = getchar()) != EOF && c != '>')
            {
                //printf("%c", c);
                total_tags[tag_count][index++] = c;
            }
            //total_tags[tag_count][index++] = '>';
            total_tags[tag_count][index] = '\0';
            //printf("%s\n", total_tags[tag_count]);
            //printArr(total_tags[tag_count], index);
            //printf("Value of total_tags in interation:\n %s\n", total_tags[tag_count]);

            // this works
            //printArr(total_tags[tag_count], tag_count);
            printf("STRING %s\n", total_tags[tag_count]);

            tag_count++;
            index = 0;
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
    for (int i = 0; i < tag_count; i++)
    {  
       // printf("Total tag string %s\n", total_tags[i]);
        int is_unique = 1;
        for (int j = 0; j < unique_tag_count; j++)
        {
            if (strcmp(unique_tags[j], total_tags[i]) == 0)
            {
                is_unique = 0;
                break;
            }
        }
        if (is_unique)
        {
            strcpy(unique_tags[unique_tag_count], total_tags[i]);
            unique_tag_count++;
        }
    }
    
    // Print unique tags
    printf("\nUnique tags:\n");
    for (int i = 0; i < unique_tag_count; i++) {
        printf("%s\n", unique_tags[i]);
    }
}