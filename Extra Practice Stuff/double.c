#include <stdio.h>
#include <stdlib.h>
void setArray(int * arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = i;
    }
}
void printArr(int * arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%2d ", arr[i]);
    }
}
void doubleItUp(int * arr, int length)
{
    int total = 0;

    for (int i = 0; i < length; i++)
    {
        arr[i] = arr[i]*2;
    }
}
int main()
{
    int * arr;
    int iter = 0;
    int length = 12;

    arr = malloc(length * sizeof(int));

    if (arr == NULL)
    {
        printf("error");
        return EXIT_FAILURE;
    }

    setArray(arr, length);
    doubleItUp(arr, length);
    printArr(arr,length);

    free(arr);
}