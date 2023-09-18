#include <stdio.h>

void greetUser() {
    printf("Enter your first name: ");
    char firstName[10];
    scanf("%10s", firstName);
    // scanf_s("%10s", firstName, 11);
    printf("Hello %s! Good luck on your assignment\n", firstName);
}

int main() {
    greetUser();
}