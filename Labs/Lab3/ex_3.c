#include <stdio.h>
#include <stdlib.h>


int arrindex(int a[], int * p){
    return p - a;
}


int main (int argc ,char * * argv)
{
    int arr[] = {10, 11, 12, 13, 14, 15, 16};
    // this is taking the address of the first element in the array
    // and calculates a difference -- they will be seperated by 4 bytes
    // which would be a difference in 1 element
    // printf("%p\n", arr);
    // printf("%p\n", &arr[1]);
    // printf("%ld\n", &arr[1] - arr);
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i ++){
        printf ("%d   %d \n", i, arrindex( arr, &arr[i])); 
    }
    return EXIT_SUCCESS;
}