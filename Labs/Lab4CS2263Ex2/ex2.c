/* ex1.c */

#include <stdio.h>
#include <stdlib.h>

void dummy_frame()
{
    return;
}

int main(int argc, char * * argv)
{
    int i;
    //   int a[] = {1,2,3,4,5};;
    int * a;
    a = malloc(5 * sizeof(int));
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    for (i=0; i<5; i++)
    printf("main: a = %d %p \n", a[i], &a[i]);
    printf("\n");
    int * b = realloc(a, 7);

    b[5] = 6;
    b[6] = 7;

    for (i=0; i<7; i++)
    printf("main: a = %d %p \n", a[i], &a[i]);

    dummy_frame();
    free(b);
    free(a);

    return EXIT_SUCCESS;
}