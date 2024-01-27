#include <stdio.h>

void swap (int *a, int *b);
int main()
{
   int a, b;

   a = 3;
   b = 5;
   printf("Value of a before: %d\nValue of b before:%d\n", a, b);                               
   swap(&a, &b);
   printf("Value of a after: %d\nValue of b after:%d\n", a, b);

}

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}