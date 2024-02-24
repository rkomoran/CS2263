#include <stdio.h>
#include <stdlib.h>
/* binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low = 0, mid, high = n;
    
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x > v[mid])
        {
            low = mid + 1;
        }
        else if (x < v[mid])
        {
            high = mid - 1;
        }
        else 
        {
            return mid;
        }
    }
    return EXIT_FAILURE;
}

int main()
{
    int arr[] = {2, 3, 4, 6, 8, 10};
    int num = 10;
    int length = sizeof(arr)/sizeof(int);
    int value = binsearch(num, arr, length - 1);

    printf("Posisiton value %d is in:\t arr[%d]", num, value);
}