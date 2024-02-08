// arithmetic1.c
#include <stdio.h>
#include <stdlib.h>
int main (int argc ,char * * argv)
{
    int    arr1[] = {7, 2, 5, 3, 1, 6, -8, 16, 4};
    char   arr2[] = {'m', 'q', 'k', 'z', '%', '>'};
    double arr3[] = {3.14, -2.718, 6.626, 0.529};
    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(char);
    int len3 = sizeof(arr3) / sizeof(double);
    printf("lengths = %d, %d, %d\n", len1, len2, len3);
    int    * iptr = arr1;
    char   * cptr = arr2;
    double * dptr = arr3;

    long int first_addr_iptr = (long int) iptr;
    long int first_addr_cptr = (long int) cptr;
    long int first_addr_dptr = (long int) dptr;
    printf("values = %p, %p, %p\n", iptr, cptr, dptr);
    iptr ++;
    cptr ++;
    dptr ++;
    long int second_addr_iptr = (long int) iptr;
    long int second_addr_cptr = (long int) cptr;
    long int second_addr_dptr = (long int) dptr;
    printf("values = %p, %p, %p\n", iptr, cptr, dptr);
    iptr ++;
    cptr ++;
    dptr ++;
    printf("values = %p, %p, %p\n", iptr, cptr, dptr);
    iptr ++;
    cptr ++;
    dptr ++;
    printf("values = %p, %p, %p\n", iptr, cptr, dptr);

    // increments of each pointer variable
    printf("Increment for iptr: %ld\n", (second_addr_iptr - first_addr_iptr));
    printf("Increment for cptr: %ld\n", (second_addr_cptr - first_addr_cptr));
    printf("Increment for dptr: %ld\n", (second_addr_dptr - first_addr_dptr));

    // increments of the pointers are not the same due to different
    // datatypes requiring different amounts of bytes
    // long - 8 bytes
    // int - 4 bytes
    // char - 1 byte
    return EXIT_SUCCESS;
}