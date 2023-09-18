#include <stdio.h>

void hammingweight()
{
    printf("Enter your the value of an unsigned int: ");
    unsigned int input;
    scanf("%u", &input);
    int count = 0;
    unsigned int value = input;
    while (value != 0)
    {
        if (value & 1 == 1)
        {
            count++;
        }
        value = value >> 1;
    }

    // printf("%d %d \n", 2 >> 1, 2 >> 1 >> 1);
    printf("%u has %d “1” bits in its binary representation.\n", input, count);
    // system("pause");
}

int main()
{
    hammingweight();
}