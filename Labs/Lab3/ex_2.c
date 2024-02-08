#include <stdio.h>

void print_element(int * arr, int len);
void main()
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    int len = sizeof(arr)/sizeof(arr[0]);
    print_element(arr, len);
}

// prints twice by referencing
// arr[i] and by pointer only
void print_element(int *arr, int len) {
    int * parr = arr;
    printf("Index\tValue\t\tAddress\t\t\tValue\n");
    for (int i = 0; i < len; i++) {
        printf("%-4d\t%-6d\t%p\t%d\n", i, arr[i], parr, *(parr++));
    }
}