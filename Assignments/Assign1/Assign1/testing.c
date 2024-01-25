#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLEN 10

#include "convertInt.h"
#include "addReversedInt.h"
#include "printArr.h"
#include "printNum.h"
#include "printReversed.h"
#include "readVals.h"
#include "calculator.h"

int main(void) {

    // ex 1
    printf("Example 1 Tests:\n");
    // first example
    printf("First Test:\t");
    char helloWorld[] = "Hello World";
    printArr(helloWorld, strlen(helloWorld));

    // second example
    printf("\nSecond Test:\t");
    char className[] = "I'm in CS2263!";
    printArr(className, strlen(className));

    // third example
    printf("\nThird Test:\t");
    char name[] = "My name is Rinor\n";
    printArr(name, strlen(name));

    // ex 2
    printf("Second Example Tests:\n");

    // first example
    printf("\nFirst Test:\n");
    unsigned int numToReverse = 2263;
    printf("Reversed number of %u: ", numToReverse);
    printReversed(numToReverse);

    // second example
    printf("\nSecond Test:\n");
    numToReverse = 1234;
    printf("Reversed number of %u: ", numToReverse);
    printReversed(numToReverse);

    // third example
    printf("\nThird Test:\n");
    numToReverse = 5656;
    printf("Reversed number of %u: ", numToReverse);
    printReversed(numToReverse);
    printf("\n");

    // ex 3
    printf("Third Example Tests:\n");

    // first example
    printf("\nFirst Test:\n");
    char reversedDigits[] = {'3', '2', '1', '\0'};
    printf("Integer to be converted:  ");
    printArr(reversedDigits, strlen(reversedDigits));

    int convertedInt = convertInt(reversedDigits, strlen(reversedDigits));
    printf("Converted integer: %d\n", convertedInt);

    // second example
    printf("\nSecond Test:\n");
    char reversedDigits2[] = {'8', '3', '6', '\0'};
    printf("Integer to be converted:  ");
    printArr(reversedDigits2, strlen(reversedDigits2));

    convertedInt = convertInt(reversedDigits2, strlen(reversedDigits2));
    printf("Converted integer: %d\n", convertedInt);

    // third example
    printf("\nThird Test:\n");
    char reversedDigits3[] = {'9', '9', '1', '\0'};
    printf("Integer to be converted:  ");
    printArr(reversedDigits3, strlen(reversedDigits3));

    convertedInt = convertInt(reversedDigits3, strlen(reversedDigits3));
    printf("Converted integer: %d\n", convertedInt);

    // ex 4
    printf("\nFourth Example Tests:\n");

    // first example
    printf("\nFirst Test:\n\n");
    printf("Values to be added:\n\n");
    char a[] = {'3', '2', '1', '\0'};
    char b[] = {'6', '5', '4', '\0'};
    printf("First Value: ");
    printArr(a, strlen(a));
    printf("Second Value: ");
    printArr(b, strlen(b));
    int result = addReversedInt(a, strlen(a), b, strlen(b));
    printf("Sum of reversed integers: %d\n", result);

    // second example
    printf("\nSecond Test:\n\n");
    printf("Values to be added:\n\n");
    char c[] = {'7', '1', '8', '\0'};
    char d[] = {'7', '1', '\0'};
    printf("First Value: ");
    printArr(c, strlen(c));
    printf("Second Value: ");
    printArr(d, strlen(d));
    result = addReversedInt(c, strlen(c), d, strlen(d));
    printf("Sum of reversed integers: %d\n", result);

    // Third example
    printf("\nThird Test:\n\n");
    printf("Values to be added:\n\n");
    char e[] = {'1', '9', '9', '\0'};
    char f[] = {'3', '9', '9', '8', '\0'};
    printf("First Value: ");
    printArr(e, strlen(e));
    printf("Second Value: ");
    printArr(f, strlen(f));
    result = addReversedInt(e, strlen(e), f, strlen(f));
    printf("Sum of reversed integers: %d\n", result);

    // ex 5
    printf("\nFifth Example Tests\n");

    // first example
    printf("\nFirst Test:\n\n");
    calculatorPrint();
    
    // second example
    printf("\nSecond Test:\n\n");
    calculatorPrint();

    // third example
    printf("\nThird Test:\n\n");
    calculatorPrint();

    return 0;
}
