#include <stdio.h>
#include <string.h>

int main(void)
{
    char firstName[20], lastName[20];
    unsigned long fnLen, lnLen;  // first name length and last name length
    printf("Enter your full name:");
    scanf("%s %s", firstName, lastName);
    fnLen = strlen(firstName);
    lnLen = strlen(lastName);

    printf("%s %s\n%*lu %*lu\n", firstName, lastName, (int)fnLen, fnLen, (int)lnLen, lnLen);
    printf("%s %s\n%-*lu %-*lu\n", firstName, lastName, (int)fnLen, fnLen, (int)lnLen, lnLen);

    return 0;
}