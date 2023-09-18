#include <stdio.h>

/*
Exercise 3 Even and Odd Bits
Write a C program evenOdd.c that prompts the user to enter a positive integer n.
 The program then counts and prints the number of occurrences of the “1” bit on
 each of the even and odd indices in the binary representation of n.
Example:
Input: 13 (hint: Binary representation is 1101)
Output: even: 2, odd: 1 (hint: It contains 1 on 0th 2nd & 3rd indices)
*/
void evenOdd()
{
    printf("Enter a positive integer.\nInput: ");
    int input = 0, even = 0, odd = 0;
    scanf("%d", &input);

    for (int i = 0; input > 0; i++)
    {
        printf("%d %d\n", i, input);
        if (input & 1 == 1)
        {
            if (i % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        input = input >> 1;
    }

    // printf("%d %d \n", 2 >> 1, 2 >> 1 >> 1);
    printf("Output: even: %d, odd: %d\n", even, odd);
    // system("pause");
}

// int main()
// {
//     evenOdd();
// }