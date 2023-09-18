#include <stdio.h>

#define _countof(array) (sizeof(array) / sizeof(array[0]))
#define SIZE 10
/*
Exercise 4 Arrays
Create a C program, arrayFun.c.
Create an array of size 10 using only the numbers 1, 2 and 3 (yes the numbers will repeat).
1. Define a symbolic constant called SIZE with value 10, to be used to refer to the size of the array when needed.
2. Implement a function printArray that takes a 1D array of integers, and prints it as shown below.
    Index   Value
    0       1
    1       5
    2       6
    3       8
    4       3
3. Implement a function – swapValues – that takes an array, and two indices.
    It then swaps the values at these indices.
    The changes should be reflected in the original array.
4. Implement a function – binarySearch – which takes a sorted array and target integer,
    then looks for the integer in the array.
    If the target integer is found, return its index, else return -1
*/

void printArray(int arr[], int size)
{
    printf("\tIndex\tValue\n");

    for (int x = 0; x < size; x++)
    {
        printf("\t%d\t%d\n", x, arr[x]);
    }
}

void swapValues(int arr[], int size, int firstIndex, int secondIndex)
{
    if (firstIndex >= size || secondIndex >= size)
    {
        return;
    }
    int secondValue = arr[secondIndex];
    arr[secondIndex] = arr[firstIndex];
    arr[firstIndex] = secondIndex;
}

int binarySearch(int arr[], int size, int value)
{
    if (size == 0)
    {
        return -1;
    }

    int start = 0, end = size - 1;
    while (start <= end)
    {
        int mid = start + ((end - start + 1) / 2);
        // printf("s: %d m: %d e: %d s: %d: %d\n", start, mid, end, size, arr[mid]);

        if (arr[mid] == value)
        {
            return mid;
        }
        else if (value > arr[mid])
        {
            // it's in the lower half
            start = mid + 1;
        }
        else
        {
            // it's in the upper half
            end = mid - 1;
        }
    }
    return -1;
}

void test_fun()
{
    int nums[SIZE] = { 1, 2, 3, 1, 2, 3, 1, 2, 3, 1 };
    printArray(nums, _countof(nums));
    int sortedArray[SIZE] = {2, 2, 3, 3, 3, 5, 8, 10, 11, 14};
    int searchFor = 3;
    printf("%d is at index %d\n", searchFor, binarySearch(nums, _countof(nums), searchFor));
}

void test_binarySearch_array_of_one()
{
    int nums[] = {1};
    int value = 1;
    printf("%d should be at index 0 is found at %d\n", value, binarySearch(nums, _countof(nums), value));
}
void test_binarySearch_array_of_two()
{
    int nums[] = {1, 2};
    printf("%d, expected: -1, found: %d\n", 0, binarySearch(nums, _countof(nums), 0));
    printf("%d, expected:  0, found: %d\n", 1, binarySearch(nums, _countof(nums), 1));
    printf("%d, expected:  1, found: %d\n", 2, binarySearch(nums, _countof(nums), 2));
}

// int main()
// {
//     // test_binarySearch_array_of_two();
//      test_fun();
// }