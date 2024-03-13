// The following example creates an array whose length is determined by argc. The pro-
// gram converts the command line arguments—the elements of argv—into integers. This is
// necessary because each element of argv is a string. Then, the program adds up the integers’
// values and prints the sum.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    // need to make integer pointer (since we are dealing with integer malloc)
    // to point to allocated heap memory
    int * arr;

    arr = malloc(argc * sizeof(int));

    if (arr == NULL)
    {
        return EXIT_FAILURE;
    }

    for (int i = 1; i < argc; i++)
    {
        arr[i] = atoi(argv[i]);
    }

    // summing
    int sum = 0;

    for (int i = 0; i < argc; i++)
    {
        sum += arr[i];
    }

    printf("Sum: %d\n", sum);

    free(arr);

    return EXIT_SUCCESS;
}

