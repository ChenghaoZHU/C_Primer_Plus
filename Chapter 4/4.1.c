#include <stdio.h>

int main(void)
{
    char firstName[50], lastName[50];

    printf("Please enter your first name and last name:");
    scanf("%s %s", firstName, lastName);
    printf("Hello, %s,%s\n", firstName, lastName);

    return 0;
}