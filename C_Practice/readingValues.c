#include <stdio.h>
#include <stdlib.h>
int main(){

  int a, b;
  printf("Enter first value:\t");
  if (scanf("%d", &a) == 1) {
    printf("Enter second value:\t");
    if (scanf("%d", &b) == 1) {
      printf("Value of first value:\t%d\nValue of second value:\t%d\n", a, b);
    }
    else {
      return EXIT_FAILURE;
    }

  }
  else{
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
