#include <stdio.h>

#define SIZE 26

int main(void)
{
    char first_char = 'a';
    char alphabet[SIZE];
    int i;
    for (i = 0; i < SIZE; i++)
    {
        alphabet[i] = first_char + i;
    }
    printf("Alphabet is as follows:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%c ", alphabet[i]);
    }
    printf("\n");
    
    return 0;
}