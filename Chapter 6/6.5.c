#include <stdio.h>

int main(void)
{
    char ch;
    int height, i, j;

    printf("Enter a capital letter: ");
    scanf("%c", &ch);
    
    height = ch - 'A' + 1;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j < i; j++)
        {
            printf("%c", 'A' + j);
        }

        printf("%c", 'A' + i);

        for (j = 0; j < i; j++)
        {
            printf("%c", 'A' + i - 1 - j);
        }

        for (j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        printf("\n");
    }

    return 0;
}