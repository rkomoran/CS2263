#include "printArr.h"
#include "readVals.h"
#include "addReversedInt.h"
#include "printReversed.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    This function takes in two numbers from user input,
    converts them into reversed integers from the 
    convertInt function, then adds them together
    using the addReversedInt function

    The output is produced completely from putchar, and the input
    is stored using only getchar from the readVals function

    The function then shows the sum (that is reversed again -- from printReversed)
    of those two numbers provided
*/

void calculatorPrint()
{
    int maxLen = 10;

    char message[] = "Enter two unsigned integer numbers in reverse order to be calculated: ";
    // size of array
    int len = sizeof(message)/sizeof(char);

    printArr(message, len);

    // user input arrays
    char a[maxLen + 1];
    readVals(a);
    char b[maxLen + 1];
    readVals(b);

    // size of array 'a'
    int lenA = strlen(a);

    // size of array 'b'
    int lenB = strlen(b);

    int secondResult = addReversedInt(a, lenA, b, lenB);

    char resultMessage[] = "Result of the two numbers provided: ";
    int resultLen = sizeof(resultMessage)/sizeof(char);
    printArr(resultMessage, resultLen);

    printReversed(secondResult);
}