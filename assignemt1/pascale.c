#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "arrayFun.c"

/*
Write a program pascale.c that prompts the user for an
integer rowIndex and returns an array containing values
of Pascal’s triangle at the given rowIndex.
To learn more about Pascale’s triangle:
https://en.wikipedia.org/wiki/Pascal's_triangle
Example:
Input: rowIndex = 4
Output: 1, 4, 6, 4, 1
Explanation: The following is Pascale’s triangle up to row index = 4:
     1          n = 0       0! / 0! (0 - 0)!
    1 1         n = 1       1! / 1! (1 - 1)!
   1 2 1
  1 3 3 1
 1 4 6 4 1

 n-k k
x   y

n! / k!(n-k)!


*/

int factorialWithMin(int value, int min, int initialTotal)
{
    if (value == min)
        return initialTotal;
    return value * factorialWithMin(value - 1, min, initialTotal);
}

int factorial(int value)
{
    return factorialWithMin(value, 1, 1);
}

char *pascaleTriangle(int rowIndex)
{
    // if (rowIndex == 0)
    // {
    //     return "1";
    // }
    // else if (rowIndex == 1)
    // {
    //     return "1 1";
    // }
    bool isEven = (rowIndex % 2 == 0);
    int loopCount = (rowIndex / 2) + 1;
    if (!isEven)
    {
        loopCount++;
    }

    printf("%d\n", loopCount);

    char *row = (char *)calloc(rowIndex + 2, sizeof(char));
    int *coffiecent;
    if (loopCount > 0)
    {
        coffiecent = (int *)calloc(loopCount, sizeof(int));
    }


    int nFact = factorial(rowIndex), kFact = 1, nMinusK = nFact;
    for (int k = 0; k < loopCount; k++)
    {
        printf("%d %d %d\n", nFact, kFact, nMinusK);
        coffiecent[k] = nFact / (kFact * nMinusK);
        // printf("\t%d\t%d\n", x, arr[x]);

        nFact = nFact / (rowIndex - k);
        kFact *= k;
        nMinusK = factorial(rowIndex - k);
    }

    printArray(coffiecent, loopCount);
    //

    // if (isEven)
    // {
    //     loopCount--;
    // }
    char *pRow = row;
    for (int i = 0; i < loopCount; i++)
    {
        int chars = sprintf(pRow, "%d", coffiecent[i]);
        pRow = pRow + chars;
        *pRow = ' ';
        pRow++;
    }
    pRow++;
    pRow = '\0'; // null terminator
    
    free(coffiecent);
    return row;
}

int main()
{
    printf("Enter the rowIndex for pascale triangle.\nInput: ");
    int rowIndex = 0;
    scanf("%d", &rowIndex);

    char *result = pascaleTriangle(rowIndex);

    printf("Resulted row is %s\n", result);
}